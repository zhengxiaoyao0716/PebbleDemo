#include "frame.h"

#include "game.h"

static int timeAxis = 0;
static void refresh(struct tm *tick_time, TimeUnits units_changed) {
    timeAxis++;
    if (timeAxis % 3 == 0) {
        gameLoop.start();
    
        gbitmap_destroy(bitmap);
        layer_remove_from_parent((Layer *)bitmapLayer);
        bitmap_layer_destroy(bitmapLayer);
    }
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Time ticked: %d", timeAxis);
}

Frame frame = {
    refresh
};
