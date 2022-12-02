#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPair(vector<int>&arr,int target){
    unordered_map<int,int>mp;
    for(auto x:arr){
        mp[x]++;
    }
    for(int i=0;i<arr.size();i++){
        int x = target - arr[i];
        if(mp.find(x)!=mp.end()){
            return true;
        }
    }
    return false;
}

vector<vector<int>> twoSumPair(vector<int>&arr,int target){
    unordered_map<int,int>mp;
    vector<vector<int>>res;
    int count = 0;

    for(int i =0;i<arr.size();i++){
        int k = target - arr[i];
        if(mp.find(k)!=mp.end()){
            count++;
            res.push_back({mp[k]+1,i+1});
            //return res;
        }
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]]=i;
        }
    }
    return res;
}

bool isPairMutliple(vector<int>&arr,int k){
    unordered_map<int,int>mp;
    for(int i =0;i<arr.size();i++){
        int x = k/arr[i];
        if(mp.find(x)!=mp.end()){
            return true;
        }else{
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=i;
            }
        }
    }
    return false;
}

int maxShortestDistance(vector<int>&arr,int target){

}

int main() {
    vector<int>arr = {2, 7, 11,9,3,15,1,8};
    int target = 18;
    cout<<isPair(arr,target)<<endl;
    vector<vector<int>>pair = twoSumPair(arr,target);
    for(int i =0;i<pair.size();i++){
        cout<<pair[i][0]<<" "<<pair[i][1]<<endl;;
    }
    cout<<endl;
    cout<<isPairMutliple(arr,target)<<endl;

}