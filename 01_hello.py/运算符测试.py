'''
Author: your name
Date: 2021-10-08 21:43:41
LastEditTime: 2021-10-08 22:15:48
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\01_hello.py\运算符测试.py
'''
'''
考点：
    逻辑运算符
    and 并且
    or 或者
    not 非

    运算顺序：() => not => and => or
    
    a or b:
        如果a表示False,那么结果就是b
        如果a表示True,那么结果就是a

    a and b:
        如果a表示True,那么结果就是b
        如果a表示False,结果就为是a

'''
v1 = 1 or 3 # 结果为 1
v2 = 1 and 3 #结果为 3
v3 = 0 and 2 and 1 #结果先为0，再为0
v4 = 0 and 2 or 1 #结果先为0，再为1
v5 = 0 and 2 or 1 or 4 #结果先为0，再为1，再为1
v6 = 0 or False and 1 # 结果先为False, 再为False


# 三元运算符
# 比较a，b中比较大的值
# a if a > b else b


# 用一行代码实现数值交换
# 第一种方法
a = 10
b = 20
tmp = a 
a = b
b = tmp
# 第二种方法
a, b = b, a
# b,a为元组 

# 第三种方法
a=a^b
b=a^b
a=a^b
print(a,b)
