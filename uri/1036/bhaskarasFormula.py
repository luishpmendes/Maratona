line = raw_input()
line = line.split(' ')
a = float(line[0])
b = float(line[1])
c = float(line[2])
delta = b*b-4.0*a*c
if delta < 0.0 or a == 0.0 :
    print('Impossivel calcular')
else :
    import math
    r1 = (-b+math.sqrt(delta))/(2*a)
    r2 = (-b-math.sqrt(delta))/(2*a)
    print('R1 = ' + format(r1, '.5f'))
    print('R2 = ' + format(r2, '.5f'))
