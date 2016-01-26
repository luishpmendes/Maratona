n = float(raw_input())
n = round(n, 2)

notasCem = int(n/100)
n = n - 100 * notasCem
n = round(n, 2)

notasCinqunta = int(n/50)
n = n - 50 * notasCinqunta
n = round(n, 2)

notasVinte = int(n/20)
n = n - 20 * notasVinte
n = round(n, 2)

notasDez = int(n/10)
n = n - 10 * notasDez
n = round(n, 2)

notasCinco = int(n/5)
n = n - 5 * notasCinco
n = round(n, 2)

notasDois = int(n/2)
n = n - 2 * notasDois
n = round(n, 2)

moedasCem = int(n)
n = n - 1 * moedasCem
n = round(n, 2)

moedasCinquenta = int(n * 2)
n = n - 0.50 * moedasCinquenta
n = round(n, 2)

moedasVinteCinco = int(n * 4)
n = n - 0.25 * moedasVinteCinco
n = round(n, 2)

moedasDez = int(n * 10)
n = n - 0.10 * moedasDez
n = round(n, 2)

moedasCinco = int(n * 20)
n = n - 0.05 * moedasCinco
n = round(n, 2)

moedasUm = int(n * 100)
n = n - 0.01 * moedasUm
n = round(n, 2)

print('NOTAS:')
print(str(notasCem) + ' nota(s) de R$ 100.00')
print(str(notasCinqunta) + ' nota(s) de R$ 50.00')
print(str(notasVinte) + ' nota(s) de R$ 20.00')
print(str(notasDez) + ' nota(s) de R$ 10.00')
print(str(notasCinco) + ' nota(s) de R$ 5.00')
print(str(notasDois) + ' nota(s) de R$ 2.00')
print('MOEDAS:')
print(str(moedasCem) + ' moeda(s) de R$ 1.00')
print(str(moedasCinquenta) + ' moeda(s) de R$ 0.50')
print(str(moedasVinteCinco) + ' moeda(s) de R$ 0.25')
print(str(moedasDez) + ' moeda(s) de R$ 0.10')
print(str(moedasCinco) + ' moeda(s) de R$ 0.05')
print(str(moedasUm) + ' moeda(s) de R$ 0.01')
