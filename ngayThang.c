#include <stdio.h>
#include "ngayThang.h"

// Hàm xác định số ngày trong một tháng của một năm nhất định
int soNgayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))) {
        return 29;
    }
    return ngayTrongThang[thang - 1];
}

// Hàm tính ngày trả dự kiến sau 7 ngày từ ngày mượn
void tinhNgayTraDuKien(char *ngayMuon, char *ngayTraDuKien) {
    int nam, thang, ngay;
    sscanf(ngayMuon, "%d/%d/%d", &ngay, &thang, &nam); // Tách năm, tháng, ngày từ chuỗi ngayMuon

    ngay += 7; // Thêm 7 ngày vào ngày mượn

    // Điều chỉnh ngày, tháng, năm nếu vượt quá số ngày trong tháng
    while (ngay > soNgayTrongThang(thang, nam)) {
        ngay -= soNgayTrongThang(thang, nam); // Trừ số ngày của tháng
        thang++; // Chuyển sang tháng tiếp theo
        
        if (thang > 12) { // Nếu tháng vượt quá 12, tăng năm và đặt lại tháng
            thang = 1;
            nam++;
        }
    }

    sprintf(ngayTraDuKien, "%02d/%02d/%04d", ngay, thang, nam);
}

// Hàm tính số ngày chênh lệch giữa hai ngày
int tinhChenhLechNgay(char *ngayTraThucTe, char *ngayTraDuKien) {
    int nam1, thang1, ngay1;
    int nam2, thang2, ngay2;
    sscanf(ngayTraThucTe, "%d/%d/%d", &ngay1, &thang1, &nam1);
    sscanf(ngayTraDuKien, "%d/%d/%d", &ngay2, &thang2, &nam2);

    int ngayChenhLech = 0;
    while (nam1 > nam2 || thang1 > thang2 || ngay1 > ngay2) {
        ngay2++;
        if (ngay2 > soNgayTrongThang(thang2, nam2)) {
            ngay2 = 1;
            thang2++;
            if (thang2 > 12) {
                thang2 = 1;
                nam2++;
            }
        }
        ngayChenhLech++;
    }

    return ngayChenhLech;
}
