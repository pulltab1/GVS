using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Threading;

namespace CurrentController
{
    class CurrentController
    {
        private SerialPort Serial;
        private string Log;

        private void SetRegister(byte addr, byte val)
        {
            string cmd = "SET," + addr.ToString("X2") + "," + val.ToString("X2");
            Serial.Write(cmd + "\r\n");
            Log += cmd + "..." + Serial.ReadLine().Replace("\r", "").Replace("\n", "") + "\r\n";
            Thread.Sleep(50);
        }
        private int GetRegister(byte addr)
        {
            string cmd = "GET," + addr.ToString("X2");
            string ret;
            Serial.Write(cmd + "\r\n");
            ret = Serial.ReadLine().Replace("\r", "").Replace("\n", "");

            Log += cmd + "..." + ret + "\r\n";
            Thread.Sleep(50);

            return Convert.ToInt32(ret, 16);
        }

        public void Open(string PortName)
        {
            Log += "SerialOpen" + "...";
            try
            {
                Serial = new SerialPort(PortName, 9600, Parity.None, 8);
                Serial.Open();
                Log += "AOK\r\n";
            }
            catch (Exception)
            {
                Log += "NOK\r\n";
                throw new Exception();
            }
        }
        public void Close()
        {
            Log += "SerialClose" + "...";
            try
            {
                SetRegister(0x00, 0x01);
                Serial.Close();
                Log += "AOK\r\n";
            }
            catch (Exception)
            {
                Log += "NOK\r\n";
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
            String temp;
            temp = Log;
            Log = "";
            return temp;
        }
    }
}