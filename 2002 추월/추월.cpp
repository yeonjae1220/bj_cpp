#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> in;
vector<string> out;

int n, cnt = 0;

int main()
{
	string number;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		in.push_back(number);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> number;
		out.push_back(number);
	}

	int index = 0;

	for (int i = 0; i < n; i++)
	{
		number = out[i];
		
		if (number == in[index])
		{
			index++;
		}

		else
		{
			//둘다 컴파일 에러 뜬다
			/*in.erase(remove(in.begin(), in.end(), number), in.end());*/
			/*remove(in.begin(), in.end(), number);*/
			cnt++;
		}
	}



	cout << cnt;

	return 0;
}