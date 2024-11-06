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
        map<long long int, long long int> mp;
        bool check = true;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
            if(mp[arr[i]] > 2) {check = false;}
        }
        if(check == false || (mp.find(1) != mp.end() && mp[1] > 1)) {cout << "NO" << endl; continue; }
        vector<long long int> doubles;
        vector<long long int> missing;
        for(int i=1; i<=n; i++)
        {
            if(mp.find(i) == mp.end()) {missing.push_back(i);}
            else if(mp[i] == 2) {doubles.push_back(i);}
        }
        missing.shrink_to_fit();
        doubles.shrink_to_fit();
        if(missing.size() != doubles.size()) {cout << "NO" << endl; continue;}
        map<long long int, bool> checker;
        map<long long int, long long int> putter;
        check = true;
        for(int i=0; i<missing.size(); i++)
        {
            if(missing[i] > doubles[i]) {check = false; break;}
            checker[doubles[i]] = false;
            putter[doubles[i]] = missing[i];
        }
        if(check == false) {cout << "NO" << endl; continue;}
        vector<long long int> p(n), q(n);
        check = true;
        for(int i=0; i<n; i++)
        {
            if(mp[arr[i]] == 1) {p[i] = arr[i]; q[i] = arr[i];}
            else if(mp[arr[i]] == 2)
            {
                if(checker[arr[i]]) {p[i] = putter[arr[i]]; q[i] = arr[i];}
                else {checker[arr[i]] = true; p[i] = arr[i]; q[i] = putter[arr[i]];}
            }
            else check = false;
        }
        if(check == false) {cout << "NO" << endl; continue;}
        cout << "YES" << endl;
        for(int i=0; i<n; i++) cout << p[i] << " ";
        cout << endl;
        for(int i=0; i<n; i++) cout << q[i] << " ";
        cout << endl;
    }
}