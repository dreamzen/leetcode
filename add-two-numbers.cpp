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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        ListNode *preHead = new ListNode(-1);
        ListNode *p = preHead;
        int val1;
        int val2;
        int carry = 0;
        while(l1 || l2)
        {
            val1 = val2 = 0;
            if(l1)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            int sum = val1 + val2 + carry;
            int newVal = sum % 10;
            p->next = new ListNode(newVal);
            p = p->next;
            carry = sum / 10;
        }
        if(carry)
        {
            p->next = new ListNode(carry);
        }
        return preHead->next;
    }
};

int main()
{
	return 0;
}
