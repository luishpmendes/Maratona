n = int(raw_input())
for _ in range(n) :
    s = raw_input()
    l = list(s)
    for i in range(len(l)) :
        if (l[i] >= 'A' and l[i] <= 'Z') or (l[i] >= 'a' and l[i] <= 'z') :
            l[i] = chr(ord(l[i]) + 3)
    l.reverse()
    for i in range(len(l)/2, len(l)) :
        l[i] = chr(ord(l[i]) - 1)
    print(''.join(l))
