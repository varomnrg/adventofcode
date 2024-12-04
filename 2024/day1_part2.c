#include <stdio.h>
#include <stdlib.h>

// Structure for dictionary
typedef struct
{
    int key;
    int value;
} Dict;

// Function for initializing the dictionary
Dict* initDict(int *capacity){
    *capacity = 10; 
    Dict *dict = (Dict *)malloc((*capacity) * sizeof(Dict));
    if (dict == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    return dict;
}

// Function for resizing the dictionary 
Dict* resizeDict(Dict *dict, int *capacity){
    *capacity *= 2;
    dict = (Dict *)realloc(dict, (*capacity) * sizeof(Dict));
    if (dict == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    return dict;
}

// Function for getting the value of the dictionary with the key
int getVal(Dict *dict, int size, int key){
    for (int i = 0; i < size; i++){
        if(dict[i].key == key){
            return dict[i].value;
        }
    }

    return 0;
}


// Function for incrementing the value of the dictionary
/*
    Function for incrementing the value of the dictionary
    - Using double pointer to modify the dict for resizing purposes
    - 
*/
void increment(Dict **dict, int *size, int *capacity, int key){
    for (int i = 0; i < *size; i++){
        if((*dict)[i].key == key){
            (*dict)[i].value++;
            return;
        }
    }

    // Resize the dicct if capacity is not enough
    if (*size >= *capacity) {
        *dict = resizeDict(*dict, capacity);
    }
    
    // Add the new key to the dict
    (*dict)[*size].key = key;
    (*dict)[*size].value = 1;  
    (*size)++;
}
    

int main(){
    // Start capacity for the array
    int capacity = 10;

    // Created 2 dynamic array
    int *arr1 = (int *)malloc(capacity * sizeof(int));
    int *arr2 = (int *)malloc(capacity * sizeof(int));
    
    if (arr1 == NULL || arr2 == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int row_count = 0;

    while(1){
        int a, b;

        if (scanf("%d %d", &a, &b) != 2){
            break;
        }

        // grow the memory by * 2 if the total row count > initial capacity
        if (row_count >= capacity) {
            capacity *= 2;
            arr1 = (int *)realloc(arr1, capacity * sizeof(int));
            arr2 = (int *)realloc(arr2, capacity * sizeof(int));

            if (arr1 == NULL || arr2 == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                return 1;
            }
        }

        arr1[row_count] = a;
        arr2[row_count] = b;
        row_count++;
    }

    int capacityDict = 10;
    int sizeDict = 0;

    Dict *dict = initDict(&capacityDict);

    for (int i = 0; i < row_count; i++) {
        increment(&dict, &sizeDict, &capacityDict, arr2[i]);
    }
    
    int total = 0;

    for(int i = 0; i < row_count ; i++){
        int value = arr1[i];
        total += value * getVal(dict, sizeDict, arr1[i]);
    }

    printf("Total Distance : ");
    printf("%i\n", total);

    free(arr1);
    free(arr2);
    free(dict);

    return 0;
}
