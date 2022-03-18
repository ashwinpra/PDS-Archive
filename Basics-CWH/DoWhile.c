#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 0;
    int num;
    printf("Enter upper limit\n");
    scanf("%d", &num);
    do
    {
        printf("%d\n", x);
        x = x + 1;
    } while (x <= num);
    return 0;
}
