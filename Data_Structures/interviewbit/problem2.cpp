
#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007


bool isPrime(string s)
{
	int num = stoi(s); // to string to number.
	for (int i = 2; i * i <= num; i++)
		if ((num % i) == 0)
			return false;
	return num > 1 ? true : false;
}


int countPrime(string& s, int n){
	if (n == 0)
		return 1;
	int ans = 0; 
	for (int i = 1; i <= 3; i++) {
		if (n - i >= 0 && s[n - i] != '0' && isPrime(s.substr(n - i, i))) {
			ans += countPrime(s,n - i);
            ans %= MOD;
		}
	}

	return ans;
}

int main()
{
    fast
	string s;
    cin>>s;
	int n = s.length();
	cout << countPrime(s, n) << "\n";
	return 0;
}
