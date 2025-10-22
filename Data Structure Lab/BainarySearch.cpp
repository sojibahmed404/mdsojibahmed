#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int tar)
{
    int st = 0, end = n - 1;
    int count = 0;
    while (st <= end)
    {
        count++;
        int mid = (st + end) / 2;
        if (tar < arr[mid])
        {
            end = mid - 1;
        }
        else if (tar > arr[mid])
        {
            st = mid + 1;
        }
        else if (tar == arr[mid])
        {
            return count;
        }

    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int tar;
    cin >> tar;
    int res = search(a, n, tar);
    cout << res << endl;
    return 0;
}
