#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m,n;
    cin >> n >> m;
    vector<long long int> arr(n), brr(m);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<m; i++) cin >> brr[i];
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    vector<pair<long long int,long long int>> tarr; 
    for(int i=0; i<n; i++) 
    {
        pair<long long int, long long int> p;
        p.first = arr[i];
        p.second = 2;
        tarr.push_back(p);
    }
    for(int i=0; i<m; i++) 
    {
        pair<long long int, long long int> p;
        p.first = brr[i];
        p.second = 1;
        tarr.push_back(p);
    }
    sort(tarr.begin(), tarr.end());
    vector<pair<long long int, long long int>> rad(n);
    long long int prev = LONG_MIN;
    for(int i=0,j=0; i<tarr.size() && j<n; i++)
    {
        if(tarr[i].second == 1) prev = tarr[i].first;
        else {rad[j].first = prev; j++;}
    }
    prev = LONG_MAX;
    for(int i=tarr.size()-1, j=n-1; i>=0, j>=0; i--)
    {
        if(tarr[i].second == 1) prev = tarr[i].first;
        else {rad[j].second = prev; j--;}
    }
    long long int ans = 0;
    for(int i = 0; i<n; i++)
    {
        long long int a = LONG_MAX, b = LONG_MAX;
        if(rad[i].first != LONG_MIN) {a = arr[i]-rad[i].first;}
        if(rad[i].second != LONG_MAX) {b = rad[i].second - arr[i];}
        ans = max(ans, min(a, b));
    }
    cout << ans << endl;
}