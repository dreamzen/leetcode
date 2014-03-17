#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if(head == NULL)
        {
            return;
        }
        stack<ListNode *> s;//push L(n/2), L(n/2 + 1),..., L(n) to stack
        int len = 0;
        int middle;
        ListNode *tmp = head;
        while(tmp)
        {
            len++;
            tmp = tmp->next;
        }
        if(len <= 2)
        {
            return;
        }
        middle = (len + 1)/2;//ensure that L1, L2,..., Lmiddle >= L(middle+1), ..., Ln
        ListNode *p = head;
        ListNode *q = head;
        //p:L1,L2 q:L3 or p:L1,L2 q:L3,L4
        while(--middle)
        {
            q = q->next;
        }
        
        //push q to stack
        while(q)
        {
            s.push(q);
            q = q->next;
        }

        //reorder:take top of stack, and insert into p
        while(!s.empty())
        {
            q = s.top();
            s.pop();
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
    }
};

int main()
{
    ListNode l1(1);

    ListNode *head = &l1;

    Solution s;
    s.reorderList(head);
        cout << head->val << endl;
    return 0;
}
