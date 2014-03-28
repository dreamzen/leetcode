#include <iostream>
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
    int maxDepth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL)//reach the leaf
        {
            return 1;
        }
        else
        {
            int max_left = maxDepth(root->left);
            int max_right = maxDepth(root->right);
            return 1 + ((max_left > max_right) ? max_left : max_right);
        }
    }
};

int main()
{
    return 0;
}
