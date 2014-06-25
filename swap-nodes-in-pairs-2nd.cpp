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
    ListNode *swapPairs(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *currentTail = preHead;
        ListNode *p = head;
        while(p && p->next)
        {
            ListNode *q = p->next;
            p->next = q->next;
            q->next = p;
            currentTail->next = q;
            currentTail = p;
            p = p->next;
        }
        return preHead->next;
    }
};

int main()
{
	return 0;
}
