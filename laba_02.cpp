#include <iostream>
#include <fstream>
#include <string>

using namespace std;




bool is_vowel(string p) {
	if ((p[0] == 'a' ||
		p[0] == 'e' ||
		p[0] == 'i' ||
		p[0] == 'o' ||
		p[0] == 'u' ||
		p[0] == 'A' ||
		p[0] == 'E' ||
		p[0] == 'I' ||
		p[0] == 'O' ||
		p[0] == 'U') && 
		(p[p.size() - 1] == 'a' ||
		p[p.size() - 1] == 'e' ||
		p[p.size() - 1] == 'i' ||
		p[p.size() - 1] == 'o' ||
		p[p.size() - 1] == 'u' ||
		p[p.size() - 1] == 'A' ||
		p[p.size() - 1] == 'E' ||
		p[p.size() - 1] == 'I' ||
		p[p.size() - 1] == 'O' ||
		p[p.size() - 1] == 'U')) {
		return true;
	}
	
	else {
		return false;
	}
}

void t1()
{

	char c;

	while (1)
	{
		cout << "\n  1. Cчитать текст из файла и вывести на экран необходимые слова текста"
			<< "\n  0. Назад\n-> ";
		cin >> c;

		switch (c)
		{
		case '1': {
			
			ifstream file("file1.txt");
			string str;
			char* p = NULL;
			while (getline(file, str))
			{
				int pos = 0;
				string token;
				string delimiter = " ";
				while ((pos = str.find(delimiter)) != string::npos) {
					token = str.substr(0, pos);

					if (is_vowel(token)) {
						cout << token << endl;
					}
					str.erase(0, pos + delimiter.length());
				}
				if (is_vowel(str)) {
					cout << str << endl;
				}
			}
			file.close();
			
			break; }
		case '0': return;
		}
	}
}

int main()
{
	setlocale(0, "rus");
	int c;

	while (1)
	{
		cout << "Меню"
			<< "\n1. Задание N2 Файловые и строковые потоки"
			<< "\n0.Выход\n-> ";
		cin >> c;

		switch (c)
		{
		case 1:	t1(); break;
		case 0:			return 0;
		}
	}
}


