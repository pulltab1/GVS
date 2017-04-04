# -*- coding: utf-8 -*-
import serial
from serial.tools import list_ports

class SerialConnector(object):
    def __init__(self):
        self.ser = serial.Serial()
        self.ser.baudrate = 9600
        self.ser.timeout = 0.1

        self.ports = list_ports.comports()
        self.devices = []

        for info in self.ports:
            self.devices.append(info.device)

    def get_devices(self):
        return self.devices
