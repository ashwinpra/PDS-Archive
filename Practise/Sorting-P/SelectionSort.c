#include<stdio.h>
//set min to location 0 
//search minimum element in list 
//swap with value at location MIN 
//increment min to point to next element 
//repeat until list is sorted
int main(int argc, char const *argv[])
{
    int numbers[50];
    int n=1,i=0,count=0,min_index;
    int temp;
    while(n>0){
        scanf("%d",&n);
        if (n>0)  
        {
            numbers[i]=n;
            count++;
            i++;
        }
        else break;
    }
    printf("Before sorting: ");
    for (int j=0;j<count;j++){
        printf("%d ",numbers[j]);
    }
    printf("\n");
    printf("count is %d\n",count);

    for(i=0;i<(count-1);i++){
        //we check one by one by setting min index as each i 
        min_index = i;
        for(int j=(i+1);j<count;j++){
            //if any entry is smaller than the number in min index, that is our new min entry
            if (numbers[j]<numbers[min_index])   min_index=j;        
        }
        //we swap this min entry with ith position (min-most => i=0 and so on)
        temp=numbers[min_index];
        numbers[min_index]=numbers[i];
        numbers[i]=temp;
    }
    printf("After sorting: ");
    for (int j=0;j<count;j++){
        printf("%d ",numbers[j]);
    }
    return 0;
}
