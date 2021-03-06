#include <iostream>
using namespace std;

void readData(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void showResult(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void removeX(int* arr, int& n, int x) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x) {
			for (int j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			n--;
			i--; // xét lại phần tử mới tại vị trí i
		}
	}
}

int main()
{
	int t; // so bo test
	int n; // so phan tu mang
	int x; // gia tri can chen
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int* numbers = new int[n];
		readData(numbers, n);
		removeX(numbers, n, x);
		showResult(numbers, n);
		delete[] numbers;
	}

	return 0;
}