import csv

lista = []
for i in range(1, 500001):
    lista.append(i)

with open('50cres.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])