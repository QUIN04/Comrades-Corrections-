#include <stdio.h>

void ReverseArray(int a[], int length);

int main()
{
	int arr[] = {3, 6, 8, 2, 1, 9, 5, 0, 4, 7};
	int length = 10;
	
    printf("The initial array is:\n");
    for(int i = 0; i <length; i++)
        printf("%d ", arr[i]);	
    printf("\n\n");
        
    ReverseArray(arr, length);
	
	return 0;
}


void ReverseArray(int a[], int length){
    int left;
    
    for(left = 0; left < length/2; left++){
            int temp = a[left];
            a[left] = a[length - left - 1];
            a[length - left - 1] = temp;
        } 
    printf("The reverse is:\n");
    for(int i = 0; i < length; i++)
        printf("%d ", a[i]);
}
