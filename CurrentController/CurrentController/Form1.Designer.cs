namespace CurrentController
{
    partial class Form1
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.CCGroupBox = new System.Windows.Forms.GroupBox();
            this.OutButton = new System.Windows.Forms.Button();
            this.sinmode = new System.Windows.Forms.CheckBox();
            this.CurrentValue = new System.Windows.Forms.TextBox();
            this.VolumeBar = new System.Windows.Forms.TrackBar();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.ConnButton = new System.Windows.Forms.Button();
            this.PortList = new System.Windows.Forms.ComboBox();
            this.LogGroup = new System.Windows.Forms.GroupBox();
            this.Log = new System.Windows.Forms.TextBox();
            this.CCGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.VolumeBar)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.LogGroup.SuspendLayout();
            this.SuspendLayout();
            // 
            // CCGroupBox
            // 
            this.CCGroupBox.Controls.Add(this.OutButton);
            this.CCGroupBox.Controls.Add(this.sinmode);
            this.CCGroupBox.Controls.Add(this.CurrentValue);
            this.CCGroupBox.Controls.Add(this.VolumeBar);
            this.CCGroupBox.Location = new System.Drawing.Point(12, 64);
            this.CCGroupBox.Name = "CCGroupBox";
            this.CCGroupBox.Size = new System.Drawing.Size(316, 81);
            this.CCGroupBox.TabIndex = 12;
            this.CCGroupBox.TabStop = false;
            this.CCGroupBox.Text = "設定";
            // 
            // OutButton
            // 
            this.OutButton.Location = new System.Drawing.Point(235, 52);
            this.OutButton.Name = "OutButton";
            this.OutButton.Size = new System.Drawing.Size(75, 23);
            this.OutButton.TabIndex = 15;
            this.OutButton.Text = "出力";
            this.OutButton.UseVisualStyleBackColor = true;
            this.OutButton.Click += new System.EventHandler(this.pushOutputButton);
            // 
            // sinmode
            // 
            this.sinmode.AutoSize = true;
            this.sinmode.Checked = true;
            this.sinmode.CheckState = System.Windows.Forms.CheckState.Checked;
            this.sinmode.Location = new System.Drawing.Point(6, 59);
            this.sinmode.Name = "sinmode";
            this.sinmode.Size = new System.Drawing.Size(67, 16);
            this.sinmode.TabIndex = 14;
            this.sinmode.Text = "SinMode";
            this.sinmode.UseVisualStyleBackColor = true;
            this.sinmode.Click += new System.EventHandler(this.UpdataSinMode);
            // 
            // CurrentValue
            // 
            this.CurrentValue.Location = new System.Drawing.Point(235, 18);
            this.CurrentValue.Name = "CurrentValue";
            this.CurrentValue.Size = new System.Drawing.Size(74, 19);
            this.CurrentValue.TabIndex = 12;
            // 
            // VolumeBar
            // 
            this.VolumeBar.Location = new System.Drawing.Point(6, 18);
            this.VolumeBar.Maximum = 20;
            this.VolumeBar.Minimum = -20;
            this.VolumeBar.Name = "VolumeBar";
            this.VolumeBar.Size = new System.Drawing.Size(224, 45);
            this.VolumeBar.TabIndex = 11;
            this.VolumeBar.ValueChanged += new System.EventHandler(this.CurrentValueChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.ConnButton);
            this.groupBox1.Controls.Add(this.PortList);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(316, 46);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "接続";
            // 
            // ConnButton
            // 
            this.ConnButton.Location = new System.Drawing.Point(229, 14);
            this.ConnButton.Name = "ConnButton";
            this.ConnButton.Size = new System.Drawing.Size(75, 23);
            this.ConnButton.TabIndex = 7;
            this.ConnButton.Text = "接続";
            this.ConnButton.UseVisualStyleBackColor = true;
            this.ConnButton.Click += new System.EventHandler(this.pushConnectButton);
            // 
            // PortList
            // 
            this.PortList.FormattingEnabled = true;
            this.PortList.Location = new System.Drawing.Point(6, 16);
            this.PortList.Name = "PortList";
            this.PortList.Size = new System.Drawing.Size(217, 20);
            this.PortList.TabIndex = 6;
            this.PortList.DropDown += new System.EventHandler(this.UpdatePorts);
            // 
            // LogGroup
            // 
            this.LogGroup.Controls.Add(this.Log);
            this.LogGroup.Location = new System.Drawing.Point(13, 152);
            this.LogGroup.Name = "LogGroup";
            this.LogGroup.Size = new System.Drawing.Size(315, 136);
            this.LogGroup.TabIndex = 14;
            this.LogGroup.TabStop = false;
            this.LogGroup.Text = "ログ";
            // 
            // Log
            // 
            this.Log.Location = new System.Drawing.Point(7, 19);
            this.Log.Multiline = true;
            this.Log.Name = "Log";
            this.Log.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.Log.Size = new System.Drawing.Size(302, 111);
            this.Log.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(340, 300);
            this.Controls.Add(this.LogGroup);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.CCGroupBox);
            this.Name = "Form1";
            this.Text = "CurrentController";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.SerialClose);
            this.CCGroupBox.ResumeLayout(false);
            this.CCGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.VolumeBar)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.LogGroup.ResumeLayout(false);
            this.LogGroup.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.GroupBox CCGroupBox;
        private System.Windows.Forms.Button OutButton;
        private System.Windows.Forms.CheckBox sinmode;
        private System.Windows.Forms.TextBox CurrentValue;
        private System.Windows.Forms.TrackBar VolumeBar;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button ConnButton;
        private System.Windows.Forms.ComboBox PortList;
        private System.Windows.Forms.GroupBox LogGroup;
        private System.Windows.Forms.TextBox Log;
    }
}

