#include<stdio.h>
#include<stdlib.h>

int binarySearch(int array[], int small_index, int big_index, int target){
    if (big_index < small_index){
        return -1;
    }

    //write in a more complex format to avoid overflow
    int mid_index = small_index + (big_index - small_index) / 2;

    if (array[mid_index] == target){
        return mid_index;
    }

    if (array[mid_index] < target) {
        return binarySearch(array, mid_index + 1, big_index, target);
    }
    
    return binarySearch(array, small_index, mid_index - 1, target);
}

int main() {
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15};
    
    int result = binarySearch(array, 0, 7, 11);
    printf("result found: %d\n", result);
    result = binarySearch(array, 0, 7, 12);
    printf("result not found: %d\n", result);
    
    return 0;
}
