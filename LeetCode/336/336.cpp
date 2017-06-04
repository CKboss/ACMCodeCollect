#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int uLL;

class Solution {

    public:

        uLL hashString(string s)
        {
            uLL ret = 0;
            uLL P = 127;
            for(int i=0,n=s.length();i<n;i++)
            {
                ret = ret*P + s[i];
            }
            return ret;
        }

        string reverse(string s)
        {
            string ret;
            for(int i=s.length()-1;i>=0;i--)
            {
                ret+=s[i];
            }
            return ret;
        }

        bool check(string s)
        {
            for(int i=0,j=s.length()-1;i<=j;i++,j--)
            {
                if(s[i]!=s[j]) return false;
            }
            return true;
        }

        vector<vector<int>> palindromePairs(vector<string>& words) {

            int n = words.size();

            vector<vector<int>> ret;

            for(int i=0;i<n;i++)
            {
                if(words[i]!="")
                {
                    for(int j=i+1;j<n;j++)
                    {

                        if(words[i][0]==words[j][words[j].length()-1]&&check(words[i]+words[j])==true) ret.push_back(vector<int>{i,j});

                        if(words[j][0]==words[i][words[i].length()-1]&&check(words[j]+words[i])==true) ret.push_back(vector<int>{j,i});

                    }
                }
                else
                {
                    for(int j=0;j<n;j++)
                    {
                        if(j==i) continue;

                        if(check(words[j]))
                        {
                            ret.push_back(vector<int>{i,j});
                            ret.push_back(vector<int>{j,i});
                        }
                    }

                }
            }

            return ret;
        }
};

int main()
{
    Solution s ;
    //vector<string> words = {"abcd","dcba","lls","s","sssll"};
    vector<string> words = {"a",""};
    vector<vector<int>> vvs =  s.palindromePairs(words);

    for(auto vv : vvs)
    {
        cout<<vv[0]<<","<<vv[1]<<endl;
    }

    return 0;
}
