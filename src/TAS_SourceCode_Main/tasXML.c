
void ReadAccountFile(void)

{

	if (!(fd = fopen("accounts/users/account.xml", "r")))
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "accounts/users/account.xml file \n");
		fclose(ERR);
		exit(1);
	}
	else fclose(fd);

	IrrlichtDevice* NullDevice = irr::createDevice(irr::video::EDT_NULL);
	IXMLReader* xml = NullDevice->getFileSystem()->createXMLReader("accounts/users/account.xml");


	while (xml && xml->read())
	{   //read up to 199 members with membernumbers 1-199
		if (core::stringw("membership") == xml->getNodeName())
		{
			MemberNumber = xml->getAttributeValueAsInt(L"MEMNUM");
			TASMember[MemberNumber].MemberNumber = MemberNumber;
			sprintf(TASMember[MemberNumber].uName, "%ls", xml->getAttributeValueSafe(L"NAME"));
			sprintf(TASMember[MemberNumber].uPass, "%ls", xml->getAttributeValueSafe(L"PASSWORD"));
			sprintf(TASMember[MemberNumber].UPP, "%ls", xml->getAttributeValueSafe(L"UPP"));
			sprintf(TASMember[MemberNumber].uHomeWorld, "%ls", xml->getAttributeValueSafe(L"HOMEWORLD"));
			sprintf(TASMember[MemberNumber].uRace, "%ls", xml->getAttributeValueSafe(L"RACE"));
			TASMember[MemberNumber].MarkerSectorNumber = xml->getAttributeValueAsInt(L"CURRSEC");
			TASMember[MemberNumber].MarkerHex = xml->getAttributeValueAsInt(L"CURRHEX");
			sprintf(TASMember[MemberNumber].MarkerSubSector, "%ls", xml->getAttributeValueSafe(L"CURRSUBSEC"));
			TASMember[MemberNumber].uAccessLevel = xml->getAttributeValueAsInt(L"AL");
			TASMember[MemberNumber].MarkerX = xml->getAttributeValueAsInt(L"MARKERX");
			TASMember[MemberNumber].MarkerY = xml->getAttributeValueAsInt(L"MARKERY");
			TASMember[MemberNumber].TASMemberHidden = xml->getAttributeValueAsInt(L"HIDDENTASMEMBER");
		}

	} //end of while 

	// don't forget to delete the xml reader
	xml->drop();

}

void WriteAccountFile(void)
{
	int x;

	if (!(fd = fopen("accounts/users/account.xml", "w")))
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not open accounts/users/account.xml file to WRITE \n");
		fclose(ERR);
		exit(1);
	}

	fprintf(fd, "<?xml version = \"1.0\"?>\n");
	fprintf(fd, "<!--Travellers' Aid Society Access Terminal\n");
	fprintf(fd, "     ACCOUNT.XML initialization file\n\n");

	fprintf(fd, "NOTE : Each record / account entry must follow the below order and format :\n");

	fprintf(fd, "MEMNUM = TAS Membership number 1 - 199\n");
	fprintf(fd, "NAME = user name[up to 15 characters]\n");
	fprintf(fd, "PW = password[up to 15 characters]\n");
	fprintf(fd, "UPP = UPP of the character[ex:777777]\n");
	fprintf(fd, "HW = Homeworld\n");
	fprintf(fd, "RA = Race\n");
	fprintf(fd, "CURRSEC = Current sector number\n");
	fprintf(fd, "CURRHEX = Current hex location\n");
	fprintf(fd, "CURRSUBSEC= Current subsector letter\n"); 
	fprintf(fd, "AL = access level[number]\n");
	fprintf(fd, "MARKERX = X coordinates for hex marker\n");
	fprintf(fd, "MARKERY = Y coordinates for hex marker\n");
	fprintf(fd, "HIDDENTASMEMBER = flag to hide account 0 = not hidden 1 = hidden\n");

	fprintf(fd, "-->\n\n");
	fprintf(fd, "<users>\n");
	for (x = 0; x < 200; x++)
	{
		if (TASMember[x].MemberNumber > 0)
		{
			fprintf(fd, "<membership MEMNUM = \"%d\" NAME = \"%s\" PASSWORD = \"%s\" UPP = \"%s\" HOMEWORLD = \"%s\" RACE = \"%s\" CURRSEC = \"%d\" CURRHEX = \"%d\" CURRSUBSEC=\"%s\" AL = \"%d\" MARKERX = \"%d\"  MARKERY = \"%d\" HIDDENTASMEMBER = \"%d\" />\n",
				TASMember[x].MemberNumber, TASMember[x].uName, TASMember[x].uPass, TASMember[x].UPP,
				TASMember[x].uHomeWorld, TASMember[x].uRace, TASMember[x].MarkerSectorNumber,
				TASMember[x].MarkerHex, TASMember[x].MarkerSubSector,TASMember[x].uAccessLevel,
				TASMember[x].MarkerX, TASMember[x].MarkerY, TASMember[x].TASMemberHidden);
		}
	}
	fprintf(fd, "</users>\n");
	fprintf(fd, "</xml>\n");
	fclose(fd);
}

void ReadINIFile(void)
{
	char line[128] = "\0", modline[80] = "\0";
	int inputoffset = 0;
	float tempversion = 0.0;

	inputoffset = 1; //default for Windows

#if defined(__APPLE__) || defined(macintosh) || defined(OSX)
	inputoffset = 2;
#endif
#if defined(unix) || defined(__unix__) || defined(__linux__)
	inputoffset = 2;
#endif
#if defined(_WIN32_WCE) || defined(WIN32) || defined(_WIN32)
	inputoffset = 1;
#endif

	fd = NULL; //verify file pointer is clear

	Era = 1; //set default era to classic traveller

	if (!(fd = fopen("tas.xml", "r")))
	{
		fprintf(stderr, "Unable to read tas.xml file \n");
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Unable to read tas.xml file \n");
		fclose(ERR);
		exit(1);
	}
	else fclose(fd);

	IrrlichtDevice* NullDevice = irr::createDevice(irr::video::EDT_NULL);
	IXMLReader* xml = NullDevice->getFileSystem()->createXMLReader("tas.xml");

	while (xml && xml->read())
	{
		if (core::stringw("attributes") == xml->getNodeName())
		{
			tempversion = xml->getAttributeValueAsFloat(L"version");
			Era = xml->getAttributeValueAsInt(L"era");
			TASYear = xml->getAttributeValueAsInt(L"year");
			TASDay = xml->getAttributeValueAsInt(L"day");
			if (TASDay - 6 > 0)
			{
				NEWSDay = TASDay - 6;
			}
			else
			{
				NEWSDay = 1;
			}
		//}
		//else
		//	if (core::stringw("accesslevel") == xml->getNodeName())
		//	{
				ALNAVLIB = xml->getAttributeValueAsInt(L"ALNAVLIB");
				ALNAVFLEET = xml->getAttributeValueAsInt(L"ALNAVFLEET");
				ALNEWS = xml->getAttributeValueAsInt(L"ALNEWS");
				ALLIBDATA = xml->getAttributeValueAsInt(L"ALLIBDATA");
				ALACCNT = xml->getAttributeValueAsInt(L"ALACCNT");
				ALCLASS = xml->getAttributeValueAsInt(L"ALCLASS");
				ALMERC = xml->getAttributeValueAsInt(L"ALMERC");
				ALXBT = xml->getAttributeValueAsInt(L"ALXBT");
				ALSPECCOLL = xml->getAttributeValueAsInt(L"ALSPECCOLL");
			}
	} //end of while xml

	// don't forget to delete the xml reader
	xml->drop();


	//******Set Era *****
	if (Era == 1){
		sprintf(SectorDirectory, "sectors/classic");
		sprintf(EraName, "classic");
	}
	else
		if (Era == 2){
			sprintf(SectorDirectory, "sectors/tne");
			sprintf(EraName, "tne");
		}
		else
			if (Era == 3){
				sprintf(SectorDirectory, "sectors/m0");
				sprintf(EraName, "m0");
			}
			else
				if (Era == 4){
					sprintf(SectorDirectory, "sectors/custom");
					sprintf(EraName, "custom");
				}
				else
					if (Era == 5){
						sprintf(SectorDirectory, "sectors/T5");
						sprintf(EraName, "T5");
					}
					else
						if (Era == 0){
							Era = 1;
							sprintf(SectorDirectory, "sectors/classic"); //default if INI is corrupt
							sprintf(EraName, "classic");
						}

}

void WriteINIFile(void)
{


	if (!(fd = fopen("tas.xml", "w")))
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not open tas.xml file to WRITE \n");
		fclose(ERR);
		exit(1);
	}

	fprintf(fd, "<?xml version = \"1.0\"?>\n");
	fprintf(fd, "<!--Travellers' Aid Society Access Terminal\n");
	fprintf(fd, "     TAS.XML initialization file\n\n");

	fprintf(fd, "NOTE : the attributes must follow the below order and format :\n");

		fprintf(fd, "Set era for resources\n");
		fprintf(fd, "1 = Classic / MegaTraveller 1070 - 1116\n");
		fprintf(fd, "2 = Traveller the New Era 1116 + (1200)\n");
		fprintf(fd, "3 = Milieu 0 (T4)\n");
		fprintf(fd, "4 = Custom\n");
		fprintf(fd, "5 = T5(not implemented yet - 09 / 2016\n\n");

		fprintf(fd, "Set Current Year(ie 1085)\n");
		fprintf(fd, "Set Current Day(1 - 365)\n\n");

		fprintf(fd, "Access levels range from 0 to 10\n");
		fprintf(fd, "0 = basic user\n");
		fprintf(fd, "1 = TAS charter membership\n");
		fprintf(fd, "2 - 9 are members with access to special areas\n");
		fprintf(fd, "10 = Administrator(Referee)\n\n");

		fprintf(fd, "Set access level number for each area for access\n\n");

		fprintf(fd, "ALNAVLIB = Navigation Library\n");
		fprintf(fd, "ALNAVFLEET = Sector Fleet Information\n");
		fprintf(fd, "ALNEWS = TAS News Service\n");
		fprintf(fd, "ALLIBDATA = Library Data\n");
		fprintf(fd, "ALACCNT = Account Services\n");
		fprintf(fd, "ALCLASS = Classifieds\n");
		fprintf(fd, "ALMERC = Classifieds - Missions / Mercenary tickets\n");
		fprintf(fd, "ALXBT = Xboat Communication Message Services\n");
		fprintf(fd, "ALSPECCOLL = Special Collections Library access-->\n");

		fprintf(fd, "<attributes version=\"%s\" era=\"%d\" year=\"%d\" day=\"%d\" ALNAVLIB=\"%d\" ALNAVFLEET=\"%d\" ALNEWS=\"%d\" ALLIBDATA=\"%d\" ALACCNT=\"%d\" ALCLASS=\"%d\" ALMERC=\"%d\" ALXBT=\"%d\" ALSPECCOLL=\"%d\" />\n",
			TASVersion, Era, TASYear, TASDay, ALNAVLIB, ALNAVFLEET, ALNEWS, ALLIBDATA, ALACCNT, ALCLASS, ALMERC, ALXBT, ALSPECCOLL);
		fprintf(fd, "</xml>\n");
		fclose(fd);
		
}