#截取字符串,生产新的字符串
str1 = "hello,world!"
str2 = str1[0:5]  #从索引0开始截取到索引5(不包含5)
print(str2)  #hello
str3 = str1[7:]  #从索引7开始截取到字符串末尾
print(str3)  #world!
str4 = str1[:]  #从头截取到尾
print(str4)  #hello,world!
str5 = str1[::-1]  #从头到尾,步长为-1,表示逆序截取
print(str5)  #!dlrow,olleh
#分割字符串
str6 = "hello,world,python"
list1 = str6.split()  #默认分隔符进行分割
print(list1)  #['hello,world,python']
list2 = str6.split(",")  #指定逗号为分隔符进行
print(list2)  #['hello', 'world', 'python']
#count统计字符串中某个子串出现的次数
str7 = "hello,world!hello,python!"
count1 = str7.count("hello")
print(count1)  #2
#find查找子串在字符串中第一次出现的索引位置,找不到返回-1
find1 = str7.find("python")
#index查找子串在字符串中第一次出现的索引位置,找不到报错
index1 = str7.index("world")
#endwith判断字符串是否以指定的子串结尾
end1 = str7.endswith("python!")
#startwith判断字符串是否以指定的子串开头
start1 = str7.startswith("hello")
#replace替换字符串中的指定子串,生成新的字符串
str8 = str7.replace("hello", "hi") #hello为就字符串,替换为新的hi字符串
print(str8)  #hi,world!hi,python!
#字母大小写转换
str9 = "Hello,World!"
print(str9.upper())  #转换为大写,HELLO,WORLD!
print(str9.lower())  #转换为小写,hello,world!
print(str9.swapcase())  #大小写互换,hELLO,wORLD!
print(str9.title())  #每个单词首字母大写,Hello,World!
print(str9.capitalize())  #首字母大写,Hello,world!
#去除字符串两端的空白字符
str10 = "  hello,world!  "
print(str10.strip())  #去除两端空白字符,hello,world!
print(str10.lstrip())  #去除左端空白字符,hello,world
print(str10.rstrip())  #去除右端空白字符,  hello,world!
#判断字符串是否由数字组成