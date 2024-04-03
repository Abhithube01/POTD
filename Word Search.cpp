#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    return 0;
}

class Solution {
public:
int m,n;
      bool searchWord(vector<vector<char>>& board, int i, int j, int k, string &word){
        if(k==word.size())
        return true;

        if(i<0 ||  j<0 || j>=n|| i>=m|| board[i][j]=='$'){
            return false;
        }

        if(board[i][j] != word[k])
        return false;
        
        char temp = board[i][j];
        board[i][j] = '$';

        bool ret = searchWord(board, i-1, j, k+1, word) || searchWord(board, i+1, j, k+1, word) || searchWord(board, i, j-1, k+1, word) || searchWord(board, i, j+1, k+1, word);
        board[i][j] = temp;

        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0] && searchWord(board,i,j,0,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};