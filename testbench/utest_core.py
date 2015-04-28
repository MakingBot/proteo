#!/usr/bin/python

import unittest
from proteo.core import *

class UtestCore(unittest.TestCase):

	def test_object_name(self):
		""" Test core object name property
		"""
		container = Container('proteo container')
		self.assertEqual(container.objName, 'proteo container')
		container.objName = 'charlie'
		self.assertEqual(container.objName, 'charlie')

	def test_object_parent_child(self):
		""" Test to append a child and get its parent
		"""
		parent = Container('parent')
		child  = Container('child')
		child2 = Container('child2')
		
		if child.hasObjParent():
			self.fail("Child has no parent yet")
			
		parent.append(child)
		if not child.hasObjParent():
			self.fail("Child should have a parent")
		self.assertEqual( parent.nbObjChilds(), 1 )

		parent += child2
		self.assertEqual( parent.nbObjChilds(), 2 )
		self.assertEqual( child2.objParent.objName, 'parent' )

		parent.remove(child)
		if child.hasObjParent():
			self.fail("Child should have no parent anymore")

		parent -= child2
		if child.hasObjParent():
			self.fail("Child2 should have no parent anymore")

	def test_object_connection(self):
		""" Test object connection
		"""
		obj1 = Container('obj1')
		obj2 = Container('obj2')

		obj1 *= obj2

		if obj1.nbObjConnections() != 1:
			self.fail("Obj1 should be connected")

		if obj2.nbObjConnections() != 1:
			self.fail("Obj2 should be connected")

		obj2 /= obj1
	
		if obj1.nbObjConnections() == 1:
			self.fail("Obj1 should not be connected")

		if obj2.nbObjConnections() == 1:
			self.fail("Obj2 should not be connected")


	# def test_object_idNumber(self):

	# def test_object_idChain(self):

if __name__ == '__main__':
	unittest.main()


