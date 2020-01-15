#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int array[], int start_index, int middle_index, int end_index){
    int first_half_index = start_index;
    int second_half_index = middle_index + 1;
    int overall_index = start_index;

    int temp[end_index + 1];
    memset(temp, 0, (end_index + 1) * sizeof(int));

    while (first_half_index < middle_index + 1 && second_half_index < end_index + 1){
        if (array[first_half_index] <= array[second_half_index]){
            temp[overall_index] = array[first_half_index++];
        }
        else {
            temp[overall_index] = array[second_half_index++];
        }
        overall_index++;
    }

    while (first_half_index < middle_index + 1){
        temp[overall_index++] = array[first_half_index++];
    }

    while (second_half_index < end_index + 1){
        temp[overall_index++] = array[second_half_index++];
    }

    memcpy(array + start_index, temp + start_index, (end_index + 1 - start_index) * sizeof(int));
}

// array[]: the array to sort
// start_index: the beginning of the sorting range
// end_index: the end of the sorting range; for the whole array, this value is size - 1
void mergesort(int array[], int start_index, int end_index) {
    if (start_index >= end_index){
        return;
    }

    //get the middle index
    //use start + (end - 1) / 2 to avoid the famous overflow bug in 2006
    int middle_index = start_index + (end_index - start_index) / 2;

    //sort first half
    mergesort(array, start_index, middle_index);
    //sort second half
    mergesort(array, middle_index + 1, end_index);

    merge(array, start_index, middle_index, end_index);
}

int main() {
    int array[] = {5, 54, 39, 2, 100, 23, 77, 1, 0};
    mergesort(array, 0, 8);

    printf("{");
    for (int i = 0; i < 9; i++) {
        printf("%d, ", array[i]);
    }
    printf("}\n");
}
