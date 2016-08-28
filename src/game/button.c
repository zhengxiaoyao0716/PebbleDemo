#include "button.h"

#include "board.h"


static void onUpClick(ClickRecognizerRef recognizer, void *context) {
    board.trigger('2');
}
static void onDownClick(ClickRecognizerRef recognizer, void *context) {
    board.trigger('8');
}
static void onBackClick(ClickRecognizerRef recognizer, void *context) {
    board.trigger('4');
}
static void onSelectClick(ClickRecognizerRef recognizer, void *context) {
    board.trigger('6');
}

OnClick onClick = {
    onUpClick, onDownClick, onBackClick, onSelectClick
};