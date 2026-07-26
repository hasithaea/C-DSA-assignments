#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i,j,temp;

    for(i=1; i<n; i++) {

        temp = arr[i];
        j = i-1;
        
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
}

int main()
{
    int arr[] = {5,8,9,1,3,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Sorted Array:\n");
    for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}