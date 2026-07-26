#include <stdio.h>
#include <string.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for(i=0; i<n-1; i++) {
        
        for(j=0; j<n-1-i; j++) {

            if(arr[j]>arr[j+1]) {

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5,8,9,1,3,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before:\n");
    for(int i=0; i<n; i++) 
        printf("%d ", arr[i]);
    
    printf("\n");

    bubbleSort(arr, n);

    printf("After:\n");
    for(int j=0; j<n; j++) 
        printf("%d ", arr[j]);
    
    printf("\n");

    return 0;
}