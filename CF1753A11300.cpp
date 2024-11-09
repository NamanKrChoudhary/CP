#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n; cin >> n;
        vector<int> arr(n);
        long long int c1=0, cm1=0;
        for(int i=0; i<n; i++) 
        {
            cin >> arr[i];
            if(arr[i] == 1) c1 = c1 + 1;
            else cm1 = cm1 + 1;
        }
        if(n%2 == 1) {cout << -1 << endl; continue;}
        vector<int> pind1;
        vector<int> pindm1;
        for(int i=1; i<n; i++)
        {
            if(arr[i] == arr[i-1]) 
            {
                if(arr[i] == 1) pind1.push_back(i-1);
                else pindm1.push_back(i-1);
                i++;
            }
        }
        int diff = abs(cm1-c1);
        diff = diff/2;
        pind1.shrink_to_fit();
        pindm1.shrink_to_fit();
        if(cm1 > c1 && diff > pindm1.size()) {cout << -1 << endl; continue;}
        else if(c1 > cm1 && diff > pind1.size()) {cout << -1 << endl; continue;}
        int k = 0;
        cout << n-diff << endl;
        for(int i=0; i<n; i++)
        {
            if(diff > 0)
            {
                if(c1 > cm1 && i == pind1[k]) {cout << i+1 << " " << i+2 << endl; i = i+1; k = k+1; diff = diff-1;}
                else if(cm1 > c1 && i == pindm1[k]) {cout << i+1 << " " << i+2 << endl; i = i+1; k = k+1; diff = diff - 1;}
                else {cout << i+1 << " " << i+1 << endl; continue;}
            }
            else
            {
                cout << i+1 << " " << i+1 << endl;
            }
        }
    }
}