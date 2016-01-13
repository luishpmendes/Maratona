t = int(raw_input())
while t > 0 :
    t = t - 1
    scr = raw_input()
    scr = scr.split(' ')
    s = int(scr[0])
    c = int(scr[1])
    r = int(scr[2])
    v = raw_input()
    v = v.split(' ')
    v = map(float, v)
    v.sort()
    for i in range(c) :
        v[i] = v[i] + r
    result = 0.0
    for i in range(s) :
        result = result + 1/v[i]
    print(format(result, '.2f'))
