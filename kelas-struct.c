#include <stdio.h>
/*

typedef struct {
    char name[31];
    char nrp[11];
    char tmp_lahir[21];
    int tgl_lahir, bln_lahir, thn_lahir;
} mahasiswa;

int main(void) {
    mahasiswa mhs1 = {"5025251143", "Febrian", "Surabaya", 1, 1, 2007};
    mahasiswa mhs2;

    mhs2 = mhs1; // tipe struct harus sama agar bisa dicopy walaupun isi struct sama persis.

    printf("NRP: %s\nNama: %s\nTempat lahir: %s\nTanggal lahir: %d-%d-%d", mhs2.nrp, mhs2.name, mhs2.tmp_lahir, mhs2.tgl_lahir, mhs2.bln_lahir, mhs2.thn_lahir);
    return 0;
}
*/

typedef struct {
    char name[21];
    double diameter;
    int moons; 
    double orbit_time, rotation_time;
} planet_t;

void printPlanet(planet_t pl) {
    printf("%s\n", pl.name);
    printf("Equatorial diameter: %.0f km\n", pl.diameter);
    printf("Num of moons: %d\n", pl.moons);
}

int main(void) {

}