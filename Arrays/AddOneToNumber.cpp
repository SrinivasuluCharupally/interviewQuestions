#include<iostream>
#include<vector>

int main() {
	std::vector<int> input{3,2,9};
	for(auto i : input) {
		printf("%d\n", i);
	}
	int vectorSize = input.size()-1;
	input[vectorSize] += 1;
#if 1
	while(input[vectorSize] ==10){
		       	input[vectorSize] = 0;
			input[vectorSize-1] +=1;
			vectorSize -= 1;

		}
	 	

	std::cout << "After +1 to given number" << std::endl;
	for(auto j = input.begin(); j != input.end(); j++) {
		std::cout << *j << " " << std::endl;
	}

#endif
}
