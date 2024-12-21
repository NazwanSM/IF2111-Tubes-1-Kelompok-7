#ifndef OPTIMASI_RUTE_H
#define OPTIMASI_RUTE_H

#define MAX_NODES 100
#define INF 999999

#include "ADT/boolean/boolean.h"
#include "ADT/custom/custom.h"

// Struktur untuk graph
typedef struct {
    int nodes;
    int matrix[MAX_NODES][MAX_NODES];
} Graph;

// Struktur untuk rute
typedef struct {
    int distance;
    int prev;
} Route;

// Fungsi-fungsi dasar graph
void initGraph(Graph* g, int nodes);
void addEdge(Graph* g, int src, int dest, int weight);
void findBestPath(Graph* g);
boolean nextPermutation(int* arr, int n);
void swap(int* a, int* b);
boolean isValidInput(int value);
void optimasiRute();


#endif