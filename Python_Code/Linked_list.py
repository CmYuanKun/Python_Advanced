#coding:utf-8
'''
Author: your name
Date: 2021-09-17 23:37:29
LastEditTime: 2021-09-20 00:00:51
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Git_Practice_Code\hello_world.py
'''
class Node(object):
    """节点"""
    def __init__(self, elem):
        self.elem = elem
        self.next = None

class SingleLinkList(object):
    """单链表"""
    def __init__(self, node=None) : 
        self.__head = node

    def is_empty(self):
        """链表是否为空"""
        if self.__head:
            return False
    
    def length(self):
        """链表长度"""
        #cur游标，用来移动遍历节点
        cur = self.__head
        #count记录数量
        count = 0
        while cur is not None:
            count += 1
            cur = cur.next
        return count

    def travel(self):
        """遍历整个链表"""
        cur = self.__head
        while cur is not None:
            print(cur.elem, end=" ")
            cur = cur.next
        
    def add(self, item):
        """链表头部添加元素"""
        node = Node(item)
        node.next = self.__head
        self.__head = node

    def append(self, item):
        """链表尾部添加元素"""
        node = Node(item)
        if not self.__head:
            self.__head = node
        else:
            cur = self.__head
            while cur.next is not None:
                cur = cur.next
            cur.next = node

    def insert(self, pos, item):
        """指定位置添加元素"""
        if pos <= 0:
            self.add(item)
        elif pos > self.length() -1:
            self.append(item)
        else:
            pre = self.__head
            count = 0
            while count < (pos - 1):
                count += 1
                pre = pre.next
            # 当循环结束后，pre指向pos-1位置 
            node = Node(item)
            node.next = pre.next
            pre.next = node

    def remove(self, item):
        """删除节点"""
        if not self.search(item):
            return False
        else:
           cur = self.__head


    def search(self, item):
        """查找节点是否存在"""
        cur = self.__head
        while cur is not None:
            if cur.elem == item:
                return True
            else:
                cur = cur.next
        return False

if __name__ == "__main__":
    ll = SingleLinkList()
    print(ll.is_empty())
    print(ll.length())

    ll.append(1)
    print(ll.is_empty())
    print(ll.length())

    ll.append(2)
    ll.append(3)
    ll.append(4)
    ll.append(5)
    ll.append(6)
    ll.append(7)
    ll.append(8)

    ll.travel()

    ll.add(4)
    print(" ")
    ll.travel()
    print(" ")
    ll.insert(-1, 9)
    ll.travel()

    print(" ")
    ll.insert(2, 100)
    ll.travel()

    print(" ")
    ll.insert(26, 120)
    ll.travel()

    print(ll.search(8))
    print(ll.search(777))