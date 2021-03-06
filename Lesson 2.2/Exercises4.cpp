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

void insertX(int* arr, int n, int k, int x) {
    if (k <= 0) { // chèn đầu mảng
        for (int i = n; i > 0; i--) // dịch phải tất cả các phần tử
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = x; // chèn x vào đầu
    }
    else if (k >= n) { // chèn cuối mảng
        arr[n] = x; // chèn luôn vào đít
    }
    else { // chèn tại vị trí khác trong mảng
        for (int i = n; i > k; i--)
        {
            arr[i] = arr[i - 1]; // dịch phải tất cả các phần tử bên phải vị trí cần chèn
        }
        arr[k] = x; // chèn x vào vị trí k
    }
}

int main()
{
    int t; // so bo test
    int n; // so phan tu mang
    int k; // vi tri
    int x; // gia tri can chen
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        int* numbers = new int[n + 1]; // lưu ý chừa 1 chỗ để chèn x nha
        readData(numbers, n);
        insertX(numbers, n, k, x);
        showResult(numbers, n + 1);
        delete[] numbers;
    }

    return 0;
}