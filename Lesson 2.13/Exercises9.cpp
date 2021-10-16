﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// hàm template nhập vào n phần tử của mảng
template<class T> void getInput(vector<T>& v) {
    int n;
    cout << "Nhap so phan tu cua vector: ";
    cin >> n;
    if (n > 0) {
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap phan tu thu " << (i + 1) << ": ";
            T x;
            cin >> x;
            v.push_back(x);
        }
    }
    else {
        cout << "So phan tu phai la so duong.\n";
    }
}

// hàm hiển thị các phần tử của vector ra màn hình
template<class T> void showVectorElements(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

// hàm sắp xếp giảm dần
template<class T> int countX(vector<T>& v, T x) {
    int count = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == x) {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> numbers;
    getInput(numbers);
    cout << "Cac phan tu trong vector: \n";
    showVectorElements(numbers);
    int x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "So phan tu co gia tri bang x: " << countX(numbers, x) << endl;

    return 0;
}