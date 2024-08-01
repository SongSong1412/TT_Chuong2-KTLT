#include <stdio.h>

typedef struct {
	int tu;
	int mau;
} PhanSo;

void NhapDanhSach(PhanSo ps[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap tu va mau cua phan so thu %d: ", i + 1);
		scanf("%d%d", &ps[i].tu, &ps[i].mau);
	}
}

void XuatDanhSach(PhanSo ps[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d/%d ", ps[i].tu, ps[i].mau);
	}
	printf("\n");
}


int main() {
	PhanSo ps[50];
	int n;

	printf("Nhap so luong phan so: ");
	scanf("%d", &n);

	NhapDanhSach(ps, n);
	printf("Danh sach cac phan so: ");
	XuatDanhSach(ps, n);

	return 0;
}
