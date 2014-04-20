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
            return NULL;
        }
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        bool needDel = false;
        ListNode *tmp_pre = pre;
        ListNode *tmp = pre->next;
        while(tmp)
        {
            if(tmp->next == NULL)
            {
                if(needDel)
                {
                    tmp_pre->next = NULL;
                }
                break;//ATTENTION!
            }
            else
            {
                if(tmp->val != tmp->next->val)
                {
                    if(needDel)
                    {
                        needDel = false;
                        tmp_pre->next = tmp->next;
                        tmp = tmp->next;
                    }
                    else
                    {
                        tmp_pre = tmp_pre->next;
                        tmp = tmp->next;
                    }
                }
                else
                {
                    needDel = true;
                    tmp_pre->next = tmp->next;
                    tmp = tmp->next;
                }
            }
        }
        return pre->next;
    }
};

int main()
{
	return 0;
}
