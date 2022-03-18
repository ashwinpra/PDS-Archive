/* n different sets of cardinality m are represented as an n x m 2D character array, 
where each row represents one set having max size m 
we have to perform union, intersection, and difference on two of these sets, chosen by user
*/
#include<stdio.h>
#include<string.h>

void Union(char[][100], int, int);
void Intersection(char[][100], int, int);
void Difference(char[][100], int, int);

int main(){
    int m,n;
    printf("Enter number of sets: ");
    scanf("%d",&n);
    printf("Enter maximum cardinality of sets: ");
    scanf("%d",&m);
    char a[100][100];

    //Nested for loops to fill array with space characters, which may or may not be replaced later
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] ='\0';
        }
        }

    printf("Note: Enter elements for each set without space, and press enter once done.\n");
    int ctr=0; //counter variable
    //For loop to get user input for each set
    for(int i=0;i<n;i++){
        char x[100];
        printf("Enter elements in set %d: ",i+1);
        scanf("%s",x); //takes input from user until he presses Enter
        //The characters of this input are added to the set
        for(int j=0;x[j]!='\0';j++){
                a[i][ctr] = x[j];
                ctr++;
        }
        ctr=0; //resetting value of counter for next iteration
    }

    int p,q;
    printf("Enter 2 sets which you want to operate on: ");
    scanf("%d %d",&p,&q);
    printf("Union: ");
    Union(a,p,q);
    printf("\nIntersection : ");
    Intersection(a,p,q);
    printf("\nDifference: ");
    Difference(a,p,q);
    return 0;
}

void Union(char a[][100], int i, int j){
    //Note that index of ith and jth set will be i-1 and j-1
    char s1[100],s2[100];//storing each set in separate arrays
    int li1,li2; //to store last occupied index of both sets    
    int ec=0; //counting number of elements, if zero, prints Null set
     //Approach, we will first print all elements of s1, then those elements of s2 that are not there in s1 
    for(int x=0;a[i-1][x]!='\0';x++){
        // if(a[i-1][x]==32) break;
        s1[x]=a[i-1][x];
        li1=x;
    }
    
    for(int y=0;a[j-1][y]!='\0';y++){
        // if(a[j-1][y]==32) break;
        s2[y]=a[j-1][y];
        li2=y;
    }
    for(int x=0;x<=li1;x++) {
        printf("%c ",s1[x]);
        ec++;
    }

    int count=0;
    for(int y=0;y<=li2;y++){
        for(int z=0;z<=li1;z++) {
            if(s2[y]==s1[z]) count++;
        }
        if(count==0) {
            printf("%c ",s2[y]);
            ec++;
        }
        count=0;
    }
    if(ec==0) printf("Null set");
    return;
}

void Intersection(char a[][100], int i, int j){
    //Note that index of ith and jth set will be i-1 and j-1
    char s1[100],s2[100];//storing each set in separate arrays
    int li1,li2; //to store last occupied index of both sets    
    int ec=0;
     //Approach, we will first check which is larger set, then check in smaller set 
     //whichever is present in larger one as well, those will be printed
    for(int x=0;a[i-1][x]!='\0';x++){
        // if(a[i-1][x]==32) break;
        s1[x]=a[i-1][x];
        li1=x;
    }
    
    for(int y=0;a[j-1][y]!='\0';y++){
        // if(a[j-1][y]==32) break;
        s2[y]=a[j-1][y];
        li2=y;
    }
    int count=0;
    if(li1>=li2){
        for(int y=0;y<=li2;y++){
        for(int z=0;z<=li1;z++) {
            if(s2[y]==s1[z]) count++;
        }
        if(count>0) {
            printf("%c ",s2[y]);
            ec++;
        }
        count=0;
    }
    }
    else{
         for(int y=0;y<=li1;y++){
        for(int z=0;z<=li2;z++) {
            if(s2[z]==s1[y]) count++;
        }
        if(count>0) {
            printf("%c ",s1[y]);
            ec++;
        }
        count=0;
    }
    }
    if(ec==0) printf("Null set");
    return;
}

void Difference(char a[][100], int i, int j){
    //Note that index of ith and jth set will be i-1 and j-1
    char s1[100],s2[100];//storing each set in separate arrays
    int li1,li2; //to store last occupied index of both sets    
    int ec=0;
     //Approach, we will go to first set, and print those elements that are NOT in second set
    for(int x=0;a[i-1][x]!='\0';x++){
        // if(a[i-1][x]==32) break;
        s1[x]=a[i-1][x];
        li1=x;
    }
    
    for(int y=0;a[j-1][y]!='\0';y++){
        // if(a[j-1][y]==32) break;
        s2[y]=a[j-1][y];
        li2=y;
    }
    int count=0;

    for(int x=0;x<=li1;x++){
        for(int y=0;y<=li2;y++){
            if(s1[x]==s2[y]) count++;
        }
        if (count==0) {
            printf("%c ", s1[x]);
            ec++;
        }
        count=0;
    }
    if(ec==0) printf("Null set");
    return;
}