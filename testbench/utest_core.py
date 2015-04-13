#!/usr/bin/python

import unittest
from proteo.model import *

class UtestCore(unittest.TestCase):

	def test_object_name(self):
		""" Test core object name property through simple model class 
		"""
		sensor = SensorDistance('proteo sensor')
		self.assertEqual(sensor.objName, 'proteo sensor')
		sensor.objName = 'robert'
		self.assertEqual(sensor.objName, 'robert')
		

if __name__ == '__main__':
	unittest.main()


