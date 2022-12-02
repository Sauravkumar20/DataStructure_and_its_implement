#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Product_itself(vector<int>&arr){
    vector<int>product(arr.size(),1);
    int temp = 1;

    for(int i =0;i<arr.size();i++){
        product[i] = temp;
        temp *= arr[i];
    }
    cout<<product[product.size()-1]<<endl;
    temp = 1;
    for(int i =arr.size()-1;i>=0;i--){
        //cout<<temp<<endl;
        product[i] *=temp;
        temp *= arr[i];
    }

    for(int i =0;i<product.size();i++){
        cout<<product[i]<<" ";
    }
    return;
}

int main() {
    vector<int> arr  = {10, 3, 5, 6, 2};
    Product_itself(arr);
    return 0;

}