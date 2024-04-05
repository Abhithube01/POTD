#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    return 0;
}
class Solution {
public:
    int maxDepth(string s) {
        int openBrackets = 0;
        int result = 0;
        for(char &ch: s)
        {
            if(ch == '(')
            {
                openBrackets++;
            }
            else
            {
                if(ch == ')')
                {
                    openBrackets--;
                }
            }
            result = max(result,openBrackets);
        }

        return result;
    }
};