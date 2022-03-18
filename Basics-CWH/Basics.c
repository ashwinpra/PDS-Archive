#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int num;
	char name[20];
	printf("Enter a number\n");
	scanf("%d",&num);
	printf("Your selected number is: %d\n", num); 
	printf("Now enter your name:\n");
	scanf("%s", name);
	printf("Your name is: %s\n", name);
	return 0;	
}
