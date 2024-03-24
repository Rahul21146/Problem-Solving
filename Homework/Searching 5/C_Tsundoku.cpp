/*

Problem Statement
We have two desks: A and B. Desk A has a vertical stack of 
N books on it, and Desk B similarly has 
M books on it.

It takes us 
A 
i
​
  minutes to read the 
i-th book from the top on Desk A 
(1≤i≤N), and 
B 
i
​
  minutes to read the 
i-th book from the top on Desk B 
(1≤i≤M).

Consider the following action:

Choose a desk with a book remaining, read the topmost book on that desk, and remove it from the desk.
How many books can we read at most by repeating this action so that it takes us at most 
K minutes in total? We ignore the time it takes to do anything other than reading.

Constraints
1≤N,M≤200000
1≤K≤10 
9
 
1≤A 
i
​
 ,B 
i
​
 ≤10 
9
 
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N 
M 
K
A 
1
​
  
A 
2
​
  
… 
A 
N
​
 
B 
1
​
  
B 
2
​
  
… 
B 
M
​
 
Output
Print an integer representing the maximum number of books that can be read.

Sample Input 1
Copy
3 4 240
60 90 120
80 150 80 150
Sample Output 1
Copy
3
In this case, it takes us 
60, 
90, 
120 minutes to read the 
1-st, 
2-nd, 
3-rd books from the top on Desk A, and 
80, 
150, 
80, 
150 minutes to read the 
1-st, 
2-nd, 
3-rd, 
4-th books from the top on Desk B, respectively.

We can read three books in 
230 minutes, as shown below, and this is the maximum number of books we can read within 
240 minutes.

Read the topmost book on Desk A in 
60 minutes, and remove that book from the desk.
Read the topmost book on Desk B in 
80 minutes, and remove that book from the desk.
Read the topmost book on Desk A in 
90 minutes, and remove that book from the desk.
Sample Input 2

3 4 730
60 90 120
80 150 80 150
Sample Output 2

7
Sample Input 3
Copy
5 4 1
1000000000 1000000000 1000000000 1000000000 1000000000
1000000000 1000000000 1000000000 1000000000
Sample Output 3

0
*/


#include<iostream>
#include<vector>
using namespace std;

//binary search apporach

bool isPossible(long long prefixSum1[],long long prefixSum2[], int books,int n, int m,int limit_time){
    long long mini=max(0,books-m);
    long long high = min(books, n);
    
    for (long long i = mini; i <= high; i++) {
        long long time = prefixSum1[i] + prefixSum2[books - i];
        if (time <= limit_time)
            return true;
    }

    return false;
}

int solve(vector<long long> & arrA,vector<long long> & arrB, int n,int m,int limit_time){
    long long prefixSum1[n+1]={0};
    long long prefixSum2[m+1]={0};

    
    for(int i=1;i<=n;i++){
        prefixSum1[i]+=prefixSum1[i-1]+arrA[i-1];
    }

    for(int i=1;i<=m;i++){
        prefixSum2[i]+=prefixSum2[i-1]+arrB[i-1];
    }

    long long start=-1;
    long long end=m+n+1;
    long long ans=0;
    while(start<=end){
        long long mid=start+(end-start)/2;
        if(isPossible(prefixSum1,prefixSum2,mid,n ,m,limit_time)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

void insert(vector<long long> & arr,int n){
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
}
int main(){
    vector<long long> arrA;
    vector<long long> arrB;

    int n;
    int m;

    int time_limit;
    cout<<"enter the size of arrA , arrB and limit time"<<endl;
    cin>>n>>m>>time_limit;
    cout<<"enter the element of arrA"<<endl;
    insert(arrA,n);
    cout<<"enter the element of arrB"<<endl;
    insert(arrB ,m);

    //int ans=find_min_book(arrA,arrB,n,m,time_limit);
    int ans=solve(arrA,arrB,n,m,time_limit);
    cout<<ans;

    return 0;
}
