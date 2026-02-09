import matplotlib.pyplot as plt
import csv

# Чтение данных из CSV
sizes = []
bubble_times = []
merge_times = []
quick_times = []
shell_times = []

with open('results.csv', 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        sizes.append(int(row['size']))
        bubble_times.append(float(row['bubble']))
        merge_times.append(float(row['merge']))
        quick_times.append(float(row['quick']))
        shell_times.append(float(row['shell']))

# Построение графика
plt.figure(figsize=(12, 8))

plt.plot(sizes, bubble_times, marker='o', linewidth=2, label='Bubble Sort', color='#e74c3c')
plt.plot(sizes, merge_times, marker='s', linewidth=2, label='Merge Sort', color='#3498db')
plt.plot(sizes, quick_times, marker='^', linewidth=2, label='Quick Sort', color='#2ecc71')
plt.plot(sizes, shell_times, marker='d', linewidth=2, label='Shell Sort', color='#9b59b6')

plt.xlabel('Размер массива (n)', fontsize=12)
plt.ylabel('Время (секунды)', fontsize=12)
plt.title('Сравнение времени выполнения алгоритмов сортировки', fontsize=14)
plt.legend(fontsize=11)
plt.grid(True, alpha=0.3)
plt.tight_layout()

plt.savefig('sorting_comparison.png', dpi=150)
plt.show()

print("График сохранён: sorting_comparison.png")
