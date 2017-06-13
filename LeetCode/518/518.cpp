#include <bits/stdc++.h>

using namespace std;

int dp[5500][500];

class Solution 
{

public:

    int n;
    vector<int> coins;

    int dfs(int remain,int p)
    {
        if(remain<0) return 0;
        if(remain==0) return 1;

        if(dp[remain][p]!=-1) return dp[remain][p];

        int ret = 0;

        ret = dfs(remain-coins[p],p);

        if(p+1<n) ret += dfs(remain,p+1);

        dp[remain][p]=ret;

        return ret;
    }

    int change(int amount, vector<int>& coins) 
    {
        this->coins = coins;
        n = coins.size();
        memset(dp,-1,sizeof(dp));

        if(n==0&&amount==0) return 1;
        if(n==0) return 0;

        return dfs(amount,0);
    }

};


int main()
{

    int ammount = 5;
    vector<int> coins = {1,2,5};

    Solution s;

    int x = s.change(ammount,coins);
    cout<<x<<endl;

    return 0;
}
