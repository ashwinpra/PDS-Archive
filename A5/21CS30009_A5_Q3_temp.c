/*Program to check whether rectangles are overlapping
Function is made to check for 2 rectangles, this is used to check how many out of 3 are overlapping

*/
#include<stdio.h>
const int size = 4
//Declaring functions
int overlap(float [], float []);



int main(){
    //coordinates stored in the form x1,y1,x2,y2
    float r1[size],r2[size],r3[size];
    printf("Note: Please enter coordinates of top-left (x1,y1) and bottom-right (x2,y2) diagonal points,\n in the format x1 y1 x2 y2");
    printf("X and Y coordinates of diagonal points of r1: ");
    scanf("%f %f %f %f", &r1[0],&r1[1],&r1[2],&r1[3]);
    printf("X and Y coordinates of diagonal points of r2: ");
    scanf("%f %f %f %f", &r2[0],&r2[1],&r2[2],&r2[3]);
    printf("X and Y coordinates of diagonal points of r3: ");
    scanf("%f %f %f %f", &r3[0],&r3[1],&r3[2],&r3[3]);
    

    return 0;
}

int overlap(float r1[], float r2[]){
/*considering r1 and base rectangle and r2 as the other, we will check if each of the 4 sides of the 
    base rectangle has any intersection with any side of other rectangle
    indices => x1:0, y1:1, x2:2, y2:3
*/
//CHECK FOR LEFT AND RIGHT SIDES 
//if top side intersects - y1 of r2 must be between y1 and y2 of r1
if(r2[1]>= r1[3] && r2[1] <= r1[1]) return 1;
//if bottom side intersects - y2 of r2 must be between y1 and y2 of r2
else if (r2[3]>= r1[3] && r2[3] <= r1[1]) return 1;


else return 0;

}