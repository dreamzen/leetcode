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
    TreeNode *sortedArrayToBST(vector<int> &num)
    {   
        if(num.size() == 0)
        {   
            return NULL;
        }   
        return build(num, 0, num.size() - 1); 
    }   

    TreeNode *build(vector<int> &num, int start, int end)
    {   
        int middle = (start + end) / 2;
        int root_val = num[middle];
        TreeNode *root = new TreeNode(root_val);
        if(start == end)
        {   
            root->left = NULL;
            root->right = NULL;
            return root;
        }   
        if(middle == start)
        {   
            root->left = NULL;
        }   
        else
        {   
            root->left = build(num, start, middle - 1); 
        }   
        if(middle == end)
        {   
            root->right = NULL;
        }   
        else
        {   
            root->right = build(num, middle + 1, end);
        }   
        return root;
    }   
};

int main()
{
    return 0;
}
