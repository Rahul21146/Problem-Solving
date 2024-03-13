

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solve(vector<int> &height, int target,vector<int> &ans){
    int start=0;
    int end=height.size()-1;
    if(target>height[end]){
        return 0;
    }
    while(start<end){
        int mid=start + (end-start)/2;

        if(height[mid]>=target){
            end=mid;
        }
        else{
            start=mid+1;
        }
    }
    return height.size()-end;
}

int main(){
    int n , q;
    cin>>n>>q;
    vector<int> height;
    cout<<"Enter the height of the students"<<endl;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        height.push_back(data);
    }
    sort(height.begin(),height.end());

    vector<int> atleastHeight;
    cout<<"Enter the atleastheight of the students"<<endl;
    for(int i=0;i<q;i++){
        int height;
        cin>>height;
        atleastHeight.push_back(height);
    }

    vector<int> ans;
    for(int i=0;i<q;i++){
        ans.push_back(solve(height,atleastHeight[i],ans));
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    

    return 0;
}
