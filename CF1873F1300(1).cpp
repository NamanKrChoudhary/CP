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
        if(*min_element(arr.begin(), arr.end()) > k) maxx = 0;
        else maxx = 1;
        if(p.size()%2 == 1) p.push_back(n-1);
        if(p.size() == 0) {cout << maxx << endl; continue;}
        for(int i=0; i<p.size(); i = i+2)
        {
            int st = p[i]; int now = st+1;
            while(now <= p[i+1])
            {
                if(arr[now] == k) {maxx = max(maxx,o); st = now+1; now = st;}
                else if(arr[now] > k) {st = now+1; now = st+1;}
                else
                {
                    if(fruits[now] - fruits[st] + arr[st] == k) {long long int t = now-st+1; maxx = max(maxx, t);if(now == st) now = now+1; st = st+1;}
                    else if(fruits[now]-fruits[st]+arr[st] > k) {if(now == st) now = now+1; st = st+1;}
                    else
                    {
                        long long int t = now-st+1;
                        maxx = max(maxx, t);
                        now = now + 1;
                    }
                }
            }
        }
        cout << maxx << endl;
    }
}