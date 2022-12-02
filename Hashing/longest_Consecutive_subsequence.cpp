#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int lcs(vector<int>arr){
    unordered_set<int>s;
    int ans =0;
    for(auto x:arr){
        s.insert(x);
    }

    for(int i=0;i<arr.size();i++){
        int count =0;
        while(s.find(arr[i]++)!=s.end()){
            count++;
        }
        ans = max(ans,count);
    }
    return ans;
}

int largestIncreasingCons(vector<int>&arr){
    unordered_map<int,int>mp;
    int lis_size =1;
    int lis_idx =0;
    mp[arr[0]]=1;

    
    for(int i =1;i<arr.size();i++){
        mp[arr[i]] = mp[arr[i]-1]+1;
        //cout<<arr[i]<<"---> "<<mp[arr[i]]<<endl;
        if(lis_size < mp[arr[i]]){
            lis_size = mp[arr[i]];
            lis_idx = arr[i];
        }
    }
    int start = lis_idx-lis_size+1;
    while(start<=lis_idx){
        cout<<start<<" ";
        start++;
    }
    cout<<endl;
    return lis_size;
}

int main(){
    vector<int>arr = {2, 5, 3, 7, 4, 8, 5, 13, 6};   //{8,18,1,9,3,10,4,20,2,5,15,6};
    cout<<"longest consecutive subsequence :"<<endl;
    cout<<lcs(arr)<<endl;
    cout<<"longest increasing subsequence of consecutive integer:"<<endl;
    cout<<"lis_size: "<<largestIncreasingCons(arr)<<endl;
    return 0;
}