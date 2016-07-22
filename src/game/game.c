#include "game.h"


bool running = false;

TextLayer* textLayer;

static void start() {
    running = true;

    GRect gRect = GRect(0, 0, bounds.size.w, bounds.size.h);
    textLayer = text_layer_create(gRect);
}
static void update(int timeAxis) {
}
static void finish() {
    running = false;

    text_layer_destroy(textLayer);
}
static bool isRunning() {return running;}

GameLoop gameLoop = {
    start, update, finish
};
