#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const LL mod=1000000007L;

LL F[6][10100];

void init()
{
    for(LL i=1;i<=10000L;i++)
    {
        LL e=1L;
        for(int j=1;j<=5;j++)
        {
            e = (e*i)%mod;
            //if(i==1000L) printf("- %lld\n",e);
            F[j][i] = ( e + F[j][i-1] ) %mod;
        }
    }
}

int main()
{
    init();
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        //printf("%lld\n",F[k][n]);
        if(k!=0) cout<<F[k][n]<<endl;
        else cout<<n<<endl;
    }
    return 0;
}
