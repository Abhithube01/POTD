#include<iostream>
#include<vector>
using namespace std;
int main()
{
    return 0;
}
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
    int time = 0;
    while (tickets[k] > 0) {
        for (int i = 0; i < tickets.size() && tickets[k] > 0; ++i) {
            if (tickets[i] > 0) {
                tickets[i]--;
                time++;
            }
        }
    }
    
    return time;
        
    }
};