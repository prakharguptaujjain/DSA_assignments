#include <iostream>
#include <climits>
using namespace std;
const int HEAPSIZE = 2000;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
class minheap
{
private:
    int arr[HEAPSIZE];
    int size = -1;
    void heapifyfordelete(int n)
    {
        int right = 2 * n + 2;
        int left = 2 * n + 1;
        if (2 * n + 2 > size)
        {
            arr[2 * n + 2] = INT_MAX;
        }
        if (2 * n + 1 > size)
        {
            arr[2 * n + 1] = INT_MAX;
        }
        int smallest = min(arr[right], min(arr[n], arr[left]));
        if (smallest == arr[n])
            return;
        else
        {
            if (smallest == arr[left])
            {
                swap(&arr[n], &arr[left]);
                heapifyfordelete(left);
            }
            else
            {
                swap(&arr[n], &arr[right]);
                heapifyfordelete(right);
            }
        }
    }
    void heapifyforinsert(int i)
    {
        if (arr[i] < arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            heapifyforinsert((i - 1) / 2);
        }
    }
public:
    int getmin()
    {
        return arr[0];
    }
    void insert(int x)
    {
        size++;
        arr[size] = x;
        heapifyforinsert(size);
    }
    int remove()
    {
        int temp = arr[0];
        swap(&arr[0], &arr[size]);
        size--;
        heapifyfordelete(0);
        return temp;
    }
    int getsize()
    {
        return size + 1;
    }
};
class maxheap
{
private:
    int arr[HEAPSIZE];
    int size = -1;
    void heapifyfordelete(int n)
    {
        int right = 2 * n + 2;
        int left = 2 * n + 1;
        if (2 * n + 2 > size)
        {
            arr[2 * n + 2] = INT_MIN;
        }
        if (2 * n + 1 > size)
        {
            arr[2 * n + 1] = INT_MIN;
        }
        int largest = max(arr[right], max(arr[n], arr[left]));
        if (largest == arr[n])
            return;
        else
        {
            if (largest == arr[left])
            {
                swap(&arr[n], &arr[left]);
                heapifyfordelete(left);
            }
            else
            {
                swap(&arr[n], &arr[right]);
                heapifyfordelete(right);
            }
        }
    }
    void heapifyforinsert(int i)
    {
        if (arr[i] > arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            heapifyforinsert((i - 1) / 2);
        }
    }

public:
    int getmax()
    {
        return arr[0];
    }
    void insert(int x)
    {
        size++;
        arr[size] = x;
        heapifyforinsert(size);
    }
    int remove()
    {
        int temp = arr[0];
        swap(&arr[0], &arr[size]);
        size--;
        heapifyfordelete(0);
        return temp;
    }
    int getsize()
    {
        return size + 1;
    }
};
void medianarray(int arr[], int n)
{
    minheap mi;
    maxheap ma;
    ma.insert(arr[0]);
    cout << arr[0] << " ";
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        if (x > ma.getmax())
        {
            mi.insert(x);
        }
        else
        {
            ma.insert(x);
        }
        while (ma.getsize() - mi.getsize() > 1 || mi.getsize() > ma.getsize())
        { // BALANCER

            if (ma.getsize() - mi.getsize() > 1)
            {
                int temp = ma.remove();
                mi.insert(temp);
            }
            else if (mi.getsize() > ma.getsize())
            {
                int temp = mi.remove();
                ma.insert(temp);
            }
        }
        cout << ma.getmax() << " ";
    }
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    medianarray(arr, n);
}

int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("output.txt","w",stderr);
#endif
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
