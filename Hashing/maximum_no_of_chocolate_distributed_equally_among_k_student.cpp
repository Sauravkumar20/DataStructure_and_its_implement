#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min_no_chocolated_dist(vector<int>arr,int k){
    int n = arr.size();
    vector<int>sum(n,0);
    unordered_map<int,int>mp;
    int curr_value = 0;
    int maxSum =0;

    sum[0] = arr[0];
    for(int i =1;i<n;i++){
        sum[i] = sum[i-1]+arr[i];
    }

    for(int i=0;i<n;i++){
        curr_value = sum[i]%k;

        if(curr_value==0){
            if(maxSum<sum[i]){
                maxSum = sum[i];
            }
        }

        else if(mp.find(curr_value)==mp.end()){
            mp[curr_value]=i;
        }

        else{
           if(maxSum< sum[i]-sum[mp[curr_value]]){
            maxSum = sum[i]-sum[mp[curr_value]];
           }
        }
    }
    return maxSum/k;

}

int main() {
    vector<int>arr = {2, 7, 6, 1, 4, 5};
    int k = 3;
    cout<<"maximum number of chocolate distributted equally among k student: "<<min_no_chocolated_dist(arr,k)<<endl;
}