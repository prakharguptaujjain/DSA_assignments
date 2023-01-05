#include <iostream>
#include <unordered_map>
using namespace std;
class node
{
public:
    string s;
    int count = 0;
    node(string k, int z)
    {
        s = k;
        count = z;
    }
};
class heap
{
private:
    void swap(node *a, node *b)
    {
        node *temp = new node(a->s, a->count);
        a->count = b->count;
        a->s = b->s;
        b->count = temp->count;
        b->s = temp->s;
    }

    // void CBT(int arr[],int low,int high)
    // {
    //     int mid=(low+high)/2;
    //     node* temp=new(node())
    //     arr[mid]=
    // }
    int size = 0;
    void buildheap(node *arr[], int k)
    {
        for (int i = ((k) / 2); i >= 0; i--)
        {
            heapify(arr, i, k);
        }
    }
    void heapify(node *arr[], int i, int limit)
    {
        // bool twoip1;
        int latest = i;
        int latest1 = limit;
        int latest2 = limit;
        if (2 * i + 1 < limit && arr[2 * i + 1]->count < arr[i]->count)
        {
            latest1 = 2 * i + 1;
            latest = 2 * i + 1;
        }
        if (2 * i + 2 < limit && arr[2 * i + 2]->count < arr[i]->count)
        {
            latest2 = 2 * i + 2;
            latest = 2 * i + 2;
        }
        if (2 * i + 1 < limit && arr[2 * i + 1]->count == arr[i]->count)
        {
            if (arr[2 * i + 1]->s < arr[i]->s)
            {
                latest1 = 2 * i + 1;
                latest = 2 * i + 1;
            }
        }
        if (2 * i + 2 < limit && arr[2 * i + 2]->count == arr[i]->count)
        {
            if (arr[2 * i + 2]->s < arr[i]->s)
            {
                latest2 = 2 * i + 2;
                latest = 2 * i + 2;
            }
        }
        if (latest2 != limit && latest1 != limit)
        {
            if (arr[2 * i + 1]->count < arr[2 * i + 2]->count)
            {
                latest = 2 * i + 1;
            }
            else
                latest = 2 * i + 2;
        }

        if (i != latest)
        {
            swap(arr[i], arr[latest]);
            heapify(arr, latest, limit);
        }
    }

public:
    node *
    buildCBTandgetbackans(unordered_map<string, int> &z, int k)
    {
        size = z.size();
        int itr = 0;
        node *arr[size];
        for (auto i : z)
        {
            node *temp = new node(i.first, i.second);
            arr[itr] = temp;
            itr++;
        }
        node *heap[k];

        for (int i = 0; i < k; i++)
        {
            heap[i] = arr[i];
        }
        buildheap(heap, k - 1);
        int heaparitr = k;
        string arr2[size];
        int currentcount = -1;
        int cnt2 = 0;
        while (heaparitr < size)
        {
            if (heap[0]->count <= arr[heaparitr]->count)
            {
                if (heap[0]->count == arr[heaparitr]->count)
                {
                    arr2[cnt2] = arr[heaparitr]->s;
                    heaparitr++;
                    continue;
                }
                heap[0] = arr[heaparitr];
                heapify(heap, 0, k);
                if (heap[0]->count != currentcount)
                {
                    cnt2 = 0;
                }
            }
            heaparitr++;
        }
        // string arr1[size];
        // int cnt=0;
        // for(auto i:z)
        // {
        //     if(i.second==heap[0]->count)
        //     {
        //         arr1[cnt]=i.first;
        //         cnt++;
        //     }
        // }

        return heap[0];
    }
};
void solve()
{
    string s;
    getline(cin, s);
    int k;
    cin >> k;
    unordered_map<string, int> set;
    int preptr = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == s.size() - 1)
        {
            i = s.size();
        }
        if (s[i] == ' ' || i == s.size())
        {
            string temp = "";
            for (int j = preptr + 1; j < i; j++)
            {
                if ((s[j] >= (97) && s[j] <= (122)) || (s[j] >= (65) && s[j] <= (90)))
                    temp += s[j];
            }
            preptr = i;
            set[temp]++;
        }
    }
    heap ha;
    node *arr1[set.size()];
    node *arr2[set.size()];
    int count = 0;
    arr1[count] = ha.buildCBTandgetbackans(set, k);
    count++;
    int realk = k;
    int maxa = 0;
    int sum = k;
    int mini = 0;
    int setkamax = 0;
    for (auto i : set)
    {
        setkamax = max(setkamax, i.second);
    }
    arr2[k] = ha.buildCBTandgetbackans(set, k);

    while (k < set.size())
    {
        if (arr1[0]->count == ha.buildCBTandgetbackans(set, ++k)->count)
        {
            arr1[count] = ha.buildCBTandgetbackans(set, k);
            arr2[k] = ha.buildCBTandgetbackans(set, k);

            sum += k;
            count++;
            maxa++;
        }
        else
            break;
    }
    k = realk;
    // count=0;
    int newcount = 0;
    while (k > 0)
    {
        if (arr1[0]->count == ha.buildCBTandgetbackans(set, --k)->count)
        {
            arr1[count] = ha.buildCBTandgetbackans(set, k);
            arr2[realk - newcount - 1] = ha.buildCBTandgetbackans(set, k);

            sum += k;
            count++;
            newcount++;
            mini = newcount;
        }
        else
            break;
    }
    if (count == 1)
    {
        cout << arr1[0]->s << endl;
        return;
    }
    int mid = (realk - mini + realk + maxa) / (2);
    if (count % 2 == 1)
    {
        if (realk == mid)
        {
            cout << arr2[realk]->s << endl;
        }
        else if (realk > mid)
        {
            cout << arr2[mid - abs(realk - mid)]->s << endl;
        }
        else
            cout << arr2[mid + abs(realk - mid)]->s << endl;
    }
    else

    {
        if (realk == mid || realk==mid+1)
        {
            cout << arr2[realk]->s << endl;
        }
        else if (realk > mid)
        {
            cout << arr2[mid - abs(realk - mid)] << endl;
        }
        else
            cout << arr2[mid + abs(realk - mid)] << endl;
    }
    // int total=count;
    // int result;
    // bool aage;
    // if(sum/total ==realk)
    // {

    //     cout<<arr1[0]->s<<endl;
    // }
    // else if(sum/total >realk)
    // {
    //     result=(sum/total)-k;
    //     aage=false;
    //     cout<<arr1[total-(maxa-k)]->s<<endl;
    // }
    // else

    // {
    //     result=(sum/total)-k;
    //     aage=true;
    //     cout<<arr1[result]->s<<endl;

    // }
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
