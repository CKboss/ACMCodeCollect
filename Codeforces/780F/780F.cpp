#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

typedef long long int LL;

int n,m;

const int maxn=505;

bitset<maxn> dp[505][65][2];

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++)
    {
      int u,v,c;
      scanf("%d%d%d",&u,&v,&c);
      u--; v--;
      dp[u][0][c][v]=1;
    }

  for(int k=1;k<=60;k++)
    {
      for(int i=0;i<n;i++)
        {
          for(int c=0;c<=1;c++)
            {
              for(int j=0;j<n;j++)
                {
                  if(dp[i][k-1][c][j])
                    {
                      dp[i][k][c] |= dp[j][k-1][1-c];
                    }
                }
            }
        }
    }

  LL ans = 0;

  bitset<maxn> temp,now;
  now[0]=1;
  int cur = 0;

  for(int k=60;k>=0;k--)
    {
      temp.reset();
      for(int i=0;i<n;i++)
        {
          if(now[i])
            temp |= dp[i][k][cur];
        }
      if(temp.count())
        {
          ans += 1LL<<k;
          cur = 1-cur;
          now = temp;
        }
    }

  if(ans>1e18) {
    puts("-1");
  } else {
    printf("%lld\n",ans);
  }

  return 0;
}
