
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


The bulk of the code is by Perry Horner (perry1@liberated-technologies.com)




*/

//**************************XBOAT***************************************


void DisplayXBoatMenu(void)
{

	//display message is waiting
	if (ismessagewaiting > 0)
	{
		arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(685, 125, 0, 0), video::SColor(255, 255, 255, 255));
	}
		if (backsurf != xboatmainmenu)
		{
			backsurf = xboatmainmenu;
			driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
			arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(685, 125, 0, 0), video::SColor(255, 255, 255, 255));
		}

}

void DisplayXBoatSendMenu(void)
{

		if (newmessage == 1)
		{
			driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
			Courier10Black->draw(irr::core::stringw(currentdate).c_str(), core::rect<s32>(475, 55, 0, 0), video::SColor(255, 255, 255, 255));
		}		
}

void DisplayXBoatReadMenu(void)
{

	//display message is waiting
	if (backsurf != xboatreadmessagemenu)
	{
		backsurf = xboatreadmessagemenu;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
	}

	if (ismessagewaiting > 0)
	{
		sprintf(awaitingmessage, "%i New Messages", newmailcount);
		arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(705, 125, 0, 0), video::SColor(255, 255, 255, 255));
	}
	


}

void DisplayXBoatReadNewMenu(void)
{

	backsurf=xboatreadmessagemenu;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

	//black out read/old/new menu selection
	driver->draw2DRectangle(video::SColor(255, 0, 0, 0), core::rect<s32>(744, 364, 1015, 506));

	//display message is waiting
	if (ismessagewaiting > 0)
	{
		sprintf(awaitingmessage, "%i New Messages", newmailcount);
		arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(705, 125, 0, 0), video::SColor(255, 255, 255, 255));
		Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sendermembernumber).c_str(), core::rect<s32>(42, 105, 0, 0), video::SColor(255, 255, 255, 255));
		Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sendername).c_str(), core::rect<s32>(105, 105, 0, 0), video::SColor(255, 255, 255, 255));
		Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].xbdestination).c_str(), core::rect<s32>(400, 105, 0, 0), video::SColor(255, 255, 255, 255));
		Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sentdate).c_str(), core::rect<s32>(475, 55, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if ((newmailcount > 0)&&(ismessagewaiting>0))
	{
		//NEXT Button
		driver->draw2DImage(xboatnextbutton, core::position2d<s32>(285, 700), core::rect<s32>(0, 0, 89, 39), 0, video::SColor(255, 255, 255, 255), true);

	}  //display the NEXT message button if more than one message

	

	
}

void DisplayXBoatReadOldMenu(void)
{


	//black out read/old/new menu selection
	driver->draw2DRectangle(video::SColor(255, 0, 0, 0), core::rect<s32>(744, 364, 1015, 506));


	sprintf(awaitingmessage, "%i Messages", oldmailcount);
	arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(720, 125, 0, 0), video::SColor(255, 255, 255, 255));

	sprintf(awaitingmessage, "Message #:%d", mymessagenumber);
	arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(720, 165, 0, 0), video::SColor(255, 255, 255, 255));

	if (oldmailcount > 1){
		driver->draw2DImage(xboatnextbutton, core::position2d<s32>(285, 700), core::rect<s32>(0, 0, 89, 39), 0, video::SColor(255, 255, 255, 255), true); //next
		driver->draw2DImage(xboatbackbutton, core::position2d<s32>(50, 700), core::rect<s32>(0, 0, 89, 39), 0, video::SColor(255, 255, 255, 255), true); //back
	}  //display the NEXT and BACK message button if more than one message

	if (oldmailcount>0){
	Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sendermembernumber).c_str(), core::rect<s32>(42, 105, 0, 0), video::SColor(255, 255, 255, 255));
	Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sendername).c_str(), core::rect<s32>(105, 105, 0, 0), video::SColor(255, 255, 255, 255));
	Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].xbdestination).c_str(), core::rect<s32>(400, 105, 0, 0), video::SColor(255, 255, 255, 255));
	Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sentdate).c_str(), core::rect<s32>(475, 55, 0, 0), video::SColor(255, 255, 255, 255));
		//mymessages[mymessagenumber].markedread = 0; 
	}
	
}

int checkmouseboundsXboatMenu(void)
{
	

	int txtcounter = 0;
	
	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();


	//check to see if selection is on the grid
	if (mouse_position.X<1) return XBOATMENU;
	if (mouse_position.Y<1) return XBOATMENU;

	sprintf(awaitingmessage, "%i New Messages", newmailcount);
	arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(705, 125, 0, 0), video::SColor(255, 255, 255, 255));



	//SEND MESSAGE
	if ((mouse_position.X > 768) && (mouse_position.X < 965) && (mouse_position.Y > 362) && (mouse_position.Y < 407)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		//clear message buffers
		memset(xbmessageto, 0, sizeof(xbmessageto)); //name or member number for send-to
		memset(xbdestination, 0, sizeof(xbdestination));  //name of where the message is going
		memset(sentdate, 0, sizeof(sentdate));  //date for sent message
		memset(sendername, 0, sizeof(sendername));  //name of message sender
		sendermembernumber=0; //TAS member number of sender
		memset(xbmessage, 0, sizeof(xbmessage)); //message body


		newmessage = 0;

		TASWindow = XBOATSENDMENU;
		TASCurrentMenuWindow = XBOATMENU;
		backsurf = xboatsendmessagemenu;
		return XBOATSENDMENU;

	}
	
	//READ MESSAGE
	if ((mouse_position.X > 768) && (mouse_position.X < 959) && (mouse_position.Y > 432) && (mouse_position.Y < 475) && TASWindow == XBOATMENU) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		backsurf=xboatreadmessagemenu;


		xboattextimage = guienv->addImage((xboatblank), core::position2d<s32>(0, 0)); //678x701 image or use another image
		xboattextimage->setAlignment(EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE);
		xboattextimage->setRelativePosition(core::rect<s32>(38, 185, 650, 620));

		textBox = new CGUITextBox(Courier10Black, L"", guienv, irr::core::rect<irr::s32>(5, 5, 615, 430), xboattextimage, -1);
		textBox->setScrollModeLines(true);
		textBox->setScrollbarRight(true);
		textBox->setVisible(true);
		textBox->setText(L" ");

		TASWindow = XBOATREADMENU;
		TASCurrentMenuWindow = XBOATMENU;
		return XBOATREADMENU;
	} //end of READ message

	

	//return to MAIN WINDOW MENU
	if ((mouse_position.X > 854) && (mouse_position.X < 1015) && (mouse_position.Y > 745) && (mouse_position.Y < 760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		newmessage = 0;

		TASWindow = MAINMENUWINDOW;
		TASCurrentMenuWindow = MAINMENUWINDOW;
		//clear bitmaps to save memmory
		//ClearXboat();


		backsurf = MainMenuBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		return MAINMENUWINDOW;
	}

	return XBOATMENU;
	
}

int checkmouseboundsXboatSend(void)
{
	
	int txtcounter = 0;
	int ismembernumber = 0; //validate a member number
	int tempmembercount = 0; //temporary counter to scan through member accounts
	char tempfile[255]; //filename for message
	char temprecipientname[50]; //temporary recipient name for string comparison
	s32 selected;  //user list selection
	const wchar_t *str; //string of selected user

	FILE *FDW2;

	

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();


	//check to see if selection is on the grid
	if (mouse_position.X<1) return XBOATMENU;
	if (mouse_position.Y<1) return XBOATMENU;

	if (newmessage == 1)
	{
		//get the string of the selected recipient if there is one
		selected = UserListbox->getSelected();
		if (selected>0)
		{
			str = UserListbox->getListItem(selected);
			RecipientTextBox->setText(str);
		}
	}

	//CLEAR MESSAGE
	if ((mouse_position.X >783) && (mouse_position.X <980) && (mouse_position.Y > 495) && (mouse_position.Y <544)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		
		memset(xbmessage, 0, sizeof(xbmessage)); // clear message	

		if (RecipientTextBox){
			UserListbox->setSelected(0); //default to "not listed" entry
			selected = UserListbox->getSelected();
			RecipientTextBox->setText(L"");
		}
		if (DestinationTextBox) DestinationTextBox->setText(L"");
		if (MessageBodyTextBox) MessageBodyTextBox->setText(L"");
	}

	//CREATE NEW MESSAGE
	if ((mouse_position.X >783) && (mouse_position.X <980) && (mouse_position.Y >433) && (mouse_position.Y <480) && (newmessage == 0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		if (newmessage == 1) return XBOATMENU; //if message is in the queue then break
		else newmessage = 1;
		

		//Recipient (adressee) input box assigned ID value 301
		RecipientTextBox = guienv->addEditBox(L"", rect<s32>(39, 100, 320, 120), true, 0, 301);
		RecipientTextBox->setMax(40);
		RecipientTextBox->setAutoScroll(false);
		RecipientTextBox->setMultiLine(false);
		RecipientTextBox->setWordWrap(false);
		RecipientTextBox->setDrawBackground(true);
		RecipientTextBox->setOverrideFont(Courier10Green);
		RecipientTextBox->setOverrideColor(video::SColor(255, 0, 100, 0));
		RecipientTextBox->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);

		//Destination  value 302
		DestinationTextBox = guienv->addEditBox(L"", rect<s32>(410, 100, 590, 120), true, 0, 302);
		DestinationTextBox->setMax(20);
		DestinationTextBox->setAutoScroll(false);
		DestinationTextBox->setMultiLine(false);
		DestinationTextBox->setWordWrap(false);
		DestinationTextBox->setDrawBackground(true);
		DestinationTextBox->setOverrideFont(Courier10Green);
		DestinationTextBox->setOverrideColor(video::SColor(255, 0, 100, 0));
		DestinationTextBox->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);
		  
		//xboat message body  value 303
		MessageBodyTextBox = guienv->addEditBox(L"", rect<s32>(44, 194, 646, 612), true, 0, 303);
		MessageBodyTextBox->setMax(5000);
		MessageBodyTextBox->setAutoScroll(true);
		MessageBodyTextBox->setMultiLine(true);
		MessageBodyTextBox->setWordWrap(true);
		MessageBodyTextBox->setDrawBackground(true);
		MessageBodyTextBox->setOverrideFont(Courier10Green);
		MessageBodyTextBox->setOverrideColor(video::SColor(255, 0, 100, 0));
		MessageBodyTextBox->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);

		//Add users to listbox	at value 300	
		UserListbox = guienv->addListBox(rect<s32>(740, 90, 980, 210),0,300,1);	
		UserListbox->setDrawBackground(true);
		UserListbox->addItem(L"[Other/Not Listed (type in name)]");
		
		for (tempmembercount = 0; tempmembercount < 200;tempmembercount++)
		{
			if ((TASMember[tempmembercount].MemberNumber > 0) && (TASMember[tempmembercount].TASMemberHidden == 0) && (TASMember[tempmembercount].MemberNumber != MemberNumber))
			{
				core::stringw charconvert = TASMember[tempmembercount].uName;
				UserListbox->addItem(charconvert.c_str());
			}
		}

		UserListbox->setSelected(0); //default to "not listed" entry
		selected = UserListbox->getSelected();
		RecipientTextBox->setText(L"");
		if (selected > 0)
		{
			str = UserListbox->getListItem(selected);
			RecipientTextBox->setText(str);
		}
		

	} //end of input message

	//SEND COMPLETED MESSAGE
	if ((mouse_position.X  > 783) && (mouse_position.X <980) && (mouse_position.Y  > 560) && (mouse_position.Y <605) && (newmessage == 1)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		//check if recipient is a TAS member or not.  If not, then recipient file is GENERIC.msg
		//check if message is sent to someone other than a TAS member



		for (tempmembercount = 0; tempmembercount < 200; tempmembercount++)
		{

			sprintf(temprecipientname, "%ls", RecipientTextBox->getText()); //convert from wide
			if (strcmp(TASMember[tempmembercount].uName, temprecipientname) == 0)

			{
				ismembernumber = TASMember[tempmembercount].MemberNumber;
			}
		}
		
		FDW2 = NULL;

		//validate and transform message recipient
		//check size of fields

		if (ismembernumber>0) sprintf(tempfile, "communications/messages/mailbox/%d.msg", ismembernumber);
		else sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");

		//if member number is less than 1, then it is not a member and will be sent to Admin GENERIC account
		FDW2 = fopen(tempfile, "a");
	
		fprintf(FDW2, "%ls\n", RecipientTextBox->getText()); //message recipient TO: (TAS member name)
		fprintf(FDW2, "%ls\n", DestinationTextBox->getText()); //message destination system or world
		fprintf(FDW2, "%s\n", currentdate); //current send date
		if (uAccessLevel < 10){
			fprintf(FDW2, "%s\n", uName); //sender username
			fprintf(FDW2, "%i\n", MemberNumber); //sender TAS member number
		}
		else {
			fprintf(FDW2, "%s\n", uName); //sender username
			fprintf(FDW2, "0\n"); //sender TAS member number
		}
		fprintf(FDW2, "0\n"); //marked read = 0 not read
		if (ismembernumber < 1)
		{
			fprintf(FDW2, "TO:  %ls\n", RecipientTextBox->getText());
		}
		fprintf(FDW2, "%ls\n", MessageBodyTextBox->getText());
		fprintf(FDW2, "~~CUT~~\n");
		fclose(FDW2);
		
		//clear message buffers
		memset(xbmessage, 0, sizeof(xbmessage)); // clear message	
		//clear sent message queue
		newmessage = 0;
		if (RecipientTextBox){
			UserListbox->setSelected(0); //default to "not listed" entry
			selected = UserListbox->getSelected();
			RecipientTextBox->setText(L"");
		}
		if (DestinationTextBox) DestinationTextBox->setText(L"");
		if (MessageBodyTextBox) MessageBodyTextBox->setText(L"");

		if (UserListbox) UserListbox->remove(); //destroy user listbox
		if (RecipientTextBox) RecipientTextBox->remove();  //remove recipient input textbox
		if (DestinationTextBox) DestinationTextBox->remove();  //remove destination input textbox
		if (MessageBodyTextBox) MessageBodyTextBox->remove();  //remove message body input textbox

		//display sent message alert
		arial_24_yellow_blackout_bevel->draw(L"MESSAGE SENT", core::rect<s32>(220, 266, 0, 0), video::SColor(255, 255, 255, 255));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
		driver->beginScene(true, true, SColor(0, 0, 0, 0));
		smgr->drawAll();
		Delay(1500);

		newmessage = 0;
		TASWindow = XBOATMENU;
		TASCurrentMenuWindow = XBOATMENU;
		return XBOATMENU;
	}//end send message

	//return to MAIN WINDOW MENU
	if ((mouse_position.X >854) && (mouse_position.X <1015) && (mouse_position.Y >745) && (mouse_position.Y <760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		if (newmessage == 1)
		{
			if (UserListbox) UserListbox->remove(); //destroy user listbox
			if (RecipientTextBox) RecipientTextBox->remove();  //remove recipient input textbox
			if (DestinationTextBox) DestinationTextBox->remove();  //remove destination input textbox
			if (MessageBodyTextBox) MessageBodyTextBox->remove();  //remove message body input textbox
		}

		newmessage = 0;
		TASWindow = XBOATMENU;
		TASCurrentMenuWindow = XBOATMENU;
		return XBOATMENU;
	}

	if (newmessage == 1)
	{
		//get the string of the selected recipient if there is one
		selected = UserListbox->getSelected();
		if (selected>0)
		{
			str = UserListbox->getListItem(selected);
			RecipientTextBox->setText(str);
		}
	}

	return XBOATSENDMENU;
	
}

int checkmouseboundsXboatRead(void)
{
	
	int x=0;
	int txtcounter = 0;
	int yplacement = 220; //starting message line
	char modline[80] = "\0";


	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();


	//check to see if selection is on the grid
	if (mouse_position.X<1) return XBOATMENU;
	if (mouse_position.Y<1) return XBOATMENU;

	if (ismessagewaiting>0)
	{
		sprintf(awaitingmessage, "%i New Messages", newmailcount);
		arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(705, 125, 0, 0), video::SColor(255, 255, 255, 255));
	}

	//READ NEW MESSAGE
	if ((mouse_position.X > 747) && (mouse_position.X < 982) && (mouse_position.Y  > 374) && (mouse_position.Y < 410) && (ismessagewaiting>0)){
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//read awaiting message(s)

		

		//find starting new message index
		for (x = 0; x <= 1999; x++)
		{
			if (mymessages[x].markedread == 0)
			{
				mymessagenumber = x;
				core::stringw w_libdatatext = mymessages[mymessagenumber].xbmessage;
				textBox->setText(w_libdatatext.c_str());
				newmailcount--;
				oldmailcount++;
				mymessages[mymessagenumber].markedread = 1;

				sprintf(awaitingmessage, "%i New Messages", newmailcount);
				arial_24_yellow_blackout_bevel->draw(irr::core::stringw(awaitingmessage).c_str(), core::rect<s32>(705, 125, 0, 0), video::SColor(255, 255, 255, 255));
				Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sendermembernumber).c_str(), core::rect<s32>(42, 105, 0, 0), video::SColor(255, 255, 255, 255));
				Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sendername).c_str(), core::rect<s32>(105, 105, 0, 0), video::SColor(255, 255, 255, 255));
				Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].xbdestination).c_str(), core::rect<s32>(400, 105, 0, 0), video::SColor(255, 255, 255, 255));
				Courier10Black->draw(irr::core::stringw(mymessages[mymessagenumber].sentdate).c_str(), core::rect<s32>(475, 55, 0, 0), video::SColor(255, 255, 255, 255));

				break;
			} //end if
		} //end for loop

		TASWindow = XBOATREADNEWMENU;
		TASCurrentMenuWindow = XBOATMENU;
		return XBOATREADNEWMENU;

	} //end READ NEW MESSAGE

	//READ OLD MESSAGE
	if ((mouse_position.X > 750) && (mouse_position.X < 980) && (mouse_position.Y  > 448) && (mouse_position.Y < 496)&&(oldmailcount>0)){
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		
		mymessagenumber = 0;  //set starting starting message number
		

		for (x = 0; x <= 1999; x++)
		{
			if (mymessages[x].markedread == 1)
			{
				mymessagenumber = x;
				core::stringw w_libdatatext = mymessages[mymessagenumber].xbmessage;
				textBox->setText(w_libdatatext.c_str());
				break;
			}
		}

		TASWindow = XBOATREADOLDMENU;
		TASCurrentMenuWindow = XBOATMENU;
		return XBOATREADOLDMENU;
		
	}//end READ OLD MESSAGE

	//return to MAIN XBOAT WINDOW MENU
	if ((mouse_position.X > 854) && (mouse_position.X < 1015) && (mouse_position.Y > 745) && (mouse_position.Y < 760)) 
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		if (textBox) textBox->remove(); //destroy textbox
		if (xboattextimage) xboattextimage->remove(); //remove background image
		TASWindow = XBOATMENU;
		TASCurrentMenuWindow = XBOATMENU;
		return XBOATMENU;
	}

	
	return XBOATREADMENU;	
}

int checkmouseboundsXboatReadNew(void)
{
	

	int txtcounter = 0;
	int x = 0; //dummy counter
	int yplacement = 220; //starting message line
	char tempfile[255]; //filename for message



	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();


	//check to see if selection is on the grid
	if (mouse_position.X<1) return XBOATMENU;
	if (mouse_position.Y<1) return XBOATMENU;


	//READ NEW MESSAGE
	if ((mouse_position.X > 747) && (mouse_position.X < 982) && (mouse_position.Y  > 374) && (mouse_position.Y < 410) && (ismessagewaiting>0) && (newmailcount>0))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		if (mymessages[mymessagenumber].markedread <0) mymessagenumber = 0; //rewind to beginning message

		while ((mymessages[mymessagenumber].markedread == 1) && (newmailcount>0))
		{
			mymessagenumber++;
			if (mymessages[mymessagenumber].markedread <0) mymessagenumber = 0; //rewind to beginning message
		} //end while
		if (newmailcount > 0)
		{
			core::stringw w_libdatatext = mymessages[mymessagenumber].xbmessage;
			textBox->setText(w_libdatatext.c_str());
			mymessages[mymessagenumber].markedread = 1; //mark as read
			newmailcount--;
			oldmailcount++;
		}
		if (newmailcount < 1)
		{
			newmailcount = 0;
			ismessagewaiting = 0;
		}

		Save_Mailbox();  //write mailbox to mailbox file

		TASWindow = XBOATREADNEWMENU;
		TASCurrentMenuWindow = XBOATMENU;
		return XBOATREADNEWMENU;
	} //end READ NEW MESSAGE

	//READ NEXT MESSAGE
	if ((mouse_position.X > 285) && (mouse_position.X < 374) && (mouse_position.Y  > 700) && (mouse_position.Y < 739) && (ismessagewaiting>0) && (newmailcount>0))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		mymessagenumber++;
		if (mymessages[mymessagenumber].markedread <0) mymessagenumber = 0; //rewind to beginning message

		while ((mymessages[mymessagenumber].markedread !=0) && (newmailcount>0))
		{
			mymessagenumber++;
			if (mymessagenumber > 1999) mymessagenumber = 0;
			if (mymessages[mymessagenumber].markedread <0) mymessagenumber = 0; //rewind to beginning message
		}

		if (mymessages[mymessagenumber].markedread == 0)
		{
			core::stringw w_libdatatext = mymessages[mymessagenumber].xbmessage;
			textBox->setText(w_libdatatext.c_str());
			mymessages[mymessagenumber].markedread = 1; //mark as read

			newmailcount--;
			oldmailcount++;
		}

		if (newmailcount < 1)
		{
			newmailcount = 0;
			ismessagewaiting = 0;
		}
		Save_Mailbox();  //write mailbox to mailbox file

		sprintf(awaitingmessage, "%i New Messages", newmailcount);
		//sprintf(mymessages[x].xbmessage, "\n"); //message
	}

	

	//return to MAIN XBOAT WINDOW MENU
	if ((mouse_position.X > 854) && (mouse_position.X < 1015) && (mouse_position.Y > 745) && (mouse_position.Y < 760)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
	
		
		if (newmailcount < 1)
		{
			newmailcount = 0;
			ismessagewaiting = 0;
		}
		if (textBox) textBox->remove(); //destroy textbox
		if (xboattextimage) xboattextimage->remove(); //remove background image
		
		TASWindow = XBOATMENU;
		TASCurrentMenuWindow = XBOATMENU;

		sprintf(awaitingmessage, "%i New Messages", newmailcount);

		Save_Mailbox();

		return XBOATMENU;
	}

	sprintf(awaitingmessage, "%i New Messages", newmailcount);
	return XBOATREADNEWMENU;

}

int checkmouseboundsXboatReadOld(void)
{
	

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();


	//check to see if selection is on the grid
	if (mouse_position.X<1) return XBOATMENU;
	if (mouse_position.Y<1) return XBOATMENU;



	//READ NEXT MESSAGE
	if ((mouse_position.X > 285) && (mouse_position.X < 374) && (mouse_position.Y  > 700) && (mouse_position.Y < 739) && (oldmailcount>0))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		mymessagenumber++;
		if (mymessagenumber>1999) mymessagenumber = 0;
		
		while (mymessages[mymessagenumber].markedread <1)
		{
			mymessagenumber++;
			if (mymessagenumber>1999) mymessagenumber = 0;
		}	
		core::stringw w_libdatatext = mymessages[mymessagenumber].xbmessage;
		textBox->setText(w_libdatatext.c_str());


	} //end read next

	//READ PREVIOUS MESSAGE
	if ((mouse_position.X >50) && (mouse_position.X <139) && (mouse_position.Y > 700) && (mouse_position.Y <739) && (oldmailcount>0))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		mymessagenumber--;
		if (mymessagenumber < 0) mymessagenumber = 1999; //set to end message
		
			while (mymessages[mymessagenumber].markedread<1)
			{
				mymessagenumber--;
				if (mymessagenumber < 0) mymessagenumber = 1999;
			}
		
		core::stringw w_libdatatext = mymessages[mymessagenumber].xbmessage;
		textBox->setText(w_libdatatext.c_str());

	} //end read previous

	//return to MAIN XBOAT WINDOW MENU
	if ((mouse_position.X >854) && (mouse_position.X <1015) && (mouse_position.Y >745) && (mouse_position.Y <760)) 
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		mymessagenumber = 0;

		if (textBox) textBox->remove(); //destroy textbox
		if (xboattextimage) xboattextimage->remove(); //remove background image
		sprintf(awaitingmessage, "\0");
		TASWindow = XBOATMENU;
		TASCurrentMenuWindow = XBOATMENU;
		sprintf(awaitingmessage, "%i New Messages", newmailcount);
		return XBOATMENU;
	}


	return XBOATREADOLDMENU;

}


void Clear_Mailbox(void)
{
	int x;
	//clear mailbox
	for (x = 0; x <2000; x++){
		sprintf(mymessages[x].xbmessageto, "\n");//message recipient TO: (TAS member number or other name)
		sprintf(mymessages[x].xbdestination, "\n");//message destination system or world
		sprintf(mymessages[x].sentdate, "\n"); //date when message was sent
		sprintf(mymessages[x].sendername, "\n"); //sender's name
		mymessages[x].sendermembernumber=0; //sender member number
		mymessages[x].markedread = -1; //initialize that the message has not been read
		memset(mymessages[x].xbmessage, 0, sizeof(mymessages[x].xbmessage)); //message	
	} //end of for loop

	ismessagewaiting = 0;  //flag for if the user has a new xboat message
	newmailcount = 0; //number of awaiting messages
	oldmailcount = 0; //number of read messages
	totalmailcount = 0; //number of both read and new mail
	mymessagenumber = 0; // current message number index
	oldmessagecounter=0;  //temp counter to adjust old messages

}//end clear_mailbox

void Load_Mailbox(void)
{
	char dummymark[80]; //used for itoa conversion
	int len; //string length
	char line[128] = "\0", modline[80] = "\0";
	int templines = 0;  //for clearing mailbox
	char tempname[81] = "\0", temppassword[81] = "\0";
	char tempfile[255]; //filename for message
	int messagetempindex = 0; 

	//check if member has xboat mail waiting

	if (uAccessLevel < 10)
	{
		sprintf(tempfile, "communications/messages/mailbox/%d.msg", MemberNumber);
	}
	else sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");

	fd = NULL;
	fd = fopen(tempfile, "r");
	if (fd){

		messagetempindex = -1;
		oldmailcount = 0;
		newmailcount = 0;
		totalmailcount = 0;

		while (!feof(fd))
		{
			
			messagetempindex++;

			if (messagetempindex > 1999) messagetempindex = 0;  //clear out old messages to make room for new


			if (fgets(mymessages[messagetempindex].xbmessageto, 80, fd))
			{//message recipient TO: (TAS member number or other name)
				len = 0;
				len = strlen(mymessages[messagetempindex].xbmessageto);
				if (len < 1) sprintf(mymessages[messagetempindex].xbmessageto, "\n");
				if (len < 1) break;
			}
			else 
			{
				sprintf(mymessages[messagetempindex].xbmessageto, "\n");
				break;
			}

			if (fgets(mymessages[messagetempindex].xbdestination, 80, fd))
			{//message destination system or world
				len = 0;
				len = strlen(mymessages[messagetempindex].xbdestination);
				if (len < 1) sprintf(mymessages[messagetempindex].xbdestination, "\n");
				if (len < 1) break;
			}
			else
			{
				sprintf(mymessages[messagetempindex].xbdestination, "\n");
				break;
			}


			if (fgets(mymessages[messagetempindex].sentdate, 80, fd))
			{//date when message was sent
				len = 0;
				len = strlen(mymessages[messagetempindex].sentdate);
				if (len < 1) sprintf(mymessages[messagetempindex].sentdate, "\n");
				if (len < 1) break;
			}
			else
			{
				sprintf(mymessages[messagetempindex].sentdate, "\n");
				break;
			}

			if (fgets(mymessages[messagetempindex].sendername, 80, fd))
			{//sender's name
				len = 0;
				len = strlen(mymessages[messagetempindex].sendername);
				if (len < 1) sprintf(mymessages[messagetempindex].sendername, "\n");
				if (len < 1) break;
			}
			else
			{
				sprintf(mymessages[messagetempindex].sendername, "\n");
				break;
			}

			sprintf(dummymark, "\0");
			if (fgets(dummymark, 80, fd))
			{
				mymessages[messagetempindex].sendermembernumber = atoi(dummymark); //sender member number
			}
			else
			{
				mymessages[messagetempindex].sendermembernumber = 0;
				break;
			}

			sprintf(dummymark, "\0");
			if (fgets(dummymark, 80, fd))
			{
				mymessages[messagetempindex].markedread = atoi(dummymark); //0 if read 1 if not read
			}
			else
			{
				mymessages[messagetempindex].markedread = -1;
				break;
			}
			sprintf(mymessages[messagetempindex].xbmessage, "\n");  //clear message buffer

			//load message body
			sprintf(modline, " ");
			len = 0;
			while (!(strstr(modline, "~~CUT~~")) && (len < 5000) && !feof(fd))
			{
				if (fgets(modline, 80, fd))
				{
					if (!(strstr(modline, "~~CUT~~")))
					{
						len = strlen(mymessages[messagetempindex].xbmessage);
						sprintf(mymessages[messagetempindex].xbmessage, "%s%s", mymessages[messagetempindex].xbmessage, modline);
					}
				}
				/*else
				{
					sprintf(mymessages[messagetempindex].xbmessage, "\n");  //clear message buffer
					break;
				}	*/	
			}

			len = strlen(mymessages[messagetempindex].xbmessage);
			mymessages[messagetempindex].xbmessage[len + 1] = '\0';

			if (mymessages[messagetempindex].markedread == 0)  //0=has not been read yet
			{
				ismessagewaiting = 1; //A message is waiting
				newmailcount++; //increment the number of unread messages
			}
			if (mymessages[messagetempindex].markedread == 1)
			{
				oldmailcount++;
			}

			totalmailcount=newmailcount+oldmailcount;

			
		} //end while loop
		fclose(fd);
	} //end if fd
	else
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load %s\n", tempfile);
		fclose(ERR);
		messagetempindex = 0;
		oldmailcount = 0;
		newmailcount = 0;
		ismessagewaiting = 0;
		totalmailcount = 0;
	
	} // end else

}

void Save_Mailbox(void)

{
	char tempfile[255]; //filename for message
	int messagetempindex = 0; 

	//check if member has xboat mail waiting

	if (uAccessLevel < 10)
	{
		sprintf(tempfile, "communications/messages/mailbox/%d.msg", MemberNumber);
	}
	else sprintf(tempfile, "communications/messages/mailbox/GENERIC.msg");


	fd = fopen(tempfile, "w");

	if (fd)
	{

		messagetempindex = 0;

		while (messagetempindex < 2000)
		{
			if (mymessages[messagetempindex].markedread >= 0)
			{
				//write each message to mailbox file
				fprintf(fd, "%s", mymessages[messagetempindex].xbmessageto);  //name or member number for send-to
				fprintf(fd, "%s", mymessages[messagetempindex].xbdestination);  //name of where the message is going
				fprintf(fd, "%s", mymessages[messagetempindex].sentdate);  //date for sent message
				fprintf(fd, "%s", mymessages[messagetempindex].sendername);  //name of message sender
				fprintf(fd, "%d\n", mymessages[messagetempindex].sendermembernumber);  //TAS member number of sender
				fprintf(fd, "%d\n", mymessages[messagetempindex].markedread);  //flag for if message was read
				fprintf(fd, "%s", mymessages[messagetempindex].xbmessage);  //body of message
				fprintf(fd, "~~CUT~~\n");
			} //end if markedread>=0
			messagetempindex++;
		}
		fclose(fd);
	}
	else
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not open file pointer to write to %s\n", tempfile);
		fclose(ERR);
		messagetempindex = 0;
		oldmailcount = 0;
		newmailcount = 0;
		ismessagewaiting = 0;
		totalmailcount = 0;
	}


}


