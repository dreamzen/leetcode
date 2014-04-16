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
private:
    int max;
public:
    int maxPathSum(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        max = root->val;
        maxPath(root);
        return max;
    }
    
    //max path from root to leaf
    int maxPath(TreeNode *node)
    {
        if(node == NULL)
        {
            return 0;
        }
        int leftPath = maxPath(node->left);
        leftPath = (leftPath > 0) ? leftPath : 0;
        int rightPath = maxPath(node->right);
        rightPath = (rightPath > 0) ? rightPath : 0;
        int path = leftPath + node->val + rightPath;
        max = (max > path) ? max : path;
        return (leftPath > rightPath) ? (leftPath + node->val) : (rightPath + node->val);
    }
};

int main()
{
    return 0;
}
