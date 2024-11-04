#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int t;
	cin >> t;
	while(t--)
	{
	    long long int n;
	    cin >> n;
	    vector<long long int> arr(n);
	    vector<long long int> eve;
	    vector<long long int> odd;
	    for(int i=0; i<n; i++)
	    {
	        cin >> arr[i];
	        if(i%2 == 0) eve.push_back(arr[i]);
	        else odd.push_back(arr[i]);
	    }
	    sort(eve.rbegin(), eve.rend()); sort(odd.rbegin(), odd.rend());
	    long long int sum = 0;
	    long long int maxx = LONG_MIN;
	    int ind=0;
	    while(ind < eve.size())
	    {
	        sum = sum + eve[ind];
	        maxx = max(maxx, sum); 
	        ind++;
	    }
	    ind = 0;
	    sum = 0;
	    while(ind < odd.size())
	    {
	        sum = sum + odd[ind];
	        maxx = max(maxx, sum);
	        ind++;
	    }
	    // vector<pair<long long int, long long int>> prepos(n);
	    // long long int e =0, o = 0;
	    // for(int i=0; i<arr.size(); i++)
	    // {
	    //     if(i%2==0) {e = e + arr[i]; prepos[i].first = e;}
	    //     else {o = o + arr[i]; prepos[i].first = o;}
	    // }
	    // e=0;o=0;
	    // for(int i=n-1; i>=0; i--)
	    // {
	    //     if(i%2==0) {e = e + arr[i]; prepos[i].second = e;}
	    //     else {o = o + arr[i]; prepos[i].second = o;}
	    // }
	    if(n == 1) {cout << arr[0] << endl; continue;}
	    // for(int i=1; i<n; i++)
	    // {
	    //     maxx = max(maxx, max(prepos[i-1].first, prepos[i].second));
	    // }
	    cout << maxx << endl;
	}
}
