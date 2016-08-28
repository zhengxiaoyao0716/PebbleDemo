#include "game/package.h"

#include "game/button.h"
#include "game/frame.h"
#include "game/game.h"


Window* mainWindow;
GRect bounds;

GBitmap *bitmap;
BitmapLayer* bitmapLayer;

static void clickConfigProvider(void *context) {
    window_single_click_subscribe(BUTTON_ID_UP, onClick.up);
    window_single_click_subscribe(BUTTON_ID_DOWN, onClick.down);
    window_single_click_subscribe(BUTTON_ID_BACK, onClick.back);
    window_single_click_subscribe(BUTTON_ID_SELECT, onClick.select);
}

static void onWindowLoad(Window *window) {
    // 配置按键
    window_set_click_config_provider(window, clickConfigProvider);

    // 窗口信息
    Layer *layer = window_get_root_layer(window);
    bounds = layer_get_bounds(layer);

    // bitmap图层
    GRect fromRect = GRect(0, 0, bounds.size.w, bounds.size.h);
    GRect toRect = GRect(0, bounds.size.h, bounds.size.w, bounds.size.h);
    bitmapLayer = bitmap_layer_create(fromRect);

    // bitmap对象
    bitmap = gbitmap_create_with_resource(RESOURCE_ID_MY_LOGO);
    bitmap_layer_set_compositing_mode(bitmapLayer, GCompOpSet);
    bitmap_layer_set_bitmap(bitmapLayer, bitmap);

    // logo动画
    PropertyAnimation *propAnim = property_animation_create_layer_frame((Layer *)bitmapLayer, &fromRect, &toRect);
    Animation *anim = property_animation_get_animation(propAnim);
    const int delay_ms = 1000;
    const int duration_ms = 3000;
    animation_set_curve(anim, AnimationCurveEaseOut);
    animation_set_delay(anim, delay_ms);
    animation_set_duration(anim, duration_ms);
    animation_schedule(anim);

    // 添加图层
    layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(bitmapLayer));
}

static void onWindowUnload(Window *window) {
    if (bitmap != NULL) gbitmap_destroy(bitmap);
    if (bitmapLayer != NULL) bitmap_layer_destroy(bitmapLayer);
    gameLoop.finish();
}

static void init() {
    // 注册时间服务
    tick_timer_service_subscribe(SECOND_UNIT, frame.refresh);

    // 创建窗口
    mainWindow = window_create();
    // 注册窗口事件
    window_set_window_handlers(mainWindow, (WindowHandlers) {
        .load = onWindowLoad,
        .unload = onWindowUnload
    });

    // 显示窗口
    window_stack_push(mainWindow, true);
}

static void deinit() {
    // 销毁窗口
    window_destroy(mainWindow);
}

int main(void) {
    init();
    app_event_loop();
    deinit();
}