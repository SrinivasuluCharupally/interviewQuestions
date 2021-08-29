#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int compare(const void * a, const void *b) {
	return *(int*)a - *(int*)b;
}

void recursion(unordered_set<int>::iterator itr, int change, unordered_set<int> &mySet, int sequence_count, int &mylength) {
	if(sequence_count > mySet.size()) return;
	else {
			if( mySet.erase(*itr + change)  >=1 ) { change = change+1; 
				recursion(itr, change, mySet, sequence_count+1, mylength);
			}

			else if( mySet.erase(*itr - change)  >=1 ) { change = change+1;
				recursion(itr, change, mySet, sequence_count+1, mylength);
			}
			
			mySet.erase(*itr);
			itr  = mySet.begin();
			mylength = mylength < sequence_count ? sequence_count : mylength;
			change=1, sequence_count=0;

			recursion(itr, change,  mySet, sequence_count+1, mylength);
	}
}

int main()  {
	int input[] = {100, 4, 200, 1, 3, 2, 201,202,203,204,205};
	int arraySize = sizeof(input) / sizeof(int);

	unordered_set<int> mySet = {100, 4, 200, 1, 3, 2, 201,202,203,204,205};
	unordered_set<int>::iterator itr = mySet.begin();
	int change=1, sequence_count=0, mylength=0;
	
	recursion(itr, change,  mySet, sequence_count, mylength);
	cout << endl << "Consequitive length = " << mylength+1 << endl;

// using sorting , no recursion ........................................	
	qsort(input, arraySize, sizeof(int), compare);
	for(int i =0; i < arraySize; i++)
		cout << input[i] << " " ;

	int previous = 0, length=0, count=0;
	for(int i = 0; i < arraySize; i++) {
		if(input[i] + 1 == input[i+1])
			count++;

		else {
			length = length < count ? count : length;
			count = 0;
		}
	}
	
	cout << endl << "Consequitive length = " << length+1 << endl;

}
