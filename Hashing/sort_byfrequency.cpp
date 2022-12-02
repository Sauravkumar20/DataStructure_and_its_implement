#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void SortByFrequency(vector<int>arr,int m){
    unordered_map<int,int>mp;
    for(int i =0;i<arr.size();i++){
        mp[arr[i]]++;
    }

    multimap<int,int>mmp;
    for(auto x:mp){
        mmp.insert({x.second,x.first});
    }

    for(auto x: mmp){
        cout<<x.second<<"-->"<<x.first<<endl;
    }
    int count = 0;
    for(auto x:mmp){
        if(x.first<=m){
            m-=x.first;
            count++;
        }
    }

    cout<<"after removing the m element: "<<mmp.size()-count<<endl;
}

int main() {
    vector<int>arr = {2, 2, 1, 3, 3, 3};
    int m = 3;
    SortByFrequency(arr,m);
}