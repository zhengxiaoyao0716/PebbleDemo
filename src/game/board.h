#ifndef __BOARD_H
#define __BOARD_H

#include "package.h"

typedef struct {
    char content[128];
    char timeStr[8];
    char boardStr[120];
    void (* begin)();
    void (* trigger)(char action);
} Board;
extern Board board;

#endif