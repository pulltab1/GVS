# -*- coding: utf-8 -*-
import serial
from serial.tools import list_ports
import time

class SerialConnector(object):
    def __init__(self):
        self.ser = serial.Serial()

        self.ports = list_ports.comports()
        self.devices = []

        for info in self.ports:
            self.devices.append(info.device)

    def open(self, port_name):
        print("serial open...")
        try:
            self.ser = serial.Serial(port_name, 9600)
            print("AOK")
            return True
        except Exception:
            print("NOK")
            return False

    def close(self):
        print("serial close...")
        try:
            self.set_register("0x00", "0x01")
            self.ser.close()
            print("AOK")
            return True
        except Exception:
            print("NOK")
            return False

    def start_output_current(self, current, direction, sinmode):
        self.set_register("0x02", str(current >> 8))
        self.set_register("0x01", str(current & 0xff))
        self.set_register("0x00", str((direction << 2) | sinmode << 3 | 0x03))

    def stop_output_current(self):
        self.set_register("0x00", self.get_register("0x00") & 0xfd)

    def set_register(self, addr, val):
        cmd = 'SET,{0:02x},{1:02x}'.format(addr, val).upper()
        self.ser.write(cmd+'\r\n')

        ret = self.ser.readline()
        print(ret)
        time.sleep(50)

    def get_register(self, addr):
        cmd = 'GET,{0:02x}'.format(addr).upper()
        self.ser.write(cmd+'\r\n')

        ret = self.ser.readline()
        print(ret)
        time.sleep(50)

        return int(ret, 16)

    def get_devices(self):
        return self.devices
