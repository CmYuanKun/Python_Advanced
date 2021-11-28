#import pyecharts
# print(pyecharts.__version__)


# from pyecharts.charts import Bar
# bar = Bar()
# bar.add_xaxis(["衬衫", "羊毛衫", "雪纺衫", "裤子", "袜子"])
# bar.add_yaxis("商家A", [5, 20, 36, 10, 75, 90])
# bar.render()


# from pyecharts.charts import Bar
# bar = Bar()
# bar.add_xaxis(["衬衫", "羊毛衫", "雪纺衫", "裤子", "袜子"])
# bar.add_yaxis("商家B", [5, 20, 36, 10, 75, 90])
# bar.render("firstpyecharts.html")

from pyecharts.globals import CurrentConfig, OnlineHostType
CurrentConfig.ONLINE_HOST = OnlineHostType.NOTEBOOK_HOST

from pyecharts.charts import Bar
bar = Bar()
bar.add_xaxis(["衬衫", "羊毛衫", "雪纺衫", "裤子", "高跟鞋", "袜子"])
bar.add_yaxis("商家B", [15, 20, 36, 18, 45, 69])
bar.render_notebook()

