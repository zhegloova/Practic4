#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
void task_1()
{
	int count = 0; //счетчик операций
	string s;
	cout << "Enter string:" << endl;
	getline(cin, s);
	double t1 = clock();
	int i = s.length() - 1;
	string s1 = ""; // для последнего слова
	count++;
	while (isalpha(s[i])) //пока идут буквы записываем последнее слово
	{
		s1 = s[i] + s1;
		i--;
		count++;
	}
	cout << "The last word is: " << s1 << endl; //выводим последнее слово
	int  b = 0;
	int eq = 0;
	string buf = ""; //строка для текущего слова
	count++;
	while (i >= 0) // пока не дошли до начал строки (идем с конца)
	{
		count++;
		if (isalpha(s[i])) //пока буквы - записываем текущее слово
			buf = s[i] + buf;
		else { //нашли символ-разделитель
			count++;
			if (buf != "") { //если есть слово, а не символы
				count++;
				if (buf == s1) eq++; //слово равно последнему
				if (buf > s1) b++; //слово больше последнего
			}
			buf = ""; // обнуление строки текущего слова
		}
		i--;
	}
	cout << eq << " words equal to the last" << endl;
	cout << b << " words bigger than the last" << endl;
	double t2 = clock();
	cout << count << " operations" << endl;
	cout << (t2 - t1) / 1000 << " seconds" << endl;

}

void task_2()
{
	string s;
	cout << "Enter string:" << endl;
	getline(cin, s);
	int count = 0; // счетчик операций
	double t1 = clock();
	int n = s.length();
	vector<int> pi(n);
	count++;
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];  //текущая длина префикса, который мы хотим продолжить
		//гарантируется, что s[0..j-1] = s[i-j..i-1].
		count++;
		while (j > 0 && s[i] != s[j]) {     //пока мы не можем продолжить текущий префикс
			count++;
			j = pi[j - 1];  //уменьшаем его длину до следующей возможной
		}

		//Теперь j - максимальная длина префикса, который мы можем продолжить,
		//или 0, если такового не существует.
		count++;
		if (s[i] == s[j]) {
			count++;
			pi[i] = j + 1;
		}
		else {    //такое может произойти только при j = 0
			pi[i] = j;
			count++;
		}
	}
	cout << s.length() - pi[n - 1] << endl;
	double t2 = clock();
	cout << count << " operations" << endl;
	cout << (t2 - t1) / 1000 << " seconds";

}
int main()
{
	cout << "Enter task number: " << endl;
	int number;
	cin >> number;
	if (number == 1) {
		task_1();
	}
	else if (number == 2) {
		task_2();
	}
	else {
		cout << "The task number is entered incorrectly!" << endl;
	}
}