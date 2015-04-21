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

	#     parent.remove()
	#     parent += child
	#     parent -= child
#.Create

#.Create
	# def test_object_childNumbers(self):

	# def test_object_connection(self):


	# def test_object_idNumber(self):

	# def test_object_idChain(self):

if __name__ == '__main__':
	unittest.main()


