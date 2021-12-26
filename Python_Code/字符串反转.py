'''
Author: your name
Date: 2021-10-08 22:04:27
LastEditTime: 2021-10-08 23:06:43
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\01_hello.py\三元运算测试.py
'''
# 如何实现字符串的反转
name = "abcde"
name = name[::-1]
print(name)


# 列举布尔值为False的常见值
# 0 
# []
# ""
# tuple()
# dict()
# set()
# 常见的数据类型中所有表示的东西都可以称之为False

# 函数的布尔值为True
# 类的布尔值为True
# 类的对象布尔值为False
class mClass(type):
    def __bool__(self):
        return False

class myClass(metaclass=mClass):
    def __bool__(self):
        return True

print(bool(mClass))

print(bool(myClass))
print(bool(myClass()))

# is与==的区别

'''
is 判断的是内存地址
== 判断的是值
'''
list1 = [1,2,3]
list2 = [1,2,3]

print(list1 is list2) # False
print(list1 == list2) # True


# 1,2,3,4,5组成多少个互不相等且不重复的三位数
# list1 = []
# nums = {1,2,3,4,5}
# for i in range(100, 1000):
#     s = set(int(j) for j in str(i))
#     if not s-nums:
#         list1.append(s)
#         print(s)
# print(len(list1))


v = dict.fromkeys(["k1","k2"],[])
print(v)

v["k1"].append("nihao")
print(v)

v["k2"] = 888
print(v)

#一行代码实现删除列表中重复数据、

list1 = ["力能","你好","你好","打仗","张三"]

# 借助set集合，数据是不重复的
s = list(set(list1))
print(s)