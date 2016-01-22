abc = raw_input()
abc = abc.split(' ')
a = float(abc[0])
b = float(abc[1])
c = float(abc[2])
triangulo = (a * c) / 2.0
circulo = 3.14159 * c * c
trapezio = ((a + b) / 2.0) * c
quadrado = b * b
retangulo = a * b
print('TRIANGULO: ' + format(triangulo, '.3f'))
print('CIRCULO: ' + format(circulo, '.3f'))
print('TRAPEZIO: ' + format(trapezio, '.3f'))
print('QUADRADO: ' + format(quadrado, '.3f'))
print('RETANGULO: ' + format(retangulo, '.3f'))
