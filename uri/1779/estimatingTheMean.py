t = int(raw_input())
for x in range(t) :
    n = int(raw_input())
    p = raw_input()
    p = p.split(' ')
    p = map(int, p)
    m = max(p)
    y = 1
    aux = 0
    for i in range (n) :
        if p[i] == m :
            aux = aux + 1
        else :
            aux = 0
        if y < aux :
            y = aux
    print('Caso #' + str(x + 1) + ': ' + str(y))
