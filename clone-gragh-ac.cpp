#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/**
 *Graph Traversal
 *Use queue to traversal original node
 *Use map to store cloned node 
 */

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    queue<UndirectedGraphNode *> origin;
    map<int, UndirectedGraphNode *> clone;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
        {
            return NULL;
        } 
        //origin_head
        UndirectedGraphNode *origin_head = node;
        //clone_head
        UndirectedGraphNode *clone_head = new UndirectedGraphNode(node->label);

        //push the head into queue
        origin.push(origin_head);
        clone.insert(make_pair(clone_head->label, clone_head));
        while(!origin.empty())
        {
            //get one node
            UndirectedGraphNode *origin_node = origin.front();
            origin.pop();
            map<int, UndirectedGraphNode *>::iterator ite;
            ite = clone.find(origin_node->label);
            UndirectedGraphNode *clone_node = ite->second;
            
            //traversal its neighbors
            vector<UndirectedGraphNode *> origin_neighbors = origin_node->neighbors;
            vector<UndirectedGraphNode *>::iterator i;
            for(i = origin_neighbors.begin(); i != origin_neighbors.end(); i++)
            {
                map<int, UndirectedGraphNode *>::iterator ite;
                ite = clone.find((*i)->label);
                //if it's a new node
                if(ite == clone.end())
                {
                    //push it to origin's queue
                    origin.push(*i);
                    //create a new node and add it to clone_node's neighbors
                    UndirectedGraphNode *node = new UndirectedGraphNode((*i)->label);
                    (clone_node->neighbors).push_back(node);
                    //also put it into clone map
                    clone.insert(make_pair((*i)->label, node));
                }
                else//if it's already exist, then find it and add it to clone_node's neighbors
                {
                    UndirectedGraphNode *node = ite->second;
                    (clone_node->neighbors).push_back(node);
                }
            }
        }
        return clone_head;
    }
};
int main()
{
    UndirectedGraphNode node0(0);
    UndirectedGraphNode node1(1);
    UndirectedGraphNode node2(2);
    UndirectedGraphNode *head = &node0;
    (head->neighbors).push_back(&node1);
    (node1.neighbors).push_back(&node0);
    (node1.neighbors).push_back(&node2);
    (node2.neighbors).push_back(&node1);
    (node2.neighbors).push_back(&node2);
    
    Solution s;
    s.cloneGraph(head);
    return 0;
}
