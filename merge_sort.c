#include <stdio.h>

int merge_sort(int arr[], int low, int high)
{
int mid;    
if(low < high)
{   
 mid = (low + high) / 2;
 merge_sort(arr, low, mid);
 merge_sort(arr, mid + 1, high);
 merge(arr, low, mid, high);
}
}

int merge(int arr[], int low, int mid, int high) 
{
    int i, j, k; 
    int n1 = mid - low + 1; 
    int n2 = high - mid; 
    // creating temp arrays
    int arr1[n1], arr2[n2]; 
    // Copying to temporary arr1[] and arr2[] 
	    for (i = 0; i < n1; i++) 
	      arr1[i] = arr[low + i]; 
    
	for (j = 0; j < n2; j++) 
	    arr2[j] = arr[mid + 1 + j]; 

    // Merge the temp arrays back into arr[]
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = low; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (arr1[i] <= arr2[j]) 
        { 
            arr[k] = arr1[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = arr2[j]; 
            j++; 
        } 
        k++; 
    } 

    // if arr[2] empty means
    while (i < n1) 
    { 
        arr[k] = arr1[i]; 
        i++; 
        k++; 
    } 
    // if arr1 empty means
    while (j < n2) 
    { 
        arr[k] = arr2[j]; 
        j++; 
        k++; 
    } 
} 


int main()
{
    int n, i, arr[n];
	printf("enter the No.of elements");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    	scanf("%d", &arr[i]);
    merge_sort(arr, 0, n - 1);
	for( i = 0; i < n; i++)
	       printf("%d ", arr[i]);
}

