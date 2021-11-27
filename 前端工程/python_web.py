# -*- coding: utf-8 -*- 
from pywebio.input import input, FLOAT
from pywebio.output import put_text
from pywebio import session
from pywebio import start_server

# input("This is a simple text input")
# select("This is a drop down menu", ["Option1", "Option2"])
# checkbox("Multiple Choices!", options=["a","b","c","d"])
# radio("Select any one", options=['1', '2', '3'])
# textarea("Text Area", rows=3, placeholder="Multiple line text input")

# put_text("Hello friend!")
# put_table([["Object", "Unit"], ["A", "55"], ["B", "73"],])
# put_markdown("~~PyWebIO~~")
# popup('popup title', 'popup text content')

# session.hold()

def bmi():
    height = input("请输入你的身高(cm): ", type=FLOAT)
    weight = input("请输入你的体重(kg): ", type=FLOAT)

    BMI = weight / (height / 100) ** 2

    top_status = [(14.9,"极瘦"), (18.4, "偏廋"), (22.9, "正常"), (27.5, "过重"), (40.0, "肥胖")]

    for top, status in top_status:
        if BMI <= top:
            put_text("你的BMI值：%.f, 身体状态：%s" % (BMI, status))
            break


if __name__ == '__main__':
    start_server(bmi, port=80)
    

    