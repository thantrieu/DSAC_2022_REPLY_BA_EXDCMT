/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

void printRevert(long long n) {
    if (n > 0) { // điều kiện để tiếp tục
        cout << n % 10;
        printRevert(n / 10); // giảm n đi 10 lần để loại bỏ phần đơn vị
    }
}

int main() {
    long long n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n > 0) {
        printRevert(n);
    }
    else {
        cout << "Nhap n > 0.\n";
    }
    return 0;
}