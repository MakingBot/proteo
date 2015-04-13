#!/usr/bin/python

from proteo.gui import *
from proteo.model import *



gui = Scheduler()

shell = Shell("pyshell")

#gui2 = Scheduler()

sp = Spy("agent007"); #"agent007" 


# gui.test()

sensor = SensorDistance("sensor");
sensor.distance = 5;

#  #sp.spy(sensor);

sp.connect(sensor);

test=5;


gui.start()
