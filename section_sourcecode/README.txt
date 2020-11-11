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
