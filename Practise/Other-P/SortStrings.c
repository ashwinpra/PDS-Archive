#include<stdio.h>
#include<stdlib.h>
int main() {
    printf("Enter 10 names: ");
    int i=0;
    char **w;
    w = (char **)(malloc(10*sizeof(char *)));
    while(i<=9){
        
    }
    for(int i=0;i<10;i++){
        printf("%s\n",w[i]);
    }
    //w[i] is a pointer, which points to a string
    //now we can use bubble sort + strcmp
    return 0;
}
