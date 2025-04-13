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
        vector<pair<long long int, long long int>> arr(n);
        map<pair<long long int, long long int>, long long int> mp;
        vector<vector<int>> adj(n+1);
        for(int i=1; i<n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
            mp[arr[i]] = i;
            adj[arr[i].first].push_back(arr[i].second);
            adj[arr[i].second].push_back(arr[i].first);
        }
        vector<bool> vis(n+1);
        queue<vector<long long int>> q;
        // currel, indelappears, currelcount;
        q.push({1,-1,1});
        long long int maxx = 1;
        vis[1] = true;
        while(!q.empty())
        {
            vector<long long int> curr = q.front();
            q.pop();
            for(int i=0; i<adj[curr[0]].size(); i++)
            {
                if(!vis[adj[curr[0]][i]])
                {
                    vector<long long int> temp(3);
                    int ind;
                    if(mp.find({curr[0], adj[curr[0]][i]}) != mp.end()) ind = mp[{curr[0], adj[curr[0]][i]}];
                    else ind = mp[{adj[curr[0]][i], curr[0]}];
                    temp[0] = adj[curr[0]][i];
                    temp[1] = ind;
                    if(ind > curr[1]) temp[2] = curr[2];
                    else temp[2] = curr[2]+1;
                    maxx = max(maxx, temp[2]);
                    q.push(temp);
                    vis[temp[0]] = true;
                }
            }
        }
        cout << maxx << endl;
    }
}