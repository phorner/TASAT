using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;


namespace AdminMenu
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1MemberEdit_Click(object sender, EventArgs e)
        {
            Process ExternalProcess = new Process();
            ExternalProcess.StartInfo.FileName = "usereditor.tas";
            ExternalProcess.StartInfo.CreateNoWindow = true;
            ExternalProcess.StartInfo.UseShellExecute = false;
            //ExternalProcess.StartInfo.WindowStyle = ProcessWindowStyle.Maximized;
            ExternalProcess.Start();
            ExternalProcess.WaitForExit();

        }

        private void button2ConfigEdit_Click(object sender, EventArgs e)
        {

            Process ExternalProcess = new Process();
            ExternalProcess.StartInfo.FileName = "TASConfigEdit.tas";
            ExternalProcess.StartInfo.CreateNoWindow = true;
            ExternalProcess.StartInfo.UseShellExecute = false;
            //ExternalProcess.StartInfo.WindowStyle = ProcessWindowStyle.Maximized;
            ExternalProcess.Start();
            ExternalProcess.WaitForExit();
            
        }

        private void button1Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            Form2 frm = new Form2();

            frm.Width = 820;
            frm.Height = 640;

            TextBox errortextbox1 = new TextBox();


            errortextbox1.Multiline = true;
            // Add vertical scroll bars to the TextBox control.
            errortextbox1.ScrollBars = ScrollBars.Vertical;

            errortextbox1.WordWrap = true;
            errortextbox1.Width = 800;
            errortextbox1.Height = 600;

            errortextbox1.Text = File.ReadAllText(@"error.txt");
            errortextbox1.SelectionStart = 0;
            errortextbox1.SelectionLength = 0;


            frm.Controls.Add(errortextbox1);
            frm.Show();

        }

        private void TASATfullscreen_Click(object sender, EventArgs e)
        {
            Process ExternalProcess = new Process();
            ExternalProcess.StartInfo.FileName = "TAS3.tas";
            ExternalProcess.StartInfo.CreateNoWindow = true;
            ExternalProcess.StartInfo.UseShellExecute = false;
            //ExternalProcess.StartInfo.WindowStyle = ProcessWindowStyle.Maximized;
            ExternalProcess.Start();
            ExternalProcess.WaitForExit();
        }

        private void TASATwindowscreen_Click(object sender, EventArgs e)
        {
            Process ExternalProcess = new Process();
            ExternalProcess.StartInfo.FileName = "TAS3.tas";
            ExternalProcess.StartInfo.CreateNoWindow = true;
            ExternalProcess.StartInfo.UseShellExecute = false;
            ExternalProcess.StartInfo.Arguments = "-w";
            //ExternalProcess.StartInfo.WindowStyle = ProcessWindowStyle.Maximized;
            ExternalProcess.Start();
            ExternalProcess.WaitForExit();
        }

        private void button3FleetEditor_Click(object sender, EventArgs e)
        {
            Process ExternalProcess = new Process();
            ExternalProcess.StartInfo.FileName = "FleetEditor.tas";
            ExternalProcess.StartInfo.CreateNoWindow = true;
            ExternalProcess.StartInfo.UseShellExecute = false;
            //ExternalProcess.StartInfo.WindowStyle = ProcessWindowStyle.Maximized;
            ExternalProcess.Start();
            ExternalProcess.WaitForExit();
        }
    }
    public class Form2 : Form
    {
        public Form2()
        {
            Text = "Error Log";



        }
    }

}
