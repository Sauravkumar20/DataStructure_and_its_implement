#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int i, int j){
    if(i>j){
        return false;
    }
    while(i<j ){
        if(s[i++]!=s[j--]){
            return false;
        }
    }
    return true;
}

bool checkPartition_2(string s){

    int n = s.size();
    for(int i =0;i<n;i++){
        if(isPalindrome(s,0,i)&& isPalindrome(s,i+1,n-1)){
            //cout<<"found"<<endl;
            return true;
        }
    }
    return false;
}

bool checkPartition_3(string s){
    int n = s.size();
    for(int i =0;i<n;i++){
        if(isPalindrome(s,0,i) && checkPartition_2(s.substr(i+1,n))){
            cout<<s[i]<<endl;
            return true;
        }
    }
    return false;
}

bool ischeck(string s,int i,int k,vector<vector<int>>&dp){
    if(i>s.size()){
        return false;
    }
    if(dp[i][k]!=-1){
        return dp[i][k] = true;
    }
    if(k==1){
        if(isPalindrome(s,0,s.size())){
            return dp[i][k]=true;
        }else{
            dp[i][k] = false;
        }
    }
    bool ans = false;
    for(int j =i;j<=s.size();j++){
        if(isPalindrome(s,i,j)){
            ans = ans||ischeck(s,j+1,k-1,dp);
        }
    }
    return dp[i][k] = ans;
}

bool checkPartition_3_method2(string s){
    vector<vector<int>>dp(s.size(),vector<int>(4,-1));
    return ischeck(s,0,3,dp);
}


int main(){
    string s = "abcbbd";
    cout<<"palindrome partition I"<<endl;
    cout<<checkPartition_2(s)<<endl;
    cout<<"palindrome Partition IV"<<endl;
    cout<<checkPartition_3(s)<<endl;
    cout<<"palindrome Partition IV method 2"<<endl;
    cout<<checkPartition_3_method2(s)<<endl;
}