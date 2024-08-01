//Sử dụng giải thuật Quick Sort
#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high]; // Chọn phần tử cuối cùng làm pivot
	int i = (low - 1); // Vị trí của phần tử nhỏ hơn

	for (int j = low; j < high; j++) {
		// Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		// Chia mảng thành hai phần
		int pi = partition(arr, low, high);

		// Sắp xếp các phần tử trước và sau phân vùng
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = { 10, 3, 7, 6, 2, 5, 16, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Dãy số trước khi sắp xếp: \n");
	printArray(arr, n);

	quickSort(arr, 0, n - 1);

	printf("Dãy số sau khi sắp xếp: \n");
	printArray(arr, n);

	system("pause"); // Giữ cửa sổ mở cho đến khi bạn nhấn một phím
	return 0;
}
