import random
import csv

lista = []
for i in range(100):
    lista.append(random.randint(1, 1000))

with open('100ran.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    for num in lista:
        writer.writerow([num])