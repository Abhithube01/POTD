#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    return 0;
}
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        istringstream iss(s);
        string word,lastWord;

        while(iss >> word)
        {
            lastWord = word;

        }       
        return lastWord.length();
        
    }
};