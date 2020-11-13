/* 
	Traveller's Aid Society Access Terminal

	     by Perry Horner 2001
	  

  The Traveller® game in all forms is owned by Far Future Enterprises. 
  Copyright 1977 - 2015 Far Future Enterprises. Traveller® is a registered 
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
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#ifndef FALSE
#define FALSE 0
#endif
 
#ifndef TRUE
#define TRUE (!FALSE)
#endif


#if defined(__APPLE__)
	typedef int bool;
#endif
#if defined(__linux__)
	typedef int bool;
#endif



// DEFINITIONS /////////////////////////////////////////////////////

#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=NULL; } }
#define NUM_HEX_PTS   7
#define NUM_HEXES     8     //8
#define NUM_LINES     10    //10
#define LINE_INC    50      //100
#define HEXSTART_X_LOC  50  //starting hex x location on screen 
#define HEXSTART_Y_LOC  50  //starting hex y location on screen
#define BORDER_X_ADJ  50    //adjust x loc
#define BORDER_Y_ADJ  -4    //adjust y loc
#define TRADE_X_ADJ   50    //adjust x loc
#define TRADE_Y_ADJ   -15   //adjust y loc


#define PAD          16   //16
#define HEX_PAD       4   //4

#define NUM_FONTS     6   //5 fonts to be used
#define NUM_SPRITES   18  //bitmap images for map


#define SAVESUBSECBMP -9  //save subsector to bitmap file
#define RETURNSECMENU -10 //return to sector menu

//XBOAT
#define XBOATREADOLDMENU 38 //xboat READ old messages window
#define XBOATREADNEWMENU 37 //main xboat READ new messaging window
#define XBOATREADMENU 36 //main xboat READ messaging window
#define XBOATSENDMENU 35 //main xboat SEND messaging window
#define XBOATMENU 34 //main xboat messaging window

//Classifieds

#define HELPWANTEDMENU 33 //help wanted ads
#define MISSIONSWINDOW 32 //mercenery tickets
#define FORSALEWINDOW 31 //For Sale menu
#define FORSALEITEMSWINDOW 30 //For Items menu
#define FORSALESPACECRAFTWINDOW 29 //For Spacecraft menu
#define FORSALEVEHICLESWINDOW 28 //For Vehicles menu

//Account Services
#define ACCOUNTSERVICEWINDOW 27 //Account Services main window
#define BANKINGWINDOW 26 //banking menu
#define LOANWINDOW 25 //loan menu
#define PERSONALWINDOW 24 //personal info window

//Library Data
#define LIBDATASEARCHWINDOW 23 //search dialog in library data window
#define LIBDATASERVICEWINDOW 22 //main library data service window
#define LIBDATAIMAGEWINDOW 21 //main library data image window


//News Service
#define NEWSSERVICEWINDOW 20        //main news service window
#define ARCHIVENEWSWINDOW 19		//news archive window
#define RUMORSNEWSWINDOW 18			//rumor news window
#define CURRENTNEWS 17				//newstype
#define ARCHIVENEWS 16
#define RUMORNEWS 15

//Navigation Library
#define GALAXYWINDOW 14    //galaxy window
#define SECTORWINDOW 13    //sector window
#define SECTORLIBDATAWINDOW 12 //library data view for sector
#define SECTORFLEETWINDOW 11 //fleet display for sector
#define SUBSECTORWINDOW 10 //subsector window
#define SUBSECTORLIBDATAWINDOW 9 //library data view for subsector system
#define	SUBSECLIBDATAIMAGEWINDOW 8 //display image for library data
#define PLANETWINDOW 7 //view planet map

//Menu Window Sections
#define CLASSIFIEDMENU 6 //Classifieds menu window
#define LIBDATAWINDOW 5 //main library data window
#define NEWSWINDOW 4        //main news service window
#define NAVIGATIONWINDOW 3  //Navigation Library window
#define MAINMENUWINDOW 2    //Main menu window
#define LOGINWINDOW 1	   //Login Screen
#define TASEXITWINDOW 0   //exit program





#define PI 3.14159265358979
#define DEG2RAD 0.0174532918661 // pi/180

	irr::gui::IGUIElement* editboxIDValue;
	//--------------Event Receiver------------------------


// GLOBALS //////////////////////////////////////////////////////////

const char *TASVersion="3.01";  //TAS Access Terminal application version number for compatibility
						  //Dec 2017	

int modewidth = 1920;
int modeheight = 1080;
int modedepth = 24;


int  TASWindow=0;  //what menu window is active
int TASCurrentMenuWindow=0; //what menu section is active ie. navigation library, news, etc.

//*******Video display environment and textures****************

IrrlichtDevice* device; //display device
IVideoDriver* driver;
ISceneManager* smgr;
IGUIEnvironment* guienv;
IGUIStaticText* staticText;
IGUISkin* skin;
vector2d<irr::s32> mouse_position;

IGUIWindow* SSwindow; //screen shot dialog

video::ITexture* backsurf;//primary display surface (what the user sees)
video::ITexture* primsurf;//display buffer to write to and then push to primsurf

video::ITexture*   LoginBackground;
video::ITexture*   SubmitHover;

video::ITexture*   SecLibDataMenu;
video::ITexture*   seclibdatablank;
video::ITexture*   sublibdatablank;
IGUIImage* libdatatextimage;  //background image for textbox
IGUIImage* xboattextimage; //background image for textbox


video::ITexture*   SubsecBackground;
video::ITexture*   BreakingNews;
video::ITexture*   bluestar;
video::ITexture*   yellowstar;
video::ITexture*   orangestar;

video::ITexture*   MainMenuBackground;
video::ITexture*   Advertisement;
video::ITexture*   PrinterOnButton;
video::ITexture*   PrinterOffButton;
video::ITexture*   Icon;  //window icon


//navigation library
scene::ISceneNode* Planet; //for rotating planet map
video::ITexture    *planetskin; //texture for rotating planet
video::ITexture*   secback; //sector background screen
video::ITexture*   fleetback; //sector fleet background screen
video::ITexture*   fltsectorinfo; //fleet button
video::ITexture*   Galaxy;
video::ITexture*   planetpicwater;
video::ITexture*   planetpicdesert;
video::ITexture*   planetpicgarden;
video::ITexture*   planetpicbarren;
video::ITexture*   planetpicfrozen;
video::ITexture*   planetpicasteroid;
video::ITexture*   planetpicgas;
video::ITexture*   planetpichell;
video::ITexture*   planetpicring;
video::ITexture*   planetpicnormal;
video::ITexture*   planetpicblackhole;
video::ITexture*   idbsunlogo;
video::ITexture*   plnormal;
video::ITexture*   plwater;
video::ITexture*   plbarren;
video::ITexture*   pldesert;
video::ITexture*   plgarden;
video::ITexture*   plfrozen;
video::ITexture*   plasteroid;
video::ITexture*   plhellworld;
video::ITexture*   plring;
video::ITexture*   plblackhole;
video::ITexture*   plamber;
video::ITexture*   plred;
video::ITexture*   idbgas;
video::ITexture*   idbnavalbase;
video::ITexture*   idbimpnavy;
video::ITexture*   idbimpscouta;
video::ITexture*   idbimpscoutb;
video::ITexture*   idbcorsair;
video::ITexture*   idbdepot;
video::ITexture*   idbmilbase;
video::ITexture*   idbaslan;
video::ITexture*   idbtlaukhu;
video::ITexture*   idbzhodani;
video::ITexture*   idbembassy;
video::ITexture*   idboutpost;
video::ITexture*   idbplanetary;
video::ITexture*   idbsystem1;
video::ITexture*   idbsystem2;
video::ITexture*   idbsystemgrid;
video::ITexture*   idblibdataavailable;
video::ITexture*   seclibbmp;
video::ITexture*   subseclibbmp;
video::ITexture*   tempplanet;
video::ITexture*   planetmap;
video::ITexture*   hexmarker;

//fleet
video::ITexture*   icloseescort; //30x30 imperial
video::ITexture*   isystemdefenceboat;//30x30 imperial
video::ITexture*   ipatrolcruiser;//30x30 imperial
video::ITexture*   imerccruiser;//30x30 impaerial
video::ITexture*   idreadnought; //30x30 impaerial
video::ITexture*   idestroyer; //30x30 impaerial
video::ITexture*   icorvette; //30x30 impaerial
video::ITexture*   itender; //30x30 impaerial
video::ITexture*   icruiser; //30x30 impaerial
video::ITexture*   icarrier; //30x30 impaerial
video::ITexture*   ifrigate; //30x30 impaerial


video::ITexture*   acloseescort; //30x30 aslan
video::ITexture*   asystemdefenceboat;//30x30 aslan
video::ITexture*   apatrolcruiser;//30x30 aslan
video::ITexture*   amerccruiser;//30x30 aslan
video::ITexture*   adreadnought; //30x30 aslan
video::ITexture*   adestroyer; //30x30 aslan
video::ITexture*   acorvette; //30x30 aslan
video::ITexture*   atender; //30x30 aslan
video::ITexture*   acruiser; //30x30 aslan
video::ITexture*   acarrier; //30x30 aslan
video::ITexture*   afrigate; //30x30 aslan

video::ITexture*   vcloseescort; //30x30 vargr
video::ITexture*   vsystemdefenceboat;//30x30 vargr
video::ITexture*   vpatrolcruiser;//30x30 vargr
video::ITexture*   vmerccruiser;//30x30 vargr
video::ITexture*   vdreadnought; //30x30 vargr
video::ITexture*   vdestroyer; //30x30 vargr
video::ITexture*   vcorvette; //30x30 vargr
video::ITexture*   vtender; //30x30 vargr
video::ITexture*   vcruiser; //30x30 vargr
video::ITexture*   vcarrier; //30x30 vargr
video::ITexture*   vfrigate; //30x30 vargr
video::ITexture*   vargrcorsair; //30x30 vargr

video::ITexture*   zcloseescort; //30x30 zhodani
video::ITexture*   zsystemdefenceboat;//30x30 zhodani
video::ITexture*   zpatrolcruiser;//30x30 zhodani
video::ITexture*   zmerccruiser;//30x30 zhodani
video::ITexture*   zdreadnought; //30x30 zhodani
video::ITexture*   zdestroyer; //30x30 zhodani
video::ITexture*   zcorvette; //30x30 zhodani
video::ITexture*   ztender; //30x30 zhodani
video::ITexture*   zcruiser; //30x30 zhodani
video::ITexture*   zcarrier; //30x30 zhodani
video::ITexture*   zfrigate; //30x30 zhodani

video::ITexture*   scloseescort; //30x30 solomani
video::ITexture*   ssystemdefenceboat;//30x30 solomani
video::ITexture*   spatrolcruiser;//30x30 solomani
video::ITexture*   smerccruiser;//30x30 solomani
video::ITexture*   sdreadnought; //30x30 solomani
video::ITexture*   sdestroyer; //30x30 solomani
video::ITexture*   scorvette; //30x30 solomani
video::ITexture*   stender; //30x30 solomani
video::ITexture*   scruiser; //30x30 solomani
video::ITexture*   scarrier; //30x30 solomani
video::ITexture*   sfrigate; //30x30 solomani

//news service
video::ITexture*   NewsMenuBackground;
video::ITexture*   archivemenubmp;
video::ITexture*   rumormenubmp;

//library data
video::ITexture*   libdatabmp;
video::ITexture*   libdataimagebutton;
video::ITexture*   libdataimage;
video::ITexture*   libdatablank;

//Account services
video::ITexture* accountsvcs;
video::ITexture* acctinfo;
video::ITexture* banking;
video::ITexture* loancredit;
video::ITexture* loanform;

//Classifieds
video::ITexture* classifiedmenu;
video::ITexture* foresalemenu;
video::ITexture* missionsmenu;
video::ITexture* helpwantedmenu;
video::ITexture* FSitems;
video::ITexture* FSspacecraft;
video::ITexture* FSvehicles;
video::ITexture* FSSpacecraftAd;
video::ITexture* FSVehicleAd;
video::ITexture* FSItemAd;

//Communications
video::ITexture* xboatmainmenu;
video::ITexture* xboatsendmessagemenu;
video::ITexture* xboatreadmessagemenu;
video::ITexture* xboatnextbutton;
video::ITexture* xboatbackbutton;
video::ITexture* xboatnextbuttonover;
video::ITexture* xboatbackbuttonover;
video::ITexture* xboatblank; //background for message

//fonts
IGUIFont*   Courier10White;
IGUIFont*   Courier10Black;
IGUIFont*   Courier10Yellow;
IGUIFont*   Courier10Red;
IGUIFont*   Courier10Green;
IGUIFont*   Courier10LtBlue;
IGUIFont*   Courier8White;
IGUIFont*   Courier8Black;
IGUIFont*   Courier8Yellow;
IGUIFont*   Courier8Red;
IGUIFont*   Optima18White;
IGUIFont*   Optima18Black;
IGUIFont*   Optima18Red;
IGUIFont*   Optima18Green;
IGUIFont*   Optima18Yellow;
IGUIFont*   arial_36_mac_green;
IGUIFont*   Arial24NeonYellowShadow;
IGUIFont*   arial_24_red_blackout_bevel;
IGUIFont*   arial_24_yellow_blackout_bevel;

s32 EventId; //event id for keyboard and mouse input

//globals
int  Era = 1;  //set default Traveller era to 1 (classic)
char EraName[81] = "\0"; //name of era
int  TASYear = 0;  //default Current year
core::stringw TAStempyear; //temporary storage for year
int  TASDay = 1;   //default Current day (1-365)
core::stringw TAStempday; //temporary storage for day
int  NEWSDay = 1; //default day for news (TASDay -6)
char currentdate[81] = "\0"; //date in char format
char TASVersionComp[6] = "\0";  //TAS Access Terminal application version number for compatibility
char uName[81] = "\0"; //username
char uPass[81] = "\0"; //user password
char UPP[7] = "\0"; //UPP of the character
char charAccessLevel[3] = "\0"; //access level in char format
int  uAccessLevel = 0; //user access level Default=0
int  MemberNumber=0; //user TAS member number
int  TASmembercount = 0; //total count of members
char uHomeWorld[81] = "\0"; //users homeworld
char uRace[81] = "\0"; //users race
int  LoggedOn = 0;  //is the user logged on? 0=no 1=yes
char program_name[40] = "\0";  //application name
int  UpdateTheScreen = 0;  //flag for updating the primary display surface
char currentWDir[255];; //current working directory


stringw LibDataSearchWordWide; //library data search string
stringw LoginUnametext; //text of login username
stringw LoginPasstext;  //text of login user password
int  TASAd=1;  //main menu random advertisement 1-12
char SectorDirectory[128]="\0";  //set default era directory

//dialog and edit boxes
IGUIEditBox *LoginUname; //Username input box [ID value 100]
IGUIEditBox *LoginPass; //Password input box [ID value 101]
IGUIEditBox *LoanInputBox; //input box for loan amount [ID value 115]
IGUIEditBox *LibDataSearchBox; //library data search input box [ID value 110]

IGUIListBox *UserListbox; //mail recipient listbox of who to send to [ID value 300]

IGUIEditBox *RecipientTextBox; //xboat send recipient input box [ID value 301]
IGUIEditBox *DestinationTextBox; //xboat destination input box [ID value 302]
IGUIEditBox *MessageBodyTextBox;  //xboat message body input box [ID value 303]

IGUIEditBox *ChangeYearTextBox; //account services change year input box [ID value 400]
IGUIEditBox *ChangeDayTextBox;  //account services change day input box [ID value 401]

CGUITextBox * textBox = 0; //textbox for library data

//Flags
int LoginUnameFLAG = 0; //is the username set 0=no 1=yes
int LoginPassFLAG = 0; //is the user password set 0=no 1=yes
int LoginUCreated = 0; //has the username login been created
int LoginPCreated = 0; //has the password login been created
int MarkerFlag = 0; //0=no current location 1=current location marked
int PlanetError = 0; //error flag for planet orbit information
int PrinterOn = 0; //=0printing disabled [default] 1=printing enabled (uses external Microsoft Paint program)
int MSPaintAvail = 1; //0=app available 1=app not available

//Access Level settings for menu access
int  ALNAVLIB = 0; //access level for navigation library
int  ALNAVFLEET = 0;  //access level for navigation library fleet info
int  ALNEWS = 0; //access level for news service
int  ALLIBDATA = 0; //access level for library data service
int  ALACCNT = 0; // access level for account services
int  ALCLASS = 0; // access level for classifieds
int  ALMERC = 0; //access level for mercenery tickets in clasifieds
int  ALXBT = 0; //access level for xboat communication services
int  ALSPECCOLL = 0; //Access level for special collections library

//user accounts (up to 200 members 1-199)
struct {
	int MemberNumber;       //TAS member number
	char uName[81];		    //Character name
	char uPass[81];		    //password
	char UPP[7];		    //character UPP
	char uHomeWorld[81];    //Character's homeworld
	char uRace[81];		    //Character's race
	int uAccessLevel;	    //TAS access level (1-10)
	int MarkerSectorNumber; //sector number for marker
	char MarkerSubSector[3]; //subsector letter
	int MarkerHex;          //hex number for marker
	int MarkerX;            //X coordinate for marker
	int MarkerY;            //Y coordinate for marker
	int TASMemberHidden;    //Member hidden record flag 1=yes 0=no
} TASMember[200];



//NavLib
int  water = 0, desert = 0, garden = 0, barren = 0, asteroid = 0, gas = 0, normal = 0, hell = 0,ringwrld=0, iceworld=0;
int  tr_cnt=0,w_cnt=0,arg_cnt=0,bdr_cnt=0,private_bdr_cnt=0,s_cnt=0;
int  subsectorhex=0,oldsubsectorhex=0,sectorfile=-1;
int  hexmarkerx = 0, hexmarkery = 0, MarkerSectorNumber=0, MarkerHex=0; //location for current location marker
char MarkerSubSector[3];
int  itemnumb = 0; //selected system in subsector
char *subsecfile=NULL; //subsector filename for appending
char sectorfilename[255]="\0"; //sector filename
char *sublocletter=NULL; //subsector letter location representation A-P
int  currentworld = 0; //hex number for system selected
int  secloct = 0; //sector file-location number
char tempsubfname[255]="\0"; //subsector filename
char tempsavefilename[255] = "\0"; //temp single file name without path
char tempsecfname[255]="\0"; //sector filename
char fleetfilename[255] = "\0"; //temporary filename for fleet
char title[80] = "\0";;  //subsector name
char sectitle[80] = "\0"; //sector name
char subsectitle[80] = "\0"; //subsector name
int  isthereplanet = 0; //swith 0=no custom planet map 1=custom planet map
int  hydro = 0; //planet water level * 10 is percentage
int  Plnt_ASTEROID = 1;
int  Plnt_GARDEN = 2;
int  Plnt_WATER = 3;
int  Plnt_BARREN = 4;
int  Plnt_NORMAL=5; //assign integer values for planet types
int  Plnt_DESERT = 6;
int  Plnt_HELLWORLD = 7;
int  Plnt_RINGWORLD = 8;
int  Plnt_ICEWORLD = 9;
char startemperature[3] = "\0";
char starsize[4] = "\0";
int orbits = 0; //if -1 then no star data
int fleetcount = 0; //counter for number of fleets per sector
int istherefleet = 0; //is there a fleet in the sector
int fleetmax = 40; //maximum fleet number per sector
int  fleetbuttonx = 0, fleetbuttony = 0; //floating button for if fleet available
struct {
	char sectorname[50];	//short sector name
	char fullsectorname[65]; //complete sector name
	int sectornumber;		//the sector number
	char sectorfilepath[255];	//filepath to sector data
} sectorlocationname[198];

struct {
	int fleeticon;
	int typetotal;
	char fleetdesc[26];
	char fleetsubsector[2];
}sectorfleet[40];  //up to forty fleet type groups per sector




//Library Data
core::stringw w_libdatatext;  //wide libdata text
core::stringw w_libdatasearchword;//wide search word
char *libdatatext2 = NULL;  //storage for library data text
char *libcurrentsearch = NULL; //library data current search word
char *libdatasearchword = NULL; //library data search word
int  libdatacounter2 = 0; //for scrolling library data
int  istherelibdata = 0; //is there any library data
int  isthereseclibdata = 0; //is there any sector library data
int  librarydataavailable = 0; //is there library data
int  libimagecheck = 0; //is there a library data image
int  CurrentSystemLibData = 0; // hex number for library data
int  searchmenuitemavailable = 0; //library search menu item selection available
int  searchentered = 0; //library search word entered
char *libdatatext = NULL; //storage for library data text
int  libimagecount; //check to see if there is an image for the library data subject
char libimagefilename[255]; //library data associated bmp image filename
int  libdatabuttonx = 0, libdatabuttony = 0; //floating button for library data available
int  libdatacounter = 0; //for scrolling data
char libdatafilename[255] = "\0"; //library data filename



//News Services
bool newstoday = FALSE; //is their breaking news today or not
int  intarchiveyear = 0; //current archived news year
int  istherenews = 0; //is there any news or not
int  newsdatabuttonx = 0, newsdatabuttony = 0; //floating button for news data available
int  newsdatacounter = 0; //for scrolling data
char *newsdatatext = NULL; //storage for news data text
char newsfilename[255] = "\0"; //sector filename

//Account Services
float interestgenerated1=0,interestgenerated2=0, interestgenerated3=0, interestgenerated4=0; //interest rates
float b1interestoffset0=0, b1interestoffset10=0, b1interestoffset20=0, b1interestoffset30=0; //bank 1 interest offsets by percentage of account balance
float b1interestoffset50=0, b1interestoffset70=0, b1interestoffset80=0; // bank 1 interest offsets by percentage of account balance
float b2interestoffset0=0, b2interestoffset10=0, b2interestoffset20=0, b2interestoffset30=0; //bank 2 interest offsets by percentage of account balance
float b2interestoffset50=0, b2interestoffset70=0, b2interestoffset80=0; // bank 2 interest offsets by percentage of account balance
float b3interestoffset0=0, b3interestoffset10=0, b3interestoffset20=0, b3interestoffset30=0; //bank 3 interest offsets by percentage of account balance
float b3interestoffset50=0, b3interestoffset70=0, b3interestoffset80=0; // bank 3 interest offsets by percentage of account balance
float b4interestoffset0=0, b4interestoffset10=0, b4interestoffset20=0, b4interestoffset30=0; //bank 4 interest offsets by percentage of account balance
float b4interestoffset50=0, b4interestoffset70=0, b4interestoffset80=0; // bank 4 interest offsets by percentage of account balance
char *loanrequest=NULL; //amount of loan request
char *tempstor =NULL; //temporary value store for loan interest
char *totalloan = NULL;//storage for loan amount
int totalloannumber = 0;  //total loan amount
int loanborrow=0; //flag - 0 no borrow, 1 borrow amount submitted
int loanselection=0; //0=no loan, 1-4 bank number
int loansubmit=0; //0= not submitted, 1= loan submitted
int loanboxcreated = 0; //flag for if the loan inputbox has been created or not
int ratelevel=0; //level of borrower
long long accountbalance=0; //bank account balance
char characcountbalance[81]="\0"; //character representation of same balance
int displaybalance=0; //display account balance on 1, add to balance on 2, withdraw on 3
long long addtoaccount=0; //temporary number to add to account balance
long long withdrawaccount=0; //amount to withdraw from account balance
int keypresscount=0; //max out on digit 20
char tempaccount[30]="\0"; //temporary storage for account add/subtract number;
stringw LoanAmounttext;  //text of loan amount


//Classifieds
int MissionSeed = 0;  //random seed for mercenery tickets
int NumberofMercTickets = 0; //number of mercenery tickets available
int MercTicketsRemaining = 0; //temp cycle of tickets
int Salary = 0; //Salary for job ads
int JobSeed = 0; //random seed for job ads
char JobName[81]; //name of job
char CompanyName[81]; //name of company
//************end Classifieds

//XBoat Communications Services
int ismessagewaiting = 0;  //flag for if the user has a new xboat message
int newmailcount = 0; //number of awaiting messages
int oldmailcount = 0; //number of read messages
int totalmailcount = 0; //total number of both message types
int mymessagenumber = 0; // current message number index
int oldmessagecounter;  //temp counter to adjust archived messages

//mailbox
struct{

	char xbmessageto[40]; //name or member number for send-to
	char xbdestination[20]; //name of where the message is going
	char sentdate[80]; //date for sent message
	char sendername[80]; //name of message sender
	int sendermembernumber; //TAS member number of sender
	int markedread; //flag for if message was read
	char xbmessage[5000];//create xboat message with 5000 characters of text + end of message line
} mymessages[2000];


//int PlayerFlag = 0; //0=nonplayer 1=real player
char xbmessageto[40]; //name or member number for send-to
char xbdestination[20]; //name of where the message is going
char sentdate[80]; //date for sent message
char sendername[80]; //name of message sender
int sendermembernumber=0; //TAS member number of sender
char xbmessage[5000];

int newmessage = 0; //0= no message being created 1=message waiting to be sent
char awaitingmessage[30]; //temp string



//************end Xboat Communications

FILE *fd=NULL;
FILE *ERR=NULL;  //error.txt file


//**********************************************************************************
//Planet generation variables:

int BLACK = 0;
int WHITE = 1;
int BACK = 2;
int GRID = 3;
int OUTLINE1 = 4;
int OUTLINE2 = 5;
int LOWEST = 6;
int SEA = 7;
int LAND = 8;
int HIGHEST = 9;

int nocols = 65536;
int rtable[65536], gtable[65536], btable[65536];


// these three values can be changed to change planet map characteristics
	double M = -.02;   /* initial altitude (slightly below sea level) */
	double dd1 = 0.45;  /* weight for altitude difference */
	double dd2 = 0.035; /* weight for distance */
	double POW = 0.47;  /* power for distance function */
	int Depth = 0; /* depth of subdivisions */
	double r1 = 0, r2 = 0, r3 = 0, r4 = 0; /* seeds */
	double longi = 0, lat = 0, scale = 0;
	double vgrid = 0, hgrid = 0;
	int icecap = 0; /* flag for latitude based colour */
	int Width = 800, Height = 600; /* default planet map size */
	unsigned short **col = NULL;  /* colour array */
	double **xxx = NULL, **yyy = NULL, **zzz = NULL; /* x,y,z arrays  (used fo gridlines */
	int do_outline = 0;  /* if 1, draw coastal outline */
	int do_bw = 0;       /* if 1, reduce map to black outline on white */
	int contourstep = 0; /* if >0, # of colour steps between contour lines */
	int *outx = NULL, *outy = NULL;
	int doshade = 0;
	int shade = 0;
	unsigned short **shades = NULL; /* shade array */
	double shade_angle = 150.0; /* angle of "light" on bumpmap */
	double shade_angle2 = 20.0; /* with daylight shading, these two are
							longitude/latitude */
	double cla = 0, sla = 0, clo = 0, slo = 0;
	double rseed = 0, increment = 0.0000001;
	int best = 500000;
	int weight[30];
	FILE *colfile = NULL;
	FILE *outfile = NULL;
	double ssa = 0, ssb = 0, ssc = 0, ssd = 0, ssas = 0, ssbs = 0, sscs = 0, ssds = 0,
	ssax = 0, ssay = 0, ssaz = 0, ssbx = 0, ssby = 0, ssbz = 0, sscx = 0, sscy = 0, sscz = 0, ssdx = 0, ssdy = 0, ssdz = 0;


//*********************************************************************************
//end planet generation variables



typedef struct {
		int x;
		int y;
	}loc;

typedef struct {
		int x;
		int y;
	}XPoint;


typedef struct {
	loc location;
	int WorldType;
	int GasGiant;
	char Starport[2];
	char Base[2];
	char Zone[2];
	int  NumPlanets;
	int  Belts;
	char stars[28];
	char hex[5];
	char name[21];
	char size[2];
	char uwp[9];
	char remark1[3];
	char remark2[3];
	char remark3[3];
	char remark4[3];
	char remark5[3];
	char allegiance[3];
	char allegiancefull[80];
	int  xmousepoint;
	int  ymousepoint;
	int  habitable;
	}World;        //array to store subsector system data

typedef struct {
	loc location;
	char Zone[2];
	char hex[5];
	int hexint;
	char allegiance[3];
	int  xmousepoint;
	int  ymousepoint;
	}SectorData;   //array to store sector system information

struct{
		int x1;
		int x2;
		int y1;
		int y2;
		}t_route[160], bdr_seg[160], file_bdr_seg[160]; //mapping data


World sec_world[80]; //create sec_world storage array of structure type World

SectorData sec_data[960]; //create sector data array with max 960 hexes

typedef struct
{
	char allegianceshort[3];
	char allegiancefull[80];
	int count;
}allegiance_codes;   

allegiance_codes allegiance[500]; //array to store allegiance information

int TotalAllegianceCount = 0; //initialize number count for above structure

//Static assigns ////////////////////////////////////

static XPoint hex_ctr[NUM_HEXES + 8] = {
	{ -145, 30 },
	{ -100, 55 },
	{ -55, 30 },
	{ -10, 55 },
	{ 35, 30 },
	{ 80, 55 },
	{ 125, 30 },
	{ 170, 55 },
	{ 215, 30 },
	{ 260, 55 },
	{ 305, 30 },
	{ 350, 55 },
	{ 395, 30 },
	{ 440, 55 },



	{ 485, 30 },
	{ 530, 55 } };

/****************************************************************************
 *  The next values are the 6 points of each hex, arranged in CoordModePrev.*
 *  format.  The 1st value is filled in during each pass thru a double      *
 *  'for' loop.  The points are ordered as follows:      6_1                *
 *                                                     5/   \2              *
 *                                                      \4_3/               *
 ****************************************************************************/

static XPoint hex_pts[NUM_HEX_PTS] = {
		{ 15,-25},
		{ 30,0},
		{ 15,25},
		{-15,25},
		{-30,0},
		{-15,-25},
		{ 15,-25} };

/****************************************************************************
 *  The next values are the 6 points of each hex, arranged in CoordModeAbs. *
 *  format (sort of).  Each point is an absolute value, relative to the     *
 *  0th [x,y] point in the array.  This is used for rendering static borders*
 *  loaded from the data file, rather than entered interactively.  The      *
 *  point ordering is the same as that in the hex_pts array (above).        *
 ****************************************************************************/

static XPoint abs_hex_pts[NUM_HEX_PTS] = {
		{  0,   0},
		{ 30,   0},
		{ 45,  25},
		{ 30,  50},
		{  0,  50},
		{-15,  25},
		{  0,   0} };

/****************************************************************************
 *  These values are the '0' point for each hex in a row (from left to      *
 *  right).  These values are substituted into the hex_pt array (above)     *
 *  as each hex is rendered.                                                *
 ****************************************************************************/

static XPoint hex_loc[NUM_HEXES] = {
		{ 20,  5},
		{ 65, 30},
		{110,  5},
		{155, 30},
		{200,  5},
		{245, 30},
		{290,  5},
		{335, 30} };

/***************************************************************************
 *  The subsectorfilegrid contains the filenames used for the various      *
 *  subsector letters.                                                     *
 ***************************************************************************/

char *subsectorfilegrid[4][4]={
	"sec_a.sec","sec_b.sec","sec_c.sec","sec_d.sec",
	"sec_e.sec","sec_f.sec","sec_g.sec","sec_h.sec",
	"sec_i.sec","sec_j.sec","sec_k.sec","sec_l.sec",
	"sec_m.sec","sec_n.sec","sec_o.sec","sec_p.sec"};



char *subloclettergrid[4][4]={
	    "A","B","C","D",
	    "E","F","G","H",
	    "I","J","K","L",
	    "M","N","O","P"}; 


	typedef struct 
	{
		char second[5][128];
	}locnamegrid;   //array to store sector system information;
		
	locnamegrid sublocnamegrid[5];


//IRRLICHT EVENT RECEIVER
//For mouse and keyboard input

class MyEventReceiver : public IEventReceiver
{
public:
	// We'll create a struct to record info on the mouse state
	struct SMouseState
	{
		core::position2di Position;
		bool LeftButtonDown;
		SMouseState() : LeftButtonDown(false) { }
	} MouseState;

	
	virtual bool OnEvent(const SEvent& event)
	{
		if (event.GUIEvent.EventType == irr::gui::EGET_EDITBOX_ENTER){

			//Loan input box
			if (TASWindow == LOANWINDOW)
			{
				editboxIDValue = device->getGUIEnvironment()->getRootGUIElement()->getElementFromId(115, false);
				return true;
			}//end input loan amount

			//Library Data Search editbox
			if (TASCurrentMenuWindow == LIBDATAWINDOW)
			{
				editboxIDValue = device->getGUIEnvironment()->getRootGUIElement()->getElementFromId(110, false);
				return true;
			}//end enter search word

			//login username editbox
			if ((LoginUnameFLAG == 0) && (TASWindow == LOGINWINDOW))
			{
				editboxIDValue = device->getGUIEnvironment()->getRootGUIElement()->getElementFromId(100, false);
				return true;
			}//end login username flag

			//login password editbox
			if ((LoginPassFLAG == 0) && (TASWindow == LOGINWINDOW))
			{
				editboxIDValue = device->getGUIEnvironment()->getRootGUIElement()->getElementFromId(101, false);
				return true;
			}//end login username flag

			//xboat input send recipient name
			if (TASWindow == XBOATSENDMENU)
			{
				
				//editboxIDValue = device->getGUIEnvironment()->getRootGUIElement()->getElementFromId(301, false);
				return true;
			}//end input send recipient name

		} //end if EGET_EDITBOX_ENTER

		if (event.GUIEvent.EventType == irr::gui::EGET_LISTBOX_CHANGED)
		{
			MouseState.LeftButtonDown = true;
			return true;
		}
			
		if (event.GUIEvent.EventType == irr::gui::EMBF_OK)
		{
			if ((currentworld > 0) && (TASWindow == SUBSECTORWINDOW))
			{
				subsectorhex = currentworld;
				
			}
		}
		// Remember the mouse state
		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		{
			switch (event.MouseInput.Event)
			{
			case EMIE_LMOUSE_PRESSED_DOWN:
				MouseState.LeftButtonDown = true;
				break;

			case EMIE_LMOUSE_LEFT_UP:
				MouseState.LeftButtonDown = false;
				break;

			case EMIE_MOUSE_MOVED:
				MouseState.Position.X = event.MouseInput.X;
				MouseState.Position.Y = event.MouseInput.Y;
				break;

			default:
				// We won't use the wheel
				break;
			}
		} //end if event type


		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		{
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		}

		return false;
	}
	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}


	const SMouseState & GetMouseState(void) const
	{
		return MouseState;
	}


	MyEventReceiver()
	{
		for (u32 i = 0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}

private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

MyEventReceiver receiver;
/*
//Sound files .WAV
Mix_Chunk *SoundButtonClick = NULL;
Mix_Chunk *SoundWelcome = NULL;
Mix_Chunk *SoundDenied = NULL;
*/

