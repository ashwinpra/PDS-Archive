//Program to find the winner of a game of cards by seeing who has the greatest numerical total from 5 cards
//Players: Alice, Bob, Sarah
// A=1, J=11,K=12,Q=13
#include<stdio.h>
//defining const int for size of all arrays
const int size=5;
int counting_cards(char []); //Function declaration

int main(){
    //3 arrays for cards of 3 players, and 3 ints for sum of cards of them
    char Alice[size],Bob[size],Sarah[size];
    int asum,bsum,ssum;
    //taking cards of players from user
    printf("Alice: ");
    scanf("%s",Alice);
    printf("Bob: ");
    scanf("%s",Bob);
    printf("Sarah: ");
    scanf("%s",Sarah);
    printf("\n");
    //finding sum using the function
    asum=counting_cards(Alice);
    bsum=counting_cards(Bob);
    ssum=counting_cards(Sarah);
    //displaying the sum
    printf("Alice total: %d\n",asum);
    printf("Bob total: %d\n",bsum);
    printf("Sarah total: %d\n",ssum);
    //if conditions to check the winner, or whether its tied
    if(asum>bsum && asum>ssum) printf("Alice wins!");
    else if(bsum>asum && bsum>ssum) printf("Bob wins!");
    else if(ssum>bsum && ssum>asum) printf("Sarah wins!");
    else printf("Game Tied");

    return 0;
}
//Function for counting sum of card values 
int counting_cards(char arr[]){
    int sum=0;
    //going through the array and adding value of each card accordingly 
    for(int i=0;i<size;i++){
    if(arr[i]>'1' && arr[i]<='9') sum+=(arr[i]-'0'); 
    //subtracted '0' so that actual value of number is added rather than its ascii code
    //if its not a number but is J/K/Q/A, its corresponding value is added
    else if(arr[i]=='J') sum+=11;
    else if(arr[i]=='K') sum+=12;
    else if(arr[i]=='Q') sum+=13;
    else if(arr[i]=='A') sum+=1;
    }
    //sum is returned at the end
    return sum;
}
