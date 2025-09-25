#include "array_operations.hh"

int greatest_v1(int *itemptr, int size)
{
    int greatest = *itemptr;

    for(int* position = itemptr; position < itemptr + size; ++position){
        if ( *position > greatest ){
            greatest = *position;
        }
    }
    return greatest;
}

int greatest_v2(int *itemptr, int *endptr)
{
    int greatest = *itemptr;

    for(int* position = itemptr; position != endptr ; ++position){
        if ( *position > greatest ){
            greatest = *position;
        }
    }
    return greatest;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{
    for(int* position = itemptr; position != endptr ; ++position, ++targetptr){
            *targetptr = *position;
    }
}

void reverse(int *leftptr, int *rightptr)
{
    while (leftptr != rightptr){
        --rightptr;
        int temptr = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temptr;

        if ( leftptr != rightptr ) {
            ++leftptr;
        }
    }
}
