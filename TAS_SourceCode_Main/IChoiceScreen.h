// Copyright (C) 2010-2011 Dario Oliveri
// This file is part of the "IrrSolid" game engine.
// For conditions of distribution and use, see copyright notice in AGT.h

#ifndef CHOICE_SCREEN_INCLUDED
#define CHOICE_SCREEN_INCLUDED

#include <irrlicht.h> //Irrlicht library is Copyright (C) 2002-2009 by Nikolaus Gebhardt
#include "SVideoModeUtils.h"


namespace isgf
{

//! This class is used to show a window before you application starts letting to the users the videomode choice.
/** In order to do that you must create a instance of the class and call on it the method "choiceScreen".
If all is allright it will return true and you will be able to create the device for your app using the method
"createDeviceFromMe".
*/
class IChoiceScreen : public irr::IEventReceiver
{
private:
    enum guiCommandName
    {
        GUI_ID_QUIT=101,
        GUI_ID_START,
        GUI_ID_CBO,
        GUI_ID_OPENGL,
        GUI_ID_DIRECT3D8,
        GUI_ID_DIRECT3D9,
        GUI_ID_BURNINGVIDEO,
        GUI_ID_SOFTWARE
    };
	//variables of GUI and whatever is showed in the "Video Mode Selection" window
	irr::IrrlichtDevice			*device;
	irr::video::IVideoDriver    *driver;
	irr::gui::IGUIEnvironment   *guienv;


	irr::gui::IGUIComboBox     *combobox;
	irr::gui::IGUIButton       *btn_start;
	irr::gui::IGUIButton       *btn_quit;
	irr::gui::IGUICheckBox     *check_Fullscreen;
	irr::gui::IGUICheckBox     *check_Vsync;
	irr::gui::IGUICheckBox     *check_showNextTime;
	irr::gui::IGUICheckBox     *check_opengl;
	irr::gui::IGUICheckBox     *check_directx8;
	irr::gui::IGUICheckBox     *check_directx9;
	irr::gui::IGUICheckBox	   *check_burnvideo;
	irr::gui::IGUICheckBox     *check_software;
	irr::gui::IGUIStaticText   *txt_combo;
	irr::gui::IGUIStaticText   *txt_driver;

	irr::SIrrlichtCreationParameters p;

	////variables used for creating the device of your app.
	//E_DRIVER_TYPE  p.DriverType;    //EDT_SOFTWARE, EDT_BURNINGSVIDEO, EDT_NULL, EDT_DIRECT3D8, EDT_DIRECT3D9, EDT_OPENGL.
	//dimension2du   resolution; //windowSize: Size of the Window or screen in p.FullscreenMode.
	//s32     p.Bits;             //bits: Color p.Bits This should be 16 or 32.
    //bool    p.Fullscreen;        //p.Fullscreen: Specifies if we want the device to run in p.Fullscreen mode or not.
	//bool    p.Stencilbuffer;     //p.Stencilbuffer: Specifies if we want to use the stencil buffer
	//bool    p.Vsync;             //p.Vsync: Specifies if we want to have p.Vsync enabled, this is only useful in p.Fullscreen mode.
	//IChoiceScreen  *p.EventReceiver;  //eventp.EventReceiver

	//other variables
	irr::s32			counter;   //number of items in the combobox
	bool				quit;      //if this is "true" your application will start after IChoiceScreen device being closed.
	irr::core::stringw	str;       //additional info are stored here. (you can save a string like "800x600x16" for example)
	bool				hide_choice;

	irr::core::list<VMode>		videolist; //a list that contain all videomodes available for your computer
	irr::core::rect<irr::s32>   check_coords;


public:

	//some fast access data. Don't change them. just read.. // maybe it is a good idea making them private.
	VMode        desktop;            //actual desktop resolution info
	VMode        selected_video_mode;//actual app resolution (of course if you used "createDeviceFromMe")



	//! default constructor. Set all default values.
	IChoiceScreen()
	{
		p.DriverType = irr::video::EDT_SOFTWARE;
		p.Bits          = 16;
		p.Fullscreen    = false;
		p.Stencilbuffer = false;
		p.Vsync         = false;
		p.EventReceiver = 0;
		p.AntiAlias     = false;

		quit          = true;     //if after choosing all settings something wrong "quit" will still be true.
		hide_choice   = false;    //if user asked "don't show Choice Screen Next time" this will be true
		counter       = 0;
		p.WindowSize. set(640,480);

		device        = 0;
		driver        = 0;
	    guienv        = 0;

		check_opengl    = 0; //safe settings. if a checkbox is not created it will be skipped by my controls.
	    check_directx8  = 0;
	    check_directx9  = 0;
	    check_burnvideo = 0;
	    check_software  = 0;
		check_coords    = irr::core::rect<irr::s32>(20,200,400,220);

		str				= L"";
	}



	//! returns if \param windowSize ratio is equals to one of the standard screen ratios, or unknown.
	screenRatio getRatio(     const irr::core::dimension2d<irr::u32>& windowSize =
		(irr::core::dimension2d<irr::u32>(100,100))    )
	{
		if(windowSize.Height*4 == windowSize.Width*3)
			return SCRRATIO_4_3 ;
		if(windowSize.Height*16 == windowSize.Width*9)
			return SCRRATIO_16_9;
		if(windowSize.Height*15 == windowSize.Width*9)
			return SCRRATIO_15_9;
		if(windowSize.Height*20 == windowSize.Width*9)
			return SCRRATIO_20_9;
		return SCRRATIO_UNKNOWN;
	}


	//! returns if \param windowSize ratio is equals to one of the standard screen ratios, or unknown
	/** taking into account an explicit rounding tolerance error.*/
	screenRatio getRatioEquals(
		const irr::core::dimension2d<irr::u32>& windowSize = (irr::core::dimension2d<irr::u32>(100,100)),
		irr::s32 error=30)
	{

		if(irr::core::equals(windowSize.Height*4, windowSize.Width*3, error))
			return SCRRATIO_4_3 ;
		if(irr::core::equals(windowSize.Height*16, windowSize.Width*9, error))
			return SCRRATIO_16_9;
		if(irr::core::equals(windowSize.Height*15, windowSize.Width*9, error))
			return SCRRATIO_15_9;
		if(irr::core::equals(windowSize.Height*20, windowSize.Width*9, error))
			return SCRRATIO_20_9;
		return SCRRATIO_UNKNOWN;
	}


	//! override of the method in the IEventp.EventReceiver class. Used for events handling in the
	/**"Video Mode Seletcion" window*/
	virtual bool OnEvent(const irr::SEvent& event);


	//! This shows the "Video Mode Selection" window. If anything is wrong it return false. If
	/**it returns true you can proceed with the "createDeviceFromMe" method*/
	bool choiceScreen();

	//! create a device using the parameters selected in the "Video Mode Selection" window
	/**If anything is wrong it return false (0). Created device has always to being dropped*/
	irr::IrrlichtDevice *createDeviceFromMe();

	//! returns creation parameters. I really don't know if it will be usefull to someone..
	irr::SIrrlichtCreationParameters getParameters()
	{
		return p;
	}

	//! load Settings from a XML file. (it is possible that this will stop
	/**ChoiceScreen from being showed). return true if successfully*/
	bool loadFromXML();

	//! save settings to a XML file. return true if successfully
	bool writeToXML();

	//! some security control on data being used for create a device
	/** for now only platform dependcy of the drivers*/
	void validateXMLData();

	//! destructor
	~IChoiceScreen() { }

private:


	//! private method that I use for fillin the <VMode> list and keep the code cleaner.
	void updateVideoModeList();


	//! private method that I use for update data according to the user settings selection.
	void updateData();


	//! private method, returns the selected videomode in the combo box as an iterator
	/**to use that just do "VMode screen=(*iterator)*/
	VMode getSelectedVideoMode();


	//! private method, check if some options are available for the choosen resolution
	void checkUpdate();

	//! private method, remove the check sign from all the drivers checkboxes.
	void unCheckDrivers();

	//! private method, used to increase automatically the check button coordinates.
	irr::core::rect<irr::s32> appendNextCheck()
	{
		check_coords+=irr::core::vector2d<irr::s32>(0,30); //move down of 30 pixels the coordinates for the next checkbutton
		return check_coords;
	}

};//end of class IChoiceScreen:IEventp.EventReceiver
}
#endif //CHOICE_SCREEN_INCLUDED
