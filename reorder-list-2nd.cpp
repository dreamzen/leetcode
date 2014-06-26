#include <iostream>
#include <stack>
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
    void reorderList(ListNode *head)
    {
        int len = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            len++;
            tmp = tmp->next;
        }
        if(len <= 2)
        {
            return;
        }
        ListNode *rightNode = head;
        int count = (len + 1) / 2;
        while(count--)
        {
            rightNode = rightNode->next;
        }
        stack<ListNode *> s;
        while(rightNode)
        {
            s.push(rightNode);
            rightNode = rightNode->next;
        }
        ListNode *p = head;
        while(!s.empty())
        {
            ListNode *node = s.top();
            s.pop();
            ListNode *pNext = p->next;
            p->next = node;
            node->next = pNext;
            p = pNext;
        }
        if(p)
        {
            p->next = NULL;
        }
    }
};

int main()
{
	return 0;
}
