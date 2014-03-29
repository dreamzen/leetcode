#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        if(root == NULL)
        {
            vector<vector<int> > nop;
            return nop;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);//mark the end of current level

        vector<int> row;
        vector<vector<int> > result;
        stack<vector<int> > s;//store vector row to reverse them
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if(node != NULL)
            {
                row.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            else//current velel is over
            {
                s.push(row);
                row.resize(0);
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
        }
        while(!s.empty())
        {
            vector<int> v = s.top();
            s.pop();
            result.push_back(v);
        }
        return result;
    }
};

int main()
{
    TreeNode n1(3);
    TreeNode n2(9);
    TreeNode n3(20);
    TreeNode n4(15);
    TreeNode n5(17);
    
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    
    Solution s;
    vector<vector<int> > v = s.levelOrderBottom(&n1);
    cout << v[0][0] << " "; 
    cout << v[0][1] << " "; 
    cout << v[1][0] << " "; 
    cout << v[1][1] << " "; 
    cout << v[2][0] << " "; 
    cout << endl;
    return 0;
}
