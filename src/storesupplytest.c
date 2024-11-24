#include <stdio.h>
#include <stdlib.h>

#include "start.h"
#include "save.h"
#include "load.h"
#include "storeList.h"

void storesupply(ArrayDin *barang, Queue *antrian, int *nbarang) {
    while (!(isEmptyQueue(*antrian))) {
        elType pilihan;
        ElTypeQ x;

        // Print the name of the first item in the queue
        printf("Apakah kamu ingin menambahkan barang %s (terima/tolak): ", antrian->buffer[0].name);

        // Handle user input for the next item
        START();
        char item[100] = {0};
        int itemLen = 0;
        while (currentChar != '\n' && itemLen < 100 - 1) {
            item[itemLen++] = currentChar;
            READADV();
        } 
        item[itemLen] = '\0';

        // Copy the user input to pilihan.name
        manualStrcpy(pilihan.name, item);

        // Check user input ("terima" or "tolak")
        if (myStrcmp(pilihan.name, "terima") == 0) {
            // Ask for the price and assign it to the item
            printf("Masukkan harga barang: ");
            int price;
            scanf("%d", &price);

            // Set the price for the item
            pilihan.price = price;

            // Insert the item into ArrayDin `barang`
            insertAt(barang, antrian->buffer[0], barang->Neff);  // Add at the first empty index

            // Remove the item from the queue after adding to ArrayDin
            dequeue(antrian, &x);  

            printf("Barang diterima dan dimasukkan ke dalam ArrayDin dengan harga %d.\n", price);
        } else if (myStrcmp(pilihan.name, "tolak") == 0) {
            // Put the item back at the tail of the queue
            enqueue(antrian, antrian->buffer[0]);
            dequeue(antrian, &x);  // Remove it from the front of the queue
            printf("Barang ditolak dan dimasukkan kembali ke antrian.\n");
        } else {
            printf("Input tidak dikenali. Silakan coba lagi.\n");
        }
    }

    // After the loop, check if the queue is empty
    if (isEmptyQueue(*antrian)) {
        printf("Queue is empty.\n");
    }
}

int main() {
    ArrayDin barang = MakeArrayDin();  // Create your ArrayDin
    int nbarang;

    // Initialize the data
    start("../save/config.txt", &barang, NULL, &nbarang, NULL);

    // Define an empty queue
    Queue antrian;
    CreateQueue(&antrian); // Create the queue first

    // Initialize the queue element (first item) with "hehe" and set some price
    ElTypeQ val;
    manualStrcpy(val.name, "hehe");  // Manually copy "hehe" to val.name
    val.price = 150;  // Set price as example

    // Enqueue the item
    enqueue(&antrian, val);

    // Call the storesupply function to process the queue
    storesupply(&barang, &antrian, &nbarang);

    // Print the result after processing the queue
    if (!isEmptyQueue(antrian)) {
        printf("Remaining item in queue: %s\n", antrian.buffer[0].name);  // Print the full name
    } else {
        printf("Queue is empty.\n");
    }

    // Optionally, print out all the items in ArrayDin
    for (int i = 0; i < barang.Neff; i++) {
        printf("Barang %d: %s, Price: %d\n", i, barang.A[i].name, barang.A[i].price);
    }

    return 0;
}