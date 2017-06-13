#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:

    int n;

    double calu(int l,int r,int* order,vector<int>& v)
    {
        if(l==r) return v[l];

        int mx=-1,P=-1;
        for(int i=l;i<r;i++)
        {
            if(order[i]>mx)
            {
                mx = order[i];
                P = i;
            }
        }

        double ret = calu(l,P,order,v) / calu(P+1,r,order,v);
        return ret;
    }

    bool vis[100];
    int order[100];

    double mxvalue = 0;
    int mxorder[100];

    void dfs(int nt,vector<int> v)
    {
        if(nt==n-1)
        {
            double val = calu(0,n-1,order,v);
            if( mxvalue < val )
            {
                for(int i=0;i<n-1;i++) mxorder[i] = order[i];
                mxvalue = val;
            }
            return ;
        }

        for(int i=0;i<n-1;i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;

                order[nt]=i;
                dfs(nt+1,v);

                vis[i]=false;
            }
        }
    }

    string optimalDivision(vector<int>& v) 
    {
        n = v.size();
        memset(vis,false,sizeof(vis));
        memset(order,false,sizeof(order));
        dfs(0,v);
        return "hello";
    }

    string calustr(int l,int r,int* order,vector<int>& v)
    {
        if(l==r) 
        {
            return to_string(v[l]);
        }

        int mx=-1,P=-1;
        for(int i=l;i<r;i++)
        {
            if(order[i]>mx)
            {
                mx = order[i];
                P = i;
            }
        }

        string ret = "(" + calustr(l,P,order,v) + "/" +  calustr(P+1,r,order,v) + ")";
        return ret;
    }
};

void debug()
{
    vector<int> v = {1000,100,10,2};
    int ord[3];
    ord[0]=2;ord[1]=0,ord[2]=1;

    Solution s;
    cout<<s.calustr(0,3,ord,v)<<endl;
}

int main()
{
    debug();
    return 0;

    vector<int> v = {1000,100,10,2};
    Solution s;
    s.optimalDivision(v);

    cout<<s.mxvalue<<" ";

    return 0;
}
