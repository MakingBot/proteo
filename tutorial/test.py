#!/usr/bin/python

from proteo.gui import *
from proteo.model import *



gui = Scheduler()

shell = Shell("pyshell")


sp = Spy("agent007");



sensor = SensorDistance("sensor");
sensor.distance = 5;

sp.connect(sensor);


test=5;


gui.start()


