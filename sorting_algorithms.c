#include <stdio.h>
#include <string.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1 ; i++){
        int minIndex = i;

        for (int j = i+1; j < n; j++){
            if (arr[j]< arr[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(&arr[i], &arr[minIndex]);
        }
    }
}


void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++ ){
        int key = arr[i];
        int j = i -1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;

    for (int j= low; j< high; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if (low< high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi -1);
        quickSort(arr, pi+1, high);
    }
}

void bubbleSort(int arr[], int n){
    for (int i= 0; i < n-1; i++){
        for (int j = 0; j< n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void displayArray(int arr[], int n){
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[]= {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    displayArray(arr, n);

    
    int arr1[n], arr2[n], arr3[n], arr4[n];
    memcpy(arr1, arr, n * sizeof(int));
    memcpy(arr2, arr, n * sizeof(int));
    memcpy(arr3, arr, n * sizeof(int));
    memcpy(arr4, arr, n * sizeof(int));

    bubbleSort(arr1, n);
    printf("Sorted array (Bubble Sort): ");
    displayArray(arr1, n);

    quickSort(arr2, 0, n-1);
    printf("Sorted array (Quick Sort): ");
    displayArray(arr2, n);

    insertionSort(arr3, n);
    printf("Sorted array (Insertion Sort): ");
    displayArray(arr3, n);

    selectionSort(arr4, n);
    printf("Sorted array (Selection Sort): ");
    displayArray(arr4, n);

    return 0;
}