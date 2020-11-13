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

namespace ConfigEdit
{
    public partial class Form1 : Form
    {
        string Era;
        string TASYear;
        string TASDay;
        string TASVersion;
        string ALNAVLIB, ALNAVFLEET, ALNEWS, ALLIBDATA, ALACCNT, ALCLASS, ALMERC, ALXBT, ALSPECCOLL;

        public Form1()
        {
            InitializeComponent();
            ReadINIFile(); //load tas.xml
        }

      


    //Write tas.xml file
     private void WriteConfigFile()
        {

            //clear out existing file
            System.IO.File.WriteAllText(@"tas.xml","");
            //append to new file
            System.IO.File.AppendAllText(@"tas.xml", "<?xml version=\"1.0\"?>" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "<!-- Travellers' Aid Society Access Terminal" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "TAS.XML initialization file" + Environment.NewLine + Environment.NewLine + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    Set era for resources" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    1=Classic/MegaTraveller 1070-1116" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    2=Traveller the New Era 1116+ (1200)" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    3=Milieu 0 (T4)" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    4=Custom" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    5=T5 (not implemented yet - 09/2016" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "Set Current Year (ie 1085)" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "Set Current Day (1-365)" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "Access levels range from 0 to 10" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    0=basic user" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    1=TAS charter membership" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    2-9 are members with access to special areas" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    10=Administrator (Referee)" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "Set access level number for each area for access" + Environment.NewLine + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALNAVLIB= Navigation Library" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALNAVFLEET= Sector Fleet Information" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALNEWS= TAS News Service" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALLIBDATA= Library Data" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALACCNT= Account Services" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALCLASS= Classifieds" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALMERC= Classifieds-Missions/Mercenary tickets" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALXBT= Xboat Communication Message Services" + Environment.NewLine);
            System.IO.File.AppendAllText(@"tas.xml", "    ALSPECCOLL= Special Collections Library access -->" + Environment.NewLine + Environment.NewLine);

            System.IO.File.AppendAllText(@"tas.xml", "<attributes version=\"" + TASVersion + "\" era=\"" + Era + "\" year=\"" +
                TASYear + "\" day=\"" + TASDay + "\" ALNAVLIB=\"" + ALNAVLIB + "\" ALNAVFLEET=\"" + ALNAVFLEET +
                "\" ALNEWS=\"" + ALNEWS + "\"  ALLIBDATA=\"" + ALLIBDATA + "\" ALACCNT=\"" + ALACCNT +
                "\" ALCLASS=\"" + ALCLASS + "\" ALMERC=\"" + ALMERC + "\" ALXBT=\"" + ALXBT + "\" ALSPECCOLL=\"" + ALSPECCOLL + "\" />" + Environment.NewLine + "</xml>" + Environment.NewLine);

        } //end WriteConfigFile
      

        //READ tas.xml file
    private void ReadINIFile()
        {
            int term = 0;

    /*
          Set era for resources
    1=Classic/MegaTraveller 1070-1116
    2=Traveller the New Era 1116+ (1200)
    3=Milieu 0 (T4)
    4=Custom
    5=T5 (not implemented yet - 09/2016)

    Set Current Year (ie 1085)
    Set Current Day (1-365)

	Access levels range from 0 to 9
    0=basic user
    1=TAS charter membership
    2-9 are members with access to special areas
    10=Administrator (Referee)
   
    Set access level number for each area for access

 ALNAVLIB= Navigation Library
 ALNAVFLEET= Sector Fleet Information
 ALNEWS= TAS News Service
 ALLIBDATA= Library Data 
 ALACCNT= Account Services 
 ALCLASS= Classifieds 
 ALMERC= Classifieds-Missions/Mercenary tickets 
 ALXBT= Xboat Communication Message Services
 ALSPECCOLL= Special Collections Library access 
 */
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

                        }
                    }
                } //end while
                xConfigFile.Close();

                //Populate form with loaded values
                textBox3.Text = ALACCNT;
                textBox4.Text = ALCLASS;
                textBox5.Text = ALMERC;
                textBox6.Text = ALLIBDATA;
                textBox7.Text = ALNAVLIB;
                textBox8.Text = ALNEWS;
                textBox9.Text = ALXBT;
                textBox10.Text = ALSPECCOLL;
                textBox11.Text = ALNAVFLEET;

                textBox1.Text = TASYear;
                textBox2.Text = TASDay;

                textBox12.Text = TASVersion;

                //check era radio button
                //classic megatraveller
                if (Era.Equals("1"))
                {
                    radioButton1.Checked = true;
                }
                else
                {
                    radioButton1.Checked = false;
                }

                //TNE
                if (Era.Equals("2"))
                {
                    radioButton3.Checked = true;
                }
                else
                {
                    radioButton3.Checked = false;
                }

                //Mileu 0 T4
                if (Era.Equals("3"))
                {
                    radioButton4.Checked = true;
                }
                else
                {
                    radioButton4.Checked = false;
                }

                //Custom
                if (Era.Equals("4"))
                {
                    radioButton6.Checked = true;
                }
                else
                {
                    radioButton6.Checked = false;
                }

                //T5
                if (Era.Equals("5"))
                {
                    radioButton5.Checked = true;
                }
                else
                {
                    radioButton5.Checked = false;
                }
            }//end file exists check
            else 
            {
                DialogResult myexitflag = MessageBox.Show(null,"Could not read or find tas.xml file.\nMake sure it is in the TASAT root directory.", "File Does Not Exist", MessageBoxButtons.OK , MessageBoxIcon.Exclamation);
                if (myexitflag == DialogResult.OK)
                {
                    //this.Close();
                    //this.Dispose();
                    Environment.Exit(0);
                    //Application.Exit();
                    
                }
                
            } //file does not exist

            /*
                        while (xml && xml->read())
                        {
                            if (core::stringw("attributes") == xml->getNodeName())
	
                            else
                                if (core::stringw("accesslevel") == xml->getNodeName())
                                {
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
                        */
        }//end readinifile

        //IMPERIAL Sun Symbol
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            DialogResult myexitflag = MessageBox.Show(null, "TASAT Editor for the Travellers' Aid Society Access Terminal tas.xml configuration file" +
                "\nBy Perry Horner 2016\nThe Traveller game in all forms is owned by Far Future Enterprises"+
            "Copyright 1977-2016 Far Future Enterprises\nTraveller is a registered trademark of Far Future Enterprises",
            "About", MessageBoxButtons.OK , MessageBoxIcon.Information);
        }

        //Entry of YEAR
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;

        }

        //entry of DATE
        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //account services
        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //classifieds
        private void textBox4_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //missions and tickets
        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //library data
        private void textBox6_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //navigation library
        private void textBox7_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //news service
        private void textBox8_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //xboat messages
        private void textBox9_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //special collections
        private void textBox10_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        private void textBox11_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Initialize the flag to false.
            bool nonNumberEntered = false;

            if (e.KeyChar < '0' || e.KeyChar > '9')
            {
                if (e.KeyChar != '\b')
                {
                    nonNumberEntered = true;
                }

            }
            // Stop the character from being entered into the control since it is non-numerical.
            e.Handled = nonNumberEntered;
        }

        //PRESS CANCEL BUTTON to close program
        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //SAVE BUTTON to save tas.xml file
        private void button1_Click(object sender, EventArgs e)
        {
            WriteConfigFile();
            Environment.Exit(0);
        }

        //Year changed
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            TASYear = textBox1.Text;
        }

        //Day changed
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            TASDay = textBox2.Text;
        }

        //account services changed
        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            ALACCNT = textBox3.Text;
        }
        //classified changed
        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            ALCLASS = textBox4.Text;
        }
        //mercenery changed
        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            ALMERC = textBox5.Text;
        }
        //libdata changed
        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            ALLIBDATA = textBox6.Text;
        }
        //navigation library changed
        private void textBox7_TextChanged(object sender, EventArgs e)
        {
            ALNAVLIB = textBox7.Text;
        }
        //news service changed
        private void textBox8_TextChanged(object sender, EventArgs e)
        {
            ALNEWS = textBox8.Text;
        }
        //xboat messages changed
        private void textBox9_TextChanged(object sender, EventArgs e)
        {
            ALXBT = textBox9.Text;
        }
        //special collections changed
        private void textBox10_TextChanged(object sender, EventArgs e)
        {
            ALSPECCOLL = textBox10.Text;
        }
        //fleet info changed
        private void textBox11_TextChanged(object sender, EventArgs e)
        {
            ALNAVFLEET = textBox11.Text;
        }
        //tne era changed
        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            Era = "2";
        }
        //classic era changed
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            Era = "1";
        }
        //Milieu 0 era changed
        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            Era = "3";
        }
        //T5 era changed
        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            Era = "5";
        }
        //custom era changed
        private void radioButton6_CheckedChanged(object sender, EventArgs e)
        {
            Era = "4";
        } 
    } //end public partial class Form1 : Form
} //end namespace ConfigEdit
