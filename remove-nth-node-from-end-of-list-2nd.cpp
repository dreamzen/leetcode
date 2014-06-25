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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if(head == NULL)
        {
            return head;
        }
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *preDeleted = preHead;
        ListNode *needDeleted = head;
        ListNode *tail = head;
        for(int i = 0; i < n - 1; i++)
        {
            tail = tail->next;
        }
        while(tail && tail->next)
        {
            tail = tail->next;
            preDeleted = preDeleted->next;
            needDeleted = needDeleted->next;
        }
        preDeleted->next = needDeleted->next;
        delete needDeleted;
        return preHead->next;
    }
};

int main()
{
	return 0;
}
