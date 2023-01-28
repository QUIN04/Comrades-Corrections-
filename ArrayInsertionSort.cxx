#include <stdio.h>

void ArrayInsertionSort(int a[], int length);

int main()
{
	int arr[] = {3, 6, 8, 2, 1, 9, 5, 0, 4, 7};
	int length = 10;
	
    ArrayInsertionSort(arr, length);
	
	return 0;
}


void ArrayInsertionSort(int a[], int length){
    int i, j, key;
    
    for(i = 1; i < length; i++){
                 key = a[i];
                 j = i - 1;
                 while((key < a[j]) && j >=0){
                        a[j+1] = a[j];
                        j--;
                 }
                 a[j+1] = key;
    }
                 for(i = 0; i < length; i++)
                     printf("a[%d] = %d\n",i, a[i]);
}
    
    
    
    