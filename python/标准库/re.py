#需要引入re标准库
#r表示原生字符模式及\n不表示转义后的意思,而直接输出\n
import re
#通过compile方法来确定规则re.compile(规则,匹配方式)
#常见匹配方式 A进行ascii匹配 I不区分大小写匹配
#规则常用表式 .匹配除\n以外的 []匹配范围内的字符,如[az]匹配azds中的a,z [A-Z]匹配字母范围从a-z默认区分大小写 [^...]表示排除范围内的字符
# ^表示匹配开头 $表示匹配末尾 \w匹配字母,数字,下划线,汉字 \W匹配\w以外的内容 \s匹配单个空白包括\t和\n \S匹配\s以外的内容
#\b匹配\b后面或前面的内容如\bw表示匹配开头的w \wb表示匹配结尾的w \B匹配规则与前面相反\Bw匹配结尾的w \wB匹配开头的w \d匹配数字 \D匹配除数字以外的
#限定符 ?匹配前面的字符一次或零次 例colou?r匹配colour或color +匹配前面字符一次或多次 *匹配前面字符一次或零次
#{n}匹配前面字符n次例如go{2}gle只能匹配google {n,}匹配前面的字符至少n次 {n,m}匹配前面的字符至少n次,至多m次
# |表示或匹配`这两个规则 例如a|b可以匹配a或者b
# (...)书写复杂规则使用一般与|搭配 例如([0-9]{1,3}){3}表示匹配0-9至少1次至多3次,这个规则重复匹配三次(分组版本) (?:...)不分组版本 区别在下面具体演示
patter1 = re.compile(r'[A-Z]',re.I)#匹配字母,不区分大小写
patter2 = re.compile(r'^\d{8}')#匹配数字匹配8个数字为真否则为假
patter3 = re.compile(r'(\.[0-9]{1,3}){3}')
patter4 = re.compile(r'(?:\.[0-9]{1,3}){3}')
#简单的邮箱验证程序
patter5 = re.compile(r'(^\w+)(\@\w+)(\.com{1}$)',re.I)
test = '127.0.0.1'
print(patter3.findall(test))
print(patter4.findall(test))
email = str(input('输入你的邮箱'))
if patter5.search(email):
    print(f'你的邮箱{email}符合规定')
else:
    print('你的邮箱有问题')