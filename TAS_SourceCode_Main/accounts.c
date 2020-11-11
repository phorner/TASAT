
/* 
	Traveller's Aid Society Access Terminal

	     by Perry Horner 2001
	  

  The Traveller game in all forms is owned by Far Future Enterprises. 
  Copyright 1977 - 2016 Far Future Enterprises. Traveller is a registered 
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


int checkmouseboundsAccounts()
{  

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	
	int txtcounter=0;
	

	//check to see if selection is on the grid
	if (mouse_position.X<1) return ACCOUNTSERVICEWINDOW;
	if (mouse_position.Y<1) return ACCOUNTSERVICEWINDOW;
	
	//BANKING
	if ((mouse_position.X>294) && (mouse_position.X<691) && (mouse_position.Y>233) && (mouse_position.Y<282)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		
		addtoaccount = 0;
		displaybalance = 0;
		tempaccount[0] = '\0';
		
		TASWindow=BANKINGWINDOW;
		TASCurrentMenuWindow=ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
		
	}

	//LOANS
	if ((mouse_position.X>294) && (mouse_position.X<691) && (mouse_position.Y>356) && (mouse_position.Y<403)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		
		TASWindow = LOANWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return LOANWINDOW;
		
	}

	//PERSONAL
	if ((mouse_position.X>294) && (mouse_position.X<691) && (mouse_position.Y>473) && (mouse_position.Y<522)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		
		//ADMINISTRATOR SERVICES
		if (uAccessLevel == 10)
		{
			//change year input box assigned ID value 400
			ChangeYearTextBox = guienv->addEditBox(L"", rect<s32>(243, 653, 300, 675), true, 0, 400);
			ChangeYearTextBox->setMax(5);
			ChangeYearTextBox->setAutoScroll(false);
			ChangeYearTextBox->setMultiLine(false);
			ChangeYearTextBox->setWordWrap(false);
			ChangeYearTextBox->setDrawBackground(true);
			ChangeYearTextBox->setOverrideFont(Courier10Green);
			ChangeYearTextBox->setOverrideColor(video::SColor(255, 0, 100, 0));
			ChangeYearTextBox->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);

			//change day input box assigned ID value 400
			ChangeDayTextBox = guienv->addEditBox(L"", rect<s32>(243, 694, 300, 722), true, 0, 400);
			ChangeDayTextBox->setMax(4);
			ChangeDayTextBox->setAutoScroll(false);
			ChangeDayTextBox->setMultiLine(false);
			ChangeDayTextBox->setWordWrap(false);
			ChangeDayTextBox->setDrawBackground(true);
			ChangeDayTextBox->setOverrideFont(Courier10Green);
			ChangeDayTextBox->setOverrideColor(video::SColor(255, 0, 100, 0));
			ChangeDayTextBox->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);

			//Set current year and day
			TAStempday = L"";
			TAStempday += TASDay;
			TAStempyear = L"";
			TAStempyear += TASYear;
			//sprintf(currentdate, "%d-%d", TASYear, TASDay);
			ChangeYearTextBox->setText(irr::core::stringw(TAStempyear).c_str());
			ChangeDayTextBox->setText(irr::core::stringw(TAStempday).c_str());
			
		}
		TASWindow = PERSONALWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return PERSONALWINDOW;
		
	}

	//return to MAIN WINDOW MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>745) && (mouse_position.Y<760)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		
		TASWindow=MAINMENUWINDOW;
        TASCurrentMenuWindow=MAINMENUWINDOW;
		//clear bitmaps to save memmory
		//ClearAccounts();
		backsurf = MainMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		return MAINMENUWINDOW;
	} 
	
	
	return ACCOUNTSERVICEWINDOW;

}



int checkmouseboundsBank()
{  
	
	int xlookup=0,ylookup=0,templines=0;
	char tempname[81];
	char tempfile[255]; //filename for message
	FILE  *fd1=NULL;

	//displaybalance - display account balance on 1, add to balance on 2, withdraw on 3
	//tempacount - temporary value added (character);

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;



	//check to see if selection is on the grid
	if (xlookup<1) return BANKINGWINDOW;
	if (ylookup<1) return BANKINGWINDOW;

	
	//Display ACCOUNT BALANCE
	if ((xlookup>531)&&(xlookup<729)&&(ylookup>391)&&(ylookup<438)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		displaybalance = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}

	//Add to BALANCE
	if ((xlookup >531) && (xlookup <729) && (ylookup >482) && (ylookup <527)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		displaybalance = 2;
		addtoaccount = 0;
		withdrawaccount = 0;
		keypresscount = 0;
		sprintf(tempaccount, "0\0");
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}

	//Withdraw from BALANCE
	if ((xlookup >531) && (xlookup <729) && (ylookup >568) && (ylookup <616)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		displaybalance = 3;
		withdrawaccount = 0;
		addtoaccount = 0;
		keypresscount = 0;
		sprintf(tempaccount, "0\0");
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}

	//return to ACCOUNT SERVICES window
	if ((xlookup>854)&&(xlookup<1015)&&(ylookup>745)&&(ylookup<760)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		TASWindow = ACCOUNTSERVICEWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		//clear bitmaps to save memmory
		return ACCOUNTSERVICEWINDOW;
	} 

	//Keypad 1
	if ((xlookup >101) && (xlookup <207) && (ylookup >166) && (ylookup <276) && ((displaybalance==2)||(displaybalance==3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		Delay(50);
		strncat(tempaccount, "1", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 2
	if ((xlookup >224) && (xlookup <327) && (ylookup >166) && (ylookup <276) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "2", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 3
	if ((xlookup >346) && (xlookup <449) && (ylookup > 166) && (ylookup < 276) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "3", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 4
	if ((xlookup >101) && (xlookup <207) && (ylookup >293) && (ylookup <396) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "4", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 5
	if ((xlookup >224) && (xlookup <327) && (ylookup >293) && (ylookup <396) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "5", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 6
	if ((xlookup >346) && (xlookup <449) && (ylookup > 293) && (ylookup  < 396) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "6", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 7
	if ((xlookup >101) && (xlookup <207) && (ylookup >415) && (ylookup <523) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "7", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 8
	if ((xlookup >224) && (xlookup <327) && (ylookup >415) && (ylookup <523) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "8", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 9
	if ((xlookup >346) && (xlookup <449) && (ylookup > 415) && (ylookup < 523) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "9", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad 0
	if ((xlookup >224) && (xlookup <327) && (ylookup >544) && (ylookup <650) && ((displaybalance == 2) || (displaybalance == 3)) && (keypresscount<21)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		Delay(50);
		strncat(tempaccount, "0", sizeof(char));
		keypresscount++;
		addtoaccount = 1;
		withdrawaccount = 1;
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad CANCEL
	if ((xlookup >101) && (xlookup <207) && (ylookup >544) && (ylookup <650) && ((displaybalance == 2) || (displaybalance == 3))) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		displaybalance = 0;
		addtoaccount = 0;
		withdrawaccount = 0;
		keypresscount = 0;
		strcpy(tempaccount, "\0");
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	//Keypad ENTER
	if ((xlookup >346) && (xlookup <449) && (ylookup > 544) && (ylookup < 650) && ((displaybalance == 2) || (displaybalance == 3))) 
	{

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		if (displaybalance == 2)
		{
			//add to account balance
			addtoaccount = accountbalance + atoi(tempaccount);
			if ((addtoaccount <= 2000000000) && (addtoaccount >= 0))
			{
				//send mail message with statement
				fd1 = NULL;
				sprintf(tempfile, "communications/messages/mailbox/%d.msg", MemberNumber);

				fd1 = fopen(tempfile, "a");

				fprintf(fd1, "%s\n", uName); //message recipient TO: (TAS member number or other name)
				fprintf(fd1, "TAS Mail Terminal\n"); //message destination system or world
				fprintf(fd1, "%s\n", currentdate); //current send date
				fprintf(fd1, "TAS Bank Account\n"); //sender username
				fprintf(fd1, "0\n"); //sender TAS member number
				fprintf(fd1, "0\n"); // message marked unread				
				fprintf(fd1, "BANK ACCOUNT DEPOSIT\n");
				fprintf(fd1, "Previous balance:  %d\n", accountbalance);
				fprintf(fd1, "Deposit amount:  %d\n", atoi(tempaccount));
				fprintf(fd1, "\n");
				fprintf(fd1, "Ending balance:  %d\n", addtoaccount);
				fprintf(fd1, "~~CUT~~\n");
				fclose(fd1);

				//send mail message to administrator with statement
				fd1 = NULL;
				sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");
				fd1 = fopen(tempfile, "a");



				fprintf(fd1, "Administrator\n"); //message recipient TO: (TAS member number or other name)
				fprintf(fd1, "TAS Mail Terminal\n"); //message destination system or world
				fprintf(fd1, "%s\n", currentdate); //current send date
				fprintf(fd1, "%s\n", uName); //sender username
				fprintf(fd1, "%d\n", MemberNumber); //sender TAS member number
				fprintf(fd1, "0\n"); // message marked unread	
				fprintf(fd1, "BANK ACCOUNT DEPOSIT for %s\n", uName);
				fprintf(fd1, "Previous balance:  %d\n", accountbalance);
				fprintf(fd1, "Deposit amount:  %d\n", atoi(tempaccount));
				fprintf(fd1, "\n");
				fprintf(fd1, "Ending balance:  %d\n", addtoaccount);
				fprintf(fd1, "~~CUT~~\n");
				fclose(fd1);

				//refresh mailbox
				Clear_Mailbox();
				Load_Mailbox();

				accountbalance = accountbalance + atoi(tempaccount);



			} //end if ((addtoaccount <= 2000000000) && (addtoaccount >= 0))

			IImage *screenshot = driver->createScreenShot();
			video::IImage* export_img = driver->createImage(screenshot, core::vector2d<s32>(0, 0), core::dimension2d<u32>(1024, 768));
			video::ITexture* texture = driver->addTexture(L"export_imag", export_img);
			texture->grab();
			driver->draw2DImage(texture, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

			arial_24_yellow_blackout_bevel->draw(L"Deposit Complete", core::rect<s32>(552, 200, 0, 0), video::SColor(255, 255, 255, 255));

			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();

			driver->beginScene(true, true, SColor(0, 0, 0, 0));

			smgr->drawAll();
			Delay(1000);

			//write account balance
			sprintf(tempname, "accounts/bank/%d.txt", MemberNumber);
			fd1 = NULL;
			fd1 = fopen(tempname, "w");
				if (fd1){
					fprintf(fd1, "%d\n", accountbalance);
				}
			fclose(fd1);

		} //end if displaybalance = 2 deposit

		if (displaybalance == 3){
			//withdraw from account balance
			withdrawaccount = accountbalance;
			accountbalance = accountbalance - atoi(tempaccount);
		
			if (accountbalance < 0){
				accountbalance = withdrawaccount;

				IImage *screenshot2 = driver->createScreenShot();
				video::IImage* export_img2 = driver->createImage(screenshot2, core::vector2d<s32>(0, 0), core::dimension2d<u32>(1024, 768));
				video::ITexture* texture2 = driver->addTexture(L"export_imag2", export_img2);
				texture2->grab();
				driver->draw2DImage(texture2, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

				arial_24_yellow_blackout_bevel->draw(L"Negative: Cancelled", core::rect<s32>(552, 190, 0, 0), video::SColor(255, 255, 255, 255));

				smgr->drawAll();
				guienv->drawAll();
				driver->endScene();

				smgr->drawAll();
				Delay(1000);

			}
			else {
				//send mail message with statement
				fd1 = NULL;
				sprintf(tempfile, "communications/messages/mailbox/%d.msg", MemberNumber);
				fd1 = fopen(tempfile, "a");

				fprintf(fd1, "%s\n", uName); //message recipient TO: (TAS member number or other name)
				fprintf(fd1, "TAS Mail Terminal\n"); //message destination system or world
				fprintf(fd1, "%s\n", currentdate); //current send date
				fprintf(fd1, "Bank Account\n"); //sender username
				fprintf(fd1, "0\n"); //sender TAS member number
				fprintf(fd1, "0\n"); //is mail read
				fprintf(fd1, "BANK ACCOUNT WITHDRAWL\n");
				fprintf(fd1, "Previous balance:  %d\n", withdrawaccount);
				fprintf(fd1, "Withdrawl amount:  %d\n", atoi(tempaccount));
				fprintf(fd1, "\n");
				fprintf(fd1, "Ending balance:  %d\n", accountbalance);
				fprintf(fd1, "~~CUT~~\n");
				fclose(fd1);

				//send mail message to administrator with statement
				fd1 = NULL;
				sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");
				fd1 = fopen(tempfile, "a");

				fprintf(fd1, "Administrator\n"); //message recipient TO: (TAS member number or other name)
				fprintf(fd1, "Admin Mailbox\n"); //message destination system or world
				fprintf(fd1, "%s\n", currentdate); //current send date
				fprintf(fd1, "%s\n", uName); //sender username
				fprintf(fd1, "%d\n", MemberNumber); //sender TAS member number
				fprintf(fd1, "0\n"); //is read
				fprintf(fd1, "BANK ACCOUNT WITHDRAWL for %s\n", uName);
				fprintf(fd1, "Previous balance:  %d\n", withdrawaccount);
				fprintf(fd1, "Withdrawl amount:  %d\n", atoi(tempaccount));
				fprintf(fd1, "\n");
				fprintf(fd1, "Ending balance:  %d\n", accountbalance);
				fprintf(fd1, "~~CUT~~\n");
				fclose(fd1);

				//refresh mailbox
				Clear_Mailbox();
				Load_Mailbox();

				IImage *screenshot3 = driver->createScreenShot();
				video::IImage* export_img3 = driver->createImage(screenshot3, core::vector2d<s32>(0, 0), core::dimension2d<u32>(1024, 768));
				video::ITexture* texture3 = driver->addTexture(L"export_imag3", export_img3);
				texture3->grab();
				driver->draw2DImage(texture3, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

				arial_24_yellow_blackout_bevel->draw(L"Withdrawl Complete", core::rect<s32>(552, 200, 0, 0), video::SColor(255, 255, 255, 255));

				smgr->drawAll();
				guienv->drawAll();
				driver->endScene();

				smgr->drawAll();
				Delay(1000);

			}

			//write account balance
			sprintf(tempname, "accounts/bank/%d.txt", MemberNumber);
			fd1 = NULL;
			fd1 = fopen(tempname, "w");
			if (fd1){
				fprintf(fd1, "%d\n",accountbalance);
			}
			fclose(fd1);
		} //end if displaybalance= 3 withdrawl


		//free variables
		sprintf(characcountbalance, "%d\0", accountbalance);
		addtoaccount = 0;
		withdrawaccount = 0;
		displaybalance = 0;
		keypresscount = 0;
		strcpy(tempaccount, "\0");
		TASWindow = BANKINGWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		return BANKINGWINDOW;
	}
	
	return BANKINGWINDOW;
	
}

/***************Create the search box*************/
int CreateLoanBox()
{
	if (editboxIDValue)
	{ 
		editboxIDValue->remove(); //get rid of existing box
		editboxIDValue = NULL;
	}

	loanboxcreated = 1;
	LoanInputBox = NULL;
	LoanInputBox = guienv->addEditBox(L"", rect<s32>(160, 610, 569, 670), true, 0, 115);
	LoanInputBox->setMax(38); //maximum loan amount digits
	LoanInputBox->setAutoScroll(false);
	LoanInputBox->setMultiLine(false);
	LoanInputBox->setWordWrap(false);
	LoanInputBox->setOverrideFont(Courier10Black);

	LoanInputBox->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);
	guienv->setFocus(LoanInputBox);
	guienv->drawAll();
	guienv->setFocus(LoanInputBox);
	return 0;

} //end CreateLoanBox

int checkmouseboundsLoan()
{
	
	int xlookup = 0, ylookup = 0, templines=0;
	double Payment = 0;
	int r = 0; //used for random number for filename
	char tempfile[80];

	FILE *fd1;



	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;



	//check to see if selection is on the grid
	if (xlookup<1) return LOANWINDOW;
	if (ylookup<1) return LOANWINDOW;

	
	//START Loan Button
	if ((xlookup>711) && (xlookup <847) && (ylookup>587) && (ylookup<624) && (loansubmit == 0) && (loanboxcreated==0)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		loanrequest = (char *)calloc((unsigned)strlen("            "), sizeof(char));
		UpdateTheScreen=1;
		loanborrow=0; //flag - 0 no borrow, 1 borrow amount submitted
		loanselection = 0;

		backsurf = loancredit;
		CreateLoanBox();
	} //loan request


	//Bank selection
	if ((xlookup > 211) && (xlookup <226) && (ylookup> 218) && (ylookup <237) && (loanborrow == 1)&& (loansubmit==0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		loanselection = 1;
	}
	if ((xlookup > 211) && (xlookup <226) && (ylookup > 281) && (ylookup <296) && (loanborrow == 1) && (loansubmit == 0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		loanselection = 2;
	}
	if ((xlookup > 211) && (xlookup <226) && (ylookup> 339) && (ylookup <355) && (loanborrow == 1) && (loansubmit == 0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		loanselection = 3;
	}
	if ((xlookup > 211) && (xlookup<226) && (ylookup > 398) && (ylookup <414) && (loanborrow == 1) && (loansubmit == 0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		loanselection = 4;
	}

	//SUBMIT loan
	if ((xlookup > 720) && (xlookup <835) && (ylookup > 660) && (ylookup <695) && (loanborrow == 1) && (loansubmit == 0) && (loanselection>0) && (loanboxcreated == 0))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		loansubmit = 1;

		
		//Calculate monthly payment for a 60 year term

		//bank 1
		if (loanselection == 1)
		{
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated1*.01))));
		}
		//bank 2
		if (loanselection == 2)
		{
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated2*.01))));
		}
		//bank 3
		if (loanselection == 3)
		{
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated3*.01))));
		}
		//bank 4
		if (loanselection == 4)
		{
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated4*.01))));
		}
		Payment = ((totalloannumber / 60) / 12);
		


		if (loanselection == 1){

			loanform = NULL;

			if (loanform) loanform->unlock();
			driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
			if (loanform) driver->removeTexture(loanform);

			loanform = driver->getTexture("bmaps/accounts/loanform1.jpg");//bank 1
			if (loanform == NULL)
			{
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "Could not load bmaps/accounts/loanform1.jpg\n");
				fclose(ERR);
				CleanUp();
				device->drop();
				return 1;
			}
			loanform->regenerateMipMapLevels(0);

			if (loanform) loanform->lock(ETLM_READ_WRITE);
		} //end if loanselection =1

		if (loanselection == 2){

			loanform = NULL;

			if (loanform) loanform->unlock();
			driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
			if (loanform) driver->removeTexture(loanform);

			loanform = driver->getTexture("bmaps/accounts/loanform2.jpg");//bank 2
			if (loanform == NULL)
			{
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "Could not load bmaps/accounts/loanform2.jpg\n");
				fclose(ERR);
				CleanUp();
				device->drop();
				return 1;
			}
			loanform->regenerateMipMapLevels(0);

			if (loanform) loanform->lock(ETLM_READ_WRITE);
		} //end if loanselection = 2

		if (loanselection == 3){

			loanform = NULL;

			if (loanform) loanform->unlock();
			driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
			if (loanform) driver->removeTexture(loanform);

			loanform = driver->getTexture("bmaps/accounts/loanform3.jpg");//bank 3
			if (loanform == NULL)
			{
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "Could not load bmaps/accounts/loanform3.jpg\n");
				fclose(ERR);
				CleanUp();
				device->drop();
				return 1;
			}
			loanform->regenerateMipMapLevels(0);

			if (loanform) loanform->lock(ETLM_READ_WRITE);
		}//end if loanselection =3

		if (loanselection == 4){

			loanform = NULL;

			if (loanform) loanform->unlock();
			driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
			if (loanform) driver->removeTexture(loanform);

			loanform = driver->getTexture("bmaps/accounts/loanform4.jpg");//bank 4
			if (loanform == NULL)
			{
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "Could not load bmaps/accounts/loanform4.jpg\n");
				fclose(ERR);
				CleanUp();
				device->drop();
				return 1;
			}
			loanform->regenerateMipMapLevels(0);

			if (loanform) loanform->lock(ETLM_READ_WRITE);
		}//end if loanselection =4

		//paint the background
		backsurf = loanform;
		driver->endScene();
		driver->beginScene(true, true, SColor(0, 0, 0, 0));
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	} //end if submit button pressed

	//return to ACCOUNT SERVICES window
	if ((xlookup >854) && (xlookup <1015) && (ylookup>745) && (ylookup <760) && (loanboxcreated==0)) {

		if (editboxIDValue)
		{
			editboxIDValue->remove(); //get rid of existing box
			editboxIDValue = NULL;
		}
		

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		//save form to saved/account
		//CREDIT / LOAN
			// 1 Spinward credit union
			// 2 Sternmetal Financial
			// 3 Bank of Sylea
			// 4 Imperial Loans
		if (loansubmit == 1){
			if (loanselection == 1){
				r = (rand() % 100000) + 1;
				sprintf(tempsubfname, ".\\saved\\account\\%s%s_SpinwardLoan%d.bmp", uName, UPP, r);
				sprintf(tempsavefilename, "%s%s_SpinwardLoan%d.bmp", uName, UPP, r);
				Screenshot(tempsubfname, LOANWINDOW);
			}
			if (loanselection == 2){
				r = (rand() % 100000) + 1;
				sprintf(tempsubfname, ".\\saved\\account\\%s%s_SM_Loan%d.bmp", uName, UPP, r);
				sprintf(tempsavefilename, "%s%s_SM_Loan%d.bmp", uName, UPP, r);
				Screenshot(tempsubfname, LOANWINDOW);
			}
			if (loanselection == 3){
				r = (rand() % 100000) + 1;
				sprintf(tempsubfname, ".\\saved\\account\\%s%s_SyleaLoan%d.bmp", uName, UPP, r);
				sprintf(tempsavefilename, "%s%s_SyleaLoan%d.bmp", uName, UPP, r);
				Screenshot(tempsubfname, LOANWINDOW);
			}
			if (loanselection == 4){
				r = (rand() % 100000) + 1;
				sprintf(tempsubfname, ".\\saved\\account\\%s%s_ImperialLoan%d.bmp", uName, UPP, r);
				sprintf(tempsavefilename, "%s%s_ImperialLoan%d.bmp", uName, UPP, r);
				Screenshot(tempsubfname, LOANWINDOW);
			}

			//recalculate monthly payment
			Payment = ((totalloannumber / 60) / 12);

			fd1 = NULL;
			sprintf(tempfile, "communications/messages/mailbox/%d.msg", MemberNumber);
			fd1 = fopen(tempfile, "a");

			fprintf(fd1, "%s\n", uName); //message recipient TO: (TAS member number or other name)
			fprintf(fd1, "TAS Mail Terminal\n"); //message destination system or world
			fprintf(fd1, "%s\n", currentdate); //current send date
			fprintf(fd1, "Loan Administration\n"); //sender username
			fprintf(fd1, "0\n"); //sender TAS member number
			fprintf(fd1, "0\n"); //is read
			if (loanselection == 1) fprintf(fd1, "Spinward Credit Union LOAN APPLICATION Approved\n");
			if (loanselection == 2) fprintf(fd1, "SternMetal Financial LOAN APPLICATION Approved\n");
			if (loanselection == 3) fprintf(fd1, "Bank of Sylea LOAN APPLICATION Approved\n");
			if (loanselection == 4) fprintf(fd1, "Imperial Loans LOAN APPLICATION Approved\n");
			fprintf(fd1, "Loan Amount: %s credits\n", loanrequest);
			if (loanselection == 1) fprintf(fd1, "Interest Rate: %.1f %%\n", interestgenerated1);
			if (loanselection == 2) fprintf(fd1, "Interest Rate: %.1f %%\n", interestgenerated2);
			if (loanselection == 3) fprintf(fd1, "Interest Rate: %.1f %%\n", interestgenerated3);
			if (loanselection == 4) fprintf(fd1, "Interest Rate: %.1f %%\n", interestgenerated4);
			fprintf(fd1, "\n");
			
			fprintf(fd1, "Monthly Payment: %.1f Cr\n",Payment);
			fprintf(fd1, "60-year term total: %d Cr\n", totalloannumber);
			fprintf(fd1, "~~CUT~~\n");
			fclose(fd1);

			//send mail message to administrator with statement
			fd1 = NULL;
			sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");
			fd1 = fopen(tempfile, "a");

			fprintf(fd1, "Loan Administrator\n"); //message recipient TO: (TAS member number or other name)
			fprintf(fd1, "TAS Mail Terminal\n"); //message destination system or world
			fprintf(fd1, "%s\n", currentdate); //current send date
			fprintf(fd1, "%s\n", uName); //sender username
			fprintf(fd1, "0\n"); //sender TAS member number
			fprintf(fd1, "0\n"); //is read
			if (loanselection == 1) fprintf(fd1, "Spinward Credit Union LOAN APPLICATION Approved\n");
			if (loanselection == 2) fprintf(fd1, "SternMetal Financial LOAN APPLICATION Approved\n");
			if (loanselection == 3) fprintf(fd1, "Bank of Sylea LOAN APPLICATION Approved\n");
			if (loanselection == 4) fprintf(fd1, "Imperial Loans LOAN APPLICATION Approved\n");
			fprintf(fd1, "Loan Amount: %s credits\n", loanrequest);
			if (loanselection == 1) fprintf(fd1, "Interest Rate:%.1f %%\n", interestgenerated1);
			if (loanselection == 2) fprintf(fd1, "Interest Rate:%.1f %%\n", interestgenerated2);
			if (loanselection == 3) fprintf(fd1, "Interest Rate:%.1f %%\n", interestgenerated3);
			if (loanselection == 4) fprintf(fd1, "Interest Rate:%.1f %%\n", interestgenerated4);
			fprintf(fd1, "\n");
			fprintf(fd1, "***Loan application picture saved to %s ***\n", tempsubfname);
			fprintf(fd1, "Monthly Payment: %.1f Cr\n",Payment);
			fprintf(fd1, "60-year term total: %d Cr\n", totalloannumber);

			fprintf(fd1, "~~CUT~~\n");
			fclose(fd1);
			
		} //end saving loan form if Loan was Submitted


		TASWindow = ACCOUNTSERVICEWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		loanborrow = 0; //flag - 0 no borrow, 1 borrow amount submitted
		loanselection = 0;
		loansubmit = 0;
		loanboxcreated = 0;
		totalloannumber = 0;
		loanrequest = NULL;
		totalloan = NULL;
		//clear bitmaps to save memmory
		return ACCOUNTSERVICEWINDOW;
	} //exit Loan services window
	

	return LOANWINDOW;


}


int checkmouseboundsPersonal()
{
	
	int xlookup=0,ylookup=0;


	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;



	//check to see if selection is on the grid
	if (xlookup<1) return PERSONALWINDOW;
	if (ylookup<1) return PERSONALWINDOW;

	//SET new date button
	if ((mouse_position.X > 363) && (mouse_position.X < 407) && (mouse_position.Y>660) && (mouse_position.Y < 688) && (uAccessLevel == 10))
	{
		//set new year, day, and year-day string
		TAStempyear = ChangeYearTextBox->getText();
		if ((_wtoi(TAStempyear.c_str()) >= 0) && (_wtoi(TAStempyear.c_str()) < 10000))
		{
			TASYear = _wtoi(TAStempyear.c_str());
		}
		else
		{
			//display date set message alert
			arial_24_yellow_blackout_bevel->draw(L"ERROR: Year not >=0 <10000", core::rect<s32>(363, 550, 0, 0), video::SColor(255, 255, 255, 255));
			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();
			driver->beginScene(true, true, SColor(0, 0, 0, 0));
			smgr->drawAll();
			Delay(1500);
			return PERSONALWINDOW;
		}
		TAStempday = ChangeDayTextBox->getText();
		if ((_wtoi(TAStempday.c_str()) > 0) && (_wtoi(TAStempday.c_str()) < 366))
		{
			TASDay = _wtoi(TAStempday.c_str());
			sprintf(currentdate, "%d-%d", TASYear, TASDay);
		}
		else
		{
			//display date set message alert
			arial_24_yellow_blackout_bevel->draw(L"ERROR: Day not 1-365", core::rect<s32>(363, 550, 0, 0), video::SColor(255, 255, 255, 255));
			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();
			driver->beginScene(true, true, SColor(0, 0, 0, 0));
			smgr->drawAll();
			Delay(1500);
			return PERSONALWINDOW;
		}

		//write updated xml config file
		WriteINIFile();
		//srand((unsigned)time(NULL));
		srand(TASDay + TASYear);
		RandomClassifieds(); //set the for sale ads for the day
		CheckNewsOfDay(); //set mews of the day flag

		//display date set message alert
		arial_24_yellow_blackout_bevel->draw(L"DATE SET", core::rect<s32>(363, 550, 0, 0), video::SColor(255, 255, 255, 255));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
		driver->beginScene(true, true, SColor(0, 0, 0, 0));
		smgr->drawAll();
		Delay(1500);
	}

	//return to ACCOUNT SERVICES window
	if ((xlookup>854) && (xlookup <1015) && (ylookup>745) && (ylookup<760)) {

		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		if (uAccessLevel == 10)
		{
			if (ChangeYearTextBox) ChangeYearTextBox->remove(); //destroy change year textbox
			if (ChangeDayTextBox) ChangeDayTextBox->remove();  //destroy change day textbox

		}


		TASWindow = ACCOUNTSERVICEWINDOW;
		TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;
		//clear bitmaps to save memmory
		backsurf = accountsvcs;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		return ACCOUNTSERVICEWINDOW;
	}
	
	return PERSONALWINDOW;

}

void DisplayAccountServices(void)
{
	

	if (backsurf != accountsvcs){

		backsurf = accountsvcs;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
	}

		displaybalance = 0;

}

void DisplayBankServices(void)
{


	backsurf = banking;


	if (displaybalance == 1){
		arial_36_mac_green->draw(irr::core::stringw(characcountbalance).c_str(), core::rect<s32>(552, 210, 0, 0), video::SColor(255, 255, 255, 255));
	}
	if (displaybalance == 2){
		if (addtoaccount == 0) {
		arial_36_mac_green->draw(L"ADD: Use keypad", core::rect<s32>(552, 190, 0, 0), video::SColor(255, 255, 255, 255));
		arial_36_mac_green->draw(L"then ENTER", core::rect<s32>(552, 240, 0, 0), video::SColor(255, 255, 255, 255));
		}
		if (atoi(tempaccount) > 0) arial_36_mac_green->draw(irr::core::stringw(tempaccount).c_str(), core::rect<s32>(530, 210, 0, 0), video::SColor(255, 255, 255, 255));
	}
	if (displaybalance == 3){
		if (withdrawaccount == 0) {
		arial_36_mac_green->draw(L"WD: Use keypad", core::rect<s32>(552, 190, 0, 0), video::SColor(255, 255, 255, 255));
		arial_36_mac_green->draw(L"then ENTER", core::rect<s32>(552, 240, 0, 0), video::SColor(255, 255, 255, 255));
		}
		if (atoi(tempaccount) > 0) arial_36_mac_green->draw(irr::core::stringw(tempaccount).c_str(), core::rect<s32>(530, 210, 0, 0), video::SColor(255, 255, 255, 255));
	}
	
}

void DisplayLoanServices(void)
{
	double Payment = 0;
	char tempdate[9];


	totalloan = NULL;
	tempstor = NULL;

	tempstor = (char *)calloc((unsigned)strlen("       "), sizeof(char)); //temporary value store for loan interest
	totalloan = (char *)calloc((unsigned)strlen("                    "), sizeof(char));//storage for loan amount

	sprintf(tempdate, "%d-%d", TASDay, TASYear);

	//paint the background
	if (loansubmit == 0)
	{
		backsurf = loancredit;

		if (loanselection == 1){
			driver->draw2DImage(orangestar, core::position2d<s32>(205, 216), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 1
		}
		if (loanselection == 2){
			driver->draw2DImage(orangestar, core::position2d<s32>(205, 274), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 2
		}
		if (loanselection == 3){
			driver->draw2DImage(orangestar, core::position2d<s32>(206, 334), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 3
		}
		if (loanselection == 4){
			driver->draw2DImage(orangestar, core::position2d<s32>(206, 392), core::rect<s32>(0, 0, 19, 19), 0, video::SColor(255, 255, 255, 255), true); //bank 4
		}

		//black out loan star selection buttons if no loan amount has been entered
		if (loanborrow < 1)
		{
			driver->draw2DRectangle(video::SColor(255, 0, 0, 0), core::rect<s32>(160, 194, 260, 426));
		}


		//if a loan request entered
		if (loanborrow == 1){

			//bank 1
			if (loanselection == 1)
			{
				totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated1*.01))));
			}
			//bank 2
			if (loanselection == 2)
			{
				totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated2*.01))));
			}
			//bank 3
			if (loanselection == 3)
			{
				totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated3*.01))));
			}
			//bank 4
			if (loanselection == 4)
			{
				totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated4*.01))));
			}
			
			//display loan amount
			arial_36_mac_green->draw(irr::core::stringw(loanrequest).c_str(), core::rect<s32>(700, 95, 0, 0), video::SColor(255, 255, 255, 255));

			if (loanselection > 0)
			{
				//display monthly payment
				Payment = ((totalloannumber / 60) / 12);
				arial_36_mac_green->draw(irr::core::stringw((int)Payment).c_str(), core::rect<s32>(220, 95, 0, 0), video::SColor(255, 255, 255, 255));
			}

			//************Display Rates***********************
			//bank 1
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated1*.01))));
			sprintf(tempstor, "%.1f\0", interestgenerated1);
			Optima18White->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(708, 200, 0, 0), video::SColor(255, 255, 255, 255));
			sprintf(totalloan, "%d cr\0", totalloannumber);
			Optima18White->draw(irr::core::stringw(totalloan).c_str(), core::rect<s32>(826, 200, 0, 0), video::SColor(255, 255, 255, 255));
			//bank 2
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated2*.01))));
			sprintf(tempstor, "%.1f\0", interestgenerated2);
			Optima18White->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(708, 265, 0, 0), video::SColor(255, 255, 255, 255));
			sprintf(totalloan, "%d cr\0", totalloannumber);
			Optima18White->draw(irr::core::stringw(totalloan).c_str(), core::rect<s32>(826, 265, 0, 0), video::SColor(255, 255, 255, 255));
			//bank 3
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated3*.01))));
			sprintf(tempstor, "%.1f\0", interestgenerated3);
			Optima18White->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(708, 325, 0, 0), video::SColor(255, 255, 255, 255));
			sprintf(totalloan, "%d cr\0", totalloannumber);
			Optima18White->draw(irr::core::stringw(totalloan).c_str(), core::rect<s32>(826, 325, 0, 0), video::SColor(255, 255, 255, 255));
			//bank 4
			totalloannumber = (int)((atoi(loanrequest) + (atoi(loanrequest)*(interestgenerated4*.01))));
			sprintf(tempstor, "%.1f\0", interestgenerated4);
			Optima18White->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(708, 385, 0, 0), video::SColor(255, 255, 255, 255));
			sprintf(totalloan, "%d cr\0", totalloannumber);
			Optima18White->draw(irr::core::stringw(totalloan).c_str(), core::rect<s32>(826, 385, 0, 0), video::SColor(255, 255, 255, 255));

		} //end if loanborrow=1

	}//end if loansubmit=0

	if (loansubmit == 1)
		{

			Payment = ((totalloannumber / 60) / 12);
			

			if (loanselection == 1){
				Courier10Black->draw(irr::core::stringw(uName).c_str(), core::rect<s32>(308, 220, 0, 0), video::SColor(255, 255, 255, 255));//player's name
				Courier10Black->draw(irr::core::stringw(loanrequest).c_str(), core::rect<s32>(308, 250, 0, 0), video::SColor(255, 255, 255, 255));//amount of loan less interest
				sprintf(tempstor, "%.1f%%\0", interestgenerated1);
				Courier10Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(308, 280, 0, 0), video::SColor(255, 255, 255, 255));// interest rate
				Courier10Black->draw(irr::core::stringw(tempdate).c_str(), core::rect<s32>(308, 425, 0, 0), video::SColor(255, 255, 255, 255));// date
				sprintf(tempstor, "Monthly Payment: %.1f Cr\0", Payment);
				Courier10Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(77, 477, 0, 0), video::SColor(255, 255, 255, 255));// Monthly payment

			}
			if (loanselection == 2){
				
				Optima18Black->draw(irr::core::stringw(uName).c_str(), core::rect<s32>(175, 190, 0, 0), video::SColor(255, 255, 255, 255));//player's name
				Optima18Black->draw(irr::core::stringw(loanrequest).c_str(), core::rect<s32>(596, 225, 0, 0), video::SColor(255, 255, 255, 255));//amount of loan less interest
				sprintf(tempstor, "%.1f \0", interestgenerated2);
				Optima18Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(570, 307, 0, 0), video::SColor(255, 255, 255, 255));// interest rate
				Optima18Black->draw(irr::core::stringw(tempdate).c_str(), core::rect<s32>(210, 615, 0, 0), video::SColor(255, 255, 255, 255));// date
				sprintf(tempstor, "Monthly Payment: %.1f Cr\0", Payment);
				Optima18Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(145, 409, 0, 0), video::SColor(255, 255, 255, 255));// Monthly payment
			}
			if (loanselection == 3){
				Optima18Black->draw(irr::core::stringw(uName).c_str(), core::rect<s32>(330, 157, 0, 0), video::SColor(255, 255, 255, 255));//player's name
				Optima18Black->draw(irr::core::stringw(loanrequest).c_str(), core::rect<s32>(330, 187, 0, 0), video::SColor(255, 255, 255, 255));//amount of loan less interest
				sprintf(tempstor, "%.1f \0", interestgenerated3);
				Optima18Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(330, 215, 0, 0), video::SColor(255, 255, 255, 255));// interest rate
				Optima18Black->draw(irr::core::stringw(tempdate).c_str(), core::rect<s32>(330, 330, 0, 0), video::SColor(255, 255, 255, 255));// date
				sprintf(tempstor, "Monthly Payment: %.1f Cr\0", Payment);
				Optima18Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(192, 456, 0, 0), video::SColor(255, 255, 255, 255));// Monthly payment
			}
			if (loanselection == 4){
				Optima18Black->draw(irr::core::stringw(uName).c_str(), core::rect<s32>(300, 266, 0, 0), video::SColor(255, 255, 255, 255));//player's name
				Optima18Black->draw(irr::core::stringw(loanrequest).c_str(), core::rect<s32>(310, 356, 0, 0), video::SColor(255, 255, 255, 255));//amount of loan less interest
				sprintf(tempstor, "%.1f \0", interestgenerated4);
				Optima18Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(275, 446, 0, 0), video::SColor(255, 255, 255, 255));// interest rate
				Optima18Black->draw(irr::core::stringw(tempdate).c_str(), core::rect<s32>(100, 180, 0, 0), video::SColor(255, 255, 255, 255));// date
				sprintf(tempstor, "Monthly Payment: %.1f Cr\0", Payment);
				Optima18Black->draw(irr::core::stringw(tempstor).c_str(), core::rect<s32>(100, 552, 0, 0), video::SColor(255, 255, 255, 255));// Monthly payment
			}

		} //end if loansubmit =1 
	

	tempstor = NULL;
	totalloan = NULL;
	
}


void DisplayPersonalServices(void)
{

	backsurf = acctinfo;



	Optima18White->draw(irr::core::stringw(TASMember[MemberNumber].MemberNumber).c_str(), core::rect<s32>(266, 134, 0, 0), video::SColor(255, 255, 255, 255));//TAS Membership number
	Optima18White->draw(irr::core::stringw(TASMember[MemberNumber].uName).c_str(), core::rect<s32>(266, 169, 0, 0), video::SColor(255, 255, 255, 255));//player's name
	Optima18White->draw(irr::core::stringw(TASMember[MemberNumber].UPP).c_str(), core::rect<s32>(266, 197, 0, 0), video::SColor(255, 255, 255, 255));//UPP

	Optima18White->draw(irr::core::stringw(uAccessLevel).c_str(), core::rect<s32>(266, 251, 0, 0), video::SColor(255, 255, 255, 255));//Access Level

	if (uAccessLevel > 0){
		arial_24_yellow_blackout_bevel->draw(irr::core::stringw(charAccessLevel).c_str(), core::rect<s32>(266, 244, 0, 0), video::SColor(255, 255, 255, 255));//Access level

		if (uAccessLevel == 1)
		{
			arial_24_red_blackout_bevel->draw(irr::core::stringw(L"  TAS Charter Member"), core::rect<s32>(290, 244, 0, 0), video::SColor(255, 255, 255, 255));//Access level membership
		}
		if ((uAccessLevel > 1) && (uAccessLevel <= 3))
		{
			arial_24_red_blackout_bevel->draw(irr::core::stringw(L"  TAS Bronze Member"), core::rect<s32>(290, 244, 0, 0), video::SColor(255, 255, 255, 255));//Access level membership
		}
		if ((uAccessLevel > 3) && (uAccessLevel <= 7))
		{
			arial_24_red_blackout_bevel->draw(irr::core::stringw(L"  TAS Silver Member"), core::rect<s32>(290, 244, 0, 0), video::SColor(255, 255, 255, 255));//Access level membership
		}
		if ((uAccessLevel == 8))
		{
			arial_24_red_blackout_bevel->draw(irr::core::stringw(L"  TAS Gold Member"), core::rect<s32>(290, 244, 0, 0), video::SColor(255, 255, 255, 255));//Access level membership
		}
		if ((uAccessLevel == 9))
		{
			arial_24_red_blackout_bevel->draw(irr::core::stringw(L"  TAS Lananum Member"), core::rect<s32>(290, 244, 0, 0), video::SColor(255, 255, 255, 255));//Access level membership
		}
		if ((uAccessLevel == 10))
		{
			arial_24_red_blackout_bevel->draw(irr::core::stringw(L"  TAS Administrator"), core::rect<s32>(290, 244, 0, 0), video::SColor(255, 255, 255, 255));//Access level membership
		}
	}
	else 
	{
		arial_24_red_blackout_bevel->draw(irr::core::stringw(charAccessLevel).c_str(), core::rect<s32>(266, 237, 0, 0), video::SColor(255, 255, 255, 255));//Access level
	}
	//Social standing
	if ((TASMember[MemberNumber].UPP[5] == 'B') || (TASMember[MemberNumber].UPP[5] == 'b')) Optima18White->draw(irr::core::stringw(L"Knight"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'C') || (TASMember[MemberNumber].UPP[5] == 'c')) Optima18White->draw(irr::core::stringw(L"Baron"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'D') || (TASMember[MemberNumber].UPP[5] == 'd')) Optima18White->draw(irr::core::stringw(L"Marquis"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'E') || (TASMember[MemberNumber].UPP[5] == 'e')) Optima18White->draw(irr::core::stringw(L"Count"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'F') || (TASMember[MemberNumber].UPP[5] == 'f')) Optima18White->draw(irr::core::stringw(L"Duke"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'G') || (TASMember[MemberNumber].UPP[5] == 'g')) Optima18White->draw(irr::core::stringw(L"Sector Duke"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'H') || (TASMember[MemberNumber].UPP[5] == 'h')) Optima18White->draw(irr::core::stringw(L"Arch Duke"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'I') || (TASMember[MemberNumber].UPP[5] == 'i')) Optima18White->draw(irr::core::stringw(L"Emperor"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));
	if ((TASMember[MemberNumber].UPP[5] == 'J') || (TASMember[MemberNumber].UPP[5] == 'j')) Optima18White->draw(irr::core::stringw(L"Emperor"), core::rect<s32>(266, 293, 0, 0), video::SColor(255, 255, 255, 255));

	Optima18White->draw(irr::core::stringw(TASMember[MemberNumber].uHomeWorld).c_str(), core::rect<s32>(266, 325, 0, 0), video::SColor(255, 255, 255, 255));//player's Homeworld
	Optima18White->draw(irr::core::stringw(TASMember[MemberNumber].uRace).c_str(), core::rect<s32>(266, 355, 0, 0), video::SColor(255, 255, 255, 255));//player's Race
	
	Optima18White->draw(irr::core::stringw(characcountbalance).c_str(), core::rect<s32>(266, 388, 0, 0), video::SColor(255, 255, 255, 255));//Bank account balance

	//ADMINISTRATOR SERVICES
	if (uAccessLevel <10)
	{
		//blackout change date buttons
		driver->draw2DRectangle(video::SColor(255, 0, 0, 0), core::rect<s32>(130, 636, 418, 733));
	}

}