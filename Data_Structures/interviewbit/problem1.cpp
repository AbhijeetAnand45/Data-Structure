
// By Abhijeet Anand

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
bool compare( const vector<int>& v1,const vector<int>& v2 ) {
            return v1[1] > v2[1];
    }


   
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort(boxTypes.begin(),boxTypes.end(),[](vector<int> v1, vector<int> v2){
        //     return v1[1]>v2[1];
        // });
       sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans = 0;
        
        for(int i=0;i<boxTypes.size();i++){
           
            if(truckSize >= boxTypes[i][0]){
                truckSize -= boxTypes[i][0];
                ans += boxTypes[i][0] * boxTypes[i][1];
            }
            else{
                ans += truckSize * boxTypes[i][1];
                truckSize = 0;
                break;
            }
            
        }
        return ans;
}
int main(){
    fast
    cout<<maximumUnits<<"\n";
    
}