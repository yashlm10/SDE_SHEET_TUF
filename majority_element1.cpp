#include <bits/stdc++.h>
using namespace std;

int find_majority_hash(vector<int> v, int n){
    map <int,int> hmap;
    for(int i=0;i<n;i++){
        hmap[v[i]]++;
    }

    for(auto it : hmap){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
}

int find_majority_mooreAlgo(vector<int> v, int n){
    int count=1;
    int element= v[0];
    int current_ele = v[0];
    for(int i=1;i<n;i++){
        if(v[i]==element){
            count++;
        }else{
            if(count == 0){
                element = v[i];
                count++;
            }else{
                count--;
            }
        }
    }
    return element;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    int value;
    for(int i=0;i<n;i++){
       cin >> value;
       v.push_back(value);
    }
    int answer1 = find_majority_hash(v,n);
    int answer2 = find_majority_mooreAlgo(v,n);

    cout << answer1 << " " << answer2  << endl;
    return 0;
}