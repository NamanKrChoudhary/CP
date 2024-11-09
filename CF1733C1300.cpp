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
        if(n == 1) {cout << 0 << endl; continue;}
        bool check = true;
        for(int i=1; i<n; i++) if(arr[i-1] > arr[i]) check = false;
        if(check) {cout << 0 << endl; continue;}
        vector<long long int> ans;
        if(arr[0]%2 != arr[arr.size()-1]%2) {ans.push_back(0); ans.push_back(n-1); arr[n-1] = arr[0];}
        for(int i=0; i<n; i++)
        {
            if(arr[i]%2 == arr[n-1]%2 && arr[i] != arr[n-1])
            {
                ans.push_back(i); ans.push_back(n-1); arr[i] = arr[n-1];
            }
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]%2 != arr[0]%2 && arr[i] != arr[0])
            {
                ans.push_back(0); ans.push_back(i); arr[i] = arr[0];
            }
        }
        cout << ans.size()/2 << endl;
        for(int i=0; i<ans.size(); i = i+2) cout << ans[i]+1 << " " << ans[i+1]+1 << endl; 
    }
}