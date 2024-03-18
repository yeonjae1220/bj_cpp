//googleing
/*
������ ���� ū �⸧�� �������� ã�ư��°� �ξ� ȿ���� (for�� �ϳ����� �ذ� ����)
*/

#include <iostream>
#include <vector>

#define MAX 1000000001 //10��

using namespace std;

int n, input;

vector<long long int> gas_price;
vector<long long int> distan;



int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> input;
		distan.push_back(input);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		gas_price.push_back(input);
	}

	long long int max = MAX;
	long long int cost = 0;


	for (int i = 0; i < n-1; i++)//���� ������ ������ ���� ������ ����� ����
	{
		if (max > gas_price[i])
			max = gas_price[i];

		cost += max * distan[i];

	}

	cout << cost;


	return 0;
}










// �ð� �ʰ� ����!
/*
���� ���� �⸧�� ������ ã�Ƽ� �ش� �������� ����Լ��� �������� �ε��� ����(���� ���� ���� �⸧�� ���� ����)
�ش� �⸧�� * �������� �ε��� ������ �Ÿ� �� �ؼ� ��ͷ� ���Ͽ����� �ð� �ʰ� �߻�
*/

/*��ü ���ø� ���� �������� ���� �� �� ���� ���� ������ �ʿ��� �Ÿ���ŭ ����
�� �κ��� �����ϰ� �����κп� ���Ͽ� ���� ���� ����
start �κ��� ���� ������ ���� �� ���� �� �� ����

������ �ִ� ũ���� �Է¿� ���� int�� ������ ���� ���Ѵ�
long long int�� �ȵǳ�?
*/



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int n, input;
//
////int min_cost = 0;
//
//vector<long long int> gas_price;
//vector<long long int> distan;
//
//long long int find_min_cost(int index);
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n-1; i++)
//	{
//		cin >> input;
//		distan.push_back(input);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> input;
//		gas_price.push_back(input);
//	}
//
//
//	cout << find_min_cost(n);
//
//
//	return 0;
//}
//
////
//long long int find_min_cost(int index)//�Լ��� �ʿ��� �������� ���� �������� �̴�//All the variables required for the function are global variables//variables to use this function is all global varable;
//{
//	if (index == 0)
//	{
//		return 0;
//	}
//
//	if (index == 1)
//	{
//		return distan[0] * gas_price[0];
//	}
//
//	long long int min = gas_price[0];
//	int check_index = 0;
//	long long int cost = 0;
//
//	for (int i = 0; i < index; i++)
//	{
//		if (min > gas_price[i])
//		{
//			min = gas_price[i];
//			check_index = i;
//		}
//	}
//
//	if (index == n)//�ʱ� �Է��� ��
//	{
//		for (int i = check_index; i < index - 1; i++)
//		{
//			cost += distan[i] * min;
//		}
//	}
//
//	else//��� �� ��
//	{
//		for (int i = check_index; i < index; i++)
//		{
//			cost += distan[i] * min;
//		}
//	}
//
//	
//
//
//	return cost + find_min_cost(check_index);
//	
//
//}