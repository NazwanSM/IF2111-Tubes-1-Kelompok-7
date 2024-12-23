#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q){
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullQueue(Queue q){
    return IDX_TAIL(q) == CAPACITY -1;
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthQueue(Queue q){
    if (isEmptyQueue(q)){
        return 0;
    }
    else if (IDX_TAIL(q)<IDX_HEAD(q)){
        return CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
    }
    else{
        return IDX_TAIL(q)-IDX_HEAD(q)+1;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypeQ val){
    if (isEmptyQueue(*q)){
        IDX_HEAD(*q)=0; 
        IDX_TAIL(*q)=0;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q)+1) % CAPACITY;
    }
    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElTypeQ *val){
    *val = HEAD(*q);
    if (IDX_HEAD(*q)==IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = (IDX_HEAD(*q)+1) % CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q){
    printf("[");
    if (!isEmptyQueue(q)){
        if (IDX_HEAD(q)<=IDX_TAIL(q)){
            for (int i=IDX_HEAD(q); i<IDX_TAIL(q); i++){
                printf("%d %s,", q.buffer[i].price, q.buffer[i].name);
            }
        }
        else{
            for (int i=IDX_HEAD(q); i<=CAPACITY-1; i++){
                printf("%d %s,", q.buffer[i].price, q.buffer[i].name);
            }
            for (int i=0; i<IDX_TAIL(q); i++){
                printf("%d %s,", q.buffer[i].price, q.buffer[i].name);
            }
        }
    }
    printf("%d %s]\n", q.buffer[IDX_TAIL(q)].price, q.buffer[IDX_TAIL(q)].name);
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

boolean searchQueue(Queue q, ElTypeQ val) {
    int i;
    for (i = 0; i <= IDX_TAIL(q); i++) {
        if (myStrcmp(q.buffer[i].name, val.name) == 0) {
            return true;
        }
    }
    return false; 
}