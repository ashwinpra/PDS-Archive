#include<stdio.h>
#include<stdlib.h>

int **allocate(int, int);
void readData(int **, int, int);
void printData(int **, int, int);

int main() {
    int **p, m,n;
    scanf("%d %d",&m,&n);
    p = allocate(m,n);
    readData(p,m,n);
    printData(p,m,n);
    return 0;
}

int **allocate(int h, int w){
    int **p;
    p = (int **)malloc(h*sizeof(int*));
    for(int i=0;i<h;i++){
        *(p+i) = (int*)malloc(w*sizeof(int));
        //assigning each row with sufficient size
    }
    return p;
}
void readData(int **p, int h, int w){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&*(*(p+i)+j));
        }
    }
}
void printData(int **p, int h, int w){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            printf("%d ",*(*(p+i)+j));
        }
        printf("\n");
    }
}