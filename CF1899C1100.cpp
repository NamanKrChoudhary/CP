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
        vector<long long int> par;
        bool check = false;
        if(n == 1) {cout << arr[0] << endl; continue;}
        if(abs(0+arr[1]%2) == abs(0+arr[0]%2)) check = true;
        else {par.push_back(0);}
        for(int i=1; i<n; i++)
        {
            if(check && (abs(0+arr[i]%2) != abs(0+arr[i-1]%2))) {check = false; par.push_back(i-1);}
            else if(check && (abs(0+arr[i]%2) == abs(0+arr[i-1]%2))) continue;
            else if(check == false && (abs(0+arr[i]%2) != abs(0+arr[i-1]%2))) continue;
            else if(check == false && (abs(0+arr[i]%2)== abs(0+arr[i-1]%2))) {check = true; par.push_back(i-1);}
        }
        if(check == false) par.push_back(n-1);
        vector<long long int> pre(n); long long int count = 0;
        for(int i=0; i<n; i++)
        {
            count = count + arr[i];
            pre[i] = count;
        }
        if(par.empty()) {cout << *max_element(arr.begin(), arr.end()) << endl; continue;}
        long long int maxx = *max_element(arr.begin(), arr.end());
        for(int i=1; i<par.size(); i = i+2) 
        {
            long long int m = arr[par[i-1]];
            long long int temp = 0;
            for(int j=par[i-1]; j<= par[i]; j++)
            {
                temp = temp + arr[j];
                maxx = max(maxx, temp);
                if(temp < arr[j]) temp = arr[j];
                maxx = max(maxx, temp);
            }
        }
        cout << maxx << endl;
    }
}