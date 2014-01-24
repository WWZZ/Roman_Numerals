#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef unordered_map<char, int> rNumerals;

int toInt(rNumerals R, string romans)
{
	int num = 0;
	int s = romans.size();
	char previous , current;
	if (s > 1)
	{
		previous = romans.at(0);
		num += R[previous];
	}
	else return R[previous];
	for (int i = 1; i < s; i++)
	{
		current = romans.at(i);
		if (R[current] > R[previous])
		{
			num -= R[previous];
			num += R[current] - R[previous];
		}
		else num += R[current];
		previous = current;
	}
	return num;
}

int main()
{
	rNumerals first =  {{'I',1},{'V', 5},
					    {'X',10}, {'L', 50},
						{'C',100}, {'D', 500},
						{'M',1000}} ;

	string test = "XCIX"; //99
	cout << toInt(first,test) << endl;

	string test2 = "LXXIX"; //79
	cout << toInt(first, test2) << endl;

	string test3 = "DCCVII"; //707
	cout << toInt(first, test3) << endl;
	
	string test4 = "XX"; //20
	cout << toInt(first, test4) << endl;

	cin.get();
	return 0;
}
