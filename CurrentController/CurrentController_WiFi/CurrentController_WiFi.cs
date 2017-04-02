using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Net;
using System.IO;
using System.Windows.Forms;

namespace CurrentController_WiFi
{
    class CurrentController_WiFi
    {
        private string Log;
        private string URL;

        private string WiFiCommunicate(string str)
        {
            Encoding enc = Encoding.GetEncoding("UTF-8");
            string url = "http://" + URL + "/" + str;
            WebRequest req = WebRequest.Create(url);
            WebResponse res = req.GetResponse();
            Stream st = res.GetResponseStream();
            StreamReader sr = new StreamReader(st, enc);
            string html = sr.ReadToEnd();
            sr.Close();
            st.Close();
            Thread.Sleep(100);
            return html;
        }

        private void SetRegister(byte addr, byte val)
        {
            string cmd = "SET," + addr.ToString("X2") + "," + val.ToString("X2");
            Log += cmd + "..." + WiFiCommunicate(cmd + "\r\n").Replace("\r", "").Replace("\n", "") + "\r\n";
            return;
        }
        private int GetRegister(byte addr)
        {
            string cmd = "GET," + addr.ToString("X2");
            string ret;
            ret = WiFiCommunicate(cmd + "\r\n").Replace("\r", "").Replace("\n", "");
            Log += cmd + "..." + ret + "\r\n";
            return Convert.ToInt32(ret, 16);
        }

        public void Open(string url)
        {
            URL = url;
            Log += "SerialOpen" + "...";
            try
            {
                GetRegister(0x00);
                Log += "AOK" + "\r\n";
            }
            catch (Exception)
            {
                Log += "NOK" + "\r\n";
                throw new Exception();
            }
        }
        public void Close()
        {
            Log += "SerialClose" + "...";
            try
            {
                SetRegister(0x00, 0x01);
                Log += "AOK" + "\r\n";
            }
            catch (Exception)
            {
                Log += "NOK" + "\r\n";
                throw new Exception();
            }
        }
        public void StartOutputCurrent(int current, bool direction, bool sinmode)
        {
            SetRegister(0x02, (byte)(current >> 8));
            SetRegister(0x01, (byte)(current & 0xff));
            SetRegister(0x00, (byte)((Convert.ToInt16(direction) << 2) | (Convert.ToInt16(sinmode) << 3) | 0x03));
        }
        public void StopOutputCurrent()
        {
            SetRegister(0x00, (byte)(GetRegister(0x00) & 0xfd));
        }
        public String GetLog()
        {
            String temp = Log;
            Log = "";
            return temp;
        }
    }
}