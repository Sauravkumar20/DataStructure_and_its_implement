#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxPointOnLine(vector<pair<int,int>>&points){
   int n = points.size();
   int ans =1;
   int overlap =0;
   int vertical =0;
   unordered_map<double,int>mp;
   for(int i =0;i<n;i++){
    int overlap =1;
    int vertical =0;
    for(int j =i+1;j<n;j++){
        if(points[i]==points[j]){
            overlap++;
        }else if(points[i].first==points[j].second){
            vertical++;
        }else{
            double dy = points[j].second - points[i].second;
            double dx = points[j].first - points[i].second;
            double slope = dy/dx;
            mp[slope]++;
        }
    }
    for(auto x:mp){
        if(x.second+overlap>ans){
            ans = x.second+overlap;
        }
    }
    if(vertical+overlap>ans){
        ans = vertical+overlap;
    }
    mp.clear();
   }
   return ans;
}

int main(){
    vector<pair<int,int>>points = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4}};
    cout<<maxPointOnLine(points)<<endl;
}