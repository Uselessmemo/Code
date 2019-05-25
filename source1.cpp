#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string s;
int sign = 1;
vector <long long>stas;
vector<char>revPol;
long long n;
long long x, y;

bool Operator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int prior(char c) {
	if (c == '(')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == '*' || c == '/')
		return 3;
	else
		return 4;
}

bool PriorMinus(int i) {
	if (s[i] == '-' && (i == 0 || Operator(s[i - 1]) || s[i - 1] == '(')) {
		sign = -1;
		return true;
	}
	return false;
}

long long binPow(long long a, long long n) {
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binPow(a, n - 1) * a;
	else {
		long long b = binPow(a, n / 2);
		return b * b;
	}
}

void toPol(char c) {
	long long b = stas.back();
	stas.pop_back();
	long long a = stas.back();
	stas.pop_back();
	switch (c) {
	case '+':stas.push_back(a + b); break;
	case '^':stas.push_back(binPow(a, b)); break;
	case '*':stas.push_back(a * b); break;
	case '/':stas.push_back(a / b); break;
	case '-':stas.push_back(a - b); break;
	}
	return;
}

void ca(int a) {
	while (!revPol.empty() && prior(revPol.back()) >= a) {
		toPol(revPol.back());
		revPol.pop_back();
	}
	return;
}

long long calc(string s, long long x, long long y) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			if (!PriorMinus(i)) {
				ca(2);
				revPol.push_back('-');
			}
		}
		else if (s[i] == '(') {
			revPol.push_back(s[i]);
		}
		else if (s[i] == ')') {
			ca(2);
			revPol.pop_back();
		}
		else if (Operator(s[i])) {
			ca(prior(s[i]));
			revPol.push_back(s[i]);
		}
		else if (s[i] == 'x') {
			stas.push_back(x * sign);
			sign = 1;
		}
		else if (s[i] == 'y') {
			stas.push_back(y * sign);
			sign = 1;
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			long long tmp = s[i] - '0';
			while (s[i + 1] >= '0' && s[i + 1] <= '9') {
				i++;
				tmp *= 10;
				tmp += s[i] - '0';
			}
			tmp *= sign;
			sign = 1;
			stas.push_back(tmp);
		}
	}
	while (!revPol.empty()) {
		toPol(revPol.back());
		revPol.pop_back();
	}
	return stas.back();
}



int main() {
	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		stas.clear();
		revPol.clear();
		cout << calc(s, x, y) << endl;
	}
	return 0;
}
/*Арифметическое выражение
Вам будет дано правильное арифметическое выражение, содержащее круглые скобки, операции + (сложение), - (вычитание), * (умножение), / (целочисленное деление), ^ (возведение в степень), - (знак числа), переменные x, y и целочисленные константы.

Для каждой заданной пары значений переменных x, y выведите значение арифметического выражения. Гарантируется, что значение выражения не превосходит по абсолютной величине 263 - 1.

Формат входных данных
В первой строке входных данных заданно соответсвующее условию арифметическое выражение. Выражение содержит только знаки операций, скобки, переменные x, y, целочисленные константы (без пробелов).

Во второй строке задано натуральное число N (1 ≤ N ≤ 1000) - колечиство пар значений переменных x, y.

В каждой из последующих N строк содержаться два целых числа, разделенных пробелом - значения перменных x и y.

Формат результата
Для каждой пары значений переменных x и y из входных данных выведите в отдельную строку единственное целое число - значение арифметического выражения.*/