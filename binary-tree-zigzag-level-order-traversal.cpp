#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int> > tree_value;
        vector<int> level_value;
        bool zigzag = false;
        if(root == NULL)
        {
            vector<vector<int> > nop;
            return nop;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);//use NULL to mark the end of level

        while(!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();
            if(p != NULL)//at the same level
            {
                level_value.push_back(p->val);
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
            }
            else//current level is over
            {
                if(zigzag)//reverse the vector
                {
                    vector<int> r_level_value;
                    vector<int>::reverse_iterator r;
                    for(r = level_value.rbegin(); r != level_value.rend(); r++)
                    {
                        r_level_value.push_back(*r);
                    }
                    tree_value.push_back(r_level_value);
                }
                else
                {
                    tree_value.push_back(level_value);
                }
                zigzag ^= 1;// change zigzag
                level_value.resize(0);//init vector
                if(!q.empty())//or there will be a loop ==> [ q: NULL] 
                {
                    q.push(NULL);//use NULL to mark the end of level
                }
            }
        }
        return tree_value;
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
    vector<vector<int> > v = s.zigzagLevelOrder(&n1);
    cout << v[0][0] << " "; 
    cout << v[1][0] << " "; 
    cout << v[1][1] << " "; 
    cout << v[2][0] << " "; 
    cout << v[2][1] << " "; 
    cout << endl;
    return 0;
}
