//Program to evaluate fund contribution based on Basic Pay and Dearness Allowance
//Final answer is displayed as nearest integer

#include<stdio.h>

int main()
{
    int basic_pay, da;
    int fund_contr;

    //Two printf and scanf statements to get Basic Pay and DA
    printf("Basic Pay: \n");
    scanf("%d",&basic_pay);
    printf("Dearness Allowance (DA): \n");
    scanf("%d",&da);

    //fund contribution = 10% (basic pay) + 5% (DA)
    fund_contr = 0.1*basic_pay+ 0.05*da;
    //displays the fund contribution
    printf("Fund Contribution: %d\n",fund_contr);

    return 0;
}
