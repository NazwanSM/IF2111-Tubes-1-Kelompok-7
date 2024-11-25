#ifndef CONSOLE_H
#define CONSOLE_H

#include "src/ADT/arraydin.h"
#include "src/ADT/list.h"
#include "src/ADT/readTxt.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/custom.h"
#include "src/ADT/boolean.h"
#include "src/ADT/queue.h"
#include "src/start.h"
#include "src/work.h"
#include "src/work_challenge.h"
#include "src/load.h"
#include "src/save.h"
#include "src/help.h"
#include "src/quit.h"
#include "src/register.h"
#include "src/login.h"
#include "src/logout.h"
#include "src/storeList.h"
#include "src/storeRequest.h"
#include "src/storeSupply.h"
#include "src/storeRemove.h"

void displayPurrMart();
void displayWelcomeMenu();
void displayLoginMenu();
void displayMainMenu(List user, int userIdx);

#endif