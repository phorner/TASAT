// Copyright (C) 2010-2011 Dario Oliveri
// This file is part of the "IrrSolid" game engine.
// For conditions of distribution and use, see copyright notice in AGT.h

#include "IChoiceScreen.h"

namespace isgf
{

bool IChoiceScreen::loadFromXML()
{
	irr::io::IrrXMLReader* config = irr::io::createIrrXMLReader("config.xml");
	if(!config)
		return false;
	while( config && config->read() )
	{
		switch( config->getNodeType() )
		{
		case irr::io::EXN_ELEMENT:

			if     ( irr::core::stringw("screen")  == config->getNodeName())
			{
				p.WindowSize.set( config->getAttributeValueAsInt("Width") ,
								  config->getAttributeValueAsInt("Height")
					);
				p.Bits       = config->getAttributeValueAsInt("ColorDepth");
				p.Fullscreen = 0 < config->getAttributeValueAsInt("FullScreen");

			}
			else if( irr::core::stringw("options") == config->getNodeName())
			{
				p.Vsync         = 0 < config->getAttributeValueAsInt("VSync");
				p.Stencilbuffer = 0 < config->getAttributeValueAsInt("Shadows");
				p.AntiAlias     = 0 < config->getAttributeValueAsInt("AntiAlias");
				hide_choice     = 1 > config->getAttributeValueAsInt("ShowNextTime");

			}
			else if( irr::core::stringw("driver")  == config->getNodeName())
			{
				irr::core::stringw d = config->getAttributeValueSafe("Type");

				if(d == "opengl")
					p.DriverType = irr::video::EDT_OPENGL;

				if(d == "d3d8")
					p.DriverType = irr::video::EDT_DIRECT3D8;

				if(d == "d3d9")
					p.DriverType = irr::video::EDT_DIRECT3D9;

				if(d == "burn")
					p.DriverType = irr::video::EDT_BURNINGSVIDEO;

				if(d == "software")
					p.DriverType = irr::video::EDT_SOFTWARE;
			}

			break;
		default:
			break;
		}


	}
	validateXMLData();
	delete config;
	return true;
}

bool IChoiceScreen::writeToXML()
{
	irr::core::stringw strxml("");
	irr::io::IFileSystem *OS=device->getFileSystem();
	if(!OS)
		return false;
	irr::io::IXMLWriter *xml = OS->createXMLWriter(L"config.xml");
	if(!xml)
		return false;

	xml->writeXMLHeader();
	/*dimension2du x(1,0),y(0,1);
	x=x*p.WindowSize.;
	y=y*p.WindowSize;*/

	/*IAttributes a;
	a.*/
	xml->writeElement(L"config");
	xml->writeLineBreak();
	xml->writeElement(L"game",true,L"Name",L"gameName",L"Version",L"0.1",
					  L"Author",L"Dario Oliveri",L"License",L"Zlib");
	xml->writeLineBreak();
	xml->writeElement(L"screen",true,
		L"Width"     ,   (irr::core::stringw("")+=p.WindowSize.Width).c_str() ,
		L"Height"    ,   (irr::core::stringw("")+=p.WindowSize.Height).c_str(),
		L"ColorDepth",   (irr::core::stringw("")+=p.Bits).c_str(),
		L"FullScreen",   (irr::core::stringw("")+=(irr::u32)p.Fullscreen).c_str() );
	//xml->writeClosingTag(L"screen");
	xml->writeLineBreak();
	xml->writeElement(L"options",true,
		L"VSync"       , (irr::core::stringw("")+=(irr::u32)p.Vsync).c_str(),
		L"Shadows"     , (irr::core::stringw("")+=(irr::u32)p.Stencilbuffer).c_str(),
		L"AntiAlias"   , (irr::core::stringw("")+=(irr::u32)p.AntiAlias ).c_str(),
		L"ShowNextTime", (irr::core::stringw("")+=(irr::u32)(!hide_choice)).c_str() );
	xml->writeLineBreak();

	if(p.DriverType==irr::video::EDT_OPENGL)
		strxml=L"opengl";
	if(p.DriverType==irr::video::EDT_DIRECT3D8)
		strxml=L"d3d8";
	if(p.DriverType==irr::video::EDT_DIRECT3D9)
		strxml=L"d3d9";
	if(p.DriverType==irr::video::EDT_BURNINGSVIDEO)
		strxml=L"burn";
	if(p.DriverType==irr::video::EDT_SOFTWARE)
		strxml=L"software";

	xml->writeElement(L"driver",true,
		L"Type",strxml.c_str() );
	xml->writeLineBreak();
	xml->writeLineBreak();


	strxml=L"supported drivers are:";
	#ifdef _IRR_COMPILE_WITH_DIRECT3D_9_
	strxml+=" d3d8,";
	#endif
	#ifdef _IRR_COMPILE_WITH_DIRECT3D_9_
	strxml+=" d3d9,";
	#endif
	#ifdef _IRR_COMPILE_WITH_OPENGL_
	strxml+=" opengl,";
	#endif
	#ifdef _IRR_COMPILE_WITH_BURNINGSVIDEO_
	strxml+=" burn,";
	#endif
	#ifdef _IRR_COMPILE_WITH_SOFTWARE_
	strxml+=" software";
	#endif

	xml->writeComment(strxml.c_str());
	xml->writeLineBreak ();
	xml->writeLineBreak ();

	strxml=L"\n\tYour System Info:"; //print "Your System Info: "

	strxml+=L"\n\t\tOS version: ";  //print os version
	strxml+=device->getOSOperator()->getOperationSystemVersion();

	strxml+=L"\n\t\tCPU speed: ";   //print the speed of the cpu in wich the game run
	{
		irr::u32 cpu=0;
		if(device->getOSOperator()->getProcessorSpeedMHz(&cpu))
		{
			strxml+=cpu;
			strxml+=L" MHz";
		}
		else
			strxml+="not available";
	}

	{                             //print the available RAM memory/Total RAM memory
		irr::u32 tot=0,av=0;
		strxml+=L"\n\t\tMemory available: ";
		if(device->getOSOperator()->getSystemMemory(&tot,&av))
		{

			strxml+=av;
			strxml+=" / ";
			strxml+=tot;
			strxml+=" KiloBytes";
		}
		else
			strxml+="not available\n";

	}

	{								//print the irrlicht engine version
		strxml+=L"\n\t\tIrrlicht version: ";
		strxml+=device->getVersion();
		strxml+=L" (Irrlicht is Copyright (C) by Nikolaus Gebhardt)";
	}

	strxml+=L"\n";
	xml->writeComment(strxml.c_str());
	xml->writeLineBreak ();

	xml->writeClosingTag(L"config");
	xml->drop();
	return true;
}

void IChoiceScreen::validateXMLData() //Ok this is not a real xml validation but does some checks
{

	#ifndef _IRR_COMPILE_WITH_DIRECT3D_9_  // thanks to "greenya" for that idea.
	if(p.DriverType != irr::video::EDT_DIRECT3D9)
		p.DriverType = irr::video::EDT_OPENGL;
	#endif
	#ifndef	_IRR_COMPILE_WITH_DIRECT3D_8_
	if(p.DriverType == irr::video::EDT_DIRECT3D8)
		p.DriverType = irr::video::EDT_OPENGL;
	#endif

}

}//end of namespace "agt"

/* XML TEST FILE: this is an example "myGame_config.xml" that was generated by my code

<?xml version="1.0"?>
<config>
	<game Name="myGame" Version="0.1" Author="Dario Oliveri" License="Zlib" />
	<screen Width="800" Height="600" ColorDepth="32" FullScreen="1" />
	<options VSync="0" Shadows="0" AntiAlias="0" ShowNextTime="0" />
	<driver Type="d3d9" />

<!--supported drivers are: d3d8, d3d9, opengl, burn, software-->

<!--
	Your System Info:
		OS version: Microsoft Windows Vista Personal Service Pack 2 (Build 6002)
		CPU speed: 2000 MHz
		Memory available: 1174836 / 2097151 KiloBytes
		Irrlicht version: 1.7.1 (Irrlicht is Copyright (C) by Nikolaus Gebhardt)
-->
</config>
*/
