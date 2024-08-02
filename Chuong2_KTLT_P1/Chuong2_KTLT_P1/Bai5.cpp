//Xử lí phân số 
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> 
// Cấu trúc phân số
typedef struct {
	int numerator;   // Tử số
	int denominator; // Mẫu số
} Fraction;

// Hàm tính ước số chung lớn nhất
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Hàm nhập phân số
void inputFraction(Fraction *f) {
	printf("Nhập tử số: ");
	scanf_s("%d", &f->numerator);
	do {
		printf("Nhập mẫu số (khác 0): ");
		scanf_s("%d", &f->denominator);
		if (f->denominator == 0) {
			printf("Mẫu số không thể là 0. Vui lòng nhập lại.\n");
		}
	} while (f->denominator == 0);
}

// Hàm xuất phân số
void printFraction(Fraction f) {
	printf("%d/%d", f.numerator, f.denominator);
}

// Hàm tối giản phân số
void simplifyFraction(Fraction *f) {
	int gcd_value = gcd(abs(f->numerator), abs(f->denominator));
	f->numerator /= gcd_value;
	f->denominator /= gcd_value;
}

// Hàm tính tổng của hai phân số
Fraction addFractions(Fraction a, Fraction b) {
	Fraction result;
	result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	result.denominator = a.denominator * b.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm tính hiệu của hai phân số
Fraction subtractFractions(Fraction a, Fraction b) {
	Fraction result;
	result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	result.denominator = a.denominator * b.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm tính tích của hai phân số
Fraction multiplyFractions(Fraction a, Fraction b) {
	Fraction result;
	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm tính thương của hai phân số
Fraction divideFractions(Fraction a, Fraction b) {
	Fraction result;
	result.numerator = a.numerator * b.denominator;
	result.denominator = a.denominator * b.numerator;
	simplifyFraction(&result);
	return result;
}

int main() {
	Fraction f1, f2;

	// Nhập vào 2 phân số
	printf("Nhập phân số thứ nhất:\n");
	inputFraction(&f1);
	printf("Nhập phân số thứ hai:\n");
	inputFraction(&f2);

	// Tính tổng, hiệu, tích và thương
	Fraction sum = addFractions(f1, f2);
	Fraction diff = subtractFractions(f1, f2);
	Fraction prod = multiplyFractions(f1, f2);
	Fraction quot = divideFractions(f1, f2);

	// Xuất kết quả
	printf("Phân số thứ nhất: ");
	printFraction(f1);
	printf("\n");

	printf("Phân số thứ hai: ");
	printFraction(f2);
	printf("\n");

	printf("Tổng: ");
	printFraction(sum);
	printf("\n");

	printf("Hiệu: ");
	printFraction(diff);
	printf("\n");

	printf("Tích: ");
	printFraction(prod);
	printf("\n");

	printf("Thương: ");
	printFraction(quot);
	printf("\n");
	system("pause");
	return 0;
}
