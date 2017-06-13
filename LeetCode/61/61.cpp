#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void showList(ListNode* cur)
{
    while(cur!=NULL)
    {
        cout<<cur->val<<" --> ";
        cur = cur->next;
    }
    cout<<endl;
}

class Solution {

public:

    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL) return NULL;

        if(k==0) return head;

        ListNode* cur = head;
        ListNode* last;

        int n=0;
        while(cur!=NULL)
        {
            n++;
            last = cur;
            cur = cur->next;
        }

        cur = head;
        k = k%n;
        if(k==0) return head;

        for(int i=0;i<n-k;i++)
        {
            ListNode* temp;
            temp = cur;
            cur = cur->next;
            if(i==n-k-1)
            {
                temp->next=NULL;
                last->next=head;
                //head->next=cur;
                head = cur;
                break;
            }
        }

        return head;
    }
};

int main()
{
    ListNode head = NULL;
    ListNode* cur;

    for(int i=1;i<=10;i++)
    {
        if(i==1) 
        {
            head = ListNode(i);
            cur = &head;
        }
        else
        {
            cur->next = new ListNode(i);
            cur = cur->next;
        }
    }

    cur = &head;

    //showList(cur);

    Solution s;
    cur = s.rotateRight(cur,10);

    showList(cur);


    return 0;
}
