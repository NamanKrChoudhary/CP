#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	string s;
	cin >> s;
	vector<int> alpha(26,0);
	for(int i=0; i<s.size(); i++) alpha[s[i]-'a']++;
	vector<char> tochange;
	for(int i=0; i<26; i++) if(alpha[i]%2 == 1) tochange.push_back('a'+i);
	sort(tochange.begin(), tochange.end());
	int st=0, e=tochange.size()-1;
	while(st<e)
	{
	    alpha[tochange[st]-'a']++;
	    alpha[tochange[e]-'a']--;
	    st++; e--;
	}
	vector<char> ans;
	for(int i=0; i<26; i++) 
	{
	    int a = alpha[i]/2;
	    while(a--) ans.push_back('a'+i);
	}
	for(int i=0; i<ans.size(); i++) cout << ans[i];
	if(s.size()%2 == 1) cout << tochange[(tochange.size()/2)];
	for(int i=ans.size()-1; i>=0; i--) cout << ans[i];
	cout << endl;
}