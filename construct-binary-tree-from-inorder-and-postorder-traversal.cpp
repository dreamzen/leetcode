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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int end = inorder.size();
        if(end == 0)
        {
            return NULL;
        }
        return build(inorder, postorder, 0, end - 1, 0, end - 1);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int l_start, int l_end, int r_start, int r_end)
    {
        int root_val = postorder[r_end];
        TreeNode *root = new TreeNode(root_val);
        if(l_start == l_end)
        {
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        //find root( postorder[r_end] ) in inorder[l_start, ..., l_end]
        int len = 0;
        while(inorder[l_start + len] != postorder[r_end])
        {
            len++;
        }
        if(len == 0)
        {
            root->left = NULL;
        }
        else
        {
            root->left = build(inorder, postorder, l_start, l_start + len - 1, r_start, r_start + len - 1);
        }
        if(len == r_end - r_start)
        {
            root->right = NULL;
        }
        else
        {
            root->right = build(inorder, postorder, l_start + len + 1, l_end, r_start + len, r_end - 1);
        }
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);

    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(6);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);

    s.buildTree(inorder, postorder);
    cout << endl;
   
    return 0;
}
