// Copyright (C) 2010-2011 Dario Oliveri
// This file is part of the "IrrSolid" game engine.
// For conditions of distribution and use, see copyright notice in AGT.h

#include "IChoiceScreen.h"

namespace isgf
{

bool IChoiceScreen::OnEvent(const irr::SEvent& event)
{
	if(event.EventType == irr::EET_GUI_EVENT)
	{
		irr::s32 id = event.GUIEvent.Caller->getID();

		switch(event.GUIEvent.EventType)
		{
		case irr::gui::EGET_COMBO_BOX_CHANGED:

			checkUpdate();
			return true;

		case irr::gui::EGET_BUTTON_CLICKED:

			if(id==GUI_ID_START)
				quit = false;
			else
				quit = true;
			device->closeDevice(); //exit the "vide mode selection" window

			return true;

		case irr::gui::EGET_CHECKBOX_CHANGED:

			if( id == GUI_ID_OPENGL)
			{
				unCheckDrivers();
				check_opengl->setChecked(true);
			}
			if( id == GUI_ID_DIRECT3D8)
			{
				unCheckDrivers();
				check_directx8->setChecked(true);
			}
			if( id == GUI_ID_DIRECT3D9)
			{
				unCheckDrivers();
				check_directx9->setChecked(true);
			}
			if( id == GUI_ID_BURNINGVIDEO)
			{
				unCheckDrivers();
				check_burnvideo->setChecked(true);
			}
			if( id == GUI_ID_SOFTWARE)
			{
				unCheckDrivers();
				check_software->setChecked(true);
			}
		default:
			break;
		} //switch
	}  //EET_GUI_EVENT (if)


	if(event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
	{
		switch (event.KeyInput.Key)
		{
			case irr::KEY_ESCAPE:
				quit = true;
				device->closeDevice(); //exit the "vide mode selection" window
				return true;

			default:
				break;
		}//switch
	} //EET_KEY_INPUT_EVENT & keydown (if)

	return false;
}


void IChoiceScreen::checkUpdate()
{
	selected_video_mode = getSelectedVideoMode();

	//free to remove the screen ratio control if you know what are you doing.
	//(some issued related to appending GUI graphics to the screen)
	//in that way you are sure that only fullscreen mode with the same ratio
	//of users' monitor will be used
	if (selected_video_mode.ratio == desktop.ratio && desktop.ratio != SCRRATIO_UNKNOWN)
	{
		check_Fullscreen->setEnabled(true);
		check_Vsync->setEnabled(true);
	}
	else
	{
		check_Fullscreen->setChecked(false);
		check_Vsync->setChecked(false);

		check_Fullscreen->setEnabled(false);
		check_Vsync->setEnabled(false);
	}
}


//here i uncheck drivers, letting driver checbox working as a radio button list.. why don't use a listbox?
//lol i really don't know. :)
void IChoiceScreen::unCheckDrivers()
{
	if(check_opengl)
		check_opengl->setChecked(false);
	if(check_directx8)
		check_directx8->setChecked(false);
	if(check_directx9)
		check_directx9->setChecked(false);
	if(check_burnvideo)
		check_burnvideo->setChecked(false);
	if(check_software)
		check_software->setChecked(false);
}

}//end of namespace "agt"
