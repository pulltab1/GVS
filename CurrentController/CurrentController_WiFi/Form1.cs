using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CurrentController_WiFi
{
    public partial class Form1 : Form
    {
        private bool isConnect;
        private bool isOutput;
        private CurrentController_WiFi CurController = new CurrentController_WiFi();

        public Form1()
        {
            InitializeComponent();
        }
        private void OutputCurrent()
        {
            int curval;
            bool direction;

            curval = Math.Abs(VolumeBar.Value);
            direction = VolumeBar.Value < 0;

            CurController.StartOutputCurrent(curval * 200, direction, sinmode.Checked);
            Log.AppendText(CurController.GetLog());
        }

        private void pushConnectButton(object sender, EventArgs e)
        {
            try
            {
                if (!isConnect)
                {
                    CurController.Open(Address.Text);
                    ConnButton.Text = "切断";
                    isConnect = true;
                }
                else
                {
                    CurController.Close();
                    ConnButton.Text = "接続";
                    OutButton.Text = "出力";
                    isConnect = false;
                    isOutput = false;
                }
            }
            catch (Exception){}
            Log.AppendText(CurController.GetLog());
        }

        private void pushOutputButton(object sender, EventArgs e)
        {
            try
            {
                if (isConnect)
                {
                    if (!isOutput)
                    {
                        OutputCurrent();
                        OutButton.Text = "停止";
                        isOutput = true;
                    }
                    else
                    {
                        CurController.StopOutputCurrent();
                        OutButton.Text = "出力";
                        isOutput = false;
                    }
                }
            }
            catch (Exception){ }
            Log.AppendText(CurController.GetLog());
        }

        private void CurrentValueChanged(object sender, EventArgs e)
        {
            CurrentValue.Text = VolumeBar.Value.ToString();
            if (isOutput)
            {
                OutputCurrent();
            }
        }

        private void UpdataSinMode(object sender, EventArgs e)
        {
            if (isOutput)
            {
                OutputCurrent();
            }
        }

        private void SerialClose(object sender, FormClosedEventArgs e)
        {
            try
            {
                CurController.Close();
                Log.AppendText(CurController.GetLog());
            }
            catch (Exception){}
        }
    }
}
