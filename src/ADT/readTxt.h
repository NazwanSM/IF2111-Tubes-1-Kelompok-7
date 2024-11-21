#ifndef __READTXT_H__
#define __READTXT_H__

#include "mesinkarakter_readtxt.h"
#include "mesinkata_readtxt.h"
#include "custom.h"
#include "arraydin.h"
#include "list.h"

void manualStrcpy(char *dest, const char *source);

void readtxt(char *filename, ArrayDin *barang, List *user, int nbarang, int nuser);


#endif