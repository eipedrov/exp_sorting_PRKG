import random
import csv

lista = []
for i in range(1000):
    lista.append(random.randint(1, 1000))

with open('1000ran.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])