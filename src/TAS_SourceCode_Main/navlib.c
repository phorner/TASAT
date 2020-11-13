
/*
Traveller's Aid Society Access Terminal

by Perry Horner 2001-


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


The bulk of the code is by Perry Horner (perry1@liberated-technologies.com)



Exerpt from original xssv code:
Permission to use, copy, and modify this software is granted, provided
that this copyright appears in all copies and that both this copyright
and permission notice appear in all supporting documentation, and that
the name of Mark F. Cook and/or Hewlett-Packard not be used in advertising
without specific, writen prior permission.  Neither Mark F. Cook or
Hewlett-Packard make any representations about the suitibility of this
software for any purpose.  It is provided "as is" without express or
implied warranty."


*/




void InitKnownSpace(void)
{
	
	backsurf = Galaxy;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

}

int UpdateSubSecScreen(int sectorchoice)
{
	
	int hr=0;

	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0),core::rect<s32>(0, 0, 1024, 768), 0,video::SColor(255, 255, 255, 255), true);


	DisplaySubsectorInfo(sectorchoice);

	ViewSystemNames();
	DisplaySubSector();
	

	return hr;
}



int Updatescreengalaxy(void)
{
	
	int hr=0;

	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0),core::rect<s32>(0, 0, 1024, 768), 0,video::SColor(255, 255, 255, 255), true);

	DisplayKnownSpaceLocations();


	return hr;
}

int Updatescreensec(void)
{
	int hr = 0;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);


	DisplaySector();

	
	return hr;

}

int Updatescreenfleet(void)
{
	int hr = 0;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);


	DisplayFleet();


	return hr;

}

void DisplayFleet(void)
{
	int x = 0;
	int xinc=0,yinc = 0;
	char tempshipsubsector[2];


	//if NAVFLEET display
	yinc = 20;
	xinc = 50;


	for (x = 0; x < fleetcount; x++)
	{
		if (!strncmp(tempshipsubsector, sectorfleet[x].fleetsubsector, 2))
		{
			//display fleet icon
			displayfleeticon(xinc, yinc, sectorfleet[x].fleeticon);
			//display fleet quantity
			yinc = yinc + 10;
			Courier10Yellow->draw(irr::core::stringw(sectorfleet[x].typetotal).c_str(), core::rect<s32>(xinc + 35, yinc, 0, 0), video::SColor(255, 255, 255, 255));
			//display fleet description
			Courier10LtBlue->draw(irr::core::stringw(sectorfleet[x].fleetdesc).c_str(), core::rect<s32>(xinc + 50, yinc, 0, 0), video::SColor(255, 255, 255, 255));
			yinc = yinc + 20;
			//new column
			if (yinc > 720)
			{
				yinc = 50;
				xinc = xinc + 250;
			}
		} //end if correct sector
		else {
			strncpy(tempshipsubsector, sectorfleet[x].fleetsubsector, 2);
			
			//Display Sector Name based on Sector location Letter
			switch (tempshipsubsector[0])
			{
				case 'A':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[0].second[0]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'B':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[0].second[1]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'C':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[0].second[2]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'D':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[0].second[3]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'E':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[1].second[0]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'F':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[1].second[1]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'G':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[1].second[2]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'H':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[1].second[3]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'I':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[2].second[0]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'J':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[2].second[1]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'K':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[2].second[2]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'L':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[2].second[3]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'M':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[3].second[0]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'N':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[3].second[1]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'O':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[3].second[2]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
				case 'P':{
					Optima18White->draw(irr::core::stringw(sublocnamegrid[3].second[3]).c_str(), core::rect<s32>(xinc, yinc, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
						 
			} //end switch	
			yinc = yinc + 30;
			//draw white line between sector name and fleet lists
			driver->draw2DLine(position2d<s32>(xinc, yinc-3), position2d<s32>(xinc + 70, yinc-3), SColor(255, 255, 255, 255)); //white line

			//display fleet icon
			displayfleeticon(xinc, yinc, sectorfleet[x].fleeticon);
			//display fleet quantity
			yinc = yinc + 10;
			Courier10Yellow->draw(irr::core::stringw(sectorfleet[x].typetotal).c_str(), core::rect<s32>(xinc + 35, yinc, 0, 0), video::SColor(255, 255, 255, 255));
			//display fleet description
			Courier10LtBlue->draw(irr::core::stringw(sectorfleet[x].fleetdesc).c_str(), core::rect<s32>(xinc + 50, yinc, 0, 0), video::SColor(255, 255, 255, 255));
			yinc = yinc + 20;
			
		}//end else
		//yinc = yinc + 30;
		//new column
		if (yinc > 720)
		{
			yinc = 20;
			xinc = xinc + 250;
		}
	}
}

//*********Display Fleet Icon*********************************
void displayfleeticon(int x, int y, int fleeticon)
{
	//IMPERIAL FLEET
	switch (fleeticon)
	{
	case 1:
	{	//close escort
		driver->draw2DImage(icloseescort, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 2:
	{	//system defence boat
		driver->draw2DImage(isystemdefenceboat, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 3:
	{	//Patrol Cruiser
		driver->draw2DImage(ipatrolcruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 4:
	{	//Mercenary Cruiser
		driver->draw2DImage(imerccruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 5:
	{	//Dreadnought
		driver->draw2DImage(idreadnought, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 6:
	{	//Destroyer
		driver->draw2DImage(idestroyer, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 7:
	{	//Corvette
		driver->draw2DImage(icorvette, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 8:
	{	//Tender
		driver->draw2DImage(itender, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 9:
	{	//Cruiser
		driver->draw2DImage(icruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 10:
	{	//Carrier
		driver->draw2DImage(icarrier, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 11:
	{	//Frigate
		driver->draw2DImage(ifrigate, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	//aslan
	case 12:
	{	//close escort
		driver->draw2DImage(acloseescort, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 13:
	{	//system defence boat
		driver->draw2DImage(asystemdefenceboat, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 14:
	{	//Patrol Cruiser
		driver->draw2DImage(apatrolcruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 15:
	{	//Mercenary Cruiser
		driver->draw2DImage(amerccruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 16:
	{	//Dreadnought
		driver->draw2DImage(adreadnought, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 17:
	{	//Destroyer
		driver->draw2DImage(adestroyer, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 18:
	{	//Corvette
		driver->draw2DImage(acorvette, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 19:
	{	//Tender
		driver->draw2DImage(atender, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 20:
	{	//Cruiser
		driver->draw2DImage(acruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 21:
	{	//Carrier
		driver->draw2DImage(acarrier, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 22:
	{	//Frigate
		driver->draw2DImage(afrigate, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	//vargr
	case 23:
	{	//close escort
		driver->draw2DImage(vcloseescort, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 24:
	{	//system defence boat
		driver->draw2DImage(vsystemdefenceboat, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 25:
	{	//Patrol Cruiser
		driver->draw2DImage(vpatrolcruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 26:
	{	//Mercenary Cruiser
		driver->draw2DImage(vmerccruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 27:
	{	//Dreadnought
		driver->draw2DImage(vdreadnought, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 28:
	{	//Destroyer
		driver->draw2DImage(vdestroyer, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 29:
	{	//Corvette
		driver->draw2DImage(vcorvette, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 30:
	{	//Tender
		driver->draw2DImage(vtender, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 31:
	{	//Cruiser
		driver->draw2DImage(vcruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 32:
	{	//Carrier
		driver->draw2DImage(vcarrier, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 33:
	{	//Frigate
		driver->draw2DImage(vfrigate, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 34:
	{	//Corsair
		driver->draw2DImage(vargrcorsair, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	//zhodani
	case 35:
	{	//close escort
		driver->draw2DImage(zcloseescort, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 36:
	{	//system defence boat
		driver->draw2DImage(zsystemdefenceboat, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 37:
	{	//Patrol Cruiser
		driver->draw2DImage(zpatrolcruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 38:
	{	//Mercenary Cruiser
		driver->draw2DImage(zmerccruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 39:
	{	//Dreadnought
		driver->draw2DImage(zdreadnought, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 40:
	{	//Destroyer
		driver->draw2DImage(zdestroyer, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 41:
	{	//Corvette
		driver->draw2DImage(zcorvette, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 42:
	{	//Tender
		driver->draw2DImage(ztender, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 43:
	{	//Cruiser
		driver->draw2DImage(zcruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 44:
	{	//Carrier
		driver->draw2DImage(zcarrier, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 45:
	{	//Frigate
		driver->draw2DImage(zfrigate, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}

	//Solomani
	case 46:
	{	//close escort
		driver->draw2DImage(scloseescort, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 47:
	{	//system defence boat
		driver->draw2DImage(ssystemdefenceboat, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 48:
	{	//Patrol Cruiser
		driver->draw2DImage(spatrolcruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 49:
	{	//Mercenary Cruiser
		driver->draw2DImage(smerccruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 50:
	{	//Dreadnought
		driver->draw2DImage(sdreadnought, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 51:
	{	//Destroyer
		driver->draw2DImage(sdestroyer, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 52:
	{	//Corvette
		driver->draw2DImage(scorvette, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 53:
	{	//Tender
		driver->draw2DImage(stender, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 54:
	{	//Cruiser
		driver->draw2DImage(scruiser, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 55:
	{	//Carrier
		driver->draw2DImage(scarrier, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}
	case 56:
	{	//Frigate
		driver->draw2DImage(sfrigate, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 30, 30), 0, video::SColor(255, 255, 255, 255), true);
		break;
	}

	} //end switch

}

//**************************************************************************
//*                                                                        
//*   sector information display                                         
//                                                                        
//*                                                                        
//*------------------------------------------------------------------------
//* Paul J. Netherwood  Kingston Polytechnic               | 28th Feb 1990 
//*                                                        |               
//*------------------------------------------------------------------------
//* Modification history:                                                  
//*------------------------------------------------------------------------
//* VC-SDL       by Perry Horner                           |   01-13-2000  
//*------------------------------------------------------------------------
//* VC-Irrlicht       by Perry Horner                           |   04-2016  
//*************************************************************************

void DisplaySubsectorInfo(int sectr)
{
	int size = 0, atmos = 0, pop = 0, gov = 0;
	int cloudiness = 0, i = 0, sectornumber = 0;
	int wtype=0;
	char t[81];
	char *ch;
	char stardata[81];
	char tempstellar[24];
	int TextInc = 110;   //text vertical starting value
	int tIncValue = 15;  //text increment vertical value
	int inc=0; //star number increment

	


	itemnumb = 0;

	hydro = 0;

	normal = 0;
	water = 0;
	desert = 0;
	garden = 0;
	barren = 0;
	asteroid = 0;
	hell = 0;
	ringwrld = 0;
	iceworld = 0;
	gas = 0;
	wtype = 0;

	if (sectr == 0)
	{                     //NO System info to view
		Optima18White->draw(L"Select System or Function", core::rect<s32>(710, 200, 0, 0), video::SColor(255, 255, 255, 255));
		driver->draw2DImage(idbsunlogo, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
		return;
	}


	
	for (i = 0; i<w_cnt; i++) {
		sectornumber = atoi(sec_world[i].hex);
		if (sectornumber == sectr) 
		{
			itemnumb = i; i = i + 100; 
		}
	}
	CurrentSystemLibData = itemnumb;

	Courier10Green->draw(irr::core::stringw(sec_world[itemnumb].name).c_str(), core::rect<s32>(700, 50, 0, 0), video::SColor(255, 255, 255, 255));

	Courier8White->draw(L"Map Hex Number", core::rect<s32>(700, 70, 0, 0), video::SColor(255, 255, 255, 255));
	Courier8White->draw(irr::core::stringw(sec_world[itemnumb].hex).c_str(), core::rect<s32>(820, 70, 0, 0), video::SColor(255, 255, 255, 255));
	Courier8White->draw(L"UWP:  ", core::rect<s32>(700, 90, 0, 0), video::SColor(255, 255, 255, 255));
	Courier8White->draw(irr::core::stringw(sec_world[itemnumb].uwp).c_str(), core::rect<s32>(750, 90, 0, 0), video::SColor(255, 255, 255, 255));

	
	TextInc = 110;   //text vertical starting value

	
	// starport

	Courier8White->draw(L"Starport Class:", core::rect<s32>(700, TextInc, 0, 0), video::SColor(255, 255, 255, 255));
	Courier8White->draw(irr::core::stringw(sec_world[itemnumb].Starport).c_str(), core::rect<s32>(808, TextInc, 0, 0), video::SColor(255, 255, 255, 255));
	TextInc += tIncValue;

	switch (sec_world[itemnumb].Starport[0])
	{
	case 'a':
	case 'A':
		Courier8White->draw(L"Excellent quality installation-Refined", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"fuel available.Annual maintenance overhaul", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"available.Shipyard capabable of", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"constructing starships and non-starships.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'b':
	case 'B':
		Courier8White->draw(L"Good quality installation-Refined fuel", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"available.Annual maintenance overhaul", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"available. Shipyard capabable of", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"constructing non-starships present.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'c':
	case 'C':
		Courier8White->draw(L"Routine Quality installation. Only", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"unrefined fuel available. Reasonable", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"repair facilities present.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'd': 
	case 'D':
		Courier8White->draw(L"Poor quality installation. Only", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"unrefined fuel available. No", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"repair facilities present.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'e':
	case 'E':
		Courier8White->draw(L"Frontier installation. Essentially", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"a marked spot of bedrock with no", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"fuel, facilities, or bases present.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'f':
	case 'F':
		Courier8White->draw(L"Spaceport:Good quality installation", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Only unrefined fuel available.Minor", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"repair facilities. Spaceport used", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"mainly for inter-system travel.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'g':
	case 'G':
		Courier8White->draw(L"Spaceport:Poor quality installation.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Only unrefined fuel available. No", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"repair facilities. Spaceport used", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"mainly for inter-system travel.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'h':
	case 'H':
		Courier8White->draw(L"Spaceport:Primitive Installation-", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"no facilities.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Spaceport used mainly for", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"inter-system travel.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'j':
	case 'J':
		Courier8White->draw(L"Excellent Quality Secondary", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Spaceport. Refined", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"fuel available. Annual", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"maintenance overhaul available.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'x': 	
	case 'X': 
		Courier8White->draw(L"No starport. No provision is", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"made for any ship landings.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

	case 'y':
	case 'Y':
		Courier8White->draw(L"No spaceport.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;


	default:     Courier8White->draw(L"No listed starport type.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	//ZONES
	if (sec_world[itemnumb].Zone[0] == 'R')
	{  //red zone
		Courier8Red->draw(L"RED ZONE", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].Zone[0] == 'A')
	{ //amber
		Courier8Yellow->draw(L"AMBER ZONE", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].Zone[0] == 'r')
	{  //red zone
		Courier8Red->draw(L"RED ZONE", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].Zone[0] == 'a')
	{ //amber
		Courier8Yellow->draw(L"AMBER ZONE", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	// size 
	switch (sec_world[itemnumb].uwp[0])
	{

	case '0': {
				  Courier8White->draw(L"Asteroid/Planetoid Belt", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  asteroid = 1;
				  break; 
	}

	case 'r': {
				  Courier8White->draw(L"Ring (around a world)", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  //!!!!!!!!!!NEED TO CREATE PICTURE FOR THIS KIND OF WORLD
				  break; 
	}

	case 'R': {
				  Courier8White->draw(L"Ring (around a world)", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));

				  break; 
	}

	case 's': {
				Courier8White->draw(L"Small World (200km) Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of .024 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break; 
	}

	case 'S': {
				Courier8White->draw(L"Small World (200km) Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 
				Courier8White->draw(L"of .024 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break; 
	}

	case '1': {
				Courier8White->draw(L"Small world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  Courier8White->draw(L"of .122 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  size = 1;
				  break; 
	}

	case '2': {
				Courier8White->draw(L"Small world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of .24 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 2;
				  break; 
	}

	case '3': {
				Courier8White->draw(L"Small world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of 37.7 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 3;
				  break; 
	}

	case '4': {
				Courier8White->draw(L"Small world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of .5 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 4;
				  break; 
	}

	case '5': {
				Courier8White->draw(L"Medium sized world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of .625 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 5;
				  break; 
	}

	case '6': {
				Courier8White->draw(L"Medium sized world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of .84 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 6;
				  break; 
	}

	case '7': {
				Courier8White->draw(L"Medium sized world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of .875 of a G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 7;
				break; 
	}


	case '8': {
				Courier8White->draw(L"Medium sized world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of 1 G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 8;
				  break; 
	}


	case '9': {
				Courier8White->draw(L"Large world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of 1.12 G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 9;
				  break; 
	}

	case 'a': {
				Courier8White->draw(L"Large world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of 1.25 G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 10;
				  break; 
	}

	case 'A': {
				Courier8White->draw(L"Large world. Surface gravity", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8White->draw(L"of 1.25 G", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				size = 10;
				  break; 
	}
	case 'y': {
		Courier8White->draw(L"Complete ring around star", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Possible alien origin.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'Y': {
		Courier8White->draw(L"Complete ring around", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"star. Alien origin.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	default: Courier8White->draw(L"Non-standard world size", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 
	}


		if ((sec_world[itemnumb].uwp[0] == 'r') || (sec_world[itemnumb].uwp[0] == 'R') || (sec_world[itemnumb].uwp[0] == 's') || (sec_world[itemnumb].uwp[0] == 'S'))
		{
			size = 0;
		}
	if ((sec_world[itemnumb].uwp[0] == 'y') || (sec_world[itemnumb].uwp[0] == 'Y'))
	{
		size = 35; //ringworld
	}


	if (size > 0 && size <= 10){
		sprintf(t, "World diameter is %d miles (%d km).", (size * 1000), (size * 1600));
		Courier8White->draw(irr::core::stringw(t).c_str(), core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	else
	{
		sprintf(t, "World diameter not measured.");
		Courier8White->draw(irr::core::stringw(t).c_str(), core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	// atmos 
	if ((int)(sec_world[itemnumb].uwp[1]) >= 140)
		atmos = (int)(sec_world[itemnumb].uwp[1]) - 131;
	else
		atmos = (int)(sec_world[itemnumb].uwp[1]) - 48;
	switch (sec_world[itemnumb].uwp[1])
	{
	case '0': {
		Courier8White->draw(L"No atmosphere. Vacc suit needed.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '1': {
		Courier8White->draw(L"Trace atmosphere. Vacc suit needed.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '2':{
		Courier8White->draw(L"Very thin, tainted atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Combination mask needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '3': {
		Courier8White->draw(L"Very thin atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Compressor mask needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '4': {
		Courier8White->draw(L"Thin, tainted atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Filter mask needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '5':{
		Courier8White->draw(L"Thin atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '6': {
		Courier8White->draw(L"Standard atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '7': {
		Courier8White->draw(L"Standard, tainted atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Filter mask needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '8': {
		Courier8White->draw(L"Dense atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '9': {
		Courier8White->draw(L"Dense, tainted atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Filter mask needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'a': {
		Courier8White->draw(L"Exotic atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Oxygen tanks needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  gas = 1;
				  break; 
	}

	case 'A': {
		Courier8White->draw(L"Exotic atmosphere.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Oxygen tanks needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  gas = 1;
				  break; 
	}

	case 'b': {
		Courier8White->draw(L"Corrosive atmosphere. Vacc suit", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or protective suit needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  gas = 1;
				  break; 
	}

	case 'B': {
		Courier8White->draw(L"Corrosive atmosphere. Vacc suit", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or protective suit needed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  gas = 1;
				  break; 
	}

	case 'c': {
		Courier8White->draw(L"Insidious atmosphere. Vacc suit", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or protective suit needed-", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"will only last for 2-12 hrs", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  gas = 1;
				  break; 
	}

	case 'C': {
		Courier8White->draw(L"Insidious atmosphere. Vacc suit", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or protective suit needed-", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"will only last for 2-12 hrs", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  gas = 1;
				  break; 
	}

	case 'd': {
		Courier8White->draw(L"Dense, High atmosphere. The air", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"pressure at sea (or lower)", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"levels is too great to support life,", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"but at higher altitudes,the", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"atmosphere is breathable.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break; 
	}

	case 'D': {
		Courier8White->draw(L"Dense, High atmosphere. The air", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"pressure at sea (or lower)", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"levels is too great to support life,", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"but at higher altitudes,the", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"atmosphere is breathable.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break; 
	}

	case 'e': {
		Courier8White->draw(L"The worlds surface is ellipsoidal.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Because the atmosphere remains", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"spherical,surface atmospheric", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"pressure ranges from very high at", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"the middle to very low at the ends.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Breathable bands may exist at some", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"point within the range of pressure.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break; 
	}

	case 'E': {
		Courier8White->draw(L"The worlds surface is ellipsoidal.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Because the atmosphere remains", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"spherical,surface atmospheric", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"pressure ranges from very high at", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"the middle to very low at the ends.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Breathable bands may exist at some", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"point within the range of pressure.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break; 
	}

	case 'f': {
		Courier8White->draw(L"Thin, Low atmosphere. The world is a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"large, massive one with a thin", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"atmosphere which settles in the", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"lowest levels of the terrain. As a", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"result,the atmosphere is unbreathable", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"at most altitudes,but is breathable", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"at very low atltitudes.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break; 
	}

	case 'F': {
		Courier8White->draw(L"Thin, Low atmosphere. The world is a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"large, massive one with a thin", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"atmosphere which settles in the", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"lowest levels of the terrain. As a", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"result,the atmosphere is unbreathable", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"at most altitudes,but is breathable", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"at very low atltitudes.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
				  break;
	}

	default:   Courier8White->draw(L"Non standard atmosphere classification.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 

	}

	// hydro 
	switch (sec_world[itemnumb].uwp[2])
	{
	case '0': {hydro = 0;
		Courier8White->draw(L"No free standing water.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 
		if (asteroid == 0) desert = 1;
		break; 
	}

	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': if (((sec_world[itemnumb].uwp[2]) == 'a') ||
		((sec_world[itemnumb].uwp[2]) == 'A'))
	{
				  hydro = 10;
	}
			  else
				  hydro = ((int)(sec_world[itemnumb].uwp[2]) - 48);

		sprintf(t, "%-2d percent water.", (hydro * 10));
		Courier8White->draw(irr::core::stringw(t).c_str(), core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		switch (hydro)

		{

		case 0: cloudiness = 0;
			break;

		case 1: cloudiness = 0;
			break;

		case 2: cloudiness = 10;
			break;

		case 3: cloudiness = 10;
			break;

		case 4: cloudiness = 20;
			break;

		case 5: cloudiness = 30;
			break;

		case 6: cloudiness = 40;
			break;

		case 7: cloudiness = 50;
			break;

		case 8: cloudiness = 60;
			break;


		case 9: cloudiness = 70;
			break;

		case 10: cloudiness = 70;
			break;
		} //end hydro switch

		if (atmos >= 10){
			if (cloudiness == 70){
				cloudiness = 100;
			}
			else if (cloudiness != 70){
				cloudiness += 40;
			}
		}
		else
		if (atmos < 3 && cloudiness > 20)
			cloudiness = 20;
		else
		if (atmos == 14)
			cloudiness /= 2;
		sprintf(t, "Cloud cover is %d percent", cloudiness);
		Courier8White->draw(irr::core::stringw(t).c_str(), core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;

// water world

	case 'a': {
		water = 1; desert = 0; hell = 0; iceworld = 0; garden = 0; barren = 0; asteroid = 0; gas = 0; ringwrld = 0;
		Courier8White->draw(L"No land masses.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break; 
	}

	case 'A': {
		water = 1; desert = 0; hell = 0; iceworld = 0; garden = 0; barren = 0; asteroid = 0; gas = 0; ringwrld = 0;
		Courier8White->draw(L"No land masses.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	default:  Courier8White->draw(L"Non standard hydrographics classification.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 

	}

	// pop 
	pop = ((int)(sec_world[itemnumb].uwp[3]) - 48);
	switch (sec_world[itemnumb].uwp[3])
	{
	case '0':{
		Courier8White->draw(L"No inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '1':{
		Courier8White->draw(L"Tens of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '2':{
		Courier8White->draw(L"Hundreds of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '3':{
		Courier8White->draw(L"Thousands of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '4': {
		Courier8White->draw(L"Tens of thousands of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '5': {
		Courier8White->draw(L"Hundreds of thousands of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '6': {
		Courier8White->draw(L"Millions of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '7': {
		Courier8White->draw(L"Tens of millions of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '8': {
		Courier8White->draw(L"Hundreds of millions of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '9': {
		Courier8White->draw(L"Billions of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'a': {
		Courier8White->draw(L"Tens of billions of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		pop = 10;
		break;
	}
	case 'A': {
		Courier8White->draw(L"Tens of billions of inhabitants.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		pop = 10;
		break;
	}

	default: 	Courier8White->draw(L"Non-standard population classification.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 
	
	}



	// Government 
	gov = ((int)(sec_world[itemnumb].uwp[4]) - 48);
	switch (sec_world[itemnumb].uwp[4])
	{
	case '0':{
		Courier8White->draw(L"No government structure. In many cases,", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"family bonds predominate.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '1':{
		Courier8White->draw(L"Company/Corporation. Government by a company", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"managerial elite;citizens are employees.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '2':{
		Courier8White->draw(L"Participating Democracy. Government by", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"advice and consent of the citizen.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '3':{
		Courier8White->draw(L"Self-Perpetuating Oligarchy. Government", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by a restricted minority, with", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"little or no input from the masses.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '4':{
		Courier8White->draw(L"Representative Democracy. Government", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by elected representatives.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '5': {
		Courier8White->draw(L"Feudal Technocracy. Government by specific", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"individuals for those who agree to be ruled.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Relationships are based on peformance of", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"technical activities which are mutually", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"beneficial.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
		//maxtextinc at this moment could be 570
	}

	case '6': {
		Courier8White->draw(L"Captive Government. Government by a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"leadership answerable to an outside", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"group; a colony or conqured area.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '7': {
		Courier8White->draw(L"Balcanization. No central ruling authority", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"exists;rival governments compete for", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"control.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '8': {
		Courier8White->draw(L"Civil Service Bureaucracy. Government by", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"agencies employing individuals selected", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"for their expertise.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '9': {
		Courier8White->draw(L"Impersonal Bureaucracy.Government by", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"agencies which are insulated from the", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"governed.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'a': {
		Courier8White->draw(L"Charismatic Dictator. Government by a single", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"leader enjoying the confidence of citizens.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'A': {
		Courier8White->draw(L"Charismatic Dictator. Government by a single", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"leader enjoying the confidence of citizens.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'b': {
		Courier8White->draw(L"Non-Charismatic Dictator. A previous", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"charismatic dictator has been replaced", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by a leader through normal channels.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'B': {
		Courier8White->draw(L"Non-Charismatic Dictator. A previous", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"charismatic dictator has been replaced", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by a leader through normal channels.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'c': {
		Courier8White->draw(L"Charismatic Oligarchy. Government by a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"selected group, organisation, or class", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"enjoying the overwhelming confidence", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"of the citizenry.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'C': {
		Courier8White->draw(L"Charismatic Oligarchy. Government by a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"selected group, organisation, or class", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"enjoying the overwhelming confidence", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"of the citizenry.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'd': {
		Courier8White->draw(L"Religious Dictatorship. Government by a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"religious organisation without regard", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"to the needs of the citizenry.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'D': {
		Courier8White->draw(L"Religious Dictatorship. Government by a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"religious organisation without regard", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"to the needs of the citizenry.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'e': {
		Courier8White->draw(L"Religious Autocracy. Government by a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"single religious leader having absolute", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"power over the citizenry.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'E': {
		Courier8White->draw(L"Religious Autocracy. Government by a", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"single religious leader having absolute", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"power over the citizenry.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'f': {
		Courier8White->draw(L"Totalitarian Oligarchy. Government by an", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"all-powerful minority which maintains absolute", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"control through widespread coercion and oppression.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'F': {
		Courier8White->draw(L"Totalitarian Oligarchy. Government by an", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"all-powerful minority which maintains absolute", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"control through widespread coercion and oppression.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'g': {
		Courier8White->draw(L"Small Station or Facility. Either operated", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by an off-world clan or controlled by an Aslan", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"company.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'G': {
		Courier8White->draw(L"Small Station or Facility. Either operated", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by an off-world clan or controlled by an Aslan", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"company.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'x': {
		Courier8White->draw(L"Droyne Hierarchy. Established communities", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"are ruled by hereditary and long-established", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"governments.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'X': {
		Courier8White->draw(L"Droyne Hierarchy. Established communities", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"are ruled by hereditary and long-established", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"governments.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'm': {
		Courier8White->draw(L"Military Dictatorship. Government by the armed", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"forces as an interim survival measure or", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"result of a Coup.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'M': {
		Courier8White->draw(L"Military Dictatorship. Government by the armed", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"forces as an interim survival measure or", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"result of a Coup.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'q': {
		Courier8White->draw(L"Interim Government. The world is ruled", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by a temporary government (which may have", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"been in power for some time).", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'Q': {
		Courier8White->draw(L"Interim Government. The world is ruled", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"by a temporary government (which may have", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"been in power for some time).", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 's': {
		Courier8White->draw(L"Slave World. The world’s government is ineffectual", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or non-existent. The populace survives by", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"offering tribute or slaves to an outside power.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'S': {
		Courier8White->draw(L"Slave World. The world’s government is ineffectual", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or non-existent. The populace survives by", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"offering tribute or slaves to an outside power.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 't': {
		Courier8White->draw(L"Technologically Elevated Dictator. A leader", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or small group holds power through the use", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"of relic technology.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'T': {
		Courier8White->draw(L"Technologically Elevated Dictator. A leader", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or small group holds power through the use", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"of relic technology.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'v': {
		Courier8White->draw(L"Viral Hell. The world is run by", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"malevolent Viral Entities,", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or through a Quisling government.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case 'V': {
		Courier8White->draw(L"Viral Hell. The world is run by", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"malevolent Viral Entities,", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"or through a Quisling government.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	default: 	Courier8White->draw(L"Non-standard government classification.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 
	}

	// law 
	switch (sec_world[itemnumb].uwp[5])
	{
	case '0': {
		Courier8White->draw(L"No Law (No weapon prohibitions)", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '1': {
		Courier8White->draw(L"Low Law (Body pistols undetectable by", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"standard detectors),expolosives (bombs,", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"grenades), and poison gas prohibited.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '2': {
		Courier8White->draw(L"Low Law (Portable energy weapons (laser", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"carbine, laser rifle) prohibited. Ships", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"gunnery not affected.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '3': {
		Courier8White->draw(L"Low Law. Weapons of a strict millitary", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"nature (machine guns,automatic rifles)", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"are prohibited.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '4': {
		Courier8White->draw(L"Moderate Law. Light assault weapons (sub-", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"machine guns) prohibited.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '5': {
		Courier8White->draw(L"Moderate Law.Personal concealable firearms", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"such as pistols and revolvers prohibited.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '6': {
		Courier8White->draw(L"Moderate Law. All firearms (except shotguns)", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"are prohibited.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '7': {
		Courier8White->draw(L"Moderate Law. Shotguns are prohibited.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '8': {
		Courier8White->draw(L"High Law.Long bladed weapons(except daggers)", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"are controlled, and open possesion", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"is prohibited.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '9': {
		Courier8White->draw(L"High Law. Possession of any weapon outside", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"one's residence is prohibited.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'a': {
		Courier8White->draw(L"Extreme Law. Weapon possession prohibited.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'A': {
		Courier8White->draw(L"Extreme Law. Weapon possession prohibited.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'b': {
		Courier8White->draw(L"Extreme Law. Control of population movement.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'B': {
		Courier8White->draw(L"Extreme Law. Control of population movement.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'c': {
		Courier8White->draw(L"Extreme Law. No civil rights.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'C': {
		Courier8White->draw(L"Extreme Law. No civil rights.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'd': {
		Courier8White->draw(L"Extreme Law. Militia law enforcement.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'D': {
		Courier8White->draw(L"Extreme Law. Militia law enforcement.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'e': {
		Courier8White->draw(L"Extreme Law. Police state.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'E': {
		Courier8White->draw(L"Extreme Law. Police state.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'f': {
		Courier8White->draw(L"Extreme Law. All facets of daily", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"life rigidly controlled.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'F': {
		Courier8White->draw(L"Extreme Law. All facets of daily", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"life rigidly controlled.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'g': {
		Courier8White->draw(L"Extreme Law. Severe punishment", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"for petty infractions.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'G': {
		Courier8White->draw(L"Extreme Law. Severe punishment", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"for petty infractions.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'h': {
		Courier8White->draw(L"Extreme Law. Legalized oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"practices.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'H': {
		Courier8White->draw(L"Extreme Law. Legalized oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"practices.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'j': {
		Courier8White->draw(L"Extreme Law. Routinely oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"and restrictive.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'J': {
		Courier8White->draw(L"Extreme Law. Routinely oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"and restrictive.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'k': {
		Courier8White->draw(L"Extreme Law. Excessively oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"and restrictive.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'K': {
		Courier8White->draw(L"Extreme Law. Excessively oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"and restrictive.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'l': {
		Courier8White->draw(L"Extreme Law. Totally oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"and restrictive.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'L': {
		Courier8White->draw(L"Extreme Law. Totally oppressive", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"and restrictive.", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	default: {
		Courier8White->draw(L"Possession of any weapon is prohibited.", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	} //end switch

	// tech 

	switch (sec_world[itemnumb].uwp[7])
	{
	case '0': {
		Courier8White->draw(L"Tech Level: 0", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '1': {
		Courier8White->draw(L"Tech Level: 1", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}

	case '2': {
		Courier8White->draw(L"Tech Level: 2", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '3':{
		Courier8White->draw(L"Tech Level: 3", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '4': {
		Courier8White->draw(L"Tech Level: 4", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '5': {
		Courier8White->draw(L"Tech Level: 5", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '6': {
		Courier8White->draw(L"Tech Level: 6", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '7': {
		Courier8White->draw(L"Tech Level: 7", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '8': {
		Courier8White->draw(L"Tech Level: 8", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case '9': {
		Courier8White->draw(L"Tech Level: 9", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'a': {
		Courier8White->draw(L"Tech Level: 10", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Interstellar community", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'A': {
		Courier8White->draw(L"Tech Level: 10", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Interstellar community", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'b': {
		Courier8White->draw(L"Tech Level: 11", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'B': {
		Courier8White->draw(L"Tech Level: 11", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'c': {
		Courier8White->draw(L"Tech Level: 12", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'C': {
		Courier8White->draw(L"Tech Level: 12", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'd':  {
		Courier8White->draw(L"Tech Level: 13", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Above average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'D': {
		Courier8White->draw(L"Tech Level: 13", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Above average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'e': {
		Courier8White->draw(L"Tech Level: 14", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Above average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	} 
	case 'E': {
		Courier8White->draw(L"Tech Level: 14", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Above average Imperial tech level", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'f': {
		Courier8White->draw(L"Tech Level: 15", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Maximum Imperial technology", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'F': {
		Courier8White->draw(L"Tech Level: 15", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Maximum Imperial technology", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'g': {
		Courier8White->draw(L"Tech Level: 16", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Alien technology sometimes employed", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	case 'G': {
		Courier8White->draw(L"Tech Level: 16", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(L"Alien technology sometimes employed", core::rect<s32>(720, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		break;
	}
	default: {
		Courier8White->draw(L"Tech Level: Unknown", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	}//end switch

	// Trade classifications 

	if ((atmos >= 4) && (atmos <= 9) && (hydro >= 4) && (hydro <= 8) && (pop >= 5) && (pop <= 8))
	{
		Courier8White->draw(L"Trade Class: Agricultural", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		water = 0; desert = 0; garden = 1; barren = 0; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 0;
	}

	if (atmos < 3 && hydro < 3 && pop >= 6)
	{
		Courier8White->draw(L"Trade Class: Non-Agricultural", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		water = 0; desert = 0; garden = 0; barren = 1; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 0;
	}

	switch (atmos)
	{
	case 0:
	case 1:
	case 2:
	case 4:
	case 7:
	case 9: {
		if (pop >= 9) 	Courier8White->draw(L"Trade Class: Industrial", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		}
	} //end switch

	if (pop < 6) Courier8White->draw(L"Trade Class: Non-Industrial", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));

	if ((atmos == 6 || atmos == 8) && pop >= 6 && pop <= 8 && gov >= 4 && gov <= 9)
	{
		//check for Vargr world
		if (!strcmp(sec_world[itemnumb].allegiance, "Va") && (sec_world[itemnumb].uwp[5] == 7))
		{
			// Vargr world not allowed Rich classification
		}
		else{
			if (sec_world[itemnumb].uwp[5] == 7)
			{
				Courier8White->draw(L"Trade Class: Rich", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			}
		}
	}

	if (atmos >= 2 && atmos <= 5 && hydro < 3)
	{
		Courier8White->draw(L"Trade Class: Poor", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (atmos == 0)
	{
		water = 0; desert = 0; garden = 0; barren = 1; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Vacuum", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].WorldType == Plnt_ASTEROID)
	{
		asteroid = 1; barren = 0; water = 0; desert = 0; gas = 0; normal = 0, hell = 0, ringwrld = 0; garden = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Asteroid Belt", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].WorldType == Plnt_ICEWORLD)
	{
		water = 0; desert = 0; garden = 0; barren = 0; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 1;
		Courier8White->draw(L"World Type: Frozen", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].WorldType == Plnt_GARDEN)
	{
		water = 0; desert = 0; garden = 1; barren = 0; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Garden", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255)); 
	}
	if (sec_world[itemnumb].WorldType == Plnt_WATER)
	{
		water = 1; desert = 0; garden = 0; barren = 0; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Water", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	if (sec_world[itemnumb].WorldType == Plnt_BARREN)
	{
		water = 0; desert = 0; garden = 0; barren = 1; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Barren", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	if (sec_world[itemnumb].WorldType == Plnt_DESERT)
	{
		water = 0; desert = 1; garden = 0; barren = 0; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Desert", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].WorldType == Plnt_HELLWORLD)
	{
		water = 0; desert = 0; garden = 0; barren = 0; asteroid = 0; gas = 0; normal = 0; hell = 1; ringwrld = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Hellworld", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].WorldType == Plnt_RINGWORLD)
	{
		water = 0; desert = 0; garden = 0; barren = 0; asteroid = 0; gas = 0; normal = 0; hell = 0; ringwrld = 1; iceworld = 0;
		Courier8White->draw(L"World Type: Ringworld", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (sec_world[itemnumb].WorldType == Plnt_NORMAL)
	{
		water = 0; desert = 0; garden = 0; barren = 0; asteroid = 0; gas = 0; normal = 1; hell = 0; ringwrld = 0; iceworld = 0;
		Courier8White->draw(L"World Type: Normal", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}



	//allegiance

	Courier8White->draw(irr::core::stringw(sec_world[itemnumb].allegiancefull).c_str(), core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));

	//ice
	icecap = 0;
	if ((atmos == 0 || atmos == 1) && hydro >0)
	{
		Courier10Green->draw(L"Ice Capped", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
		icecap = 1;
	}
	//gas giant
	if (sec_world[itemnumb].GasGiant > 0)
	{
		Courier10Green->draw(L"Gas Giant Present", core::rect<s32>(890, 113, 0, 0), video::SColor(255, 255, 255, 255));
	}



	//REMARK1

	//Data Repository
	if (!strcmp(sec_world[itemnumb].remark1, "Ab"))
	{
		Courier10LtBlue->draw(L"Data Repository", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Satellite
	if (!strcmp(sec_world[itemnumb].remark1, "Sa"))
	{
		Courier10LtBlue->draw(L"Satellite", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Colony
	if (!strcmp(sec_world[itemnumb].remark1, "Cy"))
	{
		Courier10LtBlue->draw(L"Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Sector Capital
	if (!strcmp(sec_world[itemnumb].remark1, "Cs"))
	{
		Courier10LtBlue->draw(L"Sector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Reserve
	if (!strcmp(sec_world[itemnumb].remark1, "Re"))
	{
		Courier10LtBlue->draw(L"Reserve", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Penal Colony
	if (!strcmp(sec_world[itemnumb].remark1, "Pe"))
	{
		Courier10LtBlue->draw(L"Penal Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//mining
	if (!strcmp(sec_world[itemnumb].remark1, "Mi"))
	{
		Courier10LtBlue->draw(L"Mining", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//ancients site
	if (!strcmp(sec_world[itemnumb].remark1, "An"))
	{
		Courier10LtBlue->draw(L"Ancients Site", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//farming
	if (!strcmp(sec_world[itemnumb].remark1, "Fa"))
	{
		Courier10LtBlue->draw(L"Farming", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Subsector Capital
	if (!strcmp(sec_world[itemnumb].remark1, "Cp"))
	{
		Courier10LtBlue->draw(L"Subsector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Capital
	if (!strcmp(sec_world[itemnumb].remark1, "Cx"))
	{
		Courier10LtBlue->draw(L"Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Exile Camp
	if (!strcmp(sec_world[itemnumb].remark1, "Ex"))
	{
		Courier10LtBlue->draw(L"Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Military Rule
	if (!strcmp(sec_world[itemnumb].remark1, "Mr"))
	{
		Courier10LtBlue->draw(L"Military Rule", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison Camp
	if (!strcmp(sec_world[itemnumb].remark1, "Pr"))
	{
		Courier10LtBlue->draw(L"Prison Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison, Exile Camp
	if (!strcmp(sec_world[itemnumb].remark1, "Px"))
	{
		Courier10LtBlue->draw(L"Prison, Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Research Station
	if (!strcmp(sec_world[itemnumb].remark1, "Rs"))
	{
		Courier10LtBlue->draw(L"Research Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Xboat Station

	if (!strcmp(sec_world[itemnumb].remark1, "Xb"))
	{
		Courier10LtBlue->draw(L"Xboat Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}




	//REMARK2
	//Data Repository
	if (!strcmp(sec_world[itemnumb].remark2, "Ab"))
	{
		Courier10LtBlue->draw(L"Data Repository", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Satellite
	if (!strcmp(sec_world[itemnumb].remark2, "Sa"))
	{
		Courier10LtBlue->draw(L"Satellite", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Colony
	if (!strcmp(sec_world[itemnumb].remark2, "Cy"))
	{
		Courier10LtBlue->draw(L"Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Sector Capital
	if (!strcmp(sec_world[itemnumb].remark2, "Cs"))
	{
		Courier10LtBlue->draw(L"Sector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Reserve
	if (!strcmp(sec_world[itemnumb].remark2, "Re"))
	{
		Courier10LtBlue->draw(L"Reserve", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Penal Colony
	if (!strcmp(sec_world[itemnumb].remark2, "Pe"))
	{
		Courier10LtBlue->draw(L"Penal Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//mining
	if (!strcmp(sec_world[itemnumb].remark2, "Mi"))
	{
		Courier10LtBlue->draw(L"Mining", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//ancients site
	if (!strcmp(sec_world[itemnumb].remark2, "An"))
	{
		Courier10LtBlue->draw(L"Ancients Site", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//farming
	if (!strcmp(sec_world[itemnumb].remark2, "Fa"))
	{
		Courier10LtBlue->draw(L"Farming", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Subsector Capital
	if (!strcmp(sec_world[itemnumb].remark2, "Cp"))
	{
		Courier10LtBlue->draw(L"Subsector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Capital
	if (!strcmp(sec_world[itemnumb].remark2, "Cx"))
	{
		Courier10LtBlue->draw(L"Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Exile Camp
	if (!strcmp(sec_world[itemnumb].remark2, "Ex"))
	{
		Courier10LtBlue->draw(L"Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Military Rule
	if (!strcmp(sec_world[itemnumb].remark2, "Mr"))
	{
		Courier10LtBlue->draw(L"Military Rule", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison Camp
	if (!strcmp(sec_world[itemnumb].remark2, "Pr"))
	{
		Courier10LtBlue->draw(L"Prison Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison, Exile Camp
	if (!strcmp(sec_world[itemnumb].remark2, "Px"))
	{
		Courier10LtBlue->draw(L"Prison, Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Research Station
	if (!strcmp(sec_world[itemnumb].remark2, "Rs"))
	{
		Courier10LtBlue->draw(L"Research Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Xboat Station

	if (!strcmp(sec_world[itemnumb].remark2, "Xb"))
	{
		Courier10LtBlue->draw(L"Xboat Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	//REMARK3
	//Data Repository
	if (!strcmp(sec_world[itemnumb].remark3, "Ab"))
	{
		Courier10LtBlue->draw(L"Data Repository", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Satellite
	if (!strcmp(sec_world[itemnumb].remark3, "Sa"))
	{
		Courier10LtBlue->draw(L"Satellite", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Colony
	if (!strcmp(sec_world[itemnumb].remark3, "Cy"))
	{
		Courier10LtBlue->draw(L"Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Sector Capital
	if (!strcmp(sec_world[itemnumb].remark3, "Cs"))
	{
		Courier10LtBlue->draw(L"Sector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Reserve
	if (!strcmp(sec_world[itemnumb].remark3, "Re"))
	{
		Courier10LtBlue->draw(L"Reserve", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Penal Colony
	if (!strcmp(sec_world[itemnumb].remark3, "Pe"))
	{
		Courier10LtBlue->draw(L"Penal Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//mining
	if (!strcmp(sec_world[itemnumb].remark3, "Mi"))
	{
		Courier10LtBlue->draw(L"Mining", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//ancients site
	if (!strcmp(sec_world[itemnumb].remark3, "An"))
	{
		Courier10LtBlue->draw(L"Ancients Site", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//farming
	if (!strcmp(sec_world[itemnumb].remark3, "Fa"))
	{
		Courier10LtBlue->draw(L"Farming", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Subsector Capital
	if (!strcmp(sec_world[itemnumb].remark3, "Cp"))
	{
		Courier10LtBlue->draw(L"Subsector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Capital
	if (!strcmp(sec_world[itemnumb].remark3, "Cx"))
	{
		Courier10LtBlue->draw(L"Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Exile Camp
	if (!strcmp(sec_world[itemnumb].remark3, "Ex"))
	{
		Courier10LtBlue->draw(L"Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Military Rule
	if (!strcmp(sec_world[itemnumb].remark3, "Mr"))
	{
		Courier10LtBlue->draw(L"Military Rule", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison Camp
	if (!strcmp(sec_world[itemnumb].remark3, "Pr"))
	{
		Courier10LtBlue->draw(L"Prison Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison, Exile Camp
	if (!strcmp(sec_world[itemnumb].remark3, "Px"))
	{
		Courier10LtBlue->draw(L"Prison, Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Research Station
	if (!strcmp(sec_world[itemnumb].remark3, "Rs"))
	{
		Courier10LtBlue->draw(L"Research Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Xboat Station

	if (!strcmp(sec_world[itemnumb].remark3, "Xb"))
	{
		Courier10LtBlue->draw(L"Xboat Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	//REMARK4
	//Data Repository
	if (!strcmp(sec_world[itemnumb].remark4, "Ab"))
	{
		Courier10LtBlue->draw(L"Data Repository", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Satellite
	if (!strcmp(sec_world[itemnumb].remark4, "Sa"))
	{
		Courier10LtBlue->draw(L"Satellite", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Colony
	if (!strcmp(sec_world[itemnumb].remark4, "Cy"))
	{
		Courier10LtBlue->draw(L"Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Sector Capital
	if (!strcmp(sec_world[itemnumb].remark4, "Cs"))
	{
		Courier10LtBlue->draw(L"Sector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Reserve
	if (!strcmp(sec_world[itemnumb].remark4, "Re"))
	{
		Courier10LtBlue->draw(L"Reserve", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Penal Colony
	if (!strcmp(sec_world[itemnumb].remark4, "Pe"))
	{
		Courier10LtBlue->draw(L"Penal Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//mining
	if (!strcmp(sec_world[itemnumb].remark4, "Mi"))
	{
		Courier10LtBlue->draw(L"Mining", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//ancients site
	if (!strcmp(sec_world[itemnumb].remark4, "An"))
	{
		Courier10LtBlue->draw(L"Ancients Site", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//farming
	if (!strcmp(sec_world[itemnumb].remark4, "Fa"))
	{
		Courier10LtBlue->draw(L"Farming", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Subsector Capital
	if (!strcmp(sec_world[itemnumb].remark4, "Cp"))
	{
		Courier10LtBlue->draw(L"Subsector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Capital
	if (!strcmp(sec_world[itemnumb].remark4, "Cx"))
	{
		Courier10LtBlue->draw(L"Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Exile Camp
	if (!strcmp(sec_world[itemnumb].remark4, "Ex"))
	{
		Courier10LtBlue->draw(L"Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Military Rule
	if (!strcmp(sec_world[itemnumb].remark4, "Mr"))
	{
		Courier10LtBlue->draw(L"Military Rule", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison Camp
	if (!strcmp(sec_world[itemnumb].remark4, "Pr"))
	{
		Courier10LtBlue->draw(L"Prison Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison, Exile Camp
	if (!strcmp(sec_world[itemnumb].remark4, "Px"))
	{
		Courier10LtBlue->draw(L"Prison, Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Research Station
	if (!strcmp(sec_world[itemnumb].remark4, "Rs"))
	{
		Courier10LtBlue->draw(L"Research Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Xboat Station

	if (!strcmp(sec_world[itemnumb].remark4, "Xb"))
	{
		Courier10LtBlue->draw(L"Xboat Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}

	//REMARK5
	//Data Repository
	if (!strcmp(sec_world[itemnumb].remark5, "Ab"))
	{
		Courier10LtBlue->draw(L"Data Repository", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Satellite
	if (!strcmp(sec_world[itemnumb].remark5, "Sa"))
	{
		Courier10LtBlue->draw(L"Satellite", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Colony
	if (!strcmp(sec_world[itemnumb].remark5, "Cy"))
	{
		Courier10LtBlue->draw(L"Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Sector Capital
	if (!strcmp(sec_world[itemnumb].remark5, "Cs"))
	{
		Courier10LtBlue->draw(L"Sector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Reserve
	if (!strcmp(sec_world[itemnumb].remark5, "Re"))
	{
		Courier10LtBlue->draw(L"Reserve", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Penal Colony
	if (!strcmp(sec_world[itemnumb].remark5, "Pe"))
	{
		Courier10LtBlue->draw(L"Penal Colony", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//mining
	if (!strcmp(sec_world[itemnumb].remark5, "Mi"))
	{
		Courier10LtBlue->draw(L"Mining", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//ancients site
	if (!strcmp(sec_world[itemnumb].remark5, "An"))
	{
		Courier10LtBlue->draw(L"Ancients Site", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//farming
	if (!strcmp(sec_world[itemnumb].remark5, "Fa"))
	{
		Courier10LtBlue->draw(L"Farming", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Subsector Capital
	if (!strcmp(sec_world[itemnumb].remark5, "Cp"))
	{
		Courier10LtBlue->draw(L"Subsector Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Capital
	if (!strcmp(sec_world[itemnumb].remark5, "Cx"))
	{
		Courier10LtBlue->draw(L"Capital", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Exile Camp
	if (!strcmp(sec_world[itemnumb].remark5, "Ex"))
	{
		Courier10LtBlue->draw(L"Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Military Rule
	if (!strcmp(sec_world[itemnumb].remark5, "Mr"))
	{
		Courier10LtBlue->draw(L"Military Rule", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison Camp
	if (!strcmp(sec_world[itemnumb].remark5, "Pr"))
	{
		Courier10LtBlue->draw(L"Prison Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Prison, Exile Camp
	if (!strcmp(sec_world[itemnumb].remark5, "Px"))
	{
		Courier10LtBlue->draw(L"Prison, Exile Camp", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Research Station
	if (!strcmp(sec_world[itemnumb].remark5, "Rs"))
	{
		Courier10LtBlue->draw(L"Research Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}
	//Xboat Station

	if (!strcmp(sec_world[itemnumb].remark5, "Xb"))
	{
		Courier10LtBlue->draw(L"Xboat Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
	}


		//bases
		switch (sec_world[itemnumb].Base[0])
		{

		case 'A': {
			//naval base and scout base
			Courier10Green->draw(L"Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Scout base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'B': {
			//naval base and scout way station
			Courier10Green->draw(L"Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Scout Way Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'C': { //vargr corsair base
			Courier10Green->draw(L"Vargr Corsair base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'D': { //naval depot
			Courier10Green->draw(L"Naval depot", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'E': { //Embassy center
			Courier10Green->draw(L"Embassy Center", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'F': { //Scout Way Station and Minor Naval Base
			Courier10Green->draw(L"Scout Way Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Minor Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'G': { //Vargr naval base
			Courier10Green->draw(L"Vargr Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'H': { //vargr corsair and naval base
			Courier10Green->draw(L"Vargr Corsair base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Vargr Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'J': { //naval base
			Courier10Green->draw(L"Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'K': { //Naval Base and Planetary Base
			Courier10Green->draw(L"Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Planetary base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'L': { //Minor Naval Base
			Courier10Green->draw(L"Minor Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'M': { //military base and Minor Naval Base
			Courier10Green->draw(L"Military base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Minor Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'N': { //naval base
			Courier10Green->draw(L"Naval base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'O': { //Naval outpost
			Courier10Green->draw(L"Naval Outpost", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'P': { //Planetary Base
			Courier10Green->draw(L"Planetary base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'Q': { //Planetary Base and Corsair Base
			Courier10Green->draw(L"Planetary base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Vargr Corsair base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'R': { //Scout Base and Planetary Base
			Courier10Green->draw(L"Scout base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Planetary base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'S': { //Scout base
			Courier10Green->draw(L"Scout base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'T': { //Aslan Tlauku base
			Courier10Green->draw(L"Aslan Tlauku base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'U': { //Aslan clan base and Tlauku
			Courier10Green->draw(L"Aslan Clan base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Aslan Tlauku base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'V': { //scout exploration base
			Courier10Green->draw(L"Scout Exploration base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'W': { //scout way station
			Courier10Green->draw(L"Scout Way Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'X': { //Scout Way Station and Planetary Base 
			Courier10Green->draw(L"Scout Way Station", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(L"Planetary base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'Y': { //Zhodani depot
			Courier10Green->draw(L"Zhodani Depot", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		case 'Z': { //Zhodani base
			Courier10Green->draw(L"Zhodani base", core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			break;
		}
		default:
			break;
		}

	//************Star/stellar data display

	//PutString(backsurf, 700, TextInc += tIncValue, sec_world[itemnumb].stars);
	sprintf(tempstellar, "%s", sec_world[itemnumb].stars);
	ch = '\0';
	ch = (char *)malloc(28 * sizeof (*ch)); //stars

	ch = strtok(tempstellar, " ");
	inc = 1;
	while (ch != NULL)  //start while for star data
	{
			sprintf(stardata, "Star %d Temperature: %s", inc, ch);
			Courier8White->draw(irr::core::stringw(stardata).c_str(), core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));
			sprintf(stardata, "%s", ch);
			if (stardata[0] == '0') Courier8White->draw(L"Blue >33000K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255));
			if (stardata[0] == 'O') Courier8White->draw(L"Blue >33000K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'B') Courier8White->draw(L"Blue-White 10000-33000K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'A') Courier8White->draw(L"Blue-White 7500-10000K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'F') Courier8White->draw(L"Yellow-White 6000-7500K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'G') Courier8White->draw(L"Yellow 5200-6000K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'K') Courier8White->draw(L"Orange 3700-5200K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'M') Courier8White->draw(L"Red 2000-3700K", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'Q') Courier8White->draw(L"Neutron Star", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (stardata[0] == 'X') Courier8White->draw(L"Black Hole", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if ((stardata[0] == 'B') && (stardata[1] == 'H')) Courier8White->draw(L"Black Hole", core::rect<s32>(855, TextInc, 0, 0), video::SColor(255, 255, 255, 255));

			ch=strtok(NULL, " ");
			sprintf(stardata, "Star %d Size:%s",inc, ch);
			Courier8White->draw(irr::core::stringw(stardata).c_str(), core::rect<s32>(700, TextInc += tIncValue, 0, 0), video::SColor(255, 255, 255, 255));

			if (!strcmp(stardata, "0")) Courier8White->draw(L"Bright Hypergiant", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "O")) Courier8White->draw(L"Bright Hypergiant", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "I")) Courier8White->draw(L"Supergiant", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "II")) Courier8White->draw(L"Bright Giant", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "III")) Courier8White->draw(L"Regular Giant", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "IV")) Courier8White->draw(L"Sub-Giant", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "V")) Courier8White->draw(L"Main Sequence Star", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "D")) Courier8White->draw(L"White Dwarf", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			if (!strcmp(stardata, "VI")) Courier8White->draw(L"Sub-dwarf", core::rect<s32>(810, TextInc, 0, 0), video::SColor(255, 255, 255, 255)); 
			
			inc++;
			ch = strtok(NULL, " ");

	}  //end while for star data


	//display if libdata is available
	if (istherelibdata > 0){
		driver->draw2DImage(idblibdataavailable, core::position2d<s32>(890, 615), core::rect<s32>(0, 0, 87, 32), 0, video::SColor(255, 255, 255, 255), true);
	}

	//display picture of planet
	if (sec_world[itemnumb].WorldType == Plnt_ASTEROID) driver->draw2DImage(planetpicasteroid, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_GARDEN) driver->draw2DImage(planetpicgarden, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_WATER) driver->draw2DImage(planetpicwater, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_BARREN) driver->draw2DImage(planetpicbarren, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_NORMAL) driver->draw2DImage(planetpicnormal, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_DESERT) driver->draw2DImage(planetpicdesert, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_HELLWORLD) driver->draw2DImage(planetpichell, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_RINGWORLD) driver->draw2DImage(planetpicring, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
	if (sec_world[itemnumb].WorldType == Plnt_ICEWORLD) driver->draw2DImage(planetpicfrozen, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);

	// black hole
	sprintf(tempstellar, "%s", sec_world[itemnumb].stars);
	ch = '\0';
	if (strlen(tempstellar) > 0)
	{
		ch = (char *)malloc(28 * sizeof(*ch)); //stars
		ch = strtok(tempstellar, " ");
		sprintf(stardata, "%s", ch);
		if ((stardata[0] == 'X') || ((stardata[0] == 'B') && (stardata[1] == 'H')))
		{
			driver->draw2DImage(planetpicblackhole, core::position2d<s32>(902, 7), core::rect<s32>(0, 0, 100, 100), 0, video::SColor(255, 255, 255, 255), true);
		}
	}



	//if (gas == 1) SDL_BlitSurface(planetpicgas, NULL, backsurf, &destimage);
	size = 0; atmos = 0; hydro = 0; pop = 0; gov = 0;
	cloudiness = 0; i = 0; sectornumber = 0; itemnumb = 0; TextInc = 0;
	wtype = 0;

	ch = '\0';
	
}






/*****************************************************************************
*                                                                           *
* Routine:  AssignPoliticalBoarders                                         *
*                                                                           *
* Purpose:  This routine reads a static border element from the datafile    *
*           and converts it into an Xsegment containing absolute values     *
*           for those endpoints.  Each segment listed in the datefile has   *
*           the following format (starting in column 0):                    *
*                                                                           *
*                 ^nnnn m                                                   *
*                                                                           *
*           Following the carat (^), the nnnn value is the hex number and   *
*           the m value is the side of the hex.  Valid values for n are     *
*           1-6, with the top edge of the hex as the 6 edge, and the other  *
*           edges numbered clockwise.                                       *
*                                                                           *
*****************************************************************************/

void AssignPoliticalBoarders(char *strbord)
{
	int i=0, lx=0, ly=0, x_off=0, y_off=0, edge=0, next_edge=0;
	char bdr_hex[3], edge_char[2];

	//--- convert hex location strings & edge strings to digits 
	bdr_hex[0] = strbord[1];
	bdr_hex[1] = strbord[2];
	bdr_hex[2] = '\0';
	lx = (atoi(bdr_hex) - 1) % 8;
	bdr_hex[0] = strbord[3];
	bdr_hex[1] = strbord[4];
	bdr_hex[2] = '\0';
	ly = (atoi(bdr_hex) - 1) % 10;
	edge_char[0] = strbord[6];
	edge_char[1] = '\0';
	edge = atoi(edge_char);
	next_edge = (edge + 1) % 6;

	i = private_bdr_cnt;
	x_off = hex_loc[lx].x;
	y_off = hex_loc[lx].y + (ly * LINE_INC) + PAD;
	file_bdr_seg[i].x1 = abs_hex_pts[edge].x + x_off;
	file_bdr_seg[i].y1 = abs_hex_pts[edge].y + y_off;
	file_bdr_seg[i].x2 = abs_hex_pts[next_edge].x + x_off;
	file_bdr_seg[i].y2 = abs_hex_pts[next_edge].y + y_off;
	private_bdr_cnt++;
	
}

//******************************************************
//view subsector info


void ViewSystemNames()
{
	int i=0, x=0, y=0, xx=0, yy=0, x_ctr=0, y_ctr=0;
	int worldcntadj=0;
	char tradecnt[81];
	char subsloclttr[4];

	World *w;

	

	worldcntadj = 60;	//total number of worlds that can be displayed in list



	if (w_cnt<worldcntadj) worldcntadj = w_cnt;

	xx = 10;
	yy = 610;
	for (i = 0; i<worldcntadj; i++) {
		if (yy>750){
			yy = 610;
			xx = xx + 140;
		}
		if (xx>410) break;
		w = &sec_world[i];
		x = w->location.x;
		y = w->location.y;

		x_ctr = hex_ctr[x + HEX_PAD].x;
		y_ctr = hex_ctr[x + HEX_PAD].y + (y * LINE_INC);


		if (w->Zone[0] == 'R') {
		Courier8Red->draw(irr::core::stringw(w->hex).c_str(), core::rect<s32>(xx, yy, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8Red->draw(irr::core::stringw(sec_world[i].name).c_str(), core::rect<s32>(xx+35, yy, 0, 0), video::SColor(255, 255, 255, 255));
		} // Red zone
		else if (w->Zone[0] == 'A') {
			Courier8Yellow->draw(irr::core::stringw(w->hex).c_str(), core::rect<s32>(xx, yy, 0, 0), video::SColor(255, 255, 255, 255));
			Courier8Yellow->draw(irr::core::stringw(sec_world[i].name).c_str(), core::rect<s32>(xx+35, yy, 0, 0), video::SColor(255, 255, 255, 255));
		}// Amber zone

		else
		{
		Courier8White->draw(irr::core::stringw(w->hex).c_str(), core::rect<s32>(xx, yy, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8White->draw(irr::core::stringw(sec_world[i].name).c_str(), core::rect<s32>(xx+35, yy, 0, 0), video::SColor(255, 255, 255, 255));
		}
		yy = yy + 12;
	}
	// display subsector location letter and total trade routes

	sprintf(subsloclttr, "%s", sublocletter);
	Courier10Black->draw(L"Subsector: ", core::rect<s32>(480, 520, 0, 0), video::SColor(255, 255, 255, 255));
	Courier10Black->draw(irr::core::stringw(subsloclttr).c_str(), core::rect<s32>(570, 520, 0, 0), video::SColor(255, 255, 255, 255));

	sprintf(tradecnt, "%d", tr_cnt);
	Courier10Black->draw(L"Total Trade Routes=", core::rect<s32>(480, 560, 0, 0), video::SColor(255, 255, 255, 255));
	Courier10Black->draw(irr::core::stringw(tradecnt).c_str(), core::rect<s32>(640, 560, 0, 0), video::SColor(255, 255, 255, 255));


	Courier10Black->draw(irr::core::stringw(title).c_str(), core::rect<s32>(60, 560, 0, 0), video::SColor(255, 255, 255, 255));//sector title


	w = '\0';

}//END view subsector system names


//********************************************************
//Read subSector


void readsubsector()
{
	int done=0, i=0, atmosphere=0, hydrology=0, x_off=0, y_off=0, t=0, stInc=0;
	int tempcount = 0;
	char str[10], t_start[5], t_end[5], offset[5];

	char line[128], strfn[80];
	char subsectorfilename[101];


	World *w;


	
	done = 0;
	w_cnt = 0;
	tr_cnt = 0;
	bdr_cnt = 0;
	private_bdr_cnt = 0;
	t = 0;
	

	//init mapping charts
	for (i = 0; i<160; i++){
		t_route[i].x1 = 0;
		t_route[i].x2 = 0;
		t_route[i].y1 = 0;
		t_route[i].y2 = 0;

		bdr_seg[i].x1 = 0;
		bdr_seg[i].x2 = 0;
		bdr_seg[i].y1 = 0;
		bdr_seg[i].y2 = 0;

		file_bdr_seg[i].x1 = 0;
		file_bdr_seg[i].x2 = 0;
		file_bdr_seg[i].y1 = 0;
		file_bdr_seg[i].y2 = 0;
	}
	i = 0;

	sprintf(subsectorfilename, "%s/%d/%s", SectorDirectory, sectorfile, subsecfile);



	if (!(fd = fopen(subsectorfilename, "r"))){
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load %s\n", subsectorfilename);
		fclose(ERR);
		return;
	}

	while ((w_cnt < 80) && (tr_cnt < 80) && (done<1)) {
		fgets(line, 128, fd);
		if (feof(fd) != 0) done = 1;
		if (line[0] == '#')
			continue;
		if (line[0] == '@') {
			t = strlen(&line[1]);
			strncpy(title, "                                                                 ", 65);
			strncpy(title, &line[1], t - 1);
			continue;
		}

		if (line[0] == '^') {
			AssignPoliticalBoarders(line);
			continue;
		}
		if (line[0] == '$') {
			//--- get trade route segment ---
			strncpy(t_start, &line[1], 4);
			strncpy(t_end, &line[6], 4);
			strncpy(offset, &line[11], 4);
			t_start[4] = '\0';
			t_end[4] = '\0';
			offset[4] = '\0';
			strncpy(str, t_start, 2);
			str[2] = '\0';
			t_route[tr_cnt].x1 = (atoi(str) - 1) % 8;
			strncpy(str, &(t_start[2]), 2);
			str[2] = '\0';
			t_route[tr_cnt].y1 = (atoi(str) - 1) % 10;
			strncpy(str, t_end, 2);
			str[2] = '\0';
			t_route[tr_cnt].x2 = (atoi(str) - 1) % 8;
			strncpy(str, &(t_end[2]), 2);
			str[2] = '\0';
			t_route[tr_cnt].y2 = (atoi(str) - 1) % 10;


			strncpy(str, offset, 2);
			str[2] = '\0';

			x_off = atoi(str);
			if (x_off) {
				if (x_off < 0){
					t_route[tr_cnt].x2 -= 8;
				}
				else{
					t_route[tr_cnt].x2 += 8;
				}
			}
			strncpy(str, &(offset[2]), 2);


			str[2] = '\0';
			y_off = atoi(str);
			if (y_off) {
				if (y_off < 0){
					t_route[tr_cnt].y2 -= 10;
				}
				else{
					t_route[tr_cnt].y2 += 10;
				}
			}
			tr_cnt++;
			continue;
		}


		//***********Initialize world-system information**********
		w = &sec_world[w_cnt];

		w->WorldType = 0;
		w->GasGiant = 0;
		w->Starport[0] = '\0';
		w->Base[0] = '\0';
		w->Zone[0] = '\0';
		w->NumPlanets = 0;
		w->Belts = 0;
		w->stars[0] = '\0';
		w->hex[0] = '\0';
		w->name[0] = '\0';
		w->uwp[0] = '\0';
		w->remark1[0] = '\0';
		w->remark2[0] = '\0';
		w->remark3[0] = '\0';
		w->remark4[0] = '\0';
		w->remark5[0] = '\0';
		w->allegiance[0] = '\0';
		w->allegiancefull[0] = '\0';
		w->xmousepoint = 0;
		w->ymousepoint = 0;
		w->location.x = 0;
		w->location.y = 0;

		
		//--- get the world name ---
		i = 12;
		while ((line[i--] == ' ') && (i >= 0));
		if (i <= 0)
			w->name[0] = '\0';
		else  {
			strncpy(w->name, &line[0], 13);
			w->name[14] = '\0';
		}

		//--- get world hex location string ---
		strncpy(w->hex, &line[14], 4);
		w->hex[4] = '\0';

		//--- get world Starport type ---
		strncpy(w->Starport, &line[19], 1);
		w->Starport[1] = '\0';

		//--- get uwp ---
		strncpy(w->uwp, &line[20], 8);
		w->uwp[8] = '\0';

		//--- get planet size ---
		strncpy(w->size, &line[20], 1);
		w->size[1] = '\0';

		//--- get world base (Naval, Scout, etc.) type ---
		strncpy(w->Base, &line[30], 1);
		w->Base[1] = '\0';

		//--- get world remarks ---
		if (line[32] == ' ') {
			w->remark1[0] = '\0';
		}
		else {
			strncpy(w->remark1, &line[32], 2);
			w->remark1[2] = '\0';
		}
		if (line[35] == ' '){
			w->remark2[0] = '\0';
		}
		else {
			strncpy(w->remark2, &line[35], 2);
			w->remark2[2] = '\0';
		}
		if (line[38] == ' '){
			w->remark3[0] = '\0';
		}
		else {
			strncpy(w->remark3, &line[38], 2);
			w->remark3[2] = '\0';
		}
		if (line[41] == ' '){
			w->remark4[0] = '\0';
		}
		else {
			strncpy(w->remark4, &line[41], 2);
			w->remark4[2] = '\0';
		}
		if (line[44] == ' '){
			w->remark5[0] = '\0';
		}
		else {
			strncpy(w->remark5, &line[44], 2);
			w->remark5[2] = '\0';
		}


		//--- get world zone type ---
		strncpy(w->Zone, &line[48], 1);
		w->Zone[1] = '\0';

		//--- number of planets ---
		strncpy(str, &line[51], 1);
		str[1] = '\0';
		w->NumPlanets = atoi(str);

		//--- get no. of belts ---
		strncpy(str, &line[52], 1);
		str[1] = '\0';
		w->Belts = atoi(str);

		//--- get no. of Gas Giants ---
		strncpy(str, &line[53], 1);
		str[1] = '\0';
		//sec_world[w_cnt].GasGiant = atoi(str);
		w->GasGiant = atoi(str);

		
		//--- get world allegiance ---
		//strncpy(sec_world[w_cnt].allegiance, &line[55], 2);
		strncpy(w->allegiance, &line[55], 2);
		w->allegiance[2] = '\0';
		for (t = 0; t<80; t++){
			w->allegiancefull[t] = '\0';
		}
		t = 0;

		for (tempcount = 0; tempcount <= TotalAllegianceCount; tempcount++) //total amount of structure
		{
			if (!strcmp(w->allegiance, allegiance[tempcount].allegianceshort))
			{
				strncpy(w->allegiancefull, allegiance[tempcount].allegiancefull, strlen(allegiance[tempcount].allegiancefull));
				tempcount = 999;
			}
		} //end for

		
		//--- get stars ---
		strncpy(w->stars, &line[58], 28);
		w->stars[strlen(w->stars) - 1] = '\0';

		//--- convert hex string to digits ---
		strncpy(str, w->hex, 2);
		str[2] = '\0';
		w->location.x = (atoi(str) - 1) % 8;
		strncpy(str, &(w->hex[2]), 2);
		str[2] = '\0';
		w->location.y = (atoi(str) - 1) % 10;

		//--- get WorldType (GARDEN/DESERT) ---
		str[0] = line[21];
		str[1] = '\0';
		switch (str[0]) {
		case '0':
		case '1':
		case '2':
		case '3':
		{
			atmosphere = 0;
			barren = 1;
			break;
		}

		default:
		{
			atmosphere = 10;
			break;
		}
		} //end switch

		str[0] = line[22];
		str[1] = '\0';
		switch (str[0]) {
		case '0': hydrology = 0;
			break;
		default: hydrology = 10;
		}
		//********************************************
		//if ((atmosphere < 4) || (hydrology == 0))
		//*********************************************


		if ((int)(w->uwp[1]) >= 141) atmosphere = (int)(w->uwp[1]) - 131;
		else atmosphere = (int)(w->uwp[1]) - 48;

		if ((int)(w->uwp[2]) >= 141) hydrology = (int)(w->uwp[2]) - 131;
		else hydrology = (int)(w->uwp[2]) - 48;


		w->WorldType = Plnt_NORMAL; //normal world

		if ((hydrology<2) && (atmosphere == 0)){
			w->WorldType = Plnt_BARREN; //barren
		}

		if ((hydrology == 0) && (atmosphere>1) && (atmosphere<10)){
			w->WorldType = Plnt_DESERT; //desert
		}
		if ((hydrology > 0) && (hydrology <3) && (atmosphere>1) && (atoi(w->size) > 1)){
			w->WorldType = Plnt_HELLWORLD; //hellworld
		}
		if ((atmosphere >= 5) && (atmosphere <= 8) && (hydrology >= 5) && (hydrology <= 7))
		{
			w->WorldType = Plnt_GARDEN; //garden
		}	
		//Ga
		if (!strcmp(w->remark1, "Ga")){
			w->WorldType = Plnt_GARDEN; //garden
		}
		//Ga
		if (!strcmp(w->remark2, "Ga")){
			w->WorldType = Plnt_GARDEN; //garden
		}
		//Ga
		if (!strcmp(w->remark3, "Ga")){
			w->WorldType = Plnt_GARDEN; //garden
		}
		//Ga
		if (!strcmp(w->remark4, "Ga")){
			w->WorldType = Plnt_GARDEN; //garden
		}
		//Ga
		if (!strcmp(w->remark5, "Ga")){
			w->WorldType = Plnt_GARDEN; //garden
		}
		//He
		if (!strcmp(w->remark1, "He")){
			w->WorldType = Plnt_HELLWORLD; //hellworld
		}
		//He
		if (!strcmp(w->remark2, "He")){
			w->WorldType = Plnt_HELLWORLD; //hellworld
		}
		//He
		if (!strcmp(w->remark3, "He")){
			w->WorldType = Plnt_HELLWORLD; //hellworld
		}
		//He
		if (!strcmp(w->remark4, "He")){
			w->WorldType = Plnt_HELLWORLD; //hellworld
		}
		//He
		if (!strcmp(w->remark5, "He")){
			w->WorldType = Plnt_HELLWORLD; //hellworld
		}

		if ((atoi(w->size) > 4) && (atoi(w->size) < 10)&& (hydrology >= 10)){
			w->WorldType = Plnt_WATER; //water world
		}

		if (line[20] == '0'){
			w->WorldType = Plnt_ASTEROID; //asteroids
		}
		if ((atoi(w->size) > 1) && (atmosphere >= 4) && (atmosphere <= 9))
		{
			w->habitable = 1;//habitable world
		}
		//Ax
		if (!strcmp(w->remark1, "Ax")){
			w->WorldType = Plnt_RINGWORLD; //ringworld
		}
		//Ax
		if (!strcmp(w->remark2, "Ax")){
			w->WorldType = Plnt_RINGWORLD; //ringworld
		}
		//Ax
		if (!strcmp(w->remark3, "Ax")){
			w->WorldType = Plnt_RINGWORLD; //ringworld
		}
		//Ax
		if (!strcmp(w->remark4, "Ax")){
			w->WorldType = Plnt_RINGWORLD; //ringworld
		}
		//Ax
		if (!strcmp(w->remark5, "Ax")){
			w->WorldType = Plnt_RINGWORLD; //ringworld
		}

		//Fr
		if (!strcmp(w->remark1, "Fr")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark2, "Fr")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark3, "Fr")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark4, "Fr")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark5, "Ic")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}

		//Fr
		if (!strcmp(w->remark1, "Ic")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark2, "Ic")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark3, "Ic")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark4, "Ic")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}
		//Fr
		if (!strcmp(w->remark5, "Ic")){
			w->WorldType = Plnt_ICEWORLD; //frozen
		}

		w->xmousepoint = hex_ctr[(w->location.x) + HEX_PAD].x + 40;

		w->ymousepoint = hex_ctr[(w->location.x) + HEX_PAD].y +
			((w->location.y) * LINE_INC) - 12 + PAD;

		w_cnt++;

	}

	w_cnt--;

	fclose(fd);

	for (i = 0; i<80; i++){
		strfn[i] = '\0';
	}

	stInc = 0;
	for (i = 0; i <= sizeof(title); i++){
		if ((title[i] != ' ') && (title[i] != ':')){
			strfn[stInc] = title[i];
			stInc++;
		}

		else if ((title[i - 1] != ' ') && ((i - 1) >= 0)){
			strfn[stInc] = '_';
			stInc++;
		}

	}
	sprintf(tempsavefilename, "%s.bmp", strfn);
	sprintf(tempsubfname, ".\\saved\\subsector\\%s.bmp", strfn);

	w = '\0';
}



/*************************************************************************
generate sub-sector map to screen
**************************************************************************/
void DisplaySubSector()
{
	int i=0, j=0, x_ctr=0, y_ctr=0, x=0, y=0, len=0;
	int sec=0, x1start=0, x2start=0, y1start=0, y2start=0;
	int x1=0, y1=0, x2=0, y2=0;
	int PART1=0, PART2=0, STOPP=0, WC=0;
	int Blackline=0, Greyline=0, Blueline=0;
	int Blacklinealpha=0, Greylinealpha=0, Bluelinealpha=0;
	int bhflag = 0;
	char *ch;
	char stardata[81];
	char tempstellar[24];
	World *w;


	

	WC = 0;     //world count start
	PART1 = 1;
	PART2 = 0;
	STOPP = 0;
	sec = 0;


	//--- Step 1: generate the empty grid ---

	//set line color to black for hexes


	for (i = 0; i<NUM_LINES*LINE_INC; i += LINE_INC) {
		for (j = 0; j<NUM_HEXES; j++) {
		driver->draw2DLine(position2d<s32>(hex_pts[0].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[0].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), 
		position2d<s32>(hex_pts[1].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[1].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), SColor(255, 0, 0, 0)); //blackline

		driver->draw2DLine(position2d<s32>(hex_pts[1].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[1].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC),
			position2d<s32>(hex_pts[2].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[2].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), SColor(255, 0, 0, 0)); //blackline

		driver->draw2DLine(position2d<s32>(hex_pts[2].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[2].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC),
			position2d<s32>(hex_pts[3].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[3].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), SColor(255, 0, 0, 0)); //blackline

		driver->draw2DLine(position2d<s32>(hex_pts[3].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[3].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC),
			position2d<s32>(hex_pts[4].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[4].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), SColor(255, 0, 0, 0)); //blackline

		driver->draw2DLine(position2d<s32>(hex_pts[4].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[4].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC),
			position2d<s32>(hex_pts[5].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[5].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), SColor(255, 0, 0, 0)); //blackline

		driver->draw2DLine(position2d<s32>(hex_pts[5].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[5].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC),
			position2d<s32>(hex_pts[6].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[6].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), SColor(255, 0, 0, 0)); //blackline

		driver->draw2DLine(position2d<s32>(hex_pts[6].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[6].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC),
			position2d<s32>(hex_pts[0].x + hex_loc[j].x + 15 + HEXSTART_X_LOC, hex_pts[0].y + hex_loc[j].y + i - 12 + HEXSTART_Y_LOC), SColor(255, 0, 0, 0)); //blackline

		} //end for numhexes
	}  //end for line inc


	
	//--- Step 2: generate the trade-routes within the grid ---

	for (i = 0; i<tr_cnt; i++) {



		x1 = t_route[i].x1;
		y1 = t_route[i].y1;
		x2 = t_route[i].x2;
		y2 = t_route[i].y2;
		y1 = hex_ctr[x1 + HEX_PAD].y + (y1 * LINE_INC);
		x1 = hex_ctr[x1 + HEX_PAD].x;
		y2 = hex_ctr[x2 + HEX_PAD].y + (y2 * LINE_INC);
		x2 = hex_ctr[x2 + HEX_PAD].x;



		x1start = x1 + TRADE_X_ADJ;
		y1start = y1 + PAD + 8 + TRADE_Y_ADJ;
		x2start = x2 + TRADE_X_ADJ;
		y2start = y2 + PAD + 8 + TRADE_Y_ADJ;

		if (x1start<57) x1start = 57;  //make sure does not go out of bounds
		if (x2start<57) x2start = 57;
		if (x1start>428) x1start = 428;
		if (x2start>428) x2start = 428;
		if (y1start<18) y1start = 18;
		if (y2start<18) y2start = 18;
		if (y1start>540) y1start = 540;
		if (y2start>540) y2start = 540;



		//set color to grey for trade lines

		driver->draw2DLine(position2d<s32>(x1start, y1start), position2d<s32>(x2start, y2start), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x1start+1, y1start+1), position2d<s32>(x2start+1, y2start+1), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x1start, y1start), position2d<s32>(x2start, y2start+1), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x1start+1, y1start+1), position2d<s32>(x2start+1, y2start), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x1start, y1start), position2d<s32>(x2start + 1, y2start), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x1start + 1, y1start + 1), position2d<s32>(x2start, y2start+1), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x2start, y2start), position2d<s32>(x1start + 1, y1start), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x2start + 1, y2start + 1), position2d<s32>(x1start, y1start + 1), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x2start, y2start), position2d<s32>(x1start + 1, y1start), SColor(255, 128, 128, 128)); //greyline
		driver->draw2DLine(position2d<s32>(x2start + 1, y2start + 1), position2d<s32>(x1start, y1start + 1), SColor(255, 128, 128, 128)); //greyline

	} // end for loop

	if ((MarkerFlag == 1) && (MarkerSectorNumber == secloct) && (!strcmp(MarkerSubSector, sublocletter))){
		driver->draw2DImage(hexmarker, core::position2d<s32>(hexmarkerx, hexmarkery), core::rect<s32>(0, 0, 63, 53), 0, video::SColor(255, 255, 255, 255), true);
	}//display current location marker
	
	//--- Step 3: if zone borders exist, generate them ---

	if (bdr_cnt || private_bdr_cnt) {

		for (i = 0; i<private_bdr_cnt; i++){
			x1start = file_bdr_seg[i].x1 + BORDER_X_ADJ;
			y1start = file_bdr_seg[i].y1 + BORDER_Y_ADJ;
			x2start = file_bdr_seg[i].x2 + BORDER_X_ADJ;
			y2start = file_bdr_seg[i].y2 + BORDER_Y_ADJ;

			if (x1start<54) x1start = 54;  //make sure does not go out of bounds
			if (x2start<54) x2start = 54;
			if (x1start>430) x1start = 430;

			if (x2start>430) x2start = 430;
			if (y1start<18) y1start = 18;
			if (y2start<18) y2start = 18;
			if (y1start>543) y1start = 543;
			if (y2start>543) y2start = 543;

			//set color to blue for zone borders
			driver->draw2DLine(position2d<s32>(x1start, y1start), position2d<s32>(x2start, y2start), SColor(255, 0, 0, 255)); //blueline
			driver->draw2DLine(position2d<s32>(x1start+1, y1start+1), position2d<s32>(x2start+1, y2start+1), SColor(255, 0, 0, 255)); //blueline
			driver->draw2DLine(position2d<s32>(x1start-1, y1start-1), position2d<s32>(x2start-1, y2start-1), SColor(255, 0, 0, 255)); //blueline
			driver->draw2DLine(position2d<s32>(x1start, y1start + 1), position2d<s32>(x2start, y2start), SColor(255, 0, 0, 255)); //blueline
			driver->draw2DLine(position2d<s32>(x1start, y1start), position2d<s32>(x2start, y2start - 1), SColor(255, 0, 0, 255)); //blueline
		} //end for loop
	} //end if zone exists

	
	//--- Step 4: generate each system within the grid ---

	for (i = WC; i<w_cnt; i++) 
	{

		w = &sec_world[i];
		x = w->location.x;
		y = w->location.y;
		x_ctr = hex_ctr[x + HEX_PAD].x;
		y_ctr = hex_ctr[x + HEX_PAD].y + (y * LINE_INC);

		if (w->Zone[0] == 'R') 
		{  //red zone
			driver->draw2DImage(plred, core::position2d<s32>(x_ctr + 36, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 28, 28), 0, video::SColor(255, 255, 255, 255), true);
		}

		if (w->Zone[0] == 'A') 
		{ //amber
			driver->draw2DImage(plamber, core::position2d<s32>(x_ctr + 36, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 28, 28), 0, video::SColor(255, 255, 255, 255), true);
		}

		if (w->Zone[0] == 'r') 
		{  //red zone
			driver->draw2DImage(plred, core::position2d<s32>(x_ctr + 36, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 28, 28), 0, video::SColor(255, 255, 255, 255), true);
		}

		if (w->Zone[0] == 'a') 
		{ //amber
			driver->draw2DImage(plamber, core::position2d<s32>(x_ctr + 36, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 28, 28), 0, video::SColor(255, 255, 255, 255), true);
		}

		// black hole
		bhflag = 0;
		sprintf(tempstellar, "%s", w->stars);
		ch = '\0';
		if (strlen(tempstellar) > 0)
		{
			ch = (char *)malloc(28 * sizeof(*ch)); //stars
			ch = strtok(tempstellar, " ");
			sprintf(stardata, "%s", ch);
			if ((stardata[0] == 'X') || ((stardata[0] == 'B') && (stardata[1] == 'H')))
			{
				driver->draw2DImage(plblackhole, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
				bhflag = 1;
			}
		}

		if ((sec_world[i].WorldType == Plnt_ASTEROID) && (bhflag<1))
		{     //asteroids
			driver->draw2DImage(plasteroid, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
		}
			
		if ((sec_world[i].WorldType == Plnt_NORMAL) && (bhflag<1))
			{
				//regular world
				icecap = 1; //has icecaps
				driver->draw2DImage(plnormal, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}

		if ((sec_world[i].WorldType == Plnt_DESERT) && (bhflag<1))
			{
				//desert world
				driver->draw2DImage(pldesert, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}

		if ((sec_world[i].WorldType == Plnt_HELLWORLD) && (bhflag<1))
			{
				//hellworld
				driver->draw2DImage(plhellworld, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}

		if ((sec_world[i].WorldType == Plnt_GARDEN) && (bhflag<1))
			{
				driver->draw2DImage(plgarden, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}

		if ((sec_world[i].WorldType == Plnt_ICEWORLD) && (bhflag<1))
		{
			driver->draw2DImage(plfrozen, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
		}

		if ((sec_world[i].WorldType == Plnt_BARREN) && (bhflag<1))
			{     //barren
				driver->draw2DImage(plbarren, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}

		if ((sec_world[i].WorldType == Plnt_WATER) && (bhflag<1))
			{     //water
				driver->draw2DImage(plwater, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}
		if ((sec_world[i].WorldType == Plnt_RINGWORLD) && (bhflag<1))
			{     //ringworld
				driver->draw2DImage(plring, core::position2d<s32>(x_ctr - 10 + 50, y_ctr - 12 + PAD), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}


		//gas giant
		if (sec_world[i].GasGiant>0)
		{
			driver->draw2DImage(idbgas, core::position2d<s32>(x_ctr + 64, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
		}

			//bases
		switch (w->Base[0]) 
		{
		case 'A':
			{
			//navy base and scout base
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbimpscouta, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'B': 
			{
			//navy base and scout way station
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbimpscoutb, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'C':  
			{
			//vargr corsair base
			driver->draw2DImage(idbcorsair, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'D': 
			{
			//naval depot
			driver->draw2DImage(idbdepot, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'E': 
			{
			//Embassy center
			driver->draw2DImage(idbembassy, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'F': 
			{
			//Scout Way Station and Minor Naval Base
			driver->draw2DImage(idbmilbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbimpscoutb, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'G':  
			{
			//Vargr naval base
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'H':
			{
			//vargr corsair and naval base
			driver->draw2DImage(idbcorsair, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'J':
			{
			//naval base
			driver->draw2DImage(idbimpnavy, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'K':
			{
			//Naval Base and Planetary Base
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbplanetary, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'L':
			{
			//Minor Naval Base
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'M':
			{
			//military base and Minor Naval Base
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbmilbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'N':
			{
			//naval base
			driver->draw2DImage(idbnavalbase, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'O': 
			{
			//K'kree naval outpost
			driver->draw2DImage(idboutpost, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'P': 
			{
			//Planetary Base
			driver->draw2DImage(idbplanetary, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'Q': 
			{
			//Planetary Base and Corsair Base
			driver->draw2DImage(idbplanetary, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbcorsair, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'R': 
			{
			//Scout Base and Planetary Base
			driver->draw2DImage(idbimpscouta, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbplanetary, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'S':  
			{
			//Scout base
			driver->draw2DImage(idbplanetary, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'T': 
		{
			//Aslan Tlauku base
			driver->draw2DImage(idbtlaukhu, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
		}
		case 'U': 
			{ 
			//Aslan clan base and Tlauku
			driver->draw2DImage(idbtlaukhu, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbaslan, core::position2d<s32>(x_ctr + 34, y_ctr - 16 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'V': 
			{
			//scout exploration base
			driver->draw2DImage(idbimpscoutb, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'W':
			{
			//scout way station
			driver->draw2DImage(idbimpscoutb, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'X':  
			{
			//Scout Way Station and Planetary Base 
			driver->draw2DImage(idbimpscoutb, core::position2d<s32>(x_ctr + 30, y_ctr - 10 + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage(idbplanetary, core::position2d<s32>(x_ctr + 64, y_ctr + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'Y': 
			{
			//Zhodani depot
			driver->draw2DImage(idbzhodani, core::position2d<s32>(x_ctr + 64, y_ctr + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		case 'Z':  
			{
			//Zhodani base
			driver->draw2DImage(idbzhodani, core::position2d<s32>(x_ctr + 64, y_ctr + PAD), core::rect<s32>(0, 0, 5, 5), 0, video::SColor(255, 255, 255, 255), true);
			break;
			}
		default:
			break;
		}




		//hex and starports
		len = strlen(w->hex) * 8;
		Courier8Black->draw(irr::core::stringw(w->hex).c_str(), core::rect<s32>(x_ctr - (len / 2) + BORDER_X_ADJ + 3, y_ctr - 36 + PAD + BORDER_Y_ADJ + LINE_INC+1, 0, 0), video::SColor(255, 255, 255, 255));
		Courier8Black->draw(irr::core::stringw(w->Starport).c_str(), core::rect<s32>(x_ctr - 4 + BORDER_X_ADJ, y_ctr - 72 + PAD + BORDER_Y_ADJ + LINE_INC+1, 0,0), video::SColor(255, 255, 255, 255));
	} //end for loop

	w = '\0';
	if (subsectorhex<1)
	{
		driver->draw2DRectangle(video::SColor(255, 0, 0, 0), core::rect<s32>(696, 5, 880, 46));
	} //cover up marker selection until a system has been selected
}



/********************************************************/
//Read Sector


int readsector(int sectorfile)
{
	int done=0, i=0, t=0, x=0, xx=0;
	char str[10];
	char line[128];
	char *ch, *convertedtitle;
	stringw myfleetdesc, myfleetsector;
	int hexl=0, h1=0, h2=0, h3=0, xplace=0, yplace=0, xl=0, yl=0;
	int rmdr=0, stInc=0, originallen=0;
	int tempcount = 0, prevcount=0, fleetinc=0;
	char tempsectorfilename[81];
	char subsectorfilename[101];
	char tempsubsectitle[80];
	char *pattern = "SECTOR:";
	int fleetincx = 0;
	int fleetincy = 0;
	int fleetflag = 0;

	SectorData *w;

	FILE *FDW;


	sprintf(tempsectorfilename, "%s/%d", SectorDirectory, sectorfile);
	sprintf(sectorfilename, "%s/all.sec", tempsectorfilename);

	//check if the sector exhists
	fd = NULL;
	fd = fopen(sectorfilename, "r");
	if (!(fd)){
		//file does not exist
		fclose(fd);
		return -1;
	}

	//init alliance counts
	InitAllianceCounts();
	InitAllianceCodes();

	//populate sublocnamegrid[4][4] with subsector names from files
	ch = (char *)malloc(129 * sizeof(*ch)); //make space for string
	for (x = 0; x < 4; x++)
	{
		for (xx = 0; xx < 4; xx++)
		{			
			sprintf(subsectorfilename, "%s/%d/%s", SectorDirectory, sectorfile, subsectorfilegrid[x][xx]);
			if (!(FDW = fopen(subsectorfilename, "r")))
			{
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "Could not load %s\n", subsectorfilename);
				fclose(ERR);
				return 0;
			}
			while (!feof(FDW))
			{
				fgets(line, 128, FDW);
				if (line[0] == '@') //name of subsector
				{
					t = strlen(&line[12]); //jump past SUBSECTOR:

					strncpy(tempsubsectitle, &line[12], t);
					
					//Remove/chop SECTOR: title information					
					ch = '\0';					
					ch = strstr(tempsubsectitle, pattern);
					convertedtitle = tempsubsectitle;
					convertedtitle[ch - tempsubsectitle] = '\0';

					if (ch != NULL)
					{
						sprintf(tempsubsectitle, "%s\0", convertedtitle);
					}			
					tempsubsectitle[strlen(tempsubsectitle)+1] = '\0';
					if (strlen(tempsubsectitle) > 0)
					{
						strncpy(sublocnamegrid[x].second[xx], tempsubsectitle, strlen(tempsubsectitle));
						sublocnamegrid[x].second[xx][strlen(tempsubsectitle)] = '\0';
					} //end if the subsector name exists
					
				}//end if line[0]=='@'
			}//end while
			fclose(FDW);
		}//end for xx
	}//end for x


	//*****************initialize sector data**********

	w = &sec_data[s_cnt];
	w->location.x = 0;
	w->location.y = 0;
	w->Zone[0] = '\0';
	w->hex[0] = '\0';
	w->hexint = 0;
	w->allegiance[0] = '\0';
	w->xmousepoint = 0;
	w->ymousepoint = 0;


	done = 0;
	s_cnt = 0;
	tr_cnt = 0;
	bdr_cnt = 0;
	private_bdr_cnt = 0;
	t = 0;



	while ((s_cnt < 960) && (done<1)) {
		fgets(line, 128, fd);
		if (feof(fd) != 0) done = 1;
		if (line[0] == '#')
			continue;
		if (line[0] == '@') {
			t = strlen(&line[1]);
			strncpy(sectitle, "                                                                 ", 65);
			strncpy(sectitle, &line[1], t - 1);

			continue;
		}
		if (line[0] == '^') {
			AssignPoliticalBoarders(line);
			continue;
		}
		if (line[0] == '$') {

		}


		//--- get the world name ---

		i = 12;
		while ((line[i--] == ' ') && (i >= 0));


		//--- get world hex location string ---
		strncpy(w->hex, &line[14], 4);
		w->hex[4] = '\0';


		//--- get world zone type ---
		strncpy(w->Zone, &line[48], 1);
		w->Zone[1] = '\0';


		//--- get world allegiance ---
		strncpy(w->allegiance, &line[55], 2);
		w->allegiance[2] = '\0';

		//add allegiance totals for sector

		for (tempcount = 0; tempcount <= TotalAllegianceCount; tempcount++) //total amount of structure
		{
			if (!strcmp(w->allegiance, allegiance[tempcount].allegianceshort))
			{		
				prevcount = allegiance[tempcount].count;
				prevcount++;
				allegiance[tempcount].count=prevcount; //increment count

				tempcount = 999;
			}
		}


	
		//s_cnt will store the total number of systems within the sector

		//--- convert hex string to digits ---
		strncpy(str, w->hex, 2);
		str[2] = '\0';
		hexl = atoi(w->hex);
		h1 = (hexl / 100);
		h2 = h1 * 100;
		h3 = hexl - h2;
		xplace = h1;
		yplace = h3;
		xl = xplace * 12;
		yl = yplace * 12;
		rmdr = (h1 % 2);


		if (rmdr == 0){ //even
			yl = yl + 4;
		}
		if (rmdr>0){ //odd
			//...		
		}

		//add pad

		xl = xl + 100;
		yl = yl + 100;


		sec_data[s_cnt].location.x = xl;
		sec_data[s_cnt].location.y = yl;

		sec_data[s_cnt].hexint = hexl;

		sec_data[s_cnt].xmousepoint = xl;
		sec_data[s_cnt].ymousepoint = yl;


		s_cnt++;

	}
	s_cnt--;

	fclose(fd);  //close file pointer

	stInc = 0;
	for (i = 0; i<128; i++){
		line[i] = '\0';
	}
	for (i = 0; i <= sizeof(sectitle); i++){
		if ((sectitle[i] != ' ') && (sectitle[i] != ':')){
			line[stInc] = sectitle[i];
			stInc++;
		}
		else if ((sectitle[i - 1] != ' ') && ((i - 1) >= 0)){
			line[stInc] = '_';
			stInc++;
		}
	}
	sprintf(tempsavefilename, "%s.bmp", line);

	sprintf(tempsecfname, ".\\saved\\sector\\%s.bmp", line);

	w = '\0';
	sprintf(fleetfilename, "%s/%d/%s", SectorDirectory, sectorfile, "fleet.xml");

	smgr->drawAll();
	guienv->drawAll();
	driver->endScene();

	//Clear out old fleet info
	for (fleetinc = 0; fleetinc < fleetmax; fleetinc++)
	{
		sectorfleet[fleetinc].fleeticon = 0;
		sectorfleet[fleetinc].typetotal = 0;
		sprintf(sectorfleet[fleetinc].fleetdesc, "\0");
		sprintf(sectorfleet[fleetinc].fleetsubsector, "\0");
	}

	istherefleet = 0;
	if (FDW = fopen(fleetfilename, "r"))
	{
		fclose(FDW);
		//if NAVFLEET display

		istherefleet = 1;
		fleetcount = 0;
		fleetinc = 0;

		for (fleetincx = 0; fleetincx < 4; fleetincx++)
		{
			for (fleetincy = 0; fleetincy < 4; fleetincy++)
			{


				IXMLReader* xml;
				xml = device->getFileSystem()->createXMLReader(fleetfilename);

				if (fleetinc>fleetmax) fleetflag = 1;

				while (xml && (xml->read()) && fleetinc<fleetmax)
				{
					if ((core::stringw("fleet") == xml->getNodeName()) && (core::stringw(subloclettergrid[fleetincx][fleetincy]) == xml->getAttributeValueSafe(L"grid")))
					{
						sectorfleet[fleetinc].fleeticon = xml->getAttributeValueAsInt(L"shiptype");
						sectorfleet[fleetinc].typetotal = xml->getAttributeValueAsInt(L"shipcount");
						myfleetdesc = xml->getAttributeValueSafe(L"shipdesc");
						sprintf(sectorfleet[fleetinc].fleetdesc, "%ls", myfleetdesc.c_str()); //convert from wide
						sprintf(sectorfleet[fleetinc].fleetsubsector, "%s", subloclettergrid[fleetincx][fleetincy]);
						fleetcount++;
						fleetinc++;
					}//end if		
				} //end of while xml
			}//end for y
		}//end for x loop
		
		// don't forget to delete the xml reader
		//xml->drop();
	} //end if file exists



	driver->beginScene(true, true, SColor(0, 0, 0, 0));

	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
	return 0;

}


void InitKnownSpaceLocations(void)
{


	int xplace = 0, yplace = 0, xloccount = 0, yloccount = 0, secfilecounter = 0, t = 0;
	int textx = 2, texty = 590, exitflag = 0;
	char tempsectorfilename[81];
	char line[128];
	char *sectornames;


	xplace = 22; yplace = 10; xloccount = 1; yloccount = 0; //init local variables

	//*****************SUPER LOOPING OF HARD DRIVE ACCESS********FIX THIS****************
	//***********************************************************************************


	sectornames = (char*)malloc(sizeof(char)* (128));

	for (secfilecounter = 0; secfilecounter <= 197; secfilecounter++)
	{
		//*init galaxy map with numbers
		sprintf(tempsectorfilename, "%s/%d", SectorDirectory, secfilecounter);
		sprintf(sectorfilename, "%s/all.sec", tempsectorfilename);


		//check to see if sec.all file exists for directory number
		fd = fopen(sectorfilename, "r");
		if (fd){
			//read sector names
			exitflag = 0;
			while ((exitflag == 0) && (!feof(fd))) 
			{
				fgets(line, 128, fd);
				if (line[0] == '@') 
				{
					t = strlen(&line[8]);
					strncpy(sectornames, "                                                                 ", 65);
					if (t > 10)
					{
						t = 10;
					}
					strncpy(sectornames, &line[8], t - 1);
					sectornames[10] = '\0';

					exitflag = 1;
					//strncpy(sectorlocationname[secfilecounter].sectorname, &line[8], t - 1);
					strncpy(sectorlocationname[secfilecounter].sectorname, sectornames, t - 1);
					t = strlen(&line[8]); //reset length for full string
					//strncpy(sectornames, "                                                                 ", 65);
					strncpy(sectornames, &line[8], t - 1);
					strncpy(sectorlocationname[secfilecounter].fullsectorname, sectornames, t - 1);
					sectorlocationname[secfilecounter].fullsectorname[strlen(sectornames)]='\0';
				}//end if line[0]==@
			} //end while

			if (exitflag == 1)
			{
				fclose(fd);
				//if sec.all file exists, identify it with its number on space map
				sectorlocationname[secfilecounter].sectornumber = secfilecounter; //set the sector number
				sprintf(sectorlocationname[secfilecounter].sectorfilepath, "%s", sectorfilename);
				exitflag = 0;
			}//end if exitflag=1
		} //end if sector file exists (fd)
		else
		{
			strncpy(sectornames, "                                                                 ", 65);
			sectornames[10] = '\0';
			strncpy(sectorlocationname[secfilecounter].fullsectorname, sectornames, 10);
			strncpy(sectorlocationname[secfilecounter].sectorname, sectornames, 10);
			sectorlocationname[secfilecounter].fullsectorname[strlen(sectornames)] = '\0';
			sectorlocationname[secfilecounter].sectornumber = -2;

		}
	} //end for loop
} //end initknownspacelocations


/*************************************************************************
generate overlay bitmap populated with number locations for sectors
**************************************************************************/
/**************************************************************************/
/*                                                                        */
/*   Known Space Locations                                                */
/*                                                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/
/* VC-Irrlicht       by Perry Horner                      |   01-13-2000  */
/*                                                        |               */
/*------------------------------------------------------------------------*/
/* Modification history:                                                  */
/*------------------------------------------------------------------------*/
/*                                                        |               */
/**************************************************************************/
void DisplayKnownSpaceLocations(void)
{


	int xplace=0, yplace=0, xloccount=0, yloccount=0, secfilecounter=0,t=0;
	int textx = 2, texty = 610;
	int linex = 0, liney = 0;
	char currentdate[81];




	xloccount = 1; yloccount = 0; //init local variables


	//CREATE GRID
	for (linex = 0; linex <= 792; linex += 43) //vertical
	{
		driver->draw2DLine(position2d<s32>(linex, 3), position2d<s32>(linex, 606), SColor(255, 0, 0, 255)); //blue line
	} //end vertical

	for (liney = 0; liney <= 606; liney += 57) //horizontal
	{
		driver->draw2DLine(position2d<s32>(11, liney), position2d<s32>(786, liney), SColor(255, 0, 0, 255)); //blue line

	} //end horizontal

	xplace = 22; //initial text X placement
	yplace = 28; //initial text Y placement

	for (secfilecounter = 0; secfilecounter <= 197; secfilecounter++)
	{
		//*init galaxy map with numbers

		//is sector available
		if (sectorlocationname[secfilecounter].sectornumber == secfilecounter)
		{

			if (secfilecounter < 100)
			{
				if ((MarkerSectorNumber == secfilecounter) && (MarkerFlag == 1))
				{
					//do not display shadow
				}
				//make 1 pixel black on all sides
				else
				{
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 6, yplace, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace -4, yplace, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace-5, yplace, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace-5, yplace + 1, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace-5, yplace - 1, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 4, yplace - 1, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace -3, yplace + 1, 0, 0), video::SColor(255, 255, 255, 255));
				}
			//display sector number
				if ((MarkerSectorNumber == secfilecounter) && (MarkerFlag == 1))
				{
					Optima18Yellow->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 10, yplace - 5, 0, 0), video::SColor(255, 255, 255, 255));
				}
				else
				{
					Courier10Green->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace-5, yplace, 0, 0), video::SColor(255, 255, 255, 255));
				}
			}
			else //adjust for 3 digits to be centered
			{
				if ((MarkerSectorNumber == secfilecounter) && (MarkerFlag == 1))
				{
					//do not display shadow
				}
				else
				{//make 1 pixel black on all sides
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 9, yplace, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 7, yplace, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 8, yplace, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 8, yplace + 1, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 8, yplace - 1, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 9, yplace - 1, 0, 0), video::SColor(255, 255, 255, 255));
					Courier10Black->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 7, yplace + 1, 0, 0), video::SColor(255, 255, 255, 255));
				}
				//display sector number
				if ((MarkerSectorNumber == secfilecounter) && (MarkerFlag == 1))
				{
					Optima18Yellow->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 15, yplace - 5, 0, 0), video::SColor(255, 255, 255, 255));
				}
				else
				{
					Courier10Green->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(xplace - 8, yplace, 0, 0), video::SColor(255, 255, 255, 255));
				}
			}


			//display sector names
				Courier8Yellow->draw(irr::core::stringw(secfilecounter).c_str(), core::rect<s32>(textx, texty, 0, 0), video::SColor(255, 255, 255, 255));
				Courier8Yellow->draw(irr::core::stringw(sectorlocationname[secfilecounter].sectorname).c_str(), core::rect<s32>(textx + 20, texty, 0, 0), video::SColor(255, 255, 255, 255));

				texty = texty + 9;
				if (texty > 755)
				{
					texty = 610;
					textx = textx + 91;
				}
			} //end if sector available


			//increment possible number location
			xloccount++;
			xplace = xplace + 43;

			if (xloccount > 10) //account for larger digits
			{
				xplace = xplace - 1;
			}
			if (xloccount > 18)
			{
				xplace = 20;
				xloccount = 1;
				yloccount++;
				yplace = yplace + 57;
				if (yplace == 598) yplace = 586;
				/*
				if (yloccount > 6)
				{
					yplace = yplace - yloccount;
				}
				if (yloccount < 3)
				{
					yplace = yplace + yloccount;
				}*/
			} //end if xloccount>18
			if (yplace ==598) yplace = 586;

	} //end for loop

	sprintf(currentdate, "Date: %d-%d", TASYear, TASDay);
	//show current date

	Courier10Green->draw(irr::core::stringw(currentdate).c_str(), core::rect<s32>(820, 140, 0, 0), video::SColor(255, 255, 255, 255));
}




/*************************************************************************
generate sector map to screen
**************************************************************************/
void DisplaySector()
{
	int i=0, x=0, y=0, yinc=0;
	int sec = 0, pertotal = 0, str_length = 0, hex=0;
	int tempcount = 0, fleetinc=0;
	int PART1=0, PART2=0, STOPP=0, WC=0;
	char seccnt[128];
	char str[81];
	char sublocltr[81];

	SectorData *sctr;

	WC = 0;     //world count start
	PART1 = 1;
	PART2 = 0;
	STOPP = 0;
	sec = 0;
	str[0] = '\0';
	pertotal = 0;
	seccnt[0] = '\0';

	//---  generate each system  ---

	driver->draw2DImage(idbsystemgrid, core::position2d<s32>(100, 110), core::rect<s32>(0, 0, 400, 480), 0, video::SColor(255, 255, 255, 255), false);

	for (i = WC; i<s_cnt; i++) 
	{
		sctr = &sec_data[i];
		x = sctr->location.x;
		if (x<0) x = 0;
		if (x>1020) x = 1020;
		y = sctr->location.y;
		if (y<0) y = 0;
		if (y>760) y = 760;


		//highlight marked system

		if (((sctr->hexint) == MarkerHex) && (MarkerSectorNumber == secloct))
		{
			driver->draw2DImage(idbsystem2, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 4, 4), 0, video::SColor(255, 255, 255, 255), true);
		}
		else
		{
			driver->draw2DImage(idbsystem1, core::position2d<s32>(x, y), core::rect<s32>(0, 0, 4, 4), 0, video::SColor(255, 255, 255, 255), true);
		}
	}


	//sector name
	Courier10Black->draw(irr::core::stringw(sectitle).c_str(), core::rect<s32>(100, 630, 0, 0), video::SColor(255, 255, 255, 255));


	//total number of systems
	sprintf(seccnt, "Total Systems: %d", s_cnt);
	Courier10Black->draw(irr::core::stringw(seccnt).c_str(), core::rect<s32>(542, 575, 0, 0), video::SColor(255, 255, 255, 255));


	//sector numerical ID
	sprintf(sublocltr, "%d", secloct);
	Courier10Black->draw(irr::core::stringw(sublocltr).c_str(), core::rect<s32>(578, 358, 0, 0), video::SColor(255, 255, 255, 255));

	//display known governments 720,200
	yinc = 80;

	for (tempcount = 0; tempcount <= TotalAllegianceCount; tempcount++)
	{
		if (allegiance[tempcount].count > 0)
		{
			pertotal = (int)(((float)allegiance[tempcount].count) / ((float)s_cnt) * 100);
			if (pertotal > 100)
			{
				pertotal = 100;
			}
			sprintf(seccnt, "%d %%", pertotal);
			pertotal = 0;
			Courier10Green->draw(irr::core::stringw(seccnt).c_str(), core::rect<s32>(710, yinc, 0, 0), video::SColor(255, 255, 255, 255));
			Courier10Green->draw(irr::core::stringw(allegiance[tempcount].allegiancefull).c_str(), core::rect<s32>(740, yinc, 0, 0), video::SColor(255, 255, 255, 255));
			yinc = yinc + 15;
		}		
	}
	if (isthereseclibdata > 0)
	{
		yinc = yinc + 15;
		libdatabuttonx = 770;
		libdatabuttony = yinc;

		driver->draw2DImage(idblibdataavailable, core::position2d<s32>(libdatabuttonx, libdatabuttony), core::rect<s32>(0, 0, 87, 32), 0, video::SColor(255, 255, 255, 255), true);
	}

	if ((istherefleet > 0) && (uAccessLevel >= ALNAVFLEET))
	{
		yinc = yinc + 45;
		fleetbuttonx = 770;
		fleetbuttony = yinc;

		driver->draw2DImage(fltsectorinfo, core::position2d<s32>(fleetbuttonx, fleetbuttony), core::rect<s32>(0, 0, 87, 32), 0, video::SColor(255, 255, 255, 255), true);
	}
	sctr = '\0';

}

/***************Check for what sector is selected*************/
int checkmouseboundsgalaxy()
{
	int xlookup = 0, ylookup = 0;
	float coordinatex = 0, coordinatey = 0;
	char tempsectorfilename[120];

	FILE *FDW;

	secloct = -1;



	CurrentSystemLibData = 0;  //initialize library data number
	libdatacounter = 0;        //initialize library data starting pointer

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;


	if (xlookup<0) xlookup = 0;
	if (xlookup>1023) xlookup = 1023;
	if (ylookup<0) ylookup = 0;
	if (ylookup>767) ylookup = 767; //edge of screen

	coordinatex = (float)(xlookup / 43);
	coordinatey = (float)(ylookup / 57) + 1;

	//RETURN TO MAIN MENU
	if ((mouse_position.X>854) && (mouse_position.X<1015) && (mouse_position.Y>740) && (mouse_position.Y<768)) 
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//go back to main menu selected
		

		TASWindow = MAINMENUWINDOW;
		TASCurrentMenuWindow = MAINMENUWINDOW;

		driver->endScene();
		backsurf = MainMenuBackground;
		driver->beginScene(true, true, SColor(0, 0, 0, 0));
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

		return -1;

	}
	
	//SELECT A SECTOR
	if ((mouse_position.X<788) && (mouse_position.Y<610) && (mouse_position.X>10) && (mouse_position.Y>10))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		secloct = ((int)(((float)((int)mouse_position.Y / 57) + 1) * 18) - (18 - ((float)((int)mouse_position.X / 43))));



		//check for out of bounds
		if (xlookup>787) secloct = -1;
		if (ylookup>609) secloct = -1;
		if (xlookup<11)  secloct = -1;
		if (ylookup<11)  secloct = -1;
	
		if (secloct > -1)
		{

			if ((sectorlocationname[secloct].sectornumber == secloct))
			{
				//read library data
				sprintf(tempsectorfilename, "%s/%d/", SectorDirectory, secloct);
				sprintf(sectorfilename, "%s/data/all.txt", tempsectorfilename);

				FDW = NULL;
				isthereseclibdata = 0;
				if (FDW = fopen(sectorfilename, "r")){
					isthereseclibdata = 1;
					fclose(FDW);
				}
			

			driver->endScene();

			driver->beginScene(true, true, SColor(0, 0, 0, 0));
			driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
			return secloct;
			}
		}
	}
	
		return -1;
	

}

/***************Check for what hex is selected*************/
int checkmouseboundsfleet()
{

	int xlookup = 0, ylookup = 0, temp_wcount = 0, newhex = 0;


	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;

	newhex = 0;
	
			//Return to Sector Window
			if ((xlookup>851) && (xlookup<1019) && (ylookup>743) && (ylookup<763)){
				//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
				//go back to sector menu screen
				backsurf = secback;
				newhex = RETURNSECMENU;
			}
	return newhex;
}

void createplanetmapscreen(void)
{
	int xlookup = 0, ylookup = 0, temp_wcount = 0, newhex = 0, systemnumber = 0;
	char planetfilename[255]; //for custom planet
	long libdatasize = 0;
	long i = 0;

	FILE *FDW; //for temp files


	for (i = 0; i < w_cnt; i++) 
	{
		systemnumber = atoi(sec_world[i].hex); //find correct array for map
		if (systemnumber == currentworld)
		{
			currentworld = i;
			i = i + 100;
		}
	}


	//check for custom planet map	
	isthereplanet = 0; //initialize custom map check
	sprintf(planetfilename, "%s/%d/data/%d.bmp", SectorDirectory, sectorfile, systemnumber);
	FDW = fopen(planetfilename, "r");
	if (FDW)
	{
		isthereplanet = 1; //custom map is available
		fclose(FDW);
	}
	else planetfilename[0] = '\0';
	FDW = NULL;

	//********No Custom Map
	if (isthereplanet < 1)
	{
		planet_surface(currentworld); //send current system hex number

		sprintf(planetfilename, "./temp/tempplanet.bmp");

		//smgr->clear();

		tempplanet->lock(ETLM_READ_WRITE);
		driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
		driver->removeTexture(tempplanet);

		tempplanet = driver->getTexture(planetfilename);

		tempplanet->unlock();
		tempplanet->regenerateMipMapLevels(0);

	} //end if isthereplanet

	//**********Custom Map
	else
	{

		tempplanet->lock(ETLM_READ_WRITE);
		driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
		driver->removeTexture(tempplanet);

		tempplanet = driver->getTexture(planetfilename);

		tempplanet->unlock();
		tempplanet->regenerateMipMapLevels(0);
	}


	//CREATE ROTATING GLOBE

	//smgr->addCameraSceneNode(0, core::vector3df(0, 0, -40), core::vector3df(0, 0, 0)); //use this node for 3d items on screen [MOVED TO MAIN.cpp]

	Planet = smgr->addSphereSceneNode(.3, 64, 0, -1, core::vector3df(13, -10, 0), core::vector3df(0, 0, 0), core::vector3df(16, 16, 16)); 

	if (isthereplanet < 1)
	{


			planetskin->lock(ETLM_READ_WRITE);
			driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
			driver->removeTexture(planetskin);

			planetskin = driver->getTexture("./temp/tempplanet2.bmp");


			planetskin->unlock();
			planetskin->regenerateMipMapLevels(0);
			driver->makeColorKeyTexture(planetskin, SColor(255, 255, 255, 255));
	

			Planet->setMaterialTexture(0, planetskin);
			Planet->setMaterialFlag(video::EMF_LIGHTING, false);

			//make planet rotate
			Planet->addAnimator(smgr->createRotationAnimator(core::vector3df(0, -0.05, 0)));//0.05 =slow rotation speed

	}//end if isthereplanet
	else
		//***********custom map
	{
			planetskin->lock(ETLM_READ_WRITE);
			driver->removeTexture(planetskin);
			driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);

			planetskin = driver->getTexture(planetfilename);

			driver->makeColorKeyTexture(planetskin, SColor(255, 255, 255, 255));
			Planet->setMaterialTexture(0, planetskin);
			Planet->setMaterialFlag(video::EMF_LIGHTING, false);
			planetskin->unlock();
			planetskin->regenerateMipMapLevels(0);

		//make planet rotate
		Planet->addAnimator(smgr->createRotationAnimator(core::vector3df(0, -0.05, 0)));//0.05 =slow rotation speed
	} //end else custom map

	Planet->setVisible(true);

	if (sec_world[currentworld].WorldType == Plnt_RINGWORLD)
	{
		Planet->setVisible(false);
	}

}


//***************Check for what hex is selected*************
int checkmouseboundssubsec()
{


	int xlookup = 0, ylookup = 0, temp_wcount = 0, newhex = 0, systemnumber = 0;

	char subfilename[255];
	char tempsectorfilename[255];
	FILE *FDW; //for temp files
	FILE *LD;
	char *current;
	long libdatasize = 0;
	long i = 0;
	int t=0,tc=0; //temp number


device->getCursorControl()->getPosition();
mouse_position = device->getCursorControl()->getPosition();

xlookup = mouse_position.X;
ylookup = mouse_position.Y;

	newhex = 0;
	//select a system on map
	if ((xlookup<430) && (ylookup<543) && (xlookup>54) && (ylookup>20)){
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		for (temp_wcount = 0; temp_wcount <= w_cnt; temp_wcount++){


			if ((xlookup >= ((sec_world[temp_wcount].xmousepoint))) &&
				(xlookup <= ((sec_world[temp_wcount].xmousepoint) + 20)) &&
				(ylookup >= ((sec_world[temp_wcount].ymousepoint) - 20)) &&
				(ylookup <= ((sec_world[temp_wcount].ymousepoint) + 20)))
			{
				istherelibdata = 0;
				newhex = atoi(sec_world[temp_wcount].hex);
				currentworld = newhex;
				

				libimagecheck = checkforlibarydataimage(temp_wcount);
			}
		}
	}
	else
		//SCREENSHOT
	if ((xlookup>851) && (xlookup<1019) && (ylookup>689) && (ylookup<737)){
		
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		newhex = SAVESUBSECBMP;

		Screenshot(tempsubfname, SUBSECTORWINDOW);
		
		for (tc = 0; tc <= w_cnt; tc++)
		{
			t = atoi(sec_world[tc].hex);
			if (t == currentworld){
				newhex = atoi(sec_world[tc].hex);
			}
		}
	}
	else
		//MARKER Selection
		//Mark current location
		if ((xlookup>700) && (xlookup < 730) && (ylookup>10) && (ylookup < 40) && (subsectorhex>0))
		{
			for (tc = 0; tc <= w_cnt; tc++){
				t = atoi(sec_world[tc].hex);
				if (t == currentworld){
					hexmarkerx = (sec_world[tc].xmousepoint) - 21;
					hexmarkery = (sec_world[tc].ymousepoint) - 18;
					MarkerHex = atoi(sec_world[tc].hex);
					MarkerSectorNumber = secloct;
					strcpy(MarkerSubSector, sublocletter);
					MarkerFlag = 1;
					newhex = subsectorhex;
				}
			}
		}
	else
		//EXIT SCREEN
		//Return to Sector Window
	if ((xlookup>851) && (xlookup<1019) && (ylookup>743) && (ylookup<763))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//go back to sector menu screen
		FDW = NULL;
		LD = NULL;
		libimagecheck = 0;
		current = '\0';
		libdatatext = '\0';
		isthereplanet = 0;
		istherelibdata = 0;
		backsurf = secback;

		if (FDW = fopen(sectorfilename, "r")){
			istherelibdata = 1;
			fclose(FDW);
		}
		
		newhex = RETURNSECMENU;
	}
	else
		//planet map
		if ((xlookup>906) && (xlookup<1003) && (ylookup>7) && (ylookup<107) && (subsectorhex >0))
		{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
			IImage *screenshot = driver->createScreenShot();
			video::IImage* export_img = driver->createImage(screenshot, core::vector2d<s32>(0, 0), core::dimension2d<u32>(1024, 768));
			video::ITexture* texture = driver->addTexture(L"export_imag", export_img);
			texture->grab();
			driver->draw2DImage(texture, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

			arial_24_yellow_blackout_bevel->draw(L"Loading", core::rect<s32>(894, 40, 0, 0), video::SColor(255, 255, 255, 255));

			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();
				
			driver->beginScene(true, true, SColor(0, 0, 0, 0));

			smgr->drawAll();

			PlanetError = 0; //clear error flag
			createplanetmapscreen();

			TASWindow = PLANETWINDOW;
			FDW = NULL;
			LD = NULL;
			current = '\0';

			return PLANETWINDOW;
		} //end if planetmap selected

	//read library data
	else
	if ((xlookup>890) && (xlookup<976) && (ylookup>615) && (ylookup<646) && (istherelibdata>0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		sprintf(tempsectorfilename, "%s/%d/", SectorDirectory, sectorfile);
		sprintf(subfilename, "%s/data/h%s.txt", tempsectorfilename, sec_world[CurrentSystemLibData].hex);

		LD = NULL;
		//create empty temp library datafile
		LD = fopen("temp/tempdata.txt", "w");
		fclose(LD);

		libdatasize = FileLenCount(subfilename);
		libdatatext = '\0';
		if (FDW = fopen(subfilename, "r")){
			fseek(FDW, 0, 2);
			rewind(FDW);
			libdatatext = (char*)malloc(sizeof(char)* (libdatasize + 1));
			fread(libdatatext, sizeof(char), libdatasize, FDW);
			fclose(FDW);

			libdatatext[libdatasize] = '\0';

			//Remove tab characters from library files
			current = (char*)malloc(sizeof(char)*(strlen(libdatatext)+1));
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
			//chop the @@@@ image filename
			char *pfound = strstr(libdatatext, "@@@@");
			if (pfound)
			{
				int dposfound = int(pfound - libdatatext);
				libdatatext[dposfound] = '\0';
			}

			newhex = SUBSECTORLIBDATAWINDOW;
			TASWindow = SUBSECTORLIBDATAWINDOW;
			DisplayLibDataSubSec();
		}//end if file exists
		else libdatatext = NULL;
	}
	
	else{
		istherelibdata = 0;
	}// end if mouse click in data area
	
	FDW = NULL;
	LD = NULL;
	current = '\0';

	return newhex;
}

/*****************check for libary data image**************************/
int checkforlibarydataimage(int newlibdataloc)
{


	int lngth = 0;
	char tempsectorfilename[81];
	char tmpdata[100]; //for library data image check
	char libimagefilenamepath[120];

	FILE *IMGCHK;


	sprintf(tempsectorfilename, "%s/%d", SectorDirectory, sectorfile);
	sprintf(sectorfilename, "%s/data/h%s.txt", tempsectorfilename, sec_world[newlibdataloc].hex);

	fd = NULL;
	libimagecheck = 0;
	istherelibdata = 0;
		//check for library data on system
	
	if (!(fd = fopen(sectorfilename, "r")))
	{
		return libimagecheck;
	}
	else fclose(fd);

	fd = fopen(sectorfilename, "r");

	//if there is library data avaliable, show icon
	if (fd){

		istherelibdata = 1;
		
		//is there an image?
		while (!feof(fd)){
			
			fgets(tmpdata, 100, fd);
			if (strstr(tmpdata, "@@@@")){
				//load libdataimage
				libdataimage = NULL;			

				lngth = strlen(&tmpdata[4]);	

				while ((tmpdata[lngth + 4] == ' ') || (tmpdata[lngth + 4] == '\0'))
					lngth--;

				//check for corrupted entry of a picture file reference
				if (lngth<5)
				{
					ERR = fopen("error.txt", "a");
					fprintf(ERR, "length of referenced image file in %s is incorrect. Possible incorrect filename.\n", sectorfilename);
					fclose(ERR);
					CleanUp();
					device->drop();
					return 1;
				}
				tmpdata[lngth + 5] = '\0';

				strncpy(libimagefilename, strtok(tmpdata, "@@@@"), lngth);
				//libimagefilename[lngth + 1] = '\0';
				libimagefilename[lngth] = '\0';
				sprintf(libimagefilenamepath, "%s/data/%s", tempsectorfilename, libimagefilename);
				
				if (!(IMGCHK = fopen(libimagefilenamepath, "r")))
				{
					ERR = fopen("error.txt", "a");
					fprintf(ERR, "Library Data:  Could not load image file %s\n", libimagefilenamepath);
					fclose(ERR);
					CleanUp();
					device->drop();
					return 1;
				}
				else fclose(IMGCHK);

				if (libdataimage) libdataimage->unlock();
				driver->setTextureCreationFlag(ETCF_ALWAYS_16_BIT);
				if (libdataimage) driver->removeTexture(libdataimage);
				libdataimage = driver->getTexture(libimagefilenamepath);
				//device->getVideoDriver()->makeColorKeyTexture(tempplanet, position2d<s32>(0, 0));

				if (libdataimage == NULL)
				{
					ERR = fopen("error.txt", "a");
					fprintf(ERR, "Library Data:  Could not load image file %s\n", libimagefilenamepath);
					fclose(ERR);
					CleanUp();
					device->drop();
					return 1;
				}
				libdataimage->regenerateMipMapLevels(0);
				if (libdataimage) libdataimage->lock(ETLM_READ_WRITE);
				libimagecheck = 1;
			} //end if image available
		}//end while not end of file

	} //end if libdata
	fclose(fd);


	return libimagecheck;
}

/***************check menu selection for planet map*************/
int checkmouseboundsplanet()
{


	int xlookup=0, ylookup=0;
	char filename[255];
	char strfn[255];
	int stInc = 0;
	int i = 0;

	UpdateTheScreen = 1;

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;

	
	    //Save screen
	if ((xlookup>851) && (xlookup<1019) && (ylookup>689) && (ylookup<737)){
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		sprintf(filename, ".\\saved\\planet\\h%s-%s-%s.bmp", sec_world[currentworld].hex, sec_world[currentworld].uwp, sec_world[currentworld].name); //save bmp file
		sprintf(tempsavefilename, "h%s-%s-%s.bmp\0", sec_world[currentworld].hex, sec_world[currentworld].uwp, sec_world[currentworld].name);
		for (i = 0; i<255; i++){
			strfn[i] = '\0';
		}

		stInc = 0;
		for (i = 0; i <= sizeof(filename); i++){
			if ((filename[i] != ' ') && (filename[i] != ':')){
				strfn[stInc] = filename[i];
				stInc++;
			}

			else {
				strfn[stInc] = '_';
				stInc++;
			}

		}

		sprintf(filename, "%s", strfn);
		filename[strlen(filename)] = '\0';

		ERR = fopen("error.txt", "a");
		fprintf(ERR, "%s\n",filename);
		fclose(ERR);
		
		//tempsavefilename
		stInc = 0;
		for (i = 0; i <= sizeof(tempsavefilename); i++){
			if ((tempsavefilename[i] != ' ') && (tempsavefilename[i] != ':')){
				strfn[stInc] = tempsavefilename[i];
				stInc++;
			}

			else {
				strfn[stInc] = '_';
				stInc++;
			}

		}

		sprintf(tempsavefilename, "%s", strfn);
		tempsavefilename[strlen(tempsavefilename)] = '\0';

		ERR = fopen("error.txt", "a");
		fprintf(ERR, "%s\n", tempsavefilename);
		fclose(ERR);


		Screenshot(filename, (int)PLANETWINDOW);
		strfn[0] = '\0';
	}

	//************RETURN TO SECTOR MENU
	if ((xlookup>851) && (xlookup<1019) && (ylookup>743) && (ylookup<763))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//go back to sector menu screen
		currentworld = atoi(sec_world[currentworld].hex);
		
		backsurf = SubsecBackground;
		if (Planet){

			Planet->removeAnimators(); //remove animator for the 3d planet
			Planet->remove(); //remove the 3d planet
		}

		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
		driver->beginScene(true, true, SColor(0, 0, 0, 0));

		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		return SUBSECTORWINDOW;
	}

	return PLANETWINDOW;
}
/***************Check for what subsector is selected*************/
char * checkmouseboundssector()
{

	int xlookup=0, ylookup=0, xspot=0, yspot=0;
	FILE *FDW; //library.txt, templibdata, templibdata2
	FILE *LD;
	char* current;
	char *subfilename = NULL;
	char tempsectorfilename[81];
	long libdatasize = 0;
	long i = 0;


device->getCursorControl()->getPosition();
mouse_position = device->getCursorControl()->getPosition();

xlookup = mouse_position.X;
ylookup = mouse_position.Y;



	//check to see if selection is on the grid
	if (xlookup<1) return NULL;
	if (ylookup<1) return NULL;

	//************EXIT to Galaxy window
	if ((xlookup >859) && (xlookup <1020) && (ylookup >749) && (ylookup <766)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//go back to known space menu selected

		TASWindow = GALAXYWINDOW;
		FDW = NULL;
		current = '\0';
		libdatatext = '\0';
		subfilename = '\0';
		libimagecount = 0;
		libdatacounter = 0;
		libdatacounter2 = 0; //for scrolling library data
		isthereseclibdata = 0; //is there any sector library data
		librarydataavailable = 0; //is there library data
		libimagecheck = 0; //is there a library data image
		CurrentSystemLibData = 0; // hex number for library data
		searchmenuitemavailable = 0; //library search menu item selection available
		searchentered = 0; //library search word entered
		libdatatext = '\0';
		libdatasearchword = '\0';
		istherefleet = 0;
		isthereplanet = 0;
		
		LD = NULL;

		Delay(50); //prevent double click back to main menu
		driver->endScene();
		backsurf = Galaxy;
		driver->beginScene(true, true, SColor(0, 0, 0, 0));
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		return NULL;
	}
	
	//***********SCREENSHOT*****************
	if ((xlookup >854) && (xlookup <1015) && (ylookup >693) && (ylookup <732)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//save bitmap file

		Screenshot(tempsecfname, SECTORWINDOW);
		FDW = NULL;
		current = '\0';
		subfilename = '\0';
		LD = NULL;
		return NULL;
	}
	
	//****************LIBDATA**************
	if ((xlookup >libdatabuttonx) && (xlookup <libdatabuttonx + 86) &&
		(ylookup >libdatabuttony) && (ylookup <libdatabuttony + 31) && (isthereseclibdata>0)) {
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//read library data
		sprintf(tempsectorfilename, "%s/%d/", SectorDirectory, sectorfile);
		sprintf(sectorfilename, "%s/data/all.txt", tempsectorfilename);
	

		libdatasize = FileLenCount(sectorfilename);

		libdatatext = '\0';
		if (FDW = fopen(sectorfilename, "r")){
			fseek(FDW, 0, 2);
			rewind(FDW);
			libdatatext = (char*)malloc(sizeof(char)* (libdatasize + 1));
			fread(libdatatext, sizeof(char), libdatasize, FDW);
			fclose(FDW);

			libdatatext[libdatasize] = '\0';

			current = (char*)malloc(sizeof(char)*(strlen(libdatatext) + 1));

			//Remove tab characters from library files
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
			
			//chop the @@@@ image filename
			char *pfound = strstr(libdatatext, "@@@@");
			if (pfound)
			{
				int dposfound = int(pfound - libdatatext);
				libdatatext[dposfound] = '\0';
			}

			TASWindow = SECTORLIBDATAWINDOW;
			DisplayLibDataSec();
		}//end if file exists
		else libdatatext = NULL;

		FDW = NULL;
		current = '\0';
		subfilename = '\0';
		LD = NULL;
		return NULL;
	}// end if libdata

	//****************FLEET**************
	if ((xlookup > fleetbuttonx) && (xlookup <fleetbuttonx + 86) &&
		(ylookup >fleetbuttony) && (ylookup < fleetbuttony + 31) && (istherefleet>0)) {
		TASWindow = SECTORFLEETWINDOW;
		backsurf = fleetback;
		DisplayFleet();
	} //end if fleet;

	xlookup = xlookup - 100;
	ylookup = ylookup - 120;
	//*mouse out of bounds - selection is nothing
	if (xlookup>395) return NULL;
	if (ylookup>465) return NULL;

	//all mouse locationions other than on the grid has been accounted for
	//now all that is left are valid sector grid locations...
	//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
	xspot = (int)(xlookup / 100);
	yspot = (int)(ylookup / 120);

	subfilename = subsectorfilegrid[yspot][xspot];
	sublocletter = subloclettergrid[yspot][xspot];

	istherelibdata = 0;
	FDW = NULL;
	current = '\0';
	LD = NULL;
	TASWindow = SUBSECTORWINDOW;
	backsurf = SubsecBackground;
	return subfilename;

}

int checkmouseboundssectorlibdata()
{

	int xlookup=0, ylookup=0, databreak=0;
	int txtcounter = 0;

	device->getCursorControl()->getPosition();
	mouse_position = device->getCursorControl()->getPosition();

	xlookup = mouse_position.X;
	ylookup = mouse_position.Y;

	//check to see if selection is on the grid
	if (xlookup<1) return SECTORLIBDATAWINDOW;
	if (ylookup<1) return SECTORLIBDATAWINDOW;

	//return to sector window
	if ((xlookup >854) && (xlookup <1015) && (ylookup >745) && (ylookup <760))
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound

		//Return to sector window
		CurrentSystemLibData = 0;
		libdatacounter = 0;
		if(textBox) textBox->remove(); //destroy textbox
		if(libdatatextimage) libdatatextimage->remove(); //remove background image
		backsurf = secback;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		return SECTORWINDOW;
	}
	txtcounter = (int)strlen(libdatatext);  //find max length of library data file

	return SECTORLIBDATAWINDOW;

}

int checkmouseboundssubseclibdataimage()
{

	int xlookup = 0, ylookup = 0;



device->getCursorControl()->getPosition();
mouse_position = device->getCursorControl()->getPosition();

xlookup = mouse_position.X;
ylookup = mouse_position.Y;

	//check to see if selection is on the grid
	if (xlookup<1) return SUBSECTORLIBDATAWINDOW;
	if (ylookup<1) return SUBSECTORLIBDATAWINDOW;


	//any mouse button click returns
	if ((xlookup >854) && (xlookup <1015) && (ylookup >745) && (ylookup <760))
	{
		libdatatextimage->setVisible(true);
		textBox->setVisible(true);
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		TASWindow = SUBSECTORLIBDATAWINDOW;
		return SUBSECTORLIBDATAWINDOW;
	}

	return SUBSECLIBDATAIMAGEWINDOW;
}

int checkmouseboundssubsectorlibdata()
{

	int xlookup=0, ylookup=0, databreak=0;
	int txtcounter = 0;


device->getCursorControl()->getPosition();
mouse_position = device->getCursorControl()->getPosition();

xlookup = mouse_position.X;
ylookup = mouse_position.Y;



	//check to see if selection is on the grid
	if (xlookup<1) return SUBSECTORLIBDATAWINDOW;
	if (ylookup<1) return SUBSECTORLIBDATAWINDOW;

	if ((xlookup > 754) && (xlookup  < 952) && (ylookup  > 332) && (ylookup  < 383) && (libimagecheck>0))
	{
		backsurf = SecLibDataMenu;
		libdatatextimage->setVisible(false); //hide background image
		textBox->setVisible(false); //hide textbox of libdata
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true);

		TASWindow = SUBSECLIBDATAIMAGEWINDOW;
		return SUBSECLIBDATAIMAGEWINDOW; //go to image window
	}


	if ((xlookup >854) && (xlookup <1015) && (ylookup >745) && (ylookup <760)) //return to subsector window
	{
		//Mix_PlayChannel(-1, SoundButtonClick, 0); //do button click sound
		//Return to subsector window
		CurrentSystemLibData = 0;
		libdatacounter = 0;
		if (textBox) textBox->remove(); //destroy textbox
		if (libdatatextimage) libdatatextimage->remove(); //remove background image
		backsurf = SubsecBackground;
		driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
		return SUBSECTORWINDOW;
	}
	txtcounter = (int)strlen(libdatatext);  //find max length of library data file

	
	return SUBSECTORLIBDATAWINDOW;
}

void DisplaylibdataDataSubSecImage(void)
{
	backsurf = SecLibDataMenu;
	driver->draw2DImage(backsurf, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), false);
	//driver->draw2DImage(sublibdatablank, core::position2d<s32>(5, 5), core::rect<s32>(0, 0, 681, 584), 0, video::SColor(255, 255, 255, 255), false);
	driver->draw2DImage(libdataimage, core::position2d<s32>(38, 15), core::rect<s32>(0, 0, 616, 594), 0, video::SColor(255, 255, 255, 255), false);
}


void DisplayLibDataSubSec(void)
{


	backsurf = SecLibDataMenu;
	core::stringw w_libdatatext = libdatatext; //make text a wide char type

	libdatatextimage = guienv->addImage((sublibdatablank), core::position2d<s32>(0, 0)); //681x584 image or use another image
	libdatatextimage->setAlignment(EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE);
	libdatatextimage->setRelativePosition(core::rect<s32>(5, 5, 686, 589));

	textBox = new CGUITextBox(Optima18Black, L"", guienv, irr::core::rect<irr::s32>(52, 20, 635, 535), libdatatextimage, -1);
	textBox->setScrollModeLines(true);
	textBox->setScrollbarRight(true);
	textBox->setVisible(true);
	textBox->setText(w_libdatatext.c_str());


}


void DisplayLibDataSec(void)
{
	backsurf = SecLibDataMenu;
	core::stringw w_libdatatext = libdatatext; //make text a wide char type

	libdatatextimage = guienv->addImage((seclibdatablank), core::position2d<s32>(0,0)); //678x701 image or use another image
	libdatatextimage->setAlignment(EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE);
	libdatatextimage->setRelativePosition(core::rect<s32>(10, 10, 688, 711));

	textBox = new CGUITextBox(Optima18Black, L"", guienv, irr::core::rect<irr::s32>(35, 35, 640, 615), libdatatextimage, -1);
	textBox->setScrollModeLines(true);
	textBox->setScrollbarRight(true);
	textBox->setVisible(true);
	textBox->setText(w_libdatatext.c_str());

}

void display_trade()

{
	int x = 0;
	int dieroll1 = 0;
	int dieroll2 = 0;
	char charuwp[10] = "         ";
	double seeduwp;
	char uwpchar[255];
	char tempremark[3];
	char *tmpuwp;
	int yplacement = 650; //display y location


	//**************************************************************************
	//Trade list taken from T5 Core Rules
	sprintf(charuwp, sec_world[currentworld].uwp);
	charuwp[7] = '\0';


	sprintf(uwpchar, ".%d%d%d%d%d%d%d", charuwp[0], charuwp[1], charuwp[2], charuwp[3], charuwp[4], charuwp[5], charuwp[6]);

	seeduwp = strtod(uwpchar, &tmpuwp) + (currentworld*.000001);



	srand((unsigned int)seeduwp);  //srand seed 



	for (x = 1; x <= 5; x++){
		if (x == 1){
			sprintf(tempremark, "%s", sec_world[currentworld].remark1);
		}
		if (x == 2){
			sprintf(tempremark, "%s", sec_world[currentworld].remark2);
		}
		if (x == 3){
			sprintf(tempremark, "%s", sec_world[currentworld].remark3);
		}
		if (x == 4){
			sprintf(tempremark, "%s", sec_world[currentworld].remark4);
		}
		if (x == 5){
			sprintf(tempremark, "%s", sec_world[currentworld].remark5);
		}

		//Ag
		if (!strcmp(tempremark, "Ag")) 
		{
			Courier10Black->draw(L"Ag-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 5 + 1;

			//RAWS
			if (dieroll1 == 1)
			{
				dieroll2 = rand() % 12 + 1;
				switch (dieroll2)
				{			
				case 1: Courier10Black->draw(L"Bulk Protein", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				case 2: Courier10Black->draw(L"Bulk Carbs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Fats", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Bulk Pharma", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Livestock", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Seedstock", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 7: Courier10Black->draw(L"Bulk Woods", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 8: Courier10Black->draw(L"Bulk Pelts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 9: Courier10Black->draw(L"Bulk Herbs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 10: Courier10Black->draw(L"Bulk Spices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				case 11: Courier10Black->draw(L"Bulk Nitrates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 12: Courier10Black->draw(L"Foodstuffs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//CONSUMABLES
			if (dieroll1 == 2)
			{
				dieroll2 = rand() % 12 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Flavored Waters", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Wines", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Juices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Nectars", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Decoctions", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Drinkable Lymphs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 7: Courier10Black->draw(L"Flowers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 8: Courier10Black->draw(L"Aromatics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 9: Courier10Black->draw(L"Pheromones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 10: Courier10Black->draw(L"Secretions", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 11: Courier10Black->draw(L"Adhesives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 12: Courier10Black->draw(L"Novel Flavorings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 CONSUMABLES

			//PHARMA
			if (dieroll1 == 3)
			{
				dieroll2 = rand() % 12 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Health Foods", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Nutraceuticals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Fast Drug", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Painkillers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Antiseptic", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Antibiotics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 7: Courier10Black->draw(L"Antifungal", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 8: Courier10Black->draw(L"Antiviral", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 9: Courier10Black->draw(L"Panacea", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 10: Courier10Black->draw(L"Pseudo Hormones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 11: Courier10Black->draw(L"Anagathics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 12: Courier10Black->draw(L"Slow Drug", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L"", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
			}//end if 3 PHARMA

			//NOVELTIES
			if (dieroll1 == 4)
			{
				dieroll2 = rand() % 12 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Incense", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Iridescents", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Reflectives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Pigments", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Noisemakers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Soundmakers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 7: Courier10Black->draw(L"Strange Seeds", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 8: Courier10Black->draw(L"Motile Plants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 9: Courier10Black->draw(L"Reactive Plants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 10: Courier10Black->draw(L"Reactive Woods", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 11: Courier10Black->draw(L"IR Emitters", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 12: Courier10Black->draw(L"Lek Emitters", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 NOVELTIES

			//RARES
			if (dieroll1 == 5)
			{
				dieroll2 = rand() % 12 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Fine Furs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Meat Delicacies", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Fruit Delicacies", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Candles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Textiles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Exotic Sauces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 7: Courier10Black->draw(L"Spices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 8: Courier10Black->draw(L"Organic Gems", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 9: Courier10Black->draw(L"Flavorings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 10: Courier10Black->draw(L"Aged Meats", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 11: Courier10Black->draw(L"Fermented Fluids", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 12: Courier10Black->draw(L"Fine Aromatics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 RARES

			yplacement = yplacement + 15;
		}//end if Ag


		//As
		if (!strcmp(tempremark, "As")) 
		{
			Courier10Black->draw(L"AS-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 

			dieroll1 = rand() % 5 + 1;

			//RAWS
			if (dieroll1 == 1)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Bulk Nitrates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Carbon", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Iron", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Bulk Copper", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Bulk Radioactive Ores", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Bulk Ices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//SAMPLES
			if (dieroll1 == 2)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Ores", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Ices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Carbons", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Metals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Radioactives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Silicates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 SAMPLES

			//VALUTA
			if (dieroll1 == 3)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Platinum", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Gold", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Gallium", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Silver", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Thorium", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Radium", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 VALUTA

			//NOVELTIES
			if (dieroll1 == 4)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Unusual Rocks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Fused Metals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Strange Crystals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Fine Dusts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Magnetics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Light-Sensitives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 NOVELTIES

			//RARES
			if (dieroll1 == 5)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Gemstones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Alloys", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Iridium Sponge", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Lanthanum", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Isotopes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Anti-Matter", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 RARES
			yplacement = yplacement + 15;
		}//end if As


		//Cp
		if (!strcmp(tempremark, "Cp")) 
		{
			Courier10Black->draw(L"Cp-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 

			dieroll1 = rand() % 6 + 1;

			//DATA
			if (dieroll1 == 1)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Software", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Expert Systems", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Databases", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Upgrades", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Backups", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Raw Sensings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 DATA

			//NOVELTIES
			if (dieroll1 == 2)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Incenses", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Contemplatives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Cold Welders", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Polymer Sheets", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Hats", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Skin Tones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 NOVELTIES

			//CONSUMABLES
			if (dieroll1 == 3)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Branded Clothes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Branded Devices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Flavored Drinks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Flavorings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Decorations", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Group Symbols", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 CONSUMABLES

			//RARES
			if (dieroll1 == 4)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Monumental Art", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Holo Sculpture", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Collectible Books", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Jewelry", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Museum Items", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Monumental Art", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 RARES

			//VALUTA
			if (dieroll1 == 5)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Coinage", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Currency", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Money Cards", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Gold", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Silver", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Platinum", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 VALUTA
			//RED TAPE
			if (dieroll1 == 6)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Regulations", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Synchronizations", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Expert Systems", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Educationals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Mandates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Accountings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 6 RED TAPE
			yplacement = yplacement + 15;
		}//end if Cp
		//De
		if (!strcmp(tempremark, "De")) 
		{

			Courier10Black->draw(L"De-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 6 + 1;

			//RAWS
			if (dieroll1 == 1)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Bulk Nitrates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Abrasives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Bulk Particulates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Exotic Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Exotic Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//SAMPLES
			if (dieroll1 == 2)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Archeologicals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Ephemerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Polymers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 SAMPLES

			//PHARMA
			if (dieroll1 == 3)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Stimulants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Herbs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Palliatives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Pheromones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Antibiotics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Combat Drug", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 PHARMA

			//NOVELTIES
			if (dieroll1 == 4)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Envirosuits", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Reclamation Suits", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Navigators", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Dupe Masterpieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"ShimmerCloth", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"ANIFX Blocker", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 NOVELTIES

			//RARES
			if (dieroll1 == 5)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Excretions", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Flavorings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Nectars", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Pelts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"ANIFX Dyes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Seedstocks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 RARES
			//UNIQUES
			if (dieroll1 == 6)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Pheromones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Artifacts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Sparx", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Repulsant", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Dominants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Fossils", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 6 UNIQUES
			yplacement = yplacement + 15;
		}//end if De
		//Fl
		if (!strcmp(tempremark, "Fl")) 
		{
			Courier10Black->draw(L"Fl-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 5 + 1;

			//RAWS
			if (dieroll1 == 1)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Bulk Carbon", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Petros", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Precipitates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Exotic Fluids", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Organic Polymers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Bulk Synthetics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//SAMPLES
			if (dieroll1 == 2)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Archeologicals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Ephemerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Polymers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 SAMPLES

			//PHARMA
			if (dieroll1 == 3)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Antifungals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Antivirals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Palliatives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Counter-prions", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Antibiotics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Cold Sleep Pills", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 PHARMA

			//NOVELTIES
			if (dieroll1 == 4)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Silanes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Lek Emitters", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Aware Blockers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Soothants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Self-Solving Puzzles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Fluidic Timepieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 NOVELTIES

			//RARES
			if (dieroll1 == 5)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Flavorings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Unusual Fluids", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Encapsulants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Insidiants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Corrosives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Exotic Aromatics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 RARES
			yplacement = yplacement + 15;
		}//end if Fl
		//Ic
		if (!strcmp(tempremark, "Ic")) 
		{
			Courier10Black->draw(L"Ic-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 6 + 1;

			//RAWS
			if (dieroll1 == 1)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Bulk Ices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Preciitates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Ephemerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Exotic Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Bulk Gases", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Bulk Oxygen", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//SAMPLES
			if (dieroll1 == 2)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Archeologicals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Ephemerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Polymers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 SAMPLES

			//PHARMA
			if (dieroll1 == 3)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Antifungals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Antivirals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Palliatives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Restoratives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Antibiotics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Antiseptics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 PHARMA

			//NOVELTIES
			if (dieroll1 == 4)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Heat Pumps", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Mag Emitters", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Percept Blockers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Silanes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Cold Light Blocks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"VHDUS Blocker", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 NOVELTIES

			//RARES
			if (dieroll1 == 5)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1: Courier10Black->draw(L"Unusual Ices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Cryo Alloys", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Rare Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Unusual Fluids", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Cryo Gems", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"VHDUS Dyes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 RARES
			//UNIQUES
			if (dieroll1 == 6)
			{
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2)
				{
				case 1:Courier10Black->draw(L"Fossils", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				case 2: Courier10Black->draw(L"Cryogems", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Vision Suppressant", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Fission Suppressant", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Wafers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Cold Sleep Pills", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 6 UNIQUES
			yplacement = yplacement + 15;
		}//end if Ic

		//In
		if (!strcmp(tempremark, "In")) {
			Courier10Black->draw(L"In-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 6 + 1;

			//MANUFACTURED
			if (dieroll1 == 1){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Electronics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Photonics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Magnetics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Fluidics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Polymerics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Gravitics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 MANUFACTURED

			//SCRAP-WASTE
			if (dieroll1 == 2){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Obsoletes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Used Goods", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Reparables", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Radioactives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Metals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Sludges", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 SCRAP-WASTE

			//MANUFACTURED
			if (dieroll1 == 3){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Biologics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Mechanicals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Textiles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Weapons", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Armor", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Robots", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 MANUFACTURED

			//PHARMA
			if (dieroll1 == 4){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Nostrums", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				case 2: Courier10Black->draw(L"Restoratives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Palliatives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Suppressants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Antidotes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Antitoxins", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 PHARMA

			//DATA
			if (dieroll1 == 5){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Software", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Databases", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Expert Systems", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Software Upgrades", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Data Backups", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Raw Sensings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 DATA
			//CONSUMABLES
			if (dieroll1 == 6){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Disposables", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Branded Drinks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Branded Foods", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Branded Clothes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Parts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Improvements", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 6 CONSUMABLES
			yplacement = yplacement + 15;
		}//end if In

		//Na
		if (!strcmp(tempremark, "Na")) {
			Courier10Black->draw(L"Na-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 5 + 1;

			//RAWS
			if (dieroll1 == 1){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Bulk Abrasives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Gases", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Bulk Precipitates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Exotic Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Exotic Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//SAMPLES
			if (dieroll1 == 2){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Archaeologicals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Ephemerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Polymers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 SAMPLES

			//NOVELTIES
			if (dieroll1 == 3){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Branded Tools", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Drinkable Lymphs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Dupe Masterpieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Pattern Creators", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Pigments", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Warm Leather", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 NOVELTIES

			//RARES
			if (dieroll1 == 4){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Hummingsand", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Masterpieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Fine Carpets", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Isotopes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Pelts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Seedstocks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 RARES

			//UNIQUES
			if (dieroll1 == 5){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Masterpieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Unusual Rocks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Artifacts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Fine Art", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Replicating Clays", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"ANIFX Emitter", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 UNIQUES
			yplacement = yplacement + 15;
		}//end if Na

		//Po
		if (!strcmp(tempremark, "Po")) {
			Courier10Black->draw(L"Po-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 5 + 1;

			//RAWS
			if (dieroll1 == 1){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Bulk Nutrients", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Fibers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Organics", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Bulk Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Bulk Textiles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Exotic Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//ENTERTAINMENTS
			if (dieroll1 == 2){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Art", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Recordings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Writings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Tactiles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Osmancies", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Waters", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 ENTERTAINMENTS

			//NOVELTIES
			if (dieroll1 == 3){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Strange Crystals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Strange Seeds", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Dupe Masterpieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Emotion Lighting", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Silanes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 NOVELTIES

			//RARES
			if (dieroll1 == 4){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Gemstones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Antiques", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				case 3: Courier10Black->draw(L"Collectibles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Allotropes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Spices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Seedstocks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 RARES

			//UNIQUES
			if (dieroll1 == 5){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Masterpieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Incomprehensibles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Antiques", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Exotic Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Fossils", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"VHDUS Emitter", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 UNIQUES
			yplacement = yplacement + 15;
		}//end if Po

		//Ri
		if (!strcmp(tempremark, "Ri")) {
			Courier10Black->draw(L"Ri-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 6 + 1;

			//RAWS
			if (dieroll1 == 1){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Bulk Foodstuffs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Protein", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Carbs", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Bulk Fats", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Exotic Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Exotic Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//NOVELTIES
			if (dieroll1 == 2){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Echostones", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Self-Defenders", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Attractants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Sophont Cuisine", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Sophont Hats", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Variable Tattoos", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 NOVELTIES

			//CONSUMABLES
			if (dieroll1 == 3){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Branded Foods", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Branded Drinks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Branded Clothes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Flavored Drinks", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Flowers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Music", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 CONSUMABLES

			//RARES
			if (dieroll1 == 4){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Delicacies", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Spices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Tisanes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Nectars", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Pelts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Variable Tattoos", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 RARES

			//UNIQUES
			if (dieroll1 == 5){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Antique Art", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Masterpieces", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Artifacts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Incomprehensibles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Meson Barriers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Famous Wafers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 UNIQUES
			//ENTERTAINMENTS
			if (dieroll1 == 6){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Art", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Recordings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Writings", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Tactiles", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Osmancies", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Wafers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				}
			}//end if 6 ENTERTAINMENTS
			yplacement = yplacement + 15;
		}//end if Ri

		//Va
		if (!strcmp(tempremark, "Va")) {
			Courier10Black->draw(L"Va-", core::rect<s32>(158, yplacement, 0, 0), video::SColor(255, 255, 255, 255));

			dieroll1 = rand() % 6 + 1;

			//RAWS
			if (dieroll1 == 1){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Bulk Dusts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Bulk Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Bulk Metals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Radioactive Ores", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Bulk Particulates", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Ephemerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 1 RAWS

			//NOVELTIES
			if (dieroll1 == 2){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Branded Vacc Suits", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Awareness Pinger", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Strange Seeds", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Musical Instruments", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Unusual Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255));
					break;
				case 6: Courier10Black->draw(L"Exotic Crystals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 2 NOVELTIES

			//CONSUMABLES
			if (dieroll1 == 3){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Branded Oxygen", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Vacc Suit Scents", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Vacc Suit Patches", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Branded Tools", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Holo-Companions", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Flavored Air", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 3 CONSUMABLES

			//RARES
			if (dieroll1 == 4){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Vacc Gems", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Unusual Dusts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Insulants", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Crafted Devices", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Rare Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Catalysts", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 4 RARES

			//SAMPLES
			if (dieroll1 == 5){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Archeologicals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Fauna", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Flora", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Minerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Ephemerals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Polymers", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 5 SAMPLES
			//SCRAP/WASTE
			if (dieroll1 == 6){
				dieroll2 = rand() % 6 + 1;
				switch (dieroll2){

				case 1: Courier10Black->draw(L"Obsoletes", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 2: Courier10Black->draw(L"Used Goods", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 3: Courier10Black->draw(L"Repairables", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 4: Courier10Black->draw(L"Radioactives", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 5: Courier10Black->draw(L"Metals", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				case 6: Courier10Black->draw(L"Sludges", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				default: Courier10Black->draw(L" ", core::rect<s32>(185, yplacement, 0, 0), video::SColor(255, 255, 255, 255)); 
					break;
				}
			}//end if 6 SCRAP/WASTE
			yplacement = yplacement + 15;
		}//end if Va
	}//end for x 1-5
	
}




void display_planet1()
{

	char *ch;
	char tempstellar[24];

	orbits = 0; //if -1 then no star data



	//************Star/stellar data display


	sprintf(tempstellar, "%s", sec_world[currentworld].stars);
	ch = '\0';
	ch = (char *)malloc(28 * sizeof (*ch)); //stars

	ch = strtok(tempstellar, " ");

	if (ch != NULL){
		sprintf(startemperature, "%s", ch);
	}

	ch = strtok(NULL, " ");
	if (ch != NULL){
		sprintf(starsize, "%s", ch);
	}

	if (sec_world[currentworld].WorldType != 8)
	{
		orbits = planetorbits(starsize, startemperature); //valid world type
	}
	else orbits = -1; //ringworld - no data

}

void display_planet2()
{


	driver->draw2DRectangle(video::SColor(255, 255, 255, 255), core::rect<s32>(0, 0, 1024, 768));
	if (isthereplanet < 1)
	{
		
		driver->draw2DImage(tempplanet, core::position2d<s32>(28, 118), core::rect<s32>(0, 0, 800, 375), 0, video::SColor(255, 255, 255, 255), true);//generated planet
		driver->draw2DImage(planetmap, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true); //grid - set alpha to TRUE?

	}
	else
	{
		driver->draw2DImage(tempplanet, core::position2d<s32>(0, 0), core::rect<s32>(0, 0, 1024, 768), 0, video::SColor(255, 255, 255, 255), true); //grid - set alpha to TRUE?
	}

	display_planet1();




	Optima18Red->draw(irr::core::stringw(currentdate).c_str(), core::rect<s32>(73, 71, 0, 0), video::SColor(255, 255, 255, 255));//current date

	Courier10Black->draw(irr::core::stringw(sec_world[currentworld].name).c_str(), core::rect<s32>(335, 72, 0, 0), video::SColor(255, 255, 255, 255));//system name
	Courier10Black->draw(irr::core::stringw(sec_world[currentworld].hex).c_str(), core::rect<s32>(785, 79, 0, 0), video::SColor(255, 255, 255, 255)); //hex number
	Optima18Red->draw(irr::core::stringw(sec_world[currentworld].uwp).c_str(), core::rect<s32>(645, 71, 0, 0), video::SColor(255, 255, 255, 255)); //UWP
	Courier10Black->draw(irr::core::stringw(title).c_str(), core::rect<s32>(198, 552, 0, 0), video::SColor(255, 255, 255, 255)); //sub sector and sector name


	//************Star/stellar data display



	if (strlen(startemperature) >0)
	{
		Courier10Black->draw(irr::core::stringw(startemperature).c_str(), core::rect<s32>(850, 105, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (strlen(starsize) >0)
	{
		Courier10Black->draw(irr::core::stringw(starsize).c_str(), core::rect<s32>(850, 120, 0, 0), video::SColor(255, 255, 255, 255));
	}

	if (orbits < 0)
	{
		Courier10Black->draw(L"No Star Data or", core::rect<s32>(880, 200, 0, 0), video::SColor(255, 255, 255, 255));
		Courier10Black->draw(L"corrupt data", core::rect<s32>(880, 220, 0, 0), video::SColor(255, 255, 255, 255));
	}
	display_trade();


}