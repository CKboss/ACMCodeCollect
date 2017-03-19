#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

const int maxn=1100;

int n;
string str1,str2;
string name[maxn];

set<string> s1,s2; 

int main()
{
	scanf("%d",&n);

	bool flag = true;
	for(int i=0;i<n&&flag;i++)
	{
		cin>>str1>>str2;
		string name1 = str1.substr(0,3);
		string name2 = str1.substr(0,2)+str2[0];
		if(s2.count(name2)==0)
		{
			s2.insert(name2);
			s1.insert(name1);
			name[i]=name2;
		}
		else
		{
			if(s1.count(name1)==0)
			{
				if(s2.count(name1)==0)
				{
					s1.insert(name1);
					name[i]=name1;
				}
				else flag=false;
			}
			else flag=false;
		}
	}

	if(flag)
	{
		puts("YES");
		for(int i=0;i<n;i++)
			cout<<name[i]<<endl;
	}
	else
	{
		puts("NO");
	}


	return 0;
}
