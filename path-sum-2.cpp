#include <iostream>
#include <map>
#include <stack>
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
 * Use MAP to store <child, parent>
 */
class Solution
{
public:
    map<TreeNode *, TreeNode *> m;//store <child, parent>
    vector<vector<int> > v;//store result
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        vector<vector<int> > nop;
        if(root == NULL)
        {
            return nop;
        }
        findLeaf(root, sum);
        return v;
    }

    void findLeaf(TreeNode *root, int sum)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)//it's a leaf
        {
            if(root->val == sum)//find it
            {
                stack<int> s;//put the reverse-path to stack
                s.push(root->val);
                map<TreeNode *, TreeNode *>::iterator ite;
                ite = m.find(root);
                while(ite != m.end())
                {
                    s.push(ite->second->val);
                    ite = m.find(ite->second);
                }
                vector<int> tmp_v;//put the path to vector
                while(!s.empty())
                {
                    tmp_v.push_back(s.top());
                    s.pop();
                }
                v.push_back(tmp_v);//put the path to final result
            }
            else
            {
                return;
            }
        }
        else//not end
        {
            m.insert(make_pair(root->left, root));
            m.insert(make_pair(root->right, root));
            findLeaf(root->left, sum - root->val);
            findLeaf(root->right, sum - root->val);
        }
    }
};


int main()
{
    TreeNode n1(5);
    TreeNode n2(4);
    TreeNode n3(8);
    TreeNode n4(11);
    TreeNode n5(13);
    TreeNode n6(4);
    TreeNode n7(7);
    TreeNode n8(2);
    TreeNode n9(5);
    TreeNode n10(1);
    
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.left = &n9;
    n6.right = &n10;

    Solution s;
    vector<vector<int> > v;
    v = s.pathSum(&n1, 22);
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
