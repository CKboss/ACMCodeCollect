#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:

    int n;
    int sum[10100];

    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        n = nums.size();

        if(n<2) return false;

        if(k==0) 
        {
            for(int i=0;i-1<n;i++)
            {
                if(nums[i]==nums[i+1]&&nums[i]==0)
                    return true;
            }
            return false;
        }

        sum[0]=nums[0]%k;
        for(int i=1;i<n;i++)
        {
            sum[i]=(sum[i-1]+nums[i])%k;
        }

        for(int i=2;i<=n;i++)
        {
            for(int l=0;l+i-1<n;l++)
            {
                int r = l+i-1;

                int left = 0;
                if(l-1>=0) left = sum[l-1];

                /*
                cout<<i<<" , "<<l<<endl;
                cout<<r<<" "<<sum[r]<<" "<<left<<endl;
                */

                if((sum[r]-left+k)%k==0) return true;
            }
        }
        return false;
    }
};

int main()
{
    //vector<int> v = {23,2,6,4,7};
    //int k = 6;

    vector<int> v = {1,2,3};
    int k = 5;

    Solution s;
    cout<<s.checkSubarraySum(v,k)<<endl;

    return 0;
}
