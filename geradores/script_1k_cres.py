import csv

lista = []
for i in range(1, 1001):
    lista.append(i)

with open('1000cres.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])