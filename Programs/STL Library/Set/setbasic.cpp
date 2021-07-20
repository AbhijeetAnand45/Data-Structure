#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(9);
    s.insert(15);
    s.insert(17);
    s.insert(0);
    cout<<"Size of set is "<<s.size()<<"\n";
    set<int>:: iterator it;
    for(it=s.begin();it != s.end();it++){
        cout<<*it<<" ";
    }
    return 0;

}