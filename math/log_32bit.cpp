#include<iostream>
#include<cmath>

using namespace std;


int main () {
double x =  4294967295; //0xffffffff;
double decimal_adjusted = (double)x / ((int64_t)1 << 7);
printf(" decimal_adjusted = %f \n",decimal_adjusted);
double answer = std::log2(decimal_adjusted);
printf(" Log value  %f \n",answer);
answer = (answer * ((int64_t)1 << 7 )) ;
printf(" float to fixed answer %f \n",answer);
}
