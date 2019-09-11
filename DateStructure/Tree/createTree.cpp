//
// Created by devinchang on 2019/9/10.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 重建二叉树

struct BiTreeNode{
    int val;
    BiTreeNode *left, *right;
    BiTreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

BiTreeNode *constructCore(int *stPre, int *endPre, int *stIn, int endIn){
    int rootval = stPre[0];
    BiTreeNode *root = new BiTreeNode(rootval);
    if(stPre == endPre){
        if(stIn == endIn && *stPre == *stIn)
            return root;
        else
            throw exception("Invalid input");
    }
    //
    int *rootInorder = stIn;
    while(rootInorder <= endIn && *rootInorder != rootval)
        ++rootInorder;
    if(rootInorder == endIn && *rootInorder != rootval)
        throw exception("Invalid input");
    int leftlen = rootInorder - stIn;
    int *leftPreoderEnd = stPre + leftlen;
    if(leftlen > 0){
        // construct left
        root->left = constructCore(stPre + 1, leftPreoderEnd, stIn, rootInorder-1);
    }
    if(leftlen < endPre - stPre){
        // construct right
        root->right = constructCore(leftPreoderEnd+1, endPre, rootInorder + 1, endIn);
    }
    return root;
}


BiTreeNode *construct(vector<BiTreeNode*> &preorder, vector<BiTreeNode*> &inorder, int length){
    if(preorder.size() < 1 || inorder.size() < 1)
        return nullptr;

}


int main(){

    return 0;
}







