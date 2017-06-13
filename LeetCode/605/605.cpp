#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int ret=0;
        for(int i=0,sz=flowerbed.size();i<sz;i++)
        {
            if(flowerbed[i]==0)
            {
                bool flag1=false,flag2=false;
                if((i-1>=0&&flowerbed[i-1]==0)||i==0) flag1=true;
                if((i+1<sz&&flowerbed[i+1]==0)||i==sz-1) flag2=true;

                //cout<<i<<" "<<flag1<<" "<<flag2<<endl;

                if(flag1&&flag2) 
                {
                    ret++;
                    flowerbed[i]=1;
                }
            }
        }
        return ret>=n;
    }
};

int main()
{
    Solution s;

    vector<int> v={1,0,0,0,1};
    cout<<s.canPlaceFlowers(v,2)<<endl;
    return 0;
}
