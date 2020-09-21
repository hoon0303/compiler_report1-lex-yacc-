/*
20164006 박훈
컴파일러(플렉스, 바이슨)
연습문제 4번 c++ 프로그램
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

vector<string> text;//파일에서 읽은 문자열 저장
stack<string> s, st;
string temp;
bool id(string x)////////////////////////////////id 판별 함수
{
	if (!(('a' <= x[0] && x[0] <= 'z') || ('A' <= x[0] && x[0] <= 'Z')))
		return 0;
	for (int i = 1; i < x.size(); i++)
	{
		if (!(('0' <= x[i] && x[i] <= '9') || ('a' <= x[i] && x[i] <= 'z') || ('A' <= x[i] && x[i] <= 'Z')))
		{
			return 0;
		}
	}
	return 1;
}
bool c_id(string x)////////////////////////////C id 판별 함수
{
	if (!(('a' <= x[0] && x[0] <= 'z') || ('A' <= x[0] && x[0] <= 'Z') || x[0] == '_'))
		return 0;
	for (int i = 1; i < x.size(); i++)
	{
		if (!(('0' <= x[i] && x[i] <= '9') || ('a' <= x[i] && x[i] <= 'z') || ('A' <= x[i] && x[i] <= 'Z') || x[i] == '_'))
		{
			return 0;
		}
	}
	return 1;
}
bool integer(string x)////////////////////////integer 판별 함수
{
	if (!(x[0] == '+' || x[0] == '-' || ('0' <= x[0] && x[0] <= '9')))
		return 0;
	for (int i = 1; i < x.size(); i++)
	{
		if (!('0' <= x[i] && x[i] <= '9'))
		{
			return 0;
		}
	}
	return 1;
}
bool real(string x)//////////////////////////real 판별 함수
{
	if (!(('0' <= x[0] && x[0] <= '9')))
		return 0;
	for (int i = 1; i < x.size(); i++)
	{
		if (!(('0' <= x[i] && x[i] <= '9') || x[i] == '.' || x[i] == 'e' || x[i] == '+' || x[i] == '-'))
		{
			return 0;
		}
	}
	return 1;
}
void init()//파일로 부터 데이터 셋팅
{
	ifstream fp;
	fp.open("data.txt");
	cout << "data.txt 파일내용" << endl;
	if (fp.is_open())
	{
		while (!fp.eof())
		{
			string str;
			getline(fp, str);
			cout << str << endl;
			text.push_back(str);
		}
		cout << "\n";
	}
	else
	{
		cout << "파일 읽기 실패" << endl;
		exit(1);
	}
	fp.close();
}
void read()
{
	for (int i = 0; i < text.size(); i++)
	{
		string str;
		str = text[i];
		char *buffer = new char[1000];
		strcpy(buffer, str.c_str());

		char *tok = strtok(buffer, ", ");
		while (tok != NULL) {
			str = string(tok);
			////////////////////////////////////////////////////////////////text comment 판별
			if (str.size() >= 2)
			{
				if (str[0] == '/'&&str[1] == '*')
				{
					s.push("/*");
				}
			}
			if (!s.empty())
			{
				if (str.size() < 2)
				{
					tok = strtok(NULL, ", ");
					continue;
				}
				if (!s.empty() && str[str.size() - 2] == '*'&&str[str.size() - 1] == '/')
				{
					s.pop();
					cout << "text comment : /* . . . */" << endl;
				}
				tok = strtok(NULL, ", ");
				continue;
			}
			///////////////////////////////////////////////////////////////line comment 판별
			if (str[0] == '/'&&str[1] == '/')
			{
				cout << "line comment : // . . ." << endl;
				break;
			}
			//////////////////////////////////////////////////////////////string 판별
			if (str[0] == '\"')
			{
				st.push("\"");
			}
			if (!st.empty())
			{
				temp = temp + " " + str;

				if (str[str.size() - 1] == '\"')
				{
					st.pop();
					cout << "      string : " << temp << endl;
					temp = "";
				}
				tok = strtok(NULL, ", ");
				continue;
			}
			///////////////////////////////////////////////////////////id 판별
			if (id(str))
			{
				cout << "          id : " << str << endl;
				tok = strtok(NULL, ", ");
				continue;
			}
			//////////////////////////////////////////////////////////C id 판별
			if (c_id(str))
			{
				cout << "        C id : " << str << endl;
				tok = strtok(NULL, ", ");
				continue;
			}
			/////////////////////////////////////////////////////////Integer 판별
			if (integer(str))
			{
				cout << "     integer : " << str << endl;
				tok = strtok(NULL, ", ");
				continue;
			}
			////////////////////////////////////////////////////////real 판별
			if (real(str))
			{
				cout << "        real : " << str << endl;
				tok = strtok(NULL, ", ");
				continue;
			}
			//////////////////////////////////////////////////////////////////////
			tok = strtok(NULL, ", ");
		}
	}
}
int main(void)
{
	init();//파일 데이터 셋팅
	read();//데이터 일기
	return 0;//정상종료
}