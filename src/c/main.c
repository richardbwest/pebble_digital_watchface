#include <pebble.h>
#include <time.h>

// Main window pointer
static Window *s_main_window;
// Text layers for time, date, and battery display
static TextLayer *s_time_layer;
static TextLayer *s_date_layer;
static TextLayer *s_battery_layer;

// Update the time, date, and battery text layers
static void update_time() {
  // Get current time
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  // Buffers for formatted text
  static char buffer[] = "00:00";
  static char date_buffer[] = "Mon 01 Jan";
  static char battery_buffer[] = "100%";

  // Format time based on 24h or 12h user preference
  if(clock_is_24h_style() == true) {
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
  }

  // Update time layer
  text_layer_set_text(s_time_layer, buffer);

  // Format and update date layer
  strftime(date_buffer, sizeof(date_buffer), "%a %d %b", tick_time);
  text_layer_set_text(s_date_layer, date_buffer);

  // Retrieve battery state
  BatteryChargeState charge_state = battery_state_service_peek();
  snprintf(battery_buffer, sizeof(battery_buffer), "%d%%", charge_state.charge_percent);

  // Update battery layer
  text_layer_set_text(s_battery_layer, battery_buffer);
}

// Tick handler runs once per minute due to subscription
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

// Battery state change handler
static void battery_handler(BatteryChargeState charge_state) {
  static char battery_buffer[] = "100%";
  snprintf(battery_buffer, sizeof(battery_buffer), "%d%%", charge_state.charge_percent);
  text_layer_set_text(s_battery_layer, battery_buffer);
}

// Runs when the main window is being created
static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // Create and configure the time layer
  s_time_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(58, 52), bounds.size.w, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Create and configure the date layer
  s_date_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(110, 104), bounds.size.w, 25));
  text_layer_set_background_color(s_date_layer, GColorClear);
  text_layer_set_text_color(s_date_layer, GColorBlack);
  text_layer_set_text(s_date_layer, "Mon 01 Jan");
  text_layer_set_font(s_date_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);

  // Create and configure the battery layer
  s_battery_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(140, 134), bounds.size.w, 20));
  text_layer_set_background_color(s_battery_layer, GColorClear);
  text_layer_set_text_color(s_battery_layer, GColorBlack);
  text_layer_set_text(s_battery_layer, "100%");
  text_layer_set_font(s_battery_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_battery_layer, GTextAlignmentCenter);

  // Add text layers to the window
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_date_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_battery_layer));
}

// Runs when the main window is destroyed
static void main_window_unload(Window *window) {
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_date_layer);
  text_layer_destroy(s_battery_layer);
}

// App initialization
static void init() {
  s_main_window = window_create();

  // Set handlers for window lifecycle
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Display the window
  window_stack_push(s_main_window, true);

  // Subscribe to minute ticks
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  // Subscribe to battery state changes
  battery_state_service_subscribe(battery_handler);

  // Ensure everything is displayed immediately
  update_time();
}

// App shutdown
static void deinit() {
  window_destroy(s_main_window);
}

// Entry point
int main(void) {
  init();
  app_event_loop();
  deinit();
}

