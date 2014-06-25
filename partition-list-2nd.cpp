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
    ListNode *partition(ListNode *head, int x)
    {
        if(head == NULL)
        {
            return head;
        }
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *tailOfSmaller = preHead;
        while(tailOfSmaller->next != NULL && tailOfSmaller->next->val < x)
        {
            tailOfSmaller = tailOfSmaller->next;
        }
        ListNode *preP = tailOfSmaller;
        ListNode *p = preP->next;
        while(p != NULL)
        {
            if(p->val < x)
            {
                preP->next = p->next;
                p->next = tailOfSmaller->next;
                tailOfSmaller->next = p;
                p = preP->next;
                tailOfSmaller = tailOfSmaller->next;
            }
            else
            {
                p = p->next;
                preP = preP->next;
            }
        }
        return preHead->next;
    }
};

int main()
{
	return 0;
}
