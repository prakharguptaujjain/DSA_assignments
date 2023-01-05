#include <iostream>
using namespace std;

void swap(auto arr,int a,int b)
{
    int temp=arr[a][0];
    int temp1=arr[a][1];
    arr[a][0]=arr[b][0];
    arr[a][1]=arr[b][1];
    arr[b][0]=temp;
    arr[b][1]=temp1;

}
int partition (auto arr,int s,int e){
    int pivot = arr[e][0];
    int fi;
    fi=s-1;
    for (int i = s; i <= e-1; i++)
    {
        if(arr[i][0]<pivot){
        fi++;swap(arr,fi,i);
        }
    }
    swap(arr,fi+1,e);
    return fi+1;
    
}
void quicksort(auto arr,int s,int e){
    if(s<e){
        int t=partition(arr,s,e);
        quicksort(arr,s,t-1);
        quicksort(arr,t+1,e);

    }

}
void print(auto arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i][0]<<" ";
    }
    
}
void solve()
{
    int n;cin>>n;
    auto *arrs=new int[n][2];
    auto *arre=new int[n][2];
    for (int i = 0; i < n; i++)
    {
        cin>>arrs[i][0];
        cin>>arre[i][0];
        int x;
        cin>>x;
        arrs[i][1]=x;
        arre[i][1]=x;
    }
    quicksort(arrs,0,n-1);
    quicksort(arre,0,n-1);
    int itr1=0,itr2=0;
    int maxa=-1;
    int sum=0;
    while(itr1!=n)
    {
        while(itr2<n && arrs[itr1][0]>=arre[itr2][0]){
            sum-=arre[itr2][1];
            itr2++;
        }
        sum+=arrs[itr1][1];
        itr1++;
        maxa=max(maxa,sum);
    }
    cout<<maxa<<endl;
    // print(arrs,n);
    // print(arre,n);


    

}


int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("output.txt","w",stderr);
#endif
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}