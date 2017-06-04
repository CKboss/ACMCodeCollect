#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n;
int a[maxn];

int main()
{
    int T_T;
    scanf("%d",&T_T);
while(T_T--)
{
    scanf("%d",&n);
    a[0]=2;
    for(int i=1;i<n;i++) scanf("%d",a+i); 
    int n2=0;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(a[i]==2) n2++;
        else
        {
            if(n2>0) n2--;
            else n2++;
        }
    }
    if(n2!=0) flag=false;

    if(flag) puts("Yes");
    else puts("No");
}
    return 0;
}
