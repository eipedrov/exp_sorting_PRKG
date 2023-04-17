import csv

lista = []
for i in range(500000, 0, -1):
    lista.append(i)

with open('50desc.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])