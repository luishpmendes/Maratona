abc = raw_input()
abc = abc.split(' ')
a = int(abc[0])
b = int(abc[1])
c = int(abc[2])
maiorab = (a + b + abs(a - b)) / 2;
maior = (maiorab + c + abs(maiorab - c)) / 2;
print(str(maior) + ' eh o maior')
