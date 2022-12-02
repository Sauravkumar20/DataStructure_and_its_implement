#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string MirrorSentence(string S){
	vector<string>store;
	string res= "";

	istringstream ss(S);
	string word;
	while(ss>>word){
		store.push_back(word);
	}
    int n = store.size()-1;
	for(int i =n;i>=0;i--){
		res= res+store[i]+" ";
	}
	return res;
}

int main() {
	string S = "hello world mindtree";
	cout<<MirrorSentence(S)<<endl;
	return 0;
}