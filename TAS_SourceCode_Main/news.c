
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

int LoadNews(int queryyear, int newstype)
{
	long newsdatasize,tempnewsdatasize,i;

	FILE *FDR,*FDW2;

	int newsavailable=0,tempcounter=0,x=0,previousday=0;
	int endday=0;
	int thereisnews=0;
	char tmpdata[100];
	char* current;

	thereisnews=0; //set to 0 for no news yet
	newsdatacounter=0; //set page position to top of news

			//read news files checking for all during the current year going back
			//from current date

			newsdatasize=0;
			tempnewsdatasize=0;
			newsavailable=0;
			

			//make sure tempfile for news is clear
			FDR = fopen("news/tempnews.txt","w");
			fclose(FDR);

			//initially set the date range
			endday=NEWSDay;
			previousday=NEWSDay-45;	
			if (previousday < 1) previousday =1;
			//if it is the whole year
			if(TASWindow==ARCHIVENEWSWINDOW){
					previousday=1;
					endday=365;
			//if it is the same year as the current year
			//only show up to the current day...
				if(TASYear==queryyear){
					endday=NEWSDay;
				}
			} //end if archive
			if(TASWindow==RUMORSNEWSWINDOW){
					previousday=1;
					endday=365;
			//if it is the same year as the current year
			//only show up to the current day...
				if(TASYear==queryyear){
					endday=NEWSDay;
				}
			} //end if rumor

			if(previousday<=0) previousday=1;


			for (x=endday;x>=previousday;x--){
				if((newstype==CURRENTNEWS)||(newstype==ARCHIVENEWS)){
					sprintf(newsfilename,"news/%s/%d/%d.txt",EraName,queryyear,x);
				}
				if(newstype==RUMORNEWS) {
					sprintf(newsfilename,"news/%s/%d/r%d.txt",EraName,queryyear,x);
                }
				FDR=NULL;
				FDR = fopen(newsfilename, "r");
				if(FDR){
					newsavailable++; //number of news dates available
					fclose(FDR);
				}
			} //end for loop


		if (newsavailable>0){
			thereisnews=1;  //yes, we have news
			istherenews=1;
			//load all news
			tempcounter=0;

			for (x=endday;x>=previousday;x--){

				tempnewsdatasize=0;
				if((newstype==CURRENTNEWS)||(newstype==ARCHIVENEWS)){
					sprintf(newsfilename,"news/%s/%d/%d.txt",EraName,queryyear,x);
				}

				if(newstype==RUMORNEWS) {
                                        sprintf(newsfilename,"news/%s/%d/r%d.txt",EraName,queryyear,x);
				}
				FDR=NULL;
				FDR = fopen(newsfilename, "r");
				FDW2 = fopen("news/tempnews.txt", "a");

				if (FDR){
					while (!feof(FDR)){
						memset(tmpdata, 0, 100);
						fgets(tmpdata, sizeof(tmpdata), FDR);
						fputs(tmpdata, FDW2);
					}
					fclose(FDR);
				} //end if news file exists for specified day
				fclose(FDW2);
			}  //end of for loop subtracting days

			// now we load the tempnews.txt file which should only contain news from the past 45 days
			FDR = fopen("news/tempnews.txt","r");
			fseek(FDR,0,2);
			newsdatasize = FileLenCount("news/tempnews.txt");
			rewind(FDR);
			newsdatatext=(char *)malloc(newsdatasize+1);
			fread(newsdatatext, 1, newsdatasize, FDR);
			fclose(FDR);	
                        newsdatatext[newsdatasize]='\0';  //terminate the string 


						//Remove tab characters from library files
						current = (char *)malloc(strlen(newsdatatext) + 1);
						current = newsdatatext;
						i = 0;
						newsdatatext = '\0';
						realloc(newsdatatext, 1);
						newsdatatext = (char *)malloc(newsdatasize);
						while (current != '\0' && i < newsdatasize - 1)
						{
							if (*current != '\t')
								newsdatatext[i++] = *current;
							++current;
						}
						newsdatatext[i] = '\0';
						current = '\0';

						core::stringw w_newsdatatext = newsdatatext; //make text a wide char type


							textBox->setText(w_newsdatatext.c_str());

		}		
		//oh well - NO NEWS
		if(newsavailable<1)
		{                     		
			if((newstype==CURRENTNEWS)||(newstype==ARCHIVENEWS))
			{
				newsdatatext = (char *) calloc((unsigned)strlen("No news at this time"),sizeof(char));
				sprintf(newsdatatext,"No news at this time");
				newsdatatext[strlen("No news at this time")]='\0';
				core::stringw w_newsdatatext = newsdatatext; //make text a wide char type
				textBox->setText(w_newsdatatext.c_str());
			}
			if(newstype==RUMORNEWS) 
			{
				newsdatatext = (char *) calloc((unsigned)strlen("No rumors at this time"),sizeof(char));
				sprintf(newsdatatext,"No rumors at this time");
				newsdatatext[strlen("No rumors at this time")]='\0';
				core::stringw w_newsdatatext = newsdatatext; //make text a wide char type
				textBox->setText(w_newsdatatext.c_str());
			}
		}

		current = '\0';
	return thereisnews;
}

int checkmouseboundsnews(void)
{  

	int xlookup=0,ylookup=0,databreak=0;
	int txtcounter=0;



	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;

	//check to see if selection is on the grid
	if (xlookup<1) return NEWSSERVICEWINDOW;
	if (ylookup<1) return NEWSSERVICEWINDOW;

	//ARCHIVES
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>640)&&(ylookup<680)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow=ARCHIVENEWSWINDOW;
		TASCurrentMenuWindow=NEWSWINDOW;
		intarchiveyear=TASYear;
		backsurf = archivemenubmp;
		UpdateTheScreen = 1;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		istherenews=LoadNews(intarchiveyear,ARCHIVENEWS);
		return ARCHIVENEWSWINDOW;
	}

	//RUMORS

	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>694)&&(ylookup<734)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		UpdateTheScreen=1;
		TASWindow=RUMORSNEWSWINDOW;
		TASCurrentMenuWindow=NEWSWINDOW;
		intarchiveyear=TASYear;
		backsurf = rumormenubmp;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		istherenews=LoadNews(TASYear,RUMORNEWS);
		return RUMORSNEWSWINDOW;
	}
	

	//return to MAIN WINDOW MENU
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>745)&&(ylookup<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		
		TASWindow=MAINMENUWINDOW;
        TASCurrentMenuWindow=MAINMENUWINDOW;
		//clear bitmaps to save memmory
		if (textBox) textBox->remove(); //destroy textbox
		if (libdatatextimage) libdatatextimage->remove(); //remove background image
		backsurf = MainMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		return MAINMENUWINDOW;
	} 
	
        if(istherenews>0) {
	txtcounter=(int)strlen(newsdatatext);  //find max length of news data file
	}


	return NEWSSERVICEWINDOW;

}



void DisplayNewsData(void)
{

	char currentyear[81];
	char currentday[81];



	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);


	Courier10Green->draw(L"Displaying past 45 days of news for:", core::rect<s32>(720, 170, 0, 0), video::SColor(255, 255, 255, 255));
		 //put date
		 //set font for Optima 18 point
		// text color white
		sprintf(currentyear,"Current Year: %d",TASYear);
		sprintf(currentday, "         Day: %d", TASDay);
		//show current date
		Optima18White->draw(irr::core::stringw(currentyear).c_str(), core::rect<s32>(760, 200, 0, 0), video::SColor(255, 255, 255, 255));
		Optima18White->draw(irr::core::stringw(currentday).c_str(), core::rect<s32>(760, 240, 0, 0), video::SColor(255, 255, 255, 255));


}

int checkmouseboundsnewsarchive(void)
{  

	int xlookup=0,ylookup=0,databreak=0;
	int txtcounter=0;
	int istherenews=0;



	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;

	//check to see if selection is on the grid
	if (xlookup<1) return ARCHIVENEWSWINDOW;
	if (ylookup<1) return ARCHIVENEWSWINDOW;

	//CURRENT NEWS
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>640)&&(ylookup<680)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		intarchiveyear = TASYear;
		backsurf = NewsMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		UpdateTheScreen=1;
		TASWindow=NEWSSERVICEWINDOW;
		TASCurrentMenuWindow=NEWSWINDOW;
		intarchiveyear=TASYear;
		istherenews=LoadNews(TASYear,CURRENTNEWS);
		return NEWSSERVICEWINDOW;
	}
	//RUMORS

	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>694)&&(ylookup<734)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		intarchiveyear = TASYear;
		backsurf = rumormenubmp;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		UpdateTheScreen=1;
		TASWindow=RUMORSNEWSWINDOW;
		TASCurrentMenuWindow=NEWSWINDOW;
		intarchiveyear=TASYear;
		istherenews=LoadNews(TASYear,RUMORNEWS);
		return RUMORSNEWSWINDOW;
	}


	//return to main window
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>745)&&(ylookup<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter=0;
		txtcounter=0;
		TASWindow=MAINMENUWINDOW;
        TASCurrentMenuWindow=MAINMENUWINDOW;
		//clear bitmaps to save memmory
		//ClearNEWS();
		if (textBox) textBox->remove(); //destroy textbox
		if (libdatatextimage) libdatatextimage->remove(); //remove background image
		backsurf = MainMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		return MAINMENUWINDOW;
	} 

	//ARCHIVE YEAR INCREMENT
	if ((xlookup>940)&&(xlookup<970)&&(ylookup>232)&&(ylookup<265)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		if(TASYear>=(intarchiveyear+1)) intarchiveyear++;
		    istherenews=LoadNews(intarchiveyear,ARCHIVENEWS);
			return ARCHIVENEWSWINDOW;
	}
	//ARCHIVE YEAR DECREMENT
	if ((xlookup>940)&&(xlookup<970)&&(ylookup>315)&&(ylookup<350)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
        if((intarchiveyear-1)>=0) intarchiveyear--;
			istherenews=LoadNews(intarchiveyear,ARCHIVENEWS);
			return ARCHIVENEWSWINDOW;
	}

	return ARCHIVENEWSWINDOW;

}

void DisplayNewsArchiveData(void)
{

	char strarchiveyear[81];

	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	Courier10Green->draw(L"Displaying past year of news for:", core::rect<s32>(720, 70, 0, 0), video::SColor(255, 255, 255, 255));
	//put date
	sprintf(strarchiveyear, "%d", intarchiveyear);
	//show current date
	arial_24_yellow_blackout_bevel->draw(irr::core::stringw(strarchiveyear).c_str(), core::rect<s32>(800, 275, 0, 0), video::SColor(255, 255, 255, 255));
}

int checkmouseboundsnewsrumor()
{  

	int xlookup=0,ylookup=0,databreak=0;
	int txtcounter=0;
	int istherenews=0;



	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;


	//check to see if selection is on the grid
	if (xlookup<1) return RUMORSNEWSWINDOW;
	if (ylookup<1) return RUMORSNEWSWINDOW;

	//CURRENT NEWS
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>640)&&(ylookup<680)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		intarchiveyear = TASYear;
		backsurf = NewsMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		UpdateTheScreen = 1;
		TASWindow = NEWSSERVICEWINDOW;
		TASCurrentMenuWindow = NEWSWINDOW;
		intarchiveyear = TASYear;
		istherenews = LoadNews(TASYear, CURRENTNEWS);
		return NEWSSERVICEWINDOW;
	}
    //ARCHIVE
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>694)&&(ylookup<734)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		TASWindow = ARCHIVENEWSWINDOW;
		TASCurrentMenuWindow = NEWSWINDOW;
		intarchiveyear = TASYear;
		backsurf = archivemenubmp;
		UpdateTheScreen = 1;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		istherenews = LoadNews(intarchiveyear, ARCHIVENEWS);
		return ARCHIVENEWSWINDOW;
	}
	

	//return to main window
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>745)&&(ylookup<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter = 0;
		txtcounter = 0;
		TASWindow = MAINMENUWINDOW;
		TASCurrentMenuWindow = MAINMENUWINDOW;
		//clear bitmaps to save memmory
		//ClearNEWS();
		if (textBox) textBox->remove(); //destroy textbox
		if (libdatatextimage) libdatatextimage->remove(); //remove background image
		backsurf = MainMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		return MAINMENUWINDOW;
	} 

	//ARCHIVE YEAR INCREMENT
	if ((xlookup>940)&&(xlookup<970)&&(ylookup>232)&&(ylookup<265)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		if(TASYear>=(intarchiveyear+1)) intarchiveyear++;
		    istherenews=LoadNews(intarchiveyear,RUMORNEWS);
			return RUMORSNEWSWINDOW;
	}
	//ARCHIVE YEAR DECREMENT
	if ((xlookup>940)&&(xlookup<970)&&(ylookup>315)&&(ylookup<350)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
        if((intarchiveyear-1)>=0) intarchiveyear--;
			istherenews=LoadNews(intarchiveyear,RUMORNEWS);
			return RUMORSNEWSWINDOW;
	}

	//DISPLAY NEWS TEXT WITH SCROLLING

	

	return RUMORSNEWSWINDOW;

}

void DisplayNewsRumorData(void)
{
	char strarchiveyear[81];	

	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	Courier10Green->draw(L"Displaying past year of rumors for:", core::rect<s32>(720, 70, 0, 0), video::SColor(255, 255, 255, 255));
	//put date
	sprintf(strarchiveyear, "%d", intarchiveyear);
	//show current date
	arial_24_yellow_blackout_bevel->draw(irr::core::stringw(strarchiveyear).c_str(), core::rect<s32>(800, 275, 0, 0), video::SColor(255, 255, 255, 255));
}

void CheckNewsOfDay(void)
{
	char ntfilenamer[81];
	//check for news of the day -6 days

	NEWSDay = TASDay - 6;
	if (NEWSDay < 1) NEWSDay = 1;

	sprintf(ntfilenamer, "news/%s/%d/%d.txt", EraName, TASYear, NEWSDay);
	fd = NULL;
	fd = fopen(ntfilenamer, "r");
	if (fd){
		newstoday = TRUE; //set flag that there is new news
		fclose(fd);
	}
	else
	{
		newstoday = FALSE; //no new news
	}

}
