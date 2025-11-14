#include <stdio.h>

void printLine(int curr, int max) {
    char c;
    if(curr == max) 
        c = 'o';

    else if(curr % 2 == 1) 
        c = 'a';

    else 
        c = 'e';

    for(int i = 0; i < curr; i++) {
        printf("%c", c);
    }

    printf("\n");
}

void printPattern(int curr, int max) {
    if(curr == 0) return; // base case karena n = 0 tidak mungkin ada.

    printPattern(curr - 1, max);  
    printLine(curr, max);         
    printPattern(curr - 1, max);  // mirror dengan upper parts
}

int main() {
    int n;
    scanf("%d", &n);
    printPattern(n, n);
    return 0;
}


/*

=== EXPLANATION ===

jika N = 1

o

jika N = 2

a
oo
a

jika N = 3

a
ee
a
ooo
a
ee
a

jika N = 4

a 
ee 
a 
aaa 
a 
ee 
a 
oooo 
a 
ee 
a 
aaa 
a 
ee 
a

jika N = 5

a
ee
a
aaa
a
ee
a
eeee
a
ee
a
aaa
a
ee
a
ooooo
a
ee
a
aaa
a
ee
a
eeee
a
ee
a
aaa
a
ee
a



Jika dilihat polanya adalah

pola ke-(N-1) (sebelumnya)
pola ke-N
pola ke-(N-1) (sebelumnya juga karena di-mirror)

*/