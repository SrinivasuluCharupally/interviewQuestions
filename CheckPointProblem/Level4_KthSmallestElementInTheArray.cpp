#include<iostream>
#include<vector>

using namespace std;

int main() {
	int input[] ={2,1,4,3,2};
	int arraySize = sizeof(input) / sizeof(int) ;
	int kth = 3;

	vector<int> v;

	bool visited[arraySize] ={false};
	while(v.size() <= kth) {
		int  j = 0;

		while(visited[j])
		       j++;

		int visitedPosition = j, minposition = j;
		while(j < arraySize) {
			if(v.size() == 0 || input[j] > v.back() ) {
				minposition  =  input[minposition]  < input[j] ? minposition : j;

			}
			j++;
		}
		v.push_back(input[minposition]);
		visited[minposition] = true;
	}

	for(int i = 0; i < v.size(); i++)
		printf("%d  ", v[i]);

	printf("\nk the min value = %d \n" , v[kth]);

}

