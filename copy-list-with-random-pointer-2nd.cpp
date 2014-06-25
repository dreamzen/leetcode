#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        unordered_map<RandomListNode *, RandomListNode *> mapping;
        RandomListNode *newHead = new RandomListNode(head->label);
        mapping[head] = newHead;
        RandomListNode *p = head->next;
        RandomListNode *q = newHead;
        while(p)
        {
            q->next = new RandomListNode(p->label);
            mapping[p] = q->next;
            p = p->next;
            q = q->next;
        }
        p = head;
        q = newHead;
        while(p)
        {
            RandomListNode *randomP = p->random;
            if(randomP)
            {
                q->random = mapping[randomP];
            }
            else
            {
                q->random = NULL;
            }
            p = p->next;
            q = q->next;
        }
        return newHead;
    }
};

int main()
{
	return 0;
}
