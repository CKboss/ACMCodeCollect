#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long int LL;

const LL INF=0x3f3f3f3f3f3f3f3f;
const int maxn=220000;

LL n;
LL sa[maxn],rank[maxn],rank2[maxn],h[maxn],c[maxn],*x,*y,ans[maxn];
LL str[maxn];

bool cmp(LL* r,LL a,LL b,LL l,LL n)
{
	if(r[a]==r[b]&&a+l<n&&b+l<n&&r[a+l]==r[b+l]) return true;
	return false;
}

void radix_sort(LL n,LL sz)
{
	for(int i=0;i<sz;i++) c[i]=0;
	for(int i=0;i<n;i++) c[x[y[i]]]++;
	for(int i=1;i<sz;i++) c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
}

void get_sa(LL c[],LL n,LL sz=maxn)
{
	x=rank,y=rank2;
	for(LL i=0;i<n;i++) x[i]=c[i],y[i]=i;
	radix_sort(n,sz);
	for(LL len=1;len<n;len<<=1)
	{
		LL yid=0;
		for(LL i=n-len;i<n;i++) y[yid++]=i;
		for(LL i=0;i<n;i++) if(sa[i]>=len) y[yid++]=sa[i]-len;

		radix_sort(n,sz);

		swap(x,y);
		x[sa[0]]=yid=0;

		for(LL i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i],sa[i-1],len,n)?yid:++yid;

		sz=yid+1;
		if(sz>=n) break;
	}
	for(LL i=0;i<n;i++) rank[i]=x[i];
}

void get_h(LL str[],LL n)
{
	LL k=0; h[0]=INF;
	for(LL i=0;i<n;i++)
	{
		if(rank[i]==0) continue;
		k = max(k-1,0LL);
		LL j=sa[rank[i]-1];
		while(i+k<n&&j+k<n&&str[i+k]==str[j+k]) k++;
		h[rank[i]]=k;
	}
}

/**********************************************************/

int dp[maxn][22],Log[maxn];

void init_log()
{
	Log[0]=-1;
	for(int i=1;i<=maxn;i++) Log[i]=(i&(i-1))?Log[i-1]:Log[i-1]+1;
}

void RMQ_init(int n)
{
	for(int i=0;i<n;i++) dp[i][0]=h[i];
	for(int i=1;i<=Log[n];i++)
	{
		for(int j=0;j+(1<<i)-1<n;j++)
		{
			dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
		}
	}
}

int lcp(int l,int r)
{
	//l=rank[l]; r=rank[r];
	if(l>r) swap(l,r);
	int a=l+1,b=r;
	int k=Log[b-a+1];
	return min(dp[a][k],dp[b-(1<<k)+1][k]);
}

/*************************LISAN****************************/

LL r[maxn];
LL md[maxn];

bool cmpLS(LL a,LL b)
{
	return str[a]<str[b];
}

void lisan()
{
	for(LL i=0;i<n;i++) r[i]=i;
	sort(r,r+n,cmpLS);

	LL m=0;
	md[m]=str[r[m]];
	str[r[m]]=m;

	for(int i=1;i<n;i++)
	{
		if(md[m]!=str[r[i]]) md[++m]=str[r[i]];
		str[r[i]]=m;
	}
}

/*********************************************/

set<int> st;

int QueryPre(int x)
{
	set<int>::iterator it = st.lower_bound(x);
	if(it==st.begin()) return -1;
	return *(--it);
}

int QueryNxt(int x)
{
	set<int>::iterator it = st.upper_bound(x);
	if(it==st.end()) return -1;
	return *it;
}

int main()
{
	init_log();

while(scanf("%lld",&n)!=EOF)
{
	for(int i=0;i<n;i++) scanf("%lld",str+i);

	lisan();
	reverse(str,str+n);

	get_sa(str,n);
	get_h(str,n);
	RMQ_init(n);

	LL cf = 0;
	for(int i=n-1;i>=0;i--)
	{
		int ri = rank[i];
		int L = QueryPre(ri);
		int R = QueryNxt(ri);
		/* L -- ri -- R */

		if(L!=-1&&R!=-1) cf -= lcp(L,R);
		if(L!=-1) cf += lcp(ri,L);
		if(R!=-1) cf += lcp(ri,R);

		int j = n-i-1;
		LL all = (j+2LL)*(j+1LL)/2LL;
		printf("%lld\n",all-cf);

		st.insert(ri);
	}
}
	return 0;
}

