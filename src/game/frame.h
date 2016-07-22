#ifndef __FRAME_H
#define __FRAME_H

#include "package.h"

typedef struct {
    void (* refresh)(struct tm *tick_time, TimeUnits units_changed);
} Frame;
extern Frame frame;

#endif