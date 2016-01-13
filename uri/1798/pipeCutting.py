nt = raw_input()
nt = nt.split(' ')
n = int(nt[0])
t = int(nt[1])
c = [0 for x in range (n)]
v = [0 for x in range (n)]
for i in range (0, n) :
    cv = raw_input()
    cv = cv.split(' ')
    c[i] = int(cv[0])
    v[i] = int(cv[1])
m = [[0 for x in range (t + 2)] for x in range(n + 2)]
for i in range(1, n + 1) :
    for j in range(0, t + 1) :
        m[i][j] = m[i - 1][j]
        if c[i-1] <= j :
            if m[i][j] < m[i][j - c[i-1]] + v[i-1] :
                m[i][j] = m[i][j - c[i-1]] + v[i-1]
print(m[n][t])
