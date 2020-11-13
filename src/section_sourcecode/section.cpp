/******************************************************************************
**  Program:		Section
**
**  Description:	Traveller Sub-Sector map data Formater.  Section
**                     takes a datafile containing all UWPs for a given
**                     Imperium sector, and breaks it up into 16 files,
**                     each file containing a header and 1 subsector of
**                     UWP data.  This pre-processing is done to general
**                     input files correctly formated for use with the
**                     "ssv" utility (an X-Windows program which draws
**                     sub-sector maps based on the UWP datafiles).
**
**                     To use, invoke as follows:
**                          section [sector_datafile]
**
**                     Section will automatically produce 16 output files
**                     named sec_A through sec_P.  Each file will contain,
**                     on the first line of it's header, the name of the
**                     sector (using the name of the file given to section
**                     as a parameter) and a dummy subsector name (using
**                     the name of the output file: sec_A - sec_P).  The
**                     user must manually edit in correct subsector names
**                     after the 16 subsector files are created.
**
**                     This program is designed to be a pre-formatter for
**                     the ssv (sub-sector viewer) program and expects
**                     input files to be in the format of GEnie traveller
**                     archive library Sector UWP files.
**
**  File:		Section.c, containing the following routines:
**                       main()
**
**  Copyright 1990 by Mark F. Cook and Hewlett-Packard,
**				Interface Technology Operation
**
**  Permission to use, copy, and modify this software is granted, provided
**  that this copyright appears in all copies and that both this copyright
**  and permission notice appear in all supporting documentation, and that
**  the name of Mark F. Cook and/or Hewlett-Packard not be used in advertising
**  without specific, writen prior permission.  Neither Mark F. Cook or
**  Hewlett-Packard make any representations about the suitibility of this
**  software for any purpose.  It is provided "as is" without express or
**  implied warranty.
**
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdafx.h"

char *header[24] = {
	"#",
	"# Trade routes within the subsector",
	"#src.dst.X Y dst.offsets",
	"# $1840 1841  0 1",
	"#",
	"#Political Borders",
	"#hexnumber hexside(0 - 5)",
	"#^1840 0",
	"#^1840 1",
	"#",
	"#",
	"#  1 - 13: Name",
	"# 15 - 18: HexNbr",
	"# 20 - 28: UWP",
	"#      31: Bases",
	"# 33 - 47: Codes & Comments",
	"#      49: Zone",
	"# 52 - 54: PBG",
	"# 56 - 57: Allegiance",
	"# 59 - 74: Stellar Data",
	"#",
	"#--------1---------2---------3---------4---------5---------6---------7--",
	"#PlanetName   Loc  UPP Code   B   Remarks       Z  PBG Al   Star(s)",
	"#----------   ---- ---------  - --------------- -  --- -- --------------"
};


#define  TRUE   1
#define  FALSE  0

#define  NUM_SSECS  16

static char *ssec_name[NUM_SSECS] = { "sec_a.sec", "sec_b.sec", "sec_c.sec", "sec_d.sec",
"sec_e.sec", "sec_f.sec", "sec_g.sec", "sec_h.sec",
"sec_i.sec", "sec_j.sec", "sec_k.sec", "sec_l.sec",
"sec_m.sec", "sec_n.sec", "sec_o.sec", "sec_p.sec" };

static char *ssec_letter[NUM_SSECS] = { "A", "B", "C", "D",
"E", "F", "G", "H",
"I", "J", "K", "L",
"M", "N", "O", "P" };

void main(int argc, char *argv)
{
	int done, i, j, col, row, target, goodline;
	char hex[10], str[10], line[91], *status;
	FILE *fd;
	FILE *fd_out[NUM_SSECS];
	

	/*--- check invocation for correct parameter count ---*/
	/*if (argc != 2) {
		printf("Section will automatically produce 16 output files\n named sec_A through sec_P.Each file will contain,\n");
		printf("on the first line of it's header, the name of the\n sector(using the name of the file given to section\n");
		printf("as a parameter) and a dummy subsector name(using \n the name of the output file : sec_A - sec_P).The\n");
		printf("user must manually edit in correct subsector names \n  after the 16 subsector files are created.");
		printf("Copyright 1990 by Mark F. Cook and Hewlett-Packard,Interface Technology Operation");

		printf("\n\n\nUsage: section sectorfilename \n");
		exit(1);
	}*/
	if (argc != 2) {
		printf("Section will automatically produce 16 output files\n named sec_A through sec_P.Each file will contain,\n");
		printf("on the first line of it's header, the name of the\n sector(using the name of the file given to section\n");
		printf("as a parameter) and a dummy subsector name(using \n the name of the output file : sec_A - sec_P).The\n");
		printf("user must manually edit in correct subsector names \n  after the 16 subsector files are created.");
		printf("Copyright 1990 by Mark F. Cook and Hewlett-Packard,Interface Technology Operation. Modified by Perry Horner 2014.\n\n");

		printf("[note: input sector file must be in hex number sequential order]\n\n");
		printf("Input sector filename:");
		gets(argv);
	}
	/*--- open the input file ---*/
	fd = fopen(argv, "r");
	if (fd == NULL) {
		printf( "Cannot open %s for input\n", argv);
		exit(1);
	}

	/*--- open the NUM_SSECS output files ---*/
	for (i = 0; i<NUM_SSECS; i++) {
		fd_out[i] = fopen(ssec_name[i], "w");
		if (fd_out[i] == NULL) {
			fprintf(stderr, "%s: Cannot open %s for output\n", argv[0], ssec_name[i]);
			exit(1);
		}
	}

	/*--- print the SUB-SECTOR/SECTOR header for each output file ---*/
	for (i = 0; i<NUM_SSECS; i++) {
		fprintf(fd_out[i], "@SUB-SECTOR:%s SECTOR:%s\n",
			ssec_letter[i], argv);
		for (j = 0; j<24; j++)
			fprintf(fd_out[i], "%s\n", header[j]);
	}

	/*--- Now, read each line in the full sector UWP file, one line at a   ---*/
	/*--- time.  Parse the 4-digit hex location code out of the line, and  ---*/
	/*--- determine which subsector file it should be written to.  Write   ---*/
	/*--- the line to the appropriate file.  Repeat the process until EOF. ---*/
	done = FALSE;
	while (!done) {
		status = fgets(line, 90, fd);
		if (status == NULL) break;

		/*--- make sure we're past the header lines ---*/
		goodline = TRUE;
		/*--- If the line is shorter than 18 chars, it's a header line ---*/
		if (strlen(line) < 18) goodline = FALSE;
		/*--- If the line is doesn't have digits in columns 14-18, ---*/
		/*--- it's a header line.                                  ---*/
		for (i = 14; i<18; i++)
		if ((line[i] < '0') || (line[i] > '9')) goodline = FALSE;
		if (!goodline) continue;

		/*--- get world hex location string ---*/
		strncpy(hex, &line[14], 4);
		hex[4] = 0;

		/*--- convert string to digits ---*/
		strncpy(str, hex, 2);
		str[2] = 0;
		/*--- determine which row and column the hex location is in ---*/
		col = atoi(str);
		strncpy(str, &(hex[2]), 2);
		str[2] = 0;
		row = atoi(str);
		/*--- determine which subsector the row/column intersect in ---*/
		target = (((row - 1) / 10) * 4) + ((col - 1) / 8);

		/*--- write the line to that subsector file ---*/
		fprintf(fd_out[target], "%s", line);
	}
	fclose(fd);
	for (i = 0; i<NUM_SSECS; i++)
		fclose(fd_out[i]);
	exit(0);
}
