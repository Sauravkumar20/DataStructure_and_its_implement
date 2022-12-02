#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>countDistinct(vector<int>&arr,int k){
    vector<int>res;
    unordered_map<int,int>m;
    int count =0;

    for(int i =0;i<k;i++){
        if(m[arr[i]]==0){
            count++;
        }
        m[arr[i]]+=1;
    }
    res.push_back(count);

    for(int i=k; i<arr.size();i++){
        if(m[arr[i-k]]==1){
            count--;
        }
        m[arr[i-k]]-=1;

        if(m[arr[i]]==0){
            count++;
        }
        m[arr[i]]+=1;
        res.push_back(count);
    }
    return res;
}

int main(){
     vector<int>arr = {1,2,1,3,4,2,3};
     int k = 4;
     vector<int>res = countDistinct(arr,k);
     for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
     }

}