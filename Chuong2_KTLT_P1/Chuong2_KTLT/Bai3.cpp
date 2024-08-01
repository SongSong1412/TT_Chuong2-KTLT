//Các hàm kiểm tra xử lí mảng 1 chiều
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
//Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
	if (num <= 1) return false;
	if (num <= 3) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;
	for (int i = 5; i * i <= num; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) return false;
	}
	return true;
}

//Hàm kiểm tra tất cả chữ số là số lẻ
bool allDigitsOdd(int num) {
	if (num < 0) num = -num; // Xử lý số âm
	while (num > 0) {
		int digit = num % 10;
		if (digit % 2 == 0) return false;
		num /= 10;
	}
	return true;
}

//Hàm kiểm tra mảng có toàn số chẵn không
bool allEven(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) return false;
	}
	return true;
}

//Hàm kiểm tra mảng có phải là dãy số chẵn lẻ xen kẻ không
bool isAlternatingEvenOdd(int arr[], int size) {
	if (size < 2) return true; // Mảng có ít hơn 2 phần tử luôn được coi là chẵn lẻ xen kẻ
	for (int i = 1; i < size; i++) {
		if ((arr[i - 1] % 2 == 0 && arr[i] % 2 == 0) || (arr[i - 1] % 2 != 0 && arr[i] % 2 != 0)) {
			return false;
		}
	}
	return true;
}

int main() {
	int arr[] = { 10, 3, 7, 6, 2, 5, 16, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//1. Đếm số phần tử có giá trị là số nguyên tố
		int primeCount = 0;
	for (int i = 0; i < size; i++) {
		if (isPrime(arr[i])) {
			primeCount++;
		}
	}
	printf("Số lượng phần tử nguyên tố: %d\n", primeCount);

	//2. Xuất các phần tử mà từng chữ số của nó là số lẻ
		printf("Các phần tử có tất cả chữ số là số lẻ: ");
	for (int i = 0; i < size; i++) {
		if (allDigitsOdd(arr[i])) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");

	//3. Tìm vị trí số lớn nhất(cuối cùng)
		int max = arr[0];
	int maxPos = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			maxPos = i;
		}
	}
	printf("Vị trí của số lớn nhất (cuối cùng): %d\n", maxPos);

	//4. Kiểm tra mảng có toàn là số chẵn không
	if (allEven(arr, size)) {
		printf("Mảng toàn số chẵn.\n");
	}
	else {
		printf("Mảng không toàn số chẵn.\n");
	}

	//5. Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẻ không
	if (isAlternatingEvenOdd(arr, size)) {
		printf("Mảng là dãy số chẵn lẻ xen kẻ.\n");
	}
	else {
		printf("Mảng không phải là dãy số chẵn lẻ xen kẻ.\n");
	}
	system("pause");
	return 0;
}
