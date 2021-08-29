#include<iostream>

typedef struct interval {
	int start=0, stop =0;
} interval;

int main() {
	interval *myinterval;
	interval input[5] =  {{1,2},{3,5},{6,7},{8,10},{12,16}};
	interval giveninterval = {4,9};
	interval tmp;
	int arraySize = sizeof(input) / sizeof(input[0]);
	//for(int i =0; i < 5; i++) {
	//	myinterval = new interval;
	//	myinterval->start = input[i].start;
	//	myinterval->stop = input[i].stop;
	//}

	interval newinterval[3];
	int i = 0;

	for(short i = 0; i < arraySize; ) {
		tmp = input[i];
		if(tmp.start < giveninterval.start & tmp.stop > giveninterval.start) {
                      	tmp.stop = giveninterval.stop;
	    	}	

		if(i == arraySize-1) i++;
		while(i<arraySize-1) {
			i++;
			if( tmp.stop >= input[i].start && tmp.stop > input[i].stop) {
//				tmp.stop = input[i].stop;
				continue;
			//	i++;
			}
			else 	if(tmp.stop > input[i].start && tmp.stop <input[i].stop) {
					tmp.stop = input[i].stop;
			     	}	
			    	else break;


		}

		
//		if ( input[i].stop <= input[i].start) {
			printf(" [ %d, %d] \n", tmp.start, tmp.stop);

//		}

	}
}


