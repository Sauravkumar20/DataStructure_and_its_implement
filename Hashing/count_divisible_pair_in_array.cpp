#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count_pair(vector<int>&arr){
    int count =0;
    unordered_map<int,int>mp;
    for(auto x:arr){
        mp[x]++;
    }

    for(int i =0;i<arr.size();i++){
        for(int j =1;j<=sqrt(arr[i]);j++){
            if(arr[i]%j==0){
                if(arr[i]==j*j){
                    count+=mp[j];
                }else{
                    count+=mp[j]+mp[arr[i]/j];
                }
            }
        }
        count = count-1;
    }
    return count;
}

int main(){
    vector<int>arr = {1,2,3};
    cout<<count_pair(arr)<<endl;
}