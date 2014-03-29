#include <iostream>
#include <vector>
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
 * Inorder traversal
 */
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> node_val;
        if(root == NULL)
        {
            return true;
        }

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
                node_val.push_back(node->val);
                node = node->right;
            }
        }

        //vector node_val should be sorted
        int len = node_val.size();
        for(int i = 0; i < len - 1; i++)
        {
            if(node_val[i] >= node_val[i + 1])
            {
                return false;
            }
        }
        return true;
            
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(0);
    root->right = new TreeNode(0);
    cout << s.isValidBST(root) << endl;
    return 0;
}
