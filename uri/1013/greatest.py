abc = raw_input()
abc = abc.split(' ')
a = int(abc[0])
b = int(abc[1])
c = int(abc[2])
maior = a;
if maior < b :
    maior = b
if maior < c :
    maior = c
print(str(maior) + ' eh o maior')
