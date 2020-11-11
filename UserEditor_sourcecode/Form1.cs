using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Xml;

namespace UserEditor
{
    public partial class Form1 : Form
    {
        //user accounts (up to 200 members 1-199)
        struct TASMemberStruct
        {
            public int MemberNumber;       //TAS member number
            public string uName;		    //Character name
            public string uPass;		    //password
            public string UPP;		    //character UPP
            public string uHomeWorld;    //Character's homeworld
            public string uRace;		    //Character's race
            public string uAccessLevel;	    //TAS access level (1-10)
            public string MarkerSectorNumber; //sector number for marker
            public string MarkerHex;          //hex number for marker
            public string MarkerX;            //X coordinate for marker
            public string MarkerY;            //Y coordinate for marker
            public string TASMemberHidden;    //Member hidden record flag 1=yes 0=no
        }
        TASMemberStruct[] TASMember = new TASMemberStruct[200];
        public string Era;
        public string TASYear;
        public string TASDay;
        public string TASVersion;
        public string ALNAVLIB, ALNAVFLEET, ALNEWS, ALLIBDATA, ALACCNT, ALCLASS, ALMERC, ALXBT, ALSPECCOLL;
        public string CurrentMemberName; //current selected member name
        public int CurrentMemberIndex; //current selected member array index number
        public int ComboBoxIndexNumber; //index of selected race list
        public int ListBoxIndexNumber; //index of selected name
        public int MemberCount; //total number of members
        private bool isFirstChange = true; //to change input to uppercase
        private bool nonNumberEntered = false; //validate for 0-9 characters


        public Form1()
        {
            
            InitializeComponent();
            
            ClearUserArray(); //set user account info to empty
            ReadINIFile(); //load tas.xml
            ReadAccountFile(); //load account.xml
            AddUsersToList(); //add users to listbox for selection
        }

        private void ClearUserArray()
        {
            int x1;
            for(x1=0;x1<=199;x1++)
            {
                TASMember[x1].MemberNumber = -2;//TAS member number
                TASMember[x1].uName = "";//Character name		    
	            TASMember[x1].uPass = "";		    //password
	            TASMember[x1].UPP = "";		    //character UPP
	            TASMember[x1].uHomeWorld = "";    //Character's homeworld
	            TASMember[x1].uRace = "";		    //Character's race
	            TASMember[x1].uAccessLevel= "-2";	    //TAS access level (1-10)
	            TASMember[x1].MarkerSectorNumber= "-2"; //sector number for marker
	            TASMember[x1].MarkerHex= "-2";          //hex number for marker
	            TASMember[x1].MarkerX= "-2";            //X coordinate for marker
	            TASMember[x1].MarkerY= "-2";            //Y coordinate for marker
	            TASMember[x1].TASMemberHidden= "-2";    //Member hidden record flag 1=yes 0=no
            }
        }

        private void ReadINIFile()
        {
            int term = 0;

         
            //LOAD XML Document

            if (File.Exists("tas.xml"))
            {


                XmlTextReader xConfigFile = new XmlTextReader("tas.xml"); ;


                while (xConfigFile.Read() && (term == 0))
                {

                    if (xConfigFile.NodeType == XmlNodeType.Element)
                    {
                        if (xConfigFile.Name == "attributes")
                        {
                            TASVersion = xConfigFile.GetAttribute("version");
                            Era = xConfigFile.GetAttribute("era");
                            TASYear = xConfigFile.GetAttribute("year");
                            TASDay = xConfigFile.GetAttribute("day");
                            ALNAVLIB = xConfigFile.GetAttribute("ALNAVLIB");
                            ALNAVFLEET = xConfigFile.GetAttribute("ALNAVFLEET");
                            ALNEWS = xConfigFile.GetAttribute("ALNEWS");
                            ALLIBDATA = xConfigFile.GetAttribute("ALLIBDATA");
                            ALACCNT = xConfigFile.GetAttribute("ALACCNT");
                            ALCLASS = xConfigFile.GetAttribute("ALCLASS");
                            ALMERC = xConfigFile.GetAttribute("ALMERC");
                            ALXBT = xConfigFile.GetAttribute("ALXBT");
                            ALSPECCOLL = xConfigFile.GetAttribute("ALSPECCOLL");

                            // System.IO.File.AppendAllText(@"WriteText.txt", ALNAVLIB);
                            term = 1;
                            //System.Media.SystemSounds.Beep.Play();

                        } //end if attributes
                    } //end if xmlnodetype
                } //end while
                xConfigFile.Close();

                //Populate form with loaded values
                textBox1ALACCNT.Text = ALACCNT;
                textBox1ALCLASS.Text = ALCLASS;
                textBox1ALMERC.Text = ALMERC;
                textBox1ALLIBDATA.Text = ALLIBDATA;
                textBox1ALNAVLIB.Text = ALNAVLIB;
                textBox1ALNEWS.Text = ALNEWS;
                textBox1ALXBT.Text = ALXBT;
                textBox1ALSPECCOLL.Text = ALSPECCOLL;
                textBox1ALNAVFLEET.Text = ALNAVFLEET;
                
              

            }//end if file exists check
            else
            {
                DialogResult myexitflag = MessageBox.Show(null, "Could not read or find tas.xml file.\nMake sure it is in the TASAT root directory.", "File Does Not Exist", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                if (myexitflag == DialogResult.OK)
                {
                    //this.Close();
                    //this.Dispose();
                    Environment.Exit(0);
                    //Application.Exit();

                }

            } //file does not exist


    }//end readinifile


    //read account.xml file
    private void ReadAccountFile()
    {
        int MemberNumber =-2;
        string MemberNum;

        MemberCount = 0;

                      //LOAD XML Document

             if (File.Exists("accounts/users/account.xml"))
             {

                 
                 XmlTextReader xConfigFile = new XmlTextReader("accounts/users/account.xml"); ;


                 while (xConfigFile.Read() && xConfigFile.NodeType != XmlNodeType.EndElement && MemberCount<200)
                {


                   if (xConfigFile.NodeType == XmlNodeType.Element)
                   {
                       if (xConfigFile.Name == "membership")
                       {
                            
                             MemberNum = xConfigFile.GetAttribute("MEMNUM");
                             MemberNumber=  Int32.Parse(MemberNum);
                             TASMember[MemberCount].MemberNumber = MemberNumber;                        
                             TASMember[MemberCount].uName = xConfigFile.GetAttribute("NAME");
                             TASMember[MemberCount].uPass = xConfigFile.GetAttribute("PASSWORD");
                             TASMember[MemberCount].UPP = xConfigFile.GetAttribute("UPP");
                             TASMember[MemberCount].uHomeWorld = xConfigFile.GetAttribute("HOMEWORLD");
                             TASMember[MemberCount].uRace = xConfigFile.GetAttribute("RACE");
                             TASMember[MemberCount].MarkerSectorNumber = xConfigFile.GetAttribute("CURRSEC");
                             TASMember[MemberCount].MarkerHex = xConfigFile.GetAttribute("CURRHEX");
                             TASMember[MemberCount].uAccessLevel = xConfigFile.GetAttribute("AL");
                             TASMember[MemberCount].MarkerX = xConfigFile.GetAttribute("MARKERX");
                             TASMember[MemberCount].MarkerY = xConfigFile.GetAttribute("MARKERY");
                             TASMember[MemberCount].TASMemberHidden = xConfigFile.GetAttribute("HIDDENTASMEMBER");

                            // File.AppendAllText("error.txt", "Member #" + MemberNumber + " MemberCount:" + MemberCount + "Name: " + TASMember[MemberCount].uName + Environment.NewLine);                         
                             MemberCount++;

                       } //end if xConfigFile.Name == "membership"
                    } //end if xConfigFile.NodeType == XmlNodeType.Element
                 } //end of while 
         
                 xConfigFile.Close();
                 textBoxMemTotal.Text = MemberCount.ToString();

          

            }//end file exists check  
         
            else 
            {
                DialogResult myexitflag = MessageBox.Show(null,"Could not read or find accounts/users/account.xml file.\nMake sure it is in the accounts/users/ directory.", "File Does Not Exist", MessageBoxButtons.OK , MessageBoxIcon.Exclamation);
                if (myexitflag == DialogResult.OK)
                {
                    //this.Close();
                    //this.Dispose();
                    Environment.Exit(0);
                    //Application.Exit();
                    
                }
                
            } //file does not exist           

                     
    }//end readaccountfile


    //Add users to listbox
    private void AddUsersToList()
    {
           int x1;
           for (x1 = 0; x1 <= 199; x1++)
           {
               if(TASMember[x1].MemberNumber >0) //TAS member number
               {
                   listBox1Users.Items.Add(TASMember[x1].uName);
               }//end add to list if a member entry
           } //end for loop
           listBox1Users.SetSelected(0, true); //preselect the first name
    }//end adduserstolist function



    //Find next available user account member number
    private int NextAvailableUserNumber()
    {
        int available = -2;
        int memberindex = 0;
        int inuseflag = 0;


        for (available = 1; available <= 199; available++)
        {
            inuseflag = 0;

            for (memberindex = 0; memberindex <= 199; memberindex++)
            {
                if (TASMember[memberindex].MemberNumber == available)
                {
                    inuseflag = 1;
                }
            }
            if (inuseflag == 0)
            {               
                return available; //found an available member number
            }
        }
        return -2;
    }

    //Find next available user index
    private int NextAvailableUserIndexNumber()
    {

        int memberindex = 0;

            for (memberindex = 0; memberindex <= 199; memberindex++)
            {
                if (TASMember[memberindex].MemberNumber == -2)
                {
                    return memberindex;
                }

            }

        return -2;
    }

    //write account.xml file
    private void WriteAccountFile()
    {
        
	        int x;

            //clear out existing file
            System.IO.File.WriteAllText(@"accounts/users/account.xml","");
         

            //append to new file
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "<?xml version=\"1.0\"?>" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "<!-- Travellers' Aid Society Access Terminal" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "ACCOUNT.XML initialization file" + Environment.NewLine + Environment.NewLine + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "NOTE : Each record / account entry must follow the below order and format :" + Environment.NewLine);

            System.IO.File.AppendAllText(@"accounts/users/account.xml", "MEMNUM = TAS Membership number 1 - 199" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "NAME = user name[up to 15 characters]" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "PASSWORD = password[up to 15 characters]" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "UPP = UPP of the character[ex:777777]" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "HOMEWORLD = Homeworld" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "RACE = Race" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "CURRSEC = Current sector number" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "CURRHEX = Current hex location" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "AL = access level[number]" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "MARKERX = X coordinates for hex marker" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "MARKERY = Y coordinates for hex marker" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "HIDDENTASMEMBER = flag to hide account 0 = not hidden 1 = hidden" + Environment.NewLine);

            System.IO.File.AppendAllText(@"accounts/users/account.xml", "-->" + Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", ""+ Environment.NewLine);

            System.IO.File.AppendAllText(@"accounts/users/account.xml", "<users>" + Environment.NewLine);

	        for (x = 0; x < 200; x++)
	        {
		        if (TASMember[x].MemberNumber > 0)
		        {
                    System.IO.File.AppendAllText(@"accounts/users/account.xml", "<membership MEMNUM =\"" + TASMember[x].MemberNumber + "\" NAME =\"" + TASMember[x].uName +
                    "\" PASSWORD = \"" + TASMember[x].uPass + "\" UPP = \"" + TASMember[x].UPP + "\" HOMEWORLD = \"" + TASMember[x].uHomeWorld + "\" RACE = \"" + TASMember[x].uRace +
                    "\" CURRSEC = \"" + TASMember[x].MarkerSectorNumber + "\"  CURRHEX = \"" + TASMember[x].MarkerHex + "\" AL=\"" + TASMember[x].uAccessLevel +
                    "\" MARKERX = \"" + TASMember[x].MarkerX + "\" MARKERY = \"" + TASMember[x].MarkerY + "\" HIDDENTASMEMBER =\"" + TASMember[x].TASMemberHidden + "\" />");

                    System.IO.File.AppendAllText(@"accounts/users/account.xml", ""+Environment.NewLine); 
		        }
	        }
            System.IO.File.AppendAllText(@"accounts/users/account.xml", "</users>"+Environment.NewLine);
            System.IO.File.AppendAllText(@"accounts/users/account.xml", Environment.NewLine + "</xml>" + Environment.NewLine);
               
        
    }//end writeaccountfile

    private void listBox1Users_DrawItem(object sender, DrawItemEventArgs e)
    {
        e.DrawBackground();

        bool isItemSelected = ((e.State & DrawItemState.Selected) == DrawItemState.Selected);
        int itemIndex = e.Index;
        if (itemIndex >= 0 && itemIndex < listBox1Users.Items.Count)
        {
            Graphics g = e.Graphics;

            // Background Color
            SolidBrush backgroundColorBrush = new SolidBrush((isItemSelected) ? Color.Red : Color.White);
            g.FillRectangle(backgroundColorBrush, e.Bounds);

            // Set text color
            string itemText = listBox1Users.Items[itemIndex].ToString();

            SolidBrush itemTextColorBrush = (isItemSelected) ? new SolidBrush(Color.White) : new SolidBrush(Color.Black);
            g.DrawString(itemText, e.Font, itemTextColorBrush, listBox1Users.GetItemRectangle(itemIndex).Location);

            // Clean up
            backgroundColorBrush.Dispose();
            itemTextColorBrush.Dispose();
        }

        e.DrawFocusRectangle();
    }



    private void listBox1Users_SelectedIndexChanged(object sender, EventArgs e)
    {
        int x1;
        CurrentMemberName = listBox1Users.GetItemText(listBox1Users.SelectedItem);

        if (CurrentMemberName != null)
        {
            for (x1 = 0; x1 <= 199; x1++) //find current member index
            {
                if (TASMember[x1].uName == CurrentMemberName) //found member
                {
                    CurrentMemberIndex = x1;
                    ListBoxIndexNumber = listBox1Users.SelectedIndex;
                }
            }

            textBox1MemNum.Text = TASMember[CurrentMemberIndex].MemberNumber.ToString();
            textBox1Name.Text = TASMember[CurrentMemberIndex].uName;
            textBox1Password.Text = TASMember[CurrentMemberIndex].uPass;
            textBox1UPP.Text = TASMember[CurrentMemberIndex].UPP;
            textBox1HomeWorld.Text = TASMember[CurrentMemberIndex].uHomeWorld;

            comboBox1.SelectedIndex = comboBox1.FindStringExact(TASMember[CurrentMemberIndex].uRace);

            textBox1AccessLevel.Text = TASMember[CurrentMemberIndex].uAccessLevel;

            if(TASMember[CurrentMemberIndex].TASMemberHidden =="1")  //hidden
            {
                checkBox1HiddenTAS.Checked = true;
            }
            if (TASMember[CurrentMemberIndex].TASMemberHidden == "0") //not hidden
            {
                checkBox1HiddenTAS.Checked = false;
            }
            
        }//end if not null selected
    }

    private void textBox1Name_Leave(object sender, EventArgs e)
    {
        int index = listBox1Users.SelectedIndex;

        listBox1Users.Items[index] = TASMember[CurrentMemberIndex].uName;
    }

    private void textBox1Name_TextChanged(object sender, EventArgs e)
    {
        int index = listBox1Users.SelectedIndex;

    
        if (index > -1 && textBox1Name.Text !="")
       {
           if (isFirstChange)
           {
               isFirstChange = false;
               textBox1Name.Text = textBox1Name.Text.ToUpper();
               textBox1Name.SelectionStart = textBox1Name.Text.Length;
               isFirstChange = true;
           }

            TASMember[CurrentMemberIndex].uName = textBox1Name.Text;

            //listBox1Users.Items[index] = TASMember[CurrentMemberIndex].uName;

            //listBox1Users.Refresh();
        }//end if listbox item selected
    } //end textbox1name changed

    private void textBox1Password_TextChanged(object sender, EventArgs e)
    {

           if (isFirstChange)
           {
               isFirstChange = false;
               textBox1Password.Text = textBox1Password.Text.ToUpper();
               textBox1Password.SelectionStart = textBox1Password.Text.Length;
               isFirstChange = true;
           }

           TASMember[CurrentMemberIndex].uPass = textBox1Password.Text;
    }

    private void textBox1UPP_TextChanged(object sender, EventArgs e)
    {
        if (isFirstChange)
        {
            isFirstChange = false;
            textBox1UPP.Text = textBox1UPP.Text.ToUpper();
            textBox1UPP.SelectionStart = textBox1UPP.Text.Length;
            isFirstChange = true;
        }

        TASMember[CurrentMemberIndex].UPP = textBox1UPP.Text;
    }

    private void textBox1HomeWorld_TextChanged(object sender, EventArgs e)
    {
        TASMember[CurrentMemberIndex].uHomeWorld = textBox1HomeWorld.Text;
    }

    private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox1.SelectedIndex;
        TASMember[CurrentMemberIndex].uRace = comboBox1.Text;
    }

    private void textBox1AccessLevel_KeyPress(object sender, KeyPressEventArgs e)
    {

    }

    private void textBox1AccessLevel_KeyDown(object sender, KeyEventArgs e)
    {
        //Allow navigation keyboard arrows
        switch (e.KeyCode)
        {
            case Keys.Up:
            case Keys.Down:
            case Keys.Left:
            case Keys.Right:
            case Keys.PageUp:
            case Keys.PageDown:
            case Keys.Delete:
                e.SuppressKeyPress = false;
                return;
            default:
                break;
        }

        //Block non-number characters
        char currentKey = (char)e.KeyCode;
        bool modifier = e.Control || e.Alt || e.Shift;
        bool nonNumber = char.IsLetter(currentKey) ||
                         char.IsSymbol(currentKey) ||
                         char.IsWhiteSpace(currentKey) ||
                         char.IsPunctuation(currentKey);

        if (!modifier && nonNumber)
            e.SuppressKeyPress = true;

        //Handle pasted Text
        if (e.Control && e.KeyCode == Keys.V)
        {
            //Preview paste data (removing non-number characters)
            string pasteText = Clipboard.GetText();
            string strippedText = "";
            for (int i = 0; i < pasteText.Length; i++)
            {
                if (char.IsDigit(pasteText[i]))
                    strippedText += pasteText[i].ToString();
            }

            if (strippedText != pasteText)
            {
                //There were non-numbers in the pasted text
                e.SuppressKeyPress = true;

                //OPTIONAL: Manually insert text stripped of non-numbers
                TextBox me = (TextBox)sender;
                int start = me.SelectionStart;
                string newTxt = me.Text;
                newTxt = newTxt.Remove(me.SelectionStart, me.SelectionLength); //remove highlighted text
                newTxt = newTxt.Insert(me.SelectionStart, strippedText); //paste
                me.Text = newTxt;
                me.SelectionStart = start + strippedText.Length;
            }
            else
                e.SuppressKeyPress = false;
        }

    }

    private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
    {
        if (nonNumberEntered == true)
        {
            e.Handled = true;
        }
    }
    private void textBox1AccessLevel_TextChanged(object sender, EventArgs e)
    {
        if (!string.IsNullOrEmpty(textBox1AccessLevel.Text))
        {
            if (Convert.ToInt32(textBox1AccessLevel.Text) > 10)
            {
                textBox1AccessLevel.Text = "10";
            }
            TASMember[CurrentMemberIndex].uAccessLevel = textBox1AccessLevel.Text;
        }
    }

    private void checkBox1HiddenTAS_CheckedChanged(object sender, EventArgs e)
    {
        if (checkBox1HiddenTAS.Checked == false)    
        {
            TASMember[CurrentMemberIndex].TASMemberHidden = "0";  //not hidden
            //checkBox1HiddenTAS.Checked = true;
        }
        else
        if (checkBox1HiddenTAS.Checked == true) 
        {
        TASMember[CurrentMemberIndex].TASMemberHidden = "1"; //hidden 
            //checkBox1HiddenTAS.Checked = false;
        }
    }

    private void button1AddUser_Click(object sender, EventArgs e)
    {
        int availableusernumber = -2;


        if ((MemberCount+1) < 200)
        {
            availableusernumber=NextAvailableUserNumber();

            if (availableusernumber > 0)
            {
                CurrentMemberIndex = NextAvailableUserIndexNumber();

                TASMember[CurrentMemberIndex].MemberNumber = availableusernumber;
                TASMember[CurrentMemberIndex].uName = "NEW USER" + availableusernumber;
                TASMember[CurrentMemberIndex].uPass = "";
                TASMember[CurrentMemberIndex].UPP = "";
                TASMember[CurrentMemberIndex].uHomeWorld = "";
                TASMember[CurrentMemberIndex].uRace = "";
                TASMember[CurrentMemberIndex].MarkerSectorNumber = "-2";
                TASMember[CurrentMemberIndex].MarkerHex = "0";
                TASMember[CurrentMemberIndex].uAccessLevel = "";
                TASMember[CurrentMemberIndex].MarkerX = "0";
                TASMember[CurrentMemberIndex].MarkerY = "0";
                TASMember[CurrentMemberIndex].TASMemberHidden = "0";

                

                listBox1Users.Items.Add(TASMember[CurrentMemberIndex].uName);
               // listBox1Users.SetSelected(MemberCount, true); //preselect the new user
               // CurrentMemberName = listBox1Users.GetItemText(listBox1Users.SelectedItem);
                //ListBoxIndexNumber = listBox1Users.SelectedIndex;

                MemberCount++; //next member index
                textBoxMemTotal.Text = MemberCount.ToString();

            } //end if availablememnum>-1
            else
            {
                //maxed out on emply memberships
            }
        }//end if membercount<200
    }//end button1AddUser_Click

    private void pictureBox1_Click(object sender, EventArgs e)
    {
        DialogResult myexitflag = MessageBox.Show(null, "TASAT User Editor for the Travellers' Aid Society Access Terminal account.xml configuration file" +
        "\nBy Perry Horner 2016\nThe Traveller game in all forms is owned by Far Future Enterprises" +
        "Copyright 1977-2016 Far Future Enterprises\nTraveller is a registered trademark of Far Future Enterprises",
        "About", MessageBoxButtons.OK, MessageBoxIcon.Information);
    }

    private void button1DELUser_Click(object sender, EventArgs e)
    {
        int x1;
        CurrentMemberIndex = -1;
        CurrentMemberName = listBox1Users.GetItemText(listBox1Users.SelectedItem);

        if ((CurrentMemberName != null)&&(MemberCount-1>0))
        {
            for (x1 = 0; x1 <= 199; x1++) //find current member index
            {
                if (TASMember[x1].uName == CurrentMemberName) //found member
                {
                    CurrentMemberIndex = x1;
                }
            }
            if (CurrentMemberIndex > -1)
            {

                //Delete Mailboxes
                //communications/messages/mailbox/%d.msg
                if (File.Exists(Directory.GetCurrentDirectory()+ "communications/messages/mailbox/" + TASMember[CurrentMemberIndex].MemberNumber + ".msg"))  File.Delete("communications/messages/mailbox/" + TASMember[CurrentMemberIndex].MemberNumber + ".msg");
                //communications/messages/read/%d.msg
               
                    TASMember[CurrentMemberIndex].MemberNumber = -2;//TAS member number
                    TASMember[CurrentMemberIndex].uName = "";//Character name		    
                    TASMember[CurrentMemberIndex].uPass = "";		    //password
                    TASMember[CurrentMemberIndex].UPP = "";		    //character UPP
                    TASMember[CurrentMemberIndex].uHomeWorld = "";    //Character's homeworld
                    TASMember[CurrentMemberIndex].uRace = "";		    //Character's race
                    TASMember[CurrentMemberIndex].uAccessLevel = "-2";	    //TAS access level (1-10)
                    TASMember[CurrentMemberIndex].MarkerSectorNumber = "-2"; //sector number for marker
                    TASMember[CurrentMemberIndex].MarkerHex = "-2";          //hex number for marker
                    TASMember[CurrentMemberIndex].MarkerX = "-2";            //X coordinate for marker
                    TASMember[CurrentMemberIndex].MarkerY = "-2";            //Y coordinate for marker
                    TASMember[CurrentMemberIndex].TASMemberHidden = "-2";    //Member hidden record flag 1=yes 0=no

                    listBox1Users.Items.Remove(listBox1Users.SelectedItem);
                    listBox1Users.Refresh();

                    MemberCount--;

                    textBoxMemTotal.Text = MemberCount.ToString();

                    listBox1Users.Focus();
                    listBox1Users.SelectedIndex = 0;

                    CurrentMemberName = listBox1Users.GetItemText(listBox1Users.SelectedItem);
                    for (x1 = 0; x1 <= 199; x1++) //find current member index
                    {
                        if (TASMember[x1].uName == CurrentMemberName) //found member
                        {
                            CurrentMemberIndex = x1;
                        }
                    }
               // }
            }
        } //end if currentmembername
    }

    private void button1Save_Click(object sender, EventArgs e)
    {
        //save account.xml file
        WriteAccountFile();
        Environment.Exit(0);
    }

    private void button1Cancel_Click(object sender, EventArgs e)
    {
        this.Close();
    }

    private void Form1_Load(object sender, EventArgs e)
    {

    }//end button1DELUser
    
  } //end form1
} //end namespace usereditor
