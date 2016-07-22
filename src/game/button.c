#include "button.h"

static void onUpClick(ClickRecognizerRef recognizer, void *context) {
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Up button clicked");
}
static void onDownClick(ClickRecognizerRef recognizer, void *context) {
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Down button clicked");
}
static void onBackClick(ClickRecognizerRef recognizer, void *context) {
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Back button clicked");
}
static void onSelectClick(ClickRecognizerRef recognizer, void *context) {
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Select button clicked");
}

OnClick onClick = {
    onUpClick, onDownClick, onBackClick, onSelectClick
};