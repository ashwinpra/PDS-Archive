#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sortArray(char**, int*);

int main() {
    printf("Enter 10 names:\n");
    char **firstname, **lastname;
    int a[10],b[10];
    firstname = (char**)malloc(10*sizeof(char*));
    lastname = (char**)malloc(10*sizeof(char*));

    for(int i=0; i<10; i++){
        firstname[i] = (char *)malloc(50*sizeof(char));
        lastname[i] = (char *)malloc(50*sizeof(char));
        scanf("%s %s",firstname[i],lastname[i]);
    }
    sortArray(firstname,a);
    // printf("First name sorting: ");
    // for(int i=0; i<10; i++) printf("%d\n",a[i]);
    printf("Names sorted according to first name: \n");
    for(int i=0; i<10; i++){
        printf("%s %s\n",firstname[a[i]],lastname[a[i]]);
    }
    sortArray(lastname,b);
    // printf("Last name sorting: ");
    // for(int i=0; i<10; i++) printf("%d\n",b[i]);
    printf("Names sorted according to last name: \n");
    for(int i=0; i<10; i++){
        printf("%s %s\n",firstname[b[i]],lastname[b[i]]);
    }

    return 0;
}

void sortArray(char **s, int *a){
    // int check[10];
    // for(int i=0; i<10; i++) check[i]=0;
    //check[i] sees if s(i,i+1) is checked
    for(int i=0;i<10;i++) a[i] = i;
    int temp;
    for(int i=0; i<9; i++){
        for(int j=0;j<9-i;j++){
                 if(strcmp(s[a[j]],s[a[j+1]])>1){
                    temp = a[j];
                    a[j]=a[j+1];    
                    a[j+1]=temp;
            }
        }
    }
}