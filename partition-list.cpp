#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * pre -> 1 -> 4 -> 3 -> 2 -> 5 -> 2  x=3
 *        ^         ^    ^
 *       tmp       tmp1 tmp2
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *tmp = pre;
        while(tmp->next != NULL && tmp->next->val < x)
        {
            tmp = tmp->next;
        }
        ListNode *tmp1 = tmp;
        ListNode *tmp2 = tmp->next;
        while(tmp2 != NULL)
        {
            if(tmp2->val >= x)
            {
                tmp2 = tmp2->next;
                tmp1 = tmp1->next;
            }
            else
            {
                //cut tmp2
                tmp1->next = tmp2->next;
                //insert tmp2 between tmp and tmp->next
                tmp2->next = tmp->next;
                tmp->next = tmp2;
                tmp2 = tmp1->next;
                //move tmp one step
                tmp = tmp->next;
            }
        }
        return pre->next;
    }
};

int main()
{
	return 0;
}
