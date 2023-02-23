#include <stdio.h>
int main()
{
    push(10);
    push(20);
    push(30);

    Display();

    printf("%d ", pop());

    return 0;
}
