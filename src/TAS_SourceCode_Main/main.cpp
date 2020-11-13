/*
Traveller's Aid Society Access Terminal

by Perry Horner 2001-
Version 3.0 2016

The Traveller game in all forms is owned by Far Future Enterprises.
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


The bulk of the code is by Perry Horner (perry1@liberated-technologies.com)


>>Exerpt from original xssv code:
Permission to use, copy, and modify this software is granted, provided
that this copyright appears in all copies and that both this copyright
and permission notice appear in all supporting documentation, and that
the name of Mark F. Cook and/or Hewlett-Packard not be used in advertising
without specific, writen prior permission.  Neither Mark F. Cook or
Hewlett-Packard make any representations about the suitibility of this
software for any purpose.  It is provided "as is" without express or
implied warranty."

>>This application uses the irrlicht 3d engine


*/

#include <irrlicht.h>
//#include "IChoiceScreen.h" //include the video resolution choice screen
#include <IrrlichtDevice.h>
#include <IGUIEditBox.h>

// INCLUDES /////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <wchar.h>

#include "CGUITextBox.h"
#include "CGUITextBox.cpp"

/*
In the Irrlicht Engine, everything can be found in the namespace 'irr'. So if
you want to use a class of the engine, you have to write irr:: before the name
of the class. For example to use the IrrlichtDevice write: irr::IrrlichtDevice.
To get rid of the irr:: in front of the name of every class, we tell the
compiler that we use that namespace from now on, and we will not have to write
irr:: anymore.
*/
using namespace irr;

/*
There are 5 sub namespaces in the Irrlicht Engine. Take a look at them, you can
read a detailed description of them in the documentation by clicking on the top
menu item 'Namespace List' or by using this link:
http://irrlicht.sourceforge.net/docu/namespaces.html
Like the irr namespace, we do not want these 5 sub namespaces now, to keep this
example simple. Hence, we tell the compiler again that we do not want always to
write their names.
*/
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/*
To be able to use the Irrlicht.DLL file, we need to link with the Irrlicht.lib.
We could set this option in the project settings, but to make it easy, we use a
pragma comment lib for VisualStudio. On Windows platforms, we have to get rid
of the console window, which pops up when starting a program with main(). This
is done by the second pragma. We could also use the WinMain method, though
losing platform independence then.
*/
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
// hides the console window
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#if defined(__APPLE__) || defined(macintosh) || defined(OSX)
#undef main
#endif

#if defined(_WIN32)
//#include <WinBase.h>
#include <Windows.h>
#pragma comment( lib, "Winmm.lib" ) 
#endif

//For DPI aware Windows OS (like surface pro, turn it off) to fix full screen scaling issue
typedef bool (WINAPI *SetProcessDPIAwareType)();
SetProcessDPIAwareType SetProcessDPIAwareFunc;

#include "globals.h"  //all global variables
#include "tas.h"  //main application
#include "planetorbit.h"
#include "planet.h"
#include "navlib.h"
#include "cleanup.h"
#include "initialization.h"
#include "output.h"
#include "news.h"
#include "libdata.h"
#include "accounts.h"
#include "tasXML.h"
#include "classifieds.h"
#include "xboat.h"



//// MODULE SOURCE CODE ////

#include "planetorbit.c"
#include "planet.c"
#include "navlib.c"
#include "cleanup.c"
#include "initialization.c"
#include "output.c"
#include "news.c"
#include "libdata.c"
#include "accounts.c"
#include "tasXML.c"
#include "classifieds.c"
#include "xboat.c"

//files for screen resolution choice
#include "CIChoiceScrData.cpp"
#include "CIChoiceScrEvent.cpp"
#include "CIChoiceScrXML.cpp"


// FUNCTIONS ////////////////////////////////////////////////////////
//Delay
void  Delay(u32 msec)
{
	u32 time = device->getTimer()->getRealTime();
	do {
	} 
	while (device->getTimer()->getRealTime()<time + msec);
}




//Event function for identifying system messages for screen,keyboard and mouse activity
void TasEventHandler()
{
	int t = 0;
	int temp_wcount = 0, comparehex=0;
	/*EMOUSE_INPUT_EVENT
00075     {
00077         EMIE_LMOUSE_PRESSED_DOWN = 0,
00078 
00080         EMIE_RMOUSE_PRESSED_DOWN,
00081 
00083         EMIE_MMOUSE_PRESSED_DOWN,
00084 
00086         EMIE_LMOUSE_LEFT_UP,
00087 
00089         EMIE_RMOUSE_LEFT_UP,
00090 
00092         EMIE_MMOUSE_LEFT_UP,
00093 
00095         EMIE_MOUSE_MOVED,
00096 
00099         EMIE_MOUSE_WHEEL,
00100 
00103         EMIE_LMOUSE_DOUBLE_CLICK,
00104 
00107         EMIE_RMOUSE_DOUBLE_CLICK,
00108 
00111         EMIE_MMOUSE_DOUBLE_CLICK,
00112 
00115         EMIE_LMOUSE_TRIPLE_CLICK,
00116 
00119         EMIE_RMOUSE_TRIPLE_CLICK,
00120 
00123         EMIE_MMOUSE_TRIPLE_CLICK,
00124 
00126         EMIE_COUNT
*/



	//go back a screen level if the escape key is pressed


	if (receiver.IsKeyDown(irr::KEY_ESCAPE)==true)
	{  
			if (TASWindow == LOGINWINDOW) {
				UpdateTheScreen = 1;
				TASWindow = TASEXITWINDOW;
			}
			else if (TASWindow == TASEXITWINDOW){
				UpdateTheScreen = 1;
				return;
			}
	} //end if keyboard input
	
	
	if (receiver.IsKeyDown(irr::KEY_RETURN)==true)
	{

	} //end if (receiver.IsKeyDown(irr::KEY_RETURN)==true)

	/*
	//check for marking hex location
	if ((receiver.IsKeyDown(irr::KEY_KEY_M) == true) && (TASWindow == SUBSECTORWINDOW))
	{
		comparehex = 0;
		for (temp_wcount = 0; temp_wcount <= w_cnt; temp_wcount++){

			comparehex = atoi(sec_world[temp_wcount].hex);
			if (currentworld == comparehex)
			{
				hexmarkerx = (sec_world[temp_wcount].xmousepoint) - 21;
				hexmarkery = (sec_world[temp_wcount].ymousepoint)-18;
				MarkerHex = atoi(sec_world[temp_wcount].hex);
				MarkerSectorNumber = secloct;
				MarkerFlag = 1;
			} //end ifn currentworld=comparehex
		} //end for
	} //end if M pressed
	*/
	if (TASCurrentMenuWindow == LIBDATAWINDOW)
	{
		if (editboxIDValue)
		{
			device->getGUIEnvironment()->setFocus(NULL);
			w_libdatasearchword = LibDataSearchBox->getText();
			editboxIDValue->remove();
			editboxIDValue = NULL;
			searchmenuitemavailable = 0;
			guienv->removeFocus(LibDataSearchBox);
			searchentered = 1;
			UpdateTheScreen = 1;

		} //end if editboxIDValue
	} //end if LIBDATAWINDOW

	if (TASWindow == LOANWINDOW)
	{

		if (editboxIDValue)
		{


				LoanAmounttext = LoanInputBox->getText();
				editboxIDValue->remove();

				editboxIDValue = NULL;
				guienv->setFocus(NULL);


				sprintf(loanrequest, "%ls", LoanAmounttext);
				if ((strlen(loanrequest)<1)||((int)atoi(loanrequest)<1)) {
					UpdateTheScreen = 1;
					loanborrow = 0; //flag - 0 no borrow, 1 borrow amount submitted
					TASWindow = LOANWINDOW;
				}
				else
				{
					loanborrow = 1; //valid amount entered
					

				}
				//requested amount too high... reset
				if (atoi(loanrequest)>1000000000){
					sprintf(loanrequest, "\0");
					loanborrow = 0;
				}

				if (loanborrow == 1){

					//calculate various interest and loan rates
					if (accountbalance < (int)(.1*atoi(loanrequest))) ratelevel = 0;
					if (accountbalance >= (int)(.1*atoi(loanrequest))) ratelevel = 10;
					if (accountbalance >= (int)(.2*atoi(loanrequest))) ratelevel = 20;
					if (accountbalance >= (int)(.3*atoi(loanrequest))) ratelevel = 30;
					if (accountbalance >= (int)(.5*atoi(loanrequest))) ratelevel = 50;
					if (accountbalance >= (int)(.7*atoi(loanrequest))) ratelevel = 70;
					if (accountbalance >= (int)(.8*atoi(loanrequest))) ratelevel = 80;


					
					if (ratelevel == 0){
						interestgenerated1 = (float)(b1interestoffset0 + 19.1);
						interestgenerated2 = (float)(b2interestoffset0 + 19.1);
						interestgenerated3 = (float)(b3interestoffset0 + 19.1);
						interestgenerated4 = (float)(b4interestoffset0 + 19.1);
					} // rate 0

					if (ratelevel == 10){
						interestgenerated1 = (float)(b1interestoffset10 + 11.1);
						interestgenerated2 = (float)(b2interestoffset10 + 11.1);
						interestgenerated3 = (float)(b3interestoffset10 + 11.1);
						interestgenerated4 = (float)(b4interestoffset10 + 11.1);
					} // rate 10
					if (ratelevel == 20){
						interestgenerated1 = (float)(b1interestoffset20 + 6.2);
						interestgenerated2 = (float)(b2interestoffset20 + 6.2);
						interestgenerated3 = (float)(b3interestoffset20 + 6.2);
						interestgenerated4 = (float)(b4interestoffset20 + 6.2);
					} // rate 20
					if (ratelevel == 30){
						interestgenerated1 = (float)(b1interestoffset30 + 3.3);
						interestgenerated2 = (float)(b2interestoffset30 + 3.3);
						interestgenerated3 = (float)(b3interestoffset30 + 3.3);
						interestgenerated4 = (float)(b4interestoffset30 + 3.3);
					} // rate 30
					if (ratelevel == 50){
						interestgenerated1 = (float)(b1interestoffset50 + 1.8);
						interestgenerated2 = (float)(b2interestoffset50 + 1.8);
						interestgenerated3 = (float)(b3interestoffset50 + 1.8);
						interestgenerated4 = (float)(b4interestoffset50 + 1.8);
					} // rate 50
					if (ratelevel == 70){
						interestgenerated1 = (float)(b1interestoffset70 + .9);
						interestgenerated2 = (float)(b2interestoffset70 + .9);
						interestgenerated3 = (float)(b3interestoffset70 + .9);
						interestgenerated4 = (float)(b4interestoffset70 + .9);
					} // rate 70
					if (ratelevel == 80){
						interestgenerated1 = (float)(b1interestoffset70 + .2);
						interestgenerated2 = (float)(b2interestoffset70 + .2);
						interestgenerated3 = (float)(b3interestoffset70 + .2);
						interestgenerated4 = (float)(b4interestoffset70 + .2);
					} // rate 80
				} //end if loanborrow==1

			device->getGUIEnvironment()->setFocus(NULL);
			UpdateTheScreen = 1;
			loanboxcreated = 0;
		} //end if editboxIDValue

	} //end if LOANWINDOW
	

	if (TASWindow == LOGINWINDOW){
			// Clear the edit box.
			if (LoginUnameFLAG == 0){

				if (editboxIDValue)
				{
					backsurf = LoginBackground;
					device->getGUIEnvironment()->setFocus(NULL);
					LoginUnametext = LoginUname->getText();
					editboxIDValue->remove();
					editboxIDValue = NULL;
					guienv->setFocus(NULL);
					LoginUnameFLAG = 1;
					LoginPass = NULL;
					LoginPass = guienv->addEditBox(L"", rect<s32>(440, 410, 660, 430), true, 0, 101);
					LoginPassFLAG = 0;
					LoginPass->setMax(80);
					LoginPass->setAutoScroll(false);
					LoginPass->setMultiLine(false);
					LoginPass->setWordWrap(false);
					LoginPass->setOverrideFont(Courier10Red);
					LoginPass->setOverrideColor(video::SColor(255, 255, 0, 0));
					LoginPass->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);
					guienv->setFocus(LoginPass);

					guienv->drawAll();
					UpdateTheScreen = 1;
				} //end if editboxIDValue
			} //end if LoginUnameFLAG=0


			else  if (LoginPassFLAG == 0){
				if (editboxIDValue)
				{
					LoginPasstext = LoginPass->getText();
					editboxIDValue->remove();
					editboxIDValue = NULL;
					guienv->setFocus(NULL);
					LoginPassFLAG = 1;
				} //end if editboxIDValue
			}//end if LoginUnameFLAG
		}//end if TASWindow == LOGINWINDOW



	
	if (receiver.MouseState.LeftButtonDown == true)
	{

		//*****LOGIN WINDOW***********
		if (TASWindow == LOGINWINDOW) {
			TASWindow = checkmouseboundslogin();
			subsectorhex = 0;
			UpdateTheScreen = 1;
			receiver.MouseState.LeftButtonDown = false;
		}

		//*****MAIN MENU WINDOW*******
		else if (TASWindow == MAINMENUWINDOW) {

			TASWindow = checkmouseboundsmain();
			subsectorhex = 0;
			UpdateTheScreen = 1;
			receiver.MouseState.LeftButtonDown = false;
		} // end if MAINMENU window

		//*****NAVIGATION MENU WINDOW*****
		else if (TASCurrentMenuWindow == NAVIGATIONWINDOW)
		{
			if (TASWindow == GALAXYWINDOW) 
			{
				sectorfile = checkmouseboundsgalaxy();
				if (sectorfile >-1)
				{
					t = readsector(sectorfile);
					if (t == 0){
						TASWindow = SECTORWINDOW;
						backsurf = secback;
						subsecfile = NULL;
						subsectorhex = 0;
					} //end if t==0
					subsectorhex = 0;
					receiver.MouseState.LeftButtonDown = false;
				} //end if sectorfile !=NULL
				else if (TASWindow == MAINMENUWINDOW)
				{
					receiver.MouseState.LeftButtonDown = false;
					ClearNAV();
					RandomAdvertisement();
				} //end if TASWindow becomes MAINMENUWINDOW
				UpdateTheScreen = 1;
			}

			else if (TASWindow == SECTORWINDOW) {
				subsecfile = checkmouseboundssector();
				
				if (subsecfile != NULL) {
				TASWindow = SUBSECTORWINDOW;
				readsubsector();
				subsectorhex = 0;
				}
				
				UpdateTheScreen = 1;
				receiver.MouseState.LeftButtonDown = false;
			}

			else if (TASWindow == SECTORFLEETWINDOW) {
				subsectorhex = checkmouseboundsfleet();
				if (subsectorhex == RETURNSECMENU)
				{
					subsectorhex = 0;
					TASWindow = SECTORWINDOW;
				}
				UpdateTheScreen = 1;
				receiver.MouseState.LeftButtonDown = false;
			}
			
			else if (TASWindow == SECTORLIBDATAWINDOW) 
			{
				TASWindow = checkmouseboundssectorlibdata();
				UpdateTheScreen = 1;
				receiver.MouseState.LeftButtonDown = false;
			}
			
			else if (TASWindow == SUBSECTORWINDOW)
			{
				oldsubsectorhex = subsectorhex;
				subsectorhex = checkmouseboundssubsec();
				receiver.MouseState.LeftButtonDown = false;
				if (subsectorhex == SAVESUBSECBMP)
				{
					subsectorhex = currentworld;
				}
				if (subsectorhex == RETURNSECMENU)
				{
					subsectorhex = 0;
					TASWindow = SECTORWINDOW;
				}
				if (subsectorhex == PLANETWINDOW)
				{
					subsectorhex = oldsubsectorhex;
					TASWindow = PLANETWINDOW;
				}
				if (subsectorhex == SUBSECTORWINDOW)
				{
					subsectorhex = 0;
					TASWindow = SUBSECTORWINDOW;
				}
				if (subsectorhex == SUBSECTORLIBDATAWINDOW)
				{
					subsectorhex = oldsubsectorhex;
					TASWindow = SUBSECTORLIBDATAWINDOW;
				}
				UpdateTheScreen = 1;
			}
			else if (TASWindow == SUBSECTORLIBDATAWINDOW) 
			{
				TASWindow = checkmouseboundssubsectorlibdata();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
			else if (TASWindow == SUBSECLIBDATAIMAGEWINDOW)
			{
				TASWindow = checkmouseboundssubseclibdataimage();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
			else if (TASWindow == PLANETWINDOW) 
			{
				TASWindow = checkmouseboundsplanet();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
			
		} //end if TASCurrentMenuWindow==NAVIGATIONWINDOW


		//*****NEWS WINDOW*****
		else if (TASCurrentMenuWindow == NEWSWINDOW)
		{
			if (TASWindow == NEWSSERVICEWINDOW) 
			{
				TASWindow = checkmouseboundsnews();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
				if (TASWindow == MAINMENUWINDOW)
				{
					ClearNEWS();
					
					RandomAdvertisement();
				}

			}
			else if (TASWindow == ARCHIVENEWSWINDOW)
			{
				TASWindow = checkmouseboundsnewsarchive();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
			else if (TASWindow == RUMORSNEWSWINDOW)
			{
				TASWindow = checkmouseboundsnewsrumor();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}

		UpdateTheScreen = 1;
		} //end if TASCurrentMenuWindow=NEWSWINDOW
		
		//*****LIBRARY DATA WINDOW*****
		else if (TASCurrentMenuWindow == LIBDATAWINDOW)
		{
			if (TASWindow == LIBDATASERVICEWINDOW) 
			{
				TASWindow = checkmouseboundslibdata();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
				if (TASWindow == MAINMENUWINDOW)
				{
					ClearLIBDATA();
					
					RandomAdvertisement();
				}
			}
			else if (TASWindow == LIBDATASEARCHWINDOW)
			{
					TASWindow = checkmouseboundslibdata();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
			else if (TASWindow == LIBDATAIMAGEWINDOW)
			{
				TASWindow = checkmouseboundslibdataimage();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}

			
		} //end if TASCurrentMenuWindow=LIBDATAWINDOW
		

		//*****ACCOUNT WINDOW*****
		else if (TASCurrentMenuWindow == ACCOUNTSERVICEWINDOW)
		{
			if (TASWindow == ACCOUNTSERVICEWINDOW)
			{
				TASWindow = checkmouseboundsAccounts();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
					if (TASWindow == MAINMENUWINDOW)
					{
						ClearAccounts();
						if(loanrequest) free(loanrequest);
						RandomAdvertisement();
					}
			}
			else if (TASWindow == BANKINGWINDOW)
			{
				TASWindow = checkmouseboundsBank();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
			else if (TASWindow == LOANWINDOW)
			{

				TASWindow = checkmouseboundsLoan();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
			else if (TASWindow == PERSONALWINDOW)
			{
				TASWindow = checkmouseboundsPersonal();
				receiver.MouseState.LeftButtonDown = false;
				UpdateTheScreen = 1;
			}
		UpdateTheScreen = 1;
		} //end if TASCurrentMenuWindow=ACCOUNTSERVICEWINDOW
	
		//*****CLASSIFIEDS WINDOW*****
		else if (TASCurrentMenuWindow == CLASSIFIEDMENU){
		if (TASWindow == CLASSIFIEDMENU) {

		TASWindow = checkmouseboundsClassifieds();
		receiver.MouseState.LeftButtonDown = false;

		UpdateTheScreen = 1;
		if (TASWindow == MAINMENUWINDOW){
		ClearCLASSIFIEDS();
		free(libdatatext);
		RandomAdvertisement();
		}
		}
		else if (TASWindow == FORSALEWINDOW){
		TASWindow = checkmouseboundsForSale();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == FORSALESPACECRAFTWINDOW){
		TASWindow = checkmouseboundsFSSpacecraft();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == FORSALEVEHICLESWINDOW){
		TASWindow = checkmouseboundsFSVehicles();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == FORSALEITEMSWINDOW){
		TASWindow = checkmouseboundsFSItems();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == MISSIONSWINDOW){
		TASWindow = checkmouseboundsMissions();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == HELPWANTEDMENU){
		TASWindow = checkmouseboundsJobs();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		UpdateTheScreen = 1;
		} //end if TASCurrentMenuWindow=CLASSIFIEDMENU
		
		//*****COMMUNICATIONS XBOAT WINDOW*****
		else if (TASCurrentMenuWindow == XBOATMENU){
		if (TASWindow == XBOATMENU){
		TASWindow = checkmouseboundsXboatMenu();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		if (TASWindow == MAINMENUWINDOW){
		ClearXboat();
		RandomAdvertisement();
		}
		}
		else if (TASWindow == XBOATREADMENU){
		TASWindow = checkmouseboundsXboatRead();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == XBOATSENDMENU){
		TASWindow = checkmouseboundsXboatSend();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == XBOATREADNEWMENU){
		TASWindow = checkmouseboundsXboatReadNew();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		else if (TASWindow == XBOATREADOLDMENU){
		TASWindow = checkmouseboundsXboatReadOld();
		receiver.MouseState.LeftButtonDown = false;
		UpdateTheScreen = 1;
		}
		UpdateTheScreen = 1;

		} //end if TASCurrentMenuWindow=XBOAT
		
	receiver.MouseState.LeftButtonDown = false;
	} //end if current mouse state
	
}


/* Read ini file for era and date settings*/


//***************Check for main window submenu selection*************
int checkmouseboundslogin()
{
	int xlookup = 0, ylookup = 0, templevel = 0;
	int mselection = 0;
	int inputoffset = 0;
	char tempname[81] = "\0"; //temp username
	char temppassword[81] = "\0"; //temp user password

	sprintf(tempname, "%s", "");
	sprintf(temppassword, "%s", "");

	fd = NULL;


	inputoffset = 1; //default for Windows
#if defined(__APPLE__) || defined(macintosh)
	inputoffset = 2;
#endif
#if defined(unix) || defined(__unix__) || defined(__linux__)
	inputoffset = 2;
#endif
#if defined(_WIN32_WCE) || defined(WIN32) || defined(_WIN32)
	inputoffset = 1;
#endif

	mselection = LOGINWINDOW;
	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();


	if ((mouse_position.X>400) && (mouse_position.X<630) && (mouse_position.Y>450) && (mouse_position.Y<510) && (LoginPassFLAG == 1) && (LoginUnameFLAG == 1))
	{


		// Submit Button selected for main menu
		//count the number of member records

		
		for (TASmembercount = 1; TASmembercount<200; TASmembercount++)
		{

			//verify
			sprintf(uName, "%ls", LoginUnametext.c_str()); //convert from wide
			sprintf(uPass, "%ls", LoginPasstext.c_str()); //convert from wide

			//convert username and password to upper case for validation
			uppercase(uName);
			uppercase(TASMember[TASmembercount].uName);
			uppercase(uPass);
			uppercase(TASMember[TASmembercount].uPass);

			if ((!strcmp(uName, TASMember[TASmembercount].uName)) && (!strcmp(uPass, TASMember[TASmembercount].uPass) && 
				(strlen(uName)>1) && (strlen(uPass) > 1) && (TASMember[TASmembercount].TASMemberHidden == 0)))
			{
				//SUCCESS
				LoggedOn = 1;
				MemberNumber = TASMember[TASmembercount].MemberNumber;
				uAccessLevel = TASMember[MemberNumber].uAccessLevel;
				MarkerSectorNumber = TASMember[MemberNumber].MarkerSectorNumber;
				sprintf(MarkerSubSector, "%s", TASMember[MemberNumber].MarkerSubSector);
				MarkerHex = TASMember[MemberNumber].MarkerHex;
				hexmarkerx = TASMember[MemberNumber].MarkerX;
				hexmarkery = TASMember[MemberNumber].MarkerY;
				if (MarkerSectorNumber > -1) MarkerFlag = 1;

				//Mix_PlayChannel(-1, SoundWelcome, 0); //play welcome message
				//PlaySoundA("sounds/welcome.wav", NULL, SND_ASYNC); //play welcome message
				if ((strlen(uPass) > 1) && (LoggedOn == 1)) mselection = MAINMENUWINDOW;
				if ((strlen(uPass) > 1) && (LoggedOn == 1)) TASCurrentMenuWindow = MAINMENUWINDOW;

				//check for and set news of the day
				CheckNewsOfDay();

				//load bank account
				sprintf(tempname, "accounts/bank/%d.txt", MemberNumber);
				fd = fopen(tempname, "r");
				if (!fd){
					fd = fopen(tempname, "w");
					fprintf(fd, "0\n");
					accountbalance = 0;
					sprintf(characcountbalance, "%d", accountbalance);
					fclose(fd);
				}
				else{
					fgets(characcountbalance, sizeof(characcountbalance), fd);

					accountbalance = atoi(characcountbalance);
					characcountbalance[strlen(characcountbalance) - 1] = '\0';

				}
				fclose(fd);

				//clear mailbox
				Clear_Mailbox();

				//Read mailbox
				Load_Mailbox();

				//set seed random classifieds job ads
				//JobSeed = (unsigned)time(NULL);
				JobSeed = TASDay + TASYear;

				//RANDOMIZE using time seed
				//srand((unsigned)time(NULL));
				

				//calculate interest offsets and rates for each lender
				//bank 1
				b1interestoffset0 = (float)((rand() % (191) + 1)*.1);
				b1interestoffset10 = (float)((rand() % (111) + 1)*.1);
				b1interestoffset20 = (float)((rand() % (62) + 1)*.1);
				b1interestoffset30 = (float)((rand() % (33) + 1)*.1);
				b1interestoffset50 = (float)((rand() % (18) + 1)*.1);
				b1interestoffset70 = (float)((rand() % (9) + 1)*.1);
				b1interestoffset80 = (float)((rand() % (2) + 1)*.1);
				//bank 2
				b2interestoffset0 = (float)((rand() % (191) + 1)*.1);
				b2interestoffset10 = (float)((rand() % (111) + 1)*.1);
				b2interestoffset20 = (float)((rand() % (62) + 1)*.1);
				b2interestoffset30 = (float)((rand() % (33) + 1)*.1);
				b2interestoffset50 = (float)((rand() % (18) + 1)*.1);
				b2interestoffset70 = (float)((rand() % (9) + 1)*.1);
				b2interestoffset80 = (float)((rand() % (2) + 1)*.1);
				//bank 3
				b3interestoffset0 = (float)((rand() % (191) + 1)*.1);
				b3interestoffset10 = (float)((rand() % (111) + 1)*.1);
				b3interestoffset20 = (float)((rand() % (62) + 1)*.1);
				b3interestoffset30 = (float)((rand() % (33) + 1)*.1);
				b3interestoffset50 = (float)((rand() % (18) + 1)*.1);
				b3interestoffset70 = (float)((rand() % (9) + 1)*.1);
				b3interestoffset80 = (float)((rand() % (2) + 1)*.1);
				//bank 4
				b4interestoffset0 = (float)((rand() % (191) + 1)*.1);
				b4interestoffset10 = (float)((rand() % (111) + 1)*.1);
				b4interestoffset20 = (float)((rand() % (62) + 1)*.1);
				b4interestoffset30 = (float)((rand() % (33) + 1)*.1);
				b4interestoffset50 = (float)((rand() % (18) + 1)*.1);
				b4interestoffset70 = (float)((rand() % (9) + 1)*.1);
				b4interestoffset80 = (float)((rand() % (2) + 1)*.1);

				//seed for mission tickets
				//MissionSeed = rand() % 100 + 1;
				MissionSeed = TASDay + TASYear;
				NumberofMercTickets = rand() % 6 + 1;
				MercTicketsRemaining = NumberofMercTickets;

				//initialize sector allegiance codes
				InitAllianceCodes();

				backsurf = MainMenuBackground;

				device->getGUIEnvironment()->setFocus(NULL);
				driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

				if (LoggedOn == 1) return mselection; //success - return 
			} //END IF LOGIN SUCCESS
			
		} //end while for loading account file

		
		// FAILURE
		backsurf = MainMenuBackground;

		device->getGUIEnvironment()->setFocus(NULL);
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		sprintf(uName, ""); //clear out user
		sprintf(uPass, ""); //clear out password
		LoggedOn = 0;
		LoginUnameFLAG = 0; //is the username set 0=no 1=yes
		LoginPassFLAG = 0;
		LoginUnametext = L"";
		LoginPasstext = L"";
		LoggedOn = 0;
		subsectorhex = 0;
		UpdateTheScreen = 1;
		LoginPass = NULL;
		mselection = LOGINWINDOW;
		TASCurrentMenuWindow = LOGINWINDOW;
	} //end if SUBMIT button selected
	
	return mselection;
}

//***************Check for main window submenu selection*************
int checkmouseboundsmain()
{
	int xlookup = 0, ylookup = 0;
	int mselection = 0;
	int val = 0;
/*


	//breaking news location
	breaknews.x = 66;
	breaknews.y = 600;
	breaknews.w = 253;
	breaknews.h = 83;
	*/
	mselection = MAINMENUWINDOW;

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	//Navigation Library GALAXYWINDOW selected
	if ((mouse_position.X>69) && (mouse_position.X<83) && (mouse_position.Y>340) && (mouse_position.Y<358) && (uAccessLevel >= ALNAVLIB)) 
	{
			//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		
			mselection = GALAXYWINDOW;
			TASCurrentMenuWindow = NAVIGATIONWINDOW;

			driver->endScene();
			driver->beginScene(true, true, SColor(0, 0, 0, 0));

			InitKnownSpace();  //display galaxy map
			DisplayKnownSpaceLocations(); //display all known locations
		} //End NAVIGATIONWINDOW

	else
		if ((mouse_position.X>73) && (mouse_position.X<88) && (mouse_position.Y>399) && (mouse_position.Y<411) && (uAccessLevel >= ALNEWS)) 
		{
			//News Service NEWSSERVICEWINDOW selected
			//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

			mselection = NEWSSERVICEWINDOW;
			TASCurrentMenuWindow = NEWSWINDOW;
			backsurf = NewsMenuBackground;
			driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
			libdatatextimage = guienv->addImage((libdatablank), core::position2d<s32>(0, 0)); //678x701 image or use another image
			libdatatextimage->setAlignment(EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE);
			libdatatextimage->setRelativePosition(core::rect<s32>(10, 10, 688, 711));

			textBox = new CGUITextBox(Optima18Black, L"", guienv, irr::core::rect<irr::s32>(35, 35, 640, 615), libdatatextimage, -1);
			textBox->setScrollModeLines(true);
			textBox->setScrollbarRight(true);
			textBox->setVisible(true);
			istherenews = LoadNews(TASYear, CURRENTNEWS);
			
		}//end NEWSSERVICE
		else
			if ((mouse_position.X>69) && (mouse_position.X<88) && (mouse_position.Y>282) && (mouse_position.Y<302) && (uAccessLevel >= ALLIBDATA))
			{
				//Library Data selected
				//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

				mselection = LIBDATASERVICEWINDOW;
				TASCurrentMenuWindow = LIBDATAWINDOW;
				backsurf = libdatabmp;
				driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
				libdatatextimage = guienv->addImage((libdatablank), core::position2d<s32>(0, 0)); //678x701 image or use another image
				libdatatextimage->setAlignment(EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE);
				libdatatextimage->setRelativePosition(core::rect<s32>(10, 10, 688, 711));

				//textBox = new CGUITextBox(Optima18Black, L"", guienv, irr::core::rect<irr::s32>(35, 35, 640, 615), libdatatextimage, -1);
				textBox = new CGUITextBox(Optima18Black, L"", guienv, irr::core::rect<irr::s32>(52, 20, 635, 535), libdatatextimage, -1);
				textBox->setScrollModeLines(true);
				textBox->setScrollbarRight(true);
				textBox->setVisible(true);

				InitLibDataString(); //set instruction string

			}//end LIBRARYDATA

		else
			if ((mouse_position.X>69) && (mouse_position.X<83) && (mouse_position.Y>148) && (mouse_position.Y<167) && (uAccessLevel >= ALACCNT)) 
			{
				//Account Service ACCOUNTSERVICEWINDOW selected
				//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
				mselection = ACCOUNTSERVICEWINDOW;
				TASCurrentMenuWindow = ACCOUNTSERVICEWINDOW;

				backsurf = accountsvcs;
				driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
			}//end ACCOUNTSERVICE

		else
			if ((mouse_position.X>69) && (mouse_position.X<89) && (mouse_position.Y>190) && (mouse_position.Y<212) && (uAccessLevel >= ALCLASS)) 
			{
				//CLASSIFIEDMENU selected
				//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

				mselection = CLASSIFIEDMENU;
				TASCurrentMenuWindow = CLASSIFIEDMENU;
					
			}//end CLASSIFIEDMENU
		else
			if ((mouse_position.X>69) && (mouse_position.X<90) && (mouse_position.Y>238) && (mouse_position.Y<260) && (uAccessLevel >= ALXBT))
			{
				//COMMUNICATIONS XBOAT selected
				//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
				sprintf(awaitingmessage, "%i New Messages\0", newmailcount);
				mselection = XBOATMENU;
				TASCurrentMenuWindow = XBOATMENU;
			
			}//end COMMUNICATIONS
		else
			if ((mouse_position.X>370) && (mouse_position.X<583) && (mouse_position.Y>610) && (mouse_position.Y<670))
			{
				//EXITWINDOW-logoff selected
				//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
				RandomAdvertisement();
				mselection = LOGINWINDOW;

				Save_Mailbox();


				sprintf(uName, ""); //clear out user
				sprintf(uPass, ""); //clear out password

				LoggedOn = 0;
				LoginUnameFLAG = 0; //is the username set 0=no 1=yes
				LoginPassFLAG = 0;
				LoginUnametext = L"";
				LoginPasstext = L"";
				LoggedOn = 0;
				TASWindow = LOGINWINDOW;
				TASCurrentMenuWindow = LOGINWINDOW;
				TASMember[MemberNumber].MarkerSectorNumber=MarkerSectorNumber;

				strcpy(TASMember[MemberNumber].MarkerSubSector, MarkerSubSector);

				TASMember[MemberNumber].MarkerHex=MarkerHex;
				TASMember[MemberNumber].MarkerX=hexmarkerx;
				TASMember[MemberNumber].MarkerY=hexmarkery;

				ismessagewaiting = 0; 
				PrinterOn = 0;

				WriteAccountFile();

				} //end LOGOFF

				
			else
				if ((mouse_position.X > 835) && (mouse_position.X < 950) && (mouse_position.Y>350) && (mouse_position.Y < 384) && (MSPaintAvail==0))
				{
					if (PrinterOn == 0)
					{
						PrinterOn = 1;
					}
					else PrinterOn = 0;

				}  //end toggle printing
				

	return mselection;	
}

int Updatescreenmainmenu(void)
{
	char tempmessage[80];

	driver->draw2DImage(Advertisement, core::position2d<s32>(775, 475), core::rect<s32>(0, 0, 200, 250), 0, video::SColor(255, 255, 255, 255), true); //display advertisement
	

	sprintf(currentdate, "%d-%d", TASYear, TASDay);

	//show current date
	Optima18White->draw(irr::core::stringw("Date:").c_str(), core::rect<s32>(400, 700, 0, 0), video::SColor(255, 255, 255, 255));
	Optima18White->draw(irr::core::stringw(currentdate).c_str(), core::rect<s32>(480, 700, 0, 0), video::SColor(255, 255, 255, 255));

	//display if news available for current date	
	if(newstoday==TRUE)
	{
		driver->draw2DImage(BreakingNews, core::position2d<s32>(66, 600), core::rect<s32>(0, 0, 253, 83), 0, video::SColor(255, 255, 255, 255), true); //headlines today
	}

	//display printer status button
	if (MSPaintAvail == 0)
	{
		if (PrinterOn < 1)
		{
			driver->draw2DImage(PrinterOffButton, core::position2d<s32>(835, 350), core::rect<s32>(0, 0, 114, 34), 0, video::SColor(255, 255, 255, 255), true); //printer off
		}
		if (PrinterOn > 0)
		{
			driver->draw2DImage(PrinterOnButton, core::position2d<s32>(835, 350), core::rect<s32>(0, 0, 114, 34), 0, video::SColor(255, 255, 255, 255), true); //printer on
		}
	}

	//display message is waiting
	if (ismessagewaiting >0)
	{
		sprintf(tempmessage, "%i X-Boat Messages Waiting\0", newmailcount);
		arial_24_yellow_blackout_bevel->draw(irr::core::stringw(tempmessage).c_str(), core::rect<s32>(275, 560, 0, 0), video::SColor(255, 255, 255, 0));
	}
	
	return 1;
}

int LoginScreen(void)
{
	
	
	if ((irr::core::stringw(LoginUnametext).size()<1) && (LoginUnameFLAG == 0)&&(backsurf != LoginBackground)){

			backsurf = LoginBackground;

			driver->draw2DImage(LoginBackground, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
			

			guienv->removeFocus(LoginUname);
			if (editboxIDValue)
			{
				editboxIDValue->remove();
				editboxIDValue = NULL;
			}

				LoginUname = guienv->addEditBox(L"", rect<s32>(440, 338, 660, 358), true, 0, 100);
				LoginUname->setMax(80);
				LoginUname->setAutoScroll(false);
				LoginUname->setMultiLine(false);
				LoginUname->setWordWrap(false);
				LoginUname->setDrawBackground(true);
				LoginUname->setOverrideFont(Courier10Red);
				LoginUname->setOverrideColor(video::SColor(255, 255, 0, 0));
				LoginUname->setTextAlignment(EGUIA_UPPERLEFT, EGUIA_UPPERLEFT);
			
				guienv->setFocus(LoginUname);
				LoginPassFLAG = 0;


	} //end if (strlen(uName)<1)
	
	
	if ((irr::core::stringw(LoginPasstext).size()<1) && (LoginPassFLAG == 0) && (LoginUnameFLAG == 1)) {

	} //end if ((strlen(uPass)<1) && (LoginPassFLAG==0) && (LoginUnameFLAG==1))
	
	if (LoginUnameFLAG == 1){
		Courier10Black->draw(irr::core::stringw(LoginUnametext).c_str(), core::rect<s32>(440, 344, 0, 0), video::SColor(255, 255, 255, 0));
	}

	if (LoginPassFLAG == 1){
		Courier10Black->draw(irr::core::stringw("**Encrypted**").c_str(), core::rect<s32>(440, 415, 0, 0), video::SColor(255, 255, 255, 0));
	}
	if ((LoginPassFLAG == 1) && (LoginUnameFLAG == 1)) {

		arial_24_yellow_blackout_bevel->draw(irr::core::stringw("* Press SUBMIT *").c_str(), core::rect<s32>(390, 635, 0, 0), video::SColor(255, 255, 255, 0));

	} //end if (LoginPassFLAG == 1) && (LoginUnameFLAG == 1)

	return 1;
	
}

/**************************************
RandomAdvertisement
Select a random ad to show on menu screen from 10 ads
***************************************/
void RandomAdvertisement()
{
	char adfilename[200] = "\0";
	int advertiseload = 0;
	FILE *FDP = NULL;
	

	Advertisement = NULL;

	//create random number between 1 and 100 for advertisement

	TASAd = (int)rand() % (100) + 1;

	if (TASAd<1) TASAd = 1;
	if (TASAd>100) TASAd = 1;

	sprintf(adfilename, "bmaps/advertisements/ad%i.jpg", TASAd);
	//load randomly selected advertisement bitmap

	FDP = NULL;
	FDP = fopen(adfilename, "r");
	if (FDP){
		advertiseload = 1;
		fclose(FDP);
	}
	if (advertiseload>0){
		if (Advertisement) Advertisement->unlock();
		if (Advertisement) driver->removeTexture(Advertisement);
		Advertisement = driver->getTexture(adfilename);
		if (Advertisement) Advertisement->lock(ETLM_READ_WRITE);
		if (Advertisement == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load %s\n", adfilename);
			fclose(ERR);
			CleanUp();
			device->drop();
		}
	} //end if advertiseload>0
	else {
		if (Advertisement) Advertisement->unlock();
		Advertisement = driver->getTexture("bmaps/advertisements/ad1.jpg");
		if (Advertisement) Advertisement->lock(ETLM_READ_WRITE);
		if (Advertisement == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load bmaps/advertisements/ad1.jpg\n");
			fclose(ERR);
			CleanUp();
			device->drop();
		}
	}//end else
}





/***************************************************************
Main entry for TASAT application [reads switches]
*****************************************************************/

int main(int argc, char *argv[])
{
	
	int brunning = 0, x=0;
	int hr = 0;
	float compare1 = 0; //compare program version
	float compare2 = 0; //compare program version


	IGUIFont* fontdefault;
	editboxIDValue = NULL;

	

	TASWindow = LOGINWINDOW; //start with login Menu

	fd = NULL;
	ERR = NULL;

	if (!(ERR = fopen("error.txt", "w")))
	{
		fprintf(stderr, "Error file open ERR \n");
		return(1);
	}
	else fclose(ERR);


	MSPaintAvail = system("where mspaint.exe");
	



	GetCurrentDirectory(255, currentWDir); //set the current working directory

	//Load TAS settings file tas.xml

	ReadINIFile();

	//clear user accounts (up to 200 members 1-199)
	for (x = 0; x < 200; x++)
	{
		TASMember[x].MemberNumber = 0;       //TAS member number		
		memset(TASMember[x].uName, 0, sizeof(TASMember[x].uName));  //Character name
		memset(TASMember[x].uPass, 0, sizeof(TASMember[x].uPass));   //password
		memset(TASMember[x].UPP, 0, sizeof(TASMember[x].UPP));   //character UPP
		memset(TASMember[x].uHomeWorld, 0, sizeof(TASMember[x].uHomeWorld));  //Character's homeworld
		memset(TASMember[x].uRace, 0, sizeof(TASMember[x].uRace));  //Character's race
		TASMember[x].uAccessLevel = 0;	    //TAS access level (1-10)
		TASMember[x].MarkerSectorNumber = -2; //sector number for marker
		memset(TASMember[x].MarkerSubSector, 0, sizeof(TASMember[x].MarkerSubSector));  //subsector letter
		TASMember[x].MarkerHex = 0;          //hex number for marker
		TASMember[x].MarkerX = 0;            //X coordinate for marker
		TASMember[x].MarkerY = 0;            //Y coordinate for marker
		TASMember[x].TASMemberHidden = 0;    //Member hidden record flag 1=yes 0=no
	}

	//Load member account file account.xml
	ReadAccountFile();

	//create the irrlicht display device
	/*
	The most important function of the engine is the createDevice()
	function. The IrrlichtDevice is created by it, which is the root
	object for doing anything with the engine. createDevice() has 7
	parameters:

	- deviceType: Type of the device. This can currently be the Null-device,
	one of the two software renderers, D3D8, D3D9, or OpenGL. In this
	example we use EDT_SOFTWARE, but to try out, you might want to
	change it to EDT_BURNINGSVIDEO, EDT_NULL, EDT_DIRECT3D8,
	EDT_DIRECT3D9, or EDT_OPENGL.

	- windowSize: Size of the Window or screen in FullScreenMode to be
	created. In this example we use 640x480.

	- bits: Amount of color bits per pixel. This should be 16 or 32. The
	parameter is often ignored when running in windowed mode.

	- fullscreen: Specifies if we want the device to run in fullscreen mode
	or not.

	- stencilbuffer: Specifies if we want to use the stencil buffer (for
	drawing shadows).

	- vsync: Specifies if we want to have vsync enabled, this is only useful
	in fullscreen mode.

	- eventReceiver: An object to receive events. We do not want to use this
	parameter here, and set it to 0.

	Always check the return value to cope with unsupported drivers,
	dimensions, etc.
	*/



	


	//check for window mode
	if ((argc >= 2) && (((strcmp(argv[1], "-w") == 0) || (strcmp(argv[1], "-W") == 0)))) {

		device = createDevice(video::EDT_OPENGL, dimension2d<u32>(1024, 768), 32, false, false, true, 0); //window mode

		if (!device)  {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Incompatible screen resolution, please check settings\n");
			fclose(ERR);
			exit(0);
		}

		//create settings for video display
		irr::SIrrlichtCreationParameters device_settings;
		device_settings.DriverType = video::EDT_OPENGL;
		device_settings.Bits = 16;
		device_settings.AntiAlias = false;
		device_settings.Fullscreen = false;
		device_settings.Vsync = false;
		device_settings.WindowSize = core::dimension2d<s32>(1024, 768);
		device_settings.EventReceiver = NULL;
		device_settings.Stencilbuffer = false;
		device = createDeviceEx(device_settings);
	}

	else{

		// create device using CHOICE MENU [uncomment below]
		isgf::IChoiceScreen set; //set the video resolution choice screen
		if (!set.choiceScreen())
			return -1;
		//irr::IrrlichtDevice *device = set.createDeviceFromMe();
		device = set.createDeviceFromMe();

		// Disable DPI auto-scaling (MS Windows 8/10). FULLSCREEN
		
		SetProcessDPIAwareFunc = (SetProcessDPIAwareType)GetProcAddress(GetModuleHandle(TEXT("user32")), "SetProcessDPIAware");
		if (SetProcessDPIAwareFunc)
		{
			SetProcessDPIAwareFunc();
		}
		/*
		device = createDevice(video::EDT_OPENGL, dimension2d<u32>(1024, 768), 16, true, false, true, 0); //full screen

		if (!device)  {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Incompatible screen resolution, please check settings\n");
			fclose(ERR);
			exit(0);
		}
		*/
		/*
		//create settings for video display
		irr::SIrrlichtCreationParameters device_settings;
		device_settings.DriverType = video::EDT_OPENGL;
		device_settings.Bits = 16;
		device_settings.AntiAlias = false;
		device_settings.Fullscreen = true;
		device_settings.Vsync = false;
		//device_settings.WindowSize = core::dimension2d<s32>(1024, 768);
		device_settings.EventReceiver = NULL;
		device_settings.Stencilbuffer = false;
		device = createDeviceEx(device_settings);
		*/
	}
	//set the event receiver back from resolution selector to our main event receiver
	device->setEventReceiver(&receiver);

	
	//Set the window caption
	if ((argc >= 2) && (((strcmp(argv[1], "-w") == 0) || (strcmp(argv[1], "-W") == 0)))) {
		device->setWindowCaption(L"Travellers' Aid Society Access Terminal");
	}
	
	//device->setResizable(true);
	
	//Set the environment based on the device pointer settings
	
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();

	skin = guienv->getSkin();

	//disable transparent GUI
	for (long i = 0; i < gui::EGDC_COUNT; ++i) {
		video::SColor col = guienv->getSkin()->getColor((gui::EGUI_DEFAULT_COLOR)i);
		col.setAlpha(255);
		guienv->getSkin()->setColor((gui::EGUI_DEFAULT_COLOR)i, col);
	}
	// Window BG
	//mySkin->setColor(EGDC_3D_FACE, SColor(255, 0, 0, 0));
	//mySkin->setColor(EGDC_3D_SHADOW, SColor(255, 0, 0, 0));

	// Titlebar Text
	//mySkin->setColor(EGDC_ACTIVE_CAPTION, SColor(255, 255, 255, 255));

	// Titlebar BG
	//mySkin->setColor(EGDC_ACTIVE_BORDER, SColor(255, 0, 0, 0));

	// Border
	//mySkin->setColor(EGDC_3D_DARK_SHADOW, SColor(255, 0, 0, 0));
	//mySkin->setColor(EGDC_3D_HIGH_LIGHT, SColor(255, 0, 0, 0));

	// Button Text
	//mySkin->setColor(EGDC_BUTTON_TEXT, SColor(255, 255, 255, 255));

	// Selected ListBox Item Text
	//skin->setColor(EGDC_HIGH_LIGHT_TEXT, SColor(255, 255, 255, 255));

	// Selected ListBox Item BG
	skin->setColor(EGDC_HIGH_LIGHT, SColor(255, 255, 255, 0));

	// Textbox BG
	//mySkin->setColor(EGDC_WINDOW, SColor(255, 0, 0, 0));

	// Scrollbar Arrows
	//mySkin->setColor(EGDC_WINDOW_SYMBOL, SColor(255, 255, 255, 255));

	// Scrollbar, EditBox BG
	//mySkin->setColor(EGDC_SCROLLBAR, SColor(255, 50, 50, 50));
	


	smgr->addCameraSceneNode(0, core::vector3df(0, 0, -40), core::vector3df(0, 0, 0)); //use this node for 3d items on screen [rotating planet]



    //load the first font. the rest are loaded in initialization.c
	Courier10Green = guienv->getFont("fonts/courier10g.xml");
	if (Courier10Green == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/courier10g.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	fontdefault = guienv->getBuiltInFont();
	
	backsurf = driver->getTexture("bmaps/menu/loading.jpg");

	if (backsurf == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/loading.jpg\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	
	//fade in title screen
	irr::gui::IGUIInOutFader* fader = device->getGUIEnvironment()->addInOutFader();
	fader->setColor(video::SColor(255, 0, 0, 0));
	fader->fadeIn(4000);

	while (device->run() && !fader->isReady())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, SColor(0, 0, 0, 0));
			driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
			device->getGUIEnvironment()->drawAll();

			driver->endScene();
		}
	}
	fader->remove();
	//end of fade in

	//draw title screen
	driver->beginScene(true, true, SColor(255, 0, 0, 0));

	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0),core::rect<s32>(0, 0, 1024, 768), 0,video::SColor(255, 255, 255, 255), true);

	//display TAS application version number

		Courier10Green->draw(L"Version:", core::rect<s32>(430, 700, 0, 0), video::SColor(255, 255, 255, 255));
		Courier10Green->draw(irr::core::stringw(TASVersion).c_str(), core::rect<s32>(540, 700, 0, 0), video::SColor(255, 255, 255, 255));

	smgr->drawAll();
	guienv->drawAll();
	driver->endScene();

	Delay(1000); //delay for splash screen
	
	InitTAS(); //initialize all global variables

	//randomize using time seed
	//srand((unsigned)time(NULL));
	srand(TASDay + TASYear);

	//set the default GUI font used by all dialog and listboxes
	guienv->getSkin()->setFont(Courier10Black);

	//reset variables
	subsectorhex = 0;
	sectorfile = -1;
	newstoday = FALSE;
	
	InitNAV(); //Load Navigation Library bitmaps
	InitNEWS(); //load news bitmaps
	InitLIBDATA(); //Load News bitmaps
	InitACCOUNTS(); //Load Account Services images
	InitKnownSpaceLocations(); //create galaxy map 
	InitCLASSIFIEDS(); //load classified images
	InitXBOAT(); //load xboat images

	RandomClassifieds(); //set the for sale ads for the day


	UpdateTheScreen = 1;
	brunning = 1;

	driver->beginScene(true, true, SColor(0, 0, 0, 0));

	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0),core::rect<s32>(0, 0, 1024, 768), 0,video::SColor(255, 255, 255, 255), true);

	//Present login screen
	hr = LoginScreen();

	//create random main screen advertisement
	RandomAdvertisement();



	while(device->run() && brunning==1)
	{

	//Anything can be drawn between a beginScene() and an endScene() call. The beginScene() call clears the screen with a color and
	//the depth buffer, if desired. Then we let the Scene Manager and the GUI Environment draw their content. With the endScene()
	//call everything is presented on the screen.
	

	TasEventHandler();  	//check for mouse and keyboard input

	if ((TASWindow == GALAXYWINDOW))
	{
		hr = Updatescreengalaxy();
	} //end if TASWindow=GALAXYWINDOW

	if ((TASWindow == SUBSECTORWINDOW))
	{
		hr = UpdateSubSecScreen(subsectorhex);

		

	} //end if TASWindow=SUBSECTORWINDOW
	

		if ((TASWindow == PLANETWINDOW))
		{

			display_planet2();

		} //end if TASWindow=PLANETWINDOW


		if ((TASWindow == SUBSECTORLIBDATAWINDOW))
		{

			//if there is an associated image...
			if (libimagecheck>0)
			{
				driver->draw2DImage(libdataimagebutton, core::position2d<s32>(750, 330), core::rect<s32>(0, 0, 200, 50), 0, video::SColor(255, 255, 255, 255), false);
			}
		} //end if TASWindow=SUBSECTORLIBDATAWINDOW
		
		if ((TASWindow == SECTORWINDOW))
		{
			hr = Updatescreensec();
		} //end if TASWindow=SECTORWINDOW

		if ((TASWindow == SECTORFLEETWINDOW))
		{
			hr = Updatescreenfleet();
		} //end if TASWindow=SECTORFLEETWINDOW
		
		if ((TASWindow == SECTORLIBDATAWINDOW))
		{			
			//place anything you need to update here
		} //end if TASWindow=SECTORLIBDATAWINDOW

		if ((TASWindow == SUBSECLIBDATAIMAGEWINDOW))
		{
			DisplaylibdataDataSubSecImage();
		} //end if TASWindow=SUBSECLIBDATAIMAGEWINDOW

		if ((TASWindow == NEWSSERVICEWINDOW)){
			DisplayNewsData();
		} //end if TASWindow=NEWSSERVICEWINDOW
		
		if ((TASWindow == LIBDATASERVICEWINDOW)){


			DisplaylibdataData();


		} //end if TASWindow=LIBDATASERVICEWINDOW
		
		if ((TASWindow == LIBDATAIMAGEWINDOW))
		{
			DisplaylibdataDataImage();
		} //end if TASWindow=LIBDATAIMAGEWINDOW

		

		if ((TASWindow == ARCHIVENEWSWINDOW)){


			DisplayNewsArchiveData();


		} //end if TASWindow=ARCHIVENEWSWINDOW

		if ((TASWindow == RUMORSNEWSWINDOW)){


			DisplayNewsRumorData();


		} //end if TASWindow=RUMORSNEWSWINDOW

		
		if ((TASWindow == ACCOUNTSERVICEWINDOW)){


			DisplayAccountServices();


		} //end if TASWindow=ACCOUNTWINDOW

		if ((TASWindow == BANKINGWINDOW)){


			DisplayBankServices();


		} //end if TASWindow=BANKINGWINDOW

		if ((TASWindow == LOANWINDOW)){


			DisplayLoanServices();


		} //end if TASWindow=LOANWINDOW

		if ((TASWindow == PERSONALWINDOW)){


			DisplayPersonalServices();


		} //end if TASWindow=PERSONALWINDOW

		
		if ((TASWindow == CLASSIFIEDMENU)){


			DisplayClassifiedsMenu();


		} //end if TASWindow=CLASSIFIEDMENU
	
		if ((TASWindow == FORSALEWINDOW)){


			DisplayForSaleWindow();


		} //end if TASWindow=FORSALEWINDOW

		if ((TASWindow == FORSALESPACECRAFTWINDOW)){


			DisplayFSSpacecraftWindow();


		} //end if TASWindow=FORSALESPACECRAFTWINDOW

		if ((TASWindow == FORSALEVEHICLESWINDOW)){


			DisplayFSVehicleWindow();


		} //end if TASWindow=FORSALEVEHICLESWINDOW

		if ((TASWindow == FORSALEITEMSWINDOW)){


			DisplayFSItemsWindow();


		} //end if TASWindow=FORSALEITEMSWINDOW

		if ((TASWindow == MISSIONSWINDOW)){


			DisplayMissionsMenu();


		} //end if TASWindow=MISSIONSWINDOW

		if ((TASWindow == HELPWANTEDMENU)){


			DisplayHelpWantedMenu();


		} //end if TASWindow=HELPWANTEDMENU

		if ((TASWindow == MAINMENUWINDOW))
		{
			hr = Updatescreenmainmenu();
		} //end if TASWindow=MAINMENUWINDOW
		
		if ((TASWindow == XBOATMENU)){


			DisplayXBoatMenu();


		} //end if TASWindow=XBOATMENU
		
		if ((TASWindow == XBOATREADMENU)){


			DisplayXBoatReadMenu();


		} //end if TASWindow=XBOATREADMENU

		if ((TASWindow == XBOATREADNEWMENU)){


			DisplayXBoatReadNewMenu();


		} //end if TASWindow=XBOATREADNEWMENU

		if ((TASWindow == XBOATREADOLDMENU)){


			DisplayXBoatReadOldMenu();


		} //end if TASWindow=XBOATREADNEWMENU

		if ((TASWindow == XBOATSENDMENU)){


			DisplayXBoatSendMenu();


		} //end if TASWindow=XBOATSENDMENU
		
		if ((TASWindow == LOGINWINDOW))
		{

			hr = LoginScreen();
			if ((LoginPassFLAG < 1) || (LoginUnameFLAG < 1))
			{
				//black out submit button
				driver->draw2DRectangle(video::SColor(255, 0, 0, 0), core::rect<s32>(380, 444, 631, 517));
				Courier10Yellow->draw(irr::core::stringw(L"Press ENTER after each entry"), core::rect<s32>(395, 225, 0, 0), video::SColor(255, 255, 255, 255));
			}
		} //end if TASWindow=LOGINWINDOW
		
		if ((TASWindow == TASEXITWINDOW))
		{
			UpdateTheScreen = 0;
			brunning = 0;
		}
	
		//!!!!TEST REMOVE MOUSE STUFF BELOW
		//device->getCursorControl()->setVisible(false);  //use to hide mouse pointer		
		device->getCursorControl()->getPosition();
		mouse_position = device->getCursorControl()->getPosition();
		/*
		Courier10Green->draw(irr::core::stringw(mouse_position.X).c_str(), core::rect<s32>(100, 740, 0, 0), video::SColor(255, 255, 255, 255));
		Courier10Green->draw(irr::core::stringw(mouse_position.Y).c_str(), core::rect<s32>(180, 740, 0, 0), video::SColor(255, 255, 255, 255));
		*/

		CheckMouseHoverOver(); //display hover over messages
		

		if (UpdateTheScreen == 1){

			UpdateTheScreen = 0;
			
		}
		smgr->drawAll();

		guienv->drawAll();

		driver->endScene();
		driver->beginScene(true, true, SColor(0, 0, 0, 0));

		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0),core::rect<s32>(0, 0, 1024, 768), 0,video::SColor(255, 255, 255, 255), true);

	} //end while

	//write updated account file
	WriteAccountFile();

	//CleanUp();
	
	//After we are done with the render loop, we have to delete the Irrlicht Device created before with createDevice(). In the Irrlicht Engine, you
	//have to delete all objects you created with a method or function which starts with 'create'. The object is simply deleted by calling ->drop().
	//See the documentation at irr::IReferenceCounted::drop() for more information.

	

device->closeDevice();
	
device->drop();

return 0;

	
}

/*
That's it. Compile and run.
**/
