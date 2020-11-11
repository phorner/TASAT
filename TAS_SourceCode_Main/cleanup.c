/* 
	Traveller's Aid Society Access Terminal

	     by Perry Horner 2001
	  

  The Traveller game in all forms is owned by Far Future Enterprises. 
  Copyright 1977 - 2002 Far Future Enterprises. Traveller is a registered 
  trademark of Far Future Enterprises. Far Future permits web sites and 
  fanzines for this game, provided it contains this notice, that Far Future 
  is notified, and subject to a withdrawal of permission on 90 days notice. 
  The use of this program is for personal, non-commercial use only. 
  Any use of Far Future Enterprises's copyrighted material or trademarks 
  anywhere in this program and its files should not be viewed as a challenge 
  to those copyrights or trademarks. In addition, any program/ article/ file 
  cannot be republished or distributed without the consent of the author who 
  contributed it. 
  

   The bulk of the code is by Perry Horner (firetaste@yahoo.com)



   Exerpt from original xssv code:
   Permission to use, copy, and modify this software is granted, provided
   that this copyright appears in all copies and that both this copyright
   and permission notice appear in all supporting documentation, and that
   the name of Mark F. Cook and/or Hewlett-Packard not be used in advertising
   without specific, writen prior permission.  Neither Mark F. Cook or
   Hewlett-Packard make any representations about the suitibility of this
   software for any purpose.  It is provided "as is" without express or
   implied warranty."

 
*/
void CleanUp(void)
{

}

void ClearNAV(void)
{
	libdatacounter = 0;
	libimagecount = 0;
	istherelibdata = 0;
	CurrentSystemLibData = 0;
	libdatacounter = 0;
	libdatacounter2 = 0; //for scrolling library data
	isthereseclibdata = 0; //is there any sector library data
	librarydataavailable = 0; //is there library data
	libimagecheck = 0; //is there a library data image
	CurrentSystemLibData = 0; // hex number for library data
	searchmenuitemavailable = 0; //library search menu item selection available
	searchentered = 0; //library search word entered
	libdatatext = '\0';
	libdatasearchword = '\0';
	outx = '\0';
	outy = '\0';
	col = '\0';
	shades = '\0';
	xxx = '\0';
	yyy = '\0';
	zzz = '\0';

}


void ClearNEWS(void)
{
	newsdatacounter = 0;
	free(newsdatatext);
}



void ClearLIBDATA(void)
{
	libdatacounter = 0;
	libimagecount = 0;
	istherelibdata = 0;
	CurrentSystemLibData = 0;
	libdatacounter = 0;
	libdatacounter2 = 0; //for scrolling library data
	isthereseclibdata = 0; //is there any sector library data
	librarydataavailable = 0; //is there library data
	libimagecheck = 0; //is there a library data image
	CurrentSystemLibData = 0; // hex number for library data
	searchmenuitemavailable = 0; //library search menu item selection available
	searchentered = 0; //library search word entered
	libdatatext = '\0';
	libdatasearchword = '\0';
	LibDataSearchBox = NULL;
	textBox = NULL;
	libdatatextimage = NULL;
	free(libdatatext);
}

void ClearAccounts(void)
{
	newsdatacounter = 0;
}

void ClearCLASSIFIEDS(void)
{

}

void ClearXboat(void)
{

}