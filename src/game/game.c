#include "game.h"

#include "board.h"


bool running = false;

TextLayer* textLayer;

GFont font;

static void start() {
    running = true;

    GRect gRect = GRect(0, 0, bounds.size.w, bounds.size.h);
    textLayer = text_layer_create(gRect);
    layer_add_child(window_get_root_layer(mainWindow), text_layer_get_layer(textLayer));

    font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_MONACO_12));
    text_layer_set_font(textLayer, font);
    text_layer_set_text_alignment(textLayer, GTextAlignmentCenter);

    board.begin();
}

static void update(int timeAxis) {
    time_t temp = time(NULL);
    struct tm *tickTime = localtime(&temp);
    strftime(board.timeStr, sizeof(board.timeStr), clock_is_24h_style() ? "%H:%M" : "%I:%M", tickTime);
    
    strcpy(board.content, board.boardStr);
    strcat(board.content, board.timeStr);
    text_layer_set_text(textLayer, board.content);
}
static void finish() {
    running = false;

    text_layer_destroy(textLayer);
    textLayer = NULL;
}
// static bool isRunning() {return running;}

GameLoop gameLoop = {
    start, update, finish
};
