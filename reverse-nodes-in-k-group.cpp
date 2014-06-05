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
        if(k <= 1 || head == NULL)
        {
            return head;
        }
        int len = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            tmp = tmp->next;
            len++;
        }
        int times = len / k;
        if(times <= 0)
        {
            return head;
        }
        ListNode *pre_head = NULL;
        ListNode *after_tail = head;//the next of the last part(new)
        ListNode *newHead = head;//the head we will return
        ListNode *_head = head;//new head of one part
        ListNode *_tail = head;//new tail of one part
        ListNode *tmp1 = head->next;
        ListNode *tmp2 = head;
        //deal with the first part
        for(int i = 0; i < k; i++)
        {
            after_tail = after_tail->next;
        }
        while(tmp1 != after_tail)
        {
            tmp2 = tmp1;
            tmp1 = tmp1->next;
            tmp2->next = _head;
            _head = tmp2;
        }
        newHead = _head;
        _tail->next = after_tail;
        pre_head = _tail;
        _tail = after_tail;
        _head = after_tail;
        
        //deal with the rest parts
        for(int j = 1; j < times; j++)
        {
            tmp1 = after_tail->next;
            for(int i = 0; i < k; i++)
            {
                after_tail = after_tail->next;
            }
            while(tmp1 != after_tail)
            {
                tmp2 = tmp1;
                tmp1 = tmp1->next;
                tmp2->next = _head;
                _head = tmp2;
            }
            _tail->next = after_tail;
            pre_head->next = _head;
            pre_head = _tail;
            _tail = after_tail;
            _head = after_tail;
        }
        return newHead;
    }
};

int main()
{
	return 0;
}
