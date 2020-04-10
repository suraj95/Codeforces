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


struct GamePair
{
	int plays, clears;
	GamePair() {}
	GamePair(int p, int c) {
		this->plays = p;
		this->clears = c;
	}
};


bool validate_games(std::vector<GamePair> games){

	auto it=games.begin();

	// initialize previous stats
	int previous_plays=it->plays;;
	int previous_clears=it->clears;

	for(;it!=games.end(); it++){

		// number of clears cannot be more than number of plays
		if(it->clears>it->plays){
			return false;
		}

		// number of plays or number of clears cannot decrease
		if(it->plays<previous_plays || it->clears<previous_clears){
			return false;
		}

		// update previous
		previous_plays=it->plays;
		previous_clears=it->clears;

	}

	return true;
}

int main(){

	int num_test_cases;
	cin>>num_test_cases;

	for(int i=0; i<num_test_cases; i++){

		int n;
		bool result;

		cin>>n; // number of peeks

		std::vector<GamePair> games_vec;

		for(int j=0; j<n; j++){

			int p, c;
			cin>>p>>c;  // the number of plays and the number of clears of the level 
						// at the i-th moment of time.

			GamePair GP(p,c);
			games_vec.push_back(GP);
		}

		result=validate_games(games_vec);

		if(result){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}

	return 0;
}
