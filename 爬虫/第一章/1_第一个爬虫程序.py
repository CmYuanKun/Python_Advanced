'''
Author: your name
Date: 2021-10-04 12:40:56
LastEditTime: 2021-10-04 21:08:33
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\爬虫\第一章\1_第一个爬虫程序.py
'''
# 爬虫: 通过编写程序来获取到互联网上的资源
# 需求：用程序模拟浏览器，输入一个网址，从该网址中获取到资源或者内容

from urllib.request import urlopen

url = 'http://www.baidu.com'
resp = urlopen(url)


with open("./爬虫/mybaidu.html", 'w', encoding='utf-8') as f:
    f.write(resp.read().decode("utf-8")) 

