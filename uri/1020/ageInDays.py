dia = int(raw_input())
ano = dia / 365
dia = dia - 365 * ano
mes = dia / 30
dia = dia - 30 * mes
print(str(ano) + ' ano(s)')
print(str(mes) + ' mes(es)')
print(str(dia) + ' dia(s)')
