#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// question 1: is possible to get the continous subarray such that sum is zero:

bool isPossible(vector<int>arr){
    unordered_map<int,int>mp;

    int currSum =0;
    for(int i =0;i<arr.size();i++){
        currSum+=arr[i];
        if(currSum==0 || mp.find(currSum)!=mp.end()){
            return true;
        }
        mp[currSum]=i;
    }
    return false;
}

// count the number of the continous subarry such that sum is zero:
int subarraySumtoZero(vector<int>arr){
    int max_len =0;
    int currSum = 0;
    unordered_map<int,int>mp;

    for(int i =0;i<arr.size();i++){
        currSum = currSum +arr[i];
        if(arr[i]=0  && max_len ==0){
            max_len = 1;
        }
        if(currSum==0){
            max_len =i+1;
        }
        if(mp.find(currSum)!=mp.end()){
            max_len = max(max_len,i-mp[currSum]);
        }
        else{
            mp[currSum]=i;
        }
    }
    return max_len;
}


// question no 3: print all the index of continous subarray such that the sum is zero:

vector<pair<int,int>> PrintAllSubarraySum(vector<int>&arr){
    unordered_map<int,vector<int>>mp;
    vector<pair<int,int>>ans;
    int currSum = 0;


    for(int i =0;i<arr.size();i++){
        currSum = currSum + arr[i];
        if(currSum==0){
            ans.push_back({0,i});
        }
        if(mp.find(currSum)!=mp.end()){
            vector<int> vc = mp[currSum];
            for(auto it = vc.begin(); it != vc.end(); it++){
                ans.push_back({*it+1,i});
            }
        }
         mp[currSum].push_back(i);
        
    }
    return ans;
}

void PrintLargestSubsWithZeroSum(vector<int>arr){
    unordered_map<int,int>mp;
    int currSum =0;
    int start =-1,end =-1,max_l = INT_MIN;

    mp.insert({0,-1});

    for(int i =0;i<arr.size();i++){
        currSum +=arr[i];
        if(mp.find(currSum)!=mp.end()){
            if(max_l<i-mp[currSum]){
                start = mp[currSum]+1;
                end = i;
                max_l = i -mp[currSum];
            }
        }
        else{
            mp.insert({currSum,i});
        }
    }
    for(int i =start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    cout<<isPossible(arr)<<endl;
    cout<<"max_len of subarray sum that sum is zero is:"<<subarraySumtoZero(arr)<<endl;
    cout<<"Print all the Subarray Sum :"<<endl;
    vector<pair<int,int>>ans = PrintAllSubarraySum(arr);
    
    for(auto x: ans){
        cout<<x.first<<"--->"<<x.second<<endl;
    }
    cout<<"print Largest Continuous Sequence Zero Sum:"<<endl;
    PrintLargestSubsWithZeroSum(arr);

}