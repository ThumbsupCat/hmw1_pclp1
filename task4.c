#include <stdio.h>
#include <math.h>

#define BITS sizeof(unsigned int) * 8
#define BITS1 sizeof(unsigned short) * 8

int semne[10], sum;

unsigned int findn(unsigned int n)
{
    n = n >> (BITS - 3);
    return n;
}

void operatii(unsigned int n, int i, int N)
{
    if(N >= i){
    int op = n << 3;
    op = n >> (BITS - 3 - 2 * i);
    int mask = 3;
    op = op & mask;
    semne[i] = op;
    operatii(n,i+1,N);
    }

}

unsigned int dim(unsigned int n, int N)
{
    n = n >> (BITS-3-2*N-4);
    int mask = 15;
    n= n & mask;
    return n+1;
}

void task2(unsigned short dimen, unsigned short i, unsigned short N) 
{
    unsigned short  operand, copie, j = 0, v[20] = {0};
    int  mask = 1 << (BITS1), mask1 = 1 << (BITS1 - dimen); 
    mask--;
    mask1--;
    mask = mask ^ mask1;
    for(int k = 0; k < i; k++){
        scanf("%hd", &operand); 
        copie = 0;  
        while(operand != 0){
            copie = operand;
            copie &= mask;
            copie = copie >> (BITS1 - dimen);
            operand = operand << dimen;
            v[j++] = copie;
        }
    }
    j = 1;
    sum = v[0];
    for(int k = 1; k <= N ; k++){
        if(semne[k] == 2)
            v[k] = v[k] * v[k+1];
        else if(semne[k] == 3)
            v[k] = v[k] / v[k+1];
    }
    for(int k = 1; k <= N; k++){
        if(semne[k] == 0)
            sum+= v[k];
        else if(semne[k] == 1)
            sum-= v[k];
    }
    printf("%d\n", sum); 
}

int main()
{
    unsigned short dimen, nroper1;
    unsigned int inst;
    float nroper ;
    scanf("%u", &inst);
    unsigned short N = findn(inst)+1; 
    operatii(inst,1,N);
    dimen = dim(inst, N);
    nroper = N+1;
    nroper = nroper * dimen / 16;
    nroper1 = ceil(nroper);
    task2(dimen,nroper1,N);
    return 0;
}