#include<stdio.h>
#include<stdlib.h>
//Declaring functions   
int isSawtooth(int *, int);
void position (int *, int *, int);

int main() {
    char choice='Y'; //user choice of whether to continue or not
    //declaring size of array, array, and pointer to position
    int n, *a, *pos;

    //this loop will go as long as choice is Y
    while(choice == 'Y') {
        //Taking user input for size and allocating memory accordingly
        printf("Enter size of array: ");
        scanf("%d", &n);
        a = (int *)malloc(n*sizeof(int));
        //Taking user input for elements of array
        printf("Enter elements of array: ");
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        printf("\n");
        //Calling function and displaying approppriate input based on return value
        if(isSawtooth(a,n)) printf("The array is a strict sawtooth array\n");
        else {
            printf("The array is not a strict sawtooth array\n");
            //Calling function to check position since its not sawtooth
            position (a,pos,n);
            printf("First violating position: %d\n",*pos);
        }
        free(a); //Freeing the allocated memory for array for use in next iteration
        //Checking if user wants to continue
        printf("Do you want to continue(Y/N): ");
        scanf(" %c", &choice);
    }
   

    return 0;   
}

int isSawtooth(int* a, int n){
    //"check" to see whether array starts off by decreasing or increasing
    int check, ct =0;
    //value of check is assigned accordingly 
    if(*a>*(a+1)) check = -1; //it starts by decreasing
    else if(*a<*(a+1)) check = 1; //it starts by increasing 
    else return 0; //if they are equal, it is not a sawtooth

    //Looping through elements of array
    for(int i = 0; i < (n-1); i++){
        //we keep incrementing ct and see whether it is odd or even
        //so that we can alternate between checking if it is > or <
        //we will check pairwise 
            if(i==0) {
                ct++; 
                continue;//we have already checked
            }
            if(ct%2 ==1){
                //based on whether it was increasing or decreasing initially, next condition is checked
                //if condition is not fulfilled, its not a sawtooth
                if(check ==-1){
                    if(*(a+i)< *(a+i+1)) ct++;
                    else return 0;
                }
               else if(check ==1){
                    if(*(a+i) > *(a+i+1)) ct++;
                    else return 0;
               }
            }
            else if(ct%2 ==0){
                if(check ==-1){
                    if(*(a+i) > *(a+i+1)) ct++;
                    else return 0;
                }
                else if(check ==1){
                    if(*(a+i)< *(a+i+1)) ct++;
                    else return 0;
                }
            }
    }
    //if loop completed successfully, it means it was sawtooth, so return 1 
    return 1;
}

void position (int * a, int *b, int n){
    /* 
        same logic as first function, but instead of returning 0, 
        it assigns position of value to pointer and returns
    */
    int check, ct =0;
    if(*a>*(a+1)) check = -1; 
    else if(*a<*(a+1)) check = 1; 
    else {
        //if they are equal at first, means second position caused violation
        *b = 2;
        return;
    }

    for(int i = 0; i < (n-1); i++){
            if(i==0) {
                ct++ ; 
                continue;
            }
            if(ct%2 ==1){
                if(check ==-1){
                    if(*(a+i)< *(a+i+1)) ct++;
                    else {
                        //i+1 is index of violation, i+2 is position
                        *b = i+2;
                        return;
                    }
                }
               else if(check ==1){
                    if(*(a+i) > *(a+i+1)) ct++;
                    else {
                        //i+1 is index of violation, i+2 is position
                        *b = i+2;
                        return;
                    }
               }
            }
            else if(ct%2 ==0){
                if(check ==-1){
                    if(*(a+i) > *(a+i+1)) ct++;
                    else {
                        //i+1 is index of violation, i+2 is position
                        *b = i+2;
                        return;
                    }
                }
                else if(check ==1){
                    if(*(a+i)< *(a+i+1)) ct++;
                    else {
                        //i+1 is index of violation, i+2 is position
                        *b = i+2;
                        return;
                    }
                }
            }
        //since we are calling only if its sawtooth, we need to worry about what to assign in case of sawtooth
    }
}