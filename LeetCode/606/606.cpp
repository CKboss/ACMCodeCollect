#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution 
{
public:
    string tree2str(TreeNode* t) 
    {
        string ret;
        ret += to_string(t->val);
        if(t->left!=NULL) 
        {
            ret += "(";
            ret += tree2str(t->left);
            ret += ")";
        }
        if(t->right!=NULL) 
        {
            ret += "(";
            ret += tree2str(t->right);
            ret += ")";
        }
        return ret;
    }
};

int main()
{
    string s;
    s += to_string(123);
    cout<<s<<endl;
    return 0;
}
