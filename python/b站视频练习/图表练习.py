from pyecharts.charts import Line
import json
f_us = open("D:\VsCode\python\b站视频练习\资料\折线图数据\美国.txt","r",encoding="UTF-8")
f_us_data = f_us.read()
f_us_data = f_us_data.replace('jsonp_1629344292311_69436(','')
f_us_data = f_us_data[::-2]
f_us_dict = json.loads(f_us_data)
trend_data = f_us_dict["data"][0]['trend']
trend_data['updateDate'][:314]