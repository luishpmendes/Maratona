n = int(raw_input())
maxLowerAngle = aux = 0.0
minUpperAngle = 100000.0
for i in range(n) :
    line = raw_input()
    line = line.split(' ')
    line = map(float, line)
    aux = line[1] / line[0]
    if maxLowerAngle < aux :
        maxLowerAngle = aux
    aux = line[2] / line[0]
    if minUpperAngle > aux :
        minUpperAngle = aux
line = raw_input()
line = line.split(' ')
line = map(float, line)
aux = line[1] / line[0]
if maxLowerAngle < aux :
    maxLowerAngle = aux
aux = line[2] / line[0]
if minUpperAngle > aux :
    minUpperAngle = aux
if maxLowerAngle <= minUpperAngle :
    print('Y')
else :
    print('N')
