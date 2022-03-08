# 08/10/2021 - Estudo Algoritmos Aula 01 - Variáveis - Python
# Referência: https://www.w3schools.com/python/python_variables.asp

x = 5
y = "Luiz"

# alterando o tipo da variável após ela já ter sido declarada
x = "Carlos"

print(x)
print(y)

# casting em python:

x = str(3)    # x será '3'
y = int(3)    # y será 3
z = float(3)  # z será 3.0 

print(x)
print(y)
print(z)

# verificando os tipos em Python - função type():

print(type(x))
print(type(y))
print(type(z))

# strings podem ser declaradas utilizando aspas simples ou dupla:

t = "da Silva"
w = 'da Silva'

print(t)
print(w)
print(type(t))
print(type(w))

# os nomes das variaveis são case-sensitive:

g = 4
G = "Joana"

print(g)