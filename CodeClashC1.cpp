#include<bits/stdc++.h>
using namespace std;
long long int caller(vector<long long int>& arr, long long int i, long long int curror, long long int chno, long long int xx)
{
    if(i == arr.size())
    {
        if(chno%2 == 1) return 0;
        else return curror;
    }
    long long int c1 = caller(arr, i+1, curror|(arr[i] ^ xx), chno+1, xx);
    long long int c2 = caller(arr, i+1, curror|arr[i], chno, xx);
    return max(c1, c2);
}
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    long long int xx = pow(2,15)-1;
    if(n >= 15) cout << xx << endl;
    else {cout << caller(arr, 0, 0, 0, xx) << endl; return 0;}
}
