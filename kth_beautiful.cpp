/* 

For the given integer n (n>2) let's write down all the strings of length n which
contain n−2 letters 'a' and two letters 'b' in lexicographical (alphabetical) order.

*/

#define _CRT_SECURE_NO_WARNINGS

#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

#define N 5010

using namespace std;


string generate_permutation(int n, int k){

	string a="a";
	string b="b";
	string c="";

	// this loop generates the 1st string that satisfies 
	// the conditon n-2 letters 'a' and 1 letter 'b'

	//int num_permutations=(n*(n-1))/2

	for(int i=0;i<n;i++){

		if(i<n-2){
			c+=a;
		}

		else{
			c+=b;
		}
	}

	return c;

}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_test_cases;

	vector<string> vec;

	cin>>num_test_cases;

	for(int i=0;i<num_test_cases;i++){

		int n,k;  // 3<=n<=10^5  and 1<=k<=min(2,10^9,n*(n-1)/2)

		cin>>n>>k;

		string result=generate_permutation(n,k);

		vec.push_back(result); // store in vector

	}

	for (string s : vec){
		cout<<s<<"\n";
	}

	return 0;
}