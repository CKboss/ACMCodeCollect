#include <bits/stdc++.h>


using namespace std;

typedef long long int LL;
const int maxn = 3030;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n;
LL x[maxn],c[maxn];

LL dp[maxn][2];
LL sum[maxn];

struct Node
{
    int x,c;
};

bool cmp(Node a,Node b)
{
    return a.x<b.x;
}

int main()
{

while(scanf("%d",&n)!=EOF)
{
    vector<Node> vi;
    for(int i=0;i<n;i++)
    {
        int x,c;
        scanf("%d%d",&x,&c);
        vi.push_back((Node){x,c});
    }

    sort(vi.begin(),vi.end(),cmp);

    for(int i=0;i<n;i++) 
    {
        x[i] = vi[i].x;
        c[i] = vi[i].c;
        if(i>0) sum[i]=sum[i-1]+x[i];
        else sum[0]=x[0];
    }

    memset(dp,63,sizeof(dp));

    dp[0][0] = INF;
    dp[0][1] = c[0];

    for(int i=1;i<n;i++)
    {
        // build shop at postion i
        dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + c[i];

        for(int j=i-1;j>=0;j--)
        {
            // do not build shop at postion j+1 ... i
            dp[i][0] = min( dp[i][0], dp[j][1]+sum[i]-sum[j]-(i-j)*x[j]);
        }

    }

    //printf("%lld\n",min(dp[n-1][0],dp[n-1][1]));
    printf("%I64d\n",min(dp[n-1][0],dp[n-1][1]));
}
    return 0;
}
