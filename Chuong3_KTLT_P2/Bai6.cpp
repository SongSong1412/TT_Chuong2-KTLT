#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CatChuoiHoTen(const char *hoTen, char **hoLot, char **ten) {
	int len = strlen(hoTen);
	int i;

	// Tìm vị trí khoảng trắng cuối cùng trong chuỗi
	for (i = len - 1; i >= 0; i--) {
		if (hoTen[i] == ' ') {
			break;
		}
	}

	// Cấp phát bộ nhớ cho chuỗi họ lót và tên
	*hoLot = (char *)malloc((i + 1) * sizeof(char));
	*ten = (char *)malloc((len - i) * sizeof(char));

	// Sao chép chuỗi họ lót và tên
	strncpy(*hoLot, hoTen, i);
	(*hoLot)[i] = '\0';
	strcpy(*ten, hoTen + i + 1);
}

int main() {
	char hoTen[100];
	char *hoLot, *ten;

	printf("Nhap ho ten cua ban: ");
	fgets(hoTen, sizeof(hoTen), stdin);

	// Xóa ký tự xuống dòng cuối chuỗi do fgets thêm vào
	size_t len = strlen(hoTen);
	if (len > 0 && hoTen[len - 1] == '\n') {
		hoTen[len - 1] = '\0';
	}

	CatChuoiHoTen(hoTen, &hoLot, &ten);

	printf("Ho lot: %s\n", hoLot);
	printf("Ten: %s\n", ten);

	free(hoLot);
	free(ten);

	return 0;
}
