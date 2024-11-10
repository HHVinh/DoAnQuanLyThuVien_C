#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "khaiBaoHam.h"
#include "quanLySach.h"

// Hàm chuyển đổi ký tự thành chữ thường
void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Khởi tạo và quản lý danh sách các sách
void quanLySach() {
    char dsISBN[MAX_SACH][MAX_ISBN] = {
        "9999999999991", "9999999999992", "9999999999993", "9999999999994", "9999999999995",
        "9999999999996", "9999999999997", "9999999999998", "9999999999999", "9999999999910"
    };
    char dsTenSach[MAX_SACH][MAX_TEN_SACH] = {
        "Truyện Kiều", "Lục Vân Tiên", "Sơn Tinh Thủy Tinh", "Sự Tích Bánh Chưng Bánh Dày",
        "Dế Mèn Phiêu Lưu Ký", "Tấm Cám", "Sách Giáo Khoa Ngữ Văn 6", "Sách Giáo Khoa Ngữ Văn 9",
        "Sách Giáo Khoa Tiếng Việt 1 - Tập 1", "Sách Giáo Khoa Tiếng Việt 3 - Tập 2"
    };
    char dsTacGia[MAX_SACH][MAX_TAC_GIA] = {
        "Nguyễn Du", "Nguyễn Đình Chiểu", "Truyền Thuyết", "Truyền Thuyết", "Tô Hoài",
        "Truyện Dân Gian", "Bộ Giáo Dục", "Bộ Giáo Dục", "Bộ Giáo Dục", "Bộ Giáo Dục"
    };
    char dsTheLoai[MAX_SACH][MAX_THE_LOAI] = {
        "Van Hoc", "Van Hoc", "Truyen Co Tich", "Truyen Co Tich", "Van Hoc Thieu Nhi",
        "Truyen Co Tich", "Sach Giao Khoa", "Sach Giao Khoa", "Sach Giao Khoa", "Sach Giao Khoa"
    };
    char dsNhaXuatBan[MAX_SACH][MAX_NHA_XUAT_BAN] = {
        "NXB Văn Học", "NXB Văn Học", "NXB Kim Đồng", "NXB Kim Đồng", "NXB Kim Đồng",
        "NXB Kim Đồng", "NXB Giáo Dục", "NXB Giáo Dục", "NXB Giáo Dục", "NXB Giáo Dục"
    };
    char dsNamXuatBan[MAX_SACH][5] = {
        "2018", "2019", "2020", "2020", "2017", "2018", "2021", "2021", "2022", "2022"
    };
    int dsGiaSach[MAX_SACH] = {50000, 40000, 30000, 45000, 35000, 25000, 60000, 65000, 30000, 50000};
    int dsSoLuong[MAX_SACH] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int demSach = 10;

    

    hienThiMenuQuanLySach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, dsGiaSach, dsSoLuong, demSach);
}

// Hàm hiển thị menu quản lý sách
void hienThiMenuQuanLySach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                           char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                           int dsGiaSach[], int dsSoLuong[], int demSach) {
    char luaChon;

    do {
        printf("\n=== Quan Ly Sach ===\n");
        printf("a. Xem danh sach sach\n");
        printf("b. Them sach\n");
        printf("c. Chinh sua thong tin sach\n");
        printf("d. Xoa thong tin sach\n");
        printf("e. Tim kiem sach theo ISBN\n");
        printf("f. Tim kiem sach theo ten\n");
        printf("g. Thoat\n");
        printf("Nhap lua chon: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                xemDanhSachSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, dsGiaSach, dsSoLuong, demSach);
                break;
            case 'b':
                themSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, dsGiaSach, dsSoLuong, &demSach);
                break;
            case 'c':
                chinhSuaThongTinSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, dsGiaSach, dsSoLuong, demSach);
                break;
            case 'd':
                xoaSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, dsGiaSach, dsSoLuong, &demSach);
                break;
            case 'e':
                timKiemSachTheoISBN(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, dsGiaSach, dsSoLuong, demSach);
                break;
            case 'f':
                timKiemSachTheoTenSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, dsGiaSach, dsSoLuong, demSach);
                break;
            case 'g':
                printf("Thoat...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 'g');
}

// Hàm xem danh sách các sách
void xemDanhSachSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                     char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                     int dsGiaSach[], int dsSoLuong[], int demSach) {
    printf("\n=== Danh Sach Sach ===\n");
    for (int i = 0; i < demSach; i++) {
        printf("ISBN: %s\n", dsISBN[i]);
        printf("Ten Sach: %s\n", dsTenSach[i]);
        printf("Tac Gia: %s\n", dsTacGia[i]);
        printf("The Loai: %s\n", dsTheLoai[i]);
        printf("Nha Xuat Ban: %s\n", dsNhaXuatBan[i]);
        printf("Nam Xuat Ban: %s\n", dsNamXuatBan[i]);
        printf("Gia: %d\n", dsGiaSach[i]);
        printf("So Luong: %d\n", dsSoLuong[i]);
        printf("--------------------------\n");
    }
}

// Hàm thêm sách
void themSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
              char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
              int dsGiaSach[], int dsSoLuong[], int *demSach) {
    if (*demSach >= MAX_SACH) {
        printf("Khong the them sach, danh sach da day!\n");
        return;
    }

    char isbnMoi[MAX_ISBN];
    printf("Nhap ISBN: ");
    scanf("%s", isbnMoi);

    // Kiểm tra mã ISBN mới có trùng với mã cũ không
    for (int i = 0; i < *demSach; i++) {
        if (strcasecmp(dsISBN[i], isbnMoi) == 0) { // So sánh không phân biệt chữ hoa và chữ thường
            printf("Ma ISBN da ton tai, kiem tra lai hoac cap nhat them so luong.\n");
            return;
        }
    }

    // Nếu không trùng, nhập thông tin sách
    strcpy(dsISBN[*demSach], isbnMoi);
    printf("Nhap Ten Sach: ");
    scanf(" %[^\n]s", dsTenSach[*demSach]);
    printf("Nhap Tac Gia: ");
    scanf(" %[^\n]s", dsTacGia[*demSach]);
    printf("Nhap The Loai: ");
    scanf(" %[^\n]s", dsTheLoai[*demSach]);
    printf("Nhap Nha Xuat Ban: ");
    scanf(" %[^\n]s", dsNhaXuatBan[*demSach]);
    printf("Nhap Nam Xuat Ban: ");
    scanf("%s", dsNamXuatBan[*demSach]);
    printf("Nhap Gia Sach: ");
    scanf("%d", &dsGiaSach[*demSach]);
    printf("Nhap So Luong: ");
    scanf("%d", &dsSoLuong[*demSach]);

    (*demSach)++;
    printf("Da them sach thanh cong!\n");
}


// Hàm chỉnh sửa thông tin sách
void chinhSuaThongTinSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                          char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                          int dsGiaSach[], int dsSoLuong[], int demSach) {
    char isbnTimKiem[MAX_ISBN];
    printf("Nhap ISBN sach muon chinh sua: ");
    scanf("%s", isbnTimKiem);
    int found = 0;
    int index = -1;

    // Tìm kiếm sách với mã ISBN nhập vào
    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbnTimKiem) == 0) {
            found = 1;
            index = i; // Lưu chỉ số sách tìm thấy
            break;
        }
    }

    // Nếu tìm thấy sách
    if (found) {
        printf("Chinh sua thong tin sach:\n");

        // Nhập mã ISBN mới
        char isbnMoi[MAX_ISBN];
        printf("Nhap ISBN moi (hien tai: %s): ", dsISBN[index]);
        scanf("%s", isbnMoi);

        // Kiểm tra mã ISBN mới có trùng với mã nào trong danh sách không
        int isbnTrung = 0;
        for (int i = 0; i < demSach; i++) {
            if (i != index && strcmp(dsISBN[i], isbnMoi) == 0) { // Kiểm tra mã khác mã hien tai
                isbnTrung = 1;
                break;
            }
        }

        if (isbnTrung) {
            printf("Ma ISBN da ton tai, kiem tra lai hoac cap nhat them so luong.\n");
            return; // Thoát khỏi hàm nếu mã ISBN đã tồn tại
        }

        // Nếu không trùng, cập nhật thông tin sách
        strcpy(dsISBN[index], isbnMoi);
        printf("Ten Sach moi (hien tai: %s): ", dsTenSach[index]);
        scanf(" %[^\n]s", dsTenSach[index]);
        printf("Tac Gia moi (hien tai: %s): ", dsTacGia[index]);
        scanf(" %[^\n]s", dsTacGia[index]);
        printf("The Loai moi (hien tai: %s): ", dsTheLoai[index]);
        scanf(" %[^\n]s", dsTheLoai[index]);
        printf("Nha Xuat Ban moi (hien tai: %s): ", dsNhaXuatBan[index]);
        scanf(" %[^\n]s", dsNhaXuatBan[index]);
        printf("Nam Xuat Ban moi (hien tai: %s): ", dsNamXuatBan[index]);
        scanf("%s", dsNamXuatBan[index]);
        printf("Gia Sach moi (hien tai: %d): ", dsGiaSach[index]);
        scanf("%d", &dsGiaSach[index]);
        printf("So Luong moi (hien tai: %d): ", dsSoLuong[index]);
        scanf("%d", &dsSoLuong[index]);
        printf("Da chinh sua thong tin sach thanh cong!\n");
    } else {
        printf("Khong tim thay sach voi ISBN %s.\n", isbnTimKiem);
    }
}

// Hàm xóa sách
void xoaSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
             char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
             int dsGiaSach[], int dsSoLuong[], int *demSach) {
    char isbnTimKiem[MAX_ISBN];
    printf("Nhap ISBN sach muon xoa: ");
    scanf("%s", isbnTimKiem);
    int found = 0;

    for (int i = 0; i < *demSach; i++) {
        if (strcmp(dsISBN[i], isbnTimKiem) == 0) {
            found = 1;
            for (int j = i; j < *demSach - 1; j++) {
                strcpy(dsISBN[j], dsISBN[j + 1]);
                strcpy(dsTenSach[j], dsTenSach[j + 1]);
                strcpy(dsTacGia[j], dsTacGia[j + 1]);
                strcpy(dsTheLoai[j], dsTheLoai[j + 1]);
                strcpy(dsNhaXuatBan[j], dsNhaXuatBan[j + 1]);
                strcpy(dsNamXuatBan[j], dsNamXuatBan[j + 1]);
                dsGiaSach[j] = dsGiaSach[j + 1];
                dsSoLuong[j] = dsSoLuong[j + 1];
            }
            (*demSach)--;  // Giảm số lượng sách
            printf("Da xoa sach voi ISBN %s thanh cong!\n", isbnTimKiem);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ISBN %s.\n", isbnTimKiem);
    }
}

// Hàm tìm sách theo mã ISBN
void timKiemSachTheoISBN(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                         char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                         int dsGiaSach[], int dsSoLuong[], int demSach) {
    char isbnTimKiem[MAX_ISBN];
    printf("Nhap ISBN sach muon tim: ");
    scanf("%s", isbnTimKiem);
    int found = 0;

    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbnTimKiem) == 0) {
            found = 1;
            printf("Tim thay sach:\n");
            printf("ISBN: %s\n", dsISBN[i]);
            printf("Ten Sach: %s\n", dsTenSach[i]);
            printf("Tac Gia: %s\n", dsTacGia[i]);
            printf("The Loai: %s\n", dsTheLoai[i]);
            printf("Nha Xuat Ban: %s\n", dsNhaXuatBan[i]);
            printf("Nam Xuat Ban: %s\n", dsNamXuatBan[i]);
            printf("Gia: %d\n", dsGiaSach[i]);
            printf("So Luong: %d\n", dsSoLuong[i]);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ISBN %s.\n", isbnTimKiem);
    }
}

// Hàm tìm sách theo tên
void timKiemSachTheoTenSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                             char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                             int dsGiaSach[], int dsSoLuong[], int demSach) {
    char tenSachTimKiem[MAX_TEN_SACH];
    printf("Nhap Ten Sach muon tim: ");
    scanf(" %[^\n]s", tenSachTimKiem);
    int found = 0;

    for (int i = 0; i < demSach; i++) {
        if (strcasecmp(dsTenSach[i], tenSachTimKiem) == 0) {
            found = 1;
            printf("Tim thay sach:\n");
            printf("ISBN: %s\n", dsISBN[i]);
            printf("Ten Sach: %s\n", dsTenSach[i]);
            printf("Tac Gia: %s\n", dsTacGia[i]);
            printf("The Loai: %s\n", dsTheLoai[i]);
            printf("Nha Xuat Ban: %s\n", dsNhaXuatBan[i]);
            printf("Nam Xuat Ban: %s\n", dsNamXuatBan[i]);
            printf("Gia: %d\n", dsGiaSach[i]);
            printf("So Luong: %d\n", dsSoLuong[i]);
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi Ten Sach %s.\n", tenSachTimKiem);
    }
}


