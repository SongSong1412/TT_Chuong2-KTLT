#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


bool SoHoanThien(int num) {
	int tong = 1;
	for (int i = 2; i <= sqrt((double)num); i++) {
		if (num % i == 0) {
			if (i == (num / i)) {
				tong += i;
			}
			else {
				tong+= i + (num / i);
			}
		}
	}
	return (tong== num && num != 1);
}

bool SoNguyenTo(int num) {
	if (num <= 1) {
		return false;
	}
	for (int i = 2; i <= (int)sqrt((double)num); i++) {
		if (num % i == 0) {
			return false;
		}
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

int TongChuSoLe(int a[][100], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int firstDigit = abs(a[i][j]);
			while (firstDigit >= 10) {
				firstDigit /= 10;
			}
			if (firstDigit % 2 != 0) {
				tong += a[i][j];
			}
		}
	}
	return tong;
}

void LietKeSoHoanThien(int a[][100], int m, int n) {
	printf("Cac so hoan thien trong ma tran: ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (SoHoanThien(a[i][j])) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

int TongPhanTuLonHonTTDPhanTuSauNo(int a[][100], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] > abs(a[i][j + 1])) {
				tong += a[i][j];
			}
		}
	}
	return tong;
}

int TongDongk(int a[][100], int m, int n, int k) {
	int tong = 0;
	for (int j = 0; j < n; j++) {
		tong += a[k][j];
	}
	return tong;
}

int TongGiaTriBien(int a[][100], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				tong += a[i][j];
			}
		}
	}
	return tong;
}

int TanXuatGiaTriX(int a[][100], int m, int n, int x) {
	int Dem = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == x) {
				Dem++;
			}
		}
	}
	return Dem;
}

void DemPhanTu(int a[][100], int m, int n, int *Chan, int *Le, int *Am, int *Duong, int *NguyenTo) {
	*Chan = *Le = *Am = *Duong = *NguyenTo = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 == 0) {
				(*Chan)++;
			}
			else {
				(*Le)++;
			}
			if (a[i][j] < 0) {
				(*Am)++;
			}
			else if (a[i][j] > 0) {
				(*Duong)++;
			}
			if (SoNguyenTo(a[i][j])) {
				(*NguyenTo)++;
			}
		}
	}
}
int main() {
	int a[100][100];
	int m, n;

	printf("Nhap so hang m: ");
	scanf("%d", &m);
	printf("Nhap so cot n: ");
	scanf("%d", &n);

	TaoMangNgauNhien(a, m, n);

	printf("Ma tran ngau nhien sau khi tao:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("Tong cac phan tu co chu so dau la chu so le: %d\n", TongChuSoLe(a, m, n));

	LietKeSoHoanThien(a, m, n);

	printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", TongPhanTuLonHonTTDPhanTuSauNo(a, m, n));

	int k;
	printf("Nhap dong k: ");
	scanf("%d", &k);
	printf("Tong gia tri tren dong k cua ma tran: %d\n", TongDongk(a, m, n, k));

	printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", TongGiaTriBien(a, m, n));

	int x;
	printf("Nhap gia tri x: ");
	scanf("%d", &x);
	printf("Tan suat xuat hien cua gia tri x trong ma tran: %d\n", TanXuatGiaTriX(a, m, n, x));

	int Chan, Le, Am, Duong, NguyenTo;
	DemPhanTu(a, m, n, &Chan, &Le, &Am, &Duong, &NguyenTo);
	printf("So luong phan tu chan: %d\n", Chan);
	printf("So luong phan tu le: %d\n", Le);
	printf("So luong phan tu am: %d\n", Am);
	printf("So luong phan tu duong: %d\n", Duong);
	printf("So luong phan tu nguyen to: %d\n", NguyenTo);

	return 0;
}