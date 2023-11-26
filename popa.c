#include <stdio.h>
int main(
)
{
    for (double i = 0; i < 300000; i+=10.0)
    {
        int kek = (int)i % 1000;
        printf("%d\n", kek);
    }
}