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
    ListNode *insertionSortList(ListNode *head)
    {
        //in case the list is EMPTY!!
        if(head == NULL)
            return head;
        //from 2nd Node
        ListNode *tmp = head->next;
        ListNode *sorted_tail = head;
        //len of list that has been sorted.
        int sorted_len = 1;
        while(tmp != NULL)
        {
            ListNode *cursor = head;
            ListNode before_head(0);
            //we can't directly find 'last' Node, so we use a 'before_cursor'
            ListNode *before_cursor = &before_head;
            before_cursor->next = head;
            bool change_tail = false;
            bool is_head = true;
            
            //find the position to insert
            for(int i = 0; i < sorted_len; i++)
            {
                if(tmp->val > cursor->val)
                {
                    is_head = false;
                    cursor = cursor->next;
                    before_cursor = before_cursor->next;
                    if(i == sorted_len -1)
                    {//if tmp is biggest, then tail <-- tmp, else tail will not change
                        change_tail = true;
                    }
                }
                else
                {
                    break;
                }
            }

            //insert
            //cut tmp out of the list
            sorted_tail->next = tmp->next;
            //if tmp is smallest, then insert to the head
            if(is_head)
            {
                tmp->next = head;
                head = tmp;
            }
            else
            {
                tmp->next = before_cursor->next;
                before_cursor->next = tmp;
                if(change_tail)
                {
                    sorted_tail = tmp;
                }
            }
            //next tmp
            tmp = sorted_tail->next;
            sorted_len++;
        }    
        return head;
    }
};

int main()
{
    ListNode head(2);
    ListNode head1(1);
    head.next = &head1;
    Solution s;
    ListNode *result = s.insertionSortList(&head);
    for(int i = 0; i < 2; i++)
    {    
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;

}
