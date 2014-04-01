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
        //swap head and head->next
        ListNode *pre = head;
        head = pre->next;
        pre->next = head->next;
        head->next = pre;
        
        ListNode *p = pre->next;
        while(p && p->next)
        {
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = p;
            pre = p;
            p = p->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}
