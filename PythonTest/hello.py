'''
Descripttion: 
version: 
Author: vansson
Date: 2023-08-24 20:20:11
LastEditors: vansson
LastEditTime: 2023-08-26 10:49:50
'''
name = '晏万松'
area = 'FZU'
print(name)
print("Hello World!"+name)
#print(type(name))
#print('my name is %s, from %s!'%(name, area))
print('my name is {}, from {}!'.format(name, area))

# row = 1
# while row <= 9:
#     col = 1
#     while col <= row:
#         print("{}*{}={}".format(row,col,row*col),end=" ")
#         col += 1
#         pass
#     print() #换行
#     row += 1
#     pass


# tags = "Love FZU"
# for item in tags:
#     print(item)
#     pass

# for i in range(1,10):
#     for j in range(1,i+1):
#         print("{}*{}={}".format(i,j,i*j),end=" ")
#         pass
#     print()
#     pass

user = 'Vansson'
password = 'vansson'
for i in range(3):
    zh = input('please input your username:')
    pd = input('please input your password:')
    if zh == user and pd == password:
        print("Success")
        break
else:
    print("fail")
    
result = (65235 ** 3 + 3 * 65235) % 4177
print(result)
