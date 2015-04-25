#!/usr/bin/python

import time 

from proteo.core  import *
from proteo.gui   import *


sched = Scheduler()



comp = Composer("composer")

archi = Container("main")


comp *= archi

comp.show()

sched.start()


