'''
Author: your name
Date: 2021-10-04 21:26:18
LastEditTime: 2021-10-04 21:43:41
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\爬虫\第一章\3_requests入门.py
'''
import requests

url = 'https://www.sogou.com/web?query=周杰伦'

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.71 Safari/537.36 Edg/94.0.992.38"
}

resp = requests.get(url, headers=headers)
print(resp)
print(resp.text)
