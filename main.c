#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "types/Vector.h"

implement_Vector(int)
implement_Vector(char)

Vector(char) strToVec(char *string) {
    size_t len = strlen(string);
    return (Vector(char)) {
        .data = strdup(string),
        .length = len,
        .size = len,
    };
}

int main(int argc, char *argv[])
{
    Vector(int) myVec = new_Vector_int(3);

    for (int i=0; i<5; ++i) {
        Vector_int_push(&myVec, i*i);
        printf("Pushed [%d]: %d\n", i, i*i);
    }

    for (int i=0; i<5; ++i) {
        printf("Popped %d\n", Vector_int_pop(&myVec));
    }

    
    return 0;
}

// Output:
//
// Pushed [0]: 0
// Pushed [1]: 1
// Pushed [2]: 4
// expanding: oldsize: 3, newsize: 6
// Pushed [3]: 9
// Pushed [4]: 16
// Popped 16
// Popped 9
// Popped 4
// Popped 1
// Popped 0
