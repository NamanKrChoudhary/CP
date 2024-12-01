#include<bits/stdc++.h>
using namespace std;

int largestElementLEQ(set<int>& s, int x) {
    auto it = s.upper_bound(x); 
    if (it == s.begin())        
        return -1;              
    --it;                       
    return *it;
}

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n,m;
        cin >> n >> m;
        vector<long long int> arr(n); 
        set<long long int> s;
        for(int i=0; i<n; i++) {cin >> arr[i]; s.insert(arr[i]);}
        long long int maxx = *max_element(arr.begin(), arr.end());
        long long int minn = *min_element(arr.begin(), arr.end());
        for(int j=0; j<m; j++)
        {
            char c;
            cin >> c;
            long long int l,r;
            cin >> l >> r;
            if(c == '+')
            {
                // if(r<minn) {cout << maxx << " "; continue;}
                // if(minn >=l && minn <= r) minn = minn + 1;
                // long long int temp = *s.lower_bound(r);
                // auto it = s.lower_bound(r);
                // if(temp == r) {s.erase(temp); s.insert(temp+1); maxx = max(maxx, (temp+1)); cout << maxx << " " ;continue;}
                // else {
                //     while(*it > r){ if(it == s.begin()) break; it--; }
                //     long long int h = *it;
                //     if(h >= l && h<= r)
                //     {
                //         s.erase(h); s.insert(h+1); 
                //         maxx = max(maxx, (h+1)); 
                //         cout << maxx << " "; continue;
                //     }
                //     else {cout << maxx << " inside"; continue;}
                // }
                if(maxx >= l && maxx <= r) maxx = maxx + 1;
                cout << maxx << " " ; continue;
            }
            else{
                // if(minn >=l && minn <= r) minn--;
                // if(r<minn) {cout << maxx << " "; continue;}
                // long long int temp = *s.lower_bound(r);
                // auto it = s.lower_bound(r);
                // if(temp == r) {s.erase(temp); s.insert(temp-1); maxx = max(maxx, (temp-1)); cout << maxx << " "; continue;}
                // else {
                //     while(*it > r) {if(it == s.begin()) break; it--; }
                //     long long int h = *it;
                //     s.erase(h); s.insert(h-1); 
                //     maxx = max(maxx, (h-1)); 
                //     cout << maxx << " "; continue;
                // }
                if(maxx >= l && maxx <= r) maxx = maxx-1;
                cout << maxx << " "; continue;
            }
        }
        cout << endl; 
    }
}