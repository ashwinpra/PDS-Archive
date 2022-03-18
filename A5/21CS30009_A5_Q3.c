/*Program to check whether rectangles are overlapping
Function is made to check for 2 rectangles, this is used to check how many out of 3 are overlapping

*/
#include<stdio.h>
int overlap(float [], float []); //Function declaration

int main(){
    //coordinates stored in the order x1,y1,x2,y2
    float r1[4],r2[4],r3[4];
    printf("Note: Please enter coordinates of top-left (x1,y1) and bottom-right (x2,y2) diagonal points, in the format x1 y1 x2 y2\n");
    printf("X and Y coordinates of diagonal points of r1: ");
    scanf("%f %f %f %f", &r1[0],&r1[1],&r1[2],&r1[3]);
    printf("X and Y coordinates of diagonal points of r2: ");
    scanf("%f %f %f %f", &r2[0],&r2[1],&r2[2],&r2[3]);
    printf("X and Y coordinates of diagonal points of r3: ");
    scanf("%f %f %f %f", &r3[0],&r3[1],&r3[2],&r3[3]);
    //displaying approppriate input based on which rectangles overlap
    if(overlap(r1,r2)==1 && overlap(r1,r3)==1 && overlap(r2,r3)==1) printf("(r1,r2,r3) -- Overlaps");
    else {
        printf("(r1,r2) -- ");
        if(overlap(r1,r2)==1) printf("Overlaps\n");
        else printf("Does not overlap\n");
        printf("(r1,r3) -- ");
        if(overlap(r1,r3)==1) printf("Overlaps\n");
        else printf("Does not overlap\n");
        printf("(r2,r3) -- ");
        if(overlap(r2,r3)==1) printf("Overlaps\n");
        else printf("Does not overlap\n");
    }
    return 0;
}
//Function to check whether the rectangles are overlapping
int overlap(float r1[], float r2[]){
/*
Considering r1 as base rectangle and r2 and the other
If there is any kind of intersection, we can say that either y1 or y2 of r2 will lie between 
y1 and y2 of r1, or be equal to it, so we will check for that condition
*/

//if top side intersects - y1 of r2 must be between y1 and y2 of r1
if(r2[1]<= r1[3] && r2[1] >= r1[1]) return 1;
//if bottom side intersects - y2 of r2 must be between y1 and y2 of r2
else if (r2[3]<= r1[3] && r2[3] >= r1[1]) return 1;
//otherwise they do not overlap
else return 0;

}