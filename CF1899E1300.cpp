#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int mini = min_element(arr.begin(), arr.end()) - arr.begin();
        if(mini == n-1) {cout << n-1 << endl; continue;}
        bool check = true;
        for(int i=mini+1; i<n; i++)
        {
            if(arr[i] < arr[i-1]) {check = false; break;}
        }
        if(check) {cout << mini << endl; continue;}
        else cout << -1 << endl;
    }
}