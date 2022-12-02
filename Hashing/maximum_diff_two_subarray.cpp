#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_diff_twoSubarray(vector<int>arr){

    unordered_map<int,int>pmp;
    unordered_map<int,int>nmp;
    int positiveSum = 0;
    int negativeSum = 0;

    for(int i =0;i<arr.size();i++){
        if(arr[i]>0){
            pmp[arr[i]]++;
        }
    }

    for(int j =0;j<arr.size();j++){
        if(arr[j]<0){
            nmp[arr[j]]++;
        }
    }

    for(auto x:pmp){
        if(x.second==1){
            positiveSum+=x.first;
        }
    }
    for(auto x:nmp){
        if(x.second==1){
            negativeSum+=x.first;
        }
    }

    return (positiveSum-negativeSum);
}

int main(){
    vector<int>arr = {4, 2, -3, 3, -2, -2, 8};
    cout<<"Maximum possible difference of two subsets of an array: "<<max_diff_twoSubarray(arr)<<endl;
}