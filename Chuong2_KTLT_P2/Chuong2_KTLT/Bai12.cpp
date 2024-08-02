#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TaoMangNgauNhien(int a[][100], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100; 
		}
	}
}

int TongDuongcCheoChinh(int a[][100], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += a[i][i];
	}
	return tong;
}

int TongDuongCheoPhu(int a[][100], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += a[i][n - i - 1];
	}
	return tong;
}

int TongDuongCheoChinhTren(int a[][100], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}

int TongDuongCheoPhuTren(int a[][100], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}

int main() {
	int a[100][100];
	int n;

	printf("Nhap kich thuoc ma tran vuong n: ");
	scanf("%d", &n);

	TaoMangNgauNhien(a, n);

	printf("Ma tran ngau nhien:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int sumMain = TongDuongcCheoChinh(a, n);
	printf("Tong cac phan tu tren duong cheo chinh: %d\n", sumMain);

	int sumSecondary = TongDuongCheoPhu(a, n);
	printf("Tong cac phan tu tren duong cheo phu: %d\n", sumSecondary);

	int sumAboveMain = TongDuongCheoChinhTren(a, n);
	printf("Tong cac phan tu phia tren duong cheo chinh: %d\n", sumAboveMain);

	int sumAboveSecondary = TongDuongCheoPhuTren(a, n);
	printf("Tong cac phan tu phia tren duong cheo phu: %d\n", sumAboveSecondary);

	return 0;
}
