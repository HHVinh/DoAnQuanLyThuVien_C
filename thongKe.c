#include <stdio.h>
#include "khaiBaoHam.h"

static char dsGioiTinh[MAX_DOC_GIA][10] = {"Nam", "Nam", "Nam", "Nữ", "Nữ", "Nữ"};
static char dsSachMuon[MAX_PHIEU][MAX_ISBN] = {"9999999999991","9999999999992"};
static char dsMaDocGia[MAX_DOC_GIA][5] = {"0001", "0002", "0003", "0004", "0005", "0006"};
static char dsTenDocGia[MAX_DOC_GIA][50] = {"Nguyễn Văn A", "Nguyễn Văn B", "Nguyễn Văn C", "Trần Thị D", "Trần Thị E", "Trần Thị F"};
static char dsMaDocGiaMuonSach[MAX_PHIEU][MAX_MA_DOC_GIA] = {"0001", "0002"};
static char dsNgayTraDuKien[MAX_PHIEU][11] = {"27/10/2024", "29/10/2024"};
char dsTheLoai[MAX_SACH][MAX_THE_LOAI] = {
        "Văn Học", "Văn Học", "Truyện Cổ Tích", "Truyện Cổ Tích", "Văn Học Thiếu Nhi",
        "Truyện Cổ Tích", "Sách Giáo Khoa", "Sách Giáo Khoa", "Sách Giáo Khoa", "Sách Giáo Khoa"};
static int dsSoLuong[MAX_SACH] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

// Hàm tính tổng số lượng sách trong thư viện dựa trên mảng số lượng của các sách
int thongKeSoLuongSach(int dsSoLuong[], int soLuongSach) {
    int tongSoLuong = 0;
    for (int i = 0; i < soLuongSach; i++) {
        tongSoLuong += dsSoLuong[i];
    }
    return tongSoLuong;
}

// Hàm đếm số lượng sách theo từng thể loại và in kết quả ra màn hình
void thongKeSoLuongSachTheoTheLoai() {
    int soLuongSachTheoTheLoai[MAX_SACH] = {0};
    char tenTheLoai[MAX_SACH][MAX_THE_LOAI];
    int soLoaiTheLoai = 0; 
    int tongSoSach = 0;

    // Duyệt qua dsTheLoai và đếm số lượng sách theo thể loại
    for (int i = 0; i < MAX_SACH; i++) {
        int found = 0;
        // Kiểm tra xem thể loại này đã có trong danh sách chưa
        for (int j = 0; j < soLoaiTheLoai; j++) {
            if (strcmp(dsTheLoai[i], tenTheLoai[j]) == 0) {
                soLuongSachTheoTheLoai[j] += dsSoLuong[i];
                found = 1;
                break;
            }
        }

        // Nếu thể loại chưa có, thêm vào danh sách
        if (!found) {
            strcpy(tenTheLoai[soLoaiTheLoai], dsTheLoai[i]);
            soLuongSachTheoTheLoai[soLoaiTheLoai] = dsSoLuong[i];
            soLoaiTheLoai++;
        }

        // Cộng dồn tổng số sách
        tongSoSach += dsSoLuong[i];
    }

    // In số lượng sách cho từng thể loại
    for (int i = 0; i < soLoaiTheLoai; i++) {
        if (soLuongSachTheoTheLoai[i] > 0) {
            printf("The loai: %s - So sach: %d\n", tenTheLoai[i], soLuongSachTheoTheLoai[i]);
        }
    }

    // In tổng số thể loại và tổng số sách
    printf("Tong the loai: %d - Tong so sach: %d\n", soLoaiTheLoai, tongSoSach);
}

// Hàm đếm số lượng độc giả dựa trên danh sách mã độc giả
int thongKeSoLuongDocGia(char dsMaDocGia[][5]) {
    int tongDocGia = 0;

    // Duyệt qua từng mã độc giả trong dsMaDocGia để đếm số lượng
    for (int i = 0; i < MAX_DOC_GIA; i++) {
        if (strlen(dsMaDocGia[i]) > 0) {  // Kiểm tra mã có hợp lệ không
            tongDocGia++;
        }
    }
    return tongDocGia;
}

// Hàm đếm số lượng độc giả theo giới tính và in ra kết quả
void thongKeSoLuongDocGiaTheoGioiTinh() {
    int soNam = 0, soNu = 0, tongDocGia = 0;

    // Duyệt qua mảng dsGioiTinh để đếm số lượng Nam và Nữ
    for (int i = 0; i < MAX_DOC_GIA; i++) {
        if (strcmp(dsGioiTinh[i], "Nam") == 0) {
            soNam++;
        } else if (strcmp(dsGioiTinh[i], "Nữ") == 0) {
            soNu++;
        }
    }
    tongDocGia = soNam + soNu;
    // In kết quả
    printf("Tong so luong Nam: %d\n", soNam);
    printf("Tong so luong Nu: %d\n", soNu);
    printf("Tong so doc gia: %d\n", tongDocGia);
}

// Hàm đếm số sách hiện đang được mượn trong thư viện
void thongKeSoLuongSachDangDuocMuon() {
    int soSachDangMuon = 0;  // Biến đếm số sách đang mượn

    // Duyệt qua mảng dsSachMuon
    for (int i = 0; i < MAX_PHIEU; i++) {
        if (dsSachMuon[i][0] != '\0') {  // Kiểm tra nếu phần tử không rỗng
            soSachDangMuon++;
        }
    }

    // In kết quả thống kê
    printf("Số sách đang mượn: %d\n", soSachDangMuon);
}
// Hàm liệt kê danh sách độc giả có sách trả trễ hạn
void thongKeDanhSachDocGiaTreHan() {
    char ngayHienTai[11];
    printf("Nhap ngay hien tai (dd/mm/yyyy): ");
    scanf("%s", ngayHienTai);  // Nhập ngày hiện tại

    int demDocGia = thongKeSoLuongDocGia(dsMaDocGia);
    int coDocGiaTreHan = 0;

    for (int i = 0; i < demSachMuon; i++) {
        int soNgayTre = tinhChenhLechNgay(ngayHienTai, dsNgayTraDuKien[i]);
        if (soNgayTre > 0) {
            for (int j = 0; j < demDocGia; j++) {
                if (strcmp(dsMaDocGiaMuonSach[i], dsMaDocGia[j]) == 0) {
                    if (!coDocGiaTreHan) {
                        printf("\nDanh sach doc gia tre han:\n\n");
                        coDocGiaTreHan = 1;  // Đánh dấu đã có độc giả trễ hạn
                    }
                    printf("Ma Doc Gia: %s, Ten Doc Gia: %s, Ngay du kien tra: %s, So ngay tre: %d\n", dsMaDocGia[j], dsTenDocGia[j], dsNgayTraDuKien[i], soNgayTre);
                    break;
                }
            }
        }
    }

    // Nếu không có độc giả nào trễ hạn, in thông báo
    if (!coDocGiaTreHan) {
        printf("Khong co doc gia tre han!\n");
    }
}


// Hàm chính để chọn và thực hiện các chức năng thống kê
void thongKe() {
    char luaChon;
    do {
        printf("\n=== Thong Ke ===\n");
        printf("a. Thong ke so luong sach trong thu vien\n");
        printf("b. Thong ke so luong sach theo the loai\n");
        printf("c. Thong ke so luong doc gia\n");
        printf("d. Thong ke so luong doc gia theo gioi tinh\n");
        printf("e. Thong ke so sach dang duoc muon\n");
        printf("f. Thong ke danh sach doc gia bi tre han\n");
        printf("g. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                printf("Tong so sach trong thu vien: %d\n", thongKeSoLuongSach(dsSoLuong, MAX_SACH));
                break;
            case 'b':
                thongKeSoLuongSachTheoTheLoai();
                break;
            case 'c':
                printf("Tong so doc gia: %d\n", thongKeSoLuongDocGia(dsMaDocGia));
                break;
            case 'd':
                thongKeSoLuongDocGiaTheoGioiTinh();
                break;
            case 'e':
                thongKeSoLuongSachDangDuocMuon();
                break;
            case 'f':
                thongKeDanhSachDocGiaTreHan();
                break;
            case 'g':
                printf("Thoat thong ke.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 'g');
}
