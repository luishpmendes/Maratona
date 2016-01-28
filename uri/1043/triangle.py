line = raw_input()
line = line.split()
a = float(line[0])
b = float(line[1])
c = float(line[2])
if a + b > c and a + c > b and b + c > a :
    perimeter = a + b + c
    print('Perimetro = ' + format(perimeter, '.1f'))
else :
    area = ((a + b) * c) / 2
    print('Area = ' + format(area, '.1f'))
