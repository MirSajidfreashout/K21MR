#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack{
    public:
    vector<T> stack;

    void push(T n){
        stack.push_back(n);
    }

    void pop(){
        if (stack.size() == 0){
            cout<<"Stack Underflow Error";
            exit(0);
            return;
        }
        auto elem = stack.end() -1;
        stack.pop_back();
        return;
    }
    T top(){
        if (stack.size() == 0) return 0;
        else return stack[stack.size()-1];
    }

    int size(){
        return stack.size();
    }

    void display(){
        for(auto i = stack.rbegin(); i != stack.rend(); i++) cout<<*i<<' ';
        cout<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    if(n < 1) {cout<<"Invalid Input"; return 0;}
    while(n--){
        string s;
        cin>>s;
        Stack<char> container;
        for(int i = 0; i < s.size()/2; i++){
            container.push(s[i]);
        }
        for(int i = s.size()/2; i < s.size(); i++){
            if(s[i] == container.top()) container.pop();
        }
        if (container.size() == 0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
return 0;
}
