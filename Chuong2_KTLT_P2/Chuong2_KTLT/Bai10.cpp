#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

bool SoHoanThien(int num) {
	if (num < 2) return false;
	int tong = 1;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			tong += i;
		}
	}
	return tong == num;
}

bool SoNguyenTo(int num) {
	if (num <= 1) return false;
	for (int i = 2; i <= (int)sqrt((double)num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void TaoMangNgauNhien(int a[][100], int m, int n) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100;
		}
	}
}

void LietKeTongNhoNhat(int a[][100], int m, int n) {
	int tongnho = INT_MAX;
	int tongcot[100] = { 0 };

	for (int j = 0; j < n; j++) {
		int tong = 0;
		for (int i = 0; i < m; i++) {
			tong += a[i][j];
		}
		tongcot[j] = tong;
		if (tong < tongnho) {
			tongnho = tong;
		}
	}
	printf("Cac cot co tong nho nhat trong ma tran: ");
	for (int j = 0; j < n; j++) {
		if (tongcot[j] == tongnho) {
			printf("%d ", j);
		}
	}
	printf("\n");
}


int main() {
	int a[100][100];
	int m, n;

	printf("Nhap so hang m: ");
	scanf("%d", &m);
	printf("Nhap so cot n: ");
	scanf("%d", &n);

	TaoMangNgauNhien(a, m, n);

	printf("Ma tran ngau nhien:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	LietKeTongNhoNhat(a, m, n);
	return 0;
}