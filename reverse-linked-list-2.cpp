#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 0->1->2->3->4->5->NULL  m=2, n=4
 * ^  ^  ^  ^
 * p' p  c  t
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if(m == n)
        {
            return head;
        }
        ListNode *pre = new ListNode(0);
        ListNode *pre1 = pre;
        pre->next = head;
        ListNode *cursor = head;
        ListNode *tail = head->next;
        for(int i = 1; i < m; i++)
        {
            pre = pre->next;
            cursor = cursor->next;
            tail = tail->next;
        }
        //insert tail to (p, c), do it n-m times
        for(int i = 0; i < n - m; i++)
        {
            cursor->next = tail->next;
            tail->next = pre->next;
            pre->next = tail;
            tail = cursor->next;
        }
        if(m == 1)
        {
            return pre1->next;
        }
        else
        {
            return head;
        }
    }
};

int main()
{
    return 0;
}
