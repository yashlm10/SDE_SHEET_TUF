#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate_mysol(int numRows) {
        vector<vector<int>> v;
        for(int i=0;i<numRows;i++){
           vector<int> row(i+1,1);
           for(int j=1;j<i;j++){
               row[j] = v[i-1][j] + v[i-1][j-1];
           }
           v.push_back(row);
        }
        
        return v;
    }

vector<int> generateRow(int row){
    vector<int> reqrow;
    long long first = 1;
    reqrow.push_back(first);

    for(int i=1;i<row;i++){
       first *= row-i;
       first /= i;
       reqrow.push_back(first);
    }
    return reqrow;
}

vector<vector<int>> generate(int numRows){
    vector<vector<int>> u;
    for(int i=1;i<=numRows;i++){
        u.push_back(generateRow(i));
    }
    return u;
}

int nCr(int n,int r){
    long long ans =1;
    for(int i=0;i<r;i++){
        ans *= n-i;
        ans /= i+1;
    }
    return ans;
}

int generateValue(int r, int c){
    int answer;
    answer = nCr(r-1,c-1);
    return answer;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> pascal;
        pascal = generate_mysol(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout << pascal[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";
        pascal = generate(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout << pascal[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";

        int row;
        cin >> row;
        vector<int> printRow = generateRow(row);
        for(int i=0;i<printRow.size();i++){
            cout << printRow[i] << " ";
        }
        cout << endl;

        int r,c;
        cin >> r >> c;
        int value = generateValue(r,c);
        cout << value << endl;

    }
}
     