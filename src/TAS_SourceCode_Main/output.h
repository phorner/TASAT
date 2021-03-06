/* 
	Traveller's Aid Society Access Terminal

	     by Perry Horner 2001
	  

  The Traveller® game in all forms is owned by Far Future Enterprises. 
  Copyright 1977 - 2002 Far Future Enterprises. Traveller® is a registered 
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


//output.h



int Screenshot(char *FileName,  int typeclip);

long FileLenCount(char *countfilename);

void uppercase(char *sPtr);

void copy_string(char *target, char *source);

void printer_out_text(char text[]);

int printer_out_image(BITMAPINFO *info,void *bits);

bool saveTextureAsBitmap(ITexture* txt, char* file);

void CheckMouseHoverOverLOGIN(void);

void CheckMouseHoverOverMAIN(void);

void CheckMouseHoverOverNEWS(void);

void CheckMouseHoverOverNAV(void);

void CheckMouseHoverOverLIBDATA(void);

void CheckMouseHoverOverACCOUNTS(void);

void CheckMouseHoverOverCLASSIFIEDS(void);

void CheckMouseHoverOverXBOAT(void);

void CheckMouseHoverOver(void);

char *replace_str(char *str, char *orig, char *rep);


