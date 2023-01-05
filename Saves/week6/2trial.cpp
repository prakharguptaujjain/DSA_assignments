#include <iostream>
using namespace std;
int maparr[100000];
int maarr[100000];
int cntmaarr = 0;
string touch = "YOYO";
int checker()
{
    if (touch != "YOYO")
        return 1;
    return 0;
}
void reset()
{
    for (int i = 0; i < 100000; i++)
    {
        maparr[i] = 0;
        maarr[i] = 0;
    }
    cntmaarr = 0;
}
void recurse(int arr[], int n, int x, int y,int cnt)
{
    cntmaarr=cnt;
    if (maparr[y] == 1 && checker)
    {
        touch = "YES";
        return;
    }
    for (int i = 0; i < cntmaarr; i++)
    {
        if (maparr[(x * maarr[i]) % 100000])
            break;
        maparr[(x * maarr[i]) % 100000] = 1;
        if (cntmaarr >= 100000)
        {
            if (maparr[y] == 1)
            {
                touch = "YES";
            }
            else
                touch = "NO";

            return;
        }
        maarr[cntmaarr] = (x * maarr[i]) % 100000;
        cntmaarr++;
        recurse(arr, n, (x * maarr[i]) % 100000, y,cntmaarr);
    }
}
void solve()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if(y%2==1 && x%2==0)
        {
            cout<<"NO";return;
        }
        reset();
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            long long int z;
            cin >> z;
            arr[i] = z % 100000;
            maarr[cntmaarr] = z % 100000;
            cntmaarr++;
        }
        recurse(arr, n, x, y,0);
        if (maparr[y] == 1)
        {
            touch = "YES";
        }
        else
        touch = "NO";

        cout<<touch;
    }

    return ;
}
int main()
{

    solve();
    return 0;
}