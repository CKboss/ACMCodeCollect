#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int gcd(int n,int m)
{
    if(n==0) return m;
    return gcd(m%n,n);
}

int n;
int a[maxn];
int pre[maxn],suf[maxn];

int main()
{
    int T_T;
    scanf("%d",&T_T);
while(T_T--)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",a+i);
    }
    pre[0]=a[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=gcd(pre[i-1],a[i]);
    }
    suf[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suf[i]=gcd(suf[i+1],a[i]);
    }
    int ans = max(pre[n-2],suf[1]);
    for(int i=1;i<n-1;i++)
    {
        ans = max(ans,gcd(suf[i+1],pre[i-1]));
    }
    printf("%d\n",ans);
}
    return 0;
}


