#include <bits/stdc++.h>

using namespace std;

const int maxn = 26000;
const int INF = 0x3f3f3f3f;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int tree[maxn<<2];

void push_up(int rt)
{
    tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=INF;
        return;
    }

    int m = (l+r)/2;

    build(lson); build(rson);

    push_up(rt);
}


void insert(int P,int V,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=V;
        return ;
    }


    int m = (l+r)/2;

    if(P<=m)
    {
        insert(P,V,lson);
    }
    else
    {
        insert(P,V,rson);
    }

    push_up(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return tree[rt];
    }

    int m = (l+r)/2;

    int ret=INF;

    if(L<=m)
    {
        ret = min(ret,query(L,R,lson));
    }

    if(R>m)
    {
        ret = min(ret,query(L,R,rson));
    }

    return ret;
}

void show_tree(int l,int r,int rt)
{
    printf("%d: %d <--> %d mi: %d\n",rt,l,r,tree[rt]);
    if(l==r) return;

    int m = (l+r)/2;

    show_tree(lson);
    show_tree(rson);
}


class Solution {

public:

    int n;
    int dp[maxn];


    int jump(vector<int>& a) 
    {
        n = a.size();

        build(0,n-1,1);

        memset(dp,63,sizeof(dp));
        dp[n-1]=0;

        insert(n-1,0,0,n-1,1);

        for(int i=n-2;i>=0;i--)
        {

            if(i+a[i]>=n)
            {
                dp[i]=1;
                insert(i,1,0,n-1,1);
                continue;
            }

            // range [ i , i+a[i] ]
            int l = i;
            int r = min(i+a[i],n-1);

            int mi = query(l,r,0,n-1,1);
            dp[i] = mi + 1;

            insert(i,dp[i],0,n-1,1);

            // query [l,r] min
            // dp[i] = min[l...r] + 1

            /*
            for(int j=l;j<=r;j++)
            {
                dp[i] = min(dp[i],dp[j]+1);
            }
            */
        }

        return dp[0];
    }
};

int main()
{

    /*
    build(1,5,1);

    show_tree(1,5,1);

    insert(2,3,1,5,1);

    show_tree(1,5,1);

    cout<<query(1,4,1,5,1)<<endl;
    cout<<query(3,4,1,5,1)<<endl;

    */
    Solution s;

    vector<int> v = {2,3,1,1,4};
    //vector<int> v = {0};

    cout<<s.jump(v)<<endl;

    return 0;
}
