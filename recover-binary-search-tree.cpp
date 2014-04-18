#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Morris
 */
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        bool has_bigger = false;
        TreeNode *bigger, *smaller;
        TreeNode *current = NULL;
        TreeNode *next = NULL;
        TreeNode *p = root;
        while(p)
        {
            if(p->left == NULL)
            {
                //visit current node
                if(!current)
                {
                    current = p;
                }
                else
                {
                    next = p;
                    if(current->val > next->val)
                    {
                        if(!has_bigger)
                        {
                            has_bigger = true;
                            bigger = current;
                            smaller = next;
                        }
                        else
                        {
                            smaller = next;
                        }
                    }
                    current = next;
                }
                //continue to visit
                p = p->right;
            }
            else
            {
                //find the max node in left-sub-tree
                TreeNode *tmp = p->left;
                while(tmp->right != NULL && tmp->right != p)
                {
                    tmp = tmp->right;
                }
                if(tmp->right == NULL)
                {
                    tmp->right = p;
                    p = p->left;
                }
                else
                {
                    //cut the cycle
                    tmp->right = NULL;
                    //visit current node
                    if(!current)
                    {
                        current = p;
                    }
                    else
                    {
                        next = p;
                        if(current->val > next->val)
                        {
                            if(!has_bigger)
                            {
                                has_bigger = true;
                                bigger = current;
                                smaller = next;
                            }
                            else
                            {
                                smaller = next;
                            }
                        }
                        current = next;
                    }
                    //continue to visit
                    p = p->right;
                }
            }
        }
        //fix the tree
        int tmp = bigger->val;
        bigger->val = smaller->val;
        smaller->val = tmp;
    }
};

int main()
{
	return 0;
}
