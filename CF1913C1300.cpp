#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int n;
	vector<int> arr(30,0);
	cin >> n;
	while(n--)
	{
	    long long int a,b;
	    cin >> a >> b;
	    if(a == 1) {arr[b]++; continue;}
	    long long int sum = 0;
	    long long int get = b;
	    bool check = true;
	    for(int i=0; i<30; i++)
	    {
	        if(get <= 0) break;
	        sum = sum + ((pow(2,i))*arr[i]);
	        long long int req = (get%2)*pow(2,i);
	        if(sum < req) {check = false; break;}
	        else
	        {
	            sum = sum - req;
	            get = get/2;
	            continue;
	        }
	    }
	    if(check) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
}
