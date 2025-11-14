#include <stdio.h>

#define ll long long

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", lcm(n, m));
    return 0;
}
