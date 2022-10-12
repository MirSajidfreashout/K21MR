#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue: protected list<T> {
    public:
    void enqueue(T value){
        this->push_back(value);
    };
    bool deque(){
        if(list<T>::size() == 0) return 0;
        this->pop_front();
        return true;
    }
    T front(){
        return *(this->begin());
    }
    bool empty(){
        return !this->size();
    }
    void display(){
        for(auto i  = this->begin(); i!=this->end(); i++) cout<<*i<<' ';
    }
};

int main(){
    int n, elem;
    cin>>n;
    Queue<int> q;
    while(n--){
        cin>>elem;
        q.enqueue(elem);
    }
    int k;
    cin>>k;
    Queue<int> modifiedq;
    vector<int> v;
    while(k--){
        v.push_back(q.front());
        q.deque();
    }
    for(auto i = v.rbegin(); i != v.rend(); i++){
        modifiedq.enqueue(*i);
    }
    while(!q.empty()){
        modifiedq.enqueue(q.front());
        q.deque();
    }
    modifiedq.display();
return 0;
}
