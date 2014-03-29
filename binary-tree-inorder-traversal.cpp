#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        stack<TreeNode *> s;
        TreeNode *node = root;
        
        while(!s.empty() || node)
        {
            if(node != NULL)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                node = s.top();
                s.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
    }
};

int main()
{
    return 0;
}
