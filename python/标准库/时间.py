import datetime
from datetime import timedelta#主要用于时间加减操作
from datetime import timezone#主要用于时区处理
a1 = datetime.datetime.now()# 获取当前时间具体到微秒,可以获取时区信息,无参数时为本地时间
print(a1)
a1_utc = datetime.datetime.now(timezone.utc)# 获取当前UTC时间
a2 = datetime.datetime.today()# 获取当前时间具体到微秒,不可以获取时区信息
print(a2)
a3 = a1.strftime("%Y-%m-%d %H:%M:%S")# 格式化时间输出
print(a3)
a4 = datetime.datetime.strptime("2023-06-01 12:30:45", "%Y-%m-%d %H:%M:%S")# 字符串转换为时间类型(datetime对象)
a5 = a1.date()#输出日期部分,仅对datetime对象有效
a6 = a1.time()#输出时间部分,仅对datetime对象有效
a1.replace(year=2022, month=5)# 替换时间指定部分,返回一个新的datetime对象
a11 = a1 + timedelta(days=5, hours=3)# 时间加减,天数加5,小时加3,返回一个新的datetime对象
a1_newyork = a1_utc.astimezone(timezone(timedelta(hours=-4)))# astimezone函数,转换时间将UTC时间转换为纽约时间(UTC-4)