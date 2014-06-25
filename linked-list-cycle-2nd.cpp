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
    bool hasCycle(ListNode *head)
    {
        if(head == NULL)
        {
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(true)
        {
            fast = fast->next;
            if(fast)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if(fast == NULL || slow == NULL)
            {
                return false;
            }
            if(fast == slow)
            {
                return true;
            }
        }
    }
};

int main()
{
	return 0;
}
