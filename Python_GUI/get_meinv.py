import requests
import parsel
import re
import concurrent.futures
import time
import warnings

# 取消警告
warnings.filterwarnings("ignore")

def get_html(url):
    """发送请求获取网页源代码"""
    html_data = requests.get(url=url, verify=False).text
    return html_data

def parse_data_1(html_data):
    """第一次解析，拿到所有的详情页链接"""
    selector = parsel.Selector(html_data)
    url_list = selector.xpath('//a[@class="meta-title"]/@href').getall()
    return url_list

def parse_data_2(html_data):
    """第二次解析，获取视频链接"""
    video_url = re.findall(('url: "(.*?)",'), html_data)[0]
    return video_url

def save(video_url):
    """保存视频"""
    title = video_url.split("/")[-1]  #取链接当中的字段作为标题
    video_data = requests.get(video_url, verify=False).content  #发送网络请求
    with open(f'video/{title}', mode='wb') as f:
        f.write(video_data)
    print(title, "爬取成功!!")

start_time = time.time()
url = "https://www.520mmtv.com/hd/rewu.html"

# 1. 向目标网站发送请求
html_data = get_html(url=url)

# 2. 第一次解析数据 提起详情页链接
url_list= parse_data_1(html_data=html_data)

for info_url in url_list[:10]:
    # 3. 向详情页发送请求
    html_data_2 = get_html(url=info_url)
    # 4. 第二次解析数据 提取视频播放地址
    video_url = parse_data_2(html_data=html_data_2)
    # 5. 保存视频
    save(video_url=video_url)
print("花费时间:", time.time() - start_time)

