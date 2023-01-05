#include <iostream>
using namespace std;


void solve()
{
    int n;cin>>n;
    int arr[1001];
    for (int i = 0; i < 1001; i++)
    {
        arr[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr[x+500]++;
    }
    for (int i = 0; i < 1001; i++)
    {
        int times=arr[i];
        for (int j = 0; j < times; j++)
        {
            cout<<i-500<<" ";
        }
        
    }
    cout<<endl;
    


}


int main()
{
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}

