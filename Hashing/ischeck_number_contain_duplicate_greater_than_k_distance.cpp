#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isCheck(vector<int>&arr,int k){
    unordered_map<int,int>mp;
    for(int i =0;i<arr.size();i++){
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]]=i;
        }else{
            if(i- mp[arr[i]]<=k){
                return true;
            }
            mp[arr[i]]++;
        }
    }
    return false;
}

int main(){
    vector<int>arr  = {1, 2, 1,3, 4};
    int k = 3;
    cout<<isCheck(arr,k)<<endl;
}