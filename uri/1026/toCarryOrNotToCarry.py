import sys

for line in sys.stdin:
    line = line.split(' ')
    a = int(line[0])
    b = int(line[1])
    r = a ^ b
    print(r)
