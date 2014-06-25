#include <iostream>
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head == NULL)
        {
            return head;
        }
        ListNode *preHead = new ListNode(-1);
        ListNode *tailOfNewList = preHead;
        ListNode *p = head;
        ListNode *q = head;
        while(p)
        {
            while(q->next && q->next->val == p->val)
            {
                q = q->next;
            }
            if(p == q)// no duplicates
            {
                tailOfNewList->next = p;
                tailOfNewList = p;
                p = p->next;
                q = q->next;
            }
            else//[p,...,q] are the same
            {
                //delete [p,...,q]
                ListNode *tmp;
                while(p != q)
                {
                    tmp = p->next;
                    delete p;
                    p = tmp;
                }
                tmp = q;
                delete q;
                //set NULL
                tailOfNewList->next = NULL;
                //move on
                p = tmp->next;
                q = tmp->next;
            }
        }
        return preHead->next;
    }
};

int main()
{
	return 0;
}
