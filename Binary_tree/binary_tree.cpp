#include<iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;


int maxVal = INT_MIN;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree{
    public:
    Node* root ;
    BinaryTree();
    Node* constructBT(Node* root,int i,vector<int>& arr,int n);
    void inorderTraversal(Node* root);
    void preOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
    int heightOfBT(Node* root);
    int minDepthofBT(Node* root);
    bool isBalancedTree(Node* root);
    bool isBST(Node* root);
    Node* LCAofBT(Node* root, int p, int q);
    void levelOrderTraversal(Node* root);
    void sumOfLeavesNode(Node* root,int &sum);
    void sumofLeftLeaves(Node* root, int &ans);
    void PathSum(Node* root,int &maxSusm, int sums);


};

BinaryTree::BinaryTree(){
    Node* root;
}

Node* BinaryTree::constructBT(Node* root,int i, vector<int> &arr,int n){   // insertion in Binary Tree;

    if(i==0){
        Node* newnode = new Node(arr[i]);
        root = newnode;
    }

    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n){
        Node* newnode = new Node(arr[left]);
        root->left = newnode;
        constructBT(root->left,left,arr,n);
    }
    if(right<n){
        Node* newnode = new Node(arr[right]);
        root->right = newnode;
        constructBT(root->right,right,arr,n);
    }
    return root;
}

void BinaryTree::inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

void BinaryTree::preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void BinaryTree::postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<<" ";
}

int BinaryTree::heightOfBT(Node* root){
    if(root==NULL){
        return 0;
    }
    int h1= heightOfBT(root->left);
    int h2 = heightOfBT(root->right);
    return (1+ max(h1,h2));
}

int BinaryTree::minDepthofBT(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = minDepthofBT(root->left);
    int right = minDepthofBT(root->right);

    if(left==0 || right ==0){
        return (1+max(left,right));
    }else{
        return(1+min(left,right));
    }
}

bool BinaryTree::isBalancedTree(Node* root){
    if(root==NULL){
        return true;
    }

    int left = heightOfBT(root->left);
    int right = heightOfBT(root->right);

    if(abs(left-right)<=1 && isBalancedTree(root->left) && isBalancedTree(root->right)){
        return true;
    }else{
        return false;
    }
}

bool BinaryTree::isBST(Node* root){
    if(root==NULL){
        return true;
    }
    if(root->left!=NULL && root->val>root->left->val){
        return isBST(root->left);
    }
    if(root->right!=NULL && root->val<root->right->val){
        return isBST(root->right);
    }
    return false;
}

Node* BinaryTree::LCAofBT(Node* root, int p, int q){
    if(root->val==p || root->val==q){
        return root;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    Node* leftcl =NULL;
    Node* rightcl = NULL;
    if(root->left){
        leftcl = LCAofBT(root->left,p,q);
    }
    if(root->right){
        rightcl = LCAofBT(root->right,p,q);
    }
    if(leftcl && rightcl){
        return root;
    }
    if(leftcl){
        return leftcl;
    }else{
        return rightcl;
    }
}
// algorithms of LCA is first we go to left and find the search and return 
//the node and then right to find the node and then we find the LCA of that,

void BinaryTree::levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    int prevCounter =1;
    int currCounter =0;

    queue<Node*>q;

    q.push(root);
    while(!q.empty()){
        Node* root = q.front();
        q.pop();
        prevCounter--;
        cout<<root->val<<" ";

        if(root->left!=NULL){
            q.push(root->left);
            currCounter++;
        }
        if(root->right!=NULL){
            q.push(root->right);
            currCounter++;
        }
        if(prevCounter==0){
            cout<<endl;
            prevCounter=currCounter;
            currCounter=0;

        }
    }

}

void BinaryTree::sumOfLeavesNode(Node* root,int &sum){
    /*
    if(root ==NULL){
        return;
    }
*/
    if(root->left==NULL && root->right==NULL){
        sum +=root->val;
        return;
    }

    sumOfLeavesNode(root->left,sum);
    sumOfLeavesNode(root->right,sum);
    
}

void BinaryTree::sumofLeftLeaves(Node* root,int &ans){
    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->left!=NULL){
        if(root->left->left==NULL && root->left->right==NULL){
            ans = ans+ root->left->val;
        }
    }

    sumofLeftLeaves(root->left,ans);
    sumofLeftLeaves(root->right,ans);
}

void BinaryTree::PathSum(Node* root,int &maxSum,int sums){
    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        sums = sums+root->val;
        maxSum = max(sums,maxSum);
        sums = sums-root->val;
        return;
    }

    PathSum(root->left,maxSum,sums+root->val);
    PathSum(root->right,maxSum,sums+root->val);
}



int main() {
    vector<int>arr = {3,9,20,15,7,12,18};
    int n = arr.size();

    BinaryTree bt;
    Node* root = bt.constructBT(root,0,arr,arr.size());

    /*              3
                   /  \
                  9   20
                /  \  /   \
               15   7 12   18
    */

    cout<<"inorder Traversal of BinaryTree:"<<endl;
    bt.inorderTraversal(root);
    cout<<endl;

    cout<<"preorder Traversal of BinaryTree:"<<endl;
    bt.preOrderTraversal(root);
    cout<<endl;

    cout<<"postorder Traversal of BinaryTree:"<<endl;
    bt.postOrderTraversal(root);
    cout<<endl;

    cout<<"Height of BinaryTree: "<<bt.heightOfBT(root)<<endl;
    cout<<"MinDepth of BinaryTree: "<<bt.minDepthofBT(root)<<endl;

    if(bt.isBalancedTree(root)){
        cout<<"Balanced BinaryTree"<<endl;
    }else{
        cout<<" inbalanced BinaryTree"<<endl;
    }

    if(bt.isBST(root)){
        cout<<"Binary Tree is BST"<<endl;
    }else{
        cout<<"Binary Tree is not BST"<<endl;
    }
    Node* newroot = bt.LCAofBT(root,15,12);
    cout<< "LCA of the BinaryTree is: "<<newroot->val<<endl;

    cout<<"levelOrder Traversal of BinaryTree:"<<endl;
    bt.levelOrderTraversal(root);
    cout<<endl;

    int sum =0;
    bt.sumOfLeavesNode(root,sum);
    cout<<"Sum of the leaf Node of BinaryTree: "<<sum<<endl;

    int ans =0;
    bt.sumofLeftLeaves(root,ans);
    cout<<"Sum of the left leaves is: "<<ans<<endl;

    int maxSum =0;
    bt.PathSum(root,maxSum,0);
    cout<<"Maximum path Sum of the binary tree is: "<<maxSum<<endl;

    return 0;


}