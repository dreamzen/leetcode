#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 /**
  * Child is based on parent node, so pass the value down
  */
class Solution
{
private:
    int result;
public:
    int sumNumbers(TreeNode *root)
    {
        result = 0;
        calTree(root, 0);
        return result;
    }
    
    void calTree(TreeNode *node, int sum)
    {
        if(node == NULL)
        {
            return;
        }
        int mysum = sum * 10 + node->val;
        if(node->left == NULL && node->right == NULL)
        {
            result += mysum;
            return;
        }
        calTree(node->left, mysum);
        calTree(node->right, mysum);
    }
};

int main()
{
    return 0;
}
