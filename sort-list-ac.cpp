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
    ListNode *sortList(ListNode *head)
    {
        //in case the list is EMPTY!!
        if(head == NULL)
            return head;
        //len: 0 1 2 3...
        int len = 0;
        ListNode *tmp = head;
        while(tmp->next != NULL)
        {   
            len ++;
            tmp = tmp->next;
        }
        //sigle Node,then return.
        if(len == 0)
            return head;
        
        //cut the list into 2 pieces: 0,...,middle & middle+1,...,tail
        int middle = len/2;
        ListNode *p = head;
        ListNode *q = head;
        tmp = head;
        while(middle--)
        {   
            tmp = q->next;
            q = q->next;
        }
        q = q->next;
        tmp->next = NULL;

        //sort
        ListNode *pp = sortList(p);
        ListNode *qq = sortList(q);
        //merge
        if(pp && qq)
        {
            ListNode *result;
            ListNode *tmp;

            //'catch' the head!
            if(pp->val < qq->val)
            {
                result = pp;
                tmp = pp;
                pp = pp->next;
            }
            else
            {
                result = qq;
                tmp = qq;
                qq = qq->next;
            }

            //sort
            while(pp && qq)
            {
                if(pp->val < qq->val)
                {
                    tmp->next = pp;
                    tmp = tmp->next;
                    pp = pp->next;   
                }
                else
                {
                    tmp->next = qq;
                    tmp = tmp->next;
                    qq = qq->next;
                }
            }

            //link the sorted tail.
            if(pp != NULL)
            {
                tmp->next = pp;
            }
            else
            {
                tmp->next = qq;
            }
            return result;
        }
        
    }
};

int main()
{
    ListNode *head;
    Solution s;
    ListNode *result = s.sortList(head);
  //      cout << result->val << " ";
    
    return 0;

}
