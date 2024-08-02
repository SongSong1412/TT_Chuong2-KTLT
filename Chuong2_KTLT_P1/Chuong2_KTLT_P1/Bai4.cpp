////Kiểm tra mảng
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//using namespace std;
//
////Hàm kiểm tra số nguyên tố
//bool isPrime(int num) {
//	if (num <= 1) return false;
//	if (num <= 3) return true;
//	if (num % 2 == 0 || num % 3 == 0) return false;
//	for (int i = 5; i * i <= num; i += 6) {
//		if (num % i == 0 || num % (i + 2) == 0) return false;
//	}
//	return true;
//}
//
////Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố không
//bool allPrime(const vector<int>& arr) {
//	for (int num : arr) {
//		if (!isPrime(num)) return false;
//	}
//	return true;
//}
//
////Hàm kiểm tra mảng có đối xứng không
//bool isSymmetric(const vector<int>& arr) {
//	int size = arr.size();
//	for (int i = 0; i < size / 2; i++) {
//		if (arr[i] != arr[size - i - 1]) return false;
//	}
//	return true;
//}
//
////Hàm kiểm tra mảng có tăng dần không
//bool isIncreasing(const vector<int>& arr) {
//	int size = arr.size();
//	for (int i = 1; i < size; i++) {
//		if (arr[i] < arr[i - 1]) return false;
//	}
//	return true;
//}
//
////Hàm kiểm tra mảng có giảm dần không
//bool isDecreasing(const vector<int>& arr) {
//	int size = arr.size();
//	for (int i = 1; i < size; i++) {
//		if (arr[i] > arr[i - 1]) return false;
//	}
//	return true;
//}
//
////hàm kiểm tra mảng có tăng dần, giảm dần hoặc không tăng không giảm
//void checkArray(const vector<int>& arr) {
//	if (allPrime(arr)) {
//		cout << "Mảng chứa toàn bộ số nguyên tố." << endl;
//	}
//	else {
//		cout << "Mảng không chứa toàn bộ số nguyên tố." << endl;
//	}
//
//	if (isSymmetric(arr)) {
//		cout << "Mảng là đối xứng." << endl;
//	}
//	else {
//		cout << "Mảng không phải là đối xứng." << endl;
//	}
//
//	if (isIncreasing(arr)) {
//		cout << "Mảng tăng dần." << endl;
//	}
//	else if (isDecreasing(arr)) {
//		cout << "Mảng giảm dần." << endl;
//	}
//	else {
//		cout << "Mảng không tăng không giảm." << endl;
//	}
//}
//
//int main() {
//	int size = 10; // Kích thước của mảng
//	vector<int> arr(size);
//
//	//Khởi tạo bộ sinh số ngẫu nhiên
//		srand(static_cast<unsigned>(time(0)));
//
//	//Tạo mảng ngẫu nhiên với giá trị từ 1 đến 100
//	for (int i = 0; i < size; i++) {
//		arr[i] = rand() % 100 + 1; // Số ngẫu nhiên từ 1 đến 100
//	}
//
//	//In mảng ra màn hình
//		cout << "Mảng ngẫu nhiên:" << endl;
//	for (int num : arr) {
//		cout << num << " ";
//	}
//	cout << endl;
//
//	//Kiểm tra mảng
//		checkArray(arr);
//
//	//Giữ cửa sổ CMD mở cho đến khi nhấn một phím
//		system("pause");
//
//	return 0;
//}
