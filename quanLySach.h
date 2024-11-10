#ifndef QUAN_LY_SACH_H
#define QUAN_LY_SACH_H

#include "khaiBaoHam.h"
#include "thongKe.h"

// Định nghĩa các hằng số
#define MAX_SACH 100 
#define MAX_ISBN 14
#define MAX_TEN_SACH 100
#define MAX_TAC_GIA 50
#define MAX_THE_LOAI 100 
#define MAX_NHA_XUAT_BAN 50

// Khai báo các hàm
void hienThiMenuQuanLySach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                           char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                           int dsGiaSach[], int dsSoLuong[], int demSach);

void xemDanhSachSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                     char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                     int dsGiaSach[], int dsSoLuong[], int demSach);

void themSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
              char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
              int dsGiaSach[], int dsSoLuong[], int *demSach);

void chinhSuaThongTinSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                          char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                          int dsGiaSach[], int dsSoLuong[], int demSach);

void xoaSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
             char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
             int dsGiaSach[], int dsSoLuong[], int *demSach);

void timKiemSachTheoISBN(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                         char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                         int dsGiaSach[], int dsSoLuong[], int demSach);

void timKiemSachTheoTenSach(char dsISBN[][MAX_ISBN], char dsTenSach[][MAX_TEN_SACH], char dsTacGia[][MAX_TAC_GIA],
                            char dsTheLoai[][MAX_THE_LOAI], char dsNhaXuatBan[][MAX_NHA_XUAT_BAN], char dsNamXuatBan[][5],
                            int dsGiaSach[], int dsSoLuong[], int demSach);

void thongKeSoLuongSachTheoTheLoai();

#endif // QUAN_LY_SACH_H
