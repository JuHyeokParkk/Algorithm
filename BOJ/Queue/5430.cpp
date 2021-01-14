#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	
	 int T, n;
	cin >> T;


	while (T--)
	{
		deque<int> Deque;
		string function;
		char num;
		string value = "";
		cin >> function;
		cin >> n;

		while(1)
		{
			cin >> num;
			if (num >= '0' && num <= '9')
			{
				value += num;
			}

			else
				if (value != "")
				{
					Deque.push_back(stoi(value));
					value = "";
				}
			if (num == ']')
				break;
		}

		unsigned int i, index = 0;
		bool reverse_flag = false;
		bool error_flag = false;

		while (function[index])
		{
			if (function[index] == 'R')
				reverse_flag = !reverse_flag;

			else
			{
				if (Deque.empty())
				{
					cout << "error\n";
					error_flag = true;
					break;
				}

				if (reverse_flag)
					Deque.pop_back();

				else
					Deque.pop_front();
			}
			index++;
		}
		
		
		if (!error_flag)
		{
			if (Deque.empty())
				cout << "[]\n";
				
			else
			{

				cout << "[";
				if (reverse_flag)
				{
					for (i = Deque.size() - 1; i > 0; i--)
					{

						cout << Deque[i] << ",";

					}


				}

				else
				{
					for (i = 0; i < Deque.size() - 1; i++)
					{
						cout << Deque[i] << ",";
					}


				}

				cout << Deque[i] << "]\n";
			}
		}
	}
	

}