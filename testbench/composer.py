#!/usr/bin/python

import time 

from proteo.core  import *
from proteo.gui   import *


sched = Scheduler()



comp = Composer("composer")

spy1 = Spy("agent");
#spy1.show()
spy1 *= comp

#comp.visible = True;
comp.show()

sched.start()


