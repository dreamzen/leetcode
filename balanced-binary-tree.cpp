#include <iostream>
#include <cmath>
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
    bool isBalanced(TreeNode *root)
    {
        if(root == NULL)
        {
            return true;
        }
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        bool balanced = ((abs(left - right) <= 1) ? true : false);
        return balanced && isBalanced(root->left) && isBalanced(root->right);
    }

    int maxHeight(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        return 1 + ((left > right) ? left : right); 
    }
};

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.right = &n2;
    n2.right = &n3;
    Solution s;
    cout << s.isBalanced(&n1) << endl;
    return 0;
}
