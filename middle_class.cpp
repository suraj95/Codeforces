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

using namespace std;

int generate_max_wealthy(std::vector<double> savings, int min_wealth){

	// we have to use a greedy algorithm

	// sort by decreasing order of wealth and select the most wealthiest subset possible
	// that will generate the most possible wealth which can then be divided equally

    sort(savings.begin(), savings.end(), greater<int>());

 //    for (int n : savings){
	// 	cout<<n<<"\n";
	// }

    int result=0; // initialize
    int total_wealth;
    double average_wealth;

    for(int i=0; i<savings.size(); i++){

    	total_wealth=0;
    	average_wealth=0;

    	for(int j=0; j<=i; j++){
    		total_wealth+=savings[j];
    	}

    	int num_people=i+1;
    	average_wealth=total_wealth/num_people;

    	//cout<<average_wealth<<"\n";

    	if(average_wealth<min_wealth){

    		return result; // this is breaking point and returns earlier result
    	}

    	// update result
    	result++;

    }

    return result;

}

int main(){

	int num_test_cases;
	cin>>num_test_cases;

	for(int i=0; i<num_test_cases; i++){

		int n, x; // the number of people and the minimum amount of money to be considered as wealthy
		cin>>n>>x; 

		int max_wealthy=0;
		std::vector<double> savings_vec;

		for(int j=0; j<n; j++){

			int saving;
			cin>>saving;

			savings_vec.push_back(saving);
		}

		max_wealthy=generate_max_wealthy(savings_vec,x);
		cout<<max_wealthy<<"\n";

	}
	return 0;
}	
