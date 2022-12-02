#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// t(n) = n-1Cr*T(L)*T(R);
// where L we need to calculate, and right will be n-1-l;
// L = 2^(h-1)-1 + min(2^h-1, n- (2^h -1));

vector<vector<long long int>>nCr(101,vector<long long int>(101,-1));
#define mod  1000000007

long long int choose(long long int n,int r){
    if(r>n){
        return 0;
    }
    if(r==0)return 1;
    if(n<=1){
        return 1;
    }
    if(r==1){
        return n;
    }
    if(nCr[n][r]!=-1){
        return nCr[n][r];
    }

    long long int res = (choose(n-1,r-1)+choose(n-1,r))%mod;
    nCr[n][r] = res;
    return res; 
}

long long int noOfNodeinLeft(long long int A){
    int h = log2(A);
    int x = (((1<<(h-1))-1));
    int y = min((1LL<<(h-1)),(A-((1<<h)-1)));
    return x+y;
}

long long int getNodeMaxHeap(int A,vector<long long int>&dp){
    if(A<=1){
        return 1;
    }
    if(dp[A]!=-1){
        return dp[A];
    }
    long long int L = noOfNodeinLeft(A);
    long long int waytoChooseL = choose(A-1,L)%mod;
    long long int maxheapUsingLeft = getNodeMaxHeap(L,dp)%mod;
    long long int maxheapUsingRight = getNodeMaxHeap(A-1-L,dp)%mod;
    long long int ans = ((waytoChooseL)*((maxheapUsingLeft*maxheapUsingRight)%mod))%mod;
    dp[A]= ans;
    return ans;
}


int maxHeapForm(int A){
    vector<long long int>dp(101,-1);
    return getNodeMaxHeap(A,dp);
}


int main() {
    int A =2;
    cout<<maxHeapForm(A)<<endl;
}