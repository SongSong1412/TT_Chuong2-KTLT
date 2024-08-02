#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SapXepTang(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

void SapXepGiam(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

void TaoMangNgauNhien(int a[][100], int m, int n) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100; 
		}
	}
}

void SapXepChanLe(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			SapXepTang(a[i], n);
		}
		else {
			SapXepGiam(a[i], n);
		}
	}
}

void SapXepCotChanLe(int a[][100], int m, int n) {
	for (int j = 0; j < n; j++) {
		int col[100];
		for (int i = 0; i < m; i++) {
			col[i] = a[i][j];
		}
		if (j % 2 == 0) {
			SapXepTang(col, m);
		}
		else {
			SapXepGiam(col, m);
		}
		for (int i = 0; i < m; i++) {
			a[i][j] = col[i];
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

	printf("Ma tran ngau nhien:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	SapXepChanLe(a, m, n);
	printf("Ma tran sau khi sap xep dong chan tang dong le giam:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	TaoMangNgauNhien(a, m, n);
	SapXepCotChanLe(a, m, n);
	printf("Ma tran sau khi sap xep cot chan tang cot le giam:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}