//Program to find difference of sum of last 3 digits and sum of first 2 digits of a 5 digit no.
//Also to print reverse of last 3 digits
//Using positional notation

int main(){

int num,diff,reverse;
// 5 integers corresponding to each digit of "num"
int d1,d2,d3,d4,d5;

//printf and scanf to get required 5 digit no.
printf("Enter 5 digit number:\n");
scanf("%d",&num);

//using floor and positional notation logic to get each digit of num
d1 = num/10000;
d2 = num/1000 - 10*d1;
d3 = num/100 - 10*d2 - 100*d1;
d4 = num/10 - 10*d3 - 100*d2 - 1000*d1;
d5 = num - 10*d4-100*d3-1000*d2-10000*d1;

return 0;
}
