#include <bits/stdc++.h>

using namespace std;

bool ac[100];
int a[100];

int n,m;
int pen,solve;
char buff[1024];
char res[20];

int main()
{

    int T_T;
    scanf("%d",&T_T);
while(T_T--)
{
    scanf("%d%d\n",&n,&m);

    memset(a,0,sizeof(a));
    memset(ac,false,sizeof(ac)); 
    pen=0; solve=0;

    while(m--)
    {
        gets(buff);
        int pid,hour,minute;
        memset(res,0,sizeof(res));
        sscanf(buff,"%d %d:%d %s",&pid,&hour,&minute,res); 

        pid = pid-1000;
        int time = hour*60+minute;

        if(res[0]=='A')
        {
            if(ac[pid]==false)
            {
                solve++;
                ac[pid]=true;
                a[pid]=time;
            }
        }
        else
        {
            pen+=20;
        }
    }

    for(int i=0;i<=n;i++)
        if(ac[i]==true) pen+=a[i];

    printf("%d %d\n",solve,pen);
}
    return 0;
}
