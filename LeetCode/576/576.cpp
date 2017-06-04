#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

// time x y dir
int dp[50][50][50];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

class Solution 
{

public:

    int n,m,N,x,y;

    bool checkIn(int X,int Y)
    {
        if(X>=0&&X<n&&Y>=0&&Y<m) return true;
        return false;
    }

    int findPaths(int _n, int _m, int _N, int _x, int _y) 
    {
        this->n = _n; this->m = _m; this->N = _N; this->x = _x; this->y = _y;

        memset(dp,0,sizeof(dp));

        int ans=0;

        for(int time=N-1;time>=0;time--)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    for(int k=0;k<4;k++)
                    {
                        int temp=0;
                        int nx = i+dx[k];
                        int ny = j+dy[k];

                        if(checkIn(nx,ny))
                        {
                            temp = dp[time+1][nx][ny];
                        }
                        else
                        {
                            temp = 1;
                        }

                        dp[time][i][j] = (dp[time][i][j]+temp)%mod;

                        //printf("%d,%d,%d,%d\n",time,i,j,k);
                    }

                }
            }

            // ans = (ans + dp[time][x][y])%mod;
            /*

            printf("------%d------\n",time);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    printf("%d ",dp[time][i][j]);
                }
                printf("\n");
            }
            */
        }
        return dp[0][x][y];
    }
};

int main()
{
    Solution s;
    assert(s.findPaths(1,3,3,0,1)==12);
    assert(s.findPaths(2,2,2,0,0)==6);
    return 0;
}
