#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        queue<TreeLinkNode *> q;
        vector<TreeLinkNode *> v;//hold the node of same level
        q.push(root);
        q.push(NULL);//use NULL to mark the end of current level

        while(!q.empty())
        {
            TreeLinkNode *p = q.front();
            q.pop();
            if(p != NULL)//at the same level
            {
                v.push_back(p);
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
            }
            else//the end of current level
            {
                //it's time to link the node
                vector<TreeLinkNode *>::iterator ite;
                ite = v.begin();
                TreeLinkNode * tmp = *ite;
                ite++;
                for(; ite != v.end(); ite++)
                {
                    tmp->next = *ite;
                    tmp = *ite;
                }
                tmp->next = NULL;
                v.resize(0);
                //use NULL to mark the end of level
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
        }
        
    }
};

int main()
{

    return 0;
}


