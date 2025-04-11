#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    long long int a = k/2, b=k/2;
    if(k%2 == 1) a = a+1;
    set<pair<long long int, long long int>> s1, s2;
    if(k == 1)
    {
        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
        return 0;
    }
    vector<long long int> ans;
    for(int i=0; i<n; i++)
    {
        if(i<k)
        {
            pair<long long int, long long int> p = {arr[i],i};
            s1.insert(p);
        }
        if(i == k-1)
        {
            while(s1.size() > a)
            {
                auto ite = s1.end();
                ite--;
                pair<long long int, long long int> p = *ite;
                s1.erase(p); s2.insert(p);
            }
            auto ite = s1.end(); ite--;
            ans.push_back((*ite).first);
        }
        if(i>=k)
        {
            pair<long long int, long long int> p = {arr[i],i};
            s1.insert(p);
            p = {arr[i-k],(i-k)};
            if(s1.find(p) != s1.end()) s1.erase(p);
            else if(s2.find(p) != s2.end()) s2.erase(p);
            while(s1.size() > a)
            {
                auto ite = s1.end();
                ite--;
                pair<long long int, long long int> p = *ite;
                s1.erase(p); s2.insert(p);
            }
            while((*(--s1.end())).first > (*s2.begin()).first)
            {
                pair<long long int, long long int> p1 = (*(--s1.end()));
                pair<long long int, long long int> p2 = (*s2.begin());
                s1.erase(p1); s2.insert(p1);
                s1.insert(p2); s2.erase(p2);
            }
            auto ite = s1.end(); ite--;
            ans.push_back((*ite).first);
        }
    }
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}