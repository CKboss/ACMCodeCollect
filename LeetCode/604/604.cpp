#include <bits/stdc++.h>

using namespace std;

class StringIterator {
public:
    vector<char> chars;
    vector<unsigned long long int> nums;
    int n;
    string str;
    int ptr;
    int id=1;

    bool ischar(char c)
    {
        if(c>='a'&&c<='z') return true;
        if(c>='A'&&c<='Z') return true;
        return false;
    }

    StringIterator(string compressedString) {

        str = "";
        int len = compressedString.length();
        char tmp;

        chars.push_back(' ');
        nums.push_back(0);

        for(int i=0;i<len;i++)
        {
            if(ischar(compressedString[i]))
            {
                tmp=compressedString[i];
                // read num
                int num=0;
                for(int j=i+1;j<len;j++)
                {
                    if(ischar(compressedString[j])==false)
                    {
                        num = num*10 + compressedString[j]-'0';
                    }
                    else
                    {
                        i = j-1;
                        break;
                    }
                }
                chars.push_back(tmp);
                nums.push_back(num);
           }
        }

        n = chars.size();
        for(int i=1;i<n;i++)
        {
            nums[i] = nums[i-1]+nums[i];
        }

        ptr=1;
    }
    
    char next() {
        if(hasNext())
        {
            char c ;
            if(id<=nums[ptr])
            {
                c = chars[ptr];
            }
            else
            {
                ptr++;
                c = chars[ptr];
            }

            id++;
            return c;
        }
        return ' ';
    }
    
    bool hasNext() 
    {
        if(id<=nums[n-1]) return true;

        return false;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

int main()
{
    return 0;
}
