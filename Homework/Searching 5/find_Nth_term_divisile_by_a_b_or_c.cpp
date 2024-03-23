/*
Given four integers a, b, c, and N. The task is to find the Nth term which is divisible by either of a, b or c.
Examples: 
 

Input: a = 2, b = 3, c = 5, N = 10 
Output: 14 
Sequence is 2, 3, 4, 5, 6, 8, 9, 10, 12, 14, 15, 16… 
Input: a = 3, b = 5, c = 7, N = 10 
Output: 18 
  */

#include<iostream>
using namespace std;

int count(int a ,int b, int c,int num){
    int count=0;
    for(int i=1;i<=num;i++){
        if(i%a==0 || i%b==0 || i%c==0){
            count++;
        }
    }
    return count;
}



int find_nth_term(int a ,int b, int c,int N){
    int start=1;
    int end= max(a,max(b,c))*N;
    int ans=0;
    while(start<=end){
        int mid=(start+end)>>1;
        if(count(a,b,c,mid)<=N){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}


int main(){
    int a=2, b=3 ,c=2 ,N=6;
    int Nth_term=find_nth_term(a,b,c,N);
    cout<<Nth_term;

    return 0;
}
