/* Menu-driven C program that declared two structures named: 
(i) Circle - has 3 integer members, radius r, x and y coordinates of centre 
(ii) Triangle - having perpendicular, hypotenuse and base as integer members
Performs following operations: 
(i) check_circle -> checks if two circles intersect or touch each other or not
if intersect then return 2, if touch then 1, else 0
(ii) check_triangle -> first checks if triangle is right angled. If not, then return 2
if right angled, then check if area of incircle of rt. triangle = area of circle (after rounding)
if yes, then return 1, else 0 */
#include<stdio.h>
#include<math.h>

const int pi = 3.14; //defining value of constant pi

typedef struct{
    int r,x,y;
}circle;
typedef struct{
    int p,h,b;
}triangle;

int check_circle(circle,circle);
int check_triangle(circle,triangle);
int check_right(triangle);//checks if triangle is right triangle
float dist(circle,circle); //To calculate distance between centres of two circles
int menu(); //To display menu everytime and return user input

int main()
{
    int choice; //To store user's menu choice
    char cont_choice='y'; //stores user's choice of continuing 
   
   //while loop which will keep going as long as user does not wish to continue
    while(cont_choice=='y'){
        choice = menu(); //getting user's choice through function
        //executing required function as per user's choice
        if (choice==1)
        {
            //Declaring 2 circle structures and taking user input for their members
            circle c1,c2; 
            printf("Enter radius, x and y coordinate values for circle A: ");
            scanf("%d %d %d",&c1.r,&c1.x,&c1.y);
            printf("Enter radius, x and y coordinate values for circle B: ");
            scanf("%d %d %d",&c2.r,&c2.x,&c2.y);
            //Passing these circles through function and displaying output accordingly
            int result = check_circle(c1,c2);
            if(result == 0) printf("Circle A and B are not touching each other\n");
            else if(result ==1) printf("Circle A and B are touching each other\n");
            else if(result ==2) printf("Circle A and B are intersecting each other\n");
        }
        else if(choice==2){
            //Declaring circle and triangle structures and taking user input for their members
            circle c1;
            triangle t1;
            printf("Enter the values of p,b,h of the triangle: ");
            scanf("%d %d %d",&t1.p,&t1.b,&t1.h);
            printf("Enter radius value of the circle: ");
            scanf("%d",&c1.r);
            //Passing these through function and displaying output accordingly
            int result = check_triangle(c1,t1);
            if(result==0) printf("The area of the circle is not equal to the area of the incircle of the triangle\n");
            else if(result==1) printf("The area of the circle is equal to the area of the incircle of the triangle\n");
            else if(result==2) printf("The triangle is not right-angled\n");
        }
        else printf("Invalid input\n"); //Error if user enters invalid choice

        //Asking user whether they want to continue
        printf("Do you want to continue(y/n): \n");
        scanf(" %c",&cont_choice);
    }



   

    return 0;
}

int menu(){
    int x;
    printf("--------MENU--------\n");
    printf("1. Check circles\n");
    printf("2. Check triangle\n");
    printf("Enter your choice: ");
    scanf("%d",&x);
    return x;
}

float dist(circle c1,circle c2){
    //calculating distance between centres of c1 and c2 using distance formula
    float d = (float)(pow((c1.x-c2.x),2) + pow((c1.y-c2.y),2));
    d = (float)(sqrt(d));
    return d;
}

int check_circle(circle c1,circle c2){
    int rsum = c1.r + c2.r; //stores sum of radii
    float distance = dist(c1,c2); //stores distance between centres
    //checks their relation and returns corresponding value
    if(distance == rsum) return 1;
    else if (distance > rsum) return 0;
    else if (distance < rsum) return 2;
}
//returns 1 if right, 0 otherwise
int check_right(triangle t){
    //is right angled if p^2 + b^2 = h^2
    int a = (int)(pow(t.p,2)+pow(t.b,2));
    int b = (int)(pow(t.h,2));
    if(a==b) return 1; 
    else return 0;

}

int check_triangle(circle c1, triangle t1){
    if(check_right(t1)){
        float inradius = (float)((t1.p+t1.b-t1.h)/2); //storing inradius of right triangle
        int ai = (int)(pi*pow(inradius,2)); //stores area of incircle 
        int ac= (int)(pi*pow(c1.r,2)); //stores area of circle
        //checking if they are equal or not and returns corresponding value
        if(ai==ac) return 1;
        else return 0;
    }
    else return 2;
}