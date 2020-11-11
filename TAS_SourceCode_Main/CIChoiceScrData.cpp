// Copyright (C) 2010-2011 Dario Oliveri
// This file is part of the "IrrSolid" game engine.
// For conditions of distribution and use, see copyright notice in AGT.h

#include "IChoiceScreen.h"

namespace isgf
{
bool IChoiceScreen::choiceScreen()
{
	if(loadFromXML())
		if(hide_choice)
			return true;  //if a XML config file exist and it ask for hide ChoiceScreen
	                      //it is not necessary create a device for the window of ChoiceScreen.

	device =
		createDevice( irr::video::EDT_SOFTWARE , irr::core::dimension2d<irr::u32>(380,380), 16,
		false, false, true, this);

	if (!device)
		return false; //BREAK_POINT unable to create device


	driver = device->getVideoDriver();
	guienv = device->getGUIEnvironment(); //obviously no scene manager (if you want you can add it)

	device->setWindowCaption(L"Video mode selection");

	//add the combobox that we are going to fill with all videomodes available
	combobox  = guienv->addComboBox(  irr::core::rect<irr::s32>(220,18,380,38),   0,  GUI_ID_CBO);

	//add the START and QUIT buttons.
	btn_start = guienv->addButton(    irr::core::rect<irr::s32>(20,160,80,180),   0,  GUI_ID_START,
				L"Start",L"Click here to start the app");
	btn_quit  = guienv->addButton(    irr::core::rect<irr::s32>(100,160,160,180), 0,  GUI_ID_QUIT,
				L"Quit",L"Click here or the 'X', or ESC, to quit");


	//static text with some extra description
	txt_combo  = guienv->addStaticText(L"Select Screen Resolution and color depth:", irr::core::rect<irr::s32>(20,18,220,60) );
	txt_driver = guienv->addStaticText(L"Select your 3D render driver:", irr::core::rect<irr::s32>(20,200,370,250));

	//add Checkboxes with some additional options.
	check_Fullscreen   = guienv->addCheckBox(false, irr::core::rect<irr::s32>(20,65,400,85),  0, -1, L"Full Screen");
	check_Vsync        = guienv->addCheckBox(false, irr::core::rect<irr::s32>(20,95,400,115), 0, -1, L"Vertical Screen Syncro");
	check_showNextTime = guienv->addCheckBox(true, irr::core::rect<irr::s32>(20,125,400,145), 0, -1, L"Show next time");

	//some update it will change the default Checked Check box according to your
	//default settings or settings founded in the "config.xml" file.

	bool d3d8 = p.DriverType == irr::video::EDT_DIRECT3D8;
	bool d3d9 = p.DriverType == irr::video::EDT_DIRECT3D9;
	bool opgl = p.DriverType == irr::video::EDT_OPENGL;
	bool burn = p.DriverType == irr::video::EDT_BURNINGSVIDEO ;
	bool soft = p.DriverType == irr::video::EDT_SOFTWARE;

////////////////////////////////////////////////

				//You can safely remove unwanted drivers by simply commenting
				//lines of unwated drivers from the 5 following lines

	//check_directx8   = guienv->addCheckBox(d3d8,  appendNextCheck(),  0, GUI_ID_DIRECT3D8, L"Direct3D 8");
	//check_directx9   = guienv->addCheckBox(d3d9,  appendNextCheck(),  0, GUI_ID_DIRECT3D9, L"Direct3D 9");
	check_opengl     = guienv->addCheckBox(opgl,  appendNextCheck(),  0, GUI_ID_OPENGL,    L"OpenGL");
	//check_burnvideo  = guienv->addCheckBox(burn,  appendNextCheck(),  0, GUI_ID_BURNINGVIDEO, L"Burnings Video");
	//check_software   = guienv->addCheckBox(soft,  appendNextCheck(),  0, GUI_ID_SOFTWARE, L"Software");

/////////////////////////////////////////////////

	//and if you forget to comment directx under linux or MAC OS,
	//i will remove directx check buttons for you.

	#ifndef _IRR_COMPILE_WITH_DIRECT3D_8_  // thanks to "greenya" for that idea.
	if(check_directx8)
		check_directx8->remove();
	check_directx8  = 0;
	#endif
	#ifndef	_IRR_COMPILE_WITH_DIRECT3D_9_
	if(check_directx9)
		check_directx9->remove();
	check_directx9  = 0;
	#endif

	//add irrlicht logo, directly from the DEMO app.
	driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
	guienv->addImage(driver->getTexture("bmaps/menu/icon.jpg"),
		irr::core::position2d<irr::s32>(257,185));

	//set a bigger and nicer font
	/*
	guienv->getSkin()->setFont(
		guienv->getFont(the font you like));
    */

	//create and fill the video mode list. (thanks to "greenya" for showing me how to use the
	//irr::video::IVideoModeList class)
	updateVideoModeList();

	//main loop
	while(device->run())
	{
		if(device->isWindowActive())
		{
			driver->beginScene(true,false, irr::video::SColor(0,170,170,170));
			guienv->drawAll();  //no need to draw smgr stuff.
			driver->endScene();
		}
		else
			device->yield();
	}

	//export user selected settings.
	updateData();
	if(!quit)
		writeToXML(); //save user selected settings to xml

	device->drop(); //close the actual window
	if(quit)        //user asked for QUIT or something went wrong in "UpdateData"
		return false;

	return true; //all is allright. you can create a new device now.
}


//here the combobox is filled.
void IChoiceScreen::updateVideoModeList()
{
	irr::video::IVideoModeList* vml = device->getVideoModeList(); //Thanks to "greenya" for showing me
														     //how to use getVideoModeList().
	VMode screen;

		for (irr::s32 i = 0; i < vml->getVideoModeCount(); i++)
		{

			screen.depth      = vml->getVideoModeDepth(i);
			screen.resolution = vml->getVideoModeResolution(i);
			screen.ratio      = getRatioEquals(screen.resolution);

			//you can change freely the control, just change the "if" test.
			//for example if you wanna let play only screen resolution starting from 800x600 you
			//can change the "if" into (screen.resolution.Height>=600 && screen.resolution.Width>=800)
			if ((screen.depth != 8) && (screen.resolution.Height >= 768 && screen.resolution.Width >= 1024)) //I'm really non interested on permitting playing with 256 colours
			{
				videolist.push_front(screen);


				str = L"";   //what is showed in the combo box? here i'm writing one of the items
				str+= ++counter;
				str+= ") ";
				str+= screen.resolution.Width;
				str+= "x";
				str+= screen.resolution.Height;
				str+= "x";
				str+= screen.depth;

				combobox->addItem(str.c_str());
			}
		}//for
		desktop.resolution = vml->getDesktopResolution();
		desktop.depth = vml->getDesktopDepth();
		desktop.ratio = getRatioEquals(desktop.resolution);

		checkUpdate();

}


//here you send variables wich you will use for create your application device.
void IChoiceScreen::updateData()
{
	hide_choice  = !check_showNextTime->isChecked();
	//p.Fullscreen = check_Fullscreen->isChecked();
	p.Fullscreen = true;
	//p.Vsync      = check_Vsync->isChecked();
	p.Vsync = false;
	p.WindowSize = selected_video_mode.resolution;
	p.Bits       = selected_video_mode.depth;

	/*
	if(   check_software  ) //safe control. operation on drivers checkboxes are done onyl if the checkbox exist
		if(  check_software->isChecked()  )
			p.DriverType = irr::video::EDT_SOFTWARE;

	if(  check_burnvideo  )
		if(  check_burnvideo->isChecked() )
			p.DriverType = irr::video::EDT_BURNINGSVIDEO;

	if(  check_directx9  )
		if(  check_directx9->isChecked()  )
			p.DriverType = irr::video::EDT_DIRECT3D9;

	if(  check_directx8  )
		if(  check_directx8->isChecked()  )
			p.DriverType = irr::video::EDT_DIRECT3D8;

	if(   check_opengl   )
		if(   check_opengl->isChecked()   )
			p.DriverType = irr::video::EDT_OPENGL;
			*/
	p.DriverType = irr::video::EDT_OPENGL;
}


//return VMode struct associated to selected resolution in combobox
VMode IChoiceScreen::getSelectedVideoMode()
{
	irr::core::list<VMode>::Iterator  vmi = videolist.begin(); //some thanks here to "monchito"

	irr::s32 limit = counter - combobox->getSelected();
	irr::s32 breaker = 0;

	for (; vmi != videolist.end(); ++vmi) //this loop is not very "nice" but it works greatly.
	{
		breaker++;
		if(breaker == limit)
			break;
	}

	return (*vmi);
}

//create device from user settings selection
irr::IrrlichtDevice* IChoiceScreen::createDeviceFromMe()
{
	//#ifdef _DEBUG
	//if(p.Fullscreen)
	//	p.Fullscreen=false; //BREAK_POINT prevent Irrlicht 1.7.1 bug with directX, a break point
	//#endif                  //called when in fullscreenmode can cause problems.
	return irr::createDeviceEx(p);
}

}//end of namespace "agt"
