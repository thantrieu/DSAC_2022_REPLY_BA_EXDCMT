﻿/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

// hàm tìm giá trị lớn nhất
int findMax(int* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
// thuật toán sắp xếp đếm
void countingSort(int* input, int size) {
	int k = findMax(input, size);
	int* output = new int[size];
	int* count = new int[k + 1]();
	for (int i = 0; i < size; i++)
	{
		int j = input[i];
		count[j]++;
	}
	for (int i = 1; i <= k; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		int j = input[i];
		count[j]--;
		output[count[j]] = input[i];
	}
	for (int i = 0; i < size; i++)
	{
		input[i] = output[i];
	}
	delete[] count;
	delete[] output;
}

template<class T> void showArrayElements(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T> void readData(T* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		int* arr = new int[n];
		readData(arr, n);
		countingSort(arr, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
		delete[] arr;
	}
	return 0;
}