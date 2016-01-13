import sys

for line in sys.stdin :
    line = line.split(' ')
    ld = int(line[0])
    cd = int(line[1])
    lv = int(line[2])
    cv = int(line[3])
    if ld < cd :
        aux = ld
        ld = cd
        cd = aux
    if lv < cv :
        aux = lv
        lv = cv
        cv = aux
    a = ld
    if a > lv :
        a = lv
    if a > cd + cv :
        a = cd + cv
    a = a * a
    print(a)
