#include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    int n;
    bool vis[1100];

    string addBoldTag(string s, vector<string>& dict) 
    {
        memset(vis,0,sizeof(vis));
        n = s.length();

        for(auto word : dict)
        {
            int m = word.length();
            for(int i=0;i+m-1<n;i++)
            {
                int j=i+m-1;
                if(s.substr(i,m)==word)
                {
                    for(int k=i;k<=j;k++) vis[k]=true;
                }
            }
        }

        for(int i=0;i<n;i++)
            cout<<vis[i]<<",";
        cout<<endl;

        string ret="";

        bool last=false;

        for(int i=0;i<=n;i++)
        {
            if(vis[i]!=last)
            {
                if(vis[i]==true) ret += "<b>";
                else ret += "</b>";
            }
            if(i<n)
            {
                ret += s[i];
                last = vis[i];
            }
        }
        return ret;
    }
};

int main()
{
    vector<string> dict = {"aaa","aab","bc"};
    string str = "aaabbcc";
    Solution s;
    string ret = s.addBoldTag(str,dict);
    cout<<ret<<endl;
    return 0;
}
