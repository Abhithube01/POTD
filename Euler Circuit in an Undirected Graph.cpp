#include<iostream>
#include<vector>
using namespace std;
int main()
{
    return 0;
}
class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	     vector<int> degree(v, 0);
	    
	    for(int i = 0; i<v; i++) {
	        
	        degree[i] = adj[i].size();
	        
	    }
	    
	    for(int i = 0; i<v; i++) {
	        if(degree[i] % 2 != 0) {
	            return false;
	        }
	    }
	    
	    return true;
	
	}

};