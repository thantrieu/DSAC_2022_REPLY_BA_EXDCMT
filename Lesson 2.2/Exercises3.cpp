#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void showResult(string* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void splitWords(string* words, string input, int& size) {
	istringstream ss(input);
	string str;
	while (ss >> str) {
		words[size++] = str;
	}
}

int main()
{
	int t; // so bo test
	cin >> t; // đọc số bộ test
	cin.ignore(); // đọc bỏ kí tự thừa cuối dòng số bộ test
	while (t--) {
		string input;
		int numOfWord = 0;
		getline(cin, input);
		string* words = new string[input.length()];
		splitWords(words, input, numOfWord);
		sort(words, words + numOfWord);
		showResult(words, numOfWord);
		delete[] words;
	}

	return 0;
}