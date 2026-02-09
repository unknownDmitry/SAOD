#include <iostream>

int main() {

	const int n = 8;
	const int m = 8;

	int a[n][m] = {};
	
	for (int i = 0; i < n; i++) {
		a[i][0] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}