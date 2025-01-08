#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n,k;
        cin >> n >> k;
        vector<long long int> a(n), b(n);
        long long int count = 0;
        long long int in = 0;
        for(int i=0; i<n; i++)
        {
            cin >> in;
            count = count + in;
            a[i] = count;
        }
        count = 0;
        for(int i=0; i<n; i++)
        {
            cin >> in;
            count = max(in, count);
            b[i] = count;
        }
        vector<long long int> ans(n);
        for(int i=0; i<n && i<k; i++)
        {
            long long int temp = a[i] + ((k-(i+1))*b[i]);
            ans[i] = temp;
        }
        cout << *max_element(ans.begin(), ans.end()) << endl;
    }
}