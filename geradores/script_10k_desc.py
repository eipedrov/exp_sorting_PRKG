import csv

lista = []
for i in range(10000, 0, -1):
    lista.append(i)

with open('10desc.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Números'])
    for num in lista:
        writer.writerow([num])