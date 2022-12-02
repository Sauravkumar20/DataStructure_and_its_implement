#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int j=0;j<=n;j++){
            dp[j][0]=j;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]= dp[i][j];
                }else{                   //insertion , deletion,repalce 
                    dp[i+1][j+1] = min(dp[i][j+1],min(dp[i+1][j],dp[i][j]))+1;
                }
            }
        }
        return dp[n][m];
    }

int main() {
    string word1 = "armaze";
    string word2 = "amazon";
    cout<<minDistance(word1,word2)<<endl;
    return 0;
}
