//googleing
/*
오히려 가장 큰 기름값 지역부터 찾아가는게 훨씬 효율적 (for문 하나만에 해결 가능)
*/

#include <iostream>
#include <vector>

#define MAX 1000000001 //10억

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


	for (int i = 0; i < n-1; i++)//제일 마지막 지역의 가스 가격은 상관이 없다
	{
		if (max > gas_price[i])
			max = gas_price[i];

		cost += max * distan[i];

	}

	cout << cost;


	return 0;
}










// 시간 초과 오답!
/*
가장 작은 기름값 지역을 찾아서 해당 지역부터 재귀함수로 전해지는 인덱스 까지(이전 가장 작은 기름값 지역 직전)
해당 기름값 * 전해지는 인덱스 까지의 거리 를 해서 재귀로 구하였지만 시간 초과 발생
*/

/*전체 도시를 보며 가스값이 제일 싼 곳 부터 도착 지까지 필요한 거리만큼 주유
그 부분을 제외하고 남은부분에 대하여 위의 논리를 적용
start 부분이 남은 도시중 제일 싼 곳이 될 떄 까지

문제상 최대 크기의 입력에 대해 int형 정수가 담지 못한다
long long int도 안되네?
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
//long long int find_min_cost(int index)//함수에 필요한 변수들은 전부 전역변수 이다//All the variables required for the function are global variables//variables to use this function is all global varable;
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
//	if (index == n)//초기 입력일 때
//	{
//		for (int i = check_index; i < index - 1; i++)
//		{
//			cost += distan[i] * min;
//		}
//	}
//
//	else//재귀 돌 때
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