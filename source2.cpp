#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct poi {
	int x;
	int y;
	int w;
} po;

struct para {
	int x;
	int y;
	int par;
}pare[10000];

int x, y, w;
int a[101][101];
int m, n, p, q, x1, y_1, x2, y2;
int iter = 1, it = 1;
queue <poi> quh;
stack <para> stas;

int main() {
	cin >> m >> n >> p >> q >> x1 >> y_1 >> x2 >> y2;
	int dx[8] = { -p, p, p, -p, -q, -q, q, q };
	int dy[8] = { -q, -q, q, q, -p, p, p, -p };
	po.x = x1;
	po.y = y_1;
	po.w = 0;
	pare[0].x = x1;
	pare[0].y = y_1;
	pare[0].par = 0;
	quh.push(po);
	a[x1][y_1] = 1;

	while (quh.empty() == false) {
		x = quh.front().x;
		y = quh.front().y;
		w = quh.front().w;
		quh.pop();
		if (x == x2 && y == y2) {
			cout << w << endl;
			int j = it;
			while (pare[j].x != x2 || pare[j].y != y2) {
				j--;
			}
			for (int l = w + 1; l > 0; l--) {
				stas.push(pare[j]);
				j = pare[j].par;
			}
			while (stas.empty() == false) {
				cout << stas.top().x << " " << stas.top().y << endl;
				stas.pop();
			}
			return 0;
        }
		for (int i = 0; i < 8; i++) {
			int xn = x + dx[i];
			int yn = y + dy[i];
			if ((1 <= xn && xn <= m) && (1 <= yn && yn <= n) && a[xn][yn] == 0) {
				po.x = xn;
				po.y = yn;
				po.w = w + 1;
				quh.push(po);
				pare[it].x = xn;
				pare[it].y = yn;
				pare[it].par = iter - 1;
				it++;
				a[xn][yn] = 1;
			}
        }
		iter++;
	}

	cout << -1 << endl;
	return 0;
}
/*(p, q) - лошадь
(p, q)-лошадь - это обобщение обычного шахматного коня. (p, q)-лошадь своим ходом перемещается на p клеток в одном направлении, и на q - в другом (перпендикулярном). Например, (3, 4)-лошадь может переместиться с клетки (5, 6) на клетки (1, 3), (2, 2), (2, 10), (1, 9), (8, 10), (9, 9), (8, 2) и (9, 3). Очевидно, что обычный шахматный конь - это (2, 1)-лошадь.

Ваша задача - определить минимальное число ходов, которое требуется (p, q)-лошади, чтобы добраться от одной клетки шахматной доски M×N до другой. За пределы доски выходить запрещается.

Формат входных данных
Одна строка содержит 8 целых чисел m, n, p, q, x1, y1, x2, y2 (1 ≤ x1, x2 ≤ m ≤ 100, 1 ≤ y1, y2 ≤ n ≤ 100, 0 ≤ p ≤ 100, 0 ≤ q ≤ 100).

Формат результата
Первая строка должна содержать число ходов k, которое требуется (p, q)-лошади, чтобы добраться из клетки (x1, y1) в клетку (x2, y2). Далее должна следовать k + 1 строка, содержащая последовательные положения (p, q)-лошади на этом пути.

Если (p, q)-лошадь не может добраться из (x1, y1) в (x2, y2), выведите -1.*/