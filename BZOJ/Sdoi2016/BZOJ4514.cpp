#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long int LL;

const int maxn=222*222;
const LL INF=0x3f3f3f3f3f3f3f3f;

int n;
LL a[222], b[222], c[222]; 

// max cost max flow

struct Edge
{
    LL to,next,cap,flow,cost;
}edge[maxn];

int Adj[maxn],Size,N;

void init()
{
    memset(Adj,-1,sizeof(Adj)); Size=0;
}

void addedge(int u,int v,LL cap,LL cost)
{
    edge[Size].to=v;
    edge[Size].next=Adj[u];
    edge[Size].cost=cost;
    edge[Size].cap=cap;
    edge[Size].flow=0;
    Adj[u]=Size++;
}

void Add_Edge(int u,int v,LL cap,LL cost)
{
    addedge(u,v,cap,cost);
    addedge(v,u,0,-cost);
}

LL dist[1000];
int vis[1000],pre[1000];

bool spfa(int s,int t)
{
    queue<int> q;
    for(int i=0;i<N;i++)
    {
        dist[i]=-INF; vis[i]=false; pre[i]=-1;
    }
    dist[s]=0; vis[s]=true; q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]=false;
        for(int i=Adj[u];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>edge[i].flow&&dist[v]<dist[u]+edge[i].cost)
            {
                dist[v]=edge[i].cost+dist[u];
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=true; q.push(v);
                }
            }
        }
    }
    if(pre[t]==-1) return false;
    return true;
}

LL MaxCostMaxFlow(int s,int t,LL& cost)
{
    LL flow=0;
    cost=0;
    while(spfa(s,t))
    {
        LL Min=INF;
        for(int i=pre[t];~i;i=pre[edge[i^1].to])
        {
            if(Min>edge[i].cap-edge[i].flow)
                Min=edge[i].cap-edge[i].flow;
        }

        /// 准备在费用将要小于0的时候跳出
        if(cost+dist[t]*Min<0)
        {
            Min = min(Min,cost/(-dist[t]));
            if(Min<=0) break;
        }

        for(int i=pre[t];~i;i=pre[edge[i^1].to])
        {
            edge[i].flow+=Min;
            edge[i^1].flow-=Min;
            cost+=edge[i].cost*Min;
        }

        flow+=Min;

        //cout<<"in mcmf: "<<Min<<"   "<<cost<<endl;
    }
    return flow;
}

bool isPrime(LL x)
{
    if(x==1) return false;
    if(x==2) return true;
    for(LL i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}

bool isLink(LL a1,LL a2)
{
    if(a1>a2) swap(a1,a2);
    if(a2%a1!=0) return false;
    LL c = a2/a1;
    return isPrime(c);
}

int getKind(LL x)
{
    int cnt=0;
    for(LL i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            x/=i;
            cnt++;
        }
    }
    if(x!=1) cnt++;
    return cnt%2;
}

int main()
{
while(scanf("%d",&n)!=EOF)
{
    init();
    int S=0,T=n+1;
    N=n+2;

    vector<int> v[2];

    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",a+i);
        v[getKind(a[i])].push_back(i);
    }
    for(int i=1;i<=n;i++) scanf("%lld",b+i);
    for(int i=1;i<=n;i++) scanf("%lld",c+i);


    for(int i=0,sz=v[0].size();i<sz;i++)
    {
        int x = v[0][i];
        Add_Edge(S,x,b[x],0);
    }
    for(int i=0,sz=v[1].size();i<sz;i++)
    {
        int x = v[1][i];
        Add_Edge(x,T,b[x],0);
    }

    for(int i=0,sz1=v[0].size();i<sz1;i++)
    {
        int x = v[0][i];
        for(int j=0,sz2=v[1].size();j<sz2;j++)
        {
            int y = v[1][j];
            if(isLink(a[x],a[y]))
            {
                Add_Edge(x,y,INF,c[x]*c[y]);
            }
        }
    }

    LL cost,flow;
    flow=MaxCostMaxFlow(S,T,cost);

    //printf("flow: %lld cost: %lld\n",flow,cost);

    printf("%lld\n",flow);
}
    return 0;
}
