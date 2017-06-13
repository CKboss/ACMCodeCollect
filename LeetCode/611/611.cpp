#include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    int n;
    vector<int> nums;

    int binS(int fr,int to,int sum)
    {
        int low=fr,high=to;
        int mid=-1;
        int ans = -1;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(sum>nums[mid])
            {
                low = mid+1;
                ans = mid;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }

    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        this->nums = nums;
        n = nums.size();

        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int pos = binS(j+1,n-1,nums[i]+nums[j]);
                //cout<<i<<" "<<j<<" "<<pos<<endl;
                if(pos!=-1)
                {
                    cnt += pos - (j+1) + 1;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<int> v = {2,2,3,4};
    Solution s;
    cout<<s.triangleNumber(v)<<endl;
    return 0;
}
