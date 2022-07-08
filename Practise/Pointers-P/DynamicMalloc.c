#include<stdio.h>
 
int main() {
    /* 
     calloc -> allocates space for an array of elements, initializes them to zero and then returns a pointer to the memory 
     realloc -> modifies the size of previously allocated space 
     malloc : 
     a block of memory is allocaed using this
     it returns a pointer of type void, which can be typecasted to required type
     general format: 
     type *p;
     p = (type *)malloc(byte_size);
     malloc always allocates block of contiguous bytes
     if sufficient contiguous space is unavailable, it returns NULL
     free: 
     an allocated block can be returned to the system for future use by using free
     general syntax: free(ptr);
     */
    int n, *p;
    scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int)); //address of first byte of allocated memory = p
    for(int i = 0; i < n;i++){
        scanf("%d",&p[i]);
    }

    return 0;
}
