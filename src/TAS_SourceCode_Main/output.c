/* 
	Traveller's Aid Society Access Terminal

	     by Perry Horner 2001
	  

  The Traveller® game in all forms is owned by Far Future Enterprises. 
  Copyright 1977 - 2014 Far Future Enterprises. Traveller® is a registered 
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



 
*/
// Screenshot
//    -> FileName: Name of file to save screenshot to
//    -> typeclip:  switch for bitmap boundary sizes
//    <- Result: Success
 
int Screenshot(char *FileName, int typeclip)
{
	int i = 0, x = 0, y = 0, xx = 0, yy = 0, x_ctr = 0, y_ctr = 0;
	int worldcntadj = 0;
	char tradecnt[81];
	int pertotal=0;
	int yinc = 0;
	int SSCallReturn = 0;

	
/*


	worldcntadj = 60;	//total number of worlds that can be displayed in list


    if (!FileName) return 1;


	croppedscreentodump = NULL;
	compatible_image = NULL;
	compatible_image = SDL_LoadBMP("bmaps/menu/blank.bmp");
	// re-format the image to display bpp
	croppedscreentodump = SDL_DisplayFormat(compatible_image);
	// destroy the old picture
	SDL_FreeSurface(compatible_image);

	if(typeclip==1){
			saverect.x = 0;	
			saverect.y = 0;	
			saverect.w = 1024;
			saverect.h = 768; //Full screen save

	}
	*/
	if (typeclip == (int)(SUBSECTORWINDOW)){

		IImage *screenshot = driver->createScreenShot();

		video::ITexture * rt = 0;
		if (driver->queryFeature(video::EVDF_RENDER_TO_TARGET))
		{
			rt = driver->addRenderTargetTexture(core::dimension2d<u32>(1024, 768), "RTT1");
		}
		if (rt){
			driver->setRenderTarget(rt, true, true, video::SColor(255, 255, 255, 255));
			video::IImage* export_img = driver->createImage(screenshot, core::vector2d<s32>(8, 4), core::dimension2d<u32>(675, 582));
			video::ITexture* texture = driver->addTexture(L"export_imag", export_img);
			texture->grab();
			driver->draw2DImage(texture, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(673, 0, 1024, 768));
			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(0, 582, 1024, 768));

			//view system names in black on a saved subsector file
			worldcntadj = w_cnt;

			xx = 30;
			yy = 610;
			for (i = 0; i<worldcntadj; i++) {
				if (yy>750){
					yy = 610;
					xx = xx + 140;
				}
				if (xx>410) break;

				Courier8Black->draw(irr::core::stringw(sec_world[i].hex).c_str(), core::rect<s32>(xx, yy, 0, 0), video::SColor(255, 255, 255, 255));
				if (!strcmp(sec_world[i].Zone, "R")) {
					Courier8Red->draw(irr::core::stringw(sec_world[i].name).c_str(), core::rect<s32>(xx + 35, yy, 0, 0), video::SColor(255, 255, 255, 255));
				} // Red zone
				else
				{
					Courier8Black->draw(irr::core::stringw(sec_world[i].name).c_str(), core::rect<s32>(xx + 35, yy, 0, 0), video::SColor(255, 255, 255, 255));
				}
				yy = yy + 12;
			}

			smgr->drawAll();
			screenshot->drop();
			screenshot = driver->createScreenShot();
			driver->writeImageToFile(screenshot, FileName); //partial screen
			driver->setRenderTarget(0, true, true, video::SColor(0, 0, 0, 0));
			smgr->drawAll();
			screenshot->drop();
			export_img->drop();
			texture->drop();
		}
		skin->setFont(Courier10Yellow);

		IGUIWindow* window = guienv->addMessageBox(L"File saved to...", stringw(FileName).c_str(), false, EMBF_OK, 0, -1, 0);

		//subsector map
		sprintf(tradecnt, "mspaint /pt .\\%s", FileName);
		//replace_str(tradecnt, "/", "\\");
		//sprintf(tradecnt, "mspaint /pt %s", tempsubfname);
		//sprintf(tradecnt, "mspaint /pt saved\\subsector\\%s", tempsavefilename);
		//sprintf(tradecnt, "mspaint /pt \"%s\\saved\\subsector\\%s\"", currentWDir,tempsavefilename);
		if (PrinterOn > 0)
		{
			system(tradecnt); //use Microsoft Paint to print
		}
		window->setDrawBackground(true);

		return 0;

	} //end if SUBSECTORWINDOW


	if(typeclip==(int)(SECTORWINDOW)){

		IImage *screenshot = driver->createScreenShot();

		video::ITexture * rt = 0;
		if (driver->queryFeature(video::EVDF_RENDER_TO_TARGET))
		{
			rt = driver->addRenderTargetTexture(core::dimension2d<u32>(1024, 768), "RTT1");
		}
		if (rt)
		{
			driver->setRenderTarget(rt, true, true, video::SColor(255, 255, 255, 255));
			video::IImage* export_img = driver->createImage(screenshot, core::vector2d<s32>(6, 3), core::dimension2d<u32>(682, 697));
			video::ITexture* texture = driver->addTexture(L"export_imag", export_img);
			texture->grab();
			driver->draw2DImage(texture, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(678, 0, 1024, 768));
			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(0, 692, 1024, 768));
			smgr->drawAll();
			screenshot->drop();
			screenshot = driver->createScreenShot();
			driver->writeImageToFile(screenshot, FileName); //partial screen
			driver->setRenderTarget(0, true, true, video::SColor(0, 0, 0, 0));
			smgr->drawAll();
			screenshot->drop();
			export_img->drop();
			texture->drop();

			skin->setFont(Courier10Yellow);

			SSwindow = guienv->addMessageBox(L"File saved to...", stringw(FileName).c_str(), false, EMBF_OK, 0, -1, 0);
			SSwindow->setDrawBackground(true);

			//sector map
			sprintf(tradecnt, "mspaint /pt %s", FileName);
			if (PrinterOn > 0)
			{
				system(tradecnt); //use Microsoft Paint to print
			}
		}//end if rt
		return 0;
	} //end if SECTORWINDOW

	
	if (typeclip == (int)(LOANWINDOW)){

		IImage *screenshot = driver->createScreenShot();

		video::ITexture * rt = 0;
		if (driver->queryFeature(video::EVDF_RENDER_TO_TARGET))
		{
		rt = driver->addRenderTargetTexture(core::dimension2d<u32>(1024, 768), "RTT1");
		}
		if (rt){
			driver->setRenderTarget(rt, true, true, video::SColor(255, 255, 255, 255));
			video::IImage* export_img = driver->createImage(screenshot, core::vector2d<s32>(6, 3), core::dimension2d<u32>(856, 768));
			video::ITexture* texture = driver->addTexture(L"export_imag", export_img);
			texture->grab();
			driver->draw2DImage(texture, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(860, 0, 1024, 768));
			smgr->drawAll();
			screenshot->drop();
			screenshot = driver->createScreenShot();
			driver->writeImageToFile(screenshot, FileName); //partial screen
			driver->setRenderTarget(0, true, true, video::SColor(0, 0, 0, 0));
			smgr->drawAll();
			screenshot->drop();
			export_img->drop();
			texture->drop();


			skin->setFont(Courier10Yellow);

			IGUIWindow* window = guienv->addMessageBox(L"File saved to...", stringw(FileName).c_str(), false, EMBF_OK, 0, -1, 0);

			window->setDrawBackground(true);

			//loan application
			sprintf(tradecnt, "mspaint /pt %s", FileName);
			if (PrinterOn > 0)
			{
				system(tradecnt); //use Microsoft Paint to print
			}

		}//end if rt
		return 0;
	}//end if LOANWINDOW
	
	if (typeclip == (int)(PLANETWINDOW)){

		Planet->setVisible(false); //turn 3d planet off for screenshot
		smgr->drawAll();

		IImage *screenshot = driver->createScreenShot();

		video::ITexture * rt = 0;
		if (driver->queryFeature(video::EVDF_RENDER_TO_TARGET))
		{
		rt = driver->addRenderTargetTexture(core::dimension2d<u32>(1024, 768), "RTT1");
		}
		if (rt){
		driver->setRenderTarget(rt, true, true, video::SColor(255, 255, 255, 255));
		video::IImage* export_img = driver->createImage(screenshot, core::vector2d<s32>(6, 3), core::dimension2d<u32>(1018, 775));
		video::ITexture* texture = driver->addTexture(L"export_imag", export_img);
		texture->grab();
		driver->draw2DImage(texture, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);


			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(840, 650, 1024, 768));
			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(1017, 0, 1024, 768));
			driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(0, 760, 1024, 768));


		smgr->drawAll();
		screenshot->drop();
	

		screenshot = driver->createScreenShot();
		driver->writeImageToFile(screenshot, FileName); //partial screen
		driver->setRenderTarget(0, true, true, video::SColor(0, 0, 0, 0));
		smgr->drawAll();
		screenshot->drop();
		export_img->drop();
		texture->drop();

		Planet->setVisible(true); //turn 3d planet back on

		skin->setFont(Courier10Yellow);

		//planet map
		SSwindow = guienv->addMessageBox(L"File saved to...", stringw(FileName).c_str(), false, EMBF_OK, 0, -1, 0);
		SSwindow->setDrawBackground(true);

		sprintf(tradecnt, "mspaint /pt %s", FileName);
		if (PrinterOn > 0)
		{
			system(tradecnt); //use Microsoft Paint to print
		}


		}
	}

   return 0;
}


//find the length of a file instead of using FTELL
long FileLenCount(char *countfilename)

{
	FILE *FTMPC;
	long ccount=0;
	char c;


	ccount = 0;
	FTMPC = fopen(countfilename, "r");
	while ((c = fgetc(FTMPC)) != EOF)
	{
		ccount++;
	}
	fclose(FTMPC);
	FTMPC = NULL;
	countfilename = NULL;
	return ccount;
}

void uppercase(char *sPtr)
{
	while (*sPtr != '\0')
		{
			*sPtr = toupper((unsigned char)*sPtr);
		    ++sPtr;
		}
}

void copy_string(char *target, char *source)
{
	while (*source)
	{
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}

void printer_out_text(char text[])
{

	// Bring up a dialog to choose the printer
	PRINTDLG pd = { 0 };
	pd.lStructSize = sizeof(pd);
	pd.Flags = PD_RETURNDEFAULT | PD_RETURNDC;
	pd.nCopies = 1;

	// Show the printer Dialog
	PrintDlg(&pd);


	// Zero and then initialize the members of a DOCINFO structure.
	DOCINFO di = { 0 };
	di.cbSize = sizeof(DOCINFO);
	di.lpszDocName = "Travellers' Aid Society Access Terminal";
	di.lpszOutput = (LPTSTR)NULL;
	di.lpszDatatype = (LPTSTR)NULL;
	di.fwType = 0;

	// Begin a print job by calling the StartDoc function.
	StartDoc(pd.hDC, &di);

	// Inform the driver that the application is about to begin sending data.
	StartPage(pd.hDC);

	//here we put images\text or other DC things;)

	//send some text
	TextOut(pd.hDC, 800, 800, text, strlen(text));


	//Lets close  the printer
	// Inform the driver that the page is finished.
	EndPage(pd.hDC);

	// Inform the driver that document has ended.
	EndDoc(pd.hDC);
}

int printer_out_image(BITMAPINFO *info,/* I - Bitmap information */
							void *bits) /* I - Bitmap pixel bits */

{
  PRINTDLG pd;                  /* Print dialog information */
  long     xsize,               /* Size of printed image */
           ysize,
           xoffset,             /* Offset from edges for image */
           yoffset;
  RECT     rect;                /* Page rectangle */
  DOCINFO  di;                  /* Document info */
  HDC      hdc;                 /* Device context for bitmap */
  HBITMAP  bitmap;              /* Bitmap image */
  HBRUSH   brush;               /* Background brush for page */
  HCURSOR  busy,                /* Busy cursor */
           oldcursor;           /* Old cursor */
 /*
  * Range check…
  */

  if (info == NULL || bits == NULL)
    return (0);

 /*
  * Initialize a PRINTDLG structure before displaying a standard Windows
  * print dialog…
  */

  memset(&pd, 0, sizeof(pd));
  pd.lStructSize = sizeof(pd);
  pd.Flags       = PD_RETURNDC;
  pd.hInstance   = NULL;
  if (!PrintDlg(&pd))
    return (0);                   /* User chose 'cancel'… */

 /*
  * OK, user wants to print, so set the cursor to 'busy' and start the
  * print job…
  */

  busy      = LoadCursor(NULL, IDC_WAIT);
  oldcursor = SetCursor(busy);

  SetMapMode(pd.hDC, MM_TEXT);
  di.cbSize      = sizeof(DOCINFO);
  di.lpszDocName = "Travellers' Aid Society Access Terminal";
  di.lpszOutput  = NULL;

  StartDoc(pd.hDC, &di);
  StartPage(pd.hDC);

 /*
  * Clear the background to white…
  */

  rect.top    = 0;
  rect.left   = 0;
  rect.right  = GetDeviceCaps(pd.hDC, HORZRES);
  rect.bottom = GetDeviceCaps(pd.hDC, VERTRES);
  brush       = CreateSolidBrush(0x00ffffff);
  FillRect(pd.hDC, &rect, brush);

 /*
  * Stretch the bitmap to fit the page…
  */

  hdc    = CreateCompatibleDC(pd.hDC);
  bitmap = CreateDIBitmap(hdc, &(info->bmiHeader), CBM_INIT, bits, info,
                          DIB_RGB_COLORS);
  SelectObject(hdc, bitmap);

  xsize = rect.right;
  ysize = xsize * info->bmiHeader.biHeight / info->bmiHeader.biWidth;
  if (ysize > rect.bottom)
  {
    ysize = rect.bottom;
    xsize = ysize * info->bmiHeader.biWidth / info->bmiHeader.biHeight;
  };

  xoffset = (rect.right - xsize) / 2;
  yoffset = (rect.bottom - ysize) / 2;

  StretchBlt(pd.hDC, xoffset, yoffset, xsize, ysize,
             hdc, 0, 0, info->bmiHeader.biWidth, info->bmiHeader.biHeight,
             SRCCOPY);

 /*
  * That's it.  End the print job and free anything we allocated…
  */

  EndPage(pd.hDC);
  EndDoc(pd.hDC);
  DeleteDC(pd.hDC);

  DeleteObject(bitmap);
  DeleteObject(brush);
  DeleteObject(busy);
  DeleteDC(hdc);

 /*
  * Restore the cursor and return…
  */

  SetCursor(oldcursor);

  return (1);
}
bool saveTextureAsBitmap(ITexture* txt, char* file){
  FILE* datei;
  if(!device) return false;
  if((datei = fopen(file, "wb"))==NULL) return false;

  BYTE* pixels = (BYTE*)txt->lock();
  s32 BitDepth   = 32;

  //fill bitmap file header
  BITMAPFILEHEADER   Header;
  Header.bfSize = sizeof(BITMAPFILEHEADER);
  Header.bfType = 0x4D42;
  Header.bfReserved1 = 0;
  Header.bfReserved2 = 0;
  Header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
  //fill bitmap information header
  BITMAPINFOHEADER   HeaderInformation;
  HeaderInformation.biSize = sizeof(BITMAPINFOHEADER);
  HeaderInformation.biPlanes = 1;
  HeaderInformation.biClrUsed = 0;
  HeaderInformation.biWidth = txt->getSize().Width;
  HeaderInformation.biHeight = txt->getSize().Height;
  HeaderInformation.biClrImportant = 0;
  HeaderInformation.biXPelsPerMeter = 0;
  HeaderInformation.biYPelsPerMeter = 0;
  HeaderInformation.biBitCount = BitDepth;
  HeaderInformation.biCompression = BI_RGB;
  HeaderInformation.biSizeImage = txt->getSize().Width * txt->getSize().Height * 3;

  //--Write the bitmap file header
  fwrite(&Header, 1, sizeof(BITMAPFILEHEADER), datei);
  //--Write the bitmap information header
  fwrite(&HeaderInformation, 1, sizeof(BITMAPINFOHEADER), datei);
  //--Write Pixels
  fwrite(pixels, sizeof(BYTE), txt->getSize().Width * txt->getSize().Height * 4, datei);

  fclose(datei);
  txt->unlock();

  return true;
}


void CheckMouseHoverOverLOGIN(void)
{

	//***************LOGINWINDOW **************************
	if ((mouse_position.X>400) && (mouse_position.X<630) && (mouse_position.Y>450) && (mouse_position.Y<510) && (LoginPassFLAG == 1) && (LoginUnameFLAG == 1))
	{
		driver->draw2DImage(SubmitHover, core::position2d<s32>(400, 450), core::rect<s32>(0, 0, 232, 68), 0, video::SColor(255, 255, 255, 255), true); //highlight submit button
	} //end if loginsubmit
}

void CheckMouseHoverOverMAIN(void)
{

	//***************MAINMENU **************************
	if ((TASWindow == MAINMENUWINDOW) && ((mouse_position.X > 370) && (mouse_position.X < 583) && (mouse_position.Y>610) && (mouse_position.Y < 670)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(370, 610, 583, 670), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(371, 611, 582, 669), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(372, 612, 581, 668), video::SColor(255, 255, 255, 255));
	} //end if LOGOFF

	//display all menu selections available for the user's access level

	if (uAccessLevel >= 0){
		if (uAccessLevel >= ALNAVLIB)
		{
			driver->draw2DImage(yellowstar, core::position2d<s32>(66, 337), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //navigation library
			if ((mouse_position.X > 69) && (mouse_position.X < 88) && (mouse_position.Y>340) && (mouse_position.Y < 359) && (uAccessLevel >= ALNAVLIB)) 
			{
				driver->draw2DImage(orangestar, core::position2d<s32>(66, 337), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //hoverover
			}
		}
		if (uAccessLevel >= ALNEWS)
		{
			driver->draw2DImage(yellowstar, core::position2d<s32>(66, 391), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //news service
			if ((mouse_position.X>71) && (mouse_position.X<88) && (mouse_position.Y>397) && (mouse_position.Y<414) && (uAccessLevel >= ALNEWS)) 
			{
				driver->draw2DImage(orangestar, core::position2d<s32>(66, 391), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //hoverover
			}
		}
		if (uAccessLevel >= ALLIBDATA)
		{
			driver->draw2DImage(yellowstar, core::position2d<s32>(66, 282), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //library data
			if ((mouse_position.X>69) && (mouse_position.X<88) && (mouse_position.Y>282) && (mouse_position.Y<302) && (uAccessLevel >= ALLIBDATA))
			{
				driver->draw2DImage(orangestar, core::position2d<s32>(66, 282), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //hoverover
			}
		}
		if (uAccessLevel >= ALACCNT)
		{
			driver->draw2DImage(yellowstar, core::position2d<s32>(66, 146), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //Account services
			if ((mouse_position.X>69) && (mouse_position.X<88) && (mouse_position.Y>148) && (mouse_position.Y<168) && (uAccessLevel >= ALACCNT))
			{
				driver->draw2DImage(orangestar, core::position2d<s32>(66, 146), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true);  //hoverover
			}
		}
		if (uAccessLevel >= ALCLASS)
		{
			driver->draw2DImage(yellowstar, core::position2d<s32>(66, 190), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //Classifieds
			if ((mouse_position.X>69) && (mouse_position.X<89) && (mouse_position.Y>190) && (mouse_position.Y<212) && (uAccessLevel >= ALCLASS)) 
			{
				driver->draw2DImage(orangestar, core::position2d<s32>(66, 190), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //hoverover
			}
		}
		if (uAccessLevel >= ALXBT)
		{
			driver->draw2DImage(yellowstar, core::position2d<s32>(66, 238), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //Communications
			if ((mouse_position.X>69) && (mouse_position.X<90) && (mouse_position.Y>238) && (mouse_position.Y<260) && (uAccessLevel >= ALXBT)) 
			{
				driver->draw2DImage(orangestar, core::position2d<s32>(66, 238), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //hoverover
			}
		}

	} //end if uAccessLevel >= 0

	//PRinter ON OFF toggle
	if ((TASWindow == MAINMENUWINDOW) && (mouse_position.X > 835) && (mouse_position.X < 950) && (mouse_position.Y>350) && (mouse_position.Y < 384) && (MSPaintAvail == 0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(834, 349, 951, 385), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(835, 350, 950, 384), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(836, 351, 949, 383), video::SColor(255, 255, 255, 255));
	}
}//end checkmousehoveroverMAIN

void CheckMouseHoverOverNEWS(void)
{

	//****************ARCHIVES***************************
	if ((mouse_position.X > 854) && (mouse_position.X < 1015) && (mouse_position.Y >640) && (mouse_position.Y < 680))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 639, 1016, 681), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 640, 1015, 680), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 641, 1014, 679), video::SColor(255, 255, 255, 255));
	} //ARCHIVES

	//****************RUMORS***************************
	else if ((mouse_position.X > 854) && (mouse_position.X < 1015) && (mouse_position.Y >694) && (mouse_position.Y < 734))
	{
		driver->draw2DRectangleOutline(irr::core::recti(855, 690, 1016, 733), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(856, 691, 1015, 732), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(857, 692, 1014, 731), video::SColor(255, 255, 255, 255));
	} //RUMORS

	//***************EXIT************************
	else if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760))
	{
		driver->draw2DRectangleOutline(irr::core::recti(851, 742, 1018, 763), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(852, 743, 1017, 762), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
	} //end if Exit 
	
	//RUMOR AND ARCHIVE ARROWS
	if ((TASWindow == ARCHIVENEWSWINDOW) || (TASWindow == RUMORSNEWSWINDOW))
	{
		//UP Arrow
		if ((mouse_position.X>940) && (mouse_position.X<970) && (mouse_position.Y>232) && (mouse_position.Y<265))
		{
			driver->draw2DLine(position2d<s32>(954, 227), position2d<s32>(936, 265), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(955, 228), position2d<s32>(937, 266), SColor(255, 255, 255, 255)); 
			driver->draw2DLine(position2d<s32>(956, 229), position2d<s32>(938, 267), SColor(255, 255, 255, 255));

			driver->draw2DLine(position2d<s32>(954, 227), position2d<s32>(971, 265), SColor(255, 255, 255, 255)); 
			driver->draw2DLine(position2d<s32>(955, 228), position2d<s32>(972, 266), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(956, 229), position2d<s32>(973, 267), SColor(255, 255, 255, 255));

			driver->draw2DLine(position2d<s32>(936, 265), position2d<s32>(971, 265), SColor(255, 255, 255, 255)); 
			driver->draw2DLine(position2d<s32>(937, 266), position2d<s32>(972, 266), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(938, 267), position2d<s32>(973, 267), SColor(255, 255, 255, 255));
		}
		//DOWN Arrow
		if ((mouse_position.X>940) && (mouse_position.X<970) && (mouse_position.Y>315) && (mouse_position.Y<350))
		{
			driver->draw2DLine(position2d<s32>(934, 312), position2d<s32>(969, 312), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(935, 313), position2d<s32>(970, 313), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(936, 314), position2d<s32>(971, 314), SColor(255, 255, 255, 255));

			driver->draw2DLine(position2d<s32>(934, 312), position2d<s32>(953, 350), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(935, 313), position2d<s32>(954, 351), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(936, 314), position2d<s32>(955, 352), SColor(255, 255, 255, 255));

			driver->draw2DLine(position2d<s32>(969, 312), position2d<s32>(953, 350), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(970, 313), position2d<s32>(954, 351), SColor(255, 255, 255, 255));
			driver->draw2DLine(position2d<s32>(971, 314), position2d<s32>(955, 352), SColor(255, 255, 255, 255));
		}
	}
}


void CheckMouseHoverOverNAV(void)
{
	int templocation = 0, temp_wcount=0;
	//****************GALAXY WINDOW*******************
	if ((TASWindow == GALAXYWINDOW) && ((mouse_position.X < 788) && (mouse_position.Y < 610) && (mouse_position.X>10) && (mouse_position.Y>10)))
	{
		//find map coordinate sector number
		templocation = ((int)(((float)((int)mouse_position.Y / 57) + 1) * 18) - (18 - ((float)((int)mouse_position.X / 43))));
		if (templocation > -1)
		{
			if (sectorlocationname[templocation].sectornumber == templocation)
			{
				Optima18Red->draw(irr::core::stringw(sectorlocationname[templocation].fullsectorname).c_str(), core::rect<s32>(mouse_position.X + 20, mouse_position.Y-10, 0, 0), video::SColor(255, 255, 255, 0));
			} //display hoverover of sector name on galaxy map
		}
		templocation = -1; //reset location
	} //end if GALAXYWINDOW

	//***************Exit Galaxy Window************************
	else if ((TASWindow == GALAXYWINDOW) && ((mouse_position.X < 1015) && (mouse_position.Y < 760) && (mouse_position.X>854) && (mouse_position.Y>745)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(851, 742, 1018, 763), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(852, 743, 1017, 762), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
	} //end if Exit Galaxy Window

	//****************SECTOR WINDOW SUBSECTOR LABELS*******************
	else if ((TASWindow == SECTORWINDOW) && ((mouse_position.X < 480) && (mouse_position.Y < 580) && (mouse_position.X>120) && (mouse_position.Y>120)))
	{
		//display subsector name
		Optima18Red->draw(irr::core::stringw(sublocnamegrid[(int)((mouse_position.Y - 120) / 120)].second[(int)((mouse_position.X - 100) / 100)]).c_str(), core::rect<s32>(mouse_position.X + 20, mouse_position.Y-10, 0, 0), video::SColor(255, 255, 255, 0));
	}//end if SECTORWINDOW SUBSECTOR LABELS


	//****************SECTOR SCREENSHOT***************************
	else if ((TASWindow == SECTORWINDOW) && (mouse_position.X > 854) && (mouse_position.X < 1015) && (mouse_position.Y >693) && (mouse_position.Y < 732))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 690, 1016, 733), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 691, 1015, 732), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 692, 1014, 731), video::SColor(255, 255, 255, 255));
	} //SCREENSHOT

	//***************SECTOR Library Data Button************************
	else if ((TASWindow == SECTORWINDOW) && (mouse_position.X < (libdatabuttonx + 86)) && (mouse_position.X > libdatabuttonx) && (mouse_position.Y < (libdatabuttony + 31)) && (mouse_position.Y > libdatabuttony) && (isthereseclibdata>0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(libdatabuttonx, libdatabuttony, libdatabuttonx + 86, libdatabuttony + 31), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(libdatabuttonx + 1, libdatabuttony + 1, libdatabuttonx + 1 + 86, libdatabuttony + 1 + 31), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(libdatabuttonx - 1, libdatabuttony - 1, libdatabuttonx - 1 + 86, libdatabuttony - 1 + 31), video::SColor(255, 255, 255, 255));
	}  //end if Sector Library Data Button

	//***************SECTOR Fleet Data Button************************
	else if ((TASWindow == SECTORWINDOW) && (mouse_position.X < (fleetbuttonx + 86)) && (mouse_position.X > fleetbuttonx) && (mouse_position.Y < (fleetbuttony + 31)) && (mouse_position.Y > fleetbuttony) && (istherefleet>0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(fleetbuttonx, fleetbuttony, fleetbuttonx + 86, fleetbuttony + 31), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(fleetbuttonx + 1, fleetbuttony + 1, fleetbuttonx + 1 + 86, fleetbuttony + 1 + 31), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(fleetbuttonx - 1, fleetbuttony - 1, fleetbuttonx - 1 + 86, fleetbuttony - 1 + 31), video::SColor(255, 255, 255, 255));
	}  //end if Sector Fleet Data Button

	//***************Exit Fleet Window back to sector************************
	else if ((TASWindow == SECTORFLEETWINDOW) && ((mouse_position.X < 1015) && (mouse_position.Y < 761) && (mouse_position.X>854) && (mouse_position.Y>745)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 745, 1015, 760), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 746, 1014, 759), video::SColor(255, 255, 255, 255));
	} //end if Exit Fleet Window back to sector

	//***************Exit Sector Window back to galaxy************************
	else if ((TASWindow == SECTORWINDOW) && ((mouse_position.X < 1020) && (mouse_position.Y < 766) && (mouse_position.X>859) && (mouse_position.Y>749)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 745, 1015, 760), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 746, 1014, 759), video::SColor(255, 255, 255, 255));
	} //end if Exit Sector Window back to galaxy

	//****************SUBSECTOR SCREENSHOT***************************
	else if ((TASWindow == SUBSECTORWINDOW) && (mouse_position.X > 851) && (mouse_position.X < 1019) && (mouse_position.Y >689) && (mouse_position.Y < 737))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 690, 1016, 733), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 691, 1015, 732), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 692, 1014, 731), video::SColor(255, 255, 255, 255));
	} //SCREENSHOT

	//***************Exit SubSector Window back to sector************************
	else if ((TASWindow == SUBSECTORWINDOW) && ((mouse_position.X < 1015) && (mouse_position.Y < 761) && (mouse_position.X>854) && (mouse_position.Y>745)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 762), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 745, 1015, 761), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 746, 1014, 760), video::SColor(255, 255, 255, 255));
	} //end if Exit SubSector Window back to sector

	//***************SubSector Planet box************************
	else if ((TASWindow == SUBSECTORWINDOW) && ((mouse_position.X < 1002) && (mouse_position.Y < 107) && (mouse_position.X>902) && (mouse_position.Y>8) && (currentworld > 0)) && (subsectorhex >0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(902, 8, 1002, 107), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(902, 9, 1003, 108), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(901, 7, 1001, 106), video::SColor(255, 255, 255, 255));
	} //end if Exit SubSector Planet box

	//*************Subsector Hex Grid Outline*****************************
	//select a system on map
	if ((TASWindow == SUBSECTORWINDOW) && (mouse_position.X < 430) && (mouse_position.Y < 543) && (mouse_position.X>54) && (mouse_position.Y>20))
	{
		//system lookup
		for (temp_wcount = 0; temp_wcount <= w_cnt; temp_wcount++){

			//draw hex coords
			if ((mouse_position.X >= ((sec_world[temp_wcount].xmousepoint))) && (mouse_position.X <= ((sec_world[temp_wcount].xmousepoint) + 20)) &&
				(mouse_position.Y >= ((sec_world[temp_wcount].ymousepoint) - 20)) && (mouse_position.Y <= ((sec_world[temp_wcount].ymousepoint) + 20)))
			{
				driver->draw2DLine(position2d<s32>(hex_pts[0].x + sec_world[temp_wcount].xmousepoint, hex_pts[0].y + sec_world[temp_wcount].ymousepoint) +10,
					position2d<s32>(hex_pts[1].x + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[1].y +10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[0].x +1 + sec_world[temp_wcount].xmousepoint, hex_pts[0].y +1 + sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[1].x + 10 +1 + sec_world[temp_wcount].xmousepoint, hex_pts[1].y + 10 +1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[0].x -1 + sec_world[temp_wcount].xmousepoint, hex_pts[0].y -1 + sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[1].x -1 + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[1].y -1 + 10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
		
				driver->draw2DLine(position2d<s32>(hex_pts[1].x + sec_world[temp_wcount].xmousepoint, hex_pts[1].y + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[2].x + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[2].y + 10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[1].x+1 + sec_world[temp_wcount].xmousepoint, hex_pts[1].y+1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[2].x + 10+1 + sec_world[temp_wcount].xmousepoint, hex_pts[2].y + 10 +1+ sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[1].x -1+ sec_world[temp_wcount].xmousepoint, hex_pts[1].y -1+ +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[2].x -1+ 10 + sec_world[temp_wcount].xmousepoint, hex_pts[2].y + 10-1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple

				driver->draw2DLine(position2d<s32>(hex_pts[2].x + sec_world[temp_wcount].xmousepoint, hex_pts[2].y + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[3].x + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[3].y + 10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[2].x + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[2].y + 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[3].x + 10 + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[3].y + 10 + 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[2].x - 1 + sec_world[temp_wcount].xmousepoint, hex_pts[2].y - 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[3].x - 1 + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[3].y + 10 - 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple

				driver->draw2DLine(position2d<s32>(hex_pts[3].x + sec_world[temp_wcount].xmousepoint, hex_pts[3].y + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[4].x + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[4].y + 10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[3].x + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[3].y + 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[4].x + 10 + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[4].y + 10 + 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[3].x - 1 + sec_world[temp_wcount].xmousepoint, hex_pts[3].y - 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[4].x - 1 + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[4].y + 10 - 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple

				driver->draw2DLine(position2d<s32>(hex_pts[4].x + sec_world[temp_wcount].xmousepoint, hex_pts[4].y + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[5].x + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[5].y + 10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[4].x + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[4].y + 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[5].x + 10 + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[5].y + 10 + 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[4].x - 1 + sec_world[temp_wcount].xmousepoint, hex_pts[4].y - 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[5].x - 1 + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[5].y + 10 - 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple

				driver->draw2DLine(position2d<s32>(hex_pts[5].x + sec_world[temp_wcount].xmousepoint, hex_pts[5].y + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[6].x + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[6].y + 10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[5].x + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[5].y + 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[6].x + 10 + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[6].y + 10 + 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[5].x - 1 + sec_world[temp_wcount].xmousepoint, hex_pts[5].y - 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[6].x - 1 + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[6].y + 10 - 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple

				driver->draw2DLine(position2d<s32>(hex_pts[6].x + sec_world[temp_wcount].xmousepoint, hex_pts[6].y + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[0].x + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[0].y + 10 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[6].x + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[6].y + 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[0].x + 10 + 1 + sec_world[temp_wcount].xmousepoint, hex_pts[0].y + 10 + 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
				driver->draw2DLine(position2d<s32>(hex_pts[6].x - 1 + sec_world[temp_wcount].xmousepoint, hex_pts[6].y - 1 + +sec_world[temp_wcount].ymousepoint) + 10,
					position2d<s32>(hex_pts[0].x - 1 + 10 + sec_world[temp_wcount].xmousepoint, hex_pts[0].y + 10 - 1 + sec_world[temp_wcount].ymousepoint), SColor(255, 255, 0, 255)); //purple
			} //end check hex coords
		}//end system lookup

	
	} //end subsector hex display

	//***************SubSector Library Data Button************************
	else if ((TASWindow == SUBSECTORWINDOW) && (mouse_position.X <976) && (mouse_position.X >890) && (mouse_position.Y < 646) && (mouse_position.Y > 615) && (istherelibdata>0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(890, 615, 890 + 86, 615 + 31), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(891, 616, 891 + 86, 616 + 31), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(889, 614, 889 + 86, 614 + 31), video::SColor(255, 255, 255, 255));
	}  //end if SubSector Library Data Button

	//***************SubSector Library data Window IMAGE************************
	else if ((TASWindow == SUBSECTORLIBDATAWINDOW) && ((mouse_position.X < 950) && (mouse_position.Y < 380) && (mouse_position.X>750) && (mouse_position.Y>330)) && (libimagecheck>0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(750, 330, 950, 380), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(751, 331, 951, 381), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(749, 329, 949, 379), video::SColor(255, 255, 255, 255));
	} //end if SubSector Library data IMAGE Window

	//***************Exit SubSector Library data Window************************
	else if (((TASWindow == SUBSECTORLIBDATAWINDOW) || (TASWindow == SUBSECLIBDATAIMAGEWINDOW)) && ((mouse_position.X < 1015) && (mouse_position.Y < 761) && (mouse_position.X>854) && (mouse_position.Y>745)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 745, 1015, 760), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 746, 1014, 759), video::SColor(255, 255, 255, 255));
	} //end if Exit SubSector Library data Window

	//***************Exit Sector Library data Window************************
	else if ((TASWindow == SECTORLIBDATAWINDOW) && ((mouse_position.X < 1015) && (mouse_position.Y < 761) && (mouse_position.X>854) && (mouse_position.Y>745)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 745, 1015, 760), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 746, 1014, 759), video::SColor(255, 255, 255, 255));
	} //end if Exit Sector lib data Window

	//***************Exit Planet Window back to subsector************************
	else if ((TASWindow == PLANETWINDOW) && ((mouse_position.X < 1015) && (mouse_position.Y < 761) && (mouse_position.X>854) && (mouse_position.Y>745)))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 745, 1015, 760), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 746, 1014, 759), video::SColor(255, 255, 255, 255));
	} //end if Exit Planet Window back to subsector

	//****************Planet Window SCREENSHOT***************************
	else if ((TASWindow == PLANETWINDOW) && (mouse_position.X > 851) && (mouse_position.X < 1019) && (mouse_position.Y >689) && (mouse_position.Y < 737))
	{
		driver->draw2DRectangleOutline(irr::core::recti(853, 690, 1016, 733), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(854, 691, 1015, 732), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(855, 692, 1014, 731), video::SColor(255, 255, 255, 255));
	} //SCREENSHOT

	//****************MARKER Location Selection***************************
	else if ((TASWindow == SUBSECTORWINDOW) && (mouse_position.X > 700) && (mouse_position.X < 730) && (mouse_position.Y >10) && (mouse_position.Y < 40) && (subsectorhex>0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(699, 9, 731, 41), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(700, 10, 730, 40), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(701, 11, 729, 39), video::SColor(255, 255, 255, 255));
	} //MARKER Location Selection
}

void CheckMouseHoverOverLIBDATA(void)
{
	//**********LIBDATA IMAGE SELECTION************
	if ((libimagecount == 1) && (mouse_position.X > 760) && (mouse_position.X < 960) && (mouse_position.Y > 510) && (mouse_position.Y < 560) && (TASWindow == LIBDATASERVICEWINDOW))
	{
		driver->draw2DRectangleOutline(irr::core::recti(759, 509, 961, 561), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(760, 510, 960, 560), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(761, 511, 959, 559), video::SColor(255, 255, 255, 255));
	}

	//***************EXIT************************
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760) && (searchmenuitemavailable==0))
	{
		driver->draw2DRectangleOutline(irr::core::recti(851, 742, 1018, 763), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(852, 743, 1017, 762), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(853, 744, 1016, 761), video::SColor(255, 255, 255, 255));
	} //end if Exit 

	//***************SEARCH************************
	else if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>692) && (mouse_position.Y<732) && (searchmenuitemavailable == 0) && (TASWindow == LIBDATASERVICEWINDOW))
	{
		driver->draw2DRectangleOutline(irr::core::recti(857, 692, 1014, 733), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(858, 693, 1013, 732), video::SColor(255, 255, 255, 255));
		driver->draw2DRectangleOutline(irr::core::recti(859, 694, 1012, 731), video::SColor(255, 255, 255, 255));
	} //end if Exit 
}

void CheckMouseHoverOverACCOUNTS(void)
{

	if (TASWindow == ACCOUNTSERVICEWINDOW)
	{
		//BANKING
		if ((mouse_position.X>294) && (mouse_position.X < 691) && (mouse_position.Y>233) && (mouse_position.Y < 282))
		{
			driver->draw2DRectangleOutline(irr::core::recti(294, 233, 691, 282), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(295, 234, 690, 281), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(296, 235, 689, 280), video::SColor(255, 255, 255, 255));
		} //BANKING

		//LOANS
		if ((mouse_position.X>294) && (mouse_position.X < 691) && (mouse_position.Y>356) && (mouse_position.Y < 403))
		{
			driver->draw2DRectangleOutline(irr::core::recti(294, 356, 691, 403), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(295, 357, 690, 402), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(296, 358, 689, 401), video::SColor(255, 255, 255, 255));
		} //LOANS

		//PERSONAL
		if ((mouse_position.X>294) && (mouse_position.X < 691) && (mouse_position.Y>473) && (mouse_position.Y < 522))
		{
			driver->draw2DRectangleOutline(irr::core::recti(294, 473, 691, 522), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(295, 474, 690, 521), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(296, 475, 689, 520), video::SColor(255, 255, 255, 255));
		} 	//PERSONAL
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760) && (loanboxcreated == 0))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end if EXIT BUTTON
	}

	else if (TASWindow == BANKINGWINDOW)
	{

		//Display ACCOUNT BALANCE
		if ((mouse_position.X > 531) && (mouse_position.X < 729) && (mouse_position.Y>391) && (mouse_position.Y < 438))
		{
			driver->draw2DRectangleOutline(irr::core::recti(530, 390, 730, 439), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(531, 391, 729, 438), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(532, 392, 728, 437), video::SColor(255, 255, 255, 255));
		}
		//ADD to balance
		if ((mouse_position.X >531) && (mouse_position.X < 729) && (mouse_position.Y >482) && (mouse_position.Y < 527))
		{
			driver->draw2DRectangleOutline(irr::core::recti(530, 481, 730, 528), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(531, 482, 729, 527), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(532, 483, 728, 526), video::SColor(255, 255, 255, 255));
		}
		//Withdraw from BALANCE
		if ((mouse_position.X > 531) && (mouse_position.X < 729) && (mouse_position.Y >568) && (mouse_position.Y < 616))
		{
			driver->draw2DRectangleOutline(irr::core::recti(530, 567, 730, 617), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(531, 568, 729, 616), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(532, 569, 728, 615), video::SColor(255, 255, 255, 255));
		}

		//Keypad 1
		if ((mouse_position.X >101) && (mouse_position.X < 207) && (mouse_position.Y >166) && (mouse_position.Y < 276) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(100, 165, 208, 277), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(101, 166, 207, 276), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(102, 167, 206, 275), video::SColor(255, 255, 255, 255));
			//circle
			/*
			driver->draw2DPolygon(core::position2d<s32>(153, 166 + 55), 59, video::SColor(255, 255, 255, 255), 20);
			driver->draw2DPolygon(core::position2d<s32>(153, 166 + 55), 58, video::SColor(255, 255, 255, 255), 20);
			driver->draw2DPolygon(core::position2d<s32>(153, 166 + 55), 57, video::SColor(255, 255, 255, 255), 20);
			driver->draw2DPolygon(core::position2d<s32>(153, 166 + 55), 56, video::SColor(255, 255, 255, 255), 20);
			*/
		}

		//Keypad 2
		if ((mouse_position.X  > 224) && (mouse_position.X  < 327) && (mouse_position.Y  >166) && (mouse_position.Y  < 276) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(223, 165, 328, 277), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(224, 166, 327, 276), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(225, 167, 326, 275), video::SColor(255, 255, 255, 255));
		}

		//Keypad 3
		if ((mouse_position.X > 346) && (mouse_position.X < 449) && (mouse_position.Y  > 166) && (mouse_position.Y  < 276) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(345, 165, 450, 277), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(346, 166, 449, 276), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(347, 167, 448, 275), video::SColor(255, 255, 255, 255));
		}

		//Keypad 4
		if ((mouse_position.X > 101) && (mouse_position.X < 207) && (mouse_position.Y >293) && (mouse_position.Y < 396) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(100, 292, 208, 397), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(101, 293, 207, 396), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(102, 294, 206, 395), video::SColor(255, 255, 255, 255));
		}

		//Keypad 5
		if ((mouse_position.X > 224) && (mouse_position.X < 327) && (mouse_position.Y >293) && (mouse_position.Y < 396) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(223, 292, 328, 397), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(224, 293, 327, 396), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(225, 294, 326, 395), video::SColor(255, 255, 255, 255));
		}

		//Keypad 6
		if ((mouse_position.X  > 346) && (mouse_position.X  < 449) && (mouse_position.Y > 293) && (mouse_position.Y < 396) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(345, 292, 450, 397), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(346, 293, 449, 396), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(347, 294, 448, 395), video::SColor(255, 255, 255, 255));
		}

		//Keypad 7
		if ((mouse_position.X  > 101) && (mouse_position.X  < 207) && (mouse_position.Y >415) && (mouse_position.Y < 523) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(100, 414, 208, 524), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(101, 415, 207, 523), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(102, 416, 206, 522), video::SColor(255, 255, 255, 255));
		}

		//Keypad 8
		if ((mouse_position.X > 224) && (mouse_position.X < 327) && (mouse_position.Y >415) && (mouse_position.Y < 523) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(223, 414, 328, 524), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(224, 415, 327, 523), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(225, 416, 326, 522), video::SColor(255, 255, 255, 255));
		}

		//Keypad 9
		if ((mouse_position.X > 346) && (mouse_position.X < 449) && (mouse_position.Y > 415) && (mouse_position.Y < 523) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(345, 414, 450, 524), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(346, 415, 449, 523), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(347, 416, 448, 522), video::SColor(255, 255, 255, 255));
		}

		//Keypad 0
		if ((mouse_position.X > 224) && (mouse_position.X < 327) && (mouse_position.Y >544) && (mouse_position.Y < 650) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount < 21))
		{
			driver->draw2DRectangleOutline(irr::core::recti(223, 543, 328, 651), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(224, 544, 327, 650), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(225, 545, 326, 649), video::SColor(255, 255, 255, 255));
		}

		//Keypad CANCEL
		if ((mouse_position.X > 101) && (mouse_position.X < 207) && (mouse_position.Y >544) && (mouse_position.Y < 650) && ((displaybalance == 2) || (displaybalance == 3)))
		{
			driver->draw2DRectangleOutline(irr::core::recti(100, 543, 208, 651), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(101, 544, 207, 650), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(102, 545, 206, 649), video::SColor(255, 255, 255, 255));
		}

		//Keypad ENTER
		if ((mouse_position.X >346) && (mouse_position.X < 449) && (mouse_position.Y > 544) && (mouse_position.Y < 650) && ((displaybalance == 2) || (displaybalance == 3)))
		{
			driver->draw2DRectangleOutline(irr::core::recti(345, 543, 450, 651), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(346, 544, 449, 650), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(347, 545, 448, 649), video::SColor(255, 255, 255, 255));
		}

		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end if EXIT BUTTON

	} //end of BANKINGWINDOW


	else if (TASWindow == LOANWINDOW)
	{
		if ((loanborrow == 1) && (loansubmit == 0) && (loanselection == 0))
		{
			if ((mouse_position.X > 211) && (mouse_position.X < 226) && (mouse_position.Y> 218) && (mouse_position.Y < 237)) {
				driver->draw2DImage(bluestar, core::position2d<s32>(205, 216), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 1
			}
			if ((mouse_position.X > 211) && (mouse_position.X < 226) && (mouse_position.Y > 281) && (mouse_position.Y < 296)) {
				driver->draw2DImage(bluestar, core::position2d<s32>(205, 274), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 2
			}
			if ((mouse_position.X > 211) && (mouse_position.X < 226) && (mouse_position.Y> 339) && (mouse_position.Y < 355)) {
				driver->draw2DImage(bluestar, core::position2d<s32>(206, 334), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 3
			}
			if ((mouse_position.X > 211) && (mouse_position.X < 226) && (mouse_position.Y > 398) && (mouse_position.Y < 414)) {
				driver->draw2DImage(bluestar, core::position2d<s32>(206, 392), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 4
			}
		} //end if SELECT a LOAN

		if (loansubmit == 1)
		{
			if ((mouse_position.X>856) && (mouse_position.X < 1025) && (mouse_position.Y>741) && (mouse_position.Y < 760))
			{
				driver->draw2DRectangleOutline(irr::core::recti(859, 737, 1024, 764), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(860, 738, 1023, 763), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(861, 739, 1022, 762), video::SColor(255, 255, 255, 255));
			} //end if EXIT
		} //end if LOAN PAPER WINDOW

		if ((loanborrow == 1) && (loansubmit == 0) && (loanselection > 0) && (loanboxcreated == 0))
		{
			if ((mouse_position.X > 724) && (mouse_position.X < 840) && (mouse_position.Y>664) && (mouse_position.Y < 700))
			{
				driver->draw2DRectangleOutline(irr::core::recti(719, 660, 840, 698), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(720, 661, 839, 697), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(721, 662, 838, 696), video::SColor(255, 255, 255, 255));
			} //end if SUBMIT button hoverover
		}//end SUBMIT button hoverover

		if (loansubmit == 0)
		{
			if ((mouse_position.X>716) && (mouse_position.X < 853) && (mouse_position.Y>592) && (mouse_position.Y < 629) && (loanboxcreated == 0))
			{
				driver->draw2DRectangleOutline(irr::core::recti(709, 588, 851, 627), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(710, 589, 850, 626), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(711, 590, 849, 625), video::SColor(255, 255, 255, 255));
			} //end if STARTLOAN button

			if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
			{
				driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
				driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
			} //end if EXIT BUTTON
		}//end if LOAN APPLICATION FORM
	} //END IF TASWINDOW=LOANWINDOW

	else if (TASWindow == PERSONALWINDOW)
	{   //EXIT to account window
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end if EXIT BUTTON

		//SET new date
		if ((mouse_position.X>363) && (mouse_position.X < 407) && (mouse_position.Y>660) && (mouse_position.Y < 688) && (uAccessLevel == 10))
		{
			driver->draw2DRectangleOutline(irr::core::recti(362, 659, 408, 689), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(363, 660, 407, 688), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(364, 661, 406, 687), video::SColor(255, 255, 255, 255));
		} //end if EXIT BUTTON
	}
}

void CheckMouseHoverOverCLASSIFIEDS(void)
{
	if (TASWindow == CLASSIFIEDMENU)
	{
		//FOR SALE
		if ((mouse_position.X>335) && (mouse_position.X < 630) && (mouse_position.Y>213) && (mouse_position.Y < 255))
		{
			driver->draw2DRectangleOutline(irr::core::recti(334, 212, 631, 256), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(335, 213, 630, 255), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(336, 214, 629, 254), video::SColor(255, 255, 255, 255));
		} //end if for sale

		//HELP WANTED - JOBS
		if ((mouse_position.X>335) && (mouse_position.X < 630) && (mouse_position.Y>280) && (mouse_position.Y < 330))
		{
			driver->draw2DRectangleOutline(irr::core::recti(334, 279, 631, 331), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(335, 280, 630, 330), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(336, 281, 629, 329), video::SColor(255, 255, 255, 255));
		} //end help wanted

		//MISSIONS
		if ((mouse_position.X>335) && (mouse_position.X < 630) && (mouse_position.Y>351) && (mouse_position.Y < 394))
		{
			driver->draw2DRectangleOutline(irr::core::recti(334, 350, 631, 395), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(335, 351, 630, 394), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(336, 352, 629, 393), video::SColor(255, 255, 255, 255));
		} //end if missions

		//return to MAIN WINDOW MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end return to main window
	}

	else if (TASWindow == FORSALEWINDOW)
	{
		//spacecraft
		if ((mouse_position.X>335) && (mouse_position.X < 630) && (mouse_position.Y>213) && (mouse_position.Y < 255))
		{
			driver->draw2DRectangleOutline(irr::core::recti(334, 212, 631, 256), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(335, 213, 630, 255), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(336, 214, 629, 254), video::SColor(255, 255, 255, 255));
		} //end if for sale

		//Vehicles
		if ((mouse_position.X>335) && (mouse_position.X < 630) && (mouse_position.Y>280) && (mouse_position.Y < 330))
		{
			driver->draw2DRectangleOutline(irr::core::recti(334, 279, 631, 331), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(335, 280, 630, 330), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(336, 281, 629, 329), video::SColor(255, 255, 255, 255));
		} //end help wanted

		//items
		if ((mouse_position.X>335) && (mouse_position.X < 630) && (mouse_position.Y>351) && (mouse_position.Y < 394))
		{
			driver->draw2DRectangleOutline(irr::core::recti(334, 350, 631, 395), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(335, 351, 630, 394), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(336, 352, 629, 393), video::SColor(255, 255, 255, 255));
		} //end if missions

		//return to MAIN classifieds MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end return to classifieds window
	}

	else if (TASWindow == FORSALEITEMSWINDOW)
	{
		//return to MAIN classifieds MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end return to classifieds window
	}

	else if (TASWindow == FORSALESPACECRAFTWINDOW)
	{
		//return to MAIN classifieds MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end return to classifieds window
	}

	else if (TASWindow == FORSALEVEHICLESWINDOW)
	{
		//return to MAIN classifieds MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end return to classifieds window
	}

	else if (TASWindow == MISSIONSWINDOW)
	{
		//generate mission
		if ((mouse_position.X>754) && (mouse_position.X < 954) && (mouse_position.Y> 509) && (mouse_position.Y < 559)) 
		{
			driver->draw2DRectangleOutline(irr::core::recti(753, 508, 955, 560), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(754, 509, 954, 559), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(755, 510, 953, 558), video::SColor(255, 255, 255, 255));
		}

		//save mission
		if ((mouse_position.X>754) && (mouse_position.X < 954) && (mouse_position.Y > 578) && (mouse_position.Y < 627)) 
		{
			driver->draw2DRectangleOutline(irr::core::recti(753, 577, 955, 628), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(754, 578, 954, 627), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(755, 579, 953, 626), video::SColor(255, 255, 255, 255));
		}

		//return to CLASSIFIEDS MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760)) 
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		}
	}

	else if (TASWindow == HELPWANTEDMENU)
	{
		//generate job
		if ((mouse_position.X>754) && (mouse_position.X < 954) && (mouse_position.Y> 509) && (mouse_position.Y < 559)) 
		{
			driver->draw2DRectangleOutline(irr::core::recti(753, 508, 955, 560), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(754, 509, 954, 559), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(755, 510, 953, 558), video::SColor(255, 255, 255, 255));
		}
		//save job
		if ((mouse_position.X>754) && (mouse_position.X < 954) && (mouse_position.Y> 578) && (mouse_position.Y < 627)) 
		{
			driver->draw2DRectangleOutline(irr::core::recti(753, 577, 955, 628), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(754, 578, 954, 627), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(755, 579, 953, 626), video::SColor(255, 255, 255, 255));
		}
		//return to CLASSIFIEDS MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		}
	}
}

void CheckMouseHoverOverXBOAT(void)
{
	if (TASWindow == XBOATMENU || TASWindow == XBOATREADMENU || TASWindow == XBOATREADNEWMENU || TASWindow == XBOATSENDMENU)
	{
	
		//return to MAIN XBOAT MENU
		if ((mouse_position.X>854) && (mouse_position.X < 1015) && (mouse_position.Y>745) && (mouse_position.Y < 760))
		{
			driver->draw2DRectangleOutline(irr::core::recti(849, 742, 1018, 763), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(850, 743, 1017, 762), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(851, 744, 1016, 761), video::SColor(255, 255, 255, 255));
		} //end return to XBOAT window

	}

	if (TASWindow == XBOATMENU)
	{
		//read message
		if ((mouse_position.X > 768) && (mouse_position.X < 965) && (mouse_position.Y > 432) && (mouse_position.Y < 475))
		{
			driver->draw2DRectangleOutline(irr::core::recti(767, 431, 966, 476), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(768, 432, 965, 475), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(769, 433, 964, 474), video::SColor(255, 255, 255, 255));
		}
		//SEND MESSAGE
		if ((mouse_position.X > 768) && (mouse_position.X < 965) && (mouse_position.Y > 362) && (mouse_position.Y < 407))
		{
			driver->draw2DRectangleOutline(irr::core::recti(767, 361, 966, 408), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(768, 362, 965, 407), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(769, 363, 964, 406), video::SColor(255, 255, 255, 255));
		}

	}
	if (TASWindow == XBOATREADMENU)
	{

		//READ NEW MESSAGE
		if ((mouse_position.X > 747) && (mouse_position.X < 982) && (mouse_position.Y  > 374) && (mouse_position.Y < 410) && (ismessagewaiting>0) && (newmailcount>0))
		{
			driver->draw2DRectangleOutline(irr::core::recti(746, 373, 983, 411), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(747, 374, 982, 410), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(748, 375, 981, 409), video::SColor(255, 255, 255, 255));
		}
		//READ OLD MESSAGE
		if ((mouse_position.X > 750) && (mouse_position.X < 980) && (mouse_position.Y  > 448) && (mouse_position.Y < 496) && (oldmailcount>0))
		{
			driver->draw2DRectangleOutline(irr::core::recti(749, 447, 981, 497), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(750, 448, 980, 496), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(751, 449, 979, 495), video::SColor(255, 255, 255, 255));
		}
	}

	if (TASWindow == XBOATREADNEWMENU)
	{
		//READNEXT
		if ((mouse_position.X > 285) && (mouse_position.X < 374) && (mouse_position.Y  > 700) && (mouse_position.Y < 739) && (ismessagewaiting>0) && (newmailcount>0))
		{
			//NEXT Button
			driver->draw2DImage(xboatnextbuttonover, core::position2d<s32>(285, 700), core::rect<s32>(0, 0, 89, 39), 0, video::SColor(255, 255, 255, 255), true);
		}
	}

	if (TASWindow == XBOATREADOLDMENU)
	{
		//READNEXT
		if ((mouse_position.X > 285) && (mouse_position.X < 374) && (mouse_position.Y  > 700) && (mouse_position.Y < 739) && (oldmailcount>0))
		{
			//NEXT Button
			driver->draw2DImage(xboatnextbuttonover, core::position2d<s32>(285, 700), core::rect<s32>(0, 0, 89, 39), 0, video::SColor(255, 255, 255, 255), true);
		}
	}
	if (TASWindow == XBOATSENDMENU)
	{
		//CLEAR MESSAGE
		if ((mouse_position.X  >783) && (mouse_position.X  <980) && (mouse_position.Y > 495) && (mouse_position.Y <544) && (newmessage == 1))
		{
			//clear button
			driver->draw2DRectangleOutline(irr::core::recti(782, 494, 981, 545), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(783, 495, 980, 544), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(784, 496, 979, 543), video::SColor(255, 255, 255, 255));
		}
		//CREATE NEW MESSAGE
		if ((mouse_position.X >783) && (mouse_position.X < 980) && (mouse_position.Y >433) && (mouse_position.Y < 480) && (newmessage == 0))
		{
			driver->draw2DRectangleOutline(irr::core::recti(782, 432, 981, 481), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(783, 433, 980, 480), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(784, 434, 979, 479), video::SColor(255, 255, 255, 255));
		}
		//SEND NEW COMPLETED MESSAGE
		if ((mouse_position.X  > 783) && (mouse_position.X < 980) && (mouse_position.Y  > 560) && (mouse_position.Y < 605) && (newmessage == 1)) 
		{
			driver->draw2DRectangleOutline(irr::core::recti(782, 559, 981, 606), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(783, 560, 980, 605), video::SColor(255, 255, 255, 255));
			driver->draw2DRectangleOutline(irr::core::recti(784, 561, 979, 604), video::SColor(255, 255, 255, 255));
		}
	}
}

void CheckMouseHoverOver(void)
{

	if (TASWindow == LOGINWINDOW) CheckMouseHoverOverLOGIN();

	if (TASCurrentMenuWindow == MAINMENUWINDOW) CheckMouseHoverOverMAIN();

	if (TASCurrentMenuWindow == NAVIGATIONWINDOW) CheckMouseHoverOverNAV();

	if (TASCurrentMenuWindow == NEWSWINDOW) CheckMouseHoverOverNEWS();

	if (TASCurrentMenuWindow == LIBDATAWINDOW) CheckMouseHoverOverLIBDATA();

	if (TASCurrentMenuWindow == ACCOUNTSERVICEWINDOW) CheckMouseHoverOverACCOUNTS();

	if (TASCurrentMenuWindow == CLASSIFIEDMENU) CheckMouseHoverOverCLASSIFIEDS();

	if (TASCurrentMenuWindow == XBOATMENU) CheckMouseHoverOverXBOAT();
} 

char *replace_str(char *str, char *orig, char *rep)
{
	static char buffer[4096];
	char *p;

	if (!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
		return str;

	strncpy(buffer, str, p - str); // Copy characters from 'str' start to 'orig' st$
	buffer[p - str] = '\0';

	sprintf(buffer + (p - str), "%s%s", rep, p + strlen(orig));

	return buffer;
}
