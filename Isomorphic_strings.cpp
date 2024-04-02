#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    return 0;
}

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int m =s.length();
        int n =t.length();
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;

        if(m != n)
        {
            return false;
        }
        for(int i=0;i<m;i++)
        {
            char sChar = s[i];
            char tChar = t[i];

            if (mp1.find(sChar) != mp1.end() && mp1[sChar] != tChar)
            {
                return false;
            }

            if (mp2.find(tChar) != mp2.end() && mp2[tChar] != sChar)
            {
                return false;
            }
            mp1[sChar] = tChar;
            mp2[tChar] = sChar;

        }
        return true;
    }
};