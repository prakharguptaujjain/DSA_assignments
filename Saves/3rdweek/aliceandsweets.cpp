#include<iostream>
using namespace std;

int main(){
  //code goes here
  int n,k;
  cin>>n>>k;
  int arr[n];
  int sum=0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin>>x;
    arr[i]=x;
  }
  for (int i = 0; i < k; i++)
  {
    sum+=arr[i];
  }
  int maxa;
  maxa=sum;
  for (int i = k-1; i >=0; i--)
  {
    sum=sum+arr[n+i-k]-arr[i];
    maxa=max(maxa,sum);
  }
  cout<<maxa;
  
  
  return 0;
}
