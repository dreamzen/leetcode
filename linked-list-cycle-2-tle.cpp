#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * fast & slow runner:
 * fast one run 2 steps at one time, and
 * slow one run 1 step at one time.
 * So the distance between them becomes 1 step larger at one time.
 * If there's a cycle, fast one will catch slow one within N steps.
 * N is the length of the list.
 * ------------------------
 * The difference between Node outside cycle and within cycle is that
 * fast will ALWAYS pass by only once for the former case
 * 1-->2-->3-->4-->5-->(3) : as for fast runner, 
 * 1/2 will always be passed by only once and 3 MUST be more than once,
 * Note: we consider 'skip' as 'pass by' too.
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(head == NULL)
        {
            return false;
        }
        ListNode *result = NULL;
        // O(n^2)
        for(result = head; result != NULL; result = result->next)
        {
            ListNode *slow = head;
            ListNode *fast = head;
            int showTime = 0;
            if(result == head)
            {
                showTime = 1;
            }
            while(slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
            {
                if(fast->next == result || fast->next->next == result)
                {
                    showTime++;//fast runner pass by this node
                }
                if(slow->next == fast->next->next)
                {
                    break;//fast runner catch slow one, break to check result
                }
                slow = slow->next;
                fast = fast->next->next;
            }
            if(showTime == 2)
            {
                return result;
            }
        }
        return NULL;
    }
};
    
int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    ListNode *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n4;

    Solution s;
    ListNode *result = s.detectCycle(head);
    if(result != NULL)
    {
        cout << "has_cycle: " << result->val << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }
    return 0;
}
