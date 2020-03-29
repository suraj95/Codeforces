/* A Ternary XOR operation is defined as as a number c=a⊙b of length n, where ci=(ai+bi)%3.  
For example, 10222⊙11021=21210.

So for a given x, our task is to find such ternary numbers a and b both of length n and both without 
leading zeros that a⊙b=x and max(a,b) is the minimum possible.
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


// a is the larger number
struct numbers_pair
{
	int a, b;
	numbers_pair() {}
	numbers_pair(int a, int b) {
		this->a = a;
		this->b = b;
	}
};


void split_digits(int num, int digits, int* ptr){

	int units, divider;
	
	divider=1;
	for(int i=digits-1;i>=0;i--){

		units=(num/divider)%10;
		ptr[i]=units;

		divider=divider*10;
	}
}

int create_number(int digits, int *ptr){

	int sum=0, multiplier=1;

	for(int i=digits-1;i>=0;i--){

		sum=sum+(ptr[i]*multiplier);

		multiplier=multiplier*10;
	}

	return sum;
}


numbers_pair generate_a_b(int digits, int* p, int* a, int* b){

	int x,y;
	numbers_pair result;

	for(int j=0; j<digits; j++){

			// digits will be {0,0}
			if(p[j]==0){
				a[j]=0;
				b[j]=0;
			}

			// digits will be {2,0} or {1,1}
			else if(p[j]==2){

				// assuming {1,1} for time being
				a[j]=1;
				b[j]=1;
			}

			// digits will be {1,0}
			else if(p[j]==1)
			{
				a[j]=1;
				b[j]=0;
			}

			// cout<<p[j]<<"\n";
		}

		x=create_number(digits,a);
		y=create_number(digits,b);

		result=numbers_pair(x,y);

		return result;
}

int main(){

	int num_test_cases;
	cin>>num_test_cases;

	for(int i =0; i<num_test_cases; i++){

		int digits, x;

		// create pointer to an integer
		int* p; 
		int* a;
		int* b;

		numbers_pair N_pair;

		cin>>digits>>x;

		// allocate memory for an array of integers

		p=new int[digits];
		a=new int[digits];
		b=new int[digits];


		split_digits(x,digits,p);

		N_pair = generate_a_b(digits,p,a,b);

		cout<<N_pair.a<<"\n"<<N_pair.b<<"\n";

		delete[] p;
		delete[] a;
		delete[] b;
	}

	return 0;
}
