#include<bits/stdc++.h>
using namespace std;

int profit_with_trans(vector<int>&prices,int fee){
    int n = prices.size();
    int cuttoff = prices[0];
    int ans = 0;
    vector<int>profit;
    for(int i =0;i<n;i++){
        if(prices[i]<cuttoff){
            cuttoff = prices[i];
        }
        if(prices[i]>cuttoff+fee){
            ans+=prices[i]-fee-cuttoff;
            profit.push_back(prices[i]-fee-cuttoff);
            cuttoff = prices[i] -fee;
        }
    }
    return ans;
}

int max_profit_I(vector<int>&prices){
    int n = prices.size();
    int cuttoff = prices[0];
    int ans = 0;
    for(int i =0;i<n;i++){
        if(prices[i]<cuttoff){
            cuttoff = prices[i];
        }
        if(prices[i]>cuttoff){
            ans = max(ans,prices[i]-cuttoff);
        }
    }
    return ans;
}

int max_profit_II(vector<int>&prices){
    int n = prices.size();
    int cuttoff = prices[0];
    int ans =0;
    for(int i =0;i<n;i++){
        if(prices[i]<cuttoff){
            cuttoff = prices[i];
        }
        if(prices[i]>cuttoff){
            ans = ans + prices[i]-cuttoff;
            cuttoff = prices[i];
        }
    }
    return ans;
}

int solve(vector<int>&prices,int i,int trans,bool buy,vector<vector<vector<int>>>&dp){
    if(i== prices.size()||trans==0){
        return 0;
    }

    if(dp[buy][trans][i]!=-1){
        return dp[buy][trans][i];
    }
    int res =0;
    if(buy){
        res = max(res,solve(prices,i+1,trans,false,dp)-prices[i]);
        res = max(res,solve(prices,i+1,trans,true,dp));
    }else{
        res = max(res, solve(prices,i+1,trans-1,true,dp)+prices[i]);
        res = max(res,solve(prices,i+1,trans,false,dp));
    }
    dp[buy][trans][i] = res;
    return res;
}

int max_profit_III(vector<int>prices){
    int n = prices.size();
    vector<vector<vector<int>>>dp;
    dp.resize(2,vector<vector<int>>(3,vector<int>(n,-1)));
    int ans = solve(prices,0,2,true,dp);
    return ans;
}

int maxProfit(vector<int>&prices,int i,int trans,bool buy,vector<vector<vector<int>>>&dp){
    if(i==prices.size() || trans==0){
        return 0;
    }

    if(dp[buy][trans][i]!=-1){
        return dp[buy][trans][i];
    }

    int res = 0;
    if(buy){
        res = max(res,maxProfit(prices,i+1,trans,false,dp)-prices[i]);
        res = max(res, maxProfit(prices,i+1,trans,true,dp));
    }else{
        res =max(res,maxProfit(prices,i+1,trans-1,true,dp)+prices[i]);
        res = max(res,maxProfit(prices,i+1,trans,false,dp));
    }
    dp[buy][trans][i]= res;
    return res;
}

int max_profit_IV(vector<int>prices,int trans){
    int n = prices.size();
    vector<vector<vector<int>>>dp;
    dp.resize(2,vector<vector<int>>(trans+1,vector<int>(n,-1)));
    int ans = maxProfit(prices,0,trans,true,dp);  // we take the bool because to check whether we choosen in buying or not.
    return ans;
}



int main(){
    vector<int>prices = {2,3,0,8,4,9};
    vector<int>prices1 = {7,1,5,3,6,4};
    vector<int>prices3 = {3,3,5,0,0,3,1,4};
    vector<int>prices4 = {3,2,6,5,0,3};

    cout<<endl;
    cout<<"best time to buy and sell stock with transaction"<<endl;
    int trans_cost = 2;
    cout<<profit_with_trans(prices,trans_cost)<<endl;

    cout<<endl;
    cout<<"Best Time to Buy and Sell Stock"<<endl;
    cout<<max_profit_I(prices1)<<endl;

    cout<<"Best Time to Buy and Sell Stock II"<<endl;
    cout<<max_profit_II(prices1)<<endl;

    cout<<"Best Time to Buy and Sell Stock III"<<endl;
    cout<<max_profit_III(prices3)<<endl;

    int k = 4;
    cout<<"Best Time to Buy and Sell Stock IV"<<endl;
    cout<<max_profit_IV(prices4,k)<<endl;

    return 0;


}