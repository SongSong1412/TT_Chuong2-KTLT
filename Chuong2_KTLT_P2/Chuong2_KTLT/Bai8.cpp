#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char MaMon[20];
	char TenMon[50];
	int SoTinChi;
	float Diem;
} MonHoc;

typedef struct {
	char MaSV[20];
	char HoTen[50];
	MonHoc MonHoc[5];
	float DiemTB;
} SinhVien;

void NhapMonHoc(MonHoc *mon) {
	printf("Nhap ma mon: ");
	scanf("%s", mon->MaMon);
	printf("Nhap ten mon: ");
	scanf(" %[^\n]", mon->TenMon);
	printf("Nhap so tin chi: ");
	scanf("%d", &mon->SoTinChi);
	printf("Nhap diem: ");
	scanf("%f", &mon->Diem);
}

void NhapSinhVien(SinhVien *sv) {
	printf("Nhap ma sinh vien: ");
	scanf("%s", sv->MaSV);
	printf("Nhap ho ten sinh vien: ");
	scanf(" %[^\n]", sv->HoTen);
	float tongDiem = 0;
	int tongTinChi = 0;
	for (int i = 0; i < 5; i++) {
		printf("Nhap thong tin mon hoc thu %d:\n", i + 1);
		NhapMonHoc(&sv->MonHoc[i]);
		tongDiem += sv->MonHoc[i].Diem * sv->MonHoc[i].SoTinChi;
		tongTinChi += sv->MonHoc[i].SoTinChi;
	}
	sv->DiemTB = tongDiem / tongTinChi;
}

void XuatMonHoc(MonHoc mon) {
	printf("%s\t%s\t%d\t%.2f\n", mon.MaMon, mon.TenMon, mon.SoTinChi, mon.Diem);
}

void XuatSinhVien(SinhVien sv) {
	printf("%s\t%s\t%.2f\n", sv.MaSV, sv.HoTen, sv.DiemTB);
	for (int i = 0; i < 5; i++) {
		XuatMonHoc(sv.MonHoc[i]);
	}
}

void NhapDanhSachSinhVien(SinhVien sv[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
		NhapSinhVien(&sv[i]);
	}
}

void XuatDanhSachSinhVien(SinhVien sv[], int n) {
	printf("MSSV\tHo Ten\tDiem TB\n");
	for (int i = 0; i < n; i++) {
		XuatSinhVien(sv[i]);
	}
}

int TimSinhVienTheoMa(SinhVien sv[], int n, char maSV[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(sv[i].MaSV, maSV) == 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	SinhVien sv[50];
	int n;

	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);

	NhapDanhSachSinhVien(sv, n);

	printf("Danh sach sinh vien:\n");
	XuatDanhSachSinhVien(sv, n);

	char maSV[20];
	printf("Nhap ma so sinh vien can tim: ");
	scanf("%s", maSV);
	int idx = TimSinhVienTheoMa(sv, n, maSV);
	if (idx != -1) {
		printf("Thong tin sinh vien tim thay:\n");
		XuatSinhVien(sv[idx]);
	}
	else {
		printf("Khong tim thay sinh vien\n");
	}
	return 0;
}