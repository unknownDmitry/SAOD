#include <iostream>
#include <fstream>

const int MAX = 31;

void pascal_comp(int arr[MAX][MAX], int N) {

	for (int i = 0; i < N; i++) {
		arr[i][0] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = (arr[i-1][j]) + (arr[i-1][j-1]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void save_to_file(int arr[MAX][MAX], int N, std::string& path) {
	std::ofstream out(path);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			out << arr[i][j] << " ";
		}
		out << std::endl;
	}

	out.close();
}

int read_from_file(std::string& path) {
	std::ifstream in(path);
	int size;
	in >> size;
	return size;
}

int main() {

	std::string path_in = "INPUT.txt";
	std::string path_out = "OUTPUT.txt";
	int N = read_from_file(path_in);

	int arr[MAX][MAX] = {};

	pascal_comp(arr, N);

	save_to_file(arr, N, path_out);

	return 0;
}