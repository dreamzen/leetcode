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
 *
 * If there is a cycle, assume that:
 * x is from head to the start of cycle
 * y is the length of cycle
 * m is the length from start of cycle when fast & slow runner met
 * then fast runs x + ky + m
 * and  slow runs x + m (if fast is not twice of slow ,then x + ty + m, whatever, both are OK)
 * so, x + ky + m = 2(x + m) ==> ky = x + m ==> (x + m) % y == 0
 * so, fast continue moves x steps will reach the start of cycle!
 * and x is also the distance from head to the start of cycle
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        //O(n)
        while(slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }
        
        //O(n)
        if(fast->next != NULL && fast->next->next != NULL)//must have a cycle
        {
            slow = head;
            while(slow != fast)//continue to move x steps
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        else
        {
            return NULL;
        }
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
    n4.next = &n1;

    Solution s;
    ListNode *result = s.detectCycle(head);
    if(result)
        cout << "has_cycle: " << result->val << endl;
    else
        cout << "NULL" <<endl;
    return 0;
}
