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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *pre_head = new ListNode(-1);
        pre_head->next = head;
        ListNode *watcher = head;
        ListNode *toBeDeleted = head;
        int m = n - 1;
        while(m--)
        {
            watcher = watcher->next;
        }
        if(watcher->next == NULL)//delete head
        {
            return head->next;
        }
        while(watcher->next != NULL)
        {
            pre_head = pre_head->next;
            toBeDeleted = toBeDeleted->next;
            watcher = watcher->next;
        }
        pre_head->next = toBeDeleted->next;
        return head;
    }
};

int main()
{
	return 0;
}
