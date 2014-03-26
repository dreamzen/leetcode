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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p == NULL || q == NULL)
        {
            return (p == q);
        }
        else
        {
            return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    }
};

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    Solution s;
    cout << s.isSameTree(&n1, &n2) << endl;
    return 0;
}
