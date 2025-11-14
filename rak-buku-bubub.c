/* —---------PROGRAM WAJIB MENGUNAKAN TEMPLATE PROGRAM DIBAWAH INI—--------- 

#include <stdio.h> 
#include <string.h> 
 
int inNum(int num); 
int outNum(); 
void seeTable(); 
 
int main() { 
    // Your code logic here 
    return 0; 
} 
 
int inNum(int num) { 
    // Implementation for inserting a number 
    return 1; 
} 
 
int outNum() { 
    // Implementation for removing the nearest book 
    return 0;  
} 
 
void seeTable() { 
    // Implementation for displaying the current state 
}

*/

#include <stdio.h> 
#include <string.h> 
 
int inNum(int num); 
int outNum(); 
void seeTable(); 

int rak[1000]; // menyimpan id buku sesuai posisi buku di rak
int buku = 0; // mencatat jumlah buku minus 1 dan posisi terakhir buku
int out = -1;

int main() { 
    memset(rak, -1, sizeof(int)); // set semua default val. ke -1;
    char cmd[5];
    int id;
    while(scanf("%s", cmd) != EOF) {
        if(strcmp(cmd, "IN") == 0) {
            scanf("%d", &id);
            int valid = inNum(id);
            if(valid == 1) printf("OK\n");
            else {
                printf("FULL\n");
            }
        } else if(strcmp(cmd, "OUT") == 0) {
            int valid = outNum();
            if(valid == 0) printf("REMOVED %d\n", out);
            else {
                printf("EMPTY\n");
            }
        } else {
            seeTable();
            printf("\n");
        }
    }
    return 0; 
} 
 
int inNum(int num) {
    if(buku >= 1000) return -1;
    rak[buku++] = num;
    return 1; 
} 
 
int outNum() { 
    buku--;
    if(buku == -1) {
        buku = 0; // Reset ke index awal
        return -1; // ketika semua buku REMOVED maka cetak EMPTY
    }
    if(rak[buku] == -1) return -1; // Jika gak ada buku (entah blum di masukkan atau emang gak ada) cetak EMPTY juga
    out = rak[buku];
    rak[buku] = -1;
    return 0;  
} 
 
void seeTable() { 
    if(buku == 0 && rak[0] == -1) printf("EMPTY");
    for(int i = 0; i <= buku-1; i++) {
        printf("%d ", rak[i]);
    }
}