/*
 * File:   func.c
 * Author: TranVietAn
 */

#include <stdio.h>
#include <stdint.h>


void list_print() {
	printf("\n---------CHUONG TRINH QUAN LY MANG SO NGUYEN---------");
	printf("\n| Nhap 'c' : Tao mang so nguyen                     |");
	printf("\n| Nhap 'p' : In day                                 |");
	printf("\n| Nhap 'i' : Them phan tu vao day tai vi tri thu k  |");
	printf("\n| Nhap 'd' : Xoa phan tu tai vi tri k               |");
	printf("\n| Nhap 's' : Sap xep day so tang dan                |");
	printf("\n| Nhap 'x' : Sap xep day so giam dan                |");
	printf("\n| Nhap 't' : Tim kiem                               |");
	printf("\n| Nhap 'e' : Thoat                                  |");
	printf("\n-----------------------------------------------------");
	printf("\nChon phim chuc nang: ");
}

char value_select() {
	static char s_value;
	fflush(stdin);
	scanf("%c", &s_value);
	printf("Phim Chuc Nang Da Chon: %c", s_value);
	return s_value;
}

void input_array(int array[], int length) {
	static int s_i;
	for(s_i = 0; s_i < length; s_i++)	{
//		printf("\t\t");
		scanf("%d", &array[s_i]);
	}
}

void show_array(int array[], int length) {
	static int s_i;
	for(s_i = 0; s_i < length; s_i++)  printf("%d ", array[s_i]);
}

int add_array(int array[], int k, int value, int n) {
	static int s_i;

//	if(k < 0 || k > n) return 0;

	if(k < 0) k = 0;
	if(k > n) k = n;

//	for(s_i = n-1; s_i >= k-1; s_i--) {
//		array[s_i+1] = array[s_i];
//	}
//	array[k-1] = value;

	for(s_i = n; s_i > k; s_i--)
		array[s_i] = array[s_i-1];
	array[s_i] = value;

	return 1;
}

int delete_aray(int array[], int k, int n) {
	static int s_i;
//	if(k < 0 || k > n) return 0;
	if(k < 0) k = 0;
	if(k > n) k = n;

	for(s_i = k; s_i < n-1 ; s_i++)
		array[s_i] = array[s_i+1];

	return 1;
}

int sort_asc(int array[], int n) {
	static int s_temp, s_i, s_j;
	for(s_i = 0; s_i < n; s_i++)
		for(s_j = 0; s_j <= s_i; s_j++) {
			if(array[s_j] > array[s_i]) {
				s_temp = array[s_i];
				array[s_i] = array[s_j];
				array[s_j] = s_temp;
			}
		}
	return 1;
}

int sort_des(int array[], int n) {
	static int s_temp, s_i, s_j;
	for(s_i = 0; s_i < n; s_i++)
		for(s_j = 0; s_j <= s_i; s_j++) {
			if(array[s_j] < array[s_i]) {
				s_temp = array[s_i];
				array[s_i] = array[s_j];
				array[s_j] = s_temp;
			}
		}
	return 1;
}

int search(int array[], int n, int value) {
	static int s_i, s_count = 0;
	for(s_i = 0; s_i < n; s_i++) {
		if(array[s_i] == value) {
			s_count++;
		}
	}
	return s_count;
}

