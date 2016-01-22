aux = int(raw_input())
n = aux
cem = n / 100
n = n - 100 * cem
cinquenta = n / 50
n = n - 50 * cinquenta
vinte = n / 20
n = n - 20 * vinte
dez = n / 10
n = n - 10 * dez
cinco = n / 5
n = n - 5 * cinco
dois = n / 2
um = n - 2 * dois
print (aux)
print (str(cem) + ' nota(s) de R$ 100,00')
print (str(cinquenta) + ' nota(s) de R$ 50,00')
print (str(vinte) + ' nota(s) de R$ 20,00')
print (str(dez) + ' nota(s) de R$ 10,00')
print (str(cinco) + ' nota(s) de R$ 5,00')
print (str(dois) + ' nota(s) de R$ 2,00')
print (str(um) + ' nota(s) de R$ 1,00')
