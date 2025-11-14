#include <stdio.h>

#define ll long long

// Mengalikan 2x2 matriks
void mul(double a[2][2], double b[2][2], double res[2][2]) {
    double temp[2][2];
    temp[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    temp[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    temp[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    temp[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    res[0][0] = temp[0][0];
    res[0][1] = temp[0][1];
    res[1][0] = temp[1][0];
    res[1][1] = temp[1][1];
}

// Matrix exponentiation rekursif
void power(double a[2][2], ll n, double res[2][2]) {
    if(n == 1) {
        res[0][0] = a[0][0]; res[0][1] = a[0][1];
        res[1][0] = a[1][0]; res[1][1] = a[1][1];
        return;
    }

    double half[2][2];
    if(n % 2 == 0) {
        power(a, n/2, half);
        mul(half, half, res);
    } else {
        double temp[2][2];
        power(a, n-1, temp);
        mul(a, temp, res);
    }
}

int main() {
    ll b, n;
    scanf("%lld %lld", &b, &n);

    if(n == 1) {
        printf("%.8lf\n", (double)(b+1));
        return 0;
    }

    // Matriks untuk linear recurrence
    double M[2][2] = {{b, b}, {1, 0}};
    double res[2][2];

    power(M, n-1, res);

    double p1 = b + 1; // p1
    double q1 = 1;     // q1

    double pn = res[0][0]*p1 + res[0][1]*q1;
    double qn = res[1][0]*p1 + res[1][1]*q1;

    double ans = pn / qn;
    printf("%.8lf\n", ans);

    return 0;
}
