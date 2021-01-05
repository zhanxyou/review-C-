#include "Header.h"
#if 0
void insertionSort(int arr[], int len) {
	
	for (int i = 1; i < len; i++)
	{  //4 | 2 ...
		if (arr[i - 1] > arr[i]) {
			int temp = arr[i]; //2
			int j = i - 1; //pos(4)
			for(; j>=0 && temp < arr[j]; j--) //2<4
			{
				arr[j + 1] = arr[j]; //pos(2) = 4
			} //j = i-1-1
			arr[j + 1] = temp; //pos(4) = temp =2
		}
	}
}
void printArr(int arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

}
int main(void)
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int len = sizeof(arr) / sizeof(int);
	insertionSort(arr, len);
	printArr(arr, len);
	return 0;
}
#endif