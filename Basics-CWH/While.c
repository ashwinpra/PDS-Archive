#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 0;
    int num;
    printf("Enter upper limit:\n");
    scanf("%d", &num);
    while (x <= num)
    {
        printf("%d\n", x);
        x = x + 1;
    }
    return 0;
}
