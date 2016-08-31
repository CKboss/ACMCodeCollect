#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

typedef long long int LL;

const LL mod = 1e9+7;
const int maxn = 1000100;

LL Wrong[maxn];

LL inv[maxn];
LL jc[maxn],jcv[maxn];

void init()
{
    Wrong[0]=1; Wrong[1]=0; Wrong[2]=1;
    for(int i=3;i<maxn;i++) Wrong[i]=((i-1)*(Wrong[i-1]+Wrong[i-2]))%mod;

    inv[1]=1;jc[0]=1;jcv[0]=1;
    jc[1]=1;jcv[1]=1;
    for(int i=2;i<maxn;i++)
    {
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        jc[i]=(jc[i-1]*i)%mod;
        jcv[i]=(jcv[i-1]*inv[i])%mod;
    }
}

LL C(LL n,LL m)
{
    LL ret = ((jc[n]*jcv[n-m])%mod*jcv[m])%mod;
    return ret;
}

int main()
{
    init();
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        LL n,m;
        scanf("%lld%lld",&n,&m);
        LL ret = (Wrong[n-m]*C(n,m))%mod;
        printf("%lld\n",ret);
    }
    return 0;
}
