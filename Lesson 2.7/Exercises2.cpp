/**
 * @author Branium Academy
 * @version 2021.10
 * @website https://braniumacademy.net/
 */
#include <iostream>
#include <iomanip>
using namespace std;
const int N = 8;

void showResult(int sol[N][N]);
bool solveKnightTour(int x, int y, int moveStep, int sol[N][N], int xMove[N], int yMove[N]);
bool isSafe(int x, int y, int sol[N][N]);

int main() {
    int sol[N][N]; // m?ng l?u c�c v? tr� tr�n b�n c?
        // kh?i t?o gi� tr? m?c ??nh cho m?ng
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = -1;
        }
    }
    // c�c c?p t?a ?? m� qu�n m� c� th? di chuy?n t? v? tr� hi?n t?i.
    int xMove[] = {2, 1, -1, 2, -2, 1, -1, -2};
    int yMove[] = {1, -2, 2, -1, -1, 2, -2, 1};
    // gi? s? qu�n m� b?t ??u t? � ??u ti�n t?a ?? (0, 0)
    sol[0][0] = 0;
    // t�m l?i gi?i:
    bool isSolved = solveKnightTour(0, 0, 1, sol, xMove, yMove);
    if (!isSolved) {
        cout << "Khong tim duoc loi giai.\n";
    }
    else {
        showResult(sol);
    }
}

/**
     * Ph??ng th?c t�m l?i gi?i cho b�i to�n. T?i v? tr� (x, y) n?u ??t qu�n m� d?n t?i l?i gi?i s? ?�nh d?u
     * v? tr� ?� v?i gi� tr? g l� b??c ?i k? ti?p ?? ti?n ??n k?t qu? cu?i c�ng. Sau khi th?c hi?n m?i b??c
     * ?i c?a qu�n m� s? ???c ghi l?i trong ma tr?n ch?a l?i gi?i sau c�ng.
     *
     * @param x        t?a ?? x c?a � ?ang xem x�t ??t qu�n m�
     * @param y        t?a ?? y c?a � ?ang xem x�t ??t qu�n m�
     * @param moveStep b??c ?i ti?p theo c?a qu�n m�
     * @param sol      ma tr?n k?t qu?
     * @param xMove    c�c t?a ?? x m� qu�n m� c� th? di chuy?n t?i t? v? tr� hi?n th?i
     * @param yMove    c�c t?a ?? y m� qu�n m� c� th? di chuy?n t?i t? v? tr� hi?n th?i
     * @return true n?u t�m ???c 1 l?i gi?i v� false n?u kh�ng t�m ???c l?i gi?i
     */
bool solveKnightTour(int x, int y, int moveStep, int sol[N][N], int xMove[N], int yMove[N]) {
    int nextX;
    int nextY;
    if (moveStep == N * N) {
        return true;
    }
    for (int i = 0; i < N; i++) {
        nextX = x + xMove[i];
        nextY = y + yMove[i];
        if (isSafe(nextX, nextY, sol)) {
            sol[nextX][nextY] = moveStep;
            if (solveKnightTour(nextX, nextY, moveStep + 1, sol, xMove, yMove)) {
                return true;
            }
            else {
                sol[nextX][nextY] = -1; // quay lui
            }
        }
    }
    return false;
}

/**
 * Ph??ng th?c ki?m tra vi?c ??t qu�n m� ? v? tr� x, y c� th?a m�n hay kh�ng
 *
 * @param x   t?a ?? v? tr� x t?i ?� c?n ??t qu�n m�
 * @param y   t?a ?? v? tr� y t?i ?� c?n ??t qu�n m�
 * @param sol ma tr?n l?u k?t qu?
 * @return true n?u qu�n m� c� th? ??t ???c t?i v? tr� (x, y) trong ma tr?n sol
 */
bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N&& y >= 0 && y < N&& sol[x][y] == -1);
}

/**
 * Ph??ng th?c hi?n th? k?t qu?
 *
 * @param sol ma tr?n k?t qu?
 */
void showResult(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << sol[i][j];
        }
        cout << endl;
    }
}