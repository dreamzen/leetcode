#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Preorder Traversal
 */
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> s;
        if(root == NULL)
        {
            return;
        }
        s.push(NULL);//mark the bottom of stack
        TreeNode *node = root;
        while(node != NULL)
        {
            if(node->right)
            {
                s.push(node->right);//put right-sub-tree into stack
            }
            if(node->left)
            {
                node->right = node->left;//right <-- left
                TreeNode *p = node;
                node = node->left;//traversal left-sub-tree
                p->left = NULL;//left <-- NULL
            }
            else
            {
                TreeNode *p = node;
                node = s.top();
                s.pop();
                p->right = node;
            }
        }
    }
};

int main()
{
    return 0;
}
