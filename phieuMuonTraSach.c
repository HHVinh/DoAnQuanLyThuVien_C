#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "khaiBaoHam.h"


char dsMaDocGia[MAX_DOC_GIA][5] = {"0001", "0002", "0003", "0004", "0005", "0006"};
char dsTenDocGia[MAX_DOC_GIA][50] = {"Nguyễn Văn A", "Nguyễn Văn B", "Nguyễn Văn C", "Trần Thị D", "Trần Thị E", "Trần Thị F"};
char dsCCCD[MAX_DOC_GIA][13] = {"111111111111", "111111111112", "111111111113", "111111111114", "111111111115", "111111111116"};
char dsNgaySinh[MAX_DOC_GIA][11] = {"1/1/1990", "1/1/1991", "1/1/1992", "1/1/1993", "1/1/1994", "1/1/1995"};
char dsGioiTinh[MAX_DOC_GIA][10] = {"Nam", "Nam", "Nam", "Nữ", "Nữ", "Nữ"};
char dsEmail[MAX_DOC_GIA][50] = {"nguyenvana@gmail.com", "nguyenvanb@gmail.com", "nguyenvanc@gmail.com", "tranthid@gmail.com", "tranthie@gmail.com", "tranthif@gmail.com"};
char dsDiaChi[MAX_DOC_GIA][100] = {"Hồ Chí Minh", "Tiền Giang", "Đà Lạt", "Long An", "Nghệ An", "Hà Nội"};
char dsNgayLapThe[MAX_DOC_GIA][11] = {"1/1/2024", "1/5/2024", "15/8/2024", "1/10/2022", "15/10/2023", "10/10/2024"};
char dsNgayHetHan[MAX_DOC_GIA][11] = {"1/1/2028", "1/5/2028", "15/8/2028", "1/10/2026", "15/10/2027", "10/10/2028"};

char dsISBN[MAX_SACH][14] = {"9999999999991","9999999999992","9999999999993","9999999999994","9999999999995","9999999999996","9999999999997","9999999999998","9999999999999", "9999999999910"};
char dsTenSach[MAX_SACH][100] = {"Truyện Kiều","Lục Vân Tiên","Sơn Tinh Thủy Tinh","Sự Tích Bánh Chưng Bánh Dày","Dế Mèn Phiêu Lưu Ký","Tấm Cám","Sách Giáo Khoa Ngữ Văn 6","Sách Giáo Khoa Ngữ Văn 9","Sách Giáo Khoa Tiếng Việt 1 - Tập 1","Sách Giáo Khoa Tiếng Việt 3 - Tập 2"};
char dsTacGia[MAX_SACH][50] = {"Nguyễn Du","Nguyễn Đình Chiểu","Truyền Thuyết","Truyền Thuyết","Tô Hoài","Truyện Dân Gian","Bộ Giáo Dục","Bộ Giáo Dục","Bộ Giáo Dục","Bộ Giáo Dục"};
char dsNhaXuatBan[MAX_SACH][50] = {"NXB Văn Học","NXB Văn Học","NXB Kim Đồng","NXB Kim Đồng","NXB Kim Đồng","NXB Kim Đồng","NXB Giáo Dục","NXB Giáo Dục","NXB Giáo Dục","NXB Giáo Dục"};
char dsNamXuatBan[MAX_SACH][5] = {"2018","2019","2020","2020","2017","2018","2021","2021","2022","2022"};
int dsGiaSach[MAX_SACH] = {50000, 40000, 30000, 45000, 35000, 25000, 60000, 65000, 30000, 50000};
int dsSoLuong[MAX_SACH] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

char dsISBN[MAX_SACH][MAX_ISBN];
char dsTenSach[MAX_SACH][100];
char dsCCCDSachMuon[100][13];
char dsSachMuon[MAX_PHIEU][MAX_ISBN] = {"9999999999991","9999999999992"};
char dsMaDocGiaMuonSach[MAX_PHIEU][MAX_MA_DOC_GIA] = {"0001", "0002"};
char dsNgayMuon[MAX_PHIEU][11] = {"20/10/2024", "22/10/2024"};
char dsNgayTraDuKien[MAX_PHIEU][11] = {"27/10/2024", "29/10/2024"};

int demDocGia = 6;
int demSach = 10;
int demSachMuon = 2;

// Hàm kiểm tra tính hợp lệ của ISBN
int kiemTraISBN(char *isbn) {
    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbn) == 0) {
            return 1; // ISBN hợp lệ
        }
    }
    return 0; // ISBN không hợp lệ
}

// Hàm kiểm tra tính hợp lệ của mã độc giả
int kiemTraMaDocGia(char *maDocGia) {
    for (int i = 0; i < demDocGia; i++) {
        if (strcmp(dsMaDocGia[i], maDocGia) == 0) {
            return 1; // Mã độc giả hợp lệ
        }
    }
    return 0; // Mã độc giả không hợp lệ
}

// Hàm kiểm tra tính hợp lệ của mã độc giả đang mượn sách
int kiemTraMaDocGiaMuonSach(char *maDocGia) {
    for (int i = 0; i < demDocGia; i++) {
        if (strcmp(dsMaDocGiaMuonSach[i], maDocGia) == 0) {
            return 1; // Mã độc giả hợp lệ
        }
    }
    return 0; // Mã độc giả không hợp lệ
}

// Hàm tìm vị trí sách theo ISBN
int timViTriSach(char *isbn) {
    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbn) == 0) {
            return i;
        }
    }
    return -1;
}

// Hàm mượn trả sách
void muonTraSach() {
    hienThiMenuMuonTraSach();
}

// Hàm hiển thị menu mượn trả sách
void hienThiMenuMuonTraSach() {
    char luaChon;

    do {
        printf("\n=== Muon Tra Sach ===\n");
        printf("a. Muon sach\n");
        printf("b. Tra sach\n");
        printf("c. Thoát\n");
        printf("Nhap lua chon: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                lapPhieuMuonSach();
                break;
            case 'b':
                lapPhieuTraSach();
                break;
            case 'c':
                printf("Thoát.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
                break;
        }
    } while (luaChon != 'c');
}

// Hàm lập phiếu mượn sách
void lapPhieuMuonSach() {
    char maDocGia[MAX_MA_DOC_GIA];
    printf("Nhap ma doc gia: ");
    scanf("%s", maDocGia);

    // Kiểm tra mã độc giả
    if (!kiemTraMaDocGia(maDocGia)) {
        printf("Khong tim thay ma doc gia!\n");
        return;
    }

    char isbn[MAX_ISBN];
    printf("Nhap ma ISBN sach muon: ");
    scanf("%s", isbn);

    // Kiểm tra ISBN và tìm vị trí của sách
    int viTriSach = timViTriSach(isbn);
    if (viTriSach == -1) {
        printf("Khong tim thay ISBN sach!\n");
        return;
    }

    // Kiểm tra số lượng sách
    if (dsSoLuong[viTriSach] == 0) {
        printf("Het sach, khong the muon!\n");
        return;
    }

    // Thực hiện cho mượn sách
    strcpy(dsSachMuon[demSachMuon], isbn);
    strcpy(dsMaDocGiaMuonSach[demSachMuon], maDocGia);
    printf("Nhap ngay muon (dd/mm/yyyy): ");
    scanf("%s", dsNgayMuon[demSachMuon]);

    // Tính ngày trả dự kiến
    char ngayTraDuKien[11];  // Khai báo biến để lưu ngày trả dự kiến
    tinhNgayTraDuKien(dsNgayMuon[demSachMuon], ngayTraDuKien);

      // Thêm ngày trả dự kiến vào mảng dsNgayTraDuKien
    strcpy(dsNgayTraDuKien[demSachMuon], ngayTraDuKien);

    // Giảm số lượng sách sau khi mượn
    dsSoLuong[viTriSach]--;

    demSachMuon++;
    printf("Lap phieu muon sach thanh cong!\n");

    // Hiển thị danh sách sách mượn
    printf("Danh sach sach muon:\n");
    for (int i = 0; i < demSachMuon; i++) {
        printf("Ma doc gia: %s, ISBN: %s, Ngay muon: %s, Ngay tra du kien: %s\n",
               dsMaDocGiaMuonSach[i], dsSachMuon[i], dsNgayMuon[i], dsNgayTraDuKien[i]);
    }
}


void lapPhieuTraSach() {
    char maDocGia[MAX_MA_DOC_GIA];
    printf("Nhap ma doc gia: ");
    scanf("%s", maDocGia);

    // Hàm kiemTraMaDocGia kiểm tra xem mã độc giả có hợp lệ không
    if (!kiemTraMaDocGiaMuonSach(maDocGia)) {
        printf("Khong tim thay ma doc gia!\n");
        return;
    }

    printf("Danh sach sach muon:\n");
    // Duyệt qua danh sách sách mượn (dsSachMuon) để in ra các sách mà độc giả có mã maDocGia đang mượn
    for (int i = 0; i < demSachMuon; i++) {
        if (strcmp(dsMaDocGiaMuonSach[i], maDocGia) == 0) {
            printf("%d. ISBN: %s, Ngay muon: %s, Ngay tra du kien: %s\n",
                   i + 1, dsSachMuon[i], dsNgayMuon[i], dsNgayTraDuKien[i]);
        }
    }

    char isbn[MAX_ISBN];
    printf("Nhap ma ISBN sach can tra: ");
    scanf("%s", isbn);
    // Tìm vị trí của sách trong danh sách sách mượn của độc giả. Nếu tìm thấy, lưu vị trí vào biến timSachMuon
    int timSachMuon = -1;
    for (int i = 0; i < demSachMuon; i++) {
        if (strcmp(dsSachMuon[i], isbn) == 0 && strcmp(dsMaDocGiaMuonSach[i], maDocGia) == 0) {
            timSachMuon = i;
            break;
        }
    }
    if (timSachMuon == -1) {
        printf("Khong tim thay ISBN trong dsSachMuon!\n");
        return;
    }

    char ngayTra[11];
    printf("Nhap ngay tra thuc te (dd/mm/yyyy): ");
    scanf("%s", ngayTra);

    int hienTrang;
    printf("Nhap hien trang sach (1. Con, 2. Mat): ");
    scanf("%d", &hienTrang);

    if (hienTrang < 1 || hienTrang > 2) {
        printf("Hien trang sach khong hop le! Vui long nhap lai.\n");
        return;
    }

    // Tính toán số tiền thanh toán
    int soTienThanhToan = 0;
    char *ngayTraDuKien = dsNgayTraDuKien[timSachMuon];
    // Gọi hàm tinhChenhLechNgay đã được định nghĩa trong file khác
    int chenhLechNgay = tinhChenhLechNgay(ngayTra, dsNgayTraDuKien[timSachMuon]);

    // Tìm vị trí của sách trong dsGiaSach
    int viTriSach = timViTriSach(isbn);
    if (viTriSach == -1) {
        printf("Khong tim thay gia cua ISBN trong dsGiaSach!\n");
        return;
    }

    if (hienTrang == 1) { // Sách còn
        if (chenhLechNgay <= 0) {
            soTienThanhToan = 0; // Trường hợp 1
        } else {
            soTienThanhToan = 5000 * chenhLechNgay; // Trường hợp 2
        }
    } else if (hienTrang == 2) { // Sách mất
        if (chenhLechNgay <= 0) {
            soTienThanhToan = 2 * dsGiaSach[viTriSach]; // Trường hợp 3
        } else {
            soTienThanhToan = 5000 * chenhLechNgay + 2 * dsGiaSach[viTriSach]; // Trường hợp 4
        }
    }

    // Hiển thị thông tin trả sách
    printf("Ma doc gia: %s\n", maDocGia);
    printf("ISBN: %s\n", dsSachMuon[timSachMuon]);
    printf("Ngay muon: %s\n", dsNgayMuon[timSachMuon]);
    printf("Ngay tra du kien: %s\n", dsNgayTraDuKien[timSachMuon]);
    printf("Ngay tra thuc te: %s\n", ngayTra);
    printf("So tien can thanh toan: %d\n", soTienThanhToan);

    // Xóa sách đã trả khỏi danh sách mượn
    for (int i = timSachMuon; i < demSachMuon - 1; i++) {
        strcpy(dsSachMuon[i], dsSachMuon[i + 1]);
        strcpy(dsMaDocGiaMuonSach[i], dsMaDocGiaMuonSach[i + 1]);
        strcpy(dsNgayMuon[i], dsNgayMuon[i + 1]);
        strcpy(dsNgayTraDuKien[i], dsNgayTraDuKien[i + 1]);
    }
    demSachMuon--;

    // Cập nhật số lượng sách
    if (hienTrang == 1) {
        dsSoLuong[viTriSach]++; // Tăng số lượng nếu sách còn
    }

    printf("Lap phieu tra sach thanh cong!\n");
}




