#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;cin>>n;
    int ar[3];
    ar[0]=0;
    ar[1]=0;
    ar[2]=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        ar[x%3]++;
    }
    int z=min(ar[1],ar[2]);
    ar[1]-=z;
    ar[2]-=z;
    cout<<ar[0]+z+int((ar[1]+ar[2])/3);
  return 0;
}
