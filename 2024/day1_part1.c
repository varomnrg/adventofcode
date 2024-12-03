#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n);

int main(){
    int capacity = 10;
    int *list1 = (int *)malloc(capacity * sizeof(int));
    int *list2 = (int *)malloc(capacity * sizeof(int));
    
    if (list1 == NULL || list2 == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int row_count = 0;

    while(1){
        int a, b;

        if (scanf("%d %d", &a, &b) != 2){
            break;
        }

        if (row_count >= capacity) {
            capacity *= 1.5;
            list1 = (int *)realloc(list1, capacity * sizeof(int));
            list2 = (int *)realloc(list2, capacity * sizeof(int));

            if (list1 == NULL || list2 == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                return 1;
            }
        }

        list1[row_count] = a;
        list2[row_count] = b;
        row_count++;
    }

    int total = 0;
    sort(list1, row_count);
    sort(list2, row_count);


    for(int i = 0; i < row_count ; i++){
        int distance = list2[i] - list1[i];
        
        total += abs(distance);
    }

    printf("Total Distance : ");
    printf("%i\n", total);

    free(list1);
    free(list2);

    return 0;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}