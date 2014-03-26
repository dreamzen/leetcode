#include <iostream>
#include <map>
#include <queue>
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
        //use map to store <origin, clone>
        map<RandomListNode *, RandomListNode *> node_map;
        RandomListNode *clone_head = new RandomListNode(head->label);

        //traversal the list to copy the whole list
        RandomListNode *origin_node = head;
        RandomListNode *clone_node = clone_head;
        node_map.insert(make_pair(origin_node, clone_node));
        origin_node = origin_node->next;
        for(; origin_node != NULL; origin_node = origin_node->next)
        {
            clone_node->next = new RandomListNode(origin_node->label);
            node_map.insert(make_pair(origin_node, clone_node->next));
            clone_node = clone_node->next;
        }

        //traversal again to link ramdom pointer
        map<RandomListNode *, RandomListNode *>::iterator ite;
        for(origin_node = head; origin_node != NULL; origin_node = origin_node->next)
        {
            if(origin_node->random != NULL)
            {
                ite = node_map.find(origin_node);
                clone_node = ite->second;
                ite = node_map.find(origin_node->random);
                clone_node->random = ite->second;
            }
        }
        return clone_head;
    }
};

int main()
{
    RandomListNode n1(1);
    n1.random = &n1; 
    Solution s;
    RandomListNode *result = s.copyRandomList(&n1);
    return 0;
}
