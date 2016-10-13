#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int LL;

const int maxn=3333;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n,m;
int a[maxn];

LL *f,*g;

LL sum[maxn];
LL dp[2][maxn];

inline LL square(LL x) { return x*x; }

double slop(int i,int j)
{
    return double(g[i]+sum[i]*sum[i]-g[j]-sum[j]*sum[j])/(sum[i]-sum[j]);
}

int l,r;
int q[maxn];


int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",a+i);
            sum[i] = sum[i-1] + a[i];
        }

        f=dp[0];g=dp[1];
		for(int i=1;i<=n;i++) f[i]=sum[i]*sum[i];
		
		for(int x=1;x<m;x++)
		{
		    swap(f,g); l=1;r=1; q[1]=0;
            for(int i=1;i<=n;i++)
            {
                while(l<r&&slop(q[l],q[l+1])<2*sum[i]) l++;
                f[i]=g[q[l]]+square(sum[i]-sum[q[l]]);
                while(l<r&&slop(q[r],q[r-1])>slop(q[r],i)) r--;
                q[++r]=i;
            }
		}

		cout<<f[n]*m-square(sum[n])<<endl;
    }
    return 0;
}
