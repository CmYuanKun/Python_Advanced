'''
Author: your name
Date: 2021-09-21 08:54:43
LastEditTime: 2021-09-21 19:15:34
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\01_hello.py\1_yeild.py
'''
# def foo():
#     print("starting ....")
#     while True:
#         res = yield 4
#         print("res:", res)

# g = foo()
# print("=====")
# print(next(g))
# print("*" * 20)
# print(next(g))      
# print(next(g))  

# print(type(range(10)))

def foo(num):
    print("strating...")
    while num<10:
        num = num +1
        print(",,,")
        yield num
for n in foo(0):
    print(n)