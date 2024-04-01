#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    return 0;
}
struct Node {
    int data;
    struct Node *left, *right;
};
class Solution {
  public:
        
    void inorder(Node* root, vector<int>&v)
    {
        if(root)
        {
            inorder(root->left,v);
            v.push_back(root->data);
            inorder(root->right,v);
        }
    }
    int pairsViolatingBST(int n, Node *root) {
        vector<int>v;
        inorder(root,v);
        vector<int>tp;
        tp=v;
        sort(tp.begin(),tp.end());
        int ct=0;
        for(int i=0; i<v.size(); i++)
        {
            int ind=lower_bound(tp.begin(),tp.end(),v[i])-tp.begin();
            ct+=ind;
            tp.erase(tp.begin()+ind);
        }
        return ct;
    }
};