#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int>&arr){
    unordered_map<int,int>mp;
    int n = arr.size();
    for(auto x:arr){
        mp[x]++;
    }
    int next_miss =1;
    for(int  i =0;i<arr.size();i++){
        if(mp[arr[i]]!=1 || arr[i]>n || arr[i]<1){
            mp[arr[i]]--;
            while(mp.find(next_miss)!=mp.end()){
                next_miss++;
            }
            arr[i] = next_miss;
            mp[next_miss]=1;
        }
    }
    for(auto x:arr){
        cout<<x<<" ";
    }
}

int main(){
    vector<int>arr = {2, 2, 3, 3};
    permutation(arr);
    return 0;
}
