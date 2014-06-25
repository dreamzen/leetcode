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
        ListNode *pre = head;
        ListNode *p = head->next;
        while(p)
        {
            if(p->val == pre->val)
            {
                pre->next = p->next;
                p = p->next;
            }
            else
            {
                pre = pre->next;
                p = p->next;
            }
        }
        return head;
    }
};

int main()
{
	return 0;
}
