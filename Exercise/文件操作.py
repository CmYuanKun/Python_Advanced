'''
Author: your name
Date: 2021-09-20 17:33:46
LastEditTime: 2021-09-25 19:08:09
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\Exercise\文件操作.py
'''
'''
mmap模块来实现对大文件的处理,
mmap是一种虚拟内存映射文件的方法,即将一个文件或者其它对象映射到进程的地址空间,
实现文件磁盘地址和进程虚拟地址空间中一段虚拟地址的一一对映关系。
'''
# import os,mmap
# m = mmap.mmap(os.open(r"D:\Xue_Xi\Git_Practice_Code\Python_Advanced\Exercise\file_mmap.txt", os.O_RDWR), 0)
# print(m.read(10))
# print(m.readline())
# print(m.readline())
# print(m.size())
# print(m.tell())
# print(m.read(10))
# print(m.tell())
# print(m[101:108])
# print(m[1:8])
# print(m.find(b"SET", 0))
# print(m.read_byte())
# print(m.tell())
# print(m.write_byte("zhoujy"))
# m.close()


# 读取整个文件
# import mmap
# import contextlib

# f = open(r"D:\Xue_Xi\Git_Practice_Code\Python_Advanced\Exercise\file_mmap.txt", "r")
# with contextlib.closing(mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)) as m:
# #readline需要循环才能读取整个文件
#     while True:
#         line = m.readline().split()
#         print(line)
#         # 光标到最后位置(读完)，就退出 
#         if m.tell() == m.size():
#             break  


# 读步读取指定字节数文件
# import mmap
# import contextlib

# with open(r"D:\Xue_Xi\Git_Practice_Code\Python_Advanced\Exercise\file_mmap.txt", "r") as f:
#     with contextlib.closing(mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)) as m:
#         print("读取10个字节的字符串: ", m.read(10))
#         print('支持切片，对读取到的字符串进行切片操作:', m[2:10])
#         print('读取之前光标后的10个字符串', m.read(10))


# 从整个文件查找所有匹配的
# import mmap
# import contextlib

# word = 'ZHOUJY'
# print('查找:', word)

# f = open(r"D:\Xue_Xi\Git_Practice_Code\Python_Advanced\Exercise\file_mmap.txt", 'r')
# with contextlib.closing(mmap.mmap(f.fileno(), 0,access=mmap.ACCESS_READ)) as m:    #也可以通过find(str,pos)来处理
#     while True: 
#         line = m.readline().strip()
#         if line.find(word)>=0:
#             print ("结果：")
#             print (line)
#         elif m.tell()==m.size():
#             break
#         else:
#             pass

# 从整个文件里查找，找到就退出(确认到底是否存在)
# import mmap
# import contextlib

# word = 'ZHOUJY'
# print('查找:', word)

# f = open(r"D:\Xue_Xi\Git_Practice_Code\Python_Advanced\Exercise\file_mmap.txt", 'r')
# with contextlib.closing(mmap.mmap(f.fileno(), 0,access=mmap.ACCESS_READ)) as m:    #也可以通过find(str,pos)来处理
#         #不需要循环，只要找到一个就可以了
#     loc = m.find(word)
#     if loc >= 0:
#         print (loc)
#         print (m[loc:loc+len(word)])


# 通过正则查找，（找出40开头的数字）
# import mmap
# import re
# import contextlib

# pattern = re.compile(rb'(40\d*)')

# with open(r"D:\Xue_Xi\Git_Practice_Code\Python_Advanced\Exercise\file_mmap.txt", 'r') as f:
#     with contextlib.closing(mmap.mmap(f.fileno(), 0,access=mmap.ACCESS_READ)) as m:
#         print (pattern.findall(m))


# 普通文件被映射到虚拟地址空间后，程序可以向访问普通内存一样对文件进行访问，在有些情况下可以提高IO效率。
# 它占用物理内存空间少，可以解决内存空间不足的问题，适合处理超大文件。
# 不同于通常的字符串对象，它是可变的，可以通过切片的方式更改，也可以定位当前文件位置m.tell()或m.seek()定位到文件的指定位置，再进行m.write(str)固定长度的修改操作。
#!/usr/bin/python
# -*- encoding: utf-8 -*-

import mmap
import contextlib
import time
from optparse import OptionParser


def calc_time(func):
    def _deco(*args, **kwargs):
        begin_time = time.time()
        func(*args, **kwargs)
        cost_time = time.time() - begin_time
        print ('cost time: %s' % (cost_time))
    return _deco

@calc_time
def replace_keyword_all(filename,old_word,new_word):
    if len(old_word) == len(new_word):
        loc = 0
        print ("%s 替换成 %s " %(new_word,old_word))
        with open(filename,'r+') as f:
            with contextlib.closing(mmap.mmap(f.fileno(), 0,access=mmap.ACCESS_WRITE)) as m:
                while True:
                    loc = m.find(old_word,loc)
                    if loc >= 0:
                        m[loc:loc+len(old_word)] = new_word
                    elif loc == -1:
                        break
                    else:
                        pass
        f.close()
    else:
        print ("替换的词要和被替换的词长度一致!")
        exit()

@calc_time
def replace_keyword_once(filename,old_word,new_word):
    if len(old_word) == len(new_word):
        print ("%s 替换成 %s " %(new_word,old_word))
        with open(filename,'r+') as f:
            with contextlib.closing(mmap.mmap(f.fileno(), 0,access=mmap.ACCESS_WRITE)) as m:
                loc = m.find(old_word)
                if loc >= 0:
                    m[loc:loc+len(old_word)] = new_word
        f.close()
    else:
        print ("替换的词要和被替换的词长度一致!")
        exit()

if __name__ == "__main__":
    parser = OptionParser()
    parser.add_option("-f", "--filename", help="Filename for search", dest="filename")
    parser.add_option("-o", "--oldword", help="the ip to use", dest="old_word")
    parser.add_option("-n", "--newword", help="the ip to use", dest="new_word")

    (options, args) = parser.parse_args()

    if not options.filename:
        print ('params filename need to apply')
        exit()

    if not options.old_word:
        print ('params oldword need to apply')
        exit()

    if not options.new_word:
        print ('params newword need to apply')
        exit()
# 替换文本中第一次出现的内容（查到一个就处理退出，越靠前越快）
#    replace_keyword_once(options.filename,options.old_word,options.new_word)
# 替换文本中出现的内容(查找处理整个文本)
    replace_keyword_all(options.filename,options.old_word,options.new_word)

#https://www.cnblogs.com/zhoujinyi/p/6062907.html
#https://blog.csdn.net/chenwr2018/article/details/90639533