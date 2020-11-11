
/* 
	Traveller's Aid Society Access Terminal

	     by Perry Horner 2001
	  

  The Traveller game in all forms is owned by Far Future Enterprises. 
  Copyright 1977 - 2007 Far Future Enterprises. Traveller is a registered 
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



void InitLibDataString()
{
	//set initial display with instructions on how to search
	libdatatext = (char *)calloc((unsigned)strlen("TAS Library Database ready for input.  Press the SEARCH button, enter in your search term, press ENTER/RETURN. "), sizeof(char));
	sprintf(libdatatext, "TAS Library Database ready for input.  Press the SEARCH button, enter in your search term, press ENTER/RETURN.");
	libdatatext[strlen("TAS Library Database ready for input.  Press the SEARCH button, enter in your search term, press ENTER/RETURN.")] = '\0';
	w_libdatatext = libdatatext; //make text a wide char type
	textBox->setText(w_libdatatext.c_str());
}

int checkmouseboundslibdata()
{  

	int xlookup=0,ylookup=0,databreak=0;
	int txtcounter=0;

	

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;

	
	//check to see if selection is on the grid
	if (xlookup<1) return LIBDATAWINDOW;
	if (ylookup<1) return LIBDATAWINDOW;

	if (istherelibdata>0) {
		txtcounter = (int)strlen(libdatatext);  //find max length of library data file
	}

	//LIBDATA IMAGE SELECTION
	if ((libimagecount == 1) && (xlookup >760) && (xlookup <960) && (ylookup > 510) && (ylookup <560)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow = LIBDATAIMAGEWINDOW;
		TASCurrentMenuWindow = LIBDATAWINDOW;
		libdatatextimage->setVisible(false); //hide background image
		textBox->setVisible(false); //hide textbox of libdata
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		return LIBDATAIMAGEWINDOW;
	} //display associated library data image

	

	//SEARCH
	if ((xlookup>854) && (xlookup<1015) && (ylookup>692) && (ylookup<732) && (searchmenuitemavailable == 0) && (TASWindow == LIBDATASERVICEWINDOW)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow=LIBDATASEARCHWINDOW;
		TASCurrentMenuWindow=LIBDATAWINDOW;
		//search window
		searchentered = 0;
		libimagecount = 0;

		searchentered = CreateSearchBox();
		searchentered = 0;

		return LIBDATASERVICEWINDOW;
	}



	//return to MAIN WINDOW MENU
	if ((xlookup>854) && (xlookup<1015) && (ylookup>745) && (ylookup<760) && (searchmenuitemavailable==0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		TASWindow = MAINMENUWINDOW;
		TASCurrentMenuWindow = MAINMENUWINDOW;

		if (textBox) textBox->remove(); //destroy textbox
		if (libdatatextimage) libdatatextimage->remove(); //remove background image

		device->getGUIEnvironment()->setFocus(NULL);
		backsurf = MainMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);

		//clear bitmaps to save memmory
		//ClearLIBDATA();

		return MAINMENUWINDOW;
	} 
	
	

	return LIBDATASERVICEWINDOW;
	
}

int checkmouseboundslibdataimage()
{

	int xlookup = 0, ylookup = 0;



	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;


	//check to see if selection is on the grid
	if (xlookup<1) return LIBDATASERVICEWINDOW;
	if (ylookup<1) return LIBDATASERVICEWINDOW;

	//any mouse button click returns to library menu

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		libdatatextimage->setVisible(true);

		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		textBox->setVisible(true);
	
	return LIBDATASERVICEWINDOW;

}

void DisplaylibdataData(void)
{
	char tempcharsearch[40];

	   driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	   if (searchentered == 1)
	   {
		   sprintf(tempcharsearch, "%ls", w_libdatasearchword);
		   libdatasearchword = tempcharsearch;
		   searchentered = libdatasearch();
		   textBox->setText(w_libdatatext.c_str());
		   searchentered = 0;
	   }

	   if (istherelibdata>0)
	   {
		   
		   Courier10Yellow->draw(L"Searchword:", core::rect<s32>(260, 738, 0, 0), video::SColor(255, 255, 255, 255));
		   Courier10White->draw(w_libdatasearchword, core::rect<s32>(350, 738, 0, 0), video::SColor(255, 255, 255, 255));//searchword


		   //if there are associated images...
		   if (libimagecount > 1)
		   {
			   arial_24_yellow_blackout_bevel->draw(L"Multiple Images", core::rect<s32>(745, 510, 0, 0), video::SColor(255, 255, 255, 255));
			   Optima18White->draw(L"Search individual entries", core::rect<s32>(745, 540, 0, 0), video::SColor(255, 255, 255, 255));
			   Optima18White->draw(L"to view", core::rect<s32>(745, 560, 0, 0), video::SColor(255, 255, 255, 255));
		   }
		   //if there is an associated image...
		   if (libimagecount == 1)
		   {
			   driver->draw2DImage(libdataimagebutton, core::position2d<s32>(760, 510), core::rect<s32>(0, 0, 200, 50), 0, video::SColor(255, 255, 255, 255), true);
		   }
	   } //end if istherelibdata>0

}

void DisplaylibdataDataImage(void)
{
	driver->draw2DImage(libdatabmp, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
	//driver->draw2DImage(sublibdatablank, core::position2d<s32>(5, 5), core::rect<s32>(0, 0, 681, 584), 0, video::SColor(255, 255, 255, 255), false);
	driver->draw2DImage(libdataimage, core::position2d<s32>(38, 15), core::rect<s32>(0, 0, 616, 594), 0, video::SColor(255, 255, 255, 255), false);
}

/***************Create the search box*************/
int CreateSearchBox()
{
	


	if (editboxIDValue)
	{
		editboxIDValue->remove();
		editboxIDValue = NULL;
	}

		LibDataSearchBox = NULL;
		LibDataSearchBox = guienv->addEditBox(L"", rect<s32>(730, 255, 1004, 302), true, 0, 110);
		LibDataSearchBox->setMax(38);
		LibDataSearchBox->setAutoScroll(false);
		LibDataSearchBox->setMultiLine(false);
		LibDataSearchBox->setWordWrap(false);
		LibDataSearchBox->setOverrideFont(Courier10Black);
		//LibDataSearchBox->setOverrideColor(video::SColor(255, 0, 0, 255));
		LibDataSearchBox->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);
		guienv->setFocus(LibDataSearchBox);
		guienv->drawAll();
		searchmenuitemavailable = 1;
	return 0;
}


int libdatasearch()
{
	long libdatasize=0, templibdatasize=0;
	long i=0;
	int tempcounter=0,searchfound=0;
	int lngth=0; //string length
	FILE *FMAINLIB, *FDW, *FDW2; //library.txt, templibdata, templibdata2
	char tmpdata[100];
	char uppercasedata[100];
	char uppercasesearch[100];
	char libimagefilenamepath[120];
	char libimagefilename[100];

	const char* current;

	FILE * IMGCHK;

	//clear variables
	libdatasize = 0;
	templibdatasize = 0;
	libdatacounter = 0;
	searchfound = 0;
	librarydataavailable = 0;
	istherelibdata = 0;
	libimagecount = 0;

	//make sure tempfiles for libdata is clear
	FDW = fopen("temp/templibdata.txt", "w");
	fclose(FDW);

	FDW2 = fopen("temp/templibdata2.txt", "w");
	fclose(FDW2);

	//set and open correct master library data file by Era
	sprintf(libdatafilename, "librdata/%s/library.txt", EraName);
	FMAINLIB = fopen(libdatafilename, "r");
	if (FMAINLIB){
		librarydataavailable=1; //librarydata file available
		fclose(FMAINLIB);
	}
	else {
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not open %s\n", libdatafilename);
		fclose(ERR);
	}

	//custom library data
	sprintf(libdatafilename, "librdata/%s/mydata.txt", EraName);
	FMAINLIB = fopen(libdatafilename, "r");
	if (FMAINLIB){
		librarydataavailable = 1; //mydata file available
		fclose(FMAINLIB);
	}
	else {
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not open %s\n", libdatafilename);
		fclose(ERR);
	}

	//special collections library data
	sprintf(libdatafilename, "librdata/%s/speccoll.txt", EraName);
	FMAINLIB = fopen(libdatafilename, "r");
	if (FMAINLIB){
		librarydataavailable = 1; //special collections file available
		fclose(FMAINLIB);
	}
	else {
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not open %s\n", libdatafilename);
		fclose(ERR);
	}

	//If there is a library data file...
	if ((librarydataavailable>0) && (strlen(libdatasearchword)>1)){
		tempcounter = 0;
		templibdatasize = 0;
		FMAINLIB = NULL;
		FDW2 = NULL;
		FDW = NULL;

		//set and open correct master library data file by Era
		sprintf(libdatafilename, "librdata/%s/library.txt", EraName);
		FMAINLIB = fopen(libdatafilename, "r"); //open main library file

		//create tempfile to put found data
		FDW2 = fopen("temp/templibdata2.txt", "w");

		//------------------------------------------------------
		//read each line from the MASTER library file
		//------------------------------------------------------
		while (!feof(FMAINLIB))
		{
			memset(tmpdata, 0, 100);
			fgets(tmpdata, sizeof(tmpdata), FMAINLIB);
			 //if end of library data file
			if ((!strstr(tmpdata, "^^^^")) && (!strstr(tmpdata, "@@@@"))) {
				fputs(tmpdata, FDW2);
			}
			
			//allow for upper and lower case searching
			copy_string(uppercasedata, tmpdata);
			uppercase(uppercasedata);
			copy_string(uppercasesearch, libdatasearchword);
			uppercase(uppercasesearch);


			if (strstr(uppercasedata, uppercasesearch)){
				searchfound = 1; //search word found
				istherelibdata = 1;
			}

			if (searchfound == 0 && strstr(tmpdata, "^^^^")){
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "w");
			} 

			//is there an image?
			if ((searchfound == 1) && (strstr(tmpdata, "@@@@"))){
				libimagecount++;
				if (libimagecount < 2){


					lngth = strlen(&tmpdata[4]);
					while ((tmpdata[lngth + 4] == ' ') || (tmpdata[lngth + 4] == '\0'))
						lngth--;
					tmpdata[lngth+4] = '\0';
					
					strncpy(libimagefilename, strtok(tmpdata, "@@@@"),lngth);
					libimagefilename[lngth] = '\0';
					sprintf(libimagefilenamepath, "librdata/%s/%s", EraName, libimagefilename);

					if (!(IMGCHK = fopen(libimagefilenamepath, "r")))
					{
						ERR = fopen("error.txt", "a");
						fprintf(ERR, "Library Data:  Could not load image file %s\n", libimagefilenamepath);
						fclose(ERR);
						CleanUp();
						device->drop();
						return 1;
					}
					else fclose(IMGCHK);

					if (libdataimage) libdataimage->unlock();
					driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
					if (libdataimage) driver->removeTexture(libdataimage);
					libdataimage = driver->getTexture(libimagefilenamepath);
					//device->getVideoDriver()->makeColorKeyTexture(tempplanet, position2d<s32>(0, 0));
					libdataimage->regenerateMipMapLevels(0);
					if (libdataimage) libdataimage->lock(ETLM_READ_WRITE);
					if (libdataimage == NULL)
					{
						ERR = fopen("error.txt", "a");
						fprintf(ERR, "Library Data:  Could not load %s\n", libimagefilenamepath);
						fclose(ERR);
						CleanUp();
						device->drop();
						return 1;
					}
				}
			}

			if (searchfound == 1 && strstr(tmpdata, "^^^^")){
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "r");
				if (FDW2){
					FDW = fopen("temp/templibdata.txt", "a");
					while (!feof(FDW2))
					{
						memset(tmpdata, 0, 100);
						fgets(tmpdata, sizeof(tmpdata), FDW2);
						fputs(tmpdata, FDW);

					} //end while
					fprintf(FDW, "--------------------------------------------\n\n");
					fclose(FDW);
				}
					searchfound = 0;
					fclose(FDW2);
					FDW2 = fopen("temp/templibdata2.txt", "w");				
			} //end if searchfound		
		} // end master file search
		fclose(FMAINLIB);

		//------------------------------------------------------
		//set and open correct CUSTOM library data file by Era
		//------------------------------------------------------
		sprintf(libdatafilename, "librdata/%s/mydata.txt", EraName);
		FMAINLIB = fopen(libdatafilename, "r"); //open custom library file

		//create tempfile to put found data
		FDW2 = fopen("temp/templibdata2.txt", "w");

		//read each line from the master library file
		while (!feof(FMAINLIB))
		{
			memset(tmpdata, 0, 100);
			fgets(tmpdata, sizeof(tmpdata), FMAINLIB);
			if ((!strstr(tmpdata, "^^^^")) && (!strstr(tmpdata, "@@@@"))) {

				fputs(tmpdata, FDW2);
			}

			//allow for upper and lower case searching
			copy_string(uppercasedata, tmpdata);
			uppercase(uppercasedata);
			copy_string(uppercasesearch, libdatasearchword);
			uppercase(uppercasesearch);


			if (strstr(uppercasedata, uppercasesearch)){
				searchfound = 1; //search word found
				istherelibdata = 1;
			}

			if (searchfound == 0 && strstr(tmpdata, "^^^^")){
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "w");
			}

			//is there an image?
			if ((searchfound == 1) && (strstr(tmpdata, "@@@@"))){
				libimagecount++;
				if (libimagecount < 2){
					//load libdataimage

					lngth = strlen(&tmpdata[4]);
					while ((tmpdata[lngth + 4] == ' ') || (tmpdata[lngth + 4] == '\0'))
						lngth--;
					tmpdata[lngth + 4] = '\0';

					strncpy(libimagefilename, strtok(tmpdata, "@@@@"), lngth);
					libimagefilename[lngth] = '\0';
					sprintf(libimagefilenamepath, "librdata/%s/%s", EraName, libimagefilename);

					if (!(IMGCHK = fopen(libimagefilenamepath, "r")))
					{
						ERR = fopen("error.txt", "a");
						fprintf(ERR, "Library Data:  Could not load image file %s\n", libimagefilenamepath);
						fclose(ERR);
						CleanUp();
						device->drop();
						return 1;
					}
					else fclose(IMGCHK);

					if (libdataimage) libdataimage->unlock();
					driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
					if (libdataimage) driver->removeTexture(libdataimage);
					libdataimage = driver->getTexture(libimagefilenamepath);
					//device->getVideoDriver()->makeColorKeyTexture(tempplanet, position2d<s32>(0, 0));
					libdataimage->regenerateMipMapLevels(0);
					if (libdataimage) libdataimage->lock(ETLM_READ_WRITE);
					if (libdataimage == NULL)
					{
						ERR = fopen("error.txt", "a");
						fprintf(ERR, "Library Data:  Could not load %s\n", libimagefilenamepath);
						fclose(ERR);
						CleanUp();
						device->drop();
						return 1;
					}
				}
			}
			if (searchfound == 1 && strstr(tmpdata, "^^^^")){
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "r");
				if (FDW2){
					FDW = fopen("temp/templibdata.txt", "a");
					while (!feof(FDW2))
					{
						memset(tmpdata, 0, 100);
						fgets(tmpdata, sizeof(tmpdata), FDW2);
						fputs(tmpdata, FDW);

					} //end while
					fprintf(FDW, "--------------------------------------------\n\n");
					fclose(FDW);
				}
				searchfound = 0;
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "w");
			} //end if searchfound		
		} // end custom data file search
		fclose(FMAINLIB);

		//------------------------------------------------------
		//set and open correct SPECIAL COLLECTIONS data file by Era
		//------------------------------------------------------
		sprintf(libdatafilename, "librdata/%s/speccoll.txt", EraName);
		FMAINLIB = fopen(libdatafilename, "r"); //open custom library file

		//create tempfile to put found data
		FDW2 = fopen("temp/templibdata2.txt", "w");

		//read each line from the master library file
		while (!feof(FMAINLIB))
		{
			memset(tmpdata, 0, 100);
			fgets(tmpdata, sizeof(tmpdata), FMAINLIB);
			if ((!strstr(tmpdata, "^^^^")) && (!strstr(tmpdata, "@@@@"))) {

				fputs(tmpdata, FDW2);
			}

			//allow for upper and lower case searching
			copy_string(uppercasedata, tmpdata);
			uppercase(uppercasedata);
			copy_string(uppercasesearch, libdatasearchword);
			uppercase(uppercasesearch);


			if (strstr(uppercasedata, uppercasesearch)){
				searchfound = 1; //search word found
				istherelibdata = 1;
			}

			if (searchfound == 0 && strstr(tmpdata, "^^^^")){
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "w");
			}

			//is there an image?
			if ((searchfound == 1) && (strstr(tmpdata, "@@@@"))){
				
				libimagecount++;
				if (libimagecount < 2){
					//load libdataimage

					lngth = strlen(&tmpdata[4]);
					while ((tmpdata[lngth + 4] == ' ') || (tmpdata[lngth + 4] == '\0'))
						lngth--;
					tmpdata[lngth + 4] = '\0';

					strncpy(libimagefilename, strtok(tmpdata, "@@@@"), lngth);
					libimagefilename[lngth] = '\0';
					sprintf(libimagefilenamepath, "librdata/%s/%s", EraName, libimagefilename);

					if (!(IMGCHK = fopen(libimagefilenamepath, "r")))
					{
						ERR = fopen("error.txt", "a");
						fprintf(ERR, "Library Data:  Could not load image file %s\n", libimagefilenamepath);
						fclose(ERR);
						CleanUp();
						device->drop();
						return 1;
					}
					else fclose(IMGCHK);

					if (libdataimage) libdataimage->unlock();
					driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
					if (libdataimage) driver->removeTexture(libdataimage);
					libdataimage = driver->getTexture(libimagefilenamepath);
					//device->getVideoDriver()->makeColorKeyTexture(tempplanet, position2d<s32>(0, 0));
					libdataimage->regenerateMipMapLevels(0);
					if (libdataimage) libdataimage->lock(ETLM_READ_WRITE);
					if (libdataimage == NULL)
					{
						ERR = fopen("error.txt", "a");
						fprintf(ERR, "Library Data:  Could not load %s\n", libimagefilenamepath);
						fclose(ERR);
						CleanUp();
						device->drop();
						return 1;
					}
				}
			}
			if (searchfound == 1 && strstr(tmpdata, "^^^^") && (uAccessLevel >= ALSPECCOLL)){
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "r");
				if (FDW2){
					FDW = fopen("temp/templibdata.txt", "a");
					fprintf(FDW, "-----------SPECIAL COLLECTIONS ITEM------------\n\n");
					while (!feof(FDW2))
					{
						memset(tmpdata, 0, 100);
						fgets(tmpdata, sizeof(tmpdata), FDW2);
						fputs(tmpdata, FDW);

					} //end while
					fprintf(FDW, "---------END SPECIAL COLLECTIONS ITEM--------\n\n");
					fclose(FDW);
				}
				searchfound = 0;
				fclose(FDW2);
				FDW2 = fopen("temp/templibdata2.txt", "w");
			} //end if searchfound		
		} // end special collections data file search
		fclose(FMAINLIB);

		libdatasize = FileLenCount("temp/templibdata.txt");


		// now we load the templibdata.txt file which should only contain search items
		libdatatext = '\0';
		FDW = fopen("temp/templibdata.txt", "r");
		fseek(FDW, 0, 2);
		rewind(FDW);
		libdatatext = (char*)malloc(sizeof(char)* (libdatasize+1));
		templibdatasize = fread(libdatatext, sizeof(char), libdatasize, FDW);
		fclose(FDW);

		libdatatext[libdatasize] = '\0';

		//Remove tab characters from library files
		current = (char*)malloc(sizeof(char)* (strlen(libdatatext) + 1));
		current = libdatatext;
		i = 0;
		libdatatext = '\0';
		realloc(libdatatext, 1);
		libdatatext = (char *)malloc(libdatasize);
		while (current != '\0' && i < libdatasize - 1)
		{
			if (*current != '\t')
				libdatatext[i++] = *current;
			++current;
		}
		libdatatext[i] = '\0';
		//chop the @@@@ image filename
		char *pfound = strstr(libdatatext, "@@@@");
		if (pfound)
		{
			int dposfound = int(pfound - libdatatext);
			libdatatext[dposfound] = '\0';
		}

		if (istherelibdata == 0)
		{
			libdatatext = (char *)malloc(strlen("No library data file found"));
			//libdatatext = (char *)calloc((unsigned)strlen("No library data file found "), sizeof(char));
			sprintf(libdatatext, "No library data file found");
			libdatatext[strlen("No library data file found")] = '\0';
		}
		current = '\0';
		w_libdatatext = libdatatext; //make text a wide char type

	} //end if librarydataavailable

	else
	{
		//oh well - NO data
		realloc(libdatatext, 1);
		libdatatext = (char *)malloc(strlen("No library data file found"));
		//libdatatext = (char *)calloc((unsigned)strlen("No library data file found "), sizeof(char));
		sprintf(libdatatext, "No library data file found");
		libdatatext[strlen("No library data file found")] = '\0';
		istherelibdata = 0;
		w_libdatatext = libdatatext; //make text a wide char type
	}

	
	return 1;
}