#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// going through dfs

bool isBST(vector <int>&pre){
    stack<int>st;
    int root = INT_MIN;

    for(int i =0;i<pre.size();i++){   // we are just checking the root posititon value
        if(pre[i]<root){
            return false;
        }
        while(!st.empty() && pre[i]>st.top()){
            root = st.top();
            st.pop();
        }
        st.push(pre[i]);
    }
    return true;
}

int main() {
    vector<int> pre = {40,35,10,80,100};
    if(isBST(pre)){
        cout<<"it is BST"<<endl;
    }else{
        cout<<" not BST"<<endl;
    }
    return 0;
}