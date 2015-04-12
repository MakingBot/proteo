#!/usr/bin/python

from proteo.gui import *
from proteo.model import *



gui = Scheduler()

#gui2 = Scheduler()

sp = Spy("agent007"); #"agent007" 


# gui.test()

sensor = SensorDistance("sensor");
# # sensor.distance = 5;

#  #sp.spy(sensor);

sp.connect(sensor);




gui.start()
