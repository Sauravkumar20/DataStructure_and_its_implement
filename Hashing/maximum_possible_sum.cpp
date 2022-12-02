#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_Sum(vector<int>&A, vector<int>&B){
    unordered_map<int,int>mp;
    int ans = 0;
    int n = A.size();
    int sum =0;
    int intial =0;


    for(int i = 0; i<n; i++){

        while(mp.find(A[i])!=mp.end()){
            mp.erase(A[intial]);
            sum -= B[intial];
            intial++;
        }

        mp[A[i]]++;
        sum +=B[i];
        ans = max(sum,ans);
    }
    return ans;
}

int main() {
    vector<int> A = {0, 1, 2, 3, 0, 1, 4};
    vector<int> B = {9, 8, 1, 2, 3, 4, 5};
    cout<<"maximum possible sum: " <<max_Sum(A,B)<<endl;
}