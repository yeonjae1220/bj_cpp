#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


using namespace std;


vector<string> people_come;
vector<string> attendees;

map<string, string> m;

int cnt;

int main()
{

	string start, end_assembly, end_stream;

	cin >> start >> end_assembly >> end_stream;

	


	while (/*cin.eof() == false*/!cin.eof())
	{
		string time;
		string people_name;

		cin >> time >> people_name;
		
		/*if (time == "" && people_name == "") break;*/ //�̰� �� �ȵ� �׳� ������ �������� ����

		if ("00:00" <= time && time <= start)
		{
			m[people_name] = time;
		}

		else if (time >= end_assembly && time <= end_stream)//�����ι� 2�� �����°�
		{
			if (m.count(people_name) != 0)
			{
				m.erase(people_name);
				cnt++;
			}

		}

		else if (time > end_stream)
		{
			break;
		}

	}


	cout << cnt;
	return 0;

}





//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//#define MAX 100000
//
////typedef struct log {
////	int h;
////	int m;
////	string name;
////}log_attend;
////
////vector<log_attend> check_list;
////
//
//vector<string> people_come;
//vector<string> attendees;
//
//map<string, int> m;
//
//int cnt;
//
//int main()
//{
//	int HH;
//	int MM;
//	int time;
//	string people_name;
//
//	int HH_start, MM_start, HH_end_assembly, MM_end_assembly, HH_end_stream, MM_end_stream;
//
//	scanf("%d:%d %d:%d %d:%d", &HH_start, &MM_start, &HH_end_assembly, &MM_end_assembly, &HH_end_stream, &MM_end_stream);
//
//	int start = HH_start * 100 + MM_start;
//	int end_assembly = HH_end_assembly * 100 + MM_end_assembly;
//	int end_stream = HH_end_stream * 100 + MM_end_stream;
//
//	while (!cin.eof())
//	{
//		//���ڷ� ������ ���� �Է��� ���� �� break�ϱⰡ ����
//		scanf("%d:%d", &HH, &MM);//���� �ȹް� �ϳ��� ������ �о ������
//		cin >> people_name;
//
//		time = HH * 100 + MM;
//
//
//
//		if (time <= start/*HH < HH_start || (HH == HH_start && MM <= MM_start)*/)
//		{
//			//people_come.push_back(people_name);
//			m[people_name] = time;
//		}
//
//		else if (time >= end_assembly && time <= end_stream)
//		{
//			if (m.count(people_name) != 0)
//			{
//				cnt++;
//			}
//			/*int start = 0, end = m.size(), mid = 0;
//
//			while (start <= end)
//			{
//				
//			}*/
//
//		}
//
//
//		else if (time > end_stream/*HH > HH_end_stream || (HH == HH_end_stream && MM >= MM_end_stream)*/)
//		{
//			break;
//		}
//
//	}
//
//	//sort(people_come.begin(), people_come.end());
//
//	
//	cout << cnt;
//
//
//}