#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int stt;
	char mssv[20];
	char hoten[50];
	float DiemTieuLuan;
	float DiemThiKetThucMon;
	float DiemTongKet;
} SinhVien;

void NhapSinhVien(SinhVien *sv) {
	printf("Nhap so thu tu: ");
	scanf("%d", &sv->stt);
	printf("Nhap ma so sinh vien: ");
	scanf("%s", sv->mssv);
	printf("Nhap ho ten sinh vien: ");
	scanf(" %[^\n]", sv->hoten);
	printf("Nhap diem tieu luan: ");
	scanf("%f", &sv->DiemTieuLuan);
	printf("Nhap diem thi ket thuc mon: ");
	scanf("%f", &sv->DiemThiKetThucMon);
	sv->DiemTongKet = 0.3 * sv->DiemTieuLuan + 0.7 * sv->DiemThiKetThucMon;
}

void NhapDanhSachSinhVien(SinhVien sv[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
		NhapSinhVien(&sv[i]);
	}
}

void XuatSinhVien(SinhVien sv) {
	printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\n", sv.stt, sv.mssv, sv.hoten, sv.DiemTieuLuan, sv.DiemThiKetThucMon, sv.DiemTongKet);
}

void XuatDanhSachSinhVien(SinhVien sv[], int n) {
	printf("STT\tMSSV\tHo Ten\t\tDiem TL\tDiem KTT\tDiem TK\n");
	for (int i = 0; i < n; i++) {
		XuatSinhVien(sv[i]);
	}
}

int main() {
	SinhVien sv[50];
	int n;

	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);

	NhapDanhSachSinhVien(sv, n);

	printf("Danh sach sinh vien:\n");
	XuatDanhSachSinhVien(sv, n);

	return 0;
}