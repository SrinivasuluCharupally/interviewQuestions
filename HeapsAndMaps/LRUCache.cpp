#include<iostream>
#include<map>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {
	map<int, int> mymap;
	int key, value, option;
	printf("Options. \t 1 for insert \t 2 for get \t 3 for capacity check \t 4 for exit \n");
	cout << "Your Option" ;
	scanf("%d", &option);

	mymap[2] = 20;
	mymap[3] = 30;
	unordered_set<int> tracker;
while(option !=4) {

	switch(option){

	case 1:
		{
		printf("Enter Key and Value " );
		scanf("%d %d", &key, &value);
		printf("\nKey = %d, value = %d", key, value);
		if(mymap.size() <= 4) {
			map<int, int>::iterator itr = mymap.find(key);
			if(itr != mymap.end()) {
				printf("\n Key exist, key = %d value = %d", key, mymap[key]);
			}
			else mymap[key] = value;
		}
		else {

			printf("stack is full");
		//	if(tracker.size() > 4) {

			unordered_set<int>:: iterator  itr_set = tracker.begin();
			printf("Earasing last recently used key %d", *itr_set);


			map<int, int>::iterator itr = mymap.find(*itr_set);

				mymap.erase(itr);
		//	}
			mymap[key] = value;
		}

		break;
		}
	case 2:
		{
		printf("Enter the Key to get it");
		scanf("%d", &key);
		tracker.insert(key);
		map<int, int>::iterator itr = mymap.find(key);
		if(itr != mymap.end()) {
			printf("Key exist, key = %d value = %d", key, mymap[key]);
		}
		else {
			printf("Key does not exit, return code -1");
		}
		break;
		}
	case 3:
		{
		printf("Stack Capacity %lu", mymap.size());
		break;
		}
	}


	cout << endl << "Your Option" ;
	scanf("%d", &option);
}
	
}
