#include <stdio.h>
#define BITS sizeof(unsigned int) * 8


unsigned int findn(unsigned int n)
{
    n = n >> (BITS - 3);
    return n;
}

void operatii(unsigned int n, int i, int N)
{
    if(N >= i){
    int op = n << 3;
    op = n >> (BITS - 3 - 2*i);
    int mask = 3;
    op = op & mask;
    if(op == 0)
        printf("+ ");
    else if(op == 1)
        printf("- ");
    else if(op == 2)
        printf("* ");
    else 
        printf("/ ");
    operatii(n,i+1,N);
    }

}

unsigned int dim(unsigned int n, int N)
{
    n = n >> (BITS - 3 - 2 * N - 4);
    int mask = 15;
    n = n & mask;
    printf("%d\n", n + 1);
    return n;
}

int main()
{
    unsigned int inst;
    scanf("%u", &inst);
    printf("%d ", findn(inst) + 1);
    unsigned int N = findn(inst) + 1; 
    operatii(inst, 1, N);
    dim(inst, N);
}