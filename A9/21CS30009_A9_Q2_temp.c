/* Takes user input on dimension of two vectors and their corresponding components 
    Performs two functions: 
    find their sum using vector vectorSum(vector*, vector*);
    check whether they are orthogonal using orthogonalTest(vector*, vector*)
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{ 
    //no. dimensions, and pointer that points to array that will store vector components
    int dim;
    float* comp;
}vector;
void inputVector(vector*); //to take user input for vector
void printVector(vector*); //to print corresponding vector
vector vectorSum(vector*, vector*);
int orthogonalTest(vector*, vector*);


int main() {
    vector u,v;
    printf("Enter dimension: ");
    scanf("%d",&u.dim);
    v.dim=u.dim;
    u.comp = (float*)malloc(u.dim*sizeof(float));
    v.comp = (float*)malloc(v.dim*sizeof(float));
    printf("Enter components of first vector: ");
    inputVector(&u);
    printf("Enter components of second vector: ");
    inputVector(&v);
    printf("\nFirst vector: ");
    printVector(&u);
    printf("Second vector: ");
    printVector(&v);
    vector w = vectorSum(&u,&v);
    printf("Sum of vectors is: ");
    printVector(&w);
    if(orthogonalTest(&u,&v)) printf("The vectors are orthogonal\n");
    else printf("The vectors are not orthogonal\n");
    return 0;
}

void inputVector(vector* v){
    for(int i=0; i<(*v).dim; i++){
        scanf("%f",&(*v).comp[i]);
    }
}
void printVector(vector* v){
    printf("%d, [ ",(*v).dim);
    for(int i=0; i<(*v).dim; i++){
        if(i==(*v).dim-1) printf("%f ]\n",(*v).comp[i]);
        else printf("%f, ",(*v).comp[i]);
    }
}

vector vectorSum(vector* v1, vector* v2){
    vector v3;
    v3.dim = (*v1).dim;
    v3.comp = (float*)malloc(v3.dim*sizeof(float));
    for(int i=0; i<v3.dim; i++){
        v3.comp[i] = (*v1).comp[i] + (*v2).comp[i];
    }
    return v3;
}
int orthogonalTest(vector* v1, vector* v2){
    float count=0;
    for(int i=0; i<(*v1).dim; i++){
        count += (*v1).comp[i] * (*v2).comp[i];
    }
    if(count==0) return 1;
    else return 0;
}
