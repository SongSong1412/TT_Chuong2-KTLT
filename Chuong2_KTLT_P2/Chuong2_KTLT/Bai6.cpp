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

PhanSo TimMax(PhanSo ps[], int n) {
	PhanSo max = ps[0];
	for (int i = 1; i < n; i++) {
		if ((float)ps[i].tu / ps[i].mau >(float)max.tu / max.mau) {
			max = ps[i];
		}
	}
	return max;
}

PhanSo TimMin(PhanSo ps[], int n) {
	PhanSo min = ps[0];
	for (int i = 1; i < n; i++) {
		if ((float)ps[i].tu / ps[i].mau < (float)min.tu / min.mau) {
			min = ps[i];
		}
	}
	return min;
}


int main() {
	PhanSo ps[50];
	int n;

	printf("Nhap so luong phan so: ");
	scanf("%d", &n);

	NhapDanhSach(ps, n);
	printf("Danh sach cac phan so: ");
	XuatDanhSach(ps, n);

	PhanSo max = TimMax(ps, n);
	PhanSo min = TimMin(ps, n);
	printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);
	printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);

	return 0;
}
