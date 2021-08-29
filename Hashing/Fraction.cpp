#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void function(int numerator, int denominator, string &str) {

	if(numerator == 0 ) { str = '0'; return; }
	if(numerator <0 || denominator <0) { str += '-';}

	str += to_string(abs(numerator) / abs(denominator));

	int reminder = (abs(numerator) % abs(denominator));

	if(reminder ==0) {return; }
	str += '.';


	unordered_map<int, int> m;

    for (; reminder; reminder %= abs(denominator))
    {
        if (m.find(reminder) != m.end())
        {
            str.insert(m[reminder], 1, '(');
            str.push_back(')');
            break;
        }

        m[reminder] = str.size();
        reminder *= 10;
        str.push_back('0' + (reminder/((abs(denominator)))));
    }

    return ;
}


int main() {
	int numerator = 7, denominator=4;
	string str;
	function(numerator, denominator, str);

	cout << str << endl;
}
