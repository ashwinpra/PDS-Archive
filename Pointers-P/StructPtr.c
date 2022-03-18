#include<stdio.h>
 
typedef struct{
    int id,age;
    float cgpa;
}student;

student *p;

int main() {
    student x = {10,20,3.5};
    p = &x;
    printf("Student id = %d, age = %d, cgpa = %f\n",(*p).id, (*p).age,(*p).cgpa);
    printf("Student id = %d, age = %d, cgpa = %f\n",p->id,p->age,p->cgpa);
    //both lines have the same function 
    student y[10],*ptr;
    ptr = y;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&y[i].id,&y[i].age);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Student id = %d, age = %d\n",y[i].id,y[i].age);
        printf("Student id = %d, age = %d\n",ptr[i].id,ptr[i].age);
        printf("Student id = %d, age = %d\n",*(ptr+i).id,*(ptr+i).age);
        printf("Student id = %d,age = %d\n",(ptr+i)->id,(ptr+i)->age);
    }
    // -> operator has most precedence 
    // ++ ptr -> roll means ptr->roll is incremented 
    // (++ptr) -> roll means (ptr+1)-> roll is accessed
    

    return 0;
}
