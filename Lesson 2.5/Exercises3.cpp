/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

int sumDigits(long long n) {
    if (n < 10) { // trường hợp cơ sở
        return n;
    }
    else { // bước đệ quy
        return n % 10 + sumDigits(n / 10);
    }
}

int main() {
    long long n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n > 0) {
        cout << sumDigits(n) << endl;
    }
    else {
        cout << "Nhap n > 0.\n";
    }
    return 0;
}