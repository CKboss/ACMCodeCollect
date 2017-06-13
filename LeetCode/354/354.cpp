#include <bits/stdc++.h>

using namespace std;

class Solution 
{

public:

    bool check(pair<int,int> a,pair<int,int> b)
    {
        if(a.first<b.first&&a.second<b.second) return true;
        return false;
    }

    int maxEnvelopes(vector<pair<int, int>>& v) 
    {
        int sz=v.size();
        sort(v.begin(),v.end());

        int mx = 0;
        vector<int> dp(2*sz);
        for(int i=0;i<sz;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(check(v[j],v[i])) dp[i] = max(dp[i],dp[j]+1);
            }
            if(dp[i]>mx) mx = dp[i];
        }

        return mx;
    }
};

int main()
{

    //vector<pair<int,int>> v = {{5,4},{6,4},{6,7},{2,3}};
    vector<pair<int,int>> v = {{4,5},{4,6},{6,7},{2,3},{1,1}};
    Solution s;
    cout<<s.maxEnvelopes(v)<<endl;
    return 0;
}
