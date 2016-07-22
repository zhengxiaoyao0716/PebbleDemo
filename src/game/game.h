#ifndef __GAME_H
#define __GAME_H

#include "package.h"

typedef struct {
    void (* start)();
    void (* update)(int timeAxis);
    void (* finish)();
} GameLoop;
extern GameLoop gameLoop;

#endif