#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

class Solution 
{

public:

    // time absent later
    int dp[2][2][3];

    int checkRecord(int n) 
    {

        memset(dp,0,sizeof(dp));

        dp[0][0][0]=1;
        dp[0][1][0]=1;
        dp[0][0][1]=1;

        int now = 1,lst = 0;

        for(int i=0;i<n-1;i++)
        {
            memset(dp[now],0,sizeof(dp[now]));
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<3;k++)
                {
                    // dp[lst][j][k] to dp[now]

                    // add P
                    dp[now][j][0] = (dp[now][j][0] + dp[lst][j][k])%mod;

                    // add A
                    if(j!=1) dp[now][j+1][0] = (dp[now][j+1][0] + dp[lst][j][k])%mod;

                    // add L
                    if(k!=2) dp[now][j][k+1] = (dp[now][j][k+1] + dp[lst][j][k])%mod;

                }
            }

            swap(now,lst);
        }

        int ret=0;
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                ret += dp[lst][j][k];
                ret = ret%mod;
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.checkRecord(4)<<endl;
    return 0;
}
