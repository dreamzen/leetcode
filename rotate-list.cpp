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
            return NULL;
        }
        
        ListNode *ori_head = head;
        ListNode *pre_head = head;
        ListNode *tail = head;
        int len = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            len++;
            tail = tmp;
            tmp = tmp->next;
        }
        k = k % len;
        if(k == 0)
        {
            return head;
        }
        for(int i = 0; i < len - k - 1; i++)
        {
            pre_head = pre_head->next;
        }
        head = pre_head->next;
        
        pre_head->next = NULL;
        tail->next = ori_head;
        return head;
    }
};

int main()
{
	return 0;
}
