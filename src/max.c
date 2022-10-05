#include <stdio.h>
#include <assert.h>

int max(int* numbers, int size) {
    assert(size>0); //Precondition: array not empty
    int max = *numbers; //assign 'max' first element of array, pointed to by *numbers
    for (int i = 0; i < size; i++, numbers++) { //each iteration pointer '*number' is incremented
                                                //to point at next element
        (*numbers > max) && (max = *numbers); //if value at *number is > max, its becomes new max 
    }
    return max;
}
