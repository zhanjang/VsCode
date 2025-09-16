#list操作
#enumerate()函数 返回元素的索引
list1 = ['a', 'b', 'c', 'd']
for i, value in enumerate(list1):
    print(i, value)
#append()方法 在列表末尾添加新的元素
list1.append('e')
print(list1)
#insert()方法 在指定位置添加新的元素
list1.insert(1, 'A')
print(list1)
#extend()方法 在列表末尾一次性追加另一个序列中的多个值（用新列表扩展原来的列表）
list2 = ['f', 'g', 'h']
list1.extend(list2)
print(list1)
#index()方法 从列表中找出某个值第一个匹配项的索引位置,如果没有找到该值则报错
print(list1.index('c'))
#