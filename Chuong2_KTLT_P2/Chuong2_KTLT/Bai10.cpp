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

void LietKeDongSoHoanThienMax(int a[][100], int m, int n) {
	int DemSHT = 0;
	int DemDongSHT[100] = { 0 };

	for (int i = 0; i < m; i++) {
		int Dem = 0;
		for (int j = 0; j < n; j++) {
			if (SoHoanThien(a[i][j])) {
				Dem++;
			}
		}
		DemDongSHT[i] = Dem;
		if (Dem > DemSHT) {
			DemSHT = Dem;
		}
	}

	printf("Cac dong co nhieu so hoan thien nhat trong ma tran: ");
	for (int i = 0; i < m; i++) {
		if (DemDongSHT[i] == DemSHT) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

void LietKeDongChan(int a[][100], int m, int n) {
	printf("Cac dong chua toan gia tri chan: ");
	for (int i = 0; i < m; i++) {
		bool allEven = true;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				allEven = false;
				break;
			}
		}
		if (allEven) {
			printf("%d", i);
		}
	}
	printf("khong co dong nao chua gia tri toan chan\n");
}

void GiaTriXuatHienMax(int a[][100], int m, int n) {
	int tanxuat[10000] = { 0 }; 
	int tanxuatmax = 0;
	int xuathiennhieu = a[0][0];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tanxuat[a[i][j]]++;
			if (tanxuat[a[i][j]] > tanxuatmax) {
				tanxuatmax = tanxuat[a[i][j]];
				xuathiennhieu = a[i][j];
			}
		}
	}

	printf("Gia tri xuat hien nhieu nhat trong ma tran: %d\n", xuathiennhieu);
}

void SoNguyenToMIN(int a[][100], int m, int n) {
	int sntmin = INT_MAX;
	bool found = false;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (SoNguyenTo(a[i][j]) && a[i][j] < sntmin) {
				sntmin = a[i][j];
				found = true;
			}
		}
	}

	if (found) {
		printf("So nguyen to nho nhat trong ma tran: %d\n", sntmin);
	}
	else {
		printf("Khong co so nguyen to trong ma tran.\n");
	}
}

void TimMaxMinDongk(int a[][100], int m, int n, int k) {
	if (k < 0 || k >= m) {
		printf("Dong k khong hop le.\n");
		return;
	}

	int somax = a[k][0];
	int somin = a[k][0];
	for (int j = 0; j < n; j++) {
		if (a[k][j] > somax) {
			somax = a[k][j];
		}
		if (a[k][j] < somin) {
			somin = a[k][j];
		}
	}

	printf("Phan tu lon nhat trong dong thu %d: %d\n", k, somax);
	printf("Phan tu nho nhat trong dong thu %d: %d\n", k, somin);
}

void TimMaxMinCotk(int a[][100], int m, int n, int k) {
	if (k < 0 || k >= n) {
		printf("Cot k khong hop le.\n");
		return;
	}

	int somax = a[0][k];
	int somin = a[0][k];
	for (int i = 0; i < m; i++) {
		if (a[i][k] > somax) {
			somax = a[i][k];
		}
		if (a[i][k] < somin) {
			somin = a[i][k];
		}
	}

	printf("Phan tu lon nhat trong cot thu %d: %d\n", k, somax);
	printf("Phan tu nho nhat trong cot thu %d: %d\n", k, somin);
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

	LietKeDongSoHoanThienMax(a, m, n);

	LietKeDongChan(a, m, n);

	GiaTriXuatHienMax(a, m, n);

	SoNguyenToMIN(a, m, n);

	int k;
	printf("Nhap dong k: ");
	scanf("%d", &k);
	TimMaxMinDongk(a, m, n, k);

	int c;
	printf("Nhap cot k: ");
	scanf("%d", &c);
	TimMaxMinCotk(a, m, n, c);

	return 0;
}