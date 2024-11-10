#ifndef THONGKE_H
#define THONGKE_H

#include <stdio.h>
#include "khaiBaoHam.h"
#include "menu.h"
#include "phieuMuonTraSach.h"
#include "quanLyDocGia.h"
#include "quanLySach.h"

int thongKeSoLuongSach(int dsSoLuong[], int soLuongSach);
int thongKeSoLuongDocGia(char dsMaDocGia[][5]);
int isAlphaNumeric(const char* str);
void thongKeSoLuongSachTheoTheLoai();
void thongKeSoLuongDocGiaTheoGioiTinh();
void thongKeSoLuongSachDangDuocMuon();
void thongKeDanhSachDocGiaTreHan();

#endif // THONGKE_H
