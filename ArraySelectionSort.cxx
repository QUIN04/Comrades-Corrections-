#include <stdio.h>

void ArraySelectionSort(int arr[], int length);

int main()
{
	int arr[] = {3, 6, 8, 2, 1, 9, 5, 0, 4, 7};
	int length = 10;
	int i;
	
    ArraySelectionSort(arr, length);
	
	return 0;
}


void ArraySelectionSort(int arr[], int length){
    int smallest_pos;
    int i, j;
    
    for(i = 0; i < length; i++){
        smallest_pos = i;
        for(j = i+1; j <= (length - 1); j++){
            if(arr[j] < arr[j+1]){
                j = j;
                }
            else{
                if(arr[j+1] < arr[smallest_pos])
                    smallest_pos = j+1;
            }
        }
        int temp = arr[smallest_pos];
        arr[smallest_pos] = arr[i];
        arr[i] = temp;
    }
    for(i = 0; i <= length; i++){
        printf("a[%d] = %d\n",i ,arr[i]);
        }
}











