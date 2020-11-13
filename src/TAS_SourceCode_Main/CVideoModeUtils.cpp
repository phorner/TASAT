// Copyright (C) 2010-2011 Dario Oliveri
// This file is part of the "IrrSolid" game engine.
// For conditions of distribution and use, see copyright notice in AGT.h

#include "SVideoModeUtils.h"

namespace isgf
{
	screenRatio VideoModeHelper::getScreenRatio(irr::video::IVideoDriver  *driver)
	{
		irr::core::dimension2d<irr::u32> windowSize=
			driver->getScreenSize();

		if(irr::core::equals(windowSize.Height*4, windowSize.Width*3, 30))
			return SCRRATIO_4_3 ;
		if(irr::core::equals(windowSize.Height*16, windowSize.Width*9, 30))
			return SCRRATIO_16_9;
		if(irr::core::equals(windowSize.Height*15, windowSize.Width*9, 30))
			return SCRRATIO_15_9;
		if(irr::core::equals(windowSize.Height*20, windowSize.Width*9, 30))
			return SCRRATIO_20_9;
		return SCRRATIO_UNKNOWN;
	}
}
