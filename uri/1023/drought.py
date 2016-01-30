c = 0
while True :
    try :
        n = int(raw_input())
        if n <= 0 :
            break
        if c > 0 :
            print
        c = c + 1
        xs = 0.0
        ys = 0.0
        zs = []
        for i in range(n) :
            line = raw_input()
            line = line.split(' ')
            x = int(line[0])
            y = int(line[1])
            xs = xs + x
            ys = ys + y
            zs.append((y/x, x))
        d = dict()
        for z in zs :
            try :
                d[z[0]] = d[z[0]] + z[1]
            except KeyError :
                d[z[0]] = z[1]
        zs = d.items()
        def getKey (item) :
            return item[0]
        zs.sort(key = getKey)
        print('Cidade# ' + str(c) + ':')
        s = ''
        zlen = len(zs)
        for i in range(zlen - 1) :
            s = s + str(zs[i][1]) + '-' + str(zs[i][0]) + ' '
        s = s + str(zs[zlen - 1][1]) + '-' + str(zs[zlen - 1][0])
        print(s)
        average = ys / xs
        aux = format(average, '.5f');
        aux = aux[0:len(aux)-3]
        print('Consumo medio: ' + aux + ' m3.')
    except EOFError :
        break
