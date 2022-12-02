#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> n_maxPairComb(vector<int>&A, vector<int> &B){
    typedef pair<int,pair<int,int>>pi;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    vector<int>res;
    int k = A.size();
    
    for(int i =0;i<A.size();i++){
        for(int j =0;j<B.size();j++){
            int sum  = A[i]+B[j];
            if(pq.size()<k){
                pq.push(make_pair(sum,make_pair(A[i],B[j])));
            }else if(sum>pq.top().first){
                pq.pop();
                pq.push(make_pair(sum,make_pair(A[i],B[j])));
            }else{
                break;
            }
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top().first);
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    vector<int>A = { 3, 2, 4, 2 };
    vector<int>B = {4, 3, 1, 2};
    vector<int>res = n_maxPairComb(A,B);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    

}