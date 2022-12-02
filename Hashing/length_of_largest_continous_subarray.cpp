#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// case -1 when the all the elements in array  are distinct:

int lenOfSubarray(vector<int>arr){
    
    int max_len = 0;

    for(int i =0;i<arr.size()-1;i++){
        int mx = arr[i];
        int mn = arr[i];
        for(int j =i+1;j<arr.size();j++){
            mn = min(mn,arr[j]);
            mx = max(mx,arr[j]);
            if(mx-mn==j-i+1){
                max_len = max(max_len,mx-mn+1);
            }
        }
    }
    return max_len;
}

// when all the element are not distinct
//Algorithm: we keep it in the hashing and before doing further operation we need to check whether
// element is present or not if yes then break , otherwise take the min and max for each arr[j]
// and then check whether mx-mn==j-i if yes then update the max_len = max(max_len,mx-mn+1); and finally return max_len;

int lenOfSubarrayWithIdentical(vector<int>arr){
    int max_len =0;
    int n = arr.size();

    for(int i =0; i<n-1; i++){
        unordered_set<int>s;
        int mn = arr[i];
        int mx = arr[i];
        s.insert(arr[i]);
        for(int j =i+1;j< n;j++){
            if(s.find(arr[j])!=s.end()){
                break;
            }

            s.insert(arr[j]);
            mn = min(mn,arr[j]);
            mx = max(mx,arr[j]);
            if(mx-mn==j-i){
                max_len = max(max_len,mx-mn+1);
            }
        }
    }
    return max_len;
}

int lenOfContinousSubarray(vector<int>arr){
    unordered_map<int,int>mp;
    mp[arr[0]]=0;
    int count =1;
    int res = 0;

    for(int i=0;i<arr.size();i++){
        if(mp.find(arr[i]-1)!=mp.end() && i == mp[arr[i]-1]+1){
            count++;
        }else{
            count =1;
        }
        mp[arr[i]] = i;
        res = max(res,count);
    }
    return res;
}

int main() {
    vector<int>arr = {4, 5, 1, 2, 3, 4,5,6,7,8, 10, 11, 12};
    vector<int>arr1 = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    vector<int>arr2 = {10, 12, 12, 10, 10, 11, 10};
    cout<<lenOfContinousSubarray(arr)<<endl;
    cout<<"len the subarray continous is: "<<lenOfSubarray(arr1)<<endl;
    cout<<"len of the subarray continous (if elements are not distinct): "<<lenOfSubarrayWithIdentical(arr2)<<endl;
}