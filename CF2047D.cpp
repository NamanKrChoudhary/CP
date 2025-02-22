#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t;
	cin >> t;
	while(t--)
	{
	    long long int n;
	    cin >> n;
	    deque<long long int> arr(n);
	    map<long long int, long long int> mp;
	    multiset<long long int> s;
	    for(int i=0; i<n; i++){ cin >> arr[i]; mp[arr[i]]++; s.insert(arr[i]);}
        long long int minn = *s.begin();
        long long int minc = LONG_MAX;
	    multiset<long long int> ans;
	    for(int i=0; i<n; i++)
	    {
	        
	        if(arr[i] == *s.begin() && arr[i] <= minc)
	        {
	            ans.insert(*s.begin());
	            s.erase(s.begin());
	        }

	        else if(arr[i] > minc)
	        {
	            
	            auto it = s.find(arr[i]);
	            s.erase(it);
	            ans.insert(arr[i]+1);
	            minc = min(arr[i]+1, minc);
	            
	        }
	        else if(arr[i] > *s.begin())
	        {
	            ans.insert(arr[i]+1);
	            auto it = s.find(arr[i]);
	            s.erase(it);
	            minc = min(arr[i]+1, minc);
	        }
	    }
	    for(auto i: ans) cout << i << " ";
	    cout << endl;
	}
}
