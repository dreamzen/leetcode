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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(head == NULL)
        {
            return head;
        }
        ListNode *tail;
        int len = 0;
        for(ListNode *p = head; p != NULL; p = p->next)
        {
            tail = p;
            len++;
        }
        k %= len;
        if(k == 0)
        {
            return head;
        }
        ListNode *preNewHead = head;
        for(int i = 1; i <= len - k - 1; i++)
        {
            preNewHead = preNewHead->next;
        }
        ListNode *newHead = preNewHead->next;
        //link
        tail->next = head;
        preNewHead->next = NULL;
        return newHead;
    }
};

int main()
{
	return 0;
}
