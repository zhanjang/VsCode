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
#del语句 删除列表的指定位置的元素（也可以用pop()方法）
del list1[1]
print(list1)
#remove()方法 删除列表中某个值的第一个匹配项,如果`没有找到该值则报错
list1.remove('c')
print(list1)
#count()方法 统计某个元素在列表中出现的次数
list3 = [1, 2, 3, 1, 2, 1]
print(list3.count(1))
#index()方法 从列表中找出某个值第一个匹配项的索引位置,如果没有找到该值则报错
print(list1.index('c'))
#sort()方法 对原列表进行排序
list4 = [3, 1, 4, 2]
list4.sort(reverse=True) #reverse=True 降序排列,False 升序排列
print(list4)
#sorted()函数 返回一个新的排序列表,不改变原列表
list5 = sorted(list4)
print(list4)
print(list5)
#reverse()方法 反转列表
print(list4.reverse())