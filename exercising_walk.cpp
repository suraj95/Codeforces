/*

	Position of Alice is (x,y). And the cat can talk a steps left, b steps right, c steps down, 
	d steps up. So afte the walk of a+b+c+d unit moves, Alice hopes that her cat is always in the 
	area [x1,x2]×[y1,y2], i.e. for every cat's position (u,v) of a walk x1≤u≤x2 and y1≤v≤y2 holds.

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

using namespace std;

struct position
{
	int x,y;

	position() {}
	position(long long int x, long long int y) {
		this->x = x;
		this->y = y;
	}
};

struct moves
{
	long long int a,b,c,d;

	moves() {}
	moves(long long int a, long long int b, long long int c, long long int d) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
};


bool check_moves(position start, position upper_limit, position lower_limit, moves mv){

	unsigned long long int total_moves=mv.a+mv.b+mv.c+mv.d;

	unsigned long long int length=(upper_limit.x-start.x)+(start.x-lower_limit.x);
	unsigned long long int breadth=(upper_limit.y-start.y)+(start.y-lower_limit.y);

	unsigned long long int perimeter=length+breadth;
	unsigned long long int area=length*breadth;

	if(length==0 || breadth==0){

		//check if the moves are less than perimeter of rectangle if 2D
		if(total_moves<=perimeter){
			return true;
		}
		else{
			return false;
		}
	}

	else{

		// check if the moves are less than area of rectangle if 3D
		if(total_moves<=area){
			return true;
		}

		else{
			return false;
		}
	}

}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	unsigned short int num_test_cases;
	cin>>num_test_cases;

	for(unsigned short int i=0; i<num_test_cases; i++){
		long long int a, b, c, d;
		long long int x, y, x1, y1, x2, y2;

		cin>>a>>b>>c>>d;
		cin>>x>>y>>x1>>y1>>x2>>y2;

		position start(x,y);
		position upper_limit(x2,y2);
		position lower_limit(x1,y1);
		moves mv(a,b,c,d);

		if(check_moves(start,upper_limit,lower_limit, mv)){
			cout<<"Yes"<<"\n";
		}
		else{
			cout<<"No"<<"\n";
		}

	}

	return 0;
}

