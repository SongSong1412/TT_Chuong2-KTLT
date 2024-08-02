////Xử lý mảng 1 chiều 
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//
//// Hàm nhập mảng
//void nhapMang(int *a, int n) {
//	for (int i = 0; i < n; i++) {
//		printf("Nhap phan tu a[%d]: ", i);
//		scanf_s("%d", &a[i]);
//	}
//}
//
//// Hàm xuất mảng
//void xuatMang(int *a, int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//// Hàm tìm giá trị max của mảng
//int timMax(int *a, int n) {
//	int max = a[0];
//	for (int i = 1; i < n; i++) {
//		if (a[i] > max) {
//			max = a[i];
//		}
//	}
//	return max;
//}
//
//// Hàm tìm giá trị min của mảng
//int timMin(int *a, int n) {
//	int min = a[0];
//	for (int i = 1; i < n; i++) {
//		if (a[i] < min) {
//			min = a[i];
//		}
//	}
//	return min;
//}
//
//// Hàm đếm số phần tử chẵn trong mảng
//int demChan(int *a, int n) {
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] % 2 == 0) {
//			count++;
//		}
//	}
//	return count;
//}
//
//// Hàm đếm số phần tử lẻ trong mảng
//int demLe(int *a, int n) {
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] % 2 != 0) {
//			count++;
//		}
//	}
//	return count;
//}
//
//// Hàm tìm kiếm tuyến tính
//int timKiemTuyenTinh(int *a, int n, int x) {
//	for (int i = 0; i < n; i++) {
//		if (a[i] == x) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//// Hàm tìm kiếm nhị phân
//int timKiemNhiPhan(int *a, int left, int right, int x) {
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		if (a[mid] == x) {
//			return mid;
//		}
//		if (a[mid] < x) {
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//	return -1;
//}
//
//// Hàm đếm số lượng phần tử x trong mảng
//int demPhanTuX(int *a, int n, int x) {
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] == x) {
//			count++;
//		}
//	}
//	return count;
//}
//
//// Hàm đếm số phần tử lớn hơn x trong mảng
//int demPhanTuLonHonX(int *a, int n, int x) {
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] > x) {
//			count++;
//		}
//	}
//	return count;
//}
//
//// Hàm tính tổng các phần tử trong mảng
//int tinhTong(int *a, int n) {
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += a[i];
//	}
//	return sum;
//}
//
//// Hàm kiểm tra số nguyên tố
//bool laSoNguyenTo(int n) {
//	if (n < 2) {
//		return false;
//	}
//	for (int i = 2; i <= n / 2; i++) {
//		if (n % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//
//// Hàm xuất các số nguyên tố trong mảng
//void xuatSoNguyenTo(int *a, int n) {
//	for (int i = 0; i < n; i++) {
//		if (laSoNguyenTo(a[i])) {
//			printf("%d ", a[i]);
//		}
//	}
//	printf("\n");
//}
//
//// Hàm kiểm tra số hoàn thiện
//bool laSoHoanThien(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n / 2; i++) {
//		if (n % i == 0) {
//			sum += i;
//		}
//	}
//	return sum == n;
//}
//
//// Hàm xuất các số hoàn thiện trong mảng
//void xuatSoHoanThien(int *a, int n) {
//	for (int i = 0; i < n; i++) {
//		if (laSoHoanThien(a[i])) {
//			printf("%d ", a[i]);
//		}
//	}
//	printf("\n");
//}
//
//// Hàm xuất các phần tử ở vị trí chẵn trong mảng
//void xuatViTriChan(int *a, int n) {
//	for (int i = 0; i < n; i += 2) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//// Hàm xuất các phần tử ở vị trí lẻ trong mảng
//void xuatViTriLe(int *a, int n) {
//	for (int i = 1; i < n; i += 2) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//// Hàm xuất giá trị max/min kèm theo vị trí của giá trị đó trong mảng
//void xuatMaxMinVaViTri(int *a, int n) {
//	int max = timMax(a, n);
//	int min = timMin(a, n);
//	printf("Max: %d, vi tri: ", max);
//	for (int i = 0; i < n; i++) {
//		if (a[i] == max) {
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	printf("Min: %d, vi tri: ", min);
//	for (int i = 0; i < n; i++) {
//		if (a[i] == min) {
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//}
//
//// Hàm ghép 2 dãy số tăng dần thành dãy số tăng dần
//void ghepDayTangDan(int *merged, int *b, int *c, int m, int n) {
//	int i = 0, j = 0, k = 0;
//	while (i < m && j < n) {
//		if (b[i] < c[j]) {
//			merged[k++] = b[i++];
//		}
//		else {
//			merged[k++] = c[j++];
//		}
//	}
//	while (i < m) {
//		merged[k++] = b[i++];
//	}
//	while (j < n) {
//		merged[k++] = c[j++];
//	}
//}
//
//// Hàm sắp xếp tăng dần bằng Interchange Sort cho số nguyên
//void interchangeSortTangInt(int *a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i] > a[j]) {
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//// Hàm sắp xếp giảm dần bằng Interchange Sort cho số nguyên
//void interchangeSortGiamInt(int *a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i] < a[j]) {
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//// Hàm sắp xếp tăng dần bằng Interchange Sort cho số thực
//void interchangeSortTangFloat(float *a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i] > a[j]) {
//				float temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//// Hàm sắp xếp giảm dần bằng Interchange Sort cho số thực
//void interchangeSortGiamFloat(float *a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i] < a[j]) {
//				float temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//// Hàm sắp xếp tăng dần bằng Interchange Sort cho ký tự
//void interchangeSortTangChar(char *a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i] > a[j]) {
//				char temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//// Hàm sắp xếp giảm dần bằng Interchange Sort cho ký tự
//void interchangeSortGiamChar(char *a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i] < a[j]) {
//				char temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//// Hàm sắp xếp tăng dần bằng Interchange Sort cho chuỗi ký tự
//void interchangeSortTangStr(char **a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (strcmp(a[i], a[j]) > 0) {
//				char *temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//// Hàm sắp xếp giảm dần bằng Interchange Sort cho chuỗi ký tự
//void interchangeSortGiamStr(char **a, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (strcmp(a[i], a[j]) < 0) {
//				char *temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//int main() {
//	int n;
//	printf("Nhap so luong phan tu cua mang: ");
//	scanf_s("%d", &n);
//
//	int *a = (int*)malloc(n * sizeof(int));
//	nhapMang(a, n);
//
//	int luaChon;
//	do {
//		printf("\nMenu:\n");
//		printf("1. Nhap/Xuat mang\n");
//		printf("2. Tim max/min cua mang\n");
//		printf("3. Dem so phan tu chan/le trong mang\n");
//		printf("4. Tim kiem phan tu x trong mang\n");
//		printf("5. Dem so phan tu x trong mang\n");
//		printf("6. Dem so phan tu lon hon x trong mang\n");
//		printf("7. Tinh tong cac phan tu trong mang\n");
//		printf("8. Xuat cac so nguyen to trong mang\n");
//		printf("9. Xuat cac so hoan thien trong mang\n");
//		printf("10. Xuat cac phan tu o vi tri chan/le trong mang\n");
//		printf("11. Xuat gia tri max/min kem theo vi tri trong mang\n");
//		printf("12. Ghep 2 day so tang dan\n");
//		printf("13. Sap xep tang/giam theo PP interchange sort (so nguyen/so thuc/ky tu/chuoi ky tu)\n");
//		printf("0. Thoat\n");
//		printf("Lua chon cua ban: ");
//		scanf_s("%d", &luaChon);
//
//		switch (luaChon) {
//		case 1:
//			nhapMang(a, n);
//			xuatMang(a, n);
//			break;
//		case 2:
//			printf("Max: %d\n", timMax(a, n));
//			printf("Min: %d\n", timMin(a, n));
//			break;
//		case 3:
//			printf("So phan tu chan: %d\n", demChan(a, n));
//			printf("So phan tu le: %d\n", demLe(a, n));
//			break;
//		case 4: {
//					int x;
//					printf("Nhap gia tri x: ");
//					scanf_s("%d", &x);
//					printf("Chon kieu tim kiem:\n");
//					printf("1. Tim kiem tuyen tinh\n");
//					printf("2. Tim kiem nhi phan\n");
//					int kieuTimKiem;
//					scanf_s("%d", &kieuTimKiem);
//					int viTri;
//					if (kieuTimKiem == 1) {
//						viTri = timKiemTuyenTinh(a, n, x);
//					}
//					else {
//						viTri = timKiemNhiPhan(a, 0, n - 1, x);
//					}
//					if (viTri != -1) {
//						printf("Tim thay x o vi tri %d\n", viTri);
//					}
//					else {
//						printf("Khong tim thay x\n");
//					}
//					break;
//		}
//		case 5: {
//					int x;
//					printf("Nhap gia tri x: ");
//					scanf_s("%d", &x);
//					printf("So phan tu x trong mang: %d\n", demPhanTuX(a, n, x));
//					break;
//		}
//		case 6: {
//					int x;
//					printf("Nhap gia tri x: ");
//					scanf_s("%d", &x);
//					printf("So phan tu lon hon x trong mang: %d\n", demPhanTuLonHonX(a, n, x));
//					break;
//		}
//		case 7:
//			printf("Tong cac phan tu trong mang: %d\n", tinhTong(a, n));
//			break;
//		case 8:
//			xuatSoNguyenTo(a, n);
//			break;
//		case 9:
//			xuatSoHoanThien(a, n);
//			break;
//		case 10:
//			printf("Cac phan tu o vi tri chan: ");
//			xuatViTriChan(a, n);
//			printf("Cac phan tu o vi tri le: ");
//			xuatViTriLe(a, n);
//			break;
//		case 11:
//			xuatMaxMinVaViTri(a, n);
//			break;
//		case 12: {
//					 int m;
//					 printf("Nhap so luong phan tu cua mang b: ");
//					 scanf_s("%d", &m);
//					 int *b = (int*)malloc(m * sizeof(int));
//					 nhapMang(b, m);
//					 int *c = (int*)malloc(n * sizeof(int));
//					 for (int i = 0; i < n; i++) {
//						 c[i] = a[i];
//					 }
//					 int *merged = (int*)malloc((m + n) * sizeof(int));
//					 ghepDayTangDan(merged, b, c, m, n);
//					 printf("Mang sau khi ghep: ");
//					 xuatMang(merged, m + n);
//					 free(b);
//					 free(c);
//					 free(merged);
//					 break;
//		}
//		case 13: {
//					 printf("Chon kieu du lieu:\n");
//					 printf("1. So nguyen\n");
//					 printf("2. So thuc\n");
//					 printf("3. Ky tu\n");
//					 printf("4. Chuoi ky tu\n");
//					 int kieuDuLieu;
//					 scanf_s("%d", &kieuDuLieu);
//					 printf("Chon kieu sap xep:\n");
//					 printf("1. Tang dan\n");
//					 printf("2. Giam dan\n");
//					 int kieuSapXep;
//					 scanf_s("%d", &kieuSapXep);
//					 if (kieuDuLieu == 1) {
//						 if (kieuSapXep == 1) {
//							 interchangeSortTangInt(a, n);
//						 }
//						 else {
//							 interchangeSortGiamInt(a, n);
//						 }
//					 }
//					 else if (kieuDuLieu == 2) {
//						 float *aFloat = (float*)malloc(n * sizeof(float));
//						 for (int i = 0; i < n; i++) {
//							 aFloat[i] = (float)a[i];
//						 }
//						 if (kieuSapXep == 1) {
//							 interchangeSortTangFloat(aFloat, n);
//						 }
//						 else {
//							 interchangeSortGiamFloat(aFloat, n);
//						 }
//						 for (int i = 0; i < n; i++) {
//							 a[i] = (int)aFloat[i];
//						 }
//						 free(aFloat);
//					 }
//					 else if (kieuDuLieu == 3) {
//						 char *aChar = (char*)malloc(n * sizeof(char));
//						 for (int i = 0; i < n; i++) {
//							 aChar[i] = (char)a[i];
//						 }
//						 if (kieuSapXep == 1) {
//							 interchangeSortTangChar(aChar, n);
//						 }
//						 else {
//							 interchangeSortGiamChar(aChar, n);
//						 }
//						 for (int i = 0; i < n; i++) {
//							 a[i] = (int)aChar[i];
//						 }
//						 free(aChar);
//					 }
//					 else if (kieuDuLieu == 4) {
//						 char **aStr = (char**)malloc(n * sizeof(char*));
//						 for (int i = 0; i < n; i++) {
//							 aStr[i] = (char*)malloc(100 * sizeof(char));
//							 printf(aStr[i], "%d", a[i]);
//						 }
//						 if (kieuSapXep == 1) {
//							 interchangeSortTangStr(aStr, n);
//						 }
//						 else {
//							 interchangeSortGiamStr(aStr, n);
//						 }
//						 for (int i = 0; i < n; i++) {
//							 a[i] = atoi(aStr[i]);
//							 free(aStr[i]);
//						 }
//						 free(aStr);
//					 }
//					 printf("Mang sau khi sap xep: ");
//					 xuatMang(a, n);
//					 break;
//		}
//		}
//	} while (luaChon != 0);
//
//	free(a);
//	return 0;
//}
