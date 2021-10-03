#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
}

int main(){
    queue<int> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        q.push(data);
    }
    reverse(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}