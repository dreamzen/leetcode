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

/**
 * Don't alloc new vector.
 * Reuse the preorder[] and inorder[]
 */

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int end = preorder.size();
        if(end == 0)
        {
            return NULL;
        }
        return build(preorder, inorder, 0, end - 1, 0, end - 1);
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l_start, int l_end, int r_start, int r_end)
    {
        int root_val = preorder[l_start]; 
        TreeNode *root = new TreeNode(root_val);
        if(l_start == l_end)
        {
            root->left = NULL;
            root->right = NULL;
            cout << root_val << " ";
            return root;
        }
        //find new root( preorder[l_start] ) in inorder[r_start, ..., r_end]
        int len = 0;
        while(inorder[r_start + len] != preorder[l_start])
        {
            len++;
        }
        if(len == 0)
        {
            root->left = NULL;
        }
        else
        {
            root->left = build(preorder, inorder, l_start + 1, l_start + len, r_start, r_start + len - 1);
        }
        if(len == l_end - l_start)
        {
            root->right = NULL;
        }
        else
        {
            root->right = build(preorder, inorder, l_start + len + 1, l_end, r_start + len + 1, r_end);
        }
        cout << root_val << " ";
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> preorder;
    vector<int> inorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(5);
    preorder.push_back(3);
    preorder.push_back(6);
    preorder.push_back(7);

    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);

    s.buildTree(preorder, inorder);
    cout << endl;
   
    return 0;
}
