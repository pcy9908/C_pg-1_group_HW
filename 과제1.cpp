#include<stdio.h>
int Max(int* pArr, int size);
int Min(int* pArr, int size);
void Sorting(int* pArr, int size);
int main() {
	int b[] = { 20, 34, 12, 24, 54, 91, 9,40 , 81, 10 };
	int max, min;
	max = Max(b, 10);
	min = Min(b, 10);
	
	printf("배열 b의 최대값은 %d이다\n", max);
	printf("배열 b의 최소값 %d이다\n", min);
	Sorting(b, 10);
	for (int i = 0; i < 10; i++)
		printf(" %d ", b[i]);

}
int Max(int* pArr, int size) {
	int i,max=0;
	max = *pArr;
	for (i = 0; i < size; i++) {
		if (max < *(pArr + i))
			max = *(pArr + i);
	}return max;
}
int Min(int* pArr, int size) {
	int i, min = 0;
	min = *pArr;
	for (i = 0; i < size; i++) {
		if (min > *(pArr + i))
			min = *(pArr + i);
	}return min;
}
void Sorting(int* pArr, int size) {
	int i, j, x = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < i; j++) {
			if (pArr[j] <  pArr[j + 1]) {
				x = pArr[j+1];
				pArr[j + 1] = pArr[j];
				pArr[j] = x;
			}
		}
		
	}
}