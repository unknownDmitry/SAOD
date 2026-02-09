import csv
import os
import sys
import matplotlib.pyplot as plt

def read_csv_data(filename):
    sizes = []
    linear_times = []
    binary_times = []
    interpol_times = []
    
    with open(filename, 'r', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        for row in reader:
            sizes.append(int(row['Size']))
            linear_times.append(int(row['Linear_Search_ns']))
            binary_times.append(int(row['Binary_Search_ns']))
            interpol_times.append(int(row['Interpolation_Search_ns']))
    
    return sizes, linear_times, binary_times, interpol_times

def plot_graph(sizes, linear_times, binary_times, interpol_times):
    fig, ax = plt.subplots(figsize=(10, 6))
    
    ax.plot(sizes, linear_times, 'o-', label='Линейный поиск O(n)', linewidth=2, markersize=8)
    ax.plot(sizes, binary_times, 's-', label='Бинарный поиск O(log n)', linewidth=2, markersize=8)
    ax.plot(sizes, interpol_times, '^-', label='Интерполяционный поиск O(log log n)', linewidth=2, markersize=8)
    ax.set_xlabel('Размер массива', fontsize=12)
    ax.set_ylabel('Время выполнения (наносекунды)', fontsize=12)
    ax.set_title('Время выполнения алгоритмов поиска', fontsize=14, fontweight='bold')
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.legend(fontsize=11)
    ax.grid(True, alpha=0.3, which='major')
    
    plt.tight_layout()
    
    script_dir = os.path.dirname(os.path.abspath(__file__))
    output_file = os.path.join(script_dir, 'complexity_comparison.png')
    plt.savefig(output_file, dpi=300, bbox_inches='tight')
    print(f"График сохранен в файл: {output_file}")
    plt.show()

def main():
    if len(sys.argv) > 1:
        csv_file = sys.argv[1]
    else:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        # Сначала проверяем в той же папке, где находится скрипт
        csv_file = os.path.join(script_dir, 'search_results.csv')
        # Если не найден, проверяем в корне проекта
        if not os.path.exists(csv_file):
            project_root = os.path.dirname(script_dir)
            csv_file = os.path.join(project_root, 'search_results.csv')
    
    if not os.path.exists(csv_file):
        print(f"Ошибка: файл search_results.csv не найден!")
        sys.exit(1)
    
    sizes, linear_times, binary_times, interpol_times = read_csv_data(csv_file)
    plot_graph(sizes, linear_times, binary_times, interpol_times)

if __name__ == '__main__':
    main()
