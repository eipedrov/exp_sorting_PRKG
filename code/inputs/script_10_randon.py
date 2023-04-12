import random
import csv

lista = []
for i in range(10000):
    lista.append(random.randint(1, 10000))

with open('10ran.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])