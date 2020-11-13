
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



*/


/**************************************
Randomclassifieds
Select random ads to show
***************************************/
void RandomClassifieds(void)
{
	char adfilename[255] = "\0";
	int advertiseload = 0;
	int AdNumber = 0;
	FILE *FDP = NULL;


	//***********SPACECRAFT*******************
	AdNumber = 1;  //set TASAd to 1 to start while loop
	advertiseload = 0;
	//create random number between 1 and 100 for advertisement
	while (advertiseload == 0){
		AdNumber = (int)rand() % (100) + 1;
		if (AdNumber<1) AdNumber = 1;
		if (AdNumber>100) AdNumber = 1;

		sprintf(adfilename, "bmaps/classifieds/forsale/S%i.jpg", AdNumber);
		//load randomly selected advertisement bitmap

		FDP = NULL;
		FDP = fopen(adfilename, "r");
		if (FDP){
			advertiseload = 1;
			fclose(FDP);
		}
		//load spacecraft
		if (advertiseload>0){
			if (FSSpacecraftAd) FSSpacecraftAd->unlock();
			if (FSSpacecraftAd) driver->removeTexture(FSSpacecraftAd);
			FSSpacecraftAd = driver->getTexture(adfilename);
			if (FSSpacecraftAd) FSSpacecraftAd->lock(ETLM_READ_WRITE);
			if (FSSpacecraftAd == NULL)
			{
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "CLASSIFIEDS:  Could not load %s\n\n", adfilename);
				fclose(ERR);
				CleanUp();
				device->drop();
			}
		} //end if advertiseload>0
		
	} //end while advertiseload=0

		//**********End Spacecraft***************


		//***********VEHICLE*******************
		AdNumber = 1;  //set TASAd to 1 to start while loop
		advertiseload = 0;
		//create random number between 1 and 100 for advertisement
		while (advertiseload == 0){
			AdNumber = (int)rand() % (100) + 1;
			if (AdNumber<1) AdNumber = 1;
			if (AdNumber>100) AdNumber = 1;

			sprintf(adfilename, "bmaps/classifieds/forsale/V%i.jpg", AdNumber);
			//load randomly selected advertisement bitmap

			FDP = NULL;
			FDP = fopen(adfilename, "r");
			if (FDP){
				advertiseload = 1;
				fclose(FDP);
			}
				//load Vehicle advertisement
				if (advertiseload>0){
					if (FSVehicleAd) FSVehicleAd->unlock();
					if (FSVehicleAd) driver->removeTexture(FSVehicleAd);
					FSVehicleAd = driver->getTexture(adfilename);
					if (FSVehicleAd) FSVehicleAd->lock(ETLM_READ_WRITE);
					if (FSVehicleAd == NULL)
					{
						ERR = fopen("error.txt", "a");
						fprintf(ERR, "CLASSIFIEDS:  Could not load %s\n\n", adfilename);
						fclose(ERR);
						CleanUp();
						device->drop();
					}
				} //end if advertiseload>0

		} //end while advertiseload=0

		//**********End Vehicle***************

		//***********ITEM*******************
		AdNumber = 1;  //set TASAd to 1 to start while loop
		advertiseload = 0;
		//create random number between 1 and 100 for advertisement
		while (advertiseload == 0){
			AdNumber = (int)rand() % (100) + 1;
			if (AdNumber<1) AdNumber = 1;
			if (AdNumber>100) AdNumber = 1;

			sprintf(adfilename, "bmaps/classifieds/forsale/I%i.jpg", AdNumber);
			//load randomly selected advertisement bitmap

		FDP = NULL;
		FDP = fopen(adfilename, "r");
		if (FDP){
			advertiseload = 1;
			fclose(FDP);
		}
		//load Vehicle advertisement
		if (advertiseload>0){
			if (FSItemAd) FSItemAd->unlock();
			if (FSItemAd) driver->removeTexture(FSItemAd);
			FSItemAd = driver->getTexture(adfilename);
			if (FSItemAd) FSItemAd->lock(ETLM_READ_WRITE);
			if (FSItemAd == NULL)
			{
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "CLASSIFIEDS:  Could not load %s\n\n", adfilename);
				fclose(ERR);
				CleanUp();
				device->drop();
			}
		} //end if advertiseload>0

		} //end while advertiseload=0
	//**********End Item***************

}

int checkmouseboundsClassifieds(void)
{

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	

	//check to see if selection is on the grid
	if (mouse_position.X<1) return CLASSIFIEDMENU;
	if (mouse_position.Y<1) return CLASSIFIEDMENU;

	
	//FOR SALE
	if ((mouse_position.X>335) && (mouse_position.X<630) && (mouse_position.Y>213) && (mouse_position.Y<255)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow = FORSALEWINDOW;
		TASCurrentMenuWindow = CLASSIFIEDMENU;
		return FORSALEWINDOW;
	}
	
	//HELP WANTED - JOBS
	if ((mouse_position.X>335) && (mouse_position.X<630) && (mouse_position.Y>280) && (mouse_position.Y<330)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow = HELPWANTEDMENU;
		TASCurrentMenuWindow = CLASSIFIEDMENU;
		Salary = 0;
		sprintf(JobName, "                                                                      \0");
		sprintf(CompanyName, "                                                                      \0");
		//RANDOMIZE using job seed from login
		srand(JobSeed);
		return HELPWANTEDMENU;
	}
	
	//MISSIONS
	if ((mouse_position.X>335) && (mouse_position.X<630) && (mouse_position.Y>351) && (mouse_position.Y<394)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		if (uAccessLevel >= ALMERC){
			DisplayMissionData();
			TASWindow = MISSIONSWINDOW;
			TASCurrentMenuWindow = CLASSIFIEDMENU;
			return MISSIONSWINDOW;
		}
		else{

			//Mix_PlayChannel(-1, SoundDenied, 0); //do access denied sound
			IGUIWindow* window = guienv->addMessageBox(L"DENIED", L"TAS Access Level too low", false, EMBF_OK, 0, -1, 0);
			window->setDrawBackground(true);
		} //access level too low
	}
	
	//return to MAIN WINDOW MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		backsurf = MainMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		TASWindow = MAINMENUWINDOW;
		TASCurrentMenuWindow = MAINMENUWINDOW;
		return MAINMENUWINDOW;
	}
	

	return CLASSIFIEDMENU;

}

int checkmouseboundsForSale(void)
{

	//check to see if selection is on the grid
	if (mouse_position.X<1) return FORSALEWINDOW;
	if (mouse_position.Y<1) return FORSALEWINDOW;

	
	//FOR SALE Spacecraft
	if ((mouse_position.X>335) && (mouse_position.X<630) && (mouse_position.Y>213) && (mouse_position.Y<255)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow = FORSALESPACECRAFTWINDOW;
		TASCurrentMenuWindow = CLASSIFIEDMENU;
		return FORSALESPACECRAFTWINDOW;
	}
	//FOR SALE Vehicles
	if ((mouse_position.X>335) && (mouse_position.X<630) && (mouse_position.Y>279) && (mouse_position.Y<327)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow = FORSALEVEHICLESWINDOW;
		TASCurrentMenuWindow = CLASSIFIEDMENU;
		return FORSALEVEHICLESWINDOW;
	}

	//FOR SALE Items
	if ((mouse_position.X>335) && (mouse_position.X <630) && (mouse_position.Y>350) && (mouse_position.Y<398)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow = FORSALEITEMSWINDOW;
		TASCurrentMenuWindow = CLASSIFIEDMENU;
		return FORSALEITEMSWINDOW;
	}

	//return to CLASSIFIEDS MENU
	if ((mouse_position.X>854) && (mouse_position.X <1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter = 0;	
		TASWindow = CLASSIFIEDMENU;
		TASCurrentMenuWindow = CLASSIFIEDMENU;
	
		return CLASSIFIEDMENU;
	}
	
	return FORSALEWINDOW;
}

int checkmouseboundsFSItems(void)
{

	//check to see if selection is on the grid
	if (mouse_position.X<1) return FORSALEITEMSWINDOW;
	if (mouse_position.Y<1) return FORSALEITEMSWINDOW;


	//return to FOR SALE MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter = 0;
		TASWindow = FORSALEWINDOW;
		TASCurrentMenuWindow = CLASSIFIEDMENU;

		return FORSALEWINDOW;
	}

	return FORSALEITEMSWINDOW;
}

int checkmouseboundsFSSpacecraft(void)
{

	//check to see if selection is on the grid
	if (mouse_position.X<1) return FORSALESPACECRAFTWINDOW;
	if (mouse_position.Y<1) return FORSALESPACECRAFTWINDOW;


	

	//return to FOR SALE MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter = 0;
		TASWindow = FORSALEWINDOW;
		TASCurrentMenuWindow = CLASSIFIEDMENU;

		return FORSALEWINDOW;
	}

	return FORSALESPACECRAFTWINDOW;
}

int checkmouseboundsFSVehicles(void)
{


	//check to see if selection is on the grid
	if (mouse_position.X<1) return FORSALEVEHICLESWINDOW;
	if (mouse_position.Y<1) return FORSALEVEHICLESWINDOW;




	//return to FOR SALE MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter = 0;
		TASWindow = FORSALEWINDOW;
		TASCurrentMenuWindow = CLASSIFIEDMENU;

		return FORSALEWINDOW;
	}

	return FORSALEVEHICLESWINDOW;
}

int checkmouseboundsJobs(void)
{

	FILE *FDC;
	int templines = 0;
	char jobfilename[81];
	char tempfile[81];


	sprintf(jobfilename, "saved/jobs/Member-%d_%d-%d.txt",MemberNumber,TASDay,TASYear);



	//check to see if selection is on the grid
	if (mouse_position.X<1) return HELPWANTEDMENU;
	if (mouse_position.Y<1) return HELPWANTEDMENU;

	//generate job
	if ((mouse_position.X>754) && (mouse_position.X<954) && (mouse_position.Y> 509) && (mouse_position.Y<559)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		sprintf(JobName, "                                                                      \0");
		sprintf(CompanyName, "                                                                      \0");
		Generate_Job_ad();
		TASWindow = HELPWANTEDMENU;
		return HELPWANTEDMENU;

	}

	//save job
	if ((mouse_position.X>754) && (mouse_position.X<954) && (mouse_position.Y> 578) && (mouse_position.Y<627)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		FDC = fopen(jobfilename, "a");
		fprintf(FDC, "%s\n", JobName);
		fprintf(FDC, "%s\n", CompanyName);
		fprintf(FDC, "Weekly Salary: %d cr\n", Salary);
		fprintf(FDC, "Application Date: %s\n", currentdate);
		fprintf(FDC, "######################################################\n");
		fclose(FDC);

		//send mail message to administrator with statement
		FDC = NULL;
		sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");
		FDC = fopen(tempfile, "a");
		fprintf(FDC, "Job Application Administrator\n"); //message recipient TO: (TAS member number or other name)
		fprintf(FDC, "TAS Classified Services", xbdestination); //message destination system or world
		fprintf(FDC, "%s\n", currentdate); //current send date
		fprintf(FDC, "%s\n", uName); //sender username
		fprintf(FDC, "%d\n", MemberNumber); //sender TAS member number
		fprintf(FDC, "0\n"); //message marked unread
		fprintf(FDC, "JOB APPLICATION FOR: %s\n", uName);
		fprintf(FDC, "%s\n", JobName);
		fprintf(FDC, "%s\n", CompanyName);
		fprintf(FDC, "Weekly Salary: %d cr\n", Salary);
		fprintf(FDC, "Application Date: %s\n", currentdate);
		fprintf(FDC, "~~CUT~~\n");
		fclose(FDC);

		//send mail message to TAS member applicant
		FDC = NULL;
		sprintf(tempfile, "communications/messages/mailbox/%d.msg", MemberNumber);
		FDC = fopen(tempfile, "a");
		fprintf(FDC, "%s\n", uName); //message recipient TO: (TAS member number or other name)
		fprintf(FDC, "TAS Mail Terminal\n", xbdestination); //message destination system or world
		fprintf(FDC, "%s\n", currentdate); //current send date
		fprintf(FDC, "TAS Classified Ad Agent\n"); //sender username
		fprintf(FDC, "0\n"); //sender TAS member number
		fprintf(FDC, "0\n"); //message marked unread
		fprintf(FDC, "JOB APPLICATION FOR: %s\n", uName);
		fprintf(FDC, "%s\n", JobName);
		fprintf(FDC, "%s\n", CompanyName);
		fprintf(FDC, "Weekly Salary: %d cr\n", Salary);
		fprintf(FDC, "Application Date: %s\n", currentdate);
		fprintf(FDC, "~~CUT~~\n");
		fclose(FDC);


		//refresh mailbox
		Clear_Mailbox();
		Load_Mailbox();

		IGUIWindow* window = guienv->addMessageBox(L"APPLICATION SENT", L"APPLICATION SENT", false, EMBF_OK, 0, -1, 0);

		window->setDrawBackground(true);



	} //end if save job

	//return to CLASSIFIEDS MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter = 0;
		TASWindow = CLASSIFIEDMENU;
		TASCurrentMenuWindow = CLASSIFIEDMENU;
		libdatatext = '\0';
		return CLASSIFIEDMENU;
	}

	return HELPWANTEDMENU;
}

int checkmouseboundsMissions(void)
{

	FILE *FDC;
	char tempfile[81];
	char missionfilename[81];
	int templines = 0;


	sprintf(missionfilename, "saved/missions/Member-%d_%d-%d.txt", MemberNumber, TASDay, TASYear);



	//check to see if selection is on the grid
	if (mouse_position.X<1) return MISSIONSWINDOW;
	if (mouse_position.Y<1) return MISSIONSWINDOW;

	//generate mission
	if ((mouse_position.X>754) && (mouse_position.X<954) && (mouse_position.Y> 509) && (mouse_position.Y<559)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		CreateMissionData();
		LoadMissionData();
		textBox->setText(w_libdatatext.c_str());
		TASWindow = MISSIONSWINDOW;
		return MISSIONSWINDOW;

	}

	//save mission
	if ((mouse_position.X>754) && (mouse_position.X<954) && (mouse_position.Y > 578) && (mouse_position.Y<627)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		FDC = fopen(missionfilename, "a");
		fprintf(FDC, "%s", libdatatext);
		fprintf(FDC, "######################################################\n");
		fprintf(FDC, "~~CUT~~\n");
		fclose(FDC);

		IGUIWindow* window = guienv->addMessageBox(L"APPLICATION SENT", L"APPLICATION SENT",false, EMBF_OK, 0, -1, 0);

		window->setDrawBackground(true);

		//send mail message to administrator with statement
		FDC = NULL;
		sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");
		FDC = fopen(tempfile, "a");
		fprintf(FDC, "TAS Mission Admin\n"); //message recipient TO: (TAS member number or other name)
		fprintf(FDC, "TAS Mail Terminal\n", xbdestination); //message destination system or world
		fprintf(FDC, "%s\n", currentdate); //current send date
		fprintf(FDC, "%s\n",uName); //sender username
		fprintf(FDC, "%d\n", MemberNumber); //sender TAS member number
		fprintf(FDC, "0\n"); //message marked unread
		fprintf(FDC, "MISSION REQUEST FOR: %s\n", uName);
		fprintf(FDC, "Saved to: %s\n", missionfilename);
		fprintf(FDC, "\n");
		fprintf(FDC, "\n");
		fprintf(FDC, "\n");
		fprintf(FDC, "~~CUT~~\n");
		fclose(FDC);

		//send mail message to TAS member
		FDC = NULL;
		sprintf(tempfile, "communications/messages/mailbox/%d.msg", MemberNumber);
		FDC = fopen(tempfile, "a");
		fprintf(FDC, "%s\n", uName); //message recipient TO: (TAS member number or other name)
		fprintf(FDC, "TAS Mail Terminal\n", xbdestination); //message destination system or world
		fprintf(FDC, "%s\n", currentdate); //current send date
		fprintf(FDC, "TAS Mission Appliction Administrator\n"); //sender username
		fprintf(FDC, "0\n"); //sender TAS member number
		fprintf(FDC, "0\n"); //mail unread
		fprintf(FDC, "MISSION REQUEST FOR: %s\n", uName);
		fprintf(FDC, "%s", libdatatext);
		fprintf(FDC, "\n");
		fprintf(FDC, "~~CUT~~\n");
		fclose(FDC);

		//refresh mailbox
		Clear_Mailbox();
		Load_Mailbox();

	} //end if save mission

	//return to CLASSIFIEDS MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) 
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newsdatacounter = 0;
		TASWindow = CLASSIFIEDMENU;
		TASCurrentMenuWindow = CLASSIFIEDMENU;		
		if (textBox) textBox->remove(); //destroy textbox
		if (libdatatextimage) libdatatextimage->remove(); //remove background image
		backsurf = classifiedmenu;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		return CLASSIFIEDMENU;
	}

	return MISSIONSWINDOW;
}

void DisplayClassifiedsMenu(void)
{


	if (backsurf != classifiedmenu){

		backsurf = classifiedmenu;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
	}

}

void DisplayForSaleWindow(void)
{

	backsurf = foresalemenu;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

}

void DisplayFSSpacecraftWindow(void)
{

	backsurf = FSspacecraft;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	driver->draw2DImage(FSSpacecraftAd, core::position2d<s32>(220, 190), core::rect<s32>(0, 0, 500, 480), 0, video::SColor(255, 255, 255, 255), true); //spacecraft advertisement

}

void DisplayFSVehicleWindow(void)
{

	backsurf = FSvehicles;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	driver->draw2DImage(FSVehicleAd, core::position2d<s32>(220, 190), core::rect<s32>(0, 0, 500, 480), 0, video::SColor(255, 255, 255, 255), true); //vehicle advertisement

}

void DisplayFSItemsWindow(void)
{

	backsurf = FSitems;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	driver->draw2DImage(FSItemAd, core::position2d<s32>(220, 190), core::rect<s32>(0, 0, 500, 480), 0, video::SColor(255, 255, 255, 255), true); //items advertisement

}

void DisplayMissionsMenu(void)
{
	
	char available[81];


	backsurf = missionsmenu;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	sprintf(available, "Missions Available: %d", NumberofMercTickets);

	Optima18White->draw(irr::core::stringw(available).c_str(), core::rect<s32>(755, 220, 0, 0), video::SColor(255, 255, 255, 255));

	

}

void DisplayHelpWantedMenu(void)
{

	backsurf = helpwantedmenu;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	DisplayJobData();

}

void LoadMissionData(void)
{
	
	FILE *FDC;

	int libdatasize = 0, i=0;

	char *current;


	FDC = fopen("temp/tempmission.txt", "r");
	fseek(FDC, 0, 2);
	libdatasize = FileLenCount("temp/tempmission.txt");
	rewind(FDC);
	libdatatext = (char *)malloc(libdatasize + 1);
	fread(libdatatext, 1, libdatasize, FDC);
	fclose(FDC);
	libdatatext[libdatasize] = '\0';  //terminate the string 

	current = (char *)malloc(strlen(libdatatext) + 1);
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
	current = '\0';

	w_libdatatext = libdatatext; //make text a wide char type
}

void CreateMissionData(void)

{
	
	FILE *FDW;

	int dieroll = 0, dieroll2 = 0, dieroll3 = 0; //die roll

	int targettype = 0; //1=defensive, 2=neutral, 3=offensive
	int paygrade = 0; //compensation grade


	// adapted from Mercenery Ticket generation rules at: http://www.traveller-srd.com/mercenary/mercenary-tickets

	if (MercTicketsRemaining == 0) MercTicketsRemaining = NumberofMercTickets;
	if (MercTicketsRemaining == NumberofMercTickets){
		srand(MissionSeed); //keep the same mission info for the entire TAS terminal session (no cheating)
	}
	//STEP 1- Randomize
	dieroll = (rand() % (12)) + 1;
	if (dieroll == 0) dieroll = 1;

	//STEP 2- TAS researched information on employer

	//make sure tempfiles for libdata is clear
	FDW = fopen("temp/tempmission.txt", "w");
	fclose(FDW);

	FDW = fopen("temp/tempmission.txt", "a");


	fprintf(FDW, "TICKET#:%d\n", MercTicketsRemaining);
	MercTicketsRemaining--;

	fprintf(FDW, "TAS researched employer background:\n");
	if (dieroll <= 2) fprintf(FDW, "Employer is trying to remain anonymous and use false nomenclature to protect itself.\n");
	if ((dieroll > 2) && (dieroll < 6)) fprintf(FDW, "Employer is purposefully vague on important details.\n");
	if ((dieroll>5) && (dieroll < 9)) fprintf(FDW, "Employer is perfectly honest in the ticket, but details are little more than title and mode of communication.\n");
	if ((dieroll>8) && (dieroll < 11)) fprintf(FDW, "Honest details, including the employing agent's name and direct communication.\n");
	if (dieroll == 11) fprintf(FDW, "Honest and very detailed information about the employer.\n");
	if (dieroll == 12) fprintf(FDW, "Private Ticket: employer is honest, but is willing to pay extra to keep the information secret.\n");

	fprintf(FDW, "_____________________________________________________________________\n\n");

	//Step 2.1 - Initial paygrade
	dieroll = (rand() % (6)) + 1;
	switch (dieroll){
	case 1:{
			   paygrade -= 4;
			   break;
	}
	case 2:{
			   paygrade -= 2;
			   break;
	}
	case 3:{
			   break;
	}
	case 4:{
			   break;
	}
	case 5:{
			   dieroll2 = (rand() % (6)) + 1;
			   if (dieroll2 == 1) paygrade += (rand() % (6)) + 1;
			   if (dieroll2 == 2) paygrade += (rand() % (6)) + 2;
			   if (dieroll2 == 3) paygrade += (rand() % (6)) + 3;
			   if (dieroll2 == 4) paygrade += (rand() % (6)) + 4;
			   if (dieroll2 == 5) paygrade += (rand() % (12)) + 1;
			   if (dieroll2 == 6) paygrade += (rand() % (6)) + 3;
			   break;
	}
	case 6:{
			   dieroll2 = (rand() % (6)) + 1;
			   if (dieroll2 == 1) paygrade += (rand() % (6)) + 1;
			   if (dieroll2 == 2) paygrade += (rand() % (6)) + 2;
			   if (dieroll2 == 3) paygrade += (rand() % (6)) + 3;
			   if (dieroll2 == 4) paygrade += (rand() % (6)) + 4;
			   if (dieroll2 == 5) paygrade += (rand() % (12)) + 1;
			   if (dieroll2 == 6) paygrade += (rand() % (6)) + 3;

			   dieroll2 = (rand() % (6)) + 1;
			   if (dieroll2 == 1) paygrade += (rand() % (6)) + 1;
			   if (dieroll2 == 2) paygrade += (rand() % (6)) + 2;
			   if (dieroll2 == 3) paygrade += (rand() % (6)) + 3;
			   if (dieroll2 == 4) paygrade += (rand() % (6)) + 4;
			   if (dieroll2 == 5) paygrade += (rand() % (12)) + 1;
			   if (dieroll2 == 6) paygrade += (rand() % (6)) + 3;
			   break;
	}
	default:{
				break;
	}

	} //end switch


	//STEP 3 – Service Required

	//3.1 service type

	fprintf(FDW, "Service Type:");

	dieroll3 = (rand() % (13)) + 1;
	if (dieroll3 == 0) dieroll = 13;


	if (dieroll3 < 2){
		fprintf(FDW, "Criminal-");

		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "Assassination\n");
					 targettype = 3; //offensive
					 paygrade = 5;
					 break;
		}
		case 2:{
				   fprintf(FDW, "Raid\n");
				   targettype = 3; //offensive
				   paygrade = 1;
				   break;
		}
		case 3:{
				   fprintf(FDW, "Raid\n");
				   targettype = 3; //offensive
				   paygrade = 2;
				   break;
		}
		case 4:{
				   fprintf(FDW, "Raid\n");
				   targettype = 3; //offensive
				   paygrade = 3;
				   break;
		}
		case 5:{
				   fprintf(FDW, "Sabotage\n");
				   targettype = 3; //offensive
				   paygrade = 3;
				   break;
		}
		case 6:{
				   fprintf(FDW, "Unlawful Acquisition\n");
				   targettype = 3; //offensive
				   paygrade = 4;
				   break;
		}
		default:{
					fprintf(FDW, "Raid\n");
					targettype = 3; //offensive
					paygrade = 1;
					break;
		}
		} //end switch

	}

	if (dieroll3 == 2){
		fprintf(FDW, "Guerrilla-");
		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "Sabotage\n");
					 targettype = 3; //offensive
					 paygrade = 1;
					 break;
		}
		case 2:{
				   fprintf(FDW, "Sabotage\n");
				   targettype = 3; //offensive
				   paygrade = 2;
				   break;
		}
		case 3:{
				   fprintf(FDW, "Terrorize\n");
				   targettype = 3; //offensive
				   paygrade = 4;
				   break;
		}
		case 4:{
				   fprintf(FDW, "Assassination\n");
				   targettype = 3; //offensive
				   paygrade = 4;
				   break;
		}
		case 5:{
				   fprintf(FDW, "Recon\n");
				   targettype = 2; //neutral
				   paygrade = 2;
				   break;
		}
		case 6:{
				   fprintf(FDW, "First Strike\n");
				   targettype = 3; //offensive
				   paygrade = 3;
				   break;
		}
		default:{
					fprintf(FDW, "Sabotage\n");
					targettype = 3; //offensive
					paygrade = 1;
					break;
		}
		} //end switch

	}
	if ((dieroll3 == 3) || (dieroll3 == 4)){
		fprintf(FDW, "Cadre-");
		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "Train\n");
					 paygrade = 1;
					 targettype = 1; //defensive
					 break;
		}
		case 2:{
				   fprintf(FDW, "Train\n");
				   paygrade = 2;
				   targettype = 1; //defensive
				   break;
		}
		case 3:{
				   fprintf(FDW, "Field Exercise\n");
				   paygrade = 2;
				   targettype = 2; //neutral
				   break;
		}
		case 4:{
				   fprintf(FDW, "Field Exercise\n");
				   paygrade = 3;
				   targettype = 3; //offensive
				   break;
		}
		case 5:{
				   fprintf(FDW, "Active Duty\n");
				   paygrade = 4;
				   targettype = 1; //defensive
				   break;
		}
		case 6:{
				   fprintf(FDW, "Recon\n");
				   paygrade = 3;
				   targettype = 2; //neutral
				   break;
		}
		default:{
					fprintf(FDW, "Train\n");
					paygrade = 1;
					targettype = 1; //defensive
					break;
		}
		} //end switch

	}
	if ((dieroll3 == 5) || (dieroll3 == 6)) {
		fprintf(FDW, "Commando-");
		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "First Strike\n");
					 paygrade = 3;
					 targettype = 3; //offensive
					 break;
		}
		case 2:{
				   fprintf(FDW, "Raid\n");
				   paygrade = 2;
				   targettype = 3; //offensive
				   break;
		}
		case 3:{
				   fprintf(FDW, "Active Duty\n");
				   paygrade = 4;
				   targettype = 1; //defensive
				   break;
		}
		case 4:{
				   fprintf(FDW, "Active Duty\n");
				   paygrade = 5;
				   targettype = 3; //offensive
				   break;
		}
		case 5:{
				   fprintf(FDW, "Retrieval\n");
				   paygrade = 3;
				   targettype = 2; //neutral
				   break;
		}
		case 6:{
				   fprintf(FDW, "Elimination\n");
				   targettype = 3; //offensive
				   paygrade = 4;
				   break;
		}
		default:{
					fprintf(FDW, "First Strike\n");
					targettype = 3; //offensive
					paygrade = 3;
					break;
		}
		} //end switch

	}
	if ((dieroll3 > 6) && (dieroll3 < 10)) {
		fprintf(FDW, "Striker-");
		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "Counter Strike\n");
					 paygrade = 5;
					 targettype = 3; //offensive
					 break;
		}
		case 2:{
				   fprintf(FDW, "Recon\n");
				   paygrade = 1;
				   targettype = 3; //offensive
				   break;
		}
		case 3:{
				   fprintf(FDW, "First Strike\n");
				   paygrade = 3;
				   targettype = 3; //offensive
				   break;
		}
		case 4:{
				   fprintf(FDW, "First Strike\n");
				   targettype = 3; //offensive
				   paygrade = 4;
				   break;
		}
		case 5:{
				   fprintf(FDW, "Elimination\n");
				   targettype = 3; //offensive
				   paygrade = 3;
				   break;
		}
		case 6:{
				   fprintf(FDW, "Elimination\n");
				   targettype = 3; //offensive
				   paygrade = 4;
				   break;
		}
		default:{
					fprintf(FDW, "Counter Strike\n");
					targettype = 3; //offensive
					paygrade = 5;
					break;
		}
		} //end switch

	}
	if ((dieroll3 == 10) || (dieroll3 == 11)){
		fprintf(FDW, "Security-");
		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "Defense\n");
					 paygrade = 1;
					 targettype = 1; //defensive
					 break;
		}
		case 2:{
				   fprintf(FDW, "Defense\n");
				   paygrade = 2;
				   targettype = 2; //neutral
				   break;
		}
		case 3:{
				   fprintf(FDW, "Defense\n");
				   paygrade = 3;
				   targettype = 1; //defensive
				   break;
		}
		case 4:{
				   fprintf(FDW, "Active Duty\n");
				   targettype = 1; //defensive
				   paygrade = 4;
				   break;
		}
		case 5:{
				   fprintf(FDW, "Escort\n");
				   targettype = 1; //defensive
				   paygrade = 2;
				   break;
		}
		case 6:{
				   fprintf(FDW, "Escort\n");
				   targettype = 1; //defensive
				   paygrade = 3;
				   break;
		}
		default:{
					fprintf(FDW, "Defense\n");
					targettype = 1; //defensive
					paygrade = 1;
					break;
		}
		} //end switch

	}
	if (dieroll3 == 12) {
		fprintf(FDW, "Warmonger-");
		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "Escort\n");
					 targettype = 1; //defensive
					 paygrade = 2;
					 break;
		}
		case 2:{
				   fprintf(FDW, "Escort\n");
				   targettype = 1; //defensive
				   paygrade = 3;
				   break;
		}
		case 3:{
				   fprintf(FDW, "Field Exercise\n");
				   paygrade = 3;
				   targettype = 3; //offensive
				   break;
		}
		case 4:{
				   fprintf(FDW, "Commerce\n");
				   paygrade = 4;
				   targettype = 1; //defensive
				   break;
		}
		case 5:{
				   fprintf(FDW, "Commerce\n");
				   paygrade = 5;
				   targettype = 1; //defensive
				   break;
		}
		case 6:{
				   fprintf(FDW, "Raid\n");
				   paygrade = 3;
				   targettype = 3; //offensive
				   break;
		}
		default:{
					fprintf(FDW, "Escort\n");
					targettype = 1; //defensive
					paygrade = 2;
					break;
		}
		} //end switch

	}
	if (dieroll3 == 13) {
		fprintf(FDW, "Dream-");
		dieroll = (rand() % (6)) + 1;
		if (dieroll == 0) dieroll = 1;

		switch (dieroll)
		{
		case 1:  {
					 fprintf(FDW, "Recon\n");
					 paygrade = 4;
					 targettype = 2; //neutral
					 break;
		}
		case 2:{
				   fprintf(FDW, "Escort\n");
				   targettype = 1; //defensive
				   paygrade = 5;
				   break;
		}
		case 3:{
				   fprintf(FDW, "First Strike\n");
				   paygrade = 6;
				   targettype = 3; //offensive
				   break;
		}
		case 4:{
				   fprintf(FDW, "Field Exercise\n");
				   targettype = 2; //neutral
				   paygrade = 4;
				   break;
		}
		case 5:{
				   fprintf(FDW, "Elimination\n");
				   paygrade = 7;
				   targettype = 3; //offensive
				   break;
		}
		case 6:{
				   fprintf(FDW, "Technological Test\n");
				   targettype = 2; //neutral
				   paygrade = 4;
				   break;
		}
		default:{
					fprintf(FDW, "Recon\n");
					paygrade = 4;
					targettype = 2; //neutral
					break;
		}
		} //end switch

	}


	//3.2 mission length

	fprintf(FDW, "Mission Length: ");
	dieroll3 = (rand() % (3)) + 1;
	if (dieroll3 == 0) dieroll3 = 1;

	if (dieroll3 == 1) {
		fprintf(FDW, "Short mission- ");
		dieroll = (rand() % (7)) + 1;
		if (dieroll == 0) dieroll = 1;
		switch (dieroll)
		{
		case 1:  {
					 dieroll2 = (rand() % (6)) + 1;
					 if (dieroll2 == 0) dieroll2 = 1;
					 fprintf(FDW, "%d days\n", dieroll2);
					 break;
		}
		case 2:{
				   dieroll2 = (rand() % (6)) + 1;
				   if (dieroll2 == 0) dieroll2 = 1;
				   fprintf(FDW, "%d days\n", dieroll2);
				   break;
		}
		case 3:{
				   dieroll2 = (rand() % (12)) + 3;
				   fprintf(FDW, "%d days\n", dieroll2);
				   break;
		}
		case 4:{
				   dieroll2 = (rand() % (12)) + 3;
				   fprintf(FDW, "%d days\n", dieroll2);
				   break;
		}
		case 5:{
				   dieroll2 = (rand() % (6)) + 1;
				   if (dieroll2 == 0) dieroll2 = 1;
				   fprintf(FDW, "%d weeks\n", dieroll2);
				   break;
		}
		case 6:{
				   dieroll2 = (rand() % (6)) + 1;
				   if (dieroll2 == 0) dieroll2 = 1;
				   fprintf(FDW, "%d weeks\n", dieroll2);
				   break;
		}
		case 7:{
				   dieroll2 = (rand() % (6)) + 3;
				   fprintf(FDW, "%d weeks\n", dieroll2);
				   break;
		}
		default:{
					dieroll2 = (rand() % (6)) + 1;
					if (dieroll2 == 0) dieroll2 = 1;
					fprintf(FDW, "%d days\n", dieroll2);
					break;
		}
		} //end switch
	}//end if

	if (dieroll3 == 2) {
		fprintf(FDW, "Medium mission- ");
		dieroll = (rand() % (6)) + 1;

		switch (dieroll)
		{
		case 1:  {
					 dieroll2 = (rand() % (6)) + 1;
					 if (dieroll2 == 0) dieroll2 = 1;
					 fprintf(FDW, "%d weeks\n", dieroll2);
					 break;
		}
		case 2:{
				   dieroll2 = (rand() % (6)) + 2;
				   fprintf(FDW, "%d weeks\n", dieroll2);
				   break;
		}
		case 3:{
				   dieroll2 = (rand() % (11)) + 2;
				   fprintf(FDW, "%d weeks\n", dieroll2);
				   break;
		}
		case 4:{
				   dieroll2 = (rand() % (6)) + 1;
				   if (dieroll2 == 0) dieroll2 = 1;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 5:{
				   dieroll2 = (rand() % (6)) + 2;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 6:{
				   dieroll2 = (rand() % (11)) + 2;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 7:{
				   dieroll2 = (rand() % (11)) + 3;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		default:{
					dieroll2 = (rand() % (6)) + 1;
					if (dieroll2 == 0) dieroll2 = 1;
					fprintf(FDW, "%d weeks\n", dieroll2);
					break;
		}
		} //end switch
	}//end if

	if (dieroll3 == 3) {
		fprintf(FDW, "Long mission- ");
		if (dieroll == 0) dieroll = 1;
		dieroll = (rand() % (6)) + 1;

		switch (dieroll)
		{
		case 1:  {
					 dieroll2 = (rand() % (6)) + 2;
					 if (dieroll2 == 0) dieroll2 = 1;
					 fprintf(FDW, "%d months\n", dieroll2);
					 break;
		}
		case 2:{
				   dieroll2 = (rand() % (11)) + 2;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 3:{
				   dieroll2 = (rand() % (11)) + 3;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 4:{
				   dieroll2 = (rand() % (15)) + 4;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 5:{
				   dieroll2 = (rand() % (15)) + 6;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 6:{
				   dieroll2 = (rand() % (20)) + 5;
				   fprintf(FDW, "%d months\n", dieroll2);
				   break;
		}
		case 7:{
				   dieroll2 = (rand() % (6)) + 1;
				   if (dieroll2 == 0) dieroll2 = 1;
				   fprintf(FDW, "%d years\n", dieroll2);
				   break;
		}
		default:{
					dieroll2 = (rand() % (6)) + 2;
					fprintf(FDW, "%d months\n", dieroll2);
					break;
		}
		} //end switch
	}//end if


	//devensive target
	if (targettype == 1){
		dieroll2 = (rand() % (6)) + 1;

		switch (dieroll2){

		case 1:{
				   fprintf(FDW, "Target: Item\n");
				   break;
		}
		case 2:{
				   fprintf(FDW, "Target: Location\n");
				   paygrade++;
				   break;
		}
		case 3:{
				   fprintf(FDW, "Target: Individual\n");
				   paygrade++;
				   break;
		}
		case 4:{
				   fprintf(FDW, "Target: Information\n");
				   paygrade--;
				   break;
		}
		case 5:{
				   fprintf(FDW, "Target: Ship\n");
				   paygrade++;
				   break;
		}
		case 6:{
				   fprintf(FDW, "Target: Group\n");
				   paygrade += 2;
				   break;
		}
		default:{
					fprintf(FDW, "Target: Item\n");
					break;
		}

		}//end switch

	}

	//neutral target
	if (targettype == 2){
		dieroll2 = (rand() % (6)) + 1;

		switch (dieroll2){

		case 1:{
				   fprintf(FDW, "Target: Item\n");
				   break;
		}
		case 2:{
				   fprintf(FDW, "Target: Trade Goods\n");
				   break;
		}
		case 3:{
				   fprintf(FDW, "Target: Individual\n");
				   paygrade--;
				   break;
		}
		case 4:{
				   fprintf(FDW, "Target: Personal Goods\n");
				   break;
		}
		case 5:{
				   fprintf(FDW, "Target: Ship\n");
				   paygrade += 2;
				   break;
		}
		case 6:{
				   fprintf(FDW, "Target: Activity\n");
				   break;
		}
		default:{
					fprintf(FDW, "Target: Item\n");
					break;
		}

		}//end switch

	}

	//offensive target
	if (targettype == 3){
		dieroll2 = (rand() % (6)) + 1;

		switch (dieroll2){

		case 1:{
				   fprintf(FDW, "Target: Individual\n");
				   paygrade++;
				   break;
		}
		case 2:{
				   fprintf(FDW, "Target: Location\n");
				   paygrade += 2;
				   break;
		}
		case 3:{
				   fprintf(FDW, "Target: Item\n");
				   paygrade++;
				   break;
		}
		case 4:{
				   fprintf(FDW, "Target: Vehicle\n");
				   paygrade += 2;
				   break;
		}
		case 5:{
				   fprintf(FDW, "Target: Ship\n");
				   paygrade += 2;
				   break;
		}
		case 6:{
				   fprintf(FDW, "Target: Group\n");
				   paygrade += 2;
				   break;
		}
		default:{
					fprintf(FDW, "Target: Individual\n");
					paygrade++;
					break;
		}

		}//end switch

	}



	//3.4b Target Type Descriptor

	dieroll = (rand() % (5)) + 1;

	switch (dieroll){

	case 1:{
			   fprintf(FDW, "Target Type: Political\n");
			   break;
	}
	case 2:{
			   fprintf(FDW, "Target Type: Military\n");
			   break;
	}
	case 3:{
			   fprintf(FDW, "Target Type: Civilian\n");
			   break;
	}
	case 4:{
			   fprintf(FDW, "Target Type: Commercial\n");
			   break;
	}
	case 5:{
			   fprintf(FDW, "Target Type: Alien\n");
			   break;
	}

	default:{
				fprintf(FDW, "Target Type: Political\n");
				break;
	}
	}//end switch

	fprintf(FDW, "\n\n");
	//3.5 Risk Level
	fprintf(FDW, "TAS ASSESSED RISK LEVEL: ");
	dieroll = (rand() % (6)) + 1;

	switch (dieroll){

	case 1:{
			   fprintf(FDW, "Too Easy. This is well beneath the applicant's level of training; it is unlikely they will even break a sweat.\n");
			   paygrade -= 2;
			   break;
	}
	case 2:{
			   fprintf(FDW, "Easy. This ticket will not cost the applicant much in the way of resources or stress.\n");
			   paygrade--;
			   break;
	}
	case 3:{
			   fprintf(FDW, "Average. This is what the applicant is trained for, and should serve as a good reminder what ticket work should be.\n");
			   break;
	}
	case 4:{
			   fprintf(FDW, "Worthy Test. This is a fantastic place to test the applicant's skills, even some of the obscure ones. They might suffer some wounds or even casualties.\n");
			   paygrade++;
			   break;
	}
	case 5:{
			   fprintf(FDW, "Difficult. This ticket will be a tough one for the whole unit, and the members will need to be diligent in their training or they might not make it back home.\n");
			   paygrade += 2;
			   break;
	}
	case 6:{
			   fprintf(FDW, "Arduous. This mission is a nightmare. If anyone makes it back in one piece, they will have been pushed to the very limit.\n");
			   paygrade += 3;
			   break;
	}

	default:{
				fprintf(FDW, "Too Easy. This is well beneath the applicant's level of training; it is unlikely they will even break a sweat.\n");
				paygrade -= 2;
				break;
	}
	} //end switch

	//4. Advance support
	fprintf(FDW, "\n\n");
	fprintf(FDW, "Advances: ");

	dieroll = (rand() % (6)) + 1;
	switch (dieroll){
		//advance of funds
	case 1:{
			   dieroll2 = (rand() % (6)) + 1;
			   switch (dieroll2){

			   case 1:{
						  fprintf(FDW, "Advance of 5,000 credits.\n");
						  break;
			   }
			   case 2:{
						  fprintf(FDW, "Advance of 10,000 credits.\n");
						  break;
			   }
			   case 3:{
						  fprintf(FDW, "Advance of 20,000 credits.\n");
						  break;
			   }
			   case 4:{
						  fprintf(FDW, "Advance of 30,000 credits.\n");
						  break;
			   }
			   case 5:{
						  fprintf(FDW, "Advance of 40,000 credits.\n");
						  break;
			   }
			   case 6:{
						  fprintf(FDW, "Advance of 50,000 credits.\n");
						  break;
			   }

			   default:{
						   fprintf(FDW, "Advance of 5,000 credits.\n");
						   break;
			   }
			   } //end switch
			   break;
	}
		//support services provided
	case 2:{
			   dieroll2 = (rand() % (6)) + 1;
			   switch (dieroll2){

			   case 1:{
						  fprintf(FDW, "Transportation: The unit will not have to worry about getting to and from the ticket service site. The employer will arrange for these things and will not pass on any of the cost.\n");
						  break;
			   }
			   case 2:{
						  fprintf(FDW, "Transportation: The unit will not have to worry about getting to and from the ticket service site. The employer will arrange for these things and will not pass on any of the cost.\n");
						  break;
			   }
			   case 3:{
						  fprintf(FDW, "Equipment Repairs: If the unit has physical equipment (vehicles, armour, gear, etc.) that requires repairs before the ticket begins, the employer will arrange for those repairs.\n");
						  break;
			   }
			   case 4:{
						  fprintf(FDW, "Rearmament: The employer arranges for all power packs, fuel cells, and munitions for the unit’s weaponry to be recharged, re-armed, or otherwise refreshed properly.\n");
						  break;
			   }
			   case 5:{
						  fprintf(FDW, "Arms Trading: The employer will arrange a meeting with an allied arms dealer, who will trade with the unit at a discount of 10 % to market prices.\n");
						  break;
			   }
			   case 6:{
						  fprintf(FDW, "Medical Process: The employer will pay for 50 percent of any medical services the unit wishes to undertake before the ticket can begin. This can include wound care, augmentation, implanting or image reconstruction.\n");
						  break;
			   }

			   default:{
						   fprintf(FDW, "Transportation: The unit will not have to worry about getting to and from the ticket service site. The employer will arrange for these things and will not pass on any of the cost.\n");
						   break;
			   }
			   } //end switch
			   break;
	}
		//equipment
	case 3:{
			   dieroll2 = (rand() % (6)) + 1;
			   switch (dieroll2){

			   case 1:{
						  fprintf(FDW, "Basics: The employer will arrange for each unit member to be outfitted with 5,000 credits worth of basic equipment useful to the ticket mission.\n");
						  break;
			   }
			   case 2:{
						  fprintf(FDW, "Armor: The employer will arrange for enough Flak Jackets (TL8) for the entire unit or %d suits of Combat Armor (TL11).\n", (rand() % (11)) + 2);
						  break;
			   }
			   case 3:{
						  fprintf(FDW, "Weapons: The employer will arange for up to 1,250 credits worth of weapons for each member of the unit placed on the ticket.\n");
						  break;
			   }
			   case 4:{
						  fprintf(FDW, "Heavy Weapon: The employer will arrange for a single heavy weapon for the unit’s use worth up to 5,000 credits (after ammunition).\n");
						  break;
			   }
			   case 5:{
						  fprintf(FDW, "Transport: The employer will grant the unit the use of any single vehicle worth 300,000 credits or less; this must be returned after the ticket.\n");
						  break;
			   }
			   case 6:{
						  fprintf(FDW, "Specialised Gear: The employer will give each member of the unit a single piece of specialised equipment or armament that the ticket might require them to have (Vacc suit, toxin antidotes, methane breathers and so on).\n");
						  break;
			   }

			   default:{
						   fprintf(FDW, "Basics: The employer will arrange for each unit member to be outfitted with 5,000 credits worth of basic equipment useful to the ticket mission.\n");
						   break;
			   }
			   } //end switch
			   break;
	}
	case 4:{
			   fprintf(FDW, "None.\n");
			   break;
	}
	case 5:{
			   fprintf(FDW, "None.\n");
			   break;
	}
	case 6:{
			   fprintf(FDW, "None.\n");
			   break;
	}

	default:{
				fprintf(FDW, "None.\n");
				break;
	}
	} //end switch


	//5. Post ticket support
	fprintf(FDW, "\n\n");
	fprintf(FDW, "Post Ticket Support- ");
	dieroll = (rand() % (2)) + 1;
	switch (dieroll){

	case 1:{
			   dieroll2 = (rand() % (6)) + 1;
			   switch (dieroll2){

			   case 1:{
						  fprintf(FDW, "Rest and Relaxation: The employer agrees to pay for %d weeks of recuperation time for the unit at a pleasurable location (tourist resort, vacation location, etc.).\n", (rand() % (6)) + 1);
						  break;
			   }
			   case 2:{
						  fprintf(FDW, "Repair and Rearm: The employer agrees to pay for 50 percent of any rearmament and repair costs for ticket-related equipment and weaponry.\n");
						  break;
			   }
			   case 3:{
						  fprintf(FDW, "Medical Care: The employer agrees to pay for up to 5,000 credits of medical care for unit members injured during the mission.\n");
						  break;
			   }
			   case 4:{
						  fprintf(FDW, "Expedited Evacuation: The employer agrees to ensure the fastest transportation process they can manage for the unit when the ticket is reported finished. This cuts return travel time for the unit in half.\n");
						  break;
			   }
			   case 5:{
						  fprintf(FDW, "Legal Counsel: The employer agrees to retain an attorney for the mercenary unit (if needed); with Admin 1, Advocate 2, Broker 1 and Language 1.\n");
						  break;
			   }
			   case 6:{
						  fprintf(FDW, "Repeated Ticketing Agreement: The employer agrees to contract the unit up for future use, granting an additional %d Ticket Adjustments to their next ticket with this employer.\n", (rand() % (6)) + 1);
						  break;
			   }

			   default:{
						   fprintf(FDW, "Rest and Relaxation: The employer agrees to pay for %d weeks of recuperation time for the unit at a pleasurable location (tourist resort, vacation location, etc.).\n", (rand() % (6)) + 1);
						   break;
			   }
			   } //end switch
			   break;
	}
	case 2:{
			   fprintf(FDW, "None.\n");
			   break;
	}


	default:{
				fprintf(FDW, "None.\n");
				break;
	}
	} //end switch

	//6. Compensation package

	/*
	0- 10,000 Cr
	1 A- 20,000 Cr
	2 B- 30,000 Cr
	3 C- 50,000 Cr
	4 D- 75,000 Cr
	5 E- 100,000 Cr
	6 F- 150,000 Cr
	7 G- 200,000 Cr
	8 H- 250,000 Cr
	9 I- 325,000 Cr
	10 J- 400,000 Cr
	11 K- 500,000 Cr
	12 L- 750,000 Cr
	13 M- 1 MCr
	14 N- 1.5 MCr
	15 O- 2 MCr
	16 P- 3 MCr
	17 Q- 4 MCr
	18 R- 5 MCr
	19 S- 7 MCr
	20 T- 10 MCr
	21 U- 15 MCr
	22 V- 20 MCr
	23 W- 25 MCr
	24 X- 30 MCr
	25 Y- 40 MCr
	26 Z- 50 MCr
	*/

	fprintf(FDW, "\n\n");

	fprintf(FDW, "COMPENSATION- ");

	if (paygrade < 0) paygrade = 0;

	switch (paygrade)
	{

	case 0:{
			   fprintf(FDW, "Payment: 10,000 Cr.\n");
			   break;
	}
	case 1:{
			   fprintf(FDW, "Payment: 20,000 Cr.\n");
			   break;
	}
	case 2:{
			   fprintf(FDW, "Payment: 30,000 Cr.\n");
			   break;
	}
	case 3:{
			   fprintf(FDW, "Payment: 50,000 Cr.\n");
			   break;
	}
	case 4:{
			   fprintf(FDW, "Payment: 75,000 Cr.\n");
			   break;
	}
	case 5:{
			   fprintf(FDW, "Payment: 100,000 Cr.\n");
			   break;
	}

	case 6:{
			   fprintf(FDW, "Payment: 150,000 Cr.\n");
			   break;
	}
	case 7:{
			   fprintf(FDW, "Payment: 200,000 Cr.\n");
			   break;
	}
	case 8:{
			   fprintf(FDW, "Payment: 250,000 Cr.\n");
			   break;
	}
	case 9:{
			   fprintf(FDW, "Payment: 325,000 Cr.\n");
			   break;
	}
	case 10:{
				fprintf(FDW, "Payment: 400,000 Cr.\n");
				break;
	}
	case 11:{
				fprintf(FDW, "Payment: 500,000 Cr.\n");
				break;
	}
	case 12:{
				fprintf(FDW, "Payment: 750,000 Cr.\n");
				break;
	}
	case 13:{
				fprintf(FDW, "Payment: 1 MCr.\n");
				break;
	}
	case 14:{
				fprintf(FDW, "Payment: 1.5 MCr.\n");
				break;
	}
	case 15:{
				fprintf(FDW, "Payment: 2 MCr.\n");
				break;
	}
	case 16:{
				fprintf(FDW, "Payment: 3 MCr.\n");
				break;
	}
	case 17:{
				fprintf(FDW, "Payment: 4 MCr.\n");
				break;
	}
	case 18:{
				fprintf(FDW, "Payment: 5 MCr.\n");
				break;
	}
	case 19:{
				fprintf(FDW, "Payment: 7 MCr.\n");
				break;
	}
	case 20:{
				fprintf(FDW, "Payment: 10 MCr.\n");
				break;
	}
	case 21:{
				fprintf(FDW, "Payment: 15 MCr.\n");
				break;
	}
	case 22:{
				fprintf(FDW, "Payment: 20 MCr.\n");
				break;
	}
	case 23:{
				fprintf(FDW, "Payment: 25 MCr.\n");
				break;
	}
	case 24:{
				fprintf(FDW, "Payment: 30 MCr.\n");
				break;
	}
	case 25:{
				fprintf(FDW, "Payment: 40 MCr.\n");
				break;
	}
	case 26:{
				fprintf(FDW, "Payment: 50 MCr.\n");
				break;
	}
	default: {
				 fprintf(FDW, "Payment: 10,000 Cr.\n");
				 break;
	} //end default
	}//end switch paygrade

	//Special compensation bonus
	//paygrade of 6> gets special bonus

	if (paygrade > 5){

		dieroll2 = (rand() % (6)) + 1;
		switch (dieroll2){

		case 1:{
				   fprintf(FDW, "The employer includes %d credits worth of equipment (any) as part of the compensation for a successful ticket.\n", ((rand() % (11)) + 2) * 10000);
				   break;
		}
		case 2:{
				   fprintf(FDW, "Free Medical Care: The employer includes a contract for completely free medical care for members of the mercenary unit for %d months after the ticket is finished.\n", (rand() % (11)) + 2);
				   break;
		}
		case 3:{
				   fprintf(FDW, "Combat Implant Package: The employer will arrange for the purchase and grafting of up to 100,000 credits worth of Combat Implants to the higher ranking members of the unit.\n");
				   break;
		}
		case 4:{
				   fprintf(FDW, "Ship Shares: The employer gives %d Ship Shares to the mercenary unit.\n", ((rand() % (11)) + 2));
				   break;
		}
		case 5:{
				   fprintf(FDW, "Debt Payment: The employer offers to pay %d percent of the unit's medical or banking - related debts.\n", (((rand() % (6)) + 1) * 10));
				   break;
		}
		case 6:{
				   fprintf(FDW, "Prime Ticket: The employer will grant the equivalent to the Prime Ticket benefit to the unit for their next sanctioned ticket together.\n");
				   break;
		}

		default:{
					fprintf(FDW, "The employer includes %d credits worth of equipment (any) as part of the compensation for a successful ticket.\n", ((rand() % (11)) + 2) * 10000);
					break;
		}
		} //end switch
	} //end if
	
	fprintf(FDW, "\n\n");
	fclose(FDW);

}

void DisplayMissionData(void)
{
	char text[70];
	char available[81];


	//clear out text string
	sprintf(text, "                                                                      \0");

	sprintf(available, "Missions Available: %d", NumberofMercTickets);
	Optima18White->draw(irr::core::stringw(available).c_str(), core::rect<s32>(755, 220, 0, 0), video::SColor(255, 255, 255, 255));

	core::stringw w_libdatatext = libdatatext; //make text a wide char type

	libdatatextimage = guienv->addImage((libdatablank), core::position2d<s32>(0,0)); //678x701 image or use another image
	libdatatextimage->setAlignment(EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE);
	libdatatextimage->setRelativePosition(core::rect<s32>(10, 10, 688, 711));

	textBox = new CGUITextBox(Optima18Black, L"", guienv, irr::core::rect<irr::s32>(35, 35, 640, 615), libdatatextimage, -1);
	textBox->setScrollModeLines(true);
	textBox->setScrollbarRight(true);
	textBox->setVisible(true);
	textBox->setText(w_libdatatext.c_str());
	
}

void DisplayJobData(void)
{	
	char tempsalary[20];

	sprintf(tempsalary, "%d Cr/Week", Salary);
	arial_36_mac_green->draw(irr::core::stringw(JobName).c_str(), core::rect<s32>(220, 160, 0, 0), video::SColor(255, 255, 255, 255));

	Optima18White->draw(irr::core::stringw(CompanyName).c_str(), core::rect<s32>(130, 440, 0, 0), video::SColor(255, 255, 255, 255));

	if(Salary>0) {
		arial_24_red_blackout_bevel->draw(irr::core::stringw(tempsalary).c_str(), core::rect<s32>(130, 540, 0, 0), video::SColor(255, 255, 255, 255));
		}
}

char* CompanyPrefix(void)
{
	
	char *Prefix;
	int dieroll = 0;

	Prefix = (char*)malloc(20);

	dieroll = (rand() % 101) + 1;
	sprintf(Prefix, "%s", "Inter");
	if (dieroll == 1) sprintf(Prefix, "%s", "Inter");
	if (dieroll == 2) sprintf(Prefix, "%s", "Global");
	if (dieroll == 3) sprintf(Prefix, "%s", "Futur");
	if (dieroll == 4) sprintf(Prefix, "%s", "Multi");
	if (dieroll == 5) sprintf(Prefix, "%s", "Omni");
	if (dieroll == 6) sprintf(Prefix, "%s", "Alf");
	if (dieroll == 7) sprintf(Prefix, "%s", "Bet");
	if (dieroll == 8) sprintf(Prefix, "%s", "Col");
	if (dieroll == 9) sprintf(Prefix, "%s", "Dol");
	if (dieroll == 10) sprintf(Prefix, "%s", "Del");
	if (dieroll == 11) sprintf(Prefix, "%s", "Dem");
	if (dieroll == 12) sprintf(Prefix, "%s", "Cy");
	if (dieroll == 13) sprintf(Prefix, "%s", "My");
	if (dieroll == 14) sprintf(Prefix, "%s", "Dy");
	if (dieroll == 15) sprintf(Prefix, "%s", "Ry");
	if (dieroll == 16) sprintf(Prefix, "%s", "Fy");
	if (dieroll == 17) sprintf(Prefix, "%s", "Sy");
	if (dieroll == 18) sprintf(Prefix, "%s", "By");
	if (dieroll == 19) sprintf(Prefix, "%s", "Ly");
	if (dieroll == 20) sprintf(Prefix, "%s", "Ny");
	if (dieroll == 21) sprintf(Prefix, "%s", "Pogo");
	if (dieroll == 22) sprintf(Prefix, "%s", "Robo");
	if (dieroll == 23) sprintf(Prefix, "%s", "Ty");
	if (dieroll == 24) sprintf(Prefix, "%s", "Hypo");
	if (dieroll == 25) sprintf(Prefix, "%s", "Hy");
	if (dieroll == 26) sprintf(Prefix, "%s", "Hyd");
	if (dieroll == 27) sprintf(Prefix, "%s", "Ent");
	if (dieroll == 28) sprintf(Prefix, "%s", "Epi");
	if (dieroll == 29) sprintf(Prefix, "%s", "Eco");
	if (dieroll == 30) sprintf(Prefix, "%s", "Fly");
	if (dieroll == 31) sprintf(Prefix, "%s", "Fut");
	if (dieroll == 32) sprintf(Prefix, "%s", "Fus");
	if (dieroll == 33) sprintf(Prefix, "%s", "Fer");
	if (dieroll == 34) sprintf(Prefix, "%s", "Gen");
	if (dieroll == 35) sprintf(Prefix, "%s", "Gam");
	if (dieroll == 36) sprintf(Prefix, "%s", "Gig");
	if (dieroll == 37) sprintf(Prefix, "%s", "Ion");
	if (dieroll == 38) sprintf(Prefix, "%s", "Ic");
	if (dieroll == 39) sprintf(Prefix, "%s", "Irm");
	if (dieroll == 40) sprintf(Prefix, "%s", "Mil");
	if (dieroll == 41) sprintf(Prefix, "%s", "Meg");
	if (dieroll == 42) sprintf(Prefix, "%s", "Max");
	if (dieroll == 43) sprintf(Prefix, "%s", "Mag");
	if (dieroll == 44) sprintf(Prefix, "%s", "Med");
	if (dieroll == 45) sprintf(Prefix, "%s", "Org");
	if (dieroll == 46) sprintf(Prefix, "%s", "Orph");
	if (dieroll == 47) sprintf(Prefix, "%s", "Ops");
	if (dieroll == 48) sprintf(Prefix, "%s", "Pic");
	if (dieroll == 49) sprintf(Prefix, "%s", "Psi");
	if (dieroll == 50) sprintf(Prefix, "%s", "Pen");
	if (dieroll == 51) sprintf(Prefix, "%s", "Ron");
	if (dieroll == 52) sprintf(Prefix, "%s", "Sil");
	if (dieroll == 53) sprintf(Prefix, "%s", "Tar");
	if (dieroll == 54) sprintf(Prefix, "%s", "Tra");
	if (dieroll == 55) sprintf(Prefix, "%s", "Ter");
	if (dieroll == 56) sprintf(Prefix, "%s", "Dent");
	if (dieroll == 57) sprintf(Prefix, "%s", "Sent");
	if (dieroll == 58) sprintf(Prefix, "%s", "Rent");
	if (dieroll == 59) sprintf(Prefix, "%s", "Lent");
	if (dieroll == 60) sprintf(Prefix, "%s", "Cent");
	if (dieroll == 61) sprintf(Prefix, "%s", "Tan");
	if (dieroll == 62) sprintf(Prefix, "%s", "Man");
	if (dieroll == 63) sprintf(Prefix, "%s", "Rand");
	if (dieroll == 64) sprintf(Prefix, "%s", "Lan");
	if (dieroll == 65) sprintf(Prefix, "%s", "Pan");
	if (dieroll == 66) sprintf(Prefix, "%s", "Al");
	if (dieroll == 67) sprintf(Prefix, "%s", "El");
	if (dieroll == 68) sprintf(Prefix, "%s", "Ol");
	if (dieroll == 69) sprintf(Prefix, "%s", "Ul");
	if (dieroll == 70) sprintf(Prefix, "%s", "Um");
	if (dieroll == 71) sprintf(Prefix, "%s", "Un");
	if (dieroll == 72) sprintf(Prefix, "%s", "An");
	if (dieroll == 73) sprintf(Prefix, "%s", "Am");
	if (dieroll == 74) sprintf(Prefix, "%s", "Xia");
	if (dieroll == 75) sprintf(Prefix, "%s", "Xio");
	if (dieroll == 76) sprintf(Prefix, "%s", "Zu");
	if (dieroll == 77) sprintf(Prefix, "%s", "Zo");
	if (dieroll == 78) sprintf(Prefix, "%s", "X-");
	if (dieroll == 79) sprintf(Prefix, "%s", "Z-");
	if (dieroll == 80) sprintf(Prefix, "%s", "Y-");
	if (dieroll == 81) sprintf(Prefix, "%s", "Q-");
	if (dieroll == 82) sprintf(Prefix, "%s", "W-");
	if (dieroll == 83) sprintf(Prefix, "%s", "S-");
	if (dieroll == 84) sprintf(Prefix, "%s", "Quad");
	if (dieroll == 85) sprintf(Prefix, "%s", "Watt");
	if (dieroll == 86) sprintf(Prefix, "%s", "Volt");
	if (dieroll == 87) sprintf(Prefix, "%s", "Amp");
	if (dieroll == 88) sprintf(Prefix, "%s", "Test");
	if (dieroll == 89) sprintf(Prefix, "%s", "Furn");
	if (dieroll == 90) sprintf(Prefix, "%s", "Brai");
	if (dieroll == 91) sprintf(Prefix, "%s", "Long");
	if (dieroll == 92) sprintf(Prefix, "%s", "Strat");
	if (dieroll == 93) sprintf(Prefix, "%s", "Hemi");
	if (dieroll == 94) sprintf(Prefix, "%s", "Zy");
	if (dieroll == 95) sprintf(Prefix, "%s", "Cy");
	if (dieroll == 96) sprintf(Prefix, "%s", "Cro");
	if (dieroll == 97) sprintf(Prefix, "%s", "Cyl");
	if (dieroll == 98) sprintf(Prefix, "%s", "Cyno");
	if (dieroll == 99) sprintf(Prefix, "%s", "Chem");
	if (dieroll == 100) sprintf(Prefix, "%s", "Cal");
	if (dieroll == 101) sprintf(Prefix, "%s", "Comp");


	return Prefix;
}

char* CompanySuffix(void)
{
	char *Suffix;
	int dieroll = 0;

	Suffix = (char*)malloc(20);

	sprintf(Suffix, "%s", "amn");
	dieroll = (rand() % 80) + 1;
	if (dieroll == 1) sprintf(Suffix, "%s", "amn");
	if (dieroll == 2) sprintf(Suffix, "%s", "arg");
	if (dieroll == 3) sprintf(Suffix, "%s", "art");
	if (dieroll == 4) sprintf(Suffix, "%s", "ac");
	if (dieroll == 5) sprintf(Suffix, "%s", "apt");
	if (dieroll == 6) sprintf(Suffix, "%s", "alf");
	if (dieroll == 7) sprintf(Suffix, "%s", "bet");
	if (dieroll == 8) sprintf(Suffix, "%s", "bart");
	if (dieroll == 9) sprintf(Suffix, "%s", "bor");
	if (dieroll == 10) sprintf(Suffix, "%s", "burn");
	if (dieroll == 11) sprintf(Suffix, "%s", "bulb");
	if (dieroll == 12) sprintf(Suffix, "%s", "bur");
	if (dieroll == 13) sprintf(Suffix, "%s", "cen");
	if (dieroll == 14) sprintf(Suffix, "%s", "cent");
	if (dieroll == 15) sprintf(Suffix, "%s", "corp");
	if (dieroll == 16) sprintf(Suffix, "%s", "cor");
	if (dieroll == 17) sprintf(Suffix, "%s", "core");
	if (dieroll == 18) sprintf(Suffix, "%s", "den");
	if (dieroll == 19) sprintf(Suffix, "%s", "dem");
	if (dieroll == 20) sprintf(Suffix, "%s", "dron");
	if (dieroll == 21) sprintf(Suffix, "%s", "dril");
	if (dieroll == 22) sprintf(Suffix, "%s", "del");
	if (dieroll == 23) sprintf(Suffix, "%s", "dep");
	if (dieroll == 24) sprintf(Suffix, "%s", "epac");
	if (dieroll == 25) sprintf(Suffix, "%s", "ec");
	if (dieroll == 26) sprintf(Suffix, "%s", "elic");
	if (dieroll == 27) sprintf(Suffix, "%s", "etic");
	if (dieroll == 28) sprintf(Suffix, "%s", "epic");
	if (dieroll == 29) sprintf(Suffix, "%s", "epak");
	if (dieroll == 30) sprintf(Suffix, "%s", "fire");
	if (dieroll == 31) sprintf(Suffix, "%s", "furo");
	if (dieroll == 32) sprintf(Suffix, "%s", "fara");
	if (dieroll == 33) sprintf(Suffix, "%s", "fero");
	if (dieroll == 34) sprintf(Suffix, "%s", "fub");
	if (dieroll == 35) sprintf(Suffix, "%s", "fus");
	if (dieroll == 36) sprintf(Suffix, "%s", "gig");
	if (dieroll == 37) sprintf(Suffix, "%s", "gam");
	if (dieroll == 38) sprintf(Suffix, "%s", "gen");
	if (dieroll == 39) sprintf(Suffix, "%s", "ics");
	if (dieroll == 40) sprintf(Suffix, "%s", "irm");
	if (dieroll == 41) sprintf(Suffix, "%s", "ic");
	if (dieroll == 42) sprintf(Suffix, "%s", "ion");
	if (dieroll == 43) sprintf(Suffix, "%s", "lent");
	if (dieroll == 44) sprintf(Suffix, "%s", "meg");
	if (dieroll == 45) sprintf(Suffix, "%s", "mil");
	if (dieroll == 46) sprintf(Suffix, "%s", "max");
	if (dieroll == 47) sprintf(Suffix, "%s", "med");
	if (dieroll == 48) sprintf(Suffix, "%s", "mag");
	if (dieroll == 49) sprintf(Suffix, "%s", "org");
	if (dieroll == 50) sprintf(Suffix, "%s", "olec");
	if (dieroll == 51) sprintf(Suffix, "%s", "otec");
	if (dieroll == 52) sprintf(Suffix, "%s", "ops");
	if (dieroll == 53) sprintf(Suffix, "%s", "opt");
	if (dieroll == 54) sprintf(Suffix, "%s", "orp");
	if (dieroll == 55) sprintf(Suffix, "%s", "pic");
	if (dieroll == 56) sprintf(Suffix, "%s", "psi");
	if (dieroll == 57) sprintf(Suffix, "%s", "pen");
	if (dieroll == 58) sprintf(Suffix, "%s", "quad");
	if (dieroll == 59) sprintf(Suffix, "%s", "ron");
	if (dieroll == 60) sprintf(Suffix, "%s", "rent");
	if (dieroll == 61) sprintf(Suffix, "%s", "rade");
	if (dieroll == 62) sprintf(Suffix, "%s", "sil");
	if (dieroll == 63) sprintf(Suffix, "%s", "sent");
	if (dieroll == 64) sprintf(Suffix, "%s", "ter");
	if (dieroll == 65) sprintf(Suffix, "%s", "tec");
	if (dieroll == 66) sprintf(Suffix, "%s", "tech");
	if (dieroll == 67) sprintf(Suffix, "%s", "tra");
	if (dieroll == 68) sprintf(Suffix, "%s", "tar");
	if (dieroll == 69) sprintf(Suffix, "%s", "tek");
	if (dieroll == 70) sprintf(Suffix, "%s", "watt");
	if (dieroll == 71) sprintf(Suffix, "%s", "xio");
	if (dieroll == 72) sprintf(Suffix, "%s", "zu");
	if (dieroll == 73) sprintf(Suffix, "%s", "zy");
	if (dieroll == 74) sprintf(Suffix, "%s", "cy");
	if (dieroll == 75) sprintf(Suffix, "%s", "cro");
	if (dieroll == 76) sprintf(Suffix, "%s", "cyl");
	if (dieroll == 77) sprintf(Suffix, "%s", "cyno");
	if (dieroll == 78) sprintf(Suffix, "%s", "chem");
	if (dieroll == 79) sprintf(Suffix, "%s", "cal");
	if (dieroll == 80) sprintf(Suffix, "%s", "comp");

	return Suffix;
}

char * Available_Job(void)
{
	
	int dieroll1 = 0;
	int dieroll2 = 0;
	char *random_job;

	random_job = (char*)malloc(40);

	dieroll1 = rand() % 8 + 1;

	//CRAFTSMAN
	if (dieroll1 == 1){
		dieroll2 = rand() % 2 + 1;
		Salary = (rand() % 50 + 1) * 10;
		switch (dieroll2){

		case 1: sprintf(random_job, "Metal Worker");
			break;
		case 2: sprintf(random_job, "Ceramics Worker");
			break;
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 1 CRAFTSMAN

	//SCHOLAR
	if (dieroll1 == 2){
		Salary = (rand() % 80 + 1) * 10;
		dieroll2 = rand() % 5 + 1;
		switch (dieroll2){

		case 1: sprintf(random_job, "Research Assistant");
			break;
		case 2: sprintf(random_job, "Linguist");
			break;
		case 3: sprintf(random_job, "Biologist");
			break;
		case 4: sprintf(random_job, "Historian");
		case 5: {
			sprintf(random_job, "Instructor");
			Salary = (rand() % 100 + 1) * 10;
			break;
		}
			break;
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 2 SCHOLAR

	//ENTERTAINER
	if (dieroll1 == 3){
		Salary = (rand() % 1000 + 1) * 10;
		dieroll2 = rand() % 6 + 1;
		switch (dieroll2){

		case 1: sprintf(random_job, "Actor");
			break;
		case 2: sprintf(random_job, "Artist");
			break;
		case 3: sprintf(random_job, "Dancer");
			break;
		case 4: sprintf(random_job, "Musician");
			break;
		case 5: sprintf(random_job, "Chef");
			break;
		case 6: sprintf(random_job, "Singer");
			break;
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 3 ENTERTAINER

	//EX-SCOUT
	if (dieroll1 == 4){
		dieroll2 = rand() % 6 + 1;
		Salary = (rand() % 80 + 1) * 10;
		switch (dieroll2){

		case 1: sprintf(random_job, "Archeologist");
			break;
		case 2: sprintf(random_job, "Xenobiologist");
			break;
		case 3: sprintf(random_job, "Xenobotanist");
			break;
		case 4: sprintf(random_job, "Xenolinguist");
			break;
		case 5: {
			sprintf(random_job, "Safari Guide");
			break;
			Salary = (rand() % 80 + 1) * 100;
		}
		case 6: {
			sprintf(random_job, "Zoo Hunter");
			break;
			Salary = (rand() % 30 + 1) * 100;
		}
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 4 EX-SCOUT

	//LAWYER
	if (dieroll1 == 5){
		dieroll2 = rand() % 3 + 1;

		switch (dieroll2){

		case 1: sprintf(random_job, "Investigator");
			Salary = (rand() % 80 + 1) * 10;
			break;
		case 2: sprintf(random_job, "Paralegal");
			Salary = (rand() % 40 + 1) * 10;
			break;
		case 3: sprintf(random_job, "Lawyer");
			Salary = (rand() % 800 + 1) * 10;
			break;
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 5 LAWYER
	//GUARD
	if (dieroll1 == 6){
		dieroll2 = rand() % 6 + 1;
		switch (dieroll2){

		case 1: sprintf(random_job, "Security Guard");
			Salary = (rand() % 50 + 1) * 10;
			break;
		case 2: sprintf(random_job, "Bouncer");
			Salary = (rand() % 40 + 1) * 10;
			break;
		case 3: sprintf(random_job, "Door Man");
			Salary = (rand() % 30 + 1) * 10;
			break;
		case 4: sprintf(random_job, "Lot Attendant");
			Salary = (rand() % 30 + 1) * 10;
			break;
		case 5: sprintf(random_job, "Body Guard");
			Salary = (rand() % 50 + 1) * 100;
			break;
		case 6: sprintf(random_job, "Security Manager");
			Salary = (rand() % 80 + 1) * 100;
			break;
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 6 GUARD
	//WORKER
	if (dieroll1 == 7){
		dieroll2 = rand() % 5 + 1;
		switch (dieroll2){

		case 1: sprintf(random_job, "Technician");
			Salary = (rand() % 50 + 1) * 10;
			break;
		case 2: sprintf(random_job, "Engineer");
			Salary = (rand() % 80 + 1) * 10;
			break;
		case 3: sprintf(random_job, "Laborer");
			Salary = (rand() % 20 + 1) * 10;
			break;
		case 4: sprintf(random_job, "Hotel Receptionist");
			Salary = (rand() % 20 + 1) * 10;
			break;
		case 5: sprintf(random_job, "Driver");
			Salary = (rand() % 30 + 1) * 10;
			break;
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 7 WORKER
	//DOCTOR
	if (dieroll1 == 8){
		dieroll2 = rand() % 5 + 1;
		switch (dieroll2){

		case 1: sprintf(random_job, "Doctor Assistant");
			Salary = (rand() % 40 + 1) * 10;
			break;
		case 2: sprintf(random_job, "Office Specialist");
			Salary = (rand() % 30 + 1) * 10;
			break;
		case 3: sprintf(random_job, "Nurse");
			Salary = (rand() % 50 + 5) * 10;
			break;
		case 4: sprintf(random_job, "Doctor");
			Salary = (rand() % 100 + 50) * 10;
			break;
		case 5: sprintf(random_job, "Surgeon");
			Salary = (rand() % 200 + 50) * 10;
			break;
		default: sprintf(random_job, " ");
			break;
		}
	}//end if 8 DOCTOR


	return random_job;
}

char* Company_Descriptor(void){

	char *Descriptor;
	int dieroll = 0;

	Descriptor = (char*)malloc(30);

	dieroll = rand() % 20 + 1;

	if (dieroll == 1) sprintf(Descriptor, " Corporation");
	if (dieroll == 2) sprintf(Descriptor, ", Corp.");
	if (dieroll == 3) sprintf(Descriptor, " Factories");
	if (dieroll == 4) sprintf(Descriptor, " Holdings");
	if (dieroll == 5) sprintf(Descriptor, " Investment");
	if (dieroll == 6) sprintf(Descriptor, " Incorporated");
	if (dieroll == 7) sprintf(Descriptor, ", Inc.");
	if (dieroll == 8) sprintf(Descriptor, " Manufacturing");
	if (dieroll == 9) sprintf(Descriptor, ", Mfg.");
	if (dieroll == 10) sprintf(Descriptor, " Trading");
	if (dieroll == 11) sprintf(Descriptor, " International");
	if (dieroll == 12) sprintf(Descriptor, " Multinational");
	if (dieroll == 13) sprintf(Descriptor, " Exports");
	if (dieroll == 14) sprintf(Descriptor, " Imports");
	if (dieroll == 15) sprintf(Descriptor, " Galactic");
	if (dieroll == 16) sprintf(Descriptor, ", LIC");
	if (dieroll > 16) sprintf(Descriptor, " ");

	return Descriptor;
}

char* Known_Company(void){

	char *Company;
	int dieroll = 0;

	Company = (char*)malloc(30);

	dieroll = rand() % 20 + 1;

	if (dieroll == 1) sprintf(Company, "Delgado Trading, LIC");
	if (dieroll == 2) sprintf(Company, "General Products, LIC");
	if (dieroll == 3) sprintf(Company, "GSbAG");
	if (dieroll == 4) sprintf(Company, "Hortalez et Cie, LIC");
	if (dieroll == 5) sprintf(Company, "Instellarms, LIC");
	if (dieroll == 6) sprintf(Company, "Ling-Standard Products");
	if (dieroll == 7) sprintf(Company, "Makhidkarun Communications");
	if (dieroll == 8) sprintf(Company, "Naasirka");
	if (dieroll == 9) sprintf(Company, "Sharurshid");
	if (dieroll == 10) sprintf(Company, "Sternmetal Horizons, LIC");
	if (dieroll == 11) sprintf(Company, "SuSAG, LIC");
	if (dieroll == 12) sprintf(Company, "Tukera Lines, LIC");
	if (dieroll == 13) sprintf(Company, "Zirunkariish");
	if (dieroll > 13) sprintf(Company, " ");

	return Company;
}

void Generate_Job_ad(void)
{

	int  dieroll = 0;
	


	dieroll = rand() % 20 + 1;

	sprintf(JobName,"%s", Available_Job());

	//random company
	if (dieroll < 15){
		sprintf(CompanyName,"%s%s%s", CompanyPrefix(), CompanySuffix(), Company_Descriptor());
	}
	else{
		//known company
		sprintf(CompanyName,"%s", Known_Company());
	}
}