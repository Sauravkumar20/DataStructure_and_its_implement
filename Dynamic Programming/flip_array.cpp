#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
int flipArray(vector<int>& arr,int n){
    unordered_map<int,int>dp[2];
    bool flag = 1;
    int sum = accumulate(arr.begin(),arr.end(),sum);

    for(int i = - sum;i<=sum;i++){
        dp[0][i] = INT_MAX;
    }

    dp[0][0]=0;
    for(int i = 1;i<=n;i++){
        for(int j = -sum;j<=sum;j++){
            dp[flag][j]=INT_MAX;

            if(j-arr[i-1]<=sum && j-arr[i-1]>=-sum){ // if sign arr[i-1] is not flip to make sum =j then dp[flag][j] =dp[flag^1][j-arr[i-1]]
                dp[flag][j] =dp[flag^1][j-arr[i-1]];
            }
            if(j+arr[i-1]<=sum && j+arr[i-1]>=-sum  && dp[flag^1][j+arr[i-1]] != INT_MAX){ // if sign arr[i-1] is flip to make sum = j, we do this;
                dp[flag][j] = min(dp[flag][j],dp[flag^1][j+arr[i-1]]+1);
            }
        }
        flag =flag^1;  // toggling
    }
    for (int i = 0; i <=sum; i++){
        if(dp[flag^1][i]!=INT_MAX){
            return dp[flag^1][i];
        }
    }
    return n-1;
}

// alternative method similar problem to 0-1 knapsack problem:

int flip_array(vector<int>&A,int n){
    int sum = accumulate(A.begin(),A.end(),sum);
    sum = sum/2;
    vector<vector<int>>dp(n+1,vector<int>(sum+1));

     for(int i = 0;i<=n;i++){
        dp[i][0] = 0;
    }
    
    for(int i = 1;i<=sum;i++){
        dp[0][i] = INT_MAX;
    }
   

    for(int i =1;i<=n;i++){
        for(int j =1;j<=sum;j++){
            if(A[i-1]<=j){
                dp[i][j] = min(dp[i-1][j],1+dp[i-1][j-A[i-1]]);
                
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][sum]==INT_MAX){
        for(int i=0;i<=sum;i++){
            if(dp[n][i]!=INT_MAX){
                dp[n][sum]=dp[n][i];
            }
        }
    }

    return dp[n][sum];
}
*/

int distribute(vector<vector<int>>v){
    int n = v.size();
        sort(v.begin(),v.end());
        
        vector <vector<int>> ans;
        
        int st =v[0][0];
        int ed =v[0][1];
        
        for(int i=1;i<n;i++){
            
            if(v[i][0]>ed){
                ans.push_back({st,ed});
                st = v[i][0];
                ed=  v[i][1];
            }else{
                ed = max(ed,v[i][1]);
            }
        }
        
        ans.push_back({st,ed});
        int ct = (int)ans.size(); int res = 2^(ct-2);
        return res;
}
int main() {
    //vector<int> arr  = {10, 22, 9, 33, 21, 50, 41, 60 };
    vector<vector<int>> mat(5,vector<int>(2));
    mat = {{1,5},{3,8},{10,15},{13,14},{20,100}};
    /*
    cout<<flipArray(arr,arr.size())<<endl;
    cout<<flip_array(arr,arr.size())<<endl;
    */
   cout<<distribute(mat)<<endl;
    return 0;

}