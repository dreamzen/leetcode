#include <iostream>
#include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.empty())
        {
            return NULL;
        }
        int len = lists.size();
        //merge every two lists
        while(len > 1)
        {
            int i, j;
            for(i = 0, j = 0; i + 1 < len; i += 2, j++)
            {
                lists[j] = sortLists(lists[i], lists[i + 1]);
            }
            if(len % 2 == 1)
            {
                lists[j] = lists[i];//the last list
            }
            len = (len + 1) / 2;
        }
        return lists[0];
    }
    
    ListNode *sortLists(ListNode *head1, ListNode *head2)
    {
        if(head1 == NULL)
        {
            return head2;
        }
        if(head2 == NULL)
        {
            return head1;
        }
        ListNode *result;
        ListNode *tail;
        if(head1->val < head2->val)
        {
            result = head1;
            head1 = head1->next;
            tail = result;
        }
        else
        {
            result = head2;
            head2 = head2->next;
            tail = result;
        }
        while(head1 && head2)
        {
            if(head1->val < head2->val)
            {
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
            }
        }
        if(head1)
        {
            tail->next = head1;
        }
        else
        {
            tail->next = head2;
        }
        return result;
    }
};

int main()
{
	return 0;
}
