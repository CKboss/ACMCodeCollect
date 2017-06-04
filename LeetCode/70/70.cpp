#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int climbStairs(int n)
    {
        if(n==1) return 1;
        if(n==2) return 2;

        int x=1,y=2;

        for(int i=3;i<=n;i++)
        {
            int z = x+y;
            x=y;y=z;
        }


        return y;
    }
}

int main()
{
    assert(1==1);
    return 0;
}
