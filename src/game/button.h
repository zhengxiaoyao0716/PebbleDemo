#ifndef __BUTTON_H
#define __BUTTON_H

#include "package.h"

typedef struct {
    void (* up)(ClickRecognizerRef recognizer, void *context);
    void (* down)(ClickRecognizerRef recognizer, void *context);
    void (* back)(ClickRecognizerRef recognizer, void *context);
    void (* select)(ClickRecognizerRef recognizer, void *context);
} OnClick;
extern OnClick onClick;

#endif