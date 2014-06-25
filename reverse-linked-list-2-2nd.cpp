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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if(head == NULL || m == n)
        {
            return head;
        }
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *M = head;
        ListNode *N = head;
        ListNode *preM = preHead;
        ListNode *afterN = head->next;
        for(int i = 0; i < n - m; i++)
        {
            N = N->next;
        }
        for(int i = 0; i < m - 1; i++)
        {
            N = N->next;
            preM = preM->next;
        }
        M = preM->next;
        afterN = N->next;
        //deal with the list
        ListNode *p = M;
        while(p != N)
        {
            ListNode *afterP = p->next;
            p->next = afterN;
            afterN = p;
            p = afterP;
        }
        preM->next = p;
        p->next = afterN;
        return preHead->next;
    }
};

int main()
{
	return 0;
}
