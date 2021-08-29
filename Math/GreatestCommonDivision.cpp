#include<iostream>

using namespace std;

int  gcd(int A, int B) {
    //Euclid's algorithm
    if(B!=0) cout << A << endl;
    return B==0 ? A : gcd(B, A%B);
}

int main() {

	int A = 30, B=40;

 //gcd(int A, int B) {
    //Euclid's algorithm
    while(B!=0) 
    {
        int r = A%B; // 10 % 5, r=0
        A = B;  // A = 5
        B = r;  // B = 0
    }
//    return A;
    cout << A << endl;
	gcd(A,B);
}
