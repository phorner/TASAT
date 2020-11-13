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

namespace FleetEditor
{
    public partial class Form1 : Form
    {
        //fleets in a sector (max 40 entries)
        struct FleetStruct
        {
            public string shiptype;       //type of ship
            public string shipcount;		    //number of ships of a particular type
            public string ShipDescription;		    //description of ship type
            public string GridLetter; //letter representation for subsector on sector map
        }
        FleetStruct[] Fleet = new FleetStruct[40];
        public bool nonNumberEntered;
        public string FleetFilename; //complete path and filename for fleet.xml
        public int NewFleet; //1=new 0=loaded old

        public Form1()
        {
            NewFleet = 1;
            InitializeComponent();
            
            ClearFleetArray(); //set user account info to empty

        }

        private void ClearFleetArray()
        {
            int x1;
            for(x1=0;x1<=39;x1++)
            {
                Fleet[x1].shiptype = "0";//shiptype
                Fleet[x1].shipcount = "0";//ship count		    
	            Fleet[x1].ShipDescription = "";		    //ship description
                Fleet[x1].GridLetter = ""; //subsector letter
            }
        }


    //read fleet.xml file
    private void ReadFleetFile()
    {
        int FleetCount = 0;

                      //LOAD XML Document

        if (File.Exists(FleetFilename))
             {


                 XmlTextReader xConfigFile = new XmlTextReader(FleetFilename);
                 NewFleet = 0;

                 while (xConfigFile.Read() && xConfigFile.NodeType != XmlNodeType.EndElement && FleetCount<40)
                {


                   if (xConfigFile.NodeType == XmlNodeType.Element)
                   {
                       if (xConfigFile.Name == "fleet")
                       {

                             Fleet[FleetCount].GridLetter = xConfigFile.GetAttribute("grid");
                             Fleet[FleetCount].shiptype = xConfigFile.GetAttribute("shiptype");
                             Fleet[FleetCount].shipcount = xConfigFile.GetAttribute("shipcount");
                             Fleet[FleetCount].ShipDescription = xConfigFile.GetAttribute("shipdesc");


                            // File.AppendAllText("error.txt", "GridLetter:" + Fleet[FleetCount].GridLetter + " shiptype:" + Fleet[FleetCount].shiptype + " shipcount:" + Fleet[FleetCount].shipcount + " shipdesc:" + Fleet[FleetCount].ShipDescription + Environment.NewLine);
                             FleetCount++;

                       } //end if xConfigFile.Name == "membership"
                    } //end if xConfigFile.NodeType == XmlNodeType.Element
                 } //end of while 
         
                 xConfigFile.Close();         

            }//end file exists check  
         
            else 
            {
                DialogResult myexitflag = MessageBox.Show(null,"Could not read or find fleet.xml file.\nMake sure it is in the sector directory.", "File Does Not Exist", MessageBoxButtons.OK , MessageBoxIcon.Exclamation);
                if (myexitflag == DialogResult.OK)
                {
                    //this.Close();
                    //this.Dispose();
                    Environment.Exit(0);
                    //Application.Exit();
                    
                }
                
            } //file does not exist           

                     
    }//end readaccountfile

    //Populate the screen with fleet info

    private void PopulateScreen()
    {
        //0
        comboBox1.Text = Fleet[0].GridLetter;
        textBox1_ShipType.Text = Fleet[0].shiptype;
        textBox1_NumShips.Text = Fleet[0].shipcount;
        textBox1_ShipDesc.Text = Fleet[0].ShipDescription;

        //1
        comboBox2.Text = Fleet[1].GridLetter;
        textBox2_ShipType.Text = Fleet[1].shiptype;
        textBox2_NumShips.Text = Fleet[1].shipcount;
        textBox2_ShipDesc.Text = Fleet[1].ShipDescription;

        //2
        comboBox3.Text = Fleet[2].GridLetter;
        textBox3_ShipType.Text = Fleet[2].shiptype;
        textBox3_NumShips.Text = Fleet[2].shipcount;
        textBox3_ShipDesc.Text = Fleet[2].ShipDescription;

        //3
        comboBox4.Text = Fleet[3].GridLetter;
        textBox4_ShipType.Text = Fleet[3].shiptype;
        textBox4_NumShips.Text = Fleet[3].shipcount;
        textBox4_ShipDesc.Text = Fleet[3].ShipDescription;

        //4
        comboBox5.Text = Fleet[4].GridLetter;
        textBox5_ShipType.Text = Fleet[4].shiptype;
        textBox5_NumShips.Text = Fleet[4].shipcount;
        textBox5_ShipDesc.Text = Fleet[4].ShipDescription;

        //5
        comboBox6.Text = Fleet[5].GridLetter;
        textBox6_ShipType.Text = Fleet[5].shiptype;
        textBox6_NumShips.Text = Fleet[5].shipcount;
        textBox6_ShipDesc.Text = Fleet[5].ShipDescription;

        //6
        comboBox7.Text = Fleet[6].GridLetter;
        textBox7_ShipType.Text = Fleet[6].shiptype;
        textBox7_NumShips.Text = Fleet[6].shipcount;
        textBox7_ShipDesc.Text = Fleet[6].ShipDescription;

        //7
        comboBox8.Text = Fleet[7].GridLetter;
        textBox8_ShipType.Text = Fleet[7].shiptype;
        textBox8_NumShips.Text = Fleet[7].shipcount;
        textBox8_ShipDesc.Text = Fleet[7].ShipDescription;

        //8
        comboBox9.Text = Fleet[8].GridLetter;
        textBox9_ShipType.Text = Fleet[8].shiptype;
        textBox9_NumShips.Text = Fleet[8].shipcount;
        textBox9_ShipDesc.Text = Fleet[8].ShipDescription;

        //9
        comboBox10.Text = Fleet[9].GridLetter;
        textBox10_ShipType.Text = Fleet[9].shiptype;
        textBox10_NumShips.Text = Fleet[9].shipcount;
        textBox10_ShipDesc.Text = Fleet[9].ShipDescription;

        //10
        comboBox11.Text = Fleet[10].GridLetter;
        textBox11_ShipType.Text = Fleet[10].shiptype;
        textBox11_NumShips.Text = Fleet[10].shipcount;
        textBox11_ShipDesc.Text = Fleet[10].ShipDescription;

        //11
        comboBox12.Text = Fleet[11].GridLetter;
        textBox12_ShipType.Text = Fleet[11].shiptype;
        textBox12_NumShips.Text = Fleet[11].shipcount;
        textBox12_ShipDesc.Text = Fleet[11].ShipDescription;

        //12
        comboBox13.Text = Fleet[12].GridLetter;
        textBox13_ShipType.Text = Fleet[12].shiptype;
        textBox13_NumShips.Text = Fleet[12].shipcount;
        textBox13_ShipDesc.Text = Fleet[12].ShipDescription;

        //13
        comboBox14.Text = Fleet[13].GridLetter;
        textBox14_ShipType.Text = Fleet[13].shiptype;
        textBox14_NumShips.Text = Fleet[13].shipcount;
        textBox14_ShipDesc.Text = Fleet[13].ShipDescription;

        //14
        comboBox15.Text = Fleet[14].GridLetter;
        textBox15_ShipType.Text = Fleet[14].shiptype;
        textBox15_NumShips.Text = Fleet[14].shipcount;
        textBox15_ShipDesc.Text = Fleet[14].ShipDescription;

        //15
        comboBox16.Text = Fleet[15].GridLetter;
        textBox16_ShipType.Text = Fleet[15].shiptype;
        textBox16_NumShips.Text = Fleet[15].shipcount;
        textBox16_ShipDesc.Text = Fleet[15].ShipDescription;

        //16
        comboBox17.Text = Fleet[16].GridLetter;
        textBox17_ShipType.Text = Fleet[16].shiptype;
        textBox17_NumShips.Text = Fleet[16].shipcount;
        textBox17_ShipDesc.Text = Fleet[16].ShipDescription;

        //17
        comboBox18.Text = Fleet[17].GridLetter;
        textBox18_ShipType.Text = Fleet[17].shiptype;
        textBox18_NumShips.Text = Fleet[17].shipcount;
        textBox18_ShipDesc.Text = Fleet[17].ShipDescription;

        //18
        comboBox19.Text = Fleet[18].GridLetter;
        textBox19_ShipType.Text = Fleet[18].shiptype;
        textBox19_NumShips.Text = Fleet[18].shipcount;
        textBox19_ShipDesc.Text = Fleet[18].ShipDescription;

        //19
        comboBox20.Text = Fleet[19].GridLetter;
        textBox20_ShipType.Text = Fleet[19].shiptype;
        textBox20_NumShips.Text = Fleet[19].shipcount;
        textBox20_ShipDesc.Text = Fleet[19].ShipDescription;

        //20
        comboBox21.Text = Fleet[20].GridLetter;
        textBox21_ShipType.Text = Fleet[20].shiptype;
        textBox21_NumShips.Text = Fleet[20].shipcount;
        textBox21_ShipDesc.Text = Fleet[20].ShipDescription;

        //21
        comboBox22.Text = Fleet[21].GridLetter;
        textBox22_ShipType.Text = Fleet[21].shiptype;
        textBox22_NumShips.Text = Fleet[21].shipcount;
        textBox22_ShipDesc.Text = Fleet[21].ShipDescription;

        //22
        comboBox23.Text = Fleet[22].GridLetter;
        textBox23_ShipType.Text = Fleet[22].shiptype;
        textBox23_NumShips.Text = Fleet[22].shipcount;
        textBox23_ShipDesc.Text = Fleet[22].ShipDescription;

        //23
        comboBox24.Text = Fleet[23].GridLetter;
        textBox24_ShipType.Text = Fleet[23].shiptype;
        textBox24_NumShips.Text = Fleet[23].shipcount;
        textBox24_ShipDesc.Text = Fleet[23].ShipDescription;

        //24
        comboBox25.Text = Fleet[24].GridLetter;
        textBox25_ShipType.Text = Fleet[24].shiptype;
        textBox25_NumShips.Text = Fleet[24].shipcount;
        textBox25_ShipDesc.Text = Fleet[24].ShipDescription;

        //25
        comboBox26.Text = Fleet[25].GridLetter;
        textBox26_ShipType.Text = Fleet[25].shiptype;
        textBox26_NumShips.Text = Fleet[25].shipcount;
        textBox26_ShipDesc.Text = Fleet[25].ShipDescription;

        //26
        comboBox27.Text = Fleet[26].GridLetter;
        textBox27_ShipType.Text = Fleet[26].shiptype;
        textBox27_NumShips.Text = Fleet[26].shipcount;
        textBox27_ShipDesc.Text = Fleet[26].ShipDescription;

        //27
        comboBox28.Text = Fleet[27].GridLetter;
        textBox28_ShipType.Text = Fleet[27].shiptype;
        textBox28_NumShips.Text = Fleet[27].shipcount;
        textBox28_ShipDesc.Text = Fleet[27].ShipDescription;

        //28
        comboBox29.Text = Fleet[28].GridLetter;
        textBox29_ShipType.Text = Fleet[28].shiptype;
        textBox29_NumShips.Text = Fleet[28].shipcount;
        textBox29_ShipDesc.Text = Fleet[28].ShipDescription;

        //29
        comboBox30.Text = Fleet[29].GridLetter;
        textBox30_ShipType.Text = Fleet[29].shiptype;
        textBox30_NumShips.Text = Fleet[29].shipcount;
        textBox30_ShipDesc.Text = Fleet[29].ShipDescription;

        //30
        comboBox31.Text = Fleet[30].GridLetter;
        textBox31_ShipType.Text = Fleet[30].shiptype;
        textBox31_NumShips.Text = Fleet[30].shipcount;
        textBox31_ShipDesc.Text = Fleet[30].ShipDescription;

        //31
        comboBox32.Text = Fleet[31].GridLetter;
        textBox32_ShipType.Text = Fleet[31].shiptype;
        textBox32_NumShips.Text = Fleet[31].shipcount;
        textBox32_ShipDesc.Text = Fleet[31].ShipDescription;

        //32
        comboBox33.Text = Fleet[32].GridLetter;
        textBox33_ShipType.Text = Fleet[32].shiptype;
        textBox33_NumShips.Text = Fleet[32].shipcount;
        textBox33_ShipDesc.Text = Fleet[32].ShipDescription;

        //33
        comboBox34.Text = Fleet[33].GridLetter;
        textBox34_ShipType.Text = Fleet[33].shiptype;
        textBox34_NumShips.Text = Fleet[33].shipcount;
        textBox34_ShipDesc.Text = Fleet[33].ShipDescription;

        //34
        comboBox35.Text = Fleet[34].GridLetter;
        textBox35_ShipType.Text = Fleet[34].shiptype;
        textBox35_NumShips.Text = Fleet[34].shipcount;
        textBox35_ShipDesc.Text = Fleet[34].ShipDescription;

        //35
        comboBox36.Text = Fleet[35].GridLetter;
        textBox36_ShipType.Text = Fleet[35].shiptype;
        textBox36_NumShips.Text = Fleet[35].shipcount;
        textBox36_ShipDesc.Text = Fleet[35].ShipDescription;

        //36
        comboBox37.Text = Fleet[36].GridLetter;
        textBox37_ShipType.Text = Fleet[36].shiptype;
        textBox37_NumShips.Text = Fleet[36].shipcount;
        textBox37_ShipDesc.Text = Fleet[36].ShipDescription;

        //37
        comboBox38.Text = Fleet[37].GridLetter;
        textBox38_ShipType.Text = Fleet[37].shiptype;
        textBox38_NumShips.Text = Fleet[37].shipcount;
        textBox38_ShipDesc.Text = Fleet[37].ShipDescription;

        //38
        comboBox39.Text = Fleet[38].GridLetter;
        textBox39_ShipType.Text = Fleet[38].shiptype;
        textBox39_NumShips.Text = Fleet[38].shipcount;
        textBox39_ShipDesc.Text = Fleet[38].ShipDescription;

        //39
        comboBox40.Text = Fleet[39].GridLetter;
        textBox40_ShipType.Text = Fleet[39].shiptype;
        textBox40_NumShips.Text = Fleet[39].shipcount;
        textBox40_ShipDesc.Text = Fleet[39].ShipDescription;

    }
    

    //write fleet.xml file
    private void WriteFleetFile()
    {
        
	        int x, val;

        
            //clear out existing file
        System.IO.File.WriteAllText(@FleetFilename, "");
        

           //append to new file
           System.IO.File.AppendAllText(@FleetFilename, "<?xml version=\"1.0\"?>" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "<!-- Sector Fleet Data" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "MAXIMUM Number of entries: 40" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "FILENAME:  fleet.xml" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "FILE LOCATION: in the same directory as the sector's all.sec file" + Environment.NewLine + Environment.NewLine + Environment.NewLine);

           System.IO.File.AppendAllText(@FleetFilename, "Sector Letter Grid Locations:" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "A B C D" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "E F G H" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "I J K L" + Environment.NewLine);
           System.IO.File.AppendAllText(@FleetFilename, "M N O P" + Environment.NewLine);
          
        		
    System.IO.File.AppendAllText(@FleetFilename, "Ship Types (for icons)" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "IMPERIAL" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "1  Close Escort" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "2  System Defense Boat" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "3  Patrol Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "4  Mercenary Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "5  Dreadnought" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "6  Destroyer" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "7  Corvette" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "8  Tender" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "9  Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "10 Carrier" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "11 Frigate" + Environment.NewLine);
	
	System.IO.File.AppendAllText(@FleetFilename, "	Aslan" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "12  Close Escort" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "13  System Defense Boat" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "14  Patrol Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "15  Mercenary Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "16  Dreadnought" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "17  Destroyer" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "18  Corvette" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "19  Tender" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "20  Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "21  Carrier" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "22  Frigate" + Environment.NewLine);
	
	System.IO.File.AppendAllText(@FleetFilename, "		Vargr" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "23  Close Escort" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "24  System Defense Boat" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "25  Patrol Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "26  Mercenary Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "27  Dreadnought" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "28  Destroyer" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "29  Corvette" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "30  Tender" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "31  Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "32  Carrier" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "33  Frigate" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "34  Corsair" + Environment.NewLine);
	
	System.IO.File.AppendAllText(@FleetFilename, "	Zhodani" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "35  Close Escort" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "36  System Defense Boat" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "37  Patrol Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "38  Mercenary Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "39  Dreadnought" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "40  Destroyer" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "41  Corvette" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "42  Tender" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "43  Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "44  Carrier" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "45  Frigate" + Environment.NewLine);
	
	System.IO.File.AppendAllText(@FleetFilename, "Solomani" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "46  Close Escort" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "47  System Defense Boat" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "48  Patrol Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "49  Mercenary Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "50  Dreadnought" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "51  Destroyer" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "52  Corvette" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "53  Tender" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "54  Cruiser" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "55  Carrier" + Environment.NewLine);
	System.IO.File.AppendAllText(@FleetFilename, "56  Frigate" + Environment.NewLine + Environment.NewLine + Environment.NewLine);
         
         
    System.IO.File.AppendAllText(@FleetFilename, "FORMAT with max # of characters:" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "<fleet grid=\"GRIDLETTER[1]\" shiptype=\"[number]\" shipcount=\"[number]\" shipdesc=\"xxxxxxxxx[25]\" />	\"" + Environment.NewLine);

    System.IO.File.AppendAllText(@FleetFilename, "EXAMPLE:" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "<?xml version=\"1.0\"?>" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "<sectorfleet>" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "<fleet grid=\"A\" shiptype=\"1\" shipcount=\"3\" shipdesc=\"Close Escort\" />" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "</sectorfleet>" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "... more entries" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "</xml>" + Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, "-->" + Environment.NewLine);


    System.IO.File.AppendAllText(@FleetFilename, "<sectorfleet>" + Environment.NewLine);
    
    for (x = 0; x < 40; x++)
    {
 
        val = 0;
        Int32.TryParse( Fleet[x].shipcount, out val );
        
        if (val > 0)
        {
            System.IO.File.AppendAllText(@FleetFilename, "<fleet grid=\"" + Fleet[x].GridLetter + "\" shiptype=\"" + Fleet[x].shiptype +
            "\" shipcount= \"" + Fleet[x].shipcount + "\" shipdesc=\"" + Fleet[x].ShipDescription +  "\" />" +Environment.NewLine);
        }
    }
  
        
    System.IO.File.AppendAllText(@FleetFilename, "</sectorfleet>"+Environment.NewLine);
    System.IO.File.AppendAllText(@FleetFilename, Environment.NewLine + "</xml>" + Environment.NewLine);
              
        
    }  //end writeaccountfile

   





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
  

    private void pictureBox1_Click(object sender, EventArgs e)
    {
        DialogResult myexitflag = MessageBox.Show(null, "TASAT Fleet Editor for the Travellers' Aid Society Access Terminal fleet.xml  files" +
        "\nBy Perry Horner 2017\nThe Traveller game in all forms is owned by Far Future Enterprises" +
        "Copyright 1977-2017 Far Future Enterprises\nTraveller is a registered trademark of Far Future Enterprises",
        "About", MessageBoxButtons.OK, MessageBoxIcon.Information);
    }

   

    private void button1Save_Click(object sender, EventArgs e)
    {
        // Show the dialog and get result.
        DialogResult result = saveFileDialog1.ShowDialog();
        if (result == DialogResult.OK) // Test result.
        {
            FleetFilename = saveFileDialog1.FileName;
            WriteFleetFile();

        }
        Environment.Exit(0);
    }

    private void button1Cancel_Click(object sender, EventArgs e)
    {
        this.Close();
    }

    private void Form1_Load(object sender, EventArgs e)
    {

    }

    private void label1_Click(object sender, EventArgs e)
    {

    }

    private void button1_openfleet_Click(object sender, EventArgs e)
    {
        // Show the dialog and get result.
        DialogResult result1 = openFileDialog1.ShowDialog();
        if (result1 == DialogResult.OK) // Test result.
        {
            FleetFilename = openFileDialog1.FileName;
            ClearFleetArray(); //set user account info to empty
            ReadFleetFile(); //load tas.xml
            PopulateScreen(); //fill in fleet entries
        }
        

    }

    private void folderBrowserDialog1_HelpRequest(object sender, EventArgs e)
    {

    }

    private void textBox1_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[0].shiptype = textBox1_ShipType.Text;
    }

    private void textBox1_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[0].shipcount = textBox1_NumShips.Text;
    }

    private void textBox1_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[0].ShipDescription = textBox1_ShipDesc.Text;
    }

    private void textBox2_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[1].shipcount = textBox2_NumShips.Text;
    }

    private void textBox2_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[1].shiptype = textBox2_ShipType.Text;
    }

    private void textBox2_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[1].ShipDescription = textBox2_ShipDesc.Text;
    }

    private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox1.SelectedIndex;
        Fleet[0].GridLetter = comboBox1.Text;
    }

    private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox2.SelectedIndex;
        Fleet[1].GridLetter = comboBox2.Text;
    }

    private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox3.SelectedIndex;
        Fleet[2].GridLetter = comboBox3.Text;
    }

    private void textBox3_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[2].shiptype = textBox3_ShipType.Text;
    }

    private void textBox3_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[2].shipcount = textBox3_NumShips.Text;
    }

    private void textBox3_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[2].ShipDescription = textBox3_ShipDesc.Text;
    }

    private void comboBox4_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox4.SelectedIndex;
        Fleet[3].GridLetter = comboBox4.Text;
    }

    private void textBox4_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[3].shiptype = textBox4_ShipType.Text;
    }

    private void textBox4_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[3].shipcount = textBox4_NumShips.Text;
    }

    private void textBox4_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[3].ShipDescription = textBox4_ShipDesc.Text;
    }

    private void comboBox5_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox5.SelectedIndex;
        Fleet[4].GridLetter = comboBox5.Text;
    }

    private void textBox5_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[4].shiptype = textBox5_ShipType.Text;
    }

    private void textBox5_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[4].shipcount = textBox5_NumShips.Text;
    }

    private void textBox5_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[4].ShipDescription = textBox5_ShipDesc.Text;
    }

    private void comboBox6_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox6.SelectedIndex;
        Fleet[5].GridLetter = comboBox6.Text;
    }

    private void textBox6_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[5].shiptype = textBox6_ShipType.Text;
    }

    private void textBox6_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[5].shipcount = textBox6_NumShips.Text;
    }

    private void textBox6_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[5].ShipDescription = textBox6_ShipDesc.Text;
    }

    private void comboBox7_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox6.SelectedIndex;
        Fleet[6].GridLetter = comboBox6.Text;
    }

    private void textBox7_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[6].shiptype = textBox7_ShipType.Text;
    }

    private void textBox7_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[6].shipcount = textBox7_NumShips.Text;
    }

    private void textBox7_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[6].ShipDescription = textBox7_ShipDesc.Text;
    }

    private void comboBox8_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox8.SelectedIndex;
        Fleet[7].GridLetter = comboBox8.Text;
    }

    private void textBox8_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[7].shiptype = textBox8_ShipType.Text;
    }

    private void textBox8_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[7].shipcount = textBox8_NumShips.Text;
    }

    private void textBox8_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[7].ShipDescription = textBox8_ShipDesc.Text;
    }

    private void comboBox9_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox9.SelectedIndex;
        Fleet[8].GridLetter = comboBox9.Text;
    }

    private void textBox9_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[8].shiptype = textBox9_ShipType.Text;
    }

    private void textBox9_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[8].shipcount = textBox9_NumShips.Text;
    }

    private void textBox9_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[8].ShipDescription = textBox9_ShipDesc.Text;
    }

    private void comboBox10_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox10.SelectedIndex;
        Fleet[9].GridLetter = comboBox10.Text;
    }

    private void textBox10_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[9].shiptype = textBox10_ShipType.Text;
    }

    private void textBox10_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[9].shipcount = textBox10_NumShips.Text;
    }

    private void textBox10_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[9].ShipDescription = textBox10_ShipDesc.Text;
    }

    private void comboBox11_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox11.SelectedIndex;
        Fleet[10].GridLetter = comboBox11.Text;
    }

    private void textBox11_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[10].shiptype = textBox11_ShipType.Text;
    }

    private void textBox11_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[10].shipcount = textBox11_NumShips.Text;
    }

    private void textBox11_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[10].ShipDescription = textBox11_ShipDesc.Text;
    }

    private void comboBox12_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox12.SelectedIndex;
        Fleet[11].GridLetter = comboBox12.Text;
    }

    private void textBox12_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[11].shiptype = textBox12_ShipType.Text;
    }

    private void textBox12_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[11].shipcount = textBox12_NumShips.Text;
    }

    private void textBox12_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[11].ShipDescription = textBox12_ShipDesc.Text;
    }

    private void comboBox13_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox13.SelectedIndex;
        Fleet[12].GridLetter = comboBox13.Text;
    }

    private void textBox13_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[12].shiptype = textBox13_ShipType.Text;
    }

    private void textBox13_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[12].shipcount = textBox13_NumShips.Text;
    }

    private void textBox13_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[12].ShipDescription = textBox13_ShipDesc.Text;
    }

    private void comboBox14_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox14.SelectedIndex;
        Fleet[13].GridLetter = comboBox14.Text;
    }

    private void textBox14_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[13].shiptype = textBox14_ShipType.Text;
    }

    private void textBox14_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[13].shipcount = textBox14_NumShips.Text;
    }

    private void textBox14_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[13].ShipDescription = textBox14_ShipDesc.Text;
    }

    private void comboBox15_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox15.SelectedIndex;
        Fleet[14].GridLetter = comboBox15.Text;
    }

    private void textBox15_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[14].shiptype = textBox15_ShipType.Text;
    }

    private void textBox15_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[14].shipcount = textBox15_NumShips.Text;
    }

    private void textBox15_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[14].ShipDescription = textBox15_ShipDesc.Text;
    }

    private void comboBox16_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox16.SelectedIndex;
        Fleet[15].GridLetter = comboBox16.Text;
    }

    private void textBox16_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[15].shiptype = textBox16_ShipType.Text;
    }

    private void textBox16_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[15].shipcount = textBox16_NumShips.Text;
    }

    private void textBox16_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[15].ShipDescription = textBox16_ShipDesc.Text;
    }

    private void comboBox17_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox17.SelectedIndex;
        Fleet[16].GridLetter = comboBox17.Text;
    }

    private void textBox17_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[16].shiptype = textBox17_ShipType.Text;
    }

    private void textBox17_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[16].shipcount = textBox17_NumShips.Text;
    }

    private void textBox17_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[16].ShipDescription = textBox17_ShipDesc.Text;
    }

    private void comboBox18_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox18.SelectedIndex;
        Fleet[17].GridLetter = comboBox18.Text;
    }

    private void textBox18_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[17].shiptype = textBox18_ShipType.Text;
    }

    private void textBox18_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[17].shipcount = textBox18_NumShips.Text;
    }

    private void textBox18_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[17].ShipDescription = textBox18_ShipDesc.Text;
    }

    private void comboBox19_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox19.SelectedIndex;
        Fleet[18].GridLetter = comboBox19.Text;
    }

    private void textBox19_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[18].shiptype = textBox19_ShipType.Text;
    }

    private void textBox19_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[18].shipcount = textBox19_NumShips.Text;
    }

    private void textBox19_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[18].ShipDescription = textBox19_ShipDesc.Text;
    }

    private void comboBox20_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox20.SelectedIndex;
        Fleet[19].GridLetter = comboBox20.Text;
    }

    private void textBox20_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[19].shiptype = textBox20_ShipType.Text;
    }

    private void textBox20_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[19].shipcount = textBox20_NumShips.Text;
    }

    private void textBox20_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[19].ShipDescription = textBox20_ShipDesc.Text;
    }

    private void comboBox21_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox21.SelectedIndex;
        Fleet[20].GridLetter = comboBox21.Text;
    }

    private void textBox21_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[20].shiptype = textBox21_ShipType.Text;
    }

    private void textBox21_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[20].shipcount = textBox21_NumShips.Text;
    }

    private void textBox21_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[20].ShipDescription = textBox21_ShipDesc.Text;
    }

    private void comboBox22_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox22.SelectedIndex;
        Fleet[21].GridLetter = comboBox22.Text;
    }

    private void textBox22_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[21].ShipDescription = textBox22_ShipDesc.Text;
    }

    private void textBox23_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[22].shiptype = textBox23_ShipType.Text;
    }

    private void comboBox23_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox23.SelectedIndex;
        Fleet[22].GridLetter = comboBox23.Text;
    }

    private void textBox22_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[21].shiptype = textBox22_ShipType.Text;
    }

    private void textBox22_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[21].shipcount = textBox22_NumShips.Text;
    }

    private void textBox23_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[22].shipcount = textBox23_NumShips.Text;
    }

    private void textBox23_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[22].ShipDescription = textBox23_ShipDesc.Text;
    }

    private void comboBox24_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox24.SelectedIndex;
        Fleet[23].GridLetter = comboBox24.Text;
    }

    private void textBox24_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[23].shiptype = textBox24_ShipType.Text;
    }

    private void textBox24_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[23].shipcount = textBox24_NumShips.Text;
    }

    private void textBox24_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[23].ShipDescription = textBox24_ShipDesc.Text;
    }

    private void comboBox25_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox25.SelectedIndex;
        Fleet[24].GridLetter = comboBox25.Text;
    }

    private void textBox25_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[24].shiptype = textBox25_ShipType.Text;
    }

    private void textBox25_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[24].shipcount = textBox25_NumShips.Text;
    }

    private void textBox25_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[24].ShipDescription = textBox25_ShipDesc.Text;
    }

    private void comboBox26_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox26.SelectedIndex;
        Fleet[25].GridLetter = comboBox26.Text;
    }

    private void textBox26_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[25].shiptype = textBox26_ShipType.Text;
    }

    private void textBox26_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[25].shipcount = textBox26_NumShips.Text;
    }

    private void textBox26_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[25].ShipDescription = textBox26_ShipDesc.Text;
    }

    private void comboBox27_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox27.SelectedIndex;
        Fleet[26].GridLetter = comboBox27.Text;
    }

    private void textBox27_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[26].shiptype = textBox27_ShipType.Text;
    }

    private void textBox27_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[26].shipcount = textBox27_NumShips.Text;
    }

    private void textBox27_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[26].ShipDescription = textBox27_ShipDesc.Text;
    }

    private void comboBox28_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox28.SelectedIndex;
        Fleet[27].GridLetter = comboBox28.Text;
    }

    private void textBox28_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[27].shiptype = textBox28_ShipType.Text;
    }

    private void textBox28_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[27].shipcount = textBox28_NumShips.Text;
    }

    private void textBox28_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[27].ShipDescription = textBox28_ShipDesc.Text;
    }

    private void comboBox29_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox29.SelectedIndex;
        Fleet[28].GridLetter = comboBox29.Text;
    }

    private void textBox29_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[28].shiptype = textBox29_ShipType.Text;
    }

    private void textBox29_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[28].shipcount = textBox29_NumShips.Text;
    }

    private void textBox29_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[28].ShipDescription = textBox29_ShipDesc.Text;
    }

    private void comboBox30_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox30.SelectedIndex;
        Fleet[29].GridLetter = comboBox30.Text;
    }

    private void textBox30_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[29].shiptype = textBox30_ShipType.Text;
    }

    private void textBox30_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[29].shipcount = textBox30_NumShips.Text;
    }

    private void textBox30_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[29].ShipDescription = textBox30_ShipDesc.Text;
    }

    private void comboBox31_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox31.SelectedIndex;
        Fleet[30].GridLetter = comboBox31.Text;
    }

    private void textBox31_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[30].shiptype = textBox31_ShipType.Text;
    }

    private void textBox31_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[30].shipcount = textBox31_NumShips.Text;
    }

    private void textBox31_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[30].ShipDescription = textBox31_ShipDesc.Text;
    }

    private void comboBox32_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox32.SelectedIndex;
        Fleet[31].GridLetter = comboBox32.Text;
    }

    private void textBox32_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[31].shiptype = textBox32_ShipType.Text;
    }

    private void textBox32_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[31].shipcount = textBox32_NumShips.Text;
    }

    private void textBox32_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[31].ShipDescription = textBox32_ShipDesc.Text;
    }

    private void comboBox33_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox33.SelectedIndex;
        Fleet[32].GridLetter = comboBox33.Text;
    }

    private void textBox33_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[32].shiptype = textBox33_ShipType.Text;
    }

    private void textBox33_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[32].shipcount = textBox33_NumShips.Text;
    }

    private void textBox33_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[32].ShipDescription = textBox33_ShipDesc.Text;
    }

    private void comboBox34_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox34.SelectedIndex;
        Fleet[33].GridLetter = comboBox34.Text;
    }

    private void textBox34_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[33].shiptype = textBox34_ShipType.Text;
    }

    private void textBox34_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[33].shipcount = textBox34_NumShips.Text;
    }

    private void textBox34_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[33].ShipDescription = textBox34_ShipDesc.Text;
    }

    private void comboBox35_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox35.SelectedIndex;
        Fleet[34].GridLetter = comboBox35.Text;
    }

    private void textBox35_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[34].shiptype = textBox35_ShipType.Text;
    }

    private void textBox35_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[34].shipcount = textBox35_NumShips.Text;
    }

    private void textBox35_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[34].ShipDescription = textBox35_ShipDesc.Text;
    }

    private void comboBox36_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox36.SelectedIndex;
        Fleet[35].GridLetter = comboBox36.Text;
    }

    private void textBox36_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[35].shiptype = textBox36_ShipType.Text;
    }

    private void textBox36_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[35].shipcount = textBox36_NumShips.Text;
    }

    private void textBox36_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[35].ShipDescription = textBox36_ShipDesc.Text;
    }

    private void comboBox37_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox37.SelectedIndex;
        Fleet[36].GridLetter = comboBox37.Text;
    }

    private void textBox37_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[36].shiptype = textBox37_ShipType.Text;
    }

    private void textBox37_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[36].shipcount = textBox37_NumShips.Text;
    }

    private void textBox37_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[36].ShipDescription = textBox37_ShipDesc.Text;
    }

    private void comboBox38_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox38.SelectedIndex;
        Fleet[37].GridLetter = comboBox38.Text;
    }

    private void textBox38_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[37].shiptype = textBox38_ShipType.Text;
    }

    private void textBox38_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[37].shipcount = textBox38_NumShips.Text;
    }

    private void textBox38_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[37].ShipDescription = textBox38_ShipDesc.Text;
    }

    private void comboBox39_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox39.SelectedIndex;
        Fleet[38].GridLetter = comboBox39.Text;
    }

    private void textBox39_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[38].shiptype = textBox39_ShipType.Text;
    }

    private void textBox39_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[38].shipcount = textBox39_NumShips.Text;
    }

    private void textBox39_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[38].ShipDescription = textBox39_ShipDesc.Text;
    }

    private void comboBox40_SelectedIndexChanged(object sender, EventArgs e)
    {
        int index = comboBox40.SelectedIndex;
        Fleet[39].GridLetter = comboBox40.Text;
    }

    private void textBox40_ShipType_TextChanged(object sender, EventArgs e)
    {
        Fleet[39].shiptype = textBox40_ShipType.Text;
    }

    private void textBox40_NumShips_TextChanged(object sender, EventArgs e)
    {
        Fleet[39].shipcount = textBox40_NumShips.Text;
    }

    private void textBox40_ShipDesc_TextChanged(object sender, EventArgs e)
    {
        Fleet[39].ShipDescription = textBox40_ShipDesc.Text;
    }

    private void pictureBox2_Click(object sender, EventArgs e)
    {

    }

   
    
  } //end form1
} //end namespace usereditor
