p1 = raw_input()
p1 = p1.split(' ')
x1 = float(p1[0])
y1 = float(p1[1])
p2 = raw_input()
p2 = p2.split(' ')
x2 = float(p2[0])
y2 = float(p2[1])
import math
distance = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
print(format(distance, '.4f'))