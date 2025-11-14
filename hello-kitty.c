#include <stdio.h>

int n;
long long arr[15];
long long subset[15];
long long countSubset = 0; 

void printSubsets(int idx, int len, int targetLen) {
    if(idx == n) {
        if(len == targetLen) {
            printf("{ ");
            for (int i = 0; i < len; i++) {
                printf("%lld ", subset[i]);
            }
            printf("}\n");
            countSubset++;
        }
        return;
    }

    subset[len] = arr[idx];
    printSubsets(idx + 1, len + 1, targetLen); // ambil
    printSubsets(idx + 1, len, targetLen); // skip 
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    for(int len = n; len >= 0; len--) {
        if(len % 2 == 0) {
            printSubsets(0, 0, len);
        }
    }

    printf("\nAda %lld total kombinasi pita genap yang dimiliki oleh Kitty\n", countSubset);

    return 0;
}

/*

3
1 2 3

- {1, 2}
- {1, 3}
- {2, 3}
- { }

*/