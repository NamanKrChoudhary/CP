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
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        if(temp == arr) {cout << 0 << endl; continue;}
        set<int> z,o,t;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0) z.insert(i);
            else if(arr[i] == 1) o.insert(i);
            else t.insert(i);
        }
        vector<int> last(n);
        vector<int> ans;
        for(int i=0; i<z.size(); i++)
        {
            if(arr[i] == 0) continue;
            if(arr[i] == 1)
            {
                auto it = z.end();
                it--; int l = *it;
                o.erase(i); o.insert(l);
                z.erase(l); z.insert(i);
                ans.push_back(i); ans.push_back(l);
                arr[i] = 0;
                arr[l] = 1;
            }
            else
            {
                auto it = z.end();
                auto it1= o.end();
                it--; it1--;
                int l = *it; int ll = *it1;
                arr[i] = 0; arr[l] = 1; arr[ll] = 2;
                ans.push_back(i); ans.push_back(ll);
                ans.push_back(i); ans.push_back(l);
                t.erase(i); t.insert(ll);
                o.erase(ll); o.insert(l);
                z.erase(l); z.insert(i);
            }
        }
        for(int i=z.size(); i<z.size()+o.size(); i++)
        {
            if(arr[i] == 1) continue;
            else
            {
                auto it = o.end();
                it--; int l = *it;
                ans.push_back(i); ans.push_back(l);
                o.erase(l); o.insert(i);
                t.erase(i); t.insert(l);
                arr[i] = 1; arr[l] = 2;
            }
        }
        cout << ans.size()/2 << endl;
        for(int i=0; i<ans.size(); i++)
        {
            cout << ans[i]+1 << " ";
            if(i%2 ==1) cout << endl;
        }
    
    }
}