#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int LL;

const LL mod = 1000000007LL;
const int maxn = 200200;

int len;
char str[maxn];

LL inv[maxn],jc[maxn],jcv[maxn];

void init()
{
  inv[1]=1; jc[0]=1; jcv[1]=1;
  jc[1]=1; jcv[1]=1;
  for(int i=2;i<maxn;i++)
    {
      inv[i]=inv[mod%i]*(mod-mod/i)%mod;
      jc[i]=(jc[i-1]*i)%mod;
      jcv[i]=(jcv[i-1]*inv[i])%mod;
    }
}

LL C(LL n,LL m)
{
  if(m<0||m>n) return 0LL;
  if(m==0||m==n) return 1LL;
  LL ret=((jc[n]*jcv[n-m])%mod*jcv[m])%mod;
  return ret;
}

int main()
{
  init();
  while(scanf("%s",str)!=EOF)
    {
      len = strlen(str);
      LL left=0,right=0;
      for(int i=0;i<len;i++)
        {
          if(str[i]==')') right++;
        }
      LL ans=0;
      for(int i=0;i<len;i++)
        {
          if(str[i]==')')
            {
              right--;
              if(right==0) break;
            }
          else if(str[i]=='(')
            {
              /*
              int limit = min(left,right-1);
              for(int ii=0;ii<=limit;ii++)
                {
                  ans = (ans + (C(left,ii)*C(right,ii+1))%mod)%mod;
                }
              */
              left++;
              ans = (ans+C(left+right-1,left))%mod;
            }
        }
      printf("%lld\n",ans);
    }
  return 0;
}
