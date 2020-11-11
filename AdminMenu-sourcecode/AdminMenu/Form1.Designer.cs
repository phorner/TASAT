namespace AdminMenu
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
            this.button1MemberEdit = new System.Windows.Forms.Button();
            this.button2ConfigEdit = new System.Windows.Forms.Button();
            this.button1Exit = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.TASATfullscreen = new System.Windows.Forms.Button();
            this.TASATwindowscreen = new System.Windows.Forms.Button();
            this.button3FleetEditor = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1MemberEdit
            // 
            this.button1MemberEdit.BackColor = System.Drawing.Color.White;
            this.button1MemberEdit.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1MemberEdit.Location = new System.Drawing.Point(158, 127);
            this.button1MemberEdit.Name = "button1MemberEdit";
            this.button1MemberEdit.Size = new System.Drawing.Size(114, 23);
            this.button1MemberEdit.TabIndex = 0;
            this.button1MemberEdit.Text = "Member Editor";
            this.button1MemberEdit.UseVisualStyleBackColor = false;
            this.button1MemberEdit.Click += new System.EventHandler(this.button1MemberEdit_Click);
            // 
            // button2ConfigEdit
            // 
            this.button2ConfigEdit.BackColor = System.Drawing.Color.White;
            this.button2ConfigEdit.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2ConfigEdit.Location = new System.Drawing.Point(12, 127);
            this.button2ConfigEdit.Name = "button2ConfigEdit";
            this.button2ConfigEdit.Size = new System.Drawing.Size(107, 23);
            this.button2ConfigEdit.TabIndex = 1;
            this.button2ConfigEdit.Text = "Config Editor";
            this.button2ConfigEdit.UseVisualStyleBackColor = false;
            this.button2ConfigEdit.Click += new System.EventHandler(this.button2ConfigEdit_Click);
            // 
            // button1Exit
            // 
            this.button1Exit.BackColor = System.Drawing.Color.White;
            this.button1Exit.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1Exit.ForeColor = System.Drawing.Color.Red;
            this.button1Exit.Location = new System.Drawing.Point(81, 283);
            this.button1Exit.Name = "button1Exit";
            this.button1Exit.Size = new System.Drawing.Size(114, 23);
            this.button1Exit.TabIndex = 2;
            this.button1Exit.Text = "Exit";
            this.button1Exit.UseVisualStyleBackColor = false;
            this.button1Exit.Click += new System.EventHandler(this.button1Exit_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Firebrick;
            this.label1.Location = new System.Drawing.Point(77, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(136, 24);
            this.label1.TabIndex = 3;
            this.label1.Text = "TASAT Menu";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(81, 225);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(114, 23);
            this.button1.TabIndex = 4;
            this.button1.Text = "Error Log";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // TASATfullscreen
            // 
            this.TASATfullscreen.BackColor = System.Drawing.Color.White;
            this.TASATfullscreen.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TASATfullscreen.Location = new System.Drawing.Point(43, 48);
            this.TASATfullscreen.Name = "TASATfullscreen";
            this.TASATfullscreen.Size = new System.Drawing.Size(189, 28);
            this.TASATfullscreen.TabIndex = 5;
            this.TASATfullscreen.Text = "TASAT Full Screen";
            this.TASATfullscreen.UseVisualStyleBackColor = false;
            this.TASATfullscreen.Click += new System.EventHandler(this.TASATfullscreen_Click);
            // 
            // TASATwindowscreen
            // 
            this.TASATwindowscreen.BackColor = System.Drawing.Color.White;
            this.TASATwindowscreen.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TASATwindowscreen.Location = new System.Drawing.Point(43, 83);
            this.TASATwindowscreen.Name = "TASATwindowscreen";
            this.TASATwindowscreen.Size = new System.Drawing.Size(189, 28);
            this.TASATwindowscreen.TabIndex = 6;
            this.TASATwindowscreen.Text = "TASAT Window Mode";
            this.TASATwindowscreen.UseVisualStyleBackColor = false;
            this.TASATwindowscreen.Click += new System.EventHandler(this.TASATwindowscreen_Click);
            // 
            // button3FleetEditor
            // 
            this.button3FleetEditor.BackColor = System.Drawing.Color.White;
            this.button3FleetEditor.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3FleetEditor.Location = new System.Drawing.Point(90, 173);
            this.button3FleetEditor.Name = "button3FleetEditor";
            this.button3FleetEditor.Size = new System.Drawing.Size(95, 23);
            this.button3FleetEditor.TabIndex = 7;
            this.button3FleetEditor.Text = "Fleet Editor";
            this.button3FleetEditor.UseVisualStyleBackColor = false;
            this.button3FleetEditor.Click += new System.EventHandler(this.button3FleetEditor_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Yellow;
            this.ClientSize = new System.Drawing.Size(284, 318);
            this.Controls.Add(this.button3FleetEditor);
            this.Controls.Add(this.TASATwindowscreen);
            this.Controls.Add(this.TASATfullscreen);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1Exit);
            this.Controls.Add(this.button2ConfigEdit);
            this.Controls.Add(this.button1MemberEdit);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "TASAT Launch Menu";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1MemberEdit;
        private System.Windows.Forms.Button button2ConfigEdit;
        private System.Windows.Forms.Button button1Exit;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button TASATfullscreen;
        private System.Windows.Forms.Button TASATwindowscreen;
        private System.Windows.Forms.Button button3FleetEditor;
    }
}

