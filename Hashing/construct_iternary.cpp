#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void construct_map(map<string,string>&dataSet){
    map<string,string>reverseHash;
    map<string,string>:: iterator it;
    for(auto x: dataSet){
        reverseHash[x.second]= x.first;
    
    }
    string start;
    for(auto x:dataSet){
        if(reverseHash.find(x.first)==reverseHash.end()){
            start = x.first;
            break;
        }
    }
    if(start.empty()){
        cout<<"route _not _fount"<<endl;
    }
    it = dataSet.find(start);
    while(it!=dataSet.end()){
        cout<<it->first<<"----->"<<it->second<<endl;
        it = dataSet.find(it->second);
    }
    return;
}

int main(){
    map<string, string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";
    construct_map(dataSet);

}