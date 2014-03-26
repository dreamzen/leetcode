#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 *Graph Traversal
 *Use two queue, 'clone' follows 'origin'
 */

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    queue<UndirectedGraphNode *> origin;
    queue<UndirectedGraphNode *> clone;
    vector<int> marked;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
        {
            return NULL;
        } 
        //origin_head
        UndirectedGraphNode *origin_head = node;
        //clone_head
        UndirectedGraphNode *clone_head = new UndirectedGraphNode(node->label);
        //vector to save existed clone_node
        vector<UndirectedGraphNode *> existed;

        //push the head into queue and mark it and push it into existed vector
        marked.push_back(origin_head->label);
        origin.push(origin_head);
        clone.push(clone_head);
        existed.push_back(clone_head);
        while(!origin.empty())
        {
            //get one node
            UndirectedGraphNode *origin_node = origin.front();
            origin.pop();
            UndirectedGraphNode *clone_node = clone.front();
            clone.pop();
            
            //traversal its neighbors
            vector<UndirectedGraphNode *> origin_neighbors = origin_node->neighbors;
            vector<UndirectedGraphNode *>::iterator i;
            for(i = origin_neighbors.begin(); i != origin_neighbors.end(); i++)
            {
                //if it's a new node
                if(!isMarked(*i))
                {
                    //mark it. As label is unique, so we can do this 
                    marked.push_back((*i)->label);
                    //push it into existed vector
                    existed.push_back(*i);
                    //push it to origin's queue
                    origin.push(*i);
                    //create a new node and add it to clone_node's neighbors
                    UndirectedGraphNode *node = new UndirectedGraphNode((*i)->label);
                    (clone_node->neighbors).push_back(node);
                    //also push it to clone's queue
                    clone.push(node);
                }
                else//if it's already exist, then find it and add it to clone_node's neighbors
                {
                    UndirectedGraphNode *node = findNode(existed, (*i)->label);
                    (clone_node->neighbors).push_back(node);
                }
            }
        }
        return clone_head;
    }

    bool isMarked(UndirectedGraphNode *node)
    {
        vector<int>::iterator i;
        for(i = marked.begin(); i != marked.end(); i++)
        {
            if((*i) == node->label)
            {
                return true;
            }
        }
        return false;
    }
    
    UndirectedGraphNode *findNode(vector<UndirectedGraphNode *> existed, int label)
    {
        vector<UndirectedGraphNode *>::iterator i;
        for(i = existed.begin(); i != existed.end(); i++)
        {
            if((*i)->label == label)
            {
                return *i;
            }
        }
        return NULL;
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
