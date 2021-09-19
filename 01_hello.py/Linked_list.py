#coding:utf-8
'''
Author: your name
Date: 2021-09-17 23:37:29
LastEditTime: 2021-09-19 11:03:12
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Git_Practice_Code\hello_world.py
'''
class Node(object):
    """节点"""
    def __init__(self, elem):
        self.elem = elem
        self.next = None

class singleLinkList(object):
    """单链表"""
    def __init__(self) :
        self.Node = Node()
         