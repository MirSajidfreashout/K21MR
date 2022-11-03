#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
stack<int> preorder;
int Index;

void insert(vector<int> postorder, int start, int end){
    if (start > end) return;

    int val = postorder[Index];
    int inIndex = m[val];
    Index--;

    insert(postorder, inIndex+1, end);
    insert(postorder, start, inIndex-1);

    preorder.push(val);
}

int main(){
    vector<int> inorder;
    vector<int> postorder;
    int elem;
    while(cin>>elem){
        inorder.push_back(elem);
    }
    postorder.insert(postorder.begin(), inorder.begin()+inorder.size()/2, inorder.end());
    inorder.resize(inorder.size()/2);
    
    if(inorder.size()<3 || inorder.size()>10){
        cout<<"Invalid input";
        return 0;
    }

    for(int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
    Index = inorder.size()-1;

    insert(postorder, 0, Index);

    while(!preorder.empty()){
        cout<<preorder.top()<<' ';
        preorder.pop();
    }

return 0;
}