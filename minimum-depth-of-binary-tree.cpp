#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Ele
{
    TreeNode *node;
    int depth;
    Ele(TreeNode *n, int d) : node(n), depth(d) {}
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int min = -1;
        stack<Ele *> s;
        s.push(NULL);
     
        Ele *ele = new Ele(root, 1);
        while(ele != NULL)
        {
            if(ele->node->right)
            {
                Ele *tmp_ele = new Ele(ele->node->right, ele->depth + 1);
                s.push(tmp_ele);
            }
            if(ele->node->left)
            {
                ele = new Ele(ele->node->left, ele->depth + 1);
            }
            else
            {
                if(ele->node->left == NULL && ele->node->right == NULL)//it's leaf
                {
                    if(min == -1)//only leaf do we contrast the depth
                    {
                        min = ele->depth;
                    }
                    else if(ele->depth < min)
                    {
                        min = ele->depth;
                    }
                }
                delete ele;
                ele = s.top();
                s.pop();
            }
        }
        return min;
    }
};

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    n1.right = &n2;
    Solution s;
    cout << s.minDepth(&n1) << endl;
    return 0;
}
