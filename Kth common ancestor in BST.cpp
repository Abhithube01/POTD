#include<iostream>
using namespace std;
int main()
{
    return 0;
}
struct Node
{
	int data;
	struct Node *left, *right;
};
class Solution
{
    public:
    
    int fun(Node * root,int x,int y ,int &k){
        if(root==NULL){
            return -1;
        }
        int val=-1;
        if((root->data > x  )&& (root->data)> y){
            val=fun(root->left,x,y,k);
        }
        else if((root->data < x  )&& (root->data< y)){
            val=fun(root->right,x,y,k);
        }
        k--;
        if(k==0){
            val=root->data;
        }
        return val;
    }
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        
        return fun(root,x,y,k);
    }
};
