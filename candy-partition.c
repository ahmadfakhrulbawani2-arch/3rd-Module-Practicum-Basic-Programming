#include <stdio.h>
#define ll long long

// ll fact(ll n) {
//     if(n == 0) return 1;
//     return n * fact(n-1);
// }

// ll combination(ll n, ll k) {
//     ll nFact = fact(n);
//     ll kFact = fact(k);
//     ll nkFact = fact(n-k);
//     ll res = nFact / (kFact * nkFact);
//     return res;
// }

ll memo[35][35] = {0};

ll combination(ll n, ll k) {
    if(k == 0 || k == n) return 1;
    if(memo[n][k] != 0) return memo[n][k];
    memo[n][k] = combination(n-1, k-1) + combination(n-1, k);
    return memo[n][k];
}

int main(void) {
    ll n, k;
    scanf("%lld %lld", &n, &k);

    if(n < k) {
        printf("No fair way to share the candies tonight... A truly spooky Halloween!\n");
        return 0;
    } else if(n == k) {
        printf("There are 1 ways to share the candies, A magical Halloween night!\n");
        return 0;
    }

    ll res = combination(n-1, k-1);

    if(res % 2 == 0) {
        printf("There are %lld ways to share the candies, A spooky Halloween night!\n", res);
    } else {
        printf("There are %lld ways to share the candies, A magical Halloween night!\n", res);
    }
    return 0;
}