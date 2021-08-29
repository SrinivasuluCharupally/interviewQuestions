#include<iostream>
#include<vector>

int main() {
	std::vector<int> input{1,2,2,3,4,5};
	bool check[input.size()] { false };
	for(int i = 0; i < input.size(); i++){
		if(check[input[i]]) 
			printf(" dublicate %d ", input[i]);
		else check[input[i]] = true;
	}
return 0;
}
			
