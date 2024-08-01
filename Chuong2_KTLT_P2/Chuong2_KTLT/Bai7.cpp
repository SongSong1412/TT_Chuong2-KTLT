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

SinhVien TimSinhVienDiemCaoNhat(SinhVien sv[], int n) {
	SinhVien max = sv[0];
	for (int i = 1; i < n; i++) {
		if (sv[i].DiemTongKet > max.DiemTongKet) {
			max = sv[i];
		}
	}
	return max;
}

SinhVien TimSinhVienDiemThapNhat(SinhVien sv[], int n) {
	SinhVien min = sv[0];
	for (int i = 1; i < n; i++) {
		if (sv[i].DiemTongKet < min.DiemTongKet) {
			min = sv[i];
		}
	}
	return min;
}

int DemSinhVienDat(SinhVien sv[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (sv[i].DiemTongKet >= 4.0) {
			count++;
		}
	}
	return count;
}

float QuyDoiDiem(float diem) {
	if (diem >= 8.5) return 4.0;
	if (diem >= 7.0) return 3.0;
	if (diem >= 5.5) return 2.0;
	if (diem >= 4.0) return 1.0;
	return 0.0;
}


int main() {
	SinhVien sv[50];
	int n;

	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);

	NhapDanhSachSinhVien(sv, n);

	printf("Danh sach sinh vien:\n");
	XuatDanhSachSinhVien(sv, n);

	SinhVien max = TimSinhVienDiemCaoNhat(sv, n);
	SinhVien min = TimSinhVienDiemThapNhat(sv, n);
	printf("Sinh vien co diem tong ket cao nhat: %s - %.2f\n", max.hoten, max.DiemTongKet);
	printf("Sinh vien co diem tong ket thap nhat: %s - %.2f\n", min.hoten, min.DiemTongKet);

	int SoSinhVienDat = DemSinhVienDat(sv, n);
	int SoSinhVienKhongDat = n - SoSinhVienDat;
	printf("So sinh vien dat: %d\n", SoSinhVienDat);
	printf("So sinh vien khong dat: %d\n", SoSinhVienKhongDat);

	printf("Danh sach sinh vien sau khi quy doi diem sang he 4:\n");
	for (int i = 0; i < n; i++) {
		printf("%s - %.2f\n", sv[i].hoten, QuyDoiDiem(sv[i].DiemTongKet));
	}

	return 0;
}