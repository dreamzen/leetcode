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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if(head == NULL || k <= 1)
        {
            return head;
        }
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *tailOfNewList = preHead;
        int len = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            len++;
            tmp = tmp->next;
        }
        if(k > len)
        {
            return head;
        }
        int n = len / k;
        ListNode *p = head;
        for(int i = 0; i < n; i++)
        {
            ListNode *p1 = p;
            ListNode *pNext = p->next;
            for(int j = 0; j < k - 1; j++)
            {
                ListNode *pTmp = pNext->next;
                pNext->next = p1;
                p1 = pNext;
                pNext = pTmp;
            }
            tailOfNewList->next = p1;
            p->next = pNext;
            tailOfNewList = p;
            p = pNext;
        }
        return preHead->next;
    }
};

int main()
{
	return 0;
}
