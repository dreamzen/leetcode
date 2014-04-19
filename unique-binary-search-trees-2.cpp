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
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> result;
        result = generate(1, n);
        return result;
    }
    
    vector<TreeNode *> generate(int start, int end)
    {
        vector<TreeNode *> result;
        if(start > end)
        {
            result.push_back(NULL);
            return result;
        }
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = generate(start, i - 1);
            vector<TreeNode *> right = generate(i + 1, end);
            for(int j = 0; j < left.size(); j++)
            {
                for(int k = 0; k < right.size(); k++)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
