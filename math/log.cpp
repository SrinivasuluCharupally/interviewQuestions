// decimal location https://www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html
// math instruction / value : https://www.rapidtables.com/calc/math/index.html
#include<iostream>
#include<math.h>
#include <stdint.h>


using namespace std;
int main () {
long double x =  4294967295; //0xffffffff;
cout << x << endl;
printf(" input %lf \n", x);

long double decimal_adjusted = (long double)x / ((int64_t)1 << 0);
printf(" decimal_adjusted = %lf \n",decimal_adjusted);

uint64_t num = UINT64_MAX;
  int64_t num2 = 4294967295ll ; // 317584931803ll;

  printf("%llu\n", num);
  printf("%lld\n", num2);

double  answer = std::log2(num2 /*decimal_adjusted*/ ); //// 31.9997


cout << "long double of answer "<<  answer << endl;

printf(" Log value  %f \n",answer);

answer = (answer * ((int64_t)1 << 28 )) ;

int out = answer;

printf(" float to fixed answer %f \n",answer);
printf(" float to fixed out %d \n",out);

}
