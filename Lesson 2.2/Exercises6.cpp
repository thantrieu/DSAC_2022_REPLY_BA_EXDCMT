#include <iostream>
using namespace std;

void readData(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int sum(int* arr, int n) {
	int s = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i + 1]) {
			s += arr[i];
		}
	}
	return s;
}

int main()
{
	int t; // so bo test
	int n; // so phan tu mang
	cin >> t;
	while (t--) {
		cin >> n;
		int* numbers = new int[n];
		readData(numbers, n);
		cout << sum(numbers, n) << endl;
		delete[] numbers;
	}

	return 0;
}