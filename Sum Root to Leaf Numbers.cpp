#include<iostream>
using namespace std;
int main()
{
    return 0;
}
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.

class Solution {
    int dfs(TreeNode* node,int currSum)
    {
        if(!node)
        {
            return 0;
        }
        currSum = currSum * 10 + node->val;
         if (!node->left && !node->right) 
        {
            return currSum;
        }

        int leftSum = dfs(node->left, currSum);
        int rightSum = dfs(node->right, currSum);

        return leftSum + rightSum;
    }
public:
    int sumNumbers(TreeNode* root) 
    {
        return dfs(root,0);
    }
};