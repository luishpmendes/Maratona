line = raw_input()
line = line.split(' ')
line = map(int, line)
line.sort()
a = line[0]
b = line[1]
if b % a == 0 :
    print('Sao Multiplos')
else :
    print('Nao sao Multiplos')
