#include <iostream>
#include <vector>
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
        if(root == NULL)
        {
            return true;
        }
        else
        {
            return isSameTree(root->left, root->right);
        }        
    }
    //isSame means symmetric. pay attention to p/q->left/right
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p == NULL || q == NULL)
        {
            return (p == q);
        }
        else
        {
            return ((p->val == q->val) && isSameTree(p->left, q->right) && isSameTree(p->right, q->left));
        }
    }
};

int main()
{
    TreeNode n1(1);
    Solution s;
    cout << s.isSymmetric(&n1) << endl;
    return 0;
}
