//Peter Eberhard

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// custom libraries and things like custom libraries go here   
#include "structs.h" 


//  do C code headers last, this file.s header dead last.
#include "output.h"
#include "debug.h"

// last
#include "memory.h"


//allocates a void pointer for thing of size bits
void* allocate_thing(unsigned long bytes)
{
    static int object_count = 1;

    void *pointer1 = malloc(bytes);
    if(pointer1 != NULL)
    {
        if(TEXT)printf("DIAGNOSTIC: allocate_thing: %lu bytes allocated for object #%i\n", bytes, object_count);
        
    } else
    {
        if(TEXT)printf("DIAGNOSTIC: allocate_thing returned a NULL pointer\n");
    }

    if(DEBUG)printf("allocate_thing: returning %p\n",pointer1);
    object_count++;
    return pointer1;
}

// frees a pointer and sets it to null
void free_thing(void (*pointer_to_thing))
{
    static int freed_count = 1;

    if(DEBUG)printf("DIAGNOSTIC: free_thing: freeing %p\n", pointer_to_thing);
    if(DEBUG)fflush(stdout);
    free(pointer_to_thing);
    if(TEXT)printf("DIAGNOSTIC: free_thing: %i objects freed\n", freed_count);
    pointer_to_thing = NULL;
    if(DEBUG)printf("DEBUG: freed pointer is now = %p\n", pointer_to_thing);
    freed_count++;

}

