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
        vector<long long int> fruits(n);
        vector<long long int> height(n);
        long long int sum = 0;
        long long int a;
        long long int maxx = LONG_MIN;
        vector<long long int> arr(n);
        for(int i=0; i<n; i++) {cin >> arr[i]; fruits[i] = arr[i]; fruits[i] = sum + fruits[i]; sum = fruits[i];}
        for(int i=0; i<n; i++) {cin >> height[i];}
        if(n == 1) {if(fruits[0] > k) cout << 0 << endl; else cout << 1 << endl; continue;}
        bool check = false;
        vector<int> p;
        int last = -1;
        for(int i=1; i<n; i++)
        {
            if(check)
            {
                if(height[i-1]%height[i] == 0) last = i;
                else {p.push_back(last); check = false;}
            }
            else
            {
                if(height[i-1]%height[i] == 0) {p.push_back(i-1); last = i; check = true;}
            }
        }
        long long int o = 1;
        if(*min_element(arr.begin(), arr.end()) > k) {maxx = 0; cout << maxx << endl; continue;}
        else maxx = 1;
        if(p.size()%2 == 1) p.push_back(n-1);
        p.shrink_to_fit();
        if(p.size() == 0) {cout << maxx << endl; continue;}
        for(int i=0; i<p.size(); i = i+2)
        {
            for(int j=p[i]; j<=p[i+1]; j++)
            {
                int st = p[i]; int end = p[i+1]; int mid = (st+end)/2;
                while(st <= end)
                {
                    mid = (st+end)/2;
                    if(fruits[mid]-fruits[j]+arr[j] > k) {end = mid-1; continue;}
                    else {long long int q = mid-j+1; maxx = max(maxx, q); st = mid+1; }
                }
            }
        }
        cout << maxx << endl;
    }
}