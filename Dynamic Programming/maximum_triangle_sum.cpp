#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSumTriangle(vector<vector<int>>&arr){
    int n = arr.size();
    vector<int>dp(arr.back());

    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=i;j++){
            dp[j] = max(dp[j],dp[j+1])+arr[i][j];
        }
    }
    return dp[0];
}



int main(){
vector<vector<int>>arr = {{8},{-4,4},{2,2,6},{1,1,1,1}};                    //{{3},{7,4},{2,4,6},{8,5,9,3}};
cout<<maxSumTriangle(arr)<<endl;

}