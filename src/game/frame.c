#include "frame.h"

#include "game.h"

static int timeAxis = -3;
static void refresh(struct tm *tick_time, TimeUnits units_changed) {
    timeAxis++;
    if (timeAxis > 0) {
        gameLoop.update(timeAxis);
    } else if (timeAxis == 0) {
        gameLoop.start();
    
        gbitmap_destroy(bitmap);
        layer_remove_from_parent((Layer *)bitmapLayer);
        bitmap_layer_destroy(bitmapLayer);
        bitmap = NULL;
        bitmapLayer = NULL;
    }
}

Frame frame = {
    refresh
};
