#include <stdio.h>



int main()
{
    long long int n;
    int b;
    long long int sum=0;
    int i=1;

    scanf("%lld %d",&n,&b);
    while(n>0)
    {

        sum+=(n%b)*i;
        i*=10;
        n/=b;


    }
    printf("%lld",sum);
    return 0;
}
