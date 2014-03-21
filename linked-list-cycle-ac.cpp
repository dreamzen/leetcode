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
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            if(slow->next == fast->next->next)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
    
int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    ListNode *head = NULL;
//    n1.next = &n2;
//    n2.next = &n3;
//    n3.next = &n4;
//    n4.next = &n3;

    Solution s;
    cout << "has_cycle: " << s.hasCycle(head) << endl;
    return 0;
}
