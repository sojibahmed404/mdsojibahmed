#include <stdio.h>
int main()
{
    int T, N;
    long long fib[61];
    scanf("%d", &T);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 60; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int j = 1; j <= T; j++)
    {
        scanf("%d", &N);
        printf("Fib(%d) = %lld\n", N, fib[N]);
    }
    return 0;
}
