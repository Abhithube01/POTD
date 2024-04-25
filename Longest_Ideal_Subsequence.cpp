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
    int longestIdealString(string s, int k) 
    {
        int n = s.length();
        vector<int> t(26,0);
        int result =0;

        for(int i=0;i<n;i++){
            int curr = s[i] - 'a';

            int left = max(0,curr-k);
            int right = min(25,curr+k);

            int longest =0;
            for(int j=left;j<=right;j++) //left=0 in worst and right=25 in worst case
            {
                longest= max(longest,t[j]); 
            }

            t[curr] = max(t[curr],longest+1);
            result = max(result,t[curr]);
        }
        return result;
        
    }
};