#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job j1,Job j2){
        return(j1.profit>j2.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
    
        sort( arr, arr+n, comparator);
        
        int maxi = arr[0].dead;
        
        for(int i=1;i<n;i++){
             maxi = max(arr[i].dead,maxi);
        }
        
        vector<int> units(maxi+1,-1);
        
        int jobs = 0;
        int prof = 0;
        
        for(int i=0;i<n;i++){
           for(int j = arr[i].dead;j>0;j--){
               if(units[j] == -1){
                   units[j] = arr[i].id;
                   jobs++;
                   prof += arr[i].profit;
                   break;
               }
           }
        }
        vector<int>ans;
        ans.push_back(jobs);
        ans.push_back(prof);
        return ans;
    } 
};

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}

