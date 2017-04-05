# -*- coding: utf-8 -*-
from flask import Flask
from flask import render_template
from flask import request
import json

from modules.serial_connector import SerialConnector

app = Flask(__name__)

sc = SerialConnector()

is_connected = False

@app.route('/', methods=['GET'])
def index():
    devices = sc.get_devices()
    return render_template('index.html',
                           devices=devices,
                           is_connected=is_connected)

@app.route('/open', methods=['POST'])
def open():
    req = request.get_json().split('=')
    dev = req[1]
    if not sc.open(dev):
        return json.dumps({'status':'400'})

    global is_connected
    is_connected = True
    return json.dumps({'status':'200'})

@app.route('/close', methods=['POST'])
def close():
    if not sc.close():
        return json.dumps({'status':'400'})

    global is_connected
    is_connected = False
    return json.dumps({'status':'200'})

@app.route('/execute', methods=['POST'])
def execute():
    req = request.get_json().split('&')

    return json.dumps({'status':'200'})

if __name__ == '__main__':
    app.debug = True
    app.run(host='0.0.0.0')
