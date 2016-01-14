def contaminate(mapa, n, m, row, col) :
    if row >= 0 and row < n and col >= 0 and col < m and mapa[row][col] == 'A' :
        mapa[row][col] = 'T'
        contaminate (mapa, n, m, row-1, col)
        contaminate (mapa, n, m, row, col-1)
        contaminate (mapa, n, m, row+1, col)
        contaminate (mapa, n, m, row, col+1)

while True :
    r = [0 for x in range (2552)]
    c = [0 for x in range (2552)]
    nm = raw_input()
    nm = nm.split(' ')
    n = int(nm[0])
    m = int(nm[1])
    if n > 0 and m > 0 :
        mapa = [['' for x in range(m)] for x in range(n)]
        for i in range(n) :
            line = raw_input()
            for j in range(m) :
                mapa[i][j] = line[j]
        count = 0
        for i in range(n) :
            for j in range(m) :
                if mapa[i][j] == 'T' :
                    r[count] = i
                    c[count] = j
                    count = count + 1
        for i in range(count) :
            contaminate(mapa, n, m, r[i]-1, c[i])
            contaminate(mapa, n, m, r[i], c[i]-1)
            contaminate(mapa, n, m, r[i]+1, c[i])
            contaminate(mapa, n, m, r[i], c[i]+1)
        for i in range(n) :
            print(''.join(mapa[i]))
        print
    else :
        break
