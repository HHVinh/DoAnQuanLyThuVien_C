#include "thongKe.h"
#include <stdio.h>
#include <stdlib.h>

void hienThiMenuChinh() {
    int luaChon;
    char c;

    do {
        printf("\n=== MENU CHINH ===\n");
        printf("1. Quan ly doc gia\n");
        printf("2. Quan ly sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Thong ke\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");

        // Nhập lựa chọn, kiểm tra dữ liệu đầu vào
        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le. Vui long chon lai!\n");

            // Làm sạch bộ đệm đầu vào
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Xử lý lựa chọn hợp lệ
        switch (luaChon) {
            case 1:
                quanLyDocGia();
                break;
            case 2:
                quanLySach();
                break;
            case 3:
                lapPhieuMuonSach();
                break;
            case 4:
                lapPhieuTraSach();
                break;
            case 5:
                thongKe();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 0);
}
