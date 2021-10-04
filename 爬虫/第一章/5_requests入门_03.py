'''
Author: your name
Date: 2021-10-04 21:58:54
LastEditTime: 2021-10-04 22:16:16
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\爬虫\第一章\5_requests入门_03.py
'''
import requests

url = "https://movie.douban.com/j/chart/top_list"

param = {
    "type": "24",
    "interval_id": "100:90",
    "action": "",
    "start": 0,
    "limit": 20
}


headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.71 Safari/537.36 Edg/94.0.992.38"
}

resp = requests.get(url, params=param, headers=headers)

print(resp.json())
resp.close()