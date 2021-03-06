#include <iostream>
#include <fstream>

using namespace std;
// khai báo nguyên mẫu hàm
void readData(ifstream& ifs, int* arr, int n);
int knapSack(int w, int* weight, int* value, int n);

int main() {
	ifstream ifs("input4.txt");
	if (ifs) {
		int t, n, m;
		int countTest = 1;
		ifs >> t;
		while (t > 0) {
			ifs >> n;
			int* values = new int[n];
			int* weight = new int[n];
			readData(ifs, values, n);
			readData(ifs, weight, n);
			ifs >> m;
			cout << "Test " << countTest++ << ": ";
			cout << knapSack(m, weight, values, n) << endl;
			t--;
		}
		ifs.close();
	}
	return 0;
}

void readData(ifstream& ifs, int* arr, int n) {
	for (int i = 0; i < n; i++) {
		ifs >> arr[i];
	}
}

// trả về giá trị lớn nhất có thể bỏ vào túi giới hạn khối lượng W
// chiến lược bottom-up
int knapSack(int w, int* weight, int* value, int n) {
	int** result = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		result[i] = new int[w + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0) {
				result[i][j] = 0;
			}
			else if (weight[i - 1] <= j) {
				result[i][j] = max(value[i - 1] + result[i - 1][j - weight[i - 1]], result[i - 1][j]);
			}
			else {
				result[i][j] = result[i - 1][j];
			}
		}
	}
	int x = result[n][w];
	for (int i = 0; i <= n; i++)
	{
		delete[] result[i];
	}
	delete[] result;

	return x; // trả về kết quả
}