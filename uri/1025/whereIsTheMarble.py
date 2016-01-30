for i in range(1, 67) :
    line = raw_input()
    line = line.split(' ')
    n = int(line[0])
    q = int(line[1])
    if n == 0 or q == 0 :
        break
    print('CASE# ' + str(i) + ':')
    marbleList = []
    for _ in range(n) :
        marble = int(raw_input())
        marbleList.append(marble)
    marbleList.sort()
    marbleSet = set(marbleList)
    for _ in range(q) :
        query = int(raw_input())
        if query not in marbleSet :
            print(str(query) + ' not found')
        else :
            print(str(query) + ' found at ' + str(marbleList.index(query) + 1))
