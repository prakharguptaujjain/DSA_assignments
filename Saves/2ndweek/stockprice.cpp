#include<iostream>
using namespace std;

int main(){
  int n;cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  int res[n];
  for (int i = 0; i < n; i++)
  {
        bool test=true;
    for (int j = i+1; j < n; j++)
    {
      if(arr[j]>arr[i]){
        res[i]=j-i;
        test=false;
        break;
      }
    }
    if(test){res[i]=0;}

    
  }
  for (int i = 0; i < n; i++)
  {
    cout<<res[i]<<
;
  }
  
  
  return 0;
}
