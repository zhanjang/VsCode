import pymysql
conn = pymysql.connect(
    host = 'localhost',
    port = 3306,
    user = 'root',
    password = '123456'
)
print(conn.get_server_info())

conn.close