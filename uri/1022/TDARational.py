n = int(raw_input())
for i in range(n) :
    line = raw_input()
    line = line.split(' ')
    n1 = int(line[0])
    d1 = int(line[2])
    n2 = int(line[4])
    d2 = int(line[6])
    op = line[3]
    n = 0
    d = 0
    if op == '+' :
        n = n1*d2 + n2*d1
        d = d1 * d2
    elif op == '-' :
        n = n1*d2 - n2*d1
        d = d1 * d2
    elif op == '*' :
        n = n1 * n2
        d = d1 * d2
    else :
        n = n1 * d2
        d = n2 * d1
    from fractions import gcd
    aux = gcd(n, d)
    nSimple = n / aux
    dSimple = d / aux
    print(str(n) + '/' + str(d) + ' = ' + str(nSimple) + '/' + str(dSimple))
