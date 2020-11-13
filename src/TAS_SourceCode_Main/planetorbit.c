/* planetorbit.c */
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


The bulk of the code is by Perry Horner (firetaste@yahoo.com)


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




int validate_orbit(char *starsize, char *brightness, int orbit_ring, int remaining_rings)
{
	int orbit = 0;
	// orbit = 0-no planet, orbit=1 can be planet, orbit=2 habitable planet

	//***************SIZE 0 **************************************
	if (!strncmp(starsize, "0", 1) || !strncmp(starsize, "O", 1)){
		if (!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 0; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 2; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch
		} //end B0

		if (!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;
			} //end switch

		} //end B5


		if (!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A0


		if (!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A5

		if (!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F0

		if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F5

		if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G0

		if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G5

		if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K0

		if (!strncmp(brightness, "K5", 2) || !strncmp(brightness, "K6", 2) || !strncmp(brightness, "K7", 2) || !strncmp(brightness, "K8", 2) || !strncmp(brightness, "K9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K5

		if (!strncmp(brightness, "M0", 2) || !strncmp(brightness, "M1", 2) || !strncmp(brightness, "M2", 2) || !strncmp(brightness, "M3", 2) || !strncmp(brightness, "M4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M0

		if (!strncmp(brightness, "M5", 2) || !strncmp(brightness, "M6", 2) || !strncmp(brightness, "M7", 2) || !strncmp(brightness, "M8", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 0; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M5

		if (!strncmp(brightness, "M9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 0; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M9

	}//end star size 0


	//***************SIZE 1 **************************************
	if (!strncmp(starsize, "1", 1) || !strncmp(starsize, "I", 1)){
		if (!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 0; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 2; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch
		} //end B0

		if (!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;
			} //end switch

		} //end B5


		if (!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A0


		if (!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A5

		if (!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F0

		if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F5

		if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G0

		if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G5

		if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K0

		if (!strncmp(brightness, "K5", 2) || !strncmp(brightness, "K6", 2) || !strncmp(brightness, "K7", 2) || !strncmp(brightness, "K8", 2) || !strncmp(brightness, "K9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K5

		if (!strncmp(brightness, "M0", 2) || !strncmp(brightness, "M1", 2) || !strncmp(brightness, "M2", 2) || !strncmp(brightness, "M3", 2) || !strncmp(brightness, "M4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M0

		if (!strncmp(brightness, "M5", 2) || !strncmp(brightness, "M6", 2) || !strncmp(brightness, "M7", 2) || !strncmp(brightness, "M8", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M5

		if (!strncmp(brightness, "M9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 0; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;
			case 14: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M9

	}//end star size 1

	//***************SIZE II **************************************
	if (!strncmp(starsize, "II", 1)){
		if (!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;


			default: orbit = 1;

			} //end switch
		} //end B0

		if (!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;
			} //end switch

		} //end B5


		if (!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 2; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A0


		if (!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A5

		if (!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;


			default: orbit = 1;

			} //end switch

		} //end F0

		if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F5

		if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G0

		if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G5

		if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 2; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K0

		if (!strncmp(brightness, "K5", 2) || !strncmp(brightness, "K6", 2) || !strncmp(brightness, "K7", 2) || !strncmp(brightness, "K8", 2) || !strncmp(brightness, "K9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 2; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K5

		if (!strncmp(brightness, "M0", 2) || !strncmp(brightness, "M1", 2) || !strncmp(brightness, "M2", 2) || !strncmp(brightness, "M3", 2) || !strncmp(brightness, "M4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M0

		if (!strncmp(brightness, "M5", 2) || !strncmp(brightness, "M6", 2) || !strncmp(brightness, "M7", 2) || !strncmp(brightness, "M8", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M5

		if (!strncmp(brightness, "M9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 2; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M9

	}//end star size II

	//***************SIZE III **************************************
	if (!strncmp(starsize, "III", 3)){
		if (!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;


			default: orbit = 1;

			} //end switch
		} //end B0

		if (!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 2; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;
			} //end switch

		} //end B5


		if (!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A0


		if (!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 2; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A5

		if (!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 2; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;


			default: orbit = 1;

			} //end switch

		} //end F0

		if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 2; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F5

		if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 2; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G0

		if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 2; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G5

		if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 2; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K0

		if (!strncmp(brightness, "K5", 2) || !strncmp(brightness, "K6", 2) || !strncmp(brightness, "K7", 2) || !strncmp(brightness, "K8", 2) || !strncmp(brightness, "K9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K5

		if (!strncmp(brightness, "M0", 2) || !strncmp(brightness, "M1", 2) || !strncmp(brightness, "M2", 2) || !strncmp(brightness, "M3", 2) || !strncmp(brightness, "M4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 2; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M0

		if (!strncmp(brightness, "M5", 2) || !strncmp(brightness, "M6", 2) || !strncmp(brightness, "M7", 2) || !strncmp(brightness, "M8", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 2; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M5

		if (!strncmp(brightness, "M9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 2; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M9

	}//end star size III


	//***************SIZE IV **************************************
	if (!strncmp(starsize, "IV", 2)){
		if (!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 0; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 2; break;
			case 13: orbit = 1; break;


			default: orbit = 1;

			} //end switch
		} //end B0

		if (!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 2; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;
			} //end switch

		} //end B5


		if (!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 2; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A0


		if (!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 2; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end A5

		if (!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 2; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;


			default: orbit = 1;

			} //end switch

		} //end F0

		if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 2; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F5

		if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 2; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G0

		if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 2; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G5

		if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 2; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K0

		

	}//end star size IV

	//***************SIZE V **************************************
	if (!strncmp(starsize, "V", 1)){
		if (!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2)){

			switch (orbit_ring){
			case 0: orbit = 0; break;
			case 1: orbit = 0; break;
			case 2: orbit = 0; break;
			case 3: orbit = 0; break;
			case 4: orbit = 0; break;
			case 5: orbit = 0; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
				case 12: orbit = 2; break;
				case 13: orbit = 1; break;

				default: orbit = 1;

			} //end switch
		} //end B0

		if (!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)){

			switch (orbit_ring){
				case 0: orbit = 0;break;
				case 1: orbit = 0; break;
				case 2: orbit = 0; break;
				case 3: orbit = 0; break;
				case 4: orbit = 1; break;
				case 5: orbit = 1; break;
				case 6: orbit = 1; break;
				case 7: orbit = 1; break;
				case 8: orbit = 1; break;
				case 9: orbit = 2; break;
				case 10: orbit = 1; break;
				case 11: orbit = 1; break;
				case 12: orbit = 1; break;
				case 13: orbit = 1; break;

				default: orbit = 1;
			} //end switch

		} //end B5


		if (!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 2; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

				default: orbit = 1;

			} //end switch

		} //end A0


		if (!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 2; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;
			
				default: orbit = 1;

			} //end switch

		} //end A5

		if (!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 2; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F0

		if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 2; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end F5

		if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 2; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G0

		if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 2; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end G5

		if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 2; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K0

		if (!strncmp(brightness, "K5", 2) || !strncmp(brightness, "K6", 2) || !strncmp(brightness, "K7", 2) || !strncmp(brightness, "K8", 2) || !strncmp(brightness, "K9", 2)){

			switch (orbit_ring){
			case 0: orbit = 2; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K5

		if (!strncmp(brightness, "M0", 2) || !strncmp(brightness, "M1", 2) || !strncmp(brightness, "M2", 2) || !strncmp(brightness, "M3", 2) || !strncmp(brightness, "M4", 2)){

			switch (orbit_ring){
			case 0: orbit = 2; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M0

		if (!strncmp(brightness, "M5", 2) || !strncmp(brightness, "M6", 2) || !strncmp(brightness, "M7", 2) || !strncmp(brightness, "M8", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError==0)){
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable > 0 Brightness=%s, orbit M5-M8 hex=%s sector=%s\n", currentworld, brightness, sec_world[currentworld].hex,sectorfilename);
				fprintf(ERR, "Missmatch with a habitable world located in an unhabitable location.  Bad system data?\n");
				fclose(ERR);
				PlanetError = 1; //set error flag
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)){
				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M5

		if (!strncmp(brightness, "M9", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)){
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable > 0 Brightness=%s, orbit M9 hex=%s sector:%s\n", currentworld,brightness, sec_world[currentworld].hex,sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}

			if (sec_world[currentworld].habitable > 0){
				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;
			case 5: orbit = 1; break;
			case 6: orbit = 1; break;
			case 7: orbit = 1; break;
			case 8: orbit = 1; break;
			case 9: orbit = 1; break;
			case 10: orbit = 1; break;
			case 11: orbit = 1; break;
			case 12: orbit = 1; break;
			case 13: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M9

	}//end star size V

	//***************SIZE VI **************************************
	
	if (!strncmp(starsize, "VI", 2)){

		if ((remaining_rings > 5) && (PlanetError == 0)){
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     remaining_rings >5\n     Brightness=%s, Starsize=%s hex=%s sector=%\n", brightness, starsize, sec_world[currentworld].hex, sectorfilename);
			fprintf(ERR, ".     Only max 5 orbits allowed for star size VI.\n");
			fclose(ERR);
			PlanetError = 1;
			return -1; //only 5 orbits allowed

		}
		if (remaining_rings > 5){

			return -1; //only 5 orbits allowed

		}

		if ((!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2) ||
			!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)) && (PlanetError == 0)){

			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     unavailable orbit for planet for star size (bad star size?)\n     Brightness=%s, Size=%s hex=%s sector=%s\n", brightness, starsize, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1; //these orbits do not exist. bad data if they do
		}
		if ((!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2) ||
			!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2))){

			return -1; //these orbits do not exist. bad data if they do
		}

		if ((!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2) ||
			!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)) && (PlanetError == 0)){

			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     unavailable orbit for planet for star size\n     Brightness=%s, Size=%s hex=%s sector=%s\n", brightness, starsize, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1; //these orbits do not exist. bad data if they do
		}
		if ((!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2) ||
			!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2))){

			return -1; //these orbits do not exist. bad data if they do
		}

		if ((!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)) && (PlanetError == 0)) {

			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     unavailable orbit for planet for star size\n     Brightness=%s, Size=%s hex=%s sector=%s\n", brightness, starsize, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1; //these orbits do not exist. bad data if they do
		}
		if ((!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2))) {

			return -1; //these orbits do not exist. bad data if they do
		}

		if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)){

			
			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 2; break;
			case 4: orbit = 1; break;


			default: orbit = 1;

			} //end switch

		} //end F5

		if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 2; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;


			default: orbit = 1;

			} //end switch

		} //end G0

		if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 2; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;


			default: orbit = 1;

			} //end switch

		} //end G5

		if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)){

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 2; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K0

		if (!strncmp(brightness, "K5", 2) || !strncmp(brightness, "K6", 2) || !strncmp(brightness, "K7", 2) || !strncmp(brightness, "K8", 2) || !strncmp(brightness, "K9", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)) {
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)) {

				return -1;
			}
			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end K5

		if (!strncmp(brightness, "M0", 2) || !strncmp(brightness, "M1", 2) || !strncmp(brightness, "M2", 2) || !strncmp(brightness, "M3", 2) || !strncmp(brightness, "M4", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)){
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)){

				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M0

		if (!strncmp(brightness, "M5", 2) || !strncmp(brightness, "M6", 2) || !strncmp(brightness, "M7", 2) || !strncmp(brightness, "M8", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)){
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s\n",currentworld, brightness, starsize, sec_world[currentworld].hex);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)){

				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end M5

		if (!strncmp(brightness, "M9", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)){

				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)){

				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;
			case 4: orbit = 1;

			default: orbit = 1;

			} //end switch

		} //end M9

	}//end star size VI

	//***************SIZE D **************************************

	if (!strncmp(starsize, "D", 1)){

		if ((remaining_rings > 4) && (PlanetError == 0)) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     remaining_rings>4\n     Brightness=%s, Size=%s hex=%s sector=%s\n", brightness, starsize, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1; //only 5 orbits allowed
		}
		if ((remaining_rings > 4)) {

			return -1; //only 5 orbits allowed
		}

		if (!strncmp(brightness, "DB", 2)){

			switch (orbit_ring){
			case 0: orbit = 2; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end DB

		if (!strncmp(brightness, "DA", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)){

				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)){

				return -1;
			}

				switch (orbit_ring){
				case 0: orbit = 1; break;
				case 1: orbit = 1; break;
				case 2: orbit = 1; break;
				case 3: orbit = 1; break;

				default: orbit = 1;

				} //end switch

		} //end DA

		if (!strncmp(brightness, "DF", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)){
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)){

				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end DF

		if (!strncmp(brightness, "DG", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)){
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)){

				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end DG

		if (!strncmp(brightness, "DK", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)) {
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)) {

				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end DK

		if (!strncmp(brightness, "DM", 2)){

			if ((sec_world[currentworld].habitable > 0) && (PlanetError == 0)) {
				ERR = fopen("error.txt", "a");
				fprintf(ERR, "planetorbit.c\n     sec_world[%d].habitable>0 Brightness=%s, Size=%s hex=%s sector=%s\n", currentworld, brightness, starsize, sec_world[currentworld].hex, sectorfilename);
				fclose(ERR);
				PlanetError = 1;
				return -1;
			}
			if ((sec_world[currentworld].habitable > 0)) {

				return -1;
			}

			switch (orbit_ring){
			case 0: orbit = 1; break;
			case 1: orbit = 1; break;
			case 2: orbit = 1; break;
			case 3: orbit = 1; break;

			default: orbit = 1;

			} //end switch

		} //end DM

	}//end star size D


	return orbit;

}

int planetorbits(char *starsize, char *brightness)
{
	int planets = 0; //numbers of planets
	int belts = 0; //asteroid belts
	int gasgiants = 0; //number of gas giants in system
	//char starsize[4]; //I,II,III,IV,V,VI,D
	//char brightness[3];
	double seeduwp=0.0;
	int orbit_ring=0;
	int orbit_type=0;
	int orbitringstart = 0;
	int max_ring = 0;
	int remaining_rings = 0;
	int homeworld = 0; //if 1 then homeworld has been placed;
	int habitable = 0; //if 1 then world is to go in habitable zone;
	int gascount = 0;
	int x = 0;
	int ring_zero = 0;
	double audistance = 0.0;
	int validatestar = 0;
	int validatebright = 0;
	char systemrings[15];
	char charring[2];
	int inc = 0;
	char startemp[81];
	char uwpchar[255];
	char charuwp[10] = "         ";
	int hexnum = 0;
	int deduct = 0;
	char *tmpuwp;
	


	sprintf(charuwp, sec_world[currentworld].uwp);
	charuwp[7] = '\0';
	hexnum = atoi(sec_world[currentworld].hex);


	sprintf(uwpchar, ".%d%d%d%d%d%d%d", charuwp[0], charuwp[1], charuwp[2], charuwp[3], charuwp[4], charuwp[5], charuwp[6]);
	seeduwp = strtod(uwpchar, &tmpuwp) + (hexnum*.000001);

	rseed = seeduwp; //random seed is based on the unique UWP positions 0 through 4 (5 places) + .000001 X hexnumber

	validatestar = 0;  //set validation flag
	validatebright = 0;

	//**************Validate star size and brightness syntax. exit if incorrect format
	if (!strncmp(starsize, "0", 1) || !strncmp(starsize, "O", 1) || !strncmp(starsize, "1", 1) || !strncmp(starsize, "I", 1)) { max_ring = 14; validatestar = 1; }
	if (!strncmp(starsize, "II", 2) || !strncmp(starsize, "III", 3)){ max_ring = 13; validatestar = 1; }
	if (!strncmp(starsize, "IV", 2) || !strncmp(starsize, "V", 1)) {
		max_ring = 13;
		ring_zero = 1;
		validatestar = 1;
	}
	if (!strncmp(starsize, "VI", 2)) {
		max_ring = 4; 
		ring_zero = 1;
		validatestar = 1;
	}

	if (!strncmp(starsize, "VII", 3)) {
		sprintf(starsize, "D");
	}

	if (!strncmp(starsize, "D", 1)) {
		max_ring = 3; 
		ring_zero = 1;
		validatestar = 1;
	}

	if (!strncmp(brightness, "B0", 2) || !strncmp(brightness, "B1", 2) || !strncmp(brightness, "B2", 2) || !strncmp(brightness, "B3", 2) || !strncmp(brightness, "B4", 2)) validatebright = 1;
	if (!strncmp(brightness, "B5", 2) || !strncmp(brightness, "B6", 2) || !strncmp(brightness, "B7", 2) || !strncmp(brightness, "B8", 2) || !strncmp(brightness, "B9", 2)) validatebright = 1;
	if (!strncmp(brightness, "A0", 2) || !strncmp(brightness, "A1", 2) || !strncmp(brightness, "A2", 2) || !strncmp(brightness, "A3", 2) || !strncmp(brightness, "A4", 2)) validatebright = 1;
	if (!strncmp(brightness, "A5", 2) || !strncmp(brightness, "A6", 2) || !strncmp(brightness, "A7", 2) || !strncmp(brightness, "A8", 2) || !strncmp(brightness, "A9", 2)) validatebright = 1;
	if (!strncmp(brightness, "F0", 2) || !strncmp(brightness, "F1", 2) || !strncmp(brightness, "F2", 2) || !strncmp(brightness, "F3", 2) || !strncmp(brightness, "F4", 2)) validatebright = 1;
	if (!strncmp(brightness, "F5", 2) || !strncmp(brightness, "F6", 2) || !strncmp(brightness, "F7", 2) || !strncmp(brightness, "F8", 2) || !strncmp(brightness, "F9", 2)) validatebright = 1;
	if (!strncmp(brightness, "G0", 2) || !strncmp(brightness, "G1", 2) || !strncmp(brightness, "G2", 2) || !strncmp(brightness, "G3", 2) || !strncmp(brightness, "G4", 2)) validatebright = 1;
	if (!strncmp(brightness, "G5", 2) || !strncmp(brightness, "G6", 2) || !strncmp(brightness, "G7", 2) || !strncmp(brightness, "G8", 2) || !strncmp(brightness, "G9", 2)) validatebright = 1;
	if (!strncmp(brightness, "K0", 2) || !strncmp(brightness, "K1", 2) || !strncmp(brightness, "K2", 2) || !strncmp(brightness, "K3", 2) || !strncmp(brightness, "K4", 2)) validatebright = 1;
	if (!strncmp(brightness, "K5", 2) || !strncmp(brightness, "K6", 2) || !strncmp(brightness, "K7", 2) || !strncmp(brightness, "K8", 2) || !strncmp(brightness, "K9", 2)) validatebright = 1;
	if (!strncmp(brightness, "M0", 2) || !strncmp(brightness, "M1", 2) || !strncmp(brightness, "M2", 2) || !strncmp(brightness, "M3", 2) || !strncmp(brightness, "M4", 2)) validatebright = 1;
	if (!strncmp(brightness, "M5", 2) || !strncmp(brightness, "M6", 2) || !strncmp(brightness, "M7", 2) || !strncmp(brightness, "M8", 2) || !strncmp(brightness, "M9", 2)) validatebright = 1;
	if (!strncmp(brightness, "DB", 2) || !strncmp(brightness, "DA", 2) || !strncmp(brightness, "DF", 2) || !strncmp(brightness, "DG", 2) || !strncmp(brightness, "DK", 2)) validatebright = 1;
	if (!strncmp(brightness, "DM", 2)) validatebright = 1;

	if (((validatebright == 0) || (validatestar == 0)) && (PlanetError == 0)){
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "planetorbit.c\n     validatebright or validatestar = 0 meaning brightness and size are not compatible with each other\n     Brightness=%s, Size=%s hex=%s sector=%s\n", brightness, starsize, sec_world[currentworld].hex, sectorfilename);
		fclose(ERR);
		PlanetError = 1;
		return -1;
	}
	if (((validatebright == 0) || (validatestar == 0))){

		return -1;
	}

	strncpy(systemrings, "00000000000000\0", 15);
	for (x = 0; x <= max_ring; x++){
		systemrings[x] = '-';
	}


	srand((unsigned int)rseed);


	homeworld = 1;  //set default for main world placement
	habitable = 0; //clear habitable

	deduct = 0;  //total deduction of unavailable rings

	planets = sec_world[currentworld].NumPlanets; //numbers of planets
	belts = sec_world[currentworld].Belts; //asteroid belts
	gasgiants = sec_world[currentworld].GasGiant; //number of gas giants in system
	habitable = sec_world[currentworld].habitable;
	gascount = gasgiants;

	remaining_rings = belts+planets+gasgiants;

	if ((remaining_rings <= 0) && (PlanetError == 0)) {
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "planetorbit.c\n     remaining_rings(%d)<=0 hex=%s sector=%s\n", remaining_rings, sec_world[currentworld].hex, sectorfilename);
		fclose(ERR);
		PlanetError = 1;
		return -1;
	}
	if ((remaining_rings <= 0)) {

		return -1;
	}

	if ((remaining_rings > max_ring) && (PlanetError == 0)){
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "planetorbit.c\n     remaining_rings(%d)>max_ring(%d) hex=%s sector=%s\n", remaining_rings, max_ring, sec_world[currentworld].hex, sectorfilename);
		fclose(ERR);
		PlanetError = 1;
		return -1;
	}
	if ((remaining_rings > max_ring)){

		return -1;
	}

	//validate all rings for 0

	for (x = ring_zero; x <= max_ring; x++)
	{
		orbit_type = validate_orbit(starsize, brightness, x,remaining_rings);

		if ((orbit_type<0) && (PlanetError == 0)){
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     orbit_type(%d)<0 hex=%s sector=%s\n", orbit_type, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1;
		}
		if (orbit_type<0){

			return -1;
		}

		if (orbit_type == 0) deduct++;
	}

	if (((remaining_rings + deduct) > max_ring) && (PlanetError == 0)) {
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "planetorbit.c\n     (remaining_rings + deduct) > max_ring hex=%s sector=%s\n", sec_world[currentworld].hex, sectorfilename);
		fclose(ERR);
		PlanetError = 1;
		return -1;
	}

	if (((remaining_rings + deduct) > max_ring)) {

		return -1;
	}

	//place  homeworld first

	while (homeworld == 1){
		x = (rand() % (max_ring+1));
		if (ring_zero>0){
			if (x > max_ring) x = 0; //set orbit 0
		}
		if (ring_zero == 0){
			if (x > max_ring) x = 1;
		}
		if (ring_zero == 0){
			if (x==0) x = 1;
		}

		orbit_type = validate_orbit(starsize, brightness, x,remaining_rings); //for star 1 only

		if ((orbit_type < 1) && (PlanetError == 0)) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     HOMEWORLD orbit_type<1 for starsize=%s and brightness=%s and remaining_rings=%d and x=%d hex=%s sector=%s\n", starsize, brightness, remaining_rings, x, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1;
		}
		if (orbit_type < 1) {

			return -1;
		}

		if ((orbit_type == 2) && (systemrings[x] == '-')&& (habitable==1)) {
			systemrings[x] = 'H';
			remaining_rings--;
			homeworld = 0;
		}
		else
		if ((orbit_type == 1) && (systemrings[x] == '-')&&(habitable==0)) {
			systemrings[x] = 'H';
			remaining_rings--;
			homeworld = 0;
		}
	}

	//do gas placement
	while (gascount > 0){

		x = (rand() % max_ring+2);
		if (ring_zero>0){
			if (x > max_ring) x = 0; //set orbit 0
		}
		if (ring_zero == 0){
			if (x > max_ring) x = 1;
		}
		orbit_type = validate_orbit(starsize, brightness, x,remaining_rings); //for star 1 only

		if ((orbit_type < 1) && (PlanetError == 0)){
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     GAS GIANT orbit_type<1 for starsize=%s and brightness=%s and remaining_rings=%d and x=%d hex=%s sector=%s\n", starsize, brightness, remaining_rings, x, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1;
		}
		if (orbit_type < 1){

			return -1;
		}

		if ((orbit_type == 0)&&(systemrings[x] == '-')) {
			systemrings[x] = ' ';
			remaining_rings--;
		}
		else
		if (orbit_type > 0){
			if (systemrings[x] == '-'){
				systemrings[x] = 'G';
				gascount--;
				remaining_rings--;
				if ((belts > 0) && (systemrings[x - 1] == '-')){
					systemrings[x - 1] = 'B';
					remaining_rings--;
					belts--;
				}
				else if ((belts > 0) && (systemrings[x + 1] == '-') && (x <= max_ring)){
					systemrings[x + 1] = 'B';
					remaining_rings--;
					belts--;
				}
			}
		}
	}//end gas giant placement

	//do belts

	while ((remaining_rings > 0) && (belts > 0)){
		x = (rand() % (max_ring + 2));
		if (ring_zero>0){
			if (x > max_ring) x = 0; //set orbit 0
		}
		if (ring_zero == 0){
			if (x > max_ring) x = 1;
		}

		orbit_type = validate_orbit(starsize, brightness, x,remaining_rings); //for star 1 only

		if ((orbit_type<1) && (PlanetError == 0)){
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     BELTS orbit_type<1 for starsize=%s and brightness=%s and remaining_rings=%d and x=%d hex=%s sector=%s\n", starsize, brightness, remaining_rings, x, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1;
		}
		if (orbit_type<1){

			return -1;
		}

		if ((orbit_type > 0) && (systemrings[x] == '-')){
			systemrings[x] = 'B'; //clear a ring-unavailable ring
			remaining_rings--;
			belts--;
		}

	}

	while (remaining_rings > 0){

		x = (rand() % (max_ring+2));
		if (ring_zero>0){ 
			if(x > max_ring) x = 0; //set orbit 0
			}
		if (ring_zero == 0){
			if (x > max_ring) x = 1;
		}

		orbit_type = validate_orbit(starsize, brightness, x,remaining_rings); //for star 1 only

		if ((orbit_type < 1) && (PlanetError == 0)) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planetorbit.c\n     while remaining_rings>0  orbit_type<1 for starsize=%s and brightness=%s and remaining_rings=%d and x=%d hex=%s sector=%s\n", starsize, brightness, remaining_rings, x, sec_world[currentworld].hex, sectorfilename);
			fclose(ERR);
			PlanetError = 1;
			return -1;
		}
		if (orbit_type < 1) {

			return -1;
		}

		if ((orbit_type == 0)&&(systemrings[x]=='-')){
			systemrings[x] = ' '; //clear a ring-unavailable ring
			remaining_rings--;
		}
		else
		if ((orbit_type > 0) && (systemrings[x] == '-')){
				systemrings[x] = 'P'; //place a planet
				remaining_rings--;
		}

	}

	//Clear out the rest of the empty orbits
	if (ring_zero == 0){
		for (orbit_ring = 1; orbit_ring <= max_ring; orbit_ring++)
		{
			if (systemrings[orbit_ring] == '-'){
				systemrings[orbit_ring] = ' ';
			}
		}
	}
	if (ring_zero == 1){
		for (orbit_ring = 0; orbit_ring <= max_ring; orbit_ring++)
		{
			if (systemrings[orbit_ring] == '-'){
				systemrings[orbit_ring] = ' ';
			}
		}
	}


	if (ring_zero == 0) orbitringstart = 1;
	if (ring_zero == 1) orbitringstart = 0;


	inc = 170;  //y location for displaying text data

	for (orbit_ring = orbitringstart; orbit_ring <= max_ring; orbit_ring++)
		{

		switch (orbit_ring){
		case 0: audistance = 0.2; break;
		case 1: audistance = 0.4; break;
		case 2: audistance = 0.7; break;
		case 3: audistance = 1; break;
		case 4: audistance = 1.6; break;
		case 5: audistance = 2.8; break;
		case 6: audistance = 5.2; break;
		case 7: audistance = 10; break;
		case 8: audistance = 19.6; break;
		case 9: audistance = 38.8; break;
		case 10: audistance = 77.2; break;
		case 11: audistance = 154; break;
		case 12: audistance = 307.6; break;
		case 13: audistance = 614.8; break;
		case 14: audistance = 1229.2; break;

		default: audistance = 0;

		} //end switch}

		strncpy(charring, &systemrings[orbit_ring], 1);
			charring[1] = '\0';
			if (strncmp(charring, " ", 1)){
				sprintf(startemp, "%d\0", orbit_ring);
				Courier10Black->draw(irr::core::stringw(startemp).c_str(), core::rect<s32>(855, inc, 0, 0), video::SColor(255, 255, 255, 0));//orbit ring
				sprintf(startemp, "%.1f\0", audistance);
				Courier10Black->draw(irr::core::stringw(startemp).c_str(), core::rect<s32>(965, inc, 0, 0), video::SColor(255, 255, 255, 0));//orbit distance

				if (!strncmp(charring, "P", 1)) driver->draw2DImage(plnormal, core::position2d<s32>(920, inc), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
				if (!strncmp(charring, "G", 1)) driver->draw2DImage(plgarden, core::position2d<s32>(920, inc), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
				if (!strncmp(charring, "B", 1)) driver->draw2DImage(plasteroid, core::position2d<s32>(920, inc), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
				if (!strncmp(charring, "H", 1)) driver->draw2DImage(plwater, core::position2d<s32>(920, inc), core::rect<s32>(0, 0, 20, 20), 0, video::SColor(255, 255, 255, 255), true);
			}

			inc += 30;
		}

	tmpuwp = '\0';
	
	return 0;
}


