#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    return 0;
}
class Solution{
private:
	int res=0;
    vector<int> parent;
    vector<int> size;
public:
	static bool cmp(vector<int> &C1, vector<int> &C2){
	    return C1[2]<C2[2];
	}
	
	int get(int x){
	    return x*(x-1)/2;
	}
	
	int FIND(int node){
	    if(parent[node]==node){
	        return node;
	    }
	    return parent[node]=FIND(parent[node]);
	}
	
	void MERGE(int node1, int node2){
	    int PN1=FIND(node1);
	    int PN2=FIND(node2);
	    if(PN1==PN2){
	        return;
	    }
	    res-=get(size[PN1]);  // remove old dependency 
	    res-=get(size[PN2]);
	    if(size[PN1]>size[PN2]){
	        parent[PN2]=PN1;
	        size[PN1]+=size[PN2];
	        res+=get(size[PN1]);  // add answer for new component
	        size[PN2]=0;
	    }
	    else{
	        parent[PN1]=PN2;
	        size[PN2]+=size[PN1];
	        res+=get(size[PN2]);
	        size[PN1]=0;
	    }
	}
	          
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries){
	    parent.resize(n+1);
	    size.resize(n+1,1);
	    for(int i=0;i<=n;i++){
	        parent[i]=i;
	    }
	    vector<pair<int,int>> newQ;
	    for(int i=0;i<q;i++){
	        newQ.push_back({queries[i],i});
	    }
	    sort(newQ.begin(),newQ.end());
	    sort(edges.begin(),edges.end(),cmp);
	    vector<int> ans(q,0);
	    int i=0;
	    for(int k=0;k<q;k++){
	        while(i<edges.size() && edges[i][2]<=newQ[k].first){
	            MERGE(edges[i][0],edges[i][1]);
	            i++;
	        }
	        ans[newQ[k].second]=res;
	    }
	    return ans;
        }
	};