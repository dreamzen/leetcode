#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> node_queue;
        if(root == NULL)
        {
            return true;
        }

        if(root->left == NULL || root->right == NULL)
        {
            return (root->left == root->right);
        }
        else
        {
            node_queue.push(root->left);
            node_queue.push(root->right);
        }
        //check the front two node
        TreeNode *p = NULL;
        TreeNode *q = NULL;
        while(!node_queue.empty())
        {
            p = node_queue.front();
            node_queue.pop();
            q = node_queue.front();
            node_queue.pop();
            if(p->val == q->val)
            {
                if(p->left == NULL || q->right == NULL)
                {
                    if(p->left != q->right)
                    {
                        return false;
                    }
                }
                else
                {
                    node_queue.push(p->left);
                    node_queue.push(q->right);
                }
                
                if(p->right == NULL || q->left == NULL)
                {
                    if(p->right != q->left)
                    {
                        return false;
                    }
                }
                else
                {
                    node_queue.push(p->right);
                    node_queue.push(q->left);
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = new TreeNode(4);
    n3.right = new TreeNode(4);
    Solution s;
    cout << s.isSymmetric(&n1) << endl;
    return 0;
}
