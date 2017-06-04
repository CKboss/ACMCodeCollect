#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int mx = INT_MIN/2;

        int temp=0;
        for(int i=0;i<n;i++)
        {
            mx = max(mx,nums[i]);
        }

        if(mx<0) return mx;

        for(int i=0;i<n;i++)
        {
            temp+=nums[i];
            if(temp<0) temp=0;

            mx = max(temp,mx);
        }
        return mx;
    }
};

int main()
{
    //vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v={-1};
    Solution s;
    assert(s.maxSubArray(v)==-1);
    return 0;
}
