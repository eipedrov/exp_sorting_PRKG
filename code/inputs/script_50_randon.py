import random
import csv

lista = []
for i in range(500000):
    lista.append(random.randint(1, 500000))

with open('50ran.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])