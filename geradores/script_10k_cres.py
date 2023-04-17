import csv

lista = []
for i in range(1, 10001):
    lista.append(i)

with open('10cres.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Números'])
    for num in lista:
        writer.writerow([num])