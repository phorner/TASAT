// Copyright (C) 2011 Dario Oliveri
// This file is part of the "IrrSolid" game engine.
// For conditions of distribution and use, see copyright notice in AGT.h

#ifndef VIDEO_MODE_UTILS_INCLUDED
#define VIDEO_MODE_UTILS_INCLUDED

#include <irrlicht.h>

namespace isgf
{

enum screenRatio
{
	SCRRATIO_ERROR = 0,
	SCRRATIO_UNKNOWN,
	SCRRATIO_4_3,
	SCRRATIO_16_9,
	SCRRATIO_15_9,
	SCRRATIO_20_9
};

typedef struct SVideoModeContainer
{
	irr::core::dimension2du  resolution;
	screenRatio				 ratio;
	irr::s32				 depth;
}VMode;

class VideoModeHelper
{
	//! provides the screen ratio of the device from wich you take the driver
	static screenRatio getScreenRatio(irr::video::IVideoDriver *driver);

};


}

#endif
