#include <iostream>

using namespace std;

const int c = 4 * 1e6;
long long n, k, a[c], tmp, tm, p, start;

void update(long long i, long long x) {
	i += start;
	a[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		a[i] = a[i * 2] + a[i * 2 + 1];
	}
	return;
}
long long getsum(long long l, long long r) {
	l += start;
	r += start;
	long long sum = 0;
	while (l <= r) {
		if (l % 2 != 0) {
			sum += a[l];
			l++;
		}
		if (r % 2 == 0) {
			sum += a[r];
			r--;
		}
		r /= 2;
		l /= 2;
	}
	return sum;
}


int main() {
	cin >> n >> k;
	start = 1;
	while (start < n) {
		start <<= 1;
	}
	for (int i = 0; i < k; i++) {
		cin >> tmp >> tm >> p;
		if (tmp == 1) {
			update(tm-1, p);
		}
		else {
			cout << getsum(tm-1, p-1) << endl;
		}
	}
	return 0;
}
/*Простая сумма
Дан массив из N элементов, необходимо находить сумму элементов массива на отрезке.

Формат входных данных
Первая строка входных данных содержит два целых числа N и K - число чисел в массиве и количество запросов. (1 ≤ N ≤ 106); (1 ≤ K ≤ 105). Следующие K строк содержат запросы:

1 i x – присвоить i-му элементу массива значение x (1 ≤ i ≤ n; 0 ≤ x ≤ 109)
2 l r – найти сумму чисел в массиве на позициях от l до r. (1 ≤ l ≤ r ≤ n)
Изначально массив заполнен нулями.

Формат результата
На каждый запрос вида 2 l r нужно вывести единственное число – сумму на отрезке.*/