#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int t; cin >> t;
	while(t--)
	{
	    long long int h,w,a,b,x,y;
	    cin >> h >> w >> a >> b >> x >> y;
	    long long int l1 = (b-1), r1 = (w-b), l2 = (y-1), r2 = (w-y);
	    long long int u1 = (a-1), d1 = (h-a), u2 = (x-1), d2 = (h-x);
	    if(a>=x) {cout << "DRAW" << endl; continue;}
	    long long int diff1 = x-a-1;
	    long long int diff2 = abs(y-b)-1;
	    long long int dd = diff1/2;
	    if(y==b || diff2 == 0) {if(diff1%2 == 0) cout << "ALICE" << endl; else cout << "BOB" << endl; continue;}
	    if(diff1%2 == 0)
	    {
	        long long int tot = 0;
	        tot = tot + diff2;
	        if(l1>l2) tot = tot + l2;
	        else tot = tot + r2;
	        if(tot*2>(diff1)) {cout << "DRAW" << endl; continue;}
	        else {cout << "ALICE" << endl; continue;}
	    }
	    else
	    {
	        long long int tot = 0;
	        tot = tot + diff2;
	        if(l2>l1) tot = tot + l1;
	        else tot = tot + r1;
	        if(tot*2>(diff1)) {cout << "DRAW" << endl; continue;}
	        else {cout << "BOB" << endl; continue;}
	    }
	}
}
