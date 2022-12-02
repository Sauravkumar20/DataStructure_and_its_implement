#include<bits/stdc++.h>
using namespace std;

void getSplit(vector<vector<int>> arr){
    vector<int>safe;
    vector<int>unsafe;
    vector<pair<int,int>>vec;
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<bool>>visited(m,vector<bool>(n,false));

    for(int i =0;i<arr.size();i++){
        cout<<"Sadnkdd"<<endl;
        for(int j =0;j<arr[i].size();j++){
            if(arr[i][j]==-1){
                cout<<i<< "   "<<j<<endl;
                vec.push_back(make_pair(i,j));
            }
        }
    }

    for(int i =0;i<vec.size();i++){
        int a = vec[i].first;
        int b = vec[i].second;
        for(int j =0;j<arr[b].size();j++){
            cout<<"adhkd"<<endl;
            if(!visited[b][j]){
                unsafe.push_back(arr[b][j]);
                visited[b][j] = true;
            }
            if(j==arr[b].size()){
                break;
            }
        }
        for(int j =0;j<arr.size();j++){
            cout<<"sdbsjbcbjc"<<endl;
            if(!visited[j][a]){
                unsafe.push_back(arr[j][a]);
                visited[j][a]=true;
            }
        }
        cout<<"dnsdd"<<endl;
    }

    cout<<"sahsjndld"<<endl;
    for(int i =0;i<arr.size();i++){
        for(int j =0;j<arr[0].size();j++){
            if(visited[i][j]==false){
                safe.push_back(arr[i][j]);
            }
        }
    }

    cout<<unsafe.empty()<<endl;
    for(int i =0;i<safe.size();i++){
        cout<<safe[i]<<" ";
    }
    cout<<endl;
}


int main() {
    int n,m,k;
    string x;
    /*
    cin>>n>>m>>k;
    vector<vector<int>>matrix;
    for(int i =0;i<m;i++){
        vector<int>store;
        for(int j = 0;j<n;j++){
            cin>>x;
            if(x== "B"){
                store.push_back(-1);
            }else{
                int a = stoi(x);
                store.push_back(a);
            }
        }
        matrix.push_back(store);
    }

    for(int i =0;i<matrix.size();i++){
        for(int j =0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    vector<vector<int>> arr = {{-1,1,2,-1},{3,4,5,2},{1,3,1,5}};
    getSplit(arr);
    //setZeroes(matrix);
    //cout<<getMaximumSum(arr,k)<<endl;
}



















































/*
void setzeroes(vector<vector<int>>& matrix) {
        //push rows and cols numbers with zeros in sets
        set<int>rows,cols;
        
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        
        //if we encounter either that row or column number set it to zero
        for(int i = 0;i<matrix.size();i++)
            for(int j = 0;j<matrix[i].size();j++)
                if(rows.find(i)!=rows.end() or cols.find(j)!=cols.end())
                       matrix[i][j] = 0;
        
                
       
}

void makeZero(vector<vector<int>> matrix, vector<pair<int,int>>& markZero){
        int i, r, c;
        vector<int>unsafe;
        for(i=0;i<markZero.size();i++){
            for(r=0,c=markZero[i].second;r<matrix.size();r++)
                unsafe.push_back(matrix[r][c]);
            
            for(r=markZero[i].first,c=0;c<matrix[0].size();c++)
                unsafe.push_back(matrix[r][c]);
        }

        for(auto x: unsafe){
            cout<<x<<" sas";
        }
    }
    
void setZeroes(vector<vector<int>>& matrix) {
    int i, j;
    cout<<"asss"<<endl;
    vector<pair<int,int>> markZero;
        
        for(i=0;i<matrix.size();i++)
            for(j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==-1)
                    markZero.push_back({i, j});
        
        makeZero(matrix, markZero);
    }
/*
int getAnswer(vector<vector<int>>arr,int k){
    vector<int>safe;
    vector<int>unsafe;
    vector<int>:: iterator it;
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(arr[i][j]==)
        }

    }

}

*/

/*
int getMaximumSum(vector<vector<int>>arr,int k){
    int res =0;
    for(int i =0;i<arr.size();i++){
        for(int j =0;j<arr[0].size();j++){
            if(arr[i][j]==-1){
                arr[i][j] =0;
            }
        }
    }

    setZeroes(arr);
    for(int i =0;i<arr.size();i++){
        for(int j =0;j<arr[0].size();j++){
            res = res + arr[i][j];
        }
    }
    return res;
}
*/
