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
 * MLE!
 * Don't alloc new vector.
 * Reuse the preorder[] and inorder[]
 */

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int num = preorder.size();
        if(num == 0)
        {
            return NULL;
        }
        if(num == 1)
        {
            TreeNode *root = new TreeNode(preorder[0]);
            cout << preorder[0] << " ";
            return root;
        }
        int root_val = preorder[0];
        vector<int> left_preorder;
        vector<int> right_preorder;
        vector<int> left_inorder;
        vector<int> right_inorder;
        int left_num = 0;
        //cal the number of node in left-sub-tree
        while(inorder[left_num] != root_val)
        {
            left_num++;
        }
        int right_num = num - 1 - left_num;
        //find pre & inorder of left-sub-tree & right-sub-tree
        for(int i = 0; i < left_num; i++)
        {
            left_preorder.push_back(preorder[i + 1]);
            left_inorder.push_back(inorder[i]);
        }
        for(int i = 0; i < right_num; i++)
        {
            right_preorder.push_back(preorder[left_num + i + 1]);
            right_inorder.push_back(inorder[left_num + i + 1]);
        }
        //construct root
        TreeNode *root = new TreeNode(root_val);
        //construct left & right child
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
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
