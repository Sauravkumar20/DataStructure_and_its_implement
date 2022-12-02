#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string SecondFrequent(vector<string>& words){
    string ans ="";
    string store ="";
    int i =1;
    int first_max =INT_MIN;
    int sec_max = INT_MIN;
    unordered_map<string,int>mp;
    for(auto x: words){
        if(mp.find(x)==mp.end()){
            mp[x] = 1;
        }else{
            mp[x]=mp[x]+1;
        }
    }
    for(auto x:mp){
        cout<<x.first<<" "<<x.second<<endl;
        if(first_max <x.second){
            first_max = x.second;
            store = x.first;

        }
    }
    mp.erase(store);
    for(auto x:mp){
        if(sec_max<x.second){
            sec_max = x.second;
            ans = x.first;
        }
    }
    cout<<mp.size()<<endl;
    return ans;
}

int main() {
    vector<string> words = {"ghi", "ghi", "aaa", "ghi", "ghi", "ghi" ,"ghi"};
    cout<<SecondFrequent(words)<<endl;
}