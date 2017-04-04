# -*- coding: utf-8 -*-
from flask import Flask
from flask import render_template
from flask import request
import json

from modules.serial_connector import SerialConnector

app = Flask(__name__)

sc = SerialConnector()

@app.route('/', methods=['GET'])
def index():
    devices = sc.get_devices()
    print(devices)
    return render_template('index.html', devices=devices)

@app.route('/execute', methods=['POST'])
def execute():
    print(request)
    return json.dumps({'status':'OK'})

if __name__ == '__main__':
    app.debug = True
    app.run(host='0.0.0.0')
