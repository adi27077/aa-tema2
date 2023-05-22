#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

/*variabilele in care se retin nr de noduri, matricea de adiacenta,
nodurile din clica, gradele nodurilor, si variabilda found daca
s-a gasit sau nu o clica de dimensiunea specificata*/
int n, graph[MAX][MAX]={0}, clique[MAX], degrees[MAX]={0}, found;

/*functie care verifica daca nodurile din clique formeaza
intr-adevar o clica*/
int checkClique(int b) {
    int i, j;
    for (i = 1; i < b; i++) {
        for (j = i + 1; j < b; j++) {
            if (graph[clique[i]][clique[j]] == 0)
                return 0;
        }
    }
    return 1;
}

/*functie recursiva cara cauta clica de dimensiunea specificata,
pornind de la nodul specificat*/
void findkClique(int i, int j, int k) {
    int l;
    /*pornim de la nodul specificat si trecem prin toate
    nodurile ramase*/
    for(l = i + 1; l <= n - (k - j); l++) {
        /*daca gradul nodului curent este >= cu dimensiunea clicii -1,
        inseamna ca acesta ar putea face parte din clica*/
        if(degrees[l] >= k - 1) {
            /*adaugam nodul in vectorul ce contine nodurile din clica*/
            clique[j] = l;
            /*verificam daca nodurile din clique formeaza o clica*/
            if(checkClique(j + 1)) {
                /*daca inca nu am ajuns cu pasul de recursivitate
                la dimensiunea clicii, mergem mai departe*/
                if(j < k) {
                    findkClique(l, j + 1, k); 
                }
                /*am gasit o clica de dimensiune specificata*/
                else {
                    found = 1;
                }    
            } 
        }
    }
}


int main(int argc, char* argv[]) {
    char *fileName = argv[1];
    FILE *f = fopen(fileName, "rt");
    int i, m, k, edge[MAX][2];
    found = 0;
    char line[MAX];
    int l = MAX;

    /*citire dim clica, nr de noduri si nr de muchii din fisier*/
    fgets(line, l, f);
    k = atoi(line);
    fgets(line, l, f);
    n = atoi(line);
    fgets(line, l, f);
    m = atoi(line);

    /*citire muchii din fisier*/
    for(i = 0; i < m; i++) {
        fgets(line, l, f);
        edge[i][0] = atoi(strtok(line, " "));
        edge[i][1] = atoi(strtok(NULL, " "));
    }
    
    /*creare matrice de adiacenta pe baza muchiilor citite*/
    for(i = 0; i < m; i++) {
        graph[edge[i][0]][edge[i][1]] = 1;
        graph[edge[i][1]][edge[i][0]] = 1;
        degrees[edge[i][0]]++;
        degrees[edge[i][1]]++;
    }

    /*gasire clica*/
    findkClique(0, 1, k);

    if(found == 1)
        printf("True");
    else
        printf("False");

    fclose(f);

    return 0;
}