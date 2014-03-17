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

/*
Recursive solution: visit root, visit left, visit right
Iterative solution: visit root, push right, visit left
*/
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> s;
        s.push(NULL);//simplify the code
        TreeNode *pointer = root;
        while(pointer)
        {
            //visit node first
            result.push_back(pointer->val);

            if(pointer->right)//push right child
            {
                s.push(pointer->right);
            }

            if(pointer->left)//visit left-sub-tree
            {
                pointer = pointer->left;
            }
            else//return from left-sub-tree, pop the stack to get right child to visit
            {
                pointer = s.top();
                s.pop();
            }
        }

        return result;
    }
};

int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode *p = &t1;
    p->right = &t2;
    p->right->left = &t3;

    Solution s;
    vector<int> result;
    result = s.preorderTraversal(p);
    
    vector<int>::iterator i;
    for(i = result.begin(); i!= result.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
