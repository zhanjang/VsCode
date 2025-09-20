name = ['绮梦','伊一','香凝','黛清','禹西']
sign = ['水瓶座','狮子座','射手座','双鱼座','巨蟹座']
dict1 = {zip(name,sign)}
#del删除直接删除字典,或者删除元素(若没有会报错)
dict2 = {zip(name,sign)}
del dict2
del dict1['绮梦']
#clear清空字典
dict3 = {zip(name,sign)}
dict3.clear()