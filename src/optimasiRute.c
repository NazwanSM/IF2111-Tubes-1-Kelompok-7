#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "optimasiRute.h"

void initGraph(Graph* g, int nodes) {
    g->nodes = nodes;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest, int weight) {
    g->matrix[src][dest] = weight;
    g->matrix[dest][src] = weight;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

boolean nextPermutation(int* arr, int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i < 0) return false;
    
    int j = n - 1;
    while (arr[j] <= arr[i]) j--;
    
    swap(&arr[i], &arr[j]);
    
    for (int l = i + 1, r = n - 1; l < r; l++, r--) {
        swap(&arr[l], &arr[r]);
    }
    return true;
}

void findBestPath(Graph* g) {
    int n = g->nodes;
    int vertices[MAX_NODES-1];
    int currentPath[MAX_NODES];
    int bestPath[MAX_NODES];
    int bestDist = INF;
    
    for (int i = 1; i < n; i++) {
        vertices[i-1] = i;
    }
    
    do {
        currentPath[0] = 0;
        for (int i = 0; i < n-1; i++) {
            currentPath[i+1] = vertices[i];
        }
        
        int dist = 0;
        boolean valid = true;
        
        for (int i = 0; i < n-1; i++) {
            if (g->matrix[currentPath[i]][currentPath[i+1]] == 0) {
                valid = false;
                break;
            }
            dist += g->matrix[currentPath[i]][currentPath[i+1]];
        }
        
        if (valid && dist < bestDist) {
            bestDist = dist;
            for (int i = 0; i < n; i++) {
                bestPath[i] = currentPath[i];
            }
        }
    } while (nextPermutation(vertices, n-1));
    
    printf(COLOR_BOLD_BLUE"\nA-ha!"COLOR_OFF" Rute paling efektif adalah ");
    for (int i = 0; i < n; i++) {
        printf(COLOR_BOLD_BLUE"%d"COLOR_OFF, bestPath[i]);
        if (i < n-1) printf("-");
    }
    printf(" dengan total jarak "COLOR_BOLD_RED"%d.\n"COLOR_OFF, bestDist);
}

boolean isValidInput(int value) {
    return value > 0;
}

void optimasiRute() {
    Graph g;
    int nodes, edges;


    printf("\nMasukkan jumlah lokasi pengiriman "COLOR_CYAN"(node)"COLOR_OFF": ");
    if (scanf("%d", &nodes) != 1 || !isValidInput(nodes)) {
        printf(COLOR_BOLD_RED"Input tidak valid! Jumlah lokasi harus berupa angka positif.\n"COLOR_OFF);
        return;
    }


    printf("Masukkan jumlah rute "COLOR_CYAN"(edge)"COLOR_OFF": ");
    if (scanf("%d", &edges) != 1 || !isValidInput(edges)) {
        printf(COLOR_BOLD_RED"Input tidak valid! Jumlah rute harus berupa angka positif.\n"COLOR_OFF);
        return ;
    }


    initGraph(&g, nodes);


    printf("Masukkan jarak antarlokasi "COLOR_CYAN"(weight)"COLOR_OFF":\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;

        if (scanf("%d %d %d", &src, &dest, &weight) != 3 || 
            src < 0 || src >= nodes || 
            dest < 0 || dest >= nodes || 
            weight <= 0) {
            printf(COLOR_BOLD_RED"Input tidak valid! Pastikan:\n"COLOR_OFF);
            printf("- Lokasi asal (src) dan tujuan (dest) adalah indeks yang valid (0 hingga %d).\n", nodes - 1);
            printf("- Berat (weight) adalah angka positif.\n");
            return;
        }

        addEdge(&g, src, dest, weight);
    }

    printf("\nData diterima, silakan tunggu...\n");
    struct timespec req = {1, 0};
    nanosleep(&req, NULL);

    findBestPath(&g);

}