#include<bits/stdc++.h>
using namespace std;
//abbaca
string removeDuplicate(string s){
    stack<char>st;
    string res ="";
    for(int i =0;i<s.size();i++){
        if(!st.empty() && st.top()==s[i]){
            st.pop();
            continue;
        }else{
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}


string remove_k_consecutive_Duplicate(string s, int k){
    string res = "";
    stack<pair<char,int>>st;

    for(int i =0;i<s.size();i++){
        if(st.empty()){
            st.push(make_pair(s[i],1));
        }else{
            if(st.top().first==s[i]){
                st.push(make_pair(s[i],st.top().second+1));
                if(st.top().second==k){
                    int x = k;
                    while(x!=0){
                        st.pop();
                        x--;
                    }
                }
            }else{
                st.push(make_pair(s[i],1));
            }
        }
    }
    while(!st.empty()){
        res.push_back(st.top().first);
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;

}

int main(){
    string s = "deeedbbcccbdaa";
    int k =3;
    cout<<removeDuplicate(s)<<endl;
    cout<<remove_k_consecutive_Duplicate(s,k)<<endl;
    return 0;
}