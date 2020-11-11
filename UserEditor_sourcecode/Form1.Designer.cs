namespace UserEditor
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.listBox1Users = new System.Windows.Forms.ListBox();
            this.label1UserAccount = new System.Windows.Forms.Label();
            this.textBox1MemNum = new System.Windows.Forms.TextBox();
            this.label1MemNum = new System.Windows.Forms.Label();
            this.textBox1Name = new System.Windows.Forms.TextBox();
            this.label1Name = new System.Windows.Forms.Label();
            this.textBox1Password = new System.Windows.Forms.TextBox();
            this.label1Password = new System.Windows.Forms.Label();
            this.textBox1UPP = new System.Windows.Forms.TextBox();
            this.label1UPP = new System.Windows.Forms.Label();
            this.textBox1HomeWorld = new System.Windows.Forms.TextBox();
            this.label1HomeWorld = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label1Race = new System.Windows.Forms.Label();
            this.textBox1AccessLevel = new System.Windows.Forms.TextBox();
            this.label1AccessLevel = new System.Windows.Forms.Label();
            this.checkBox1HiddenTAS = new System.Windows.Forms.CheckBox();
            this.label1HiddenTAS = new System.Windows.Forms.Label();
            this.button1Cancel = new System.Windows.Forms.Button();
            this.button1Save = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label1HideInfo = new System.Windows.Forms.Label();
            this.button1AddUser = new System.Windows.Forms.Button();
            this.textBox1ALNAVLIB = new System.Windows.Forms.TextBox();
            this.label1ALNAVLIB = new System.Windows.Forms.Label();
            this.textBox1ALNAVFLEET = new System.Windows.Forms.TextBox();
            this.label1ALNAVFLEET = new System.Windows.Forms.Label();
            this.textBox1ALNEWS = new System.Windows.Forms.TextBox();
            this.label1ALNEWS = new System.Windows.Forms.Label();
            this.textBox1ALLIBDATA = new System.Windows.Forms.TextBox();
            this.label1ALLIBDATA = new System.Windows.Forms.Label();
            this.textBox1ALACCNT = new System.Windows.Forms.TextBox();
            this.label1ALACCNT = new System.Windows.Forms.Label();
            this.textBox1ALCLASS = new System.Windows.Forms.TextBox();
            this.label1ALCLASS = new System.Windows.Forms.Label();
            this.textBox1ALMERC = new System.Windows.Forms.TextBox();
            this.label1ALMERC = new System.Windows.Forms.Label();
            this.textBox1ALXBT = new System.Windows.Forms.TextBox();
            this.label1ALXBT = new System.Windows.Forms.Label();
            this.textBox1ALSPECCOLL = new System.Windows.Forms.TextBox();
            this.label1ALSPECCOLL = new System.Windows.Forms.Label();
            this.label1ALInfo = new System.Windows.Forms.Label();
            this.button1DELUser = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxMemTotal = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // listBox1Users
            // 
            this.listBox1Users.ForeColor = System.Drawing.SystemColors.InfoText;
            this.listBox1Users.FormattingEnabled = true;
            this.listBox1Users.Location = new System.Drawing.Point(12, 38);
            this.listBox1Users.Name = "listBox1Users";
            this.listBox1Users.ScrollAlwaysVisible = true;
            this.listBox1Users.Size = new System.Drawing.Size(166, 173);
            this.listBox1Users.TabIndex = 0;
            this.listBox1Users.DrawItem += new System.Windows.Forms.DrawItemEventHandler(this.listBox1Users_DrawItem);
            this.listBox1Users.SelectedIndexChanged += new System.EventHandler(this.listBox1Users_SelectedIndexChanged);
            // 
            // label1UserAccount
            // 
            this.label1UserAccount.AutoSize = true;
            this.label1UserAccount.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1UserAccount.Location = new System.Drawing.Point(13, 13);
            this.label1UserAccount.Name = "label1UserAccount";
            this.label1UserAccount.Size = new System.Drawing.Size(148, 16);
            this.label1UserAccount.TabIndex = 1;
            this.label1UserAccount.Text = "Select User Account";
            // 
            // textBox1MemNum
            // 
            this.textBox1MemNum.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1MemNum.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox1MemNum.Enabled = false;
            this.textBox1MemNum.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1MemNum.Location = new System.Drawing.Point(312, 12);
            this.textBox1MemNum.Name = "textBox1MemNum";
            this.textBox1MemNum.ReadOnly = true;
            this.textBox1MemNum.Size = new System.Drawing.Size(42, 15);
            this.textBox1MemNum.TabIndex = 2;
            // 
            // label1MemNum
            // 
            this.label1MemNum.AutoSize = true;
            this.label1MemNum.Location = new System.Drawing.Point(185, 16);
            this.label1MemNum.Name = "label1MemNum";
            this.label1MemNum.Size = new System.Drawing.Size(121, 13);
            this.label1MemNum.TabIndex = 3;
            this.label1MemNum.Text = "Member Number (1-199)";
            // 
            // textBox1Name
            // 
            this.textBox1Name.Location = new System.Drawing.Point(312, 44);
            this.textBox1Name.MaxLength = 30;
            this.textBox1Name.Name = "textBox1Name";
            this.textBox1Name.Size = new System.Drawing.Size(121, 20);
            this.textBox1Name.TabIndex = 4;
            this.textBox1Name.WordWrap = false;
            this.textBox1Name.TextChanged += new System.EventHandler(this.textBox1Name_TextChanged);
            this.textBox1Name.Leave += new System.EventHandler(this.textBox1Name_Leave);
            // 
            // label1Name
            // 
            this.label1Name.AutoSize = true;
            this.label1Name.Location = new System.Drawing.Point(240, 47);
            this.label1Name.Name = "label1Name";
            this.label1Name.Size = new System.Drawing.Size(60, 13);
            this.label1Name.TabIndex = 5;
            this.label1Name.Text = "User Name";
            // 
            // textBox1Password
            // 
            this.textBox1Password.Location = new System.Drawing.Point(312, 70);
            this.textBox1Password.MaxLength = 30;
            this.textBox1Password.Name = "textBox1Password";
            this.textBox1Password.Size = new System.Drawing.Size(121, 20);
            this.textBox1Password.TabIndex = 6;
            this.textBox1Password.TextChanged += new System.EventHandler(this.textBox1Password_TextChanged);
            // 
            // label1Password
            // 
            this.label1Password.AutoSize = true;
            this.label1Password.Location = new System.Drawing.Point(247, 73);
            this.label1Password.Name = "label1Password";
            this.label1Password.Size = new System.Drawing.Size(53, 13);
            this.label1Password.TabIndex = 7;
            this.label1Password.Text = "Password";
            // 
            // textBox1UPP
            // 
            this.textBox1UPP.Location = new System.Drawing.Point(312, 96);
            this.textBox1UPP.MaxLength = 6;
            this.textBox1UPP.Name = "textBox1UPP";
            this.textBox1UPP.Size = new System.Drawing.Size(121, 20);
            this.textBox1UPP.TabIndex = 8;
            this.textBox1UPP.TextChanged += new System.EventHandler(this.textBox1UPP_TextChanged);
            // 
            // label1UPP
            // 
            this.label1UPP.AutoSize = true;
            this.label1UPP.Location = new System.Drawing.Point(271, 99);
            this.label1UPP.Name = "label1UPP";
            this.label1UPP.Size = new System.Drawing.Size(29, 13);
            this.label1UPP.TabIndex = 9;
            this.label1UPP.Text = "UPP";
            // 
            // textBox1HomeWorld
            // 
            this.textBox1HomeWorld.Location = new System.Drawing.Point(312, 122);
            this.textBox1HomeWorld.MaxLength = 30;
            this.textBox1HomeWorld.Name = "textBox1HomeWorld";
            this.textBox1HomeWorld.Size = new System.Drawing.Size(121, 20);
            this.textBox1HomeWorld.TabIndex = 10;
            this.textBox1HomeWorld.TextChanged += new System.EventHandler(this.textBox1HomeWorld_TextChanged);
            // 
            // label1HomeWorld
            // 
            this.label1HomeWorld.AutoSize = true;
            this.label1HomeWorld.Location = new System.Drawing.Point(240, 125);
            this.label1HomeWorld.Name = "label1HomeWorld";
            this.label1HomeWorld.Size = new System.Drawing.Size(60, 13);
            this.label1HomeWorld.TabIndex = 11;
            this.label1HomeWorld.Text = "Homeworld";
            // 
            // comboBox1
            // 
            this.comboBox1.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Append;
            this.comboBox1.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.comboBox1.Items.AddRange(new object[] {
            "Aslan",
            "Droyne",
            "Hiver",
            "K\'kree",
            "Vargr",
            "Imperial Man",
            "Solomani",
            "Vilani",
            "Zhodani",
            "Darrian",
            "Geonee",
            "Suerrat"});
            this.comboBox1.Location = new System.Drawing.Point(312, 148);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 12;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // label1Race
            // 
            this.label1Race.AutoSize = true;
            this.label1Race.Location = new System.Drawing.Point(267, 151);
            this.label1Race.Name = "label1Race";
            this.label1Race.Size = new System.Drawing.Size(33, 13);
            this.label1Race.TabIndex = 13;
            this.label1Race.Text = "Race";
            // 
            // textBox1AccessLevel
            // 
            this.textBox1AccessLevel.Location = new System.Drawing.Point(312, 175);
            this.textBox1AccessLevel.MaxLength = 2;
            this.textBox1AccessLevel.Name = "textBox1AccessLevel";
            this.textBox1AccessLevel.Size = new System.Drawing.Size(121, 20);
            this.textBox1AccessLevel.TabIndex = 14;
            this.textBox1AccessLevel.TextChanged += new System.EventHandler(this.textBox1AccessLevel_TextChanged);
            this.textBox1AccessLevel.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBox1AccessLevel_KeyDown);
            // 
            // label1AccessLevel
            // 
            this.label1AccessLevel.AutoSize = true;
            this.label1AccessLevel.Location = new System.Drawing.Point(199, 178);
            this.label1AccessLevel.Name = "label1AccessLevel";
            this.label1AccessLevel.Size = new System.Drawing.Size(101, 13);
            this.label1AccessLevel.TabIndex = 15;
            this.label1AccessLevel.Text = "Access Level (0-10)";
            // 
            // checkBox1HiddenTAS
            // 
            this.checkBox1HiddenTAS.AutoSize = true;
            this.checkBox1HiddenTAS.Location = new System.Drawing.Point(312, 215);
            this.checkBox1HiddenTAS.Name = "checkBox1HiddenTAS";
            this.checkBox1HiddenTAS.Size = new System.Drawing.Size(15, 14);
            this.checkBox1HiddenTAS.TabIndex = 16;
            this.checkBox1HiddenTAS.UseVisualStyleBackColor = true;
            this.checkBox1HiddenTAS.CheckedChanged += new System.EventHandler(this.checkBox1HiddenTAS_CheckedChanged);
            // 
            // label1HiddenTAS
            // 
            this.label1HiddenTAS.AutoSize = true;
            this.label1HiddenTAS.Location = new System.Drawing.Point(246, 215);
            this.label1HiddenTAS.Name = "label1HiddenTAS";
            this.label1HiddenTAS.Size = new System.Drawing.Size(54, 13);
            this.label1HiddenTAS.TabIndex = 17;
            this.label1HiddenTAS.Text = "Hide User";
            // 
            // button1Cancel
            // 
            this.button1Cancel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1Cancel.Location = new System.Drawing.Point(696, 124);
            this.button1Cancel.Name = "button1Cancel";
            this.button1Cancel.Size = new System.Drawing.Size(99, 23);
            this.button1Cancel.TabIndex = 18;
            this.button1Cancel.Text = "Cancel/Exit";
            this.button1Cancel.UseVisualStyleBackColor = true;
            this.button1Cancel.Click += new System.EventHandler(this.button1Cancel_Click);
            // 
            // button1Save
            // 
            this.button1Save.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1Save.Location = new System.Drawing.Point(696, 168);
            this.button1Save.Name = "button1Save";
            this.button1Save.Size = new System.Drawing.Size(99, 23);
            this.button1Save.TabIndex = 19;
            this.button1Save.Text = "Save/Exit";
            this.button1Save.UseVisualStyleBackColor = true;
            this.button1Save.Click += new System.EventHandler(this.button1Save_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.pictureBox1.Enabled = false;
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(720, 16);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(62, 50);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 20;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // label1HideInfo
            // 
            this.label1HideInfo.AutoSize = true;
            this.label1HideInfo.Location = new System.Drawing.Point(333, 215);
            this.label1HideInfo.Name = "label1HideInfo";
            this.label1HideInfo.Size = new System.Drawing.Size(139, 13);
            this.label1HideInfo.TabIndex = 21;
            this.label1HideInfo.Text = "(Check to dissable account)";
            // 
            // button1AddUser
            // 
            this.button1AddUser.BackColor = System.Drawing.Color.Black;
            this.button1AddUser.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1AddUser.ForeColor = System.Drawing.Color.Lime;
            this.button1AddUser.Location = new System.Drawing.Point(16, 217);
            this.button1AddUser.Name = "button1AddUser";
            this.button1AddUser.Size = new System.Drawing.Size(68, 34);
            this.button1AddUser.TabIndex = 22;
            this.button1AddUser.Text = "Add New User";
            this.button1AddUser.UseVisualStyleBackColor = false;
            this.button1AddUser.Click += new System.EventHandler(this.button1AddUser_Click);
            // 
            // textBox1ALNAVLIB
            // 
            this.textBox1ALNAVLIB.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALNAVLIB.ForeColor = System.Drawing.SystemColors.WindowText;
            this.textBox1ALNAVLIB.Location = new System.Drawing.Point(663, 23);
            this.textBox1ALNAVLIB.Name = "textBox1ALNAVLIB";
            this.textBox1ALNAVLIB.ReadOnly = true;
            this.textBox1ALNAVLIB.ShortcutsEnabled = false;
            this.textBox1ALNAVLIB.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALNAVLIB.TabIndex = 23;
            this.textBox1ALNAVLIB.TabStop = false;
            // 
            // label1ALNAVLIB
            // 
            this.label1ALNAVLIB.AutoSize = true;
            this.label1ALNAVLIB.Location = new System.Drawing.Point(565, 26);
            this.label1ALNAVLIB.Name = "label1ALNAVLIB";
            this.label1ALNAVLIB.Size = new System.Drawing.Size(92, 13);
            this.label1ALNAVLIB.TabIndex = 24;
            this.label1ALNAVLIB.Text = "Navigation Library";
            // 
            // textBox1ALNAVFLEET
            // 
            this.textBox1ALNAVFLEET.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALNAVFLEET.Location = new System.Drawing.Point(663, 49);
            this.textBox1ALNAVFLEET.Name = "textBox1ALNAVFLEET";
            this.textBox1ALNAVFLEET.ReadOnly = true;
            this.textBox1ALNAVFLEET.ShortcutsEnabled = false;
            this.textBox1ALNAVFLEET.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALNAVFLEET.TabIndex = 25;
            this.textBox1ALNAVFLEET.TabStop = false;
            // 
            // label1ALNAVFLEET
            // 
            this.label1ALNAVFLEET.AutoSize = true;
            this.label1ALNAVFLEET.Location = new System.Drawing.Point(538, 52);
            this.label1ALNAVFLEET.Name = "label1ALNAVFLEET";
            this.label1ALNAVFLEET.Size = new System.Drawing.Size(119, 13);
            this.label1ALNAVFLEET.TabIndex = 26;
            this.label1ALNAVFLEET.Text = "Sector Fleet Information";
            // 
            // textBox1ALNEWS
            // 
            this.textBox1ALNEWS.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALNEWS.Location = new System.Drawing.Point(663, 75);
            this.textBox1ALNEWS.Name = "textBox1ALNEWS";
            this.textBox1ALNEWS.ReadOnly = true;
            this.textBox1ALNEWS.ShortcutsEnabled = false;
            this.textBox1ALNEWS.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALNEWS.TabIndex = 27;
            this.textBox1ALNEWS.TabStop = false;
            // 
            // label1ALNEWS
            // 
            this.label1ALNEWS.AutoSize = true;
            this.label1ALNEWS.Location = new System.Drawing.Point(560, 78);
            this.label1ALNEWS.Name = "label1ALNEWS";
            this.label1ALNEWS.Size = new System.Drawing.Size(97, 13);
            this.label1ALNEWS.TabIndex = 28;
            this.label1ALNEWS.Text = "TAS News Service";
            // 
            // textBox1ALLIBDATA
            // 
            this.textBox1ALLIBDATA.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALLIBDATA.Location = new System.Drawing.Point(663, 101);
            this.textBox1ALLIBDATA.Name = "textBox1ALLIBDATA";
            this.textBox1ALLIBDATA.ReadOnly = true;
            this.textBox1ALLIBDATA.ShortcutsEnabled = false;
            this.textBox1ALLIBDATA.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALLIBDATA.TabIndex = 29;
            this.textBox1ALLIBDATA.TabStop = false;
            // 
            // label1ALLIBDATA
            // 
            this.label1ALLIBDATA.AutoSize = true;
            this.label1ALLIBDATA.Location = new System.Drawing.Point(593, 104);
            this.label1ALLIBDATA.Name = "label1ALLIBDATA";
            this.label1ALLIBDATA.Size = new System.Drawing.Size(64, 13);
            this.label1ALLIBDATA.TabIndex = 30;
            this.label1ALLIBDATA.Text = "Library Data";
            // 
            // textBox1ALACCNT
            // 
            this.textBox1ALACCNT.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALACCNT.Location = new System.Drawing.Point(663, 127);
            this.textBox1ALACCNT.Name = "textBox1ALACCNT";
            this.textBox1ALACCNT.ReadOnly = true;
            this.textBox1ALACCNT.ShortcutsEnabled = false;
            this.textBox1ALACCNT.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALACCNT.TabIndex = 31;
            this.textBox1ALACCNT.TabStop = false;
            // 
            // label1ALACCNT
            // 
            this.label1ALACCNT.AutoSize = true;
            this.label1ALACCNT.Location = new System.Drawing.Point(566, 130);
            this.label1ALACCNT.Name = "label1ALACCNT";
            this.label1ALACCNT.Size = new System.Drawing.Size(91, 13);
            this.label1ALACCNT.TabIndex = 32;
            this.label1ALACCNT.Text = "Account Services";
            // 
            // textBox1ALCLASS
            // 
            this.textBox1ALCLASS.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALCLASS.Location = new System.Drawing.Point(663, 153);
            this.textBox1ALCLASS.Name = "textBox1ALCLASS";
            this.textBox1ALCLASS.ReadOnly = true;
            this.textBox1ALCLASS.ShortcutsEnabled = false;
            this.textBox1ALCLASS.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALCLASS.TabIndex = 33;
            this.textBox1ALCLASS.TabStop = false;
            // 
            // label1ALCLASS
            // 
            this.label1ALCLASS.AutoSize = true;
            this.label1ALCLASS.Location = new System.Drawing.Point(601, 156);
            this.label1ALCLASS.Name = "label1ALCLASS";
            this.label1ALCLASS.Size = new System.Drawing.Size(56, 13);
            this.label1ALCLASS.TabIndex = 34;
            this.label1ALCLASS.Text = "Classifieds";
            // 
            // textBox1ALMERC
            // 
            this.textBox1ALMERC.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALMERC.Location = new System.Drawing.Point(663, 179);
            this.textBox1ALMERC.Name = "textBox1ALMERC";
            this.textBox1ALMERC.ReadOnly = true;
            this.textBox1ALMERC.ShortcutsEnabled = false;
            this.textBox1ALMERC.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALMERC.TabIndex = 35;
            this.textBox1ALMERC.TabStop = false;
            // 
            // label1ALMERC
            // 
            this.label1ALMERC.AutoSize = true;
            this.label1ALMERC.Location = new System.Drawing.Point(562, 184);
            this.label1ALMERC.Name = "label1ALMERC";
            this.label1ALMERC.Size = new System.Drawing.Size(95, 13);
            this.label1ALMERC.TabIndex = 36;
            this.label1ALMERC.Text = "Mercenary Tickets";
            // 
            // textBox1ALXBT
            // 
            this.textBox1ALXBT.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALXBT.Location = new System.Drawing.Point(663, 205);
            this.textBox1ALXBT.Name = "textBox1ALXBT";
            this.textBox1ALXBT.ReadOnly = true;
            this.textBox1ALXBT.ShortcutsEnabled = false;
            this.textBox1ALXBT.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALXBT.TabIndex = 37;
            this.textBox1ALXBT.TabStop = false;
            // 
            // label1ALXBT
            // 
            this.label1ALXBT.AutoSize = true;
            this.label1ALXBT.Location = new System.Drawing.Point(547, 207);
            this.label1ALXBT.Name = "label1ALXBT";
            this.label1ALXBT.Size = new System.Drawing.Size(110, 13);
            this.label1ALXBT.TabIndex = 38;
            this.label1ALXBT.Text = "Xboat Communication";
            // 
            // textBox1ALSPECCOLL
            // 
            this.textBox1ALSPECCOLL.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1ALSPECCOLL.Location = new System.Drawing.Point(663, 231);
            this.textBox1ALSPECCOLL.Name = "textBox1ALSPECCOLL";
            this.textBox1ALSPECCOLL.ReadOnly = true;
            this.textBox1ALSPECCOLL.ShortcutsEnabled = false;
            this.textBox1ALSPECCOLL.Size = new System.Drawing.Size(27, 20);
            this.textBox1ALSPECCOLL.TabIndex = 39;
            this.textBox1ALSPECCOLL.TabStop = false;
            // 
            // label1ALSPECCOLL
            // 
            this.label1ALSPECCOLL.AutoSize = true;
            this.label1ALSPECCOLL.Location = new System.Drawing.Point(561, 234);
            this.label1ALSPECCOLL.Name = "label1ALSPECCOLL";
            this.label1ALSPECCOLL.Size = new System.Drawing.Size(96, 13);
            this.label1ALSPECCOLL.TabIndex = 40;
            this.label1ALSPECCOLL.Text = "Special Collections";
            // 
            // label1ALInfo
            // 
            this.label1ALInfo.AutoSize = true;
            this.label1ALInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1ALInfo.Location = new System.Drawing.Point(466, 4);
            this.label1ALInfo.Name = "label1ALInfo";
            this.label1ALInfo.Size = new System.Drawing.Size(230, 16);
            this.label1ALInfo.TabIndex = 41;
            this.label1ALInfo.Text = "Service Minimum Access Levels";
            // 
            // button1DELUser
            // 
            this.button1DELUser.BackColor = System.Drawing.Color.Black;
            this.button1DELUser.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1DELUser.ForeColor = System.Drawing.Color.Red;
            this.button1DELUser.Location = new System.Drawing.Point(90, 217);
            this.button1DELUser.Name = "button1DELUser";
            this.button1DELUser.Size = new System.Drawing.Size(75, 34);
            this.button1DELUser.TabIndex = 42;
            this.button1DELUser.Text = "Delete User";
            this.button1DELUser.UseVisualStyleBackColor = false;
            this.button1DELUser.Click += new System.EventHandler(this.button1DELUser_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(223, 240);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 13);
            this.label1.TabIndex = 43;
            this.label1.Text = "Total Members";
            // 
            // textBoxMemTotal
            // 
            this.textBoxMemTotal.BackColor = System.Drawing.SystemColors.Menu;
            this.textBoxMemTotal.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBoxMemTotal.Location = new System.Drawing.Point(312, 237);
            this.textBoxMemTotal.Name = "textBoxMemTotal";
            this.textBoxMemTotal.ReadOnly = true;
            this.textBoxMemTotal.Size = new System.Drawing.Size(51, 13);
            this.textBoxMemTotal.TabIndex = 44;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(814, 261);
            this.Controls.Add(this.textBoxMemTotal);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1DELUser);
            this.Controls.Add(this.label1ALInfo);
            this.Controls.Add(this.label1ALSPECCOLL);
            this.Controls.Add(this.textBox1ALSPECCOLL);
            this.Controls.Add(this.label1ALXBT);
            this.Controls.Add(this.textBox1ALXBT);
            this.Controls.Add(this.label1ALMERC);
            this.Controls.Add(this.textBox1ALMERC);
            this.Controls.Add(this.label1ALCLASS);
            this.Controls.Add(this.textBox1ALCLASS);
            this.Controls.Add(this.label1ALACCNT);
            this.Controls.Add(this.textBox1ALACCNT);
            this.Controls.Add(this.label1ALLIBDATA);
            this.Controls.Add(this.textBox1ALLIBDATA);
            this.Controls.Add(this.label1ALNEWS);
            this.Controls.Add(this.textBox1ALNEWS);
            this.Controls.Add(this.label1ALNAVFLEET);
            this.Controls.Add(this.textBox1ALNAVFLEET);
            this.Controls.Add(this.label1ALNAVLIB);
            this.Controls.Add(this.textBox1ALNAVLIB);
            this.Controls.Add(this.button1AddUser);
            this.Controls.Add(this.label1HideInfo);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.button1Save);
            this.Controls.Add(this.button1Cancel);
            this.Controls.Add(this.label1HiddenTAS);
            this.Controls.Add(this.checkBox1HiddenTAS);
            this.Controls.Add(this.label1AccessLevel);
            this.Controls.Add(this.textBox1AccessLevel);
            this.Controls.Add(this.label1Race);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.label1HomeWorld);
            this.Controls.Add(this.textBox1HomeWorld);
            this.Controls.Add(this.label1UPP);
            this.Controls.Add(this.textBox1UPP);
            this.Controls.Add(this.label1Password);
            this.Controls.Add(this.textBox1Password);
            this.Controls.Add(this.label1Name);
            this.Controls.Add(this.textBox1Name);
            this.Controls.Add(this.label1MemNum);
            this.Controls.Add(this.textBox1MemNum);
            this.Controls.Add(this.label1UserAccount);
            this.Controls.Add(this.listBox1Users);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "User Editor";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1Users;
        private System.Windows.Forms.Label label1UserAccount;
        private System.Windows.Forms.TextBox textBox1MemNum;
        private System.Windows.Forms.Label label1MemNum;
        private System.Windows.Forms.TextBox textBox1Name;
        private System.Windows.Forms.Label label1Name;
        private System.Windows.Forms.TextBox textBox1Password;
        private System.Windows.Forms.Label label1Password;
        private System.Windows.Forms.TextBox textBox1UPP;
        private System.Windows.Forms.Label label1UPP;
        private System.Windows.Forms.TextBox textBox1HomeWorld;
        private System.Windows.Forms.Label label1HomeWorld;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label1Race;
        private System.Windows.Forms.TextBox textBox1AccessLevel;
        private System.Windows.Forms.Label label1AccessLevel;
        private System.Windows.Forms.CheckBox checkBox1HiddenTAS;
        private System.Windows.Forms.Label label1HiddenTAS;
        private System.Windows.Forms.Button button1Cancel;
        private System.Windows.Forms.Button button1Save;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1HideInfo;
        private System.Windows.Forms.Button button1AddUser;
        private System.Windows.Forms.TextBox textBox1ALNAVLIB;
        private System.Windows.Forms.Label label1ALNAVLIB;
        private System.Windows.Forms.TextBox textBox1ALNAVFLEET;
        private System.Windows.Forms.Label label1ALNAVFLEET;
        private System.Windows.Forms.TextBox textBox1ALNEWS;
        private System.Windows.Forms.Label label1ALNEWS;
        private System.Windows.Forms.TextBox textBox1ALLIBDATA;
        private System.Windows.Forms.Label label1ALLIBDATA;
        private System.Windows.Forms.TextBox textBox1ALACCNT;
        private System.Windows.Forms.Label label1ALACCNT;
        private System.Windows.Forms.TextBox textBox1ALCLASS;
        private System.Windows.Forms.Label label1ALCLASS;
        private System.Windows.Forms.TextBox textBox1ALMERC;
        private System.Windows.Forms.Label label1ALMERC;
        private System.Windows.Forms.TextBox textBox1ALXBT;
        private System.Windows.Forms.Label label1ALXBT;
        private System.Windows.Forms.TextBox textBox1ALSPECCOLL;
        private System.Windows.Forms.Label label1ALSPECCOLL;
        private System.Windows.Forms.Label label1ALInfo;
        private System.Windows.Forms.Button button1DELUser;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxMemTotal;
    }
}

