#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class set
{
private:
    class node
    {
    public:
        T data;
        int heightl = 0;
        int heightr = 0;
        node *left = NULL;
        node *right = NULL;
        node *parent = NULL;
        bool rightchildofitsparent;
    };
    int height(node *roo)
    {
        return min(roo->heightl, roo->heightr);
    }
    int balanced(node *roo)
    {
        if (abs(roo->heightl - roo->heightr) <= 1)
            return 1;
        return 0;
    }
    int sizeoftree = -1;
    bool intialised = false;
    node *root = new (node);
    void BSTbalance() // Incomplete
    {
        node *rootnew;
        T arr[sizeoftree];
        inorder(rootnew, arr);
    }
    node *rightRotate(node *roo)
    {
        node *temp = roo->left;
        node *temp2 = temp->right;
        temp->right = roo;
        roo->left = temp2;

        if (roo->right != NULL && roo->left != NULL)
        {

            roo->heightl = 1 + max(height(roo->right), height(roo->left));
        }
        else if (roo->left == NULL && roo->right != NULL)
        {
            roo->heightl = 1 + height(roo->right);
        }
        else if (roo->right == NULL && roo->left != NULL)
            roo->heightl = 1 + height(roo->left);
        else
            roo->heightl = 0;

        if (temp->right != NULL && temp->left != NULL)
        {

            temp->heightl = 1 + max(height(temp->right), height(temp->left));
        }
        else if (temp->left == NULL && temp->right != NULL)
        {
            temp->heightl = 1 + height(temp->right);
        }
        else if (temp->right == NULL && temp->left != NULL)
            temp->heightl = 1 + height(temp->left);
        else
            temp->heightl = 0;

        roo->heightr = roo->heightl;
        temp->heightr = temp->heightl;
        return temp;
    }
    node *leftRotate(node *roo)
    {
        node *temp = roo->right;
        node *temp2 = temp->left;
        temp->left = roo;
        roo->right = temp2;
        if (roo->right != NULL && roo->left != NULL)
        {

            roo->heightl = 1 + max(height(roo->right), height(roo->left));
        }
        else if (roo->left == NULL && roo->right != NULL)
        {
            roo->heightl = 1 + height(roo->right);
        }
        else if (roo->right == NULL && roo->left != NULL)
            roo->heightl = 1 + height(roo->left);
        else
            roo->heightl = 0;
        if (temp->right != NULL && temp->left != NULL)
        {

            temp->heightl = 1 + max(height(temp->right), height(temp->left));
        }
        else if (temp->left == NULL && temp->right != NULL)
        {
            temp->heightl = 1 + height(temp->right);
        }
        else if (temp->right == NULL && temp->left != NULL)
            temp->heightl = 1 + height(temp->left);
        else
            temp->heightl = 0;
        roo->heightr = roo->heightl;
        temp->heightr = temp->heightl;
        return temp;
    }
    node *minval(node *roo)
    {
        node *ptr = roo;
        while (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        return ptr;
    }
    node *inordersuccesor(node *roo)
    {
        node *ptr = roo;
        if (ptr->right != NULL)
        {
            ptr = ptr->right;
            while (ptr->left != NULL)
            {
                ptr = ptr->left;
            }
            return ptr;
        }
        node *papa = roo->parent;
        while (papa != NULL && ptr != papa->left)
        {
            ptr = papa;
            papa = papa->parent;
        }
        return papa;
    }
    int predecessor(node *roo)
    {
        roo = roo->left;
        while (roo->right != NULL)
            roo = roo->right;
        return roo->data;
    }

public:
    node *getroot()
    {
        return root;
    }
    int size()
    {
        return sizeoftree + 1;
    }
    int empty()
    {
        if (sizeoftree == -1)
            return 1;
        return 0;
    }
    int check(T x)
    {
        node *ptr = root;
        while (true)
        {
            if (ptr->data == x)
            {
                return 1;
            }
            else if ((ptr->data) > (x))
            {
                if (ptr->left == NULL)
                    break;
                ptr = ptr->left;
            }
            else
            {
                if (ptr->right == NULL)
                    break;
                ptr = ptr->right;
            }
        }
        return 0;
    }
    int lower_bound(T x)
    {

        node *ptr = root;
        bool check = false;
        T mini = INT_MAX;
        while (ptr != NULL)
        {
            if (ptr->data == x)
            {
                return x;
            }
            else if ((ptr->data) > (x))
            {
                check = true;
                mini = min(mini, ptr->data);
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        if (check)
        {
            return mini;
        }
        else
            return -1;
    }
    int upper_bound(T x)
    {

        node *ptr = root;
        bool check = false;
        T mini = INT_MAX;
        while (ptr != NULL)
        {
            if (ptr->data == x)
            {
                ptr = ptr->right;
                continue;
            }
            if ((ptr->data) > (x))
            {
                check = true;
                mini = min(mini, ptr->data);
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        if (check)
        {
            return mini;
        }
        else
            return -1;
    }
    void insert(T x)
    {

        if (!intialised)
        {
            root->data = x;
            intialised = true;
            sizeoftree++;
            root->parent = NULL;
            root->rightchildofitsparent = false;
            return;
        }
        node *ptr = root;
        while (true)
        {
            if (ptr->data == x)
            {
                node *ptrnegativeheight = root;
                while (true)
                {

                    if (ptr->data == x)
                    {
                        break;
                    }
                    else if ((ptr->data) > (x))
                    {
                        if (ptr->left == NULL)
                            break;
                        ptr->heightl--;
                        ptr = ptr->left;
                    }

                    else
                    {
                        if (ptr->right == NULL)
                            break;
                        ptr->heightr--;
                        ptr = ptr->right;
                    }
                }
                return;
            }
            else if ((ptr->data) > (x))
            {
                if (ptr->left == NULL)
                    break;
                ptr->heightl++;
                ptr = ptr->left;
            }
            else
            {
                if (ptr->right == NULL)
                    break;
                ptr->heightr++;
                ptr = ptr->right;
            }
        }
        sizeoftree++;
        node *temp = new (node);
        temp->data = x;
        if (ptr->data > x)
        {
            ptr->left = temp;
            temp->rightchildofitsparent = false;
        }
        else
        {

            temp->rightchildofitsparent = true;
            ptr->right = temp;
        }
        temp->parent = ptr;
        // insert balancer node finder
        node *prevptrbal = root;
        bool previousptrbalcheck = true;
        node *ptrbal = root;
        bool unbalanced = false;
        bool lastchoicewasright;
        while (true)
        {
            if (!balanced(ptrbal))
            {
                unbalanced = true;
                break;
            }
            if (ptrbal->data == x)
            {
                return;
            }
            else if ((ptrbal->data) > (x))
            {
                if (ptrbal->left == NULL)
                    break;
                if (previousptrbalcheck)
                {
                    previousptrbalcheck = false;
                }
                else
                {
                    if (lastchoicewasright)
                        prevptrbal = prevptrbal->right;
                    else
                        prevptrbal = prevptrbal->left;
                }
                lastchoicewasright = 0;

                ptrbal = ptrbal->left;
            }
            else
            {
                if (ptrbal->right == NULL)
                    break;
                if (previousptrbalcheck)
                {
                    previousptrbalcheck = false;
                }
                else
                {
                    if (lastchoicewasright)
                        prevptrbal = prevptrbal->right;
                    else
                        prevptrbal = prevptrbal->left;
                }
                lastchoicewasright = 1;
                ptrbal = ptrbal->right;
            }
        }
        if (unbalanced && prevptrbal == root)
        {
            if (ptrbal->heightl > ptrbal->heightr)
            {
                if (ptrbal->left != NULL && ptrbal->left->left != NULL && x == ptrbal->left->left->data)
                {
                    root = rightRotate(ptrbal);
                }
                else if (ptrbal->left != NULL && ptrbal->left->right != NULL && x == ptrbal->left->right->data)
                {

                    root = rightRotate(leftRotate(ptrbal->left));
                }
            }
            else
            {
                if (ptrbal->right != NULL && ptrbal->right->right != NULL && x == ptrbal->right->right->data)
                {
                    root = leftRotate(ptrbal);
                }
                else if (ptrbal->right != NULL && ptrbal->right->left != NULL && x == ptrbal->right->left->data)
                {
                    root = leftRotate(rightRotate(ptrbal->right));
                }
            }
        }
        else if (unbalanced)
        {
            if (ptrbal->heightl > ptrbal->heightr)
            {
                if (ptrbal->left != NULL && ptrbal->left->left != NULL && x == ptrbal->left->left->data)
                {
                    if (lastchoicewasright)
                    {
                        prevptrbal->right = rightRotate(ptrbal);
                    }
                    else
                        prevptrbal->left = rightRotate(ptrbal);
                }
                else if (ptrbal->left != NULL && ptrbal->left->right != NULL && x == ptrbal->left->right->data)
                {
                    if (lastchoicewasright)
                    {
                        prevptrbal->right = rightRotate(leftRotate(ptrbal->left));
                    }
                    else
                        prevptrbal->left = rightRotate(leftRotate(ptrbal->left));
                }
            }
            else
            {
                if (ptrbal->right != NULL && ptrbal->right->right != NULL && x == ptrbal->right->right->data)
                {
                    if (lastchoicewasright)
                    {
                        prevptrbal->right = leftRotate(ptrbal);
                    }
                    else
                        prevptrbal->left = leftRotate(ptrbal);
                }
                else if (ptrbal->right != NULL && ptrbal->right->left != NULL && x == ptrbal->right->left->data)
                {
                    if (lastchoicewasright)
                    {
                        prevptrbal->right = leftRotate(rightRotate(ptrbal->right));
                    }
                    else
                        prevptrbal->left = leftRotate(rightRotate(ptrbal->right));
                }
            }
        }
    }
    node *del(node *roo, T key)
    {
        if (roo->left == NULL && roo->left == NULL)
        {
            return NULL;
        }
        else if ((roo->right != NULL && roo->left == NULL))
        {
            return roo->right;
        }
        else if ((roo->left != NULL && roo->right == NULL))
        {
            return roo->left;
        }
        else if (roo->left != NULL && roo->right != NULL)
        {
            node *realroo = roo;
            node *temp = inordersuccesor(roo);
            roo->data = temp->data;
            root.right = deleteNode(root->right, root->val);
        }
        else
        {
            root->val = predecessor(root);
            root->left = deleteNode(root->left, root->val);
        }
        return roo;
    }
    // else
    // {
    //     node *succParent = roo;
    //     node *succ = roo->right;
    //     while (succ->left != NULL)
    //     {
    //         succParent = succ;
    //         succ = succ->left;
    //     }
    //     if (succParent != roo)
    //         succParent->left = succ->right;
    //     else
    //         succParent->right = succ->right;
    //     roo->data = succ->data;
    //     delete succ;
    //     return roo;
    // }
    return NULL;
} node *del2(node *roo, int key)
{
    if (roo == NULL)
        return roo;
    else
    {
        if (roo->left == NULL and roo->right == NULL)
            return NULL;
        else if (roo->left == NULL)
        {
            node *temp = roo->right;
            free(roo);
            return temp;
        }
        else if (roo->right == NULL)
        {
            node *temp = roo->left;
            free(roo);
            return temp;
        }
        node *temp = minval(roo->right);
        roo->data = temp->data;
        roo->right = del2(roo->right, temp->data);
    }
    return root;
}
void erase(T x)
{ // make condition when erase==root
    node *prevptrerase = root;
    bool previousptrerasecheck = true;
    bool eraselastchoicewasright;
    if (!intialised)
    {
        return;
    }
    if (size() == 1)
    {
        if (root->data == x)
        {
            intialised = false;
        }
        return;
    }
    if (!check(x))
    {
        return;
    }
    node *ptr = root;
    while (true)
    {
        if (ptr->data == x)
        {
            if (eraselastchoicewasright)
            {
                prevptrerase->right = del(ptr, x);
            }
            else
                prevptrerase->left = del(ptr, x);

            sizeoftree--;
            break;
        }
        else if ((ptr->data) > (x))
        {
            if (ptr->left == NULL)
                return;
            if (previousptrerasecheck)
            {
                previousptrerasecheck = false;
            }
            else
            {
                if (eraselastchoicewasright)
                    prevptrerase = prevptrerase->right;
                else
                    prevptrerase = prevptrerase->left;
            }
            eraselastchoicewasright = 0;
            ptr->heightl--;
            ptr = ptr->left;
        }
        else
        {
            if (ptr->right == NULL)
                return;
            if (previousptrerasecheck)
            {
                previousptrerasecheck = false;
            }
            else
            {
                if (eraselastchoicewasright)
                    prevptrerase = prevptrerase->right;
                else
                    prevptrerase = prevptrerase->left;
            }
            eraselastchoicewasright = 1;
            ptr->heightr--;

            ptr = ptr->right;
        }
    }
    // erase balancer node finder
    node *prevptrbal = root;
    bool previousptrbalcheck = true;
    node *ptrbal = root;
    bool unbalanced = false;
    bool lastchoicewasright;

    while (true)
    {
        if (!balanced(ptrbal))
        {
            unbalanced = true;
            break;
        }
        if (ptrbal == NULL)
        {
            return;
        }
        else if ((ptrbal->data) > (x))
        {
            if (ptrbal->left == NULL)
                break;
            if (previousptrbalcheck)
            {
                previousptrbalcheck = false;
            }
            else
            {
                if (lastchoicewasright)
                    prevptrbal = prevptrbal->right;
                else
                    prevptrbal = prevptrbal->left;
            }
            lastchoicewasright = 0;

            ptrbal = ptrbal->left;
        }
        else
        {
            if (ptrbal->right == NULL)
                break;
            if (previousptrbalcheck)
            {
                previousptrbalcheck = false;
            }
            else
            {
                if (lastchoicewasright)
                    prevptrbal = prevptrbal->right;
                else
                    prevptrbal = prevptrbal->left;
            }
            lastchoicewasright = 1;
            ptrbal = ptrbal->right;
        }
    }
    if (unbalanced && ptrbal == root)
    {
        if (ptrbal->heightl > ptrbal->heightr)
        {
            if (ptrbal->left != NULL && ptrbal->left->left != NULL && x == ptrbal->left->left->data)
            {
                if (lastchoicewasright)
                {
                    root = rightRotate(ptrbal);
                }
                else
                    root = rightRotate(ptrbal);
            }
            else if (ptrbal->left != NULL && ptrbal->left->right != NULL && x == ptrbal->left->right->data)
            {
                if (lastchoicewasright)
                {
                    root = rightRotate(leftRotate(ptrbal->left));
                }
                else
                    root = rightRotate(leftRotate(ptrbal->left));
            }
        }
        else
        {
            if (ptrbal->right != NULL && ptrbal->right->right != NULL && x == ptrbal->right->right->data)
            {
                if (lastchoicewasright)
                {
                    root = leftRotate(ptrbal);
                }
                else
                    root = leftRotate(ptrbal);
            }
            else if (ptrbal->right != NULL && ptrbal->right->left != NULL && x == ptrbal->right->left->data)
            {
                if (lastchoicewasright)
                {
                    root = leftRotate(rightRotate(ptrbal->right));
                }
                else
                    root = leftRotate(rightRotate(ptrbal->right));
            }
        }
    }

    else if (unbalanced)
    {
        if (ptrbal->heightl > ptrbal->heightr)
        {
            if (ptrbal->left != NULL && ptrbal->left->left != NULL && x == ptrbal->left->left->data)
            {
                if (lastchoicewasright)
                {
                    prevptrbal->right = rightRotate(ptrbal);
                }
                else
                    prevptrbal->left = rightRotate(ptrbal);
            }
            else if (ptrbal->left != NULL && ptrbal->left->right != NULL && x == ptrbal->left->right->data)
            {
                if (lastchoicewasright)
                {
                    prevptrbal->right = rightRotate(leftRotate(ptrbal->left));
                }
                else
                    prevptrbal->left = rightRotate(leftRotate(ptrbal->left));
            }
        }
        else
        {
            if (ptrbal->right != NULL && ptrbal->right->right != NULL && x == ptrbal->right->right->data)
            {
                if (lastchoicewasright)
                {
                    prevptrbal->right = leftRotate(ptrbal);
                }
                else
                    prevptrbal->left = leftRotate(ptrbal);
            }
            else if (ptrbal->right != NULL && ptrbal->right->left != NULL && x == ptrbal->right->left->data)
            {
                if (lastchoicewasright)
                {
                    prevptrbal->right = leftRotate(rightRotate(ptrbal->right));
                }
                else
                    prevptrbal->left = leftRotate(rightRotate(ptrbal->right));
            }
        }
    }
}
}
;
void solve()
{
    // Next Successor Code is wrong in this implementation
    set<int> se;
    long long int sum = 0;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {

        cin >> s;
        switch (int(s[0]) - int('0'))
        {
        case 1:
        {
            string extra;
            cin >> extra;
            int t = stoi(extra);
            se.insert(t);
        }
        break;
        case 2:
        {
            string extra;
            cin >> extra;
            int t = stoi(extra);
            se.erase(t);
        }
        break;
        case 3:
            sum += se.size();
            break;
        case 4:
            sum += se.empty();
            break;
        case 5:
        {
            string extra;
            cin >> extra;
            int t = stoi(extra);
            sum += se.lower_bound(t);
            // if (se.lower_bound(t) != se.Ceil(se.getroot(), t))
            // {
            //     cout << "line is:" << i << " and extra:" << extra << " my code:" << se.lower_bound(t) << " vs other:" << se.Ceil(se.getroot(), t) << endl;
            //     return;
            // }
        }
        break;
        case 6:
        {
            string extra;
            cin >> extra;
            int t = stoi(extra);
            sum += se.upper_bound(t);
            //  if (se.upper_bound(t) != se.Floor(se.getroot(), t))
            // {
            //     cout << "upper bound -- " <<"line is:" << i << " and extra:" << extra << " my code:" << se.upper_bound(t) << " vs other:" << se.Floor(se.getroot(), t) << endl;
            //     return;
            // }
        }
        break;
        case 7:
        {
            string extra;
            cin >> extra;
            int t = stoi(extra);
            sum += se.check(t);
        }
        break;
        default:
            break;
        }
    }
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; // INPUT TEST CASES
    while (t--)
        solve();

    return 0;
}
