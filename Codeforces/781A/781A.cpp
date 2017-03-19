#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
const int maxn=200200;

vector<int> G[maxn];
int color[maxn];
int K=1;

void dfs(int u,int fa)
{
	int C=1;
	for(int i=0,sz=G[u].size();i<sz;i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		// give color
		while(C==color[u]||C==color[fa]) C++;
		color[v]=C;
		K = max(K,C);
		C++;
		dfs(v,u);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v); G[v].push_back(u);
	}

	color[1]=1;
	dfs(1,1);

	printf("%d\n",K);
	for(int i=1;i<=n;i++) printf("%d ",color[i]);

	return 0;
}
