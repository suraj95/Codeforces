
/*

The round carousel consists of n figures of animals. Figures are numbered from 1 to n in order of the 
carousel moving. Thus, after the n-th figure the figure with the number 1 follows. Each figure has 
its own type — the type of the animal corresponding to this figure (the horse, the tiger and so on). 
The type of animal of the i-th figure equals ti.

Our task is to color the figures in such a way that the number of distinct colors used is the minimum 
possible and there are no figures of the different types going one right after another and colored in 
the same color. If you use exactly k distinct colors, then the colors of figures should be denoted with 
integers from 1 to k.

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


/*

There should be no consecutive animals of different types but same color.
So we basically have to use a greedy algorithm to minimize the number of colors.

*/

std::vector<int> generate_colors(std::vector<int> animals){

	std::vector<int> colors;
	int color_count=0;


	int prev_color=-1;  //previous color 
	int prev_animal=-1; //previous animal

	//A good use of auto is to avoid long initializations for iterators
	for(auto it=animals.begin(); it!=animals.end();it++){

		// first animal in carousel
		if(prev_animal==-1){
			colors.push_back(1);
			prev_animal=*it;
			prev_color=1;

			color_count++;
		}

		else{
			int current_color=-1;

			// previous animal and current animal are same
			if(prev_animal==*it){

				// check if we can use an older color instead of adding a new color
				if(color_count>1){

					// choose the first color that is different from previous color
					for(int i=1;i<=color_count;i++){
						if(i!=prev_color){
							current_color=i;
							break;
						}
					}
				}

				else{
					current_color=++color_count;
				}

				// add the color
				colors.push_back(current_color);

				// update previous animal
				prev_animal=*it;

				// update previous color
				prev_color=current_color;
			}

			//previous animal and current animal are different
			else{

				// check if we can use an older color instead of adding a new color
				if(color_count>1){

					// choose the first color that is different from previous color
					for(int i=1;i<=color_count;i++){
						if(i!=prev_color){
							current_color=i;
							break;
						}
					}
				}

				// there is only one color
				else{
					// increment the color count
					current_color=++color_count;
				}

				// add the color
				colors.push_back(current_color);

				// update previous animal
				prev_animal=*it;

				// update previous color
				prev_color=current_color;
			}
		}

	}

	return colors;

}

int main(){

	int num_test_cases;
	cin>>num_test_cases;

	for(int i=0; i<num_test_cases; i++){

		int num_figures;
		std::vector<int> animal_vec;
		std::vector<int> color_vec;

		cin>>num_figures;

		for(int j=0; j<num_figures; j++){
			int temp;
			cin>>temp;

			animal_vec.push_back(temp);
		}

		color_vec=generate_colors(animal_vec);

		// Print the numbers
		for (int n: color_vec)
			cout<<n<<"\n";
	}

	return 0;
}
