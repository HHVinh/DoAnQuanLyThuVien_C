#include <stdio.h>
#include <ctype.h>
#include "khaiBaoHam.h"
#include "menu.h"
#include "quanLyDocGia.h"

void quanLyDocGia() {
    hienThiMenuQuanLyDocGia();
}

// Hàm hiển thị menu quản lý độc giả
void hienThiMenuQuanLyDocGia() {
    char luaChon;
    char dsMaDocGia[MAX_DOC_GIA][5] = {"0001", "0002", "0003", "0004", "0005", "0006"};
    char dsTenDocGia[MAX_DOC_GIA][50] = {"Nguyễn Văn A", "Nguyễn Văn B", "Nguyễn Văn C", "Trần Thị D", "Trần Thị E", "Trần Thị F"};
    char dsCCCD[MAX_DOC_GIA][13] = {"111111111111", "111111111112", "111111111113", "111111111114", "111111111115", "111111111116"};
    char dsNgaySinh[MAX_DOC_GIA][11] = {"1/1/1990", "1/1/1991", "1/1/1992", "1/1/1993", "1/1/1994", "1/1/1995"};
    char dsGioiTinh[MAX_DOC_GIA][10] = {"Nam", "Nam", "Nam", "Nữ", "Nữ", "Nữ"};
    char dsEmail[MAX_DOC_GIA][50] = {"nguyenvana@gmail.com", "nguyenvanb@gmail.com", "nguyenvanc@gmail.com", "tranthid@gmail.com", "tranthie@gmail.com", "tranthif@gmail.com"};
    char dsDiaChi[MAX_DOC_GIA][100] = {"Hồ Chí Minh", "Tiền Giang", "Đà Lạt", "Long An", "Nghệ An", "Hà Nội"};
    char dsNgayLapThe[MAX_DOC_GIA][11] = {"1/1/2024", "1/5/2024", "15/8/2024", "1/10/2022", "15/10/2023", "10/10/2024"};
    char dsNgayHetHan[MAX_DOC_GIA][11] = {"1/1/2028", "1/5/2028", "15/8/2028", "1/10/2026", "15/10/2027", "10/10/2028"};
    int demDocGia = 6;

    do {
        printf("\n=== Quan Ly Doc Gia ===\n");
        printf("a. Xem danh sach doc gia\n");
        printf("b. Them doc gia\n");
        printf("c. Chinh sua doc gia\n");
        printf("d. Xoa doc gia\n");
        printf("e. Tim kiem doc gia theo ma doc gia hoac CCCD\n");
        printf("f. Tim kiem doc gia theo ho ten\n");
        printf("g. Thoat\n");
        printf("Nhap lua chon: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                xemDanhSachDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'b':
                themDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, &demDocGia);
                break;
            case 'c':
                chinhSuaDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'd':
                xoaDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, &demDocGia);
                break;
            case 'e':
                timKiemTheoMaDocGiaHoacCCCD(dsCCCD, dsMaDocGia, dsTenDocGia, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'f':
                timKiemTheoHoTen(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'g':
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (luaChon != 'g');
}
int getDemDocGia(int demDocGia) {
    return demDocGia; // Trả về giá trị của demDocGia
}

// Hàm xem danh sách độc giả
void xemDanhSachDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                        char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                        char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                        int demDocGia) {
    if (demDocGia == 0) {
        printf("Danh sach doc gia trong.\n");
    } else {
        printf("Danh sach doc gia:\n\n");
        for (int i = 0; i < demDocGia; i++) {
            printf("%d. Ma doc gia: %s, Ten: %s, CCCD: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n\n",
                  i +1, dsMaDocGia[i], dsTenDocGia[i], dsCCCD[i], dsNgaySinh[i], dsGioiTinh[i], dsEmail[i], dsDiaChi[i], dsNgayLapThe[i], dsNgayHetHan[i]);
        }
    }
}

// Hàm thêm độc giả
void themDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13], 
                char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50], 
                char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11], 
                int *demDocGia) {
    if (*demDocGia >= MAX_DOC_GIA) {
        printf("Danh sach doc gia da day, khong the them!\n");
        return;
    }

    char maDocGia[5];
    int maTrung;  // Biến để kiểm tra trùng mã

    do {
        maTrung = 0;  // Khởi tạo lại biến kiểm tra
        printf("Nhap ma doc gia: ");
        scanf("%s", maDocGia);

        // Kiểm tra mã độc giả đã tồn tại chưa
        for (int i = 0; i < *demDocGia; i++) {
            if (strcmp(dsMaDocGia[i], maDocGia) == 0) {
                maTrung = 1;  // Mã độc giả đã tồn tại
                printf("Ma doc gia da ton tai. Vui long nhap ma khac!\n");
                break;  // Thoát khỏi vòng lặp kiểm tra
            }
        }
    } while (maTrung);  // Tiếp tục yêu cầu nhập lại nếu mã trùng

    // Lưu mã độc giả hợp lệ vào danh sách
    strcpy(dsMaDocGia[*demDocGia], maDocGia);

    // Nhập thông tin còn lại
    printf("Nhap ten doc gia: ");
    scanf(" %[^\n]", dsTenDocGia[*demDocGia]);
    
    printf("Nhap CCCD: ");
    scanf("%s", dsCCCD[*demDocGia]);
    
    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    scanf("%s", dsNgaySinh[*demDocGia]);
    
    printf("Nhap gioi tinh: ");
    scanf("%s", dsGioiTinh[*demDocGia]);
    
    printf("Nhap email: ");
    scanf("%s", dsEmail[*demDocGia]);
    
    printf("Nhap dia chi: ");
    scanf(" %[^\n]", dsDiaChi[*demDocGia]);
    
    printf("Nhap ngay lap the (dd/mm/yyyy): ");
    scanf("%s", dsNgayLapThe[*demDocGia]);

    // Tính ngày hết hạn
    int ngay, thang, nam;
    sscanf(dsNgayLapThe[*demDocGia], "%d/%d/%d", &ngay, &thang, &nam);

    // Tính ngày hết hạn sau 48 tháng
    thang += 48;
    nam += thang / 12;  // Tăng năm nếu tháng vượt quá 12
    thang %= 12;        // Giữ lại tháng trong khoảng 0-11

    // Nếu tháng là 0, đặt tháng là 12 và giảm năm
    if (thang == 0) {
        thang = 12;
        nam--;
    }

    // Định dạng lại ngày hết hạn
    sprintf(dsNgayHetHan[*demDocGia], "%02d/%02d/%d", ngay, thang, nam);

    (*demDocGia)++;
    printf("Them doc gia thanh cong!\n");
}

// Hàm chỉnh sửa thông tin độc giả
void chinhSuaDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                     char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                     char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                     int demDocGia) {
    char maDocGia[5];
    char maDocGiaMoi[5] = "";  // Khởi tạo biến để tránh lỗi
    int validInput;  // Biến để kiểm tra nhập hợp lệ
    int maTrung = 0;  // Khởi tạo lại biến kiểm tra

    printf("Nhap ma doc gia can chinh sua: ");
    scanf("%s", maDocGia);

    for (int i = 0; i < demDocGia; i++) {
        if (strcmp(dsMaDocGia[i], maDocGia) == 0) {
            printf("Chinh sua doc gia: \n");
            
            // Sửa mã độc giả
            do {
                printf("Nhap ma doc gia moi (hien tai: %s): ", dsMaDocGia[i]);
                scanf("%s", maDocGiaMoi);

                // Kiểm tra mã độc giả mới có trùng hay không
                for (int j = 0; j < demDocGia; j++) {
                    if (strcmp(dsMaDocGia[j], maDocGiaMoi) == 0 && j != i) {
                        maTrung = 1;  // Mã độc giả mới trùng với một mã độc giả khác
                        break;
                    }
                }

                // Kiểm tra điều kiện
                if (maTrung) {
                    printf("Ma doc gia moi da ton tai. Vui long nhap ma khac hoac ma cu!\n");
                    printf("Nhap ma doc gia moi (hien tai: %s): ", dsMaDocGia[i]);
                    scanf("%s", maDocGiaMoi);
                }
                if (strlen(maDocGiaMoi) == 0) {
                    printf("Ma doc gia moi khong duoc rong. Vui long nhap lai!\n");
                    printf("Nhap ma doc gia moi (hien tai: %s): ", dsMaDocGia[i]);
                    scanf("%s", maDocGiaMoi);
                }


            } while (strlen(maDocGiaMoi) == 0);  // Điều kiện dừng

            // Cập nhật mã độc giả
            strcpy(dsMaDocGia[i], maDocGiaMoi);

            printf("Nhap ten moi (hien tai: %s): ", dsTenDocGia[i]);
            scanf(" %[^\n]", dsTenDocGia[i]);

            printf("Nhap ngay sinh moi (dd/mm/yyyy) (hien tai: %s): ", dsNgaySinh[i]);
            scanf("%s", dsNgaySinh[i]);

            printf("Nhap gioi tinh moi (hien tai: %s): ", dsGioiTinh[i]);
            scanf("%s", dsGioiTinh[i]);

            printf("Nhap email moi (hien tai: %s): ", dsEmail[i]);
            scanf("%s", dsEmail[i]);

            printf("Nhap dia chi moi (hien tai: %s): ", dsDiaChi[i]);
            scanf(" %[^\n]", dsDiaChi[i]);

            printf("Nhap ngay lap the moi (hien tai: %s): ", dsNgayLapThe[i]);
            scanf("%s", dsNgayLapThe[i]);

            // Cập nhật ngày hết hạn
            int ngay, thang, nam;
            sscanf(dsNgayLapThe[i], "%d/%d/%d", &ngay, &thang, &nam);

            // Tính ngày hết hạn sau 48 tháng
            thang += 48;
            nam += thang / 12;  // Tăng năm nếu tháng vượt quá 12
            thang %= 12;        // Giữ lại tháng trong khoảng 0-11

            // Nếu tháng là 0, đặt tháng là 12 và giảm năm
            if (thang == 0) {
                thang = 12;
                nam--;
            }

            // Định dạng lại ngày hết hạn
            sprintf(dsNgayHetHan[i], "%02d/%02d/%d", ngay, thang, nam);

            printf("Chinh sua doc gia thanh cong!\n");
            return;
        }
    }
    printf("Ma doc gia khong ton tai!\n");
}

// Hàm xóa độc giả
void xoaDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                int *demDocGia) {
    char maDocGia[5];
    printf("Nhap ma doc gia can xoa: ");
    scanf("%s", maDocGia);

    for (int i = 0; i < *demDocGia; i++) {
        if (strcmp(dsMaDocGia[i], maDocGia) == 0) {
            for (int j = i; j < *demDocGia - 1; j++) {
                strcpy(dsMaDocGia[j], dsMaDocGia[j + 1]);
                strcpy(dsTenDocGia[j], dsTenDocGia[j + 1]);
                strcpy(dsCCCD[j], dsCCCD[j + 1]);
                strcpy(dsNgaySinh[j], dsNgaySinh[j + 1]);
                strcpy(dsGioiTinh[j], dsGioiTinh[j + 1]);
                strcpy(dsEmail[j], dsEmail[j + 1]);
                strcpy(dsDiaChi[j], dsDiaChi[j + 1]);
                strcpy(dsNgayLapThe[j], dsNgayLapThe[j + 1]);
                strcpy(dsNgayHetHan[j], dsNgayHetHan[j + 1]);
            }
            (*demDocGia)--;
            printf("Xoa doc gia thanh cong!\n");
            return;
        }
    }
    printf("Ma doc gia khong ton tai!\n");
}

// Hàm tìm kiếm độc giả theo mã độc giả hoặc cccd
void timKiemTheoMaDocGiaHoacCCCD(char dsCCCD[][13], char dsMaDocGia[][5], char dsTenDocGia[][50],
                      char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                      char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                      int demDocGia) {
    char input[13];  // Mảng nhập vào đủ lớn để chứa CCCD (12 ký tự + 1 ký tự kết thúc chuỗi)
    printf("Nhap ma doc gia hoac CCCD can tim: ");
    scanf("%s", input);

    int found = 0;

    // Kiểm tra độ dài của chuỗi nhập vào
    int inputLength = strlen(input);

    // Nếu nhập vào là mã độc giả (4 ký tự)
    if (inputLength == 4) {
        for (int i = 0; i < demDocGia; i++) {
            if (strcmp(dsMaDocGia[i], input) == 0) {
                printf("Tim thay doc gia:\n");
                printf("Ma doc gia: %s, Ten: %s, CCCD: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                       dsMaDocGia[i], dsTenDocGia[i], dsCCCD[i], dsNgaySinh[i], dsGioiTinh[i], dsEmail[i], dsDiaChi[i], dsNgayLapThe[i], dsNgayHetHan[i]);
                found = 1;
                break;
            }
        }
    }
    // Nếu nhập vào là CCCD (13 ký tự)
    else if (inputLength == 12) {
        for (int i = 0; i < demDocGia; i++) {
            if (strcmp(dsCCCD[i], input) == 0) {
                printf("Tim thay doc gia:\n");
                printf("Ma doc gia: %s, Ten: %s, CCCD: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                       dsMaDocGia[i], dsTenDocGia[i], dsCCCD[i], dsNgaySinh[i], dsGioiTinh[i], dsEmail[i], dsDiaChi[i], dsNgayLapThe[i], dsNgayHetHan[i]);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia co ma doc gia: %s hoac CCCD: %s\n", input, input);
    }
}

// Hàm chuyển chuỗi thành chữ thường
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);  // Chuyển từng ký tự thành chữ thường
    }
}

// Hàm tim kiem theo ho ten
void timKiemTheoHoTen(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                       char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                       char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                       int demDocGia) {
    char ten[50];
    printf("Nhap ten doc gia can tim: ");
    scanf(" %[^\n]", ten);

    // Chuyển tên nhập vào thành chữ thường để so sánh không phân biệt hoa thường
    toLowerCase(ten);

    int found = 0;

    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < demDocGia; i++) {
        char tenDocGia[50];
        strcpy(tenDocGia, dsTenDocGia[i]);

        // Chuyển tên trong danh sách thành chữ thường để so sánh
        toLowerCase(tenDocGia);

        if (strstr(tenDocGia, ten) != NULL) { // Kiểm tra xem tên có chứa chuỗi tìm kiếm không
            printf("Ma doc gia: %s, Ten: %s, CCCD: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                   dsMaDocGia[i], dsTenDocGia[i], dsCCCD[i], dsNgaySinh[i], dsGioiTinh[i], dsEmail[i], dsDiaChi[i], dsNgayLapThe[i], dsNgayHetHan[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia co ten: %s\n", ten);
    }
}


