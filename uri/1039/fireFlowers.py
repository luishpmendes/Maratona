import sys

for line in sys.stdin :
    line = line.split(' ')
    r1 = int(line[0])
    x1 = int(line[1])
    y1 = int(line[2])
    r2 = int(line[3])
    x2 = int(line[4])
    y2 = int(line[5])
    dx = x2 - x1
    dy = y2 - y1
    distance = (dx * dx) + (dy * dy)
    if r1 > r2 and distance <= (r1-r2)*(r1-r2) :
        print('RICO')
    else :
        print('MORTO')
