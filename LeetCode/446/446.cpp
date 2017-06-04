#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int INF = 0x3f3f3f3f;

class Solution {

public:

    int n;


    int numberOfArithmeticSlices(vector<int>& v) 
    {
        n = v.size();
        int ret = 0;
        
        vector< unordered_map <int,int> > dp(n+10);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                LL dur = (LL)v[i]-(LL)v[j];

                if(dur>INT_MAX||dur<INT_MIN) continue;

                int dj = dp[j][(int)dur];
                dp[i][dur] += dj+1;
                ret += dj;
            }
        }

        return ret;
    }

};

int main()
{
    vector<int> v1 = {0,1,2,2,2};
    vector<int> v2 = {2,4,6,8,10};
    //vector<int> v3; for(int i=0;i<200;i++) v3.push_back(i);
    //vector<int> v4 = {0,2000000000,-294967296};
    //vector<int> v5 = {-2147483648,0,-2147483648};

    //v1 = {1,2,3,4,5,6};
    Solution s;
    //cout<<s.numberOfArithmeticSlices(v1)<<endl;
    cout<<s.numberOfArithmeticSlices(v2)<<endl;
    //cout<<s.numberOfArithmeticSlices(v3)<<endl;
    //cout<<s.numberOfArithmeticSlices(v4)<<endl;
    //cout<<s.numberOfArithmeticSlices(v5)<<endl;

    return 0;
}
