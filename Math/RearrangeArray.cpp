#include<iostream>
#include<vector>


using namespace std;

int main() {
	
vector<int> A {1,0,2, 4, 3};

int n = A.size();

    for(auto i=0; i<n; ++i)
    {
        A[i] += (A[A[i]]%n)*n;
    }
    for(auto i=0; i<n; ++i)
    {
       A[i] /= n;
    }

    for(int i = 0; i < A.size(); i++)
	    cout << A[i] << endl;

}



