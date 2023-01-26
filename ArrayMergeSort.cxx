#include <stdio.h>

void ArrayMergeSort(int a[], int length);
void RecursiveDivision(int a[], int l, int r);
void mergeSortedArrays(int a[], int l, int m, int r);

//l = left index
//r = right index
//m = middle index
int main()
{
	int arr[] = {3, 6, 8, 2, 1, 9, 5, 0, 4, 7};
	int length = 10;
	int i;
	
    ArrayMergeSort(arr, length);
    
    for(i = 0; i < length; i++)
        printf("a[%d] = %d\n",i, arr[i]);
    printf("\n");
	
	return 0;
}


void ArrayMergeSort(int a[], int length){
    RecursiveDivision(a, 0, length - 1);
}
    
void RecursiveDivision(int a[], int l, int r){
    if(l < r){
        int m = l + (r - l)/2;
        
        RecursiveDivision(a, l, m);
        RecursiveDivision(a, m + 1, r);
        
        mergeSortedArrays(a, l, m, r);
    }
}

void mergeSortedArrays(int a[], int l, int m, int r){
    int leftLength = m - l +1;
    int rightLength = r - m;
    
    int tempLeft[leftLength];
    int tempRight[rightLength];
    
    int i, j, k; 
    
    for(i = 0; i < leftLength; i++)
        tempLeft[i] = a[l + i];
        
    for(i = 0; i < rightLength; i++)
        tempRight[i] = a[m + 1 + i];
    // i is to track our position in tempLeft
    // j is to track our position in tempRight
    // k is to track our position in a
    
    for(i = 0, j = 0, k = l; k <= r; k++ ){
        if((i < leftLength) && ((j >= rightLength) || (tempLeft[i] <= tempRight[j]))){
            a[k] = tempLeft[i];
            i++;
        }
        else{
            a[k] = tempRight[j];
            j++;
        }
    }
}