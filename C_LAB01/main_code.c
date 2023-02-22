/*
 * File:   main_code.c
 * Author: TranVietAn
 */

#include <stdio.h>
#include "func.h"

int g_array[10];
//int g_n;

void main(void) {
	static char s_value_select = 'e';
	while(1) {
		static int s_n, s_k = 0, s_value = 0;
		list_print();
		s_value_select = value_select();
		if(s_value_select == 'c') {
			printf("\n\n\tTAO MANG:");
			printf("\nNhap so phan tu cho mang: ");
			scanf("%d", &s_n);
			printf("Do dai mang: %d", s_n);
			printf("\nNhap phan tu cho mang:\n");
			input_array(g_array, s_n);

		} else if(s_value_select == 'p') {
			printf("\n\n\tIN MANG:");
			printf("\nMang vua nhap: [ ");
			show_array(g_array, s_n);
			printf("]\n");

		} else if(s_value_select == 'i') {
			printf("\n\n\tTHEM PHAN TU VAO DAY TAI VI TRI THU K");
			printf("\nNhap vi tri K: ");
			scanf("%d", &s_k);
			printf("Gia tri phan tu muon them: ");
			scanf("%d", &s_value);
			if (s_k <= 0)
				printf("\nVi tri khong hop le. Gia tri se duoc them vao dau mang.");
			if (s_k > s_n)
				printf("\nVi tri vuot qua do dai cua mang. Gia tri se duoc them vao cuoi mang.");
//			add_array(g_array, s_k, s_value, s_n);
			if(add_array(g_array, s_k, s_value, s_n) == 1)
				printf("Thuc hien chuc nang thanh cong. Chon 'p' de in day so.\n");
			else printf("Thuc hien chuc nang that bai. Chon 'p' de in day so.\n");
			s_n++;
			s_k=0;
			s_value = 0;

		} else if(s_value_select == 'd') {
			printf("\n\n\tXOA PHAN TU VAO DAY TAI VI TRI THU K");
			printf("\nNhap vi tri K: ");
			scanf("%d", &s_k);
			if (s_k <= 0)
				printf("\nVi tri khong hop le. Se xoa gia tri dau mang. Chon 'p' de in day so.");
			if (s_k > s_n)
				printf("\nVi tri vuot qua do dai cua mang. Se xoa gia tri cuoi mang. Chon 'p' de in day so.");

			if(delete_aray(g_array, s_k, s_n) == 1) {
				printf("Thuc hien chuc nang thanh cong. Chon 'p' de in day so.\n");
			} else printf("Thuc hien chuc nang that bai. Chon 'p' de in day so.\n");

			s_n--;

		} else if(s_value_select == 's') {
			printf("\n\n\tSAP XEP DAY SO THEO THU TU TANG DAN");
			if(sort_asc(g_array, s_n) == 1) {
				printf("\nThuc hien chuc nang thanh cong. Chon 'p' de in day so.\n");
			} else printf("\nThuc hien chuc nang that bai. Chon 'p' de in day so.\n");

		} else if(s_value_select == 'x') {
			printf("\n\n\tSAP XEP DAY SO THEO THU TU GIAM DAN");
			if(sort_des(g_array, s_n) == 1) {
				printf("\nThuc hien chuc nang thanh cong. Chon 'p' de in day so.\n");
			} else printf("\nThuc hien chuc nang that bai. Chon 'p' de in day so.\n");
		
		} else if(s_value_select == 't') {
			static int s_val;
			printf("\n\n\tTIM KIEM PHAN TU TRONG DAY SO");
			printf("\nNhap phan tu muon tim kiem: ");
			scanf("%d", &s_val);
			
			printf("\nTrong day tim kiem duoc %d phan tu %d \n", search(g_array, s_n, s_val), s_val);

		}

		else if(s_value_select == 'e') {
			printf("\nThoat khoi chuong trinh !!!\n");
			return;
		} else printf("\nPhim chuc nang vua chon khong dung. Vui long thuc hien lai !!!\n");
	}
	return;
}


