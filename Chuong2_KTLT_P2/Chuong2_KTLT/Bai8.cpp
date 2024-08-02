//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct {
//	char MaMon[20];
//	char TenMon[50];
//	int SoTinChi;
//	float Diem;
//} MonHoc;
//
//typedef struct {
//	char MaSV[20];
//	char HoTen[50];
//	MonHoc MonHoc[5];
//	float DiemTB;
//} SinhVien;
//
//void NhapMonHoc(MonHoc *mon) {
//	printf("Nhap ma mon: ");
//	scanf("%s", mon->MaMon);
//	printf("Nhap ten mon: ");
//	scanf(" %[^\n]", mon->TenMon);
//	printf("Nhap so tin chi: ");
//	scanf("%d", &mon->SoTinChi);
//	printf("Nhap diem: ");
//	scanf("%f", &mon->Diem);
//}
//
//void NhapSinhVien(SinhVien *sv) {
//	printf("Nhap ma sinh vien: ");
//	scanf("%s", sv->MaSV);
//	printf("Nhap ho ten sinh vien: ");
//	scanf(" %[^\n]", sv->HoTen);
//	float tongDiem = 0;
//	int tongTinChi = 0;
//	for (int i = 0; i < 5; i++) {
//		printf("Nhap thong tin mon hoc thu %d:\n", i + 1);
//		NhapMonHoc(&sv->MonHoc[i]);
//		tongDiem += sv->MonHoc[i].Diem * sv->MonHoc[i].SoTinChi;
//		tongTinChi += sv->MonHoc[i].SoTinChi;
//	}
//	sv->DiemTB = tongDiem / tongTinChi;
//}
//
//void XuatMonHoc(MonHoc mon) {
//	printf("%s\t%s\t%d\t%.2f\n", mon.MaMon, mon.TenMon, mon.SoTinChi, mon.Diem);
//}
//
//void XuatSinhVien(SinhVien sv) {
//	printf("%s\t%s\t%.2f\n", sv.MaSV, sv.HoTen, sv.DiemTB);
//	for (int i = 0; i < 5; i++) {
//		XuatMonHoc(sv.MonHoc[i]);
//	}
//}
//
//void NhapDanhSachSinhVien(SinhVien sv[], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
//		NhapSinhVien(&sv[i]);
//	}
//}
//
//void XuatDanhSachSinhVien(SinhVien sv[], int n) {
//	printf("MSSV\tHo Ten\tDiem TB\n");
//	for (int i = 0; i < n; i++) {
//		XuatSinhVien(sv[i]);
//	}
//}
//
//int TimSinhVienTheoMa(SinhVien sv[], int n, char maSV[]) {
//	for (int i = 0; i < n; i++) {
//		if (strcmp(sv[i].MaSV, maSV) == 0) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//SinhVien TimSinhVienDiemTBCaoNhat(SinhVien sv[], int n) {
//	SinhVien max = sv[0];
//	for (int i = 1; i < n; i++) {
//		if (sv[i].DiemTB > max.DiemTB) {
//			max = sv[i];
//		}
//	}
//	return max;
//}
//
//void ThemSinhVien(SinhVien sv[], int *n, SinhVien newSV) {
//	sv[*n] = newSV;
//	(*n)++;
//}
//
//void XoaSinhVien(SinhVien sv[], int *n, char maSV[]) {
//	int idx = TimSinhVienTheoMa(sv, *n, maSV);
//	if (idx != -1) {
//		for (int i = idx; i < *n - 1; i++) {
//			sv[i] = sv[i + 1];
//		}
//		(*n)--;
//	}
//}
//
//void SapXepTangDan(SinhVien sv[], int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (sv[i].DiemTB > sv[j].DiemTB) {
//				SinhVien temp = sv[i];
//				sv[i] = sv[j];
//				sv[j] = temp;
//			}
//		}
//	}
//}
//
//void SapXepGiamDan(SinhVien sv[], int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (sv[i].DiemTB < sv[j].DiemTB) {
//				SinhVien temp = sv[i];
//				sv[i] = sv[j];
//				sv[j] = temp;
//			}
//		}
//	}
//}
//
//
//void XepLoaiHocTap(SinhVien sv[], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%s - ", sv[i].HoTen);
//		if (sv[i].DiemTB >= 8.5) {
//			printf("Xuat sac\n");
//		}
//		else if (sv[i].DiemTB >= 7.0) {
//			printf("Gioi\n");
//		}
//		else if (sv[i].DiemTB >= 5.5) {
//			printf("Kha\n");
//		}
//		else if (sv[i].DiemTB >= 4.0) {
//			printf("Trung binh\n");
//		}
//		else {
//			printf("Yeu\n");
//		}
//	}
//}
//
//void ThongKeMonHoc(SinhVien sv[], int n) {
//	for (int i = 0; i < n; i++) {
//		int SoMonDat = 0;
//		int SoMonRot = 0;
//		for (int j = 0; j < 5; j++) {
//			if (sv[i].MonHoc[j].Diem >= 4.0) {
//				SoMonDat++;
//			}
//			else {
//				SoMonRot++;
//			}
//		}
//		printf("%s - So mon dat: %d, So mon rot: %d\n", sv[i].HoTen, SoMonDat, SoMonRot);
//	}
//}
//
//int main() {
//	SinhVien sv[50];
//	int n;
//
//	printf("Nhap so luong sinh vien: ");
//	scanf("%d", &n);
//
//	NhapDanhSachSinhVien(sv, n);
//
//	printf("Danh sach sinh vien:\n");
//	XuatDanhSachSinhVien(sv, n);
//
//	char maSV[20];
//	printf("Nhap ma so sinh vien can tim: ");
//	scanf("%s", maSV);
//	int idx = TimSinhVienTheoMa(sv, n, maSV);
//	if (idx != -1) {
//		printf("Thong tin sinh vien tim thay:\n");
//		XuatSinhVien(sv[idx]);
//	}
//	else {
//		printf("Khong tim thay sinh vien\n");
//	}
//
//	SinhVien max = TimSinhVienDiemTBCaoNhat(sv, n);
//	printf("Sinh vien co diem trung binh cao nhat: %s - %.2f\n", max.HoTen, max.DiemTB);
//
//	SinhVien NewSV;
//	printf("Nhap thong tin sinh vien moi:\n");
//	NhapSinhVien(&NewSV);
//	ThemSinhVien(sv, &n, NewSV);
//	printf("Danh sach sinh vien sau khi them:\n");
//	XuatDanhSachSinhVien(sv, n);
//
//	printf("Nhap ma so sinh vien can xoa: ");
//	scanf("%s", maSV);
//	XoaSinhVien(sv, &n, maSV);
//	printf("Danh sach sinh vien sau khi xoa:\n");
//	XuatDanhSachSinhVien(sv, n);
//
//	SapXepTangDan(sv, n);
//	printf("Danh sach sinh vien sap xep tang dan theo diem trung binh:\n");
//	XuatDanhSachSinhVien(sv, n);
//
//	SapXepGiamDan(sv, n);
//	printf("Danh sach sinh vien sap xep giam dan theo diem trung binh:\n");
//	XuatDanhSachSinhVien(sv, n);
//
//	printf("Xep loai hoc tap cua sinh vien:\n");
//	XepLoaiHocTap(sv, n);
//
//	printf("Thong ke mon hoc cua sinh vien:\n");
//	ThongKeMonHoc(sv, n);
//	return 0;
//}