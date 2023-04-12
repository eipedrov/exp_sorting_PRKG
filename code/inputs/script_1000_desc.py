import csv

lista = []
for i in range(1000, 0, -1):
    lista.append(i)

with open('1000desc.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])