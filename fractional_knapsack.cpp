#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    
    static bool comparator(Item a,Item b){
        double avalue = (double)a.value/(double)a.weight;
        double bvalue = (double)b.value/(double)b.weight;
        return avalue > bvalue;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comparator);
        
        double val = 0.0;
        int currwt = 0;
        
        for(int i=0;i<n;i++){
           if(currwt + arr[i].weight <= W){
               currwt += arr[i].weight;
               val += arr[i].value;
           }else{
               int remain = W - currwt;
               val += (arr[i].value / (double) arr[i].weight) * (double) remain;
               break;
           }
        }
        return val;
    }
        
};

int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
	
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
	
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
