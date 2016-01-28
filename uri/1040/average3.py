line = raw_input()
line = line.split(' ')
n1 = float(line[0])
n2 = float(line[1])
n3 = float(line[2])
n4 = float(line[3])
average = (2.0*n1+3.0*n2+4.0*n3+n4)/10.0
print('Media: ' + format(average, '.1f'))
if average >= 7.0 :
    print('Aluno aprovado.')
elif average < 5.0 :
    print('Aluno reprovado.')
else :
    print('Aluno em exame.')
    exam = float(raw_input())
    print('Nota do exame: ' + format(exam, '.1f'))
    final = (average + exam) / 2
    if (final >= 5.0) :
        print('Aluno aprovado.')
    else :
        print('Aluno reprovado.')
    print('Media final: ' + format(final, '.1f'))
