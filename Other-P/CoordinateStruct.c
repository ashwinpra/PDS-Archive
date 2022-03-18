#include<stdio.h>
#include<math.h>
typedef struct point{
    float x, y;
}pt;

float distance(pt,pt);
pt midpoint(pt,pt);
float areaOfTriangle(pt,pt,pt);

int main(int argc, char const *argv[])
{
    pt p1,p2,p3;
    printf("Enter coordinates of p1 in the form x y :");
    scanf("%f %f",p1.x,p1.y);
    printf("Enter coordinates of p2 in the form x y :");
    scanf("%f %f",p2.x,p2.y);
    printf("Enter coordinates of p3 in the form x y :");
    scanf("%f %f",p3.x,p3.y);

    return 0;
}

float distance(pt a,pt b){
    float d2 = (float)(pow((a.x - b.x),2)+pow((a.y - b.y),2));
    return sqrt((d2));
}

pt midpoint(pt a,pt b){
    pt c = {(a.x+b.x)/2,(a.y+b.y)/2};
    return c;
}

float areaOfTriangle(pt a,pt b,pt c){
    //too much to write 
}