#include <chrono>
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
using namespace chrono;

int get_time() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main()
{
	while (1)
	{
		int n, m, j = 2, g = 0, max = 0, count = 0, block = 0, pn;
		bool c = 1;

		/*
		n - sequence number of the searched prime number
		j - count of all numbers
		l - list of prime numbers
		g - l length
		i - count for l
		m - the number of first prime numbers sufficient to verify the numbers
		c - 0/1 = prime/composite number
		max - the largest prime number which was needed
		count - count of prime numbers already used
		*/

		cout << "Enter sequence number: ";
		cin >> n;
		int* l = new int[100000];

		float start = get_time();
		for (j; g != n; j++)
		{
			if (j < 1000000) {
				m = (g < 100) ? g : pow(g, 1 / 1.999);
			}
			else {
				m = count * 1.012;
			}
			c = 1;
			for (int i = 0; i < m; i++)
			{
				if (j % l[i] == 0) {
					c = 0;
					if (l[i] > max) {
						max = l[i];
						count++;
					}
					break;
				}
			}
			if (c and g < 100000)
			{
				l[g + 1] = j;
			}
			if (c)
			{
				g++;
				pn = j;
			}
			if (j % 1000000 == 0) {
				cout << "progress: " << g * 100 / n << "%, time: " << (get_time() - start) / 1000 << "s" << endl;
			}
		}
		float t = (float(get_time()) - start) / 1000;
		system("cls");
		string a = "th";
		if (n % 10 == 1 and n % 100 != 11) { a = "st"; }
		if (n % 10 == 2 and n % 100 != 12) { a = "nd"; }
		if (n % 10 == 3 and n % 100 != 13) { a = "rd"; }
		cout << n << a << " prime number: " << pn << ", time: " << t << "s" << endl;
	}
}