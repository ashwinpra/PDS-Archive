//Program to input coeffs of quadratic eqn, and display it
//Also to check whether roots are real, complex or coincident
//If complex, check quadrant of a+ib type root

#include<stdio.h>
#include<math.h>

int main(){

	//Declaring coeffs of quadratic equation and discriminant
	float a,b,c;
	float d;

	//Getting a,b,c from user
	printf("a: ");
	scanf("%f",&a);
	printf("b: ");
	scanf("%f",&b);
	printf("c: ");
	scanf("%f",&c);

    //Displaying the quadratic eqn as required
    if(b<0 && c<0){
        if(b==-1 && a==-1){
            printf("-x^2 - x - %0.1f = 0\n",-c);
        }
        else if(b==-1 && a==1){
            printf("x^2 - x - %0.1f = 0\n",-c);
        }
        else if(b==-1 && a!=1 && a!=-1){
            printf("%0.1fx^2 - x - %0.1f = 0\n",a,-c);
        }
        else if(b!=-1 && a==1){
            printf("x^2 - %0.1fx - %0.1f = 0\n",-b,-c);
        }
        else if(b!=-1 && a==-1){
            printf("-x^2 - %0.1fx - %0.1f = 0\n",-b,-c);
        }
        else{
            printf("%0.1fx^2 - %0.1fx - %0.1f = 0\n",a,-b,-c);
        }
    }
    else if(b<0 && c>0){
        if(b==-1 && a==-1){
            printf("-x^2 - x + %0.1f = 0\n",c);
        }
        else if(b==-1 && a==1){
            printf("x^2 - x + %0.1f = 0\n",c);
        }
        else if(b==-1 && a!=1 && a!=-1){
            printf("%0.1fx^2 - x + %0.1f = 0\n",a,c);
        }
        else if(b!=-1 && a==1){
            printf("x^2 - %0.1fx + %0.1f = 0\n",-b,c);
        }
        else if(b!=-1 && a==-1){
            printf("-x^2 - %0.1fx + %0.1f = 0\n",-b,c);
        }
        else{
            printf("%0.1fx^2 - %0.1fx + %0.1f = 0\n",a,-b,c);
        }
    }
    else if(b>0 && c<0){
        if(b==1 && a==-1){
            printf("-x^2 + x - %0.1f = 0\n",-c);
        }
        else if(b==1 && a==1){
            printf("x^2 + x - %0.1f = 0\n",-c);
        }
        else if(b==1 && a!=1 && a!=-1){
            printf("%0.1fx^2 + x - %0.1f = 0\n",a,-c);
        }
        else if(b!=1 && a==1){
            printf("x^2 + %0.1fx - %0.1f = 0\n",b,-c);
        }
        else if(b!=1 && a==-1){
            printf("-x^2 + %0.1fx - %0.1f = 0\n",b,-c);
        }
        else{
            printf("%0.1fx^2 + %0.1fx - %0.1f = 0\n",a,b,-c);
        }
    }
    else{
        if(b==1 && a==-1){
            printf("-x^2 + x + %0.1f = 0\n",c);
        }
        else if(b==1 && a==1){
            printf("x^2 + x + %0.1f = 0\n",c);
        }
        else if(b==1 && a!=1 && a!=-1){
            printf("%0.1fx^2 + x + %0.1f = 0\n",a,c);
        }
        else if(b!=1 && a==1){
            printf("x^2 + %0.1fx + %0.1f = 0\n",b,c);
        }
        else if(b!=1 && a==-1){
            printf("-x^2 + %0.1fx + %0.1f = 0\n",b,c);
        }
        else{
            printf("%0.1fx^2 + %0.1fx + %0.1f = 0\n",a,b,c);
        }
    }


    //calculating discriminant to find nature of roots
	d = (pow(b,2)-4*a*c);

    //displaying input as per nature of "d"
    if(d>0){
        printf("\nRoots: Real\n");
        }
    else if(d==0){
        printf("\nRoots: Coincident\n");
    }
    else if (d<0){
        printf("\nRoots: Complex\n");
        float re = (float)(-b/(2*a));
        float im = (float)((sqrt(-d))/(2*a));
        //first root => (-b/2a)+i(sqrt(-d)/2a), in this case taking -d to get real square root
        //Determining quadrant of root based on real and imaginary part of first root
        if(re>=0 && im>0){
            printf("Quadrant of 1st complex root: 1st");
        }
        else if(re<0 && im>0){
            printf("Quadrant of 1st complex root: 2nd");
        }
        else if(re<0 && im<0){
            printf("Quadrant of 1st complex root: 3rd");
        }
        else if(re>=0 && im<0){
            printf("Quadrant of 1st complex root: 4th");
        }
    }


	return 0;
}
