line = raw_input()
line = line.split(' ')
a = int(line[0])
b = int(line[1])
c = int(line[2])
d = int(line[3])
if b > c and d > a and c + d > a + b and c > 0 and d > 0 and a & 1 == 0 :
    print('Valores aceitos')
else :
    print('Valores nao aceitos')
