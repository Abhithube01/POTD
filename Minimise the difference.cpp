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
    int minimizeDifference(int n,int k,vector<int> &arr)
    {
        vector<int> rightmn(n,0),rightmx(n,0);
        rightmx[n-1] = arr[n-1];
        rightmn[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmx[i] = max(rightmx[i+1],arr[i]); 
            rightmn[i] = min(rightmn[i+1],arr[i]);
        }
        int i=0,j=k-1;
        int mn=INT_MAX;
        int ans=INT_MAX;
        int mx=INT_MIN;
        while(j<n)
        {
            if(i!=0)
            {
                mn = min(arr[i],mn);
                mx = max(arr[i],mx);

            }
            int t1=mn,t2=mx;
            if(j!=n-1)
            {
                t1 = min(t1,rightmn[j+1]);
                t2 = max(t1,rightmx[j+1]);
            }
             ans = min(ans,abs(t2-t1));
             i++;
             j++;
        }
        return ans;

    }
};