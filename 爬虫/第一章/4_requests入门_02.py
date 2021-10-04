'''
Author: your name
Date: 2021-10-04 21:54:27
LastEditTime: 2021-10-04 21:58:17
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\爬虫\第一章\4_requests入门_02.py
'''
import requests

url = 'https://fanyi.baidu.com/sug'

s = input("请输入你要翻译的英文单词")

dat = {
    "kw" : s
}

resp = requests.post(url, data=dat)

print(resp.json())

