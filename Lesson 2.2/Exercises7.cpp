#include <iostream>
using namespace std;

void readData(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solve(int* arr, int n, int k) {
	for (int i = 0; i <= n - k; i++)
	{
		int max = arr[i];
		for (int j = i; j < i + k; j++)
		{
			if (arr[j] > max) {
				max = arr[j];
			}
		}
		cout << max << " ";
	}
	cout << endl;
}

int main()
{
	int t; // so bo test
	int n; // so phan tu mang
	int k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int* numbers = new int[n];
		readData(numbers, n);
		solve(numbers, n, k);
		delete[] numbers;
	}

	return 0;
}