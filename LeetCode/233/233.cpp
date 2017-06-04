#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:

    int a[33],nc;
    int dp[30]={1,20,300,4000,50000,600000,7000000,80000000,900000000};
    int pow[30]={10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

    void fj(int n) { nc=0; while(n) { a[nc++]=n%10; n/=10; } }//reverse(a,a+nc); }

    int dfs(int p,int ones,bool limit)
    {

        if(p<0) { return ones; }

        bool CACHE=true;
        if(CACHE&&limit==false&&dp[p]!=-1) 
        { 
            return ones*pow[p]+dp[p]; 
        }


        int ret = 0;

        int mi = 9;
        if(limit==true) mi = min(a[p],9);

        for(int i=0;i<=mi;i++)
        {
            int nones = ones;
            if(i==1) nones++;

            bool nlimit = limit;
            if(limit==true&&i<a[p]) nlimit=false;

            ret += dfs(p-1,nones,nlimit);
        }

        return ret;
    }

    int countDigitOne(int n) 
    {
        if(n==0) return 0;
        fj(n);

        for(int i=0;i<nc;i++) cout<<a[i]<<"."; cout<<endl;

        int ans = dfs(nc-1,0,true);

        return ans;
    }

};

int main()
{
    Solution s;
    cout<<s.countDigitOne(824883294)<<endl;
    cout<<s.countDigitOne(13)<<endl;
    /*
    int e = 9;
    for(int i=1;i<=10;i++)
    {
        int x = s.countDigitOne(e);
        cout<<e<<" ---> "<<x<<endl;
        e = e*10+9;
    }
    */
    return 0;
}
