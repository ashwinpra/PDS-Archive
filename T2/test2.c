#include<stdio.h>

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int a=y2-y1;
    int b=x1-x2;
    int c=y1*(x2-x1)-x2*(y2-y1);
    int d=y4-y3;
    int e=x3-x4;
    int f=y3*(x4-x3)-x4*(y4-y3);
    if(a*e!=b*d)
    {
    int x=(b*f-e*c)/(a*e-b*d);
    int y=(a*f-d*c)/(b*d-a*e);
    if(x>=(x1>x2?x2:x1) && x<=(x1>x2?x1:x2) && x>=(x3>x4?x4:x3) && x<=(x3>x4?x3:x4))
    {
        return 1;
    }
    }
    return 0;
}

int main()
{
    int numOfInt = 0;
    int n, i, j;
    int x[100], y[100];
    printf("how many vertices? ");
    scanf("%d", &n);
    printf("Enter coords\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    x[n] = x[0];
    y[n] = y[0];
    for(i=0;i<n-2;i++)
    {
        for(j=i+2;j<n;j++)
        {
            if (i==0 && j==n-1)
            {
                break;
            }
            if(intersect(x[i],y[i],x[i+1],y[i+1],x[j],y[j],x[j+1],y[j+1]))
            {
                numOfInt+=1;
            }
        }
    }
    if (numOfInt==0)
    {
        printf("its a simple polygon");
    }
    else
    {
        printf("not simple with %d intersections", numOfInt);
    }
return 0;
}