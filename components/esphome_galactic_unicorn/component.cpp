#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pico/stdlib.h"

#include "pico_graphics.hpp"
#include "galactic_unicorn.hpp"
//#include "okcolor.hpp"


#include "esphome/core/log.h"
#include "esphome/core/application.h"
#include "foo_component.hpp"


extern uint8_t left_channel_bin[];
extern uint32_t left_channel_bin_len;
extern uint8_t right_channel_bin[];
extern uint32_t right_channel_bin_len;

using namespace pimoroni;

int width = 53;
int height = 11;

PicoGraphics_PenRGB888 graphics(width, height, nullptr);
GalacticUnicorn galactic_unicorn;

float buffer[53][11];
float age[53][11];

namespace esphome {
namespace esphome_galactic_unicorn {

static const char *TAG = "galactic_unicorn.component";

bool landscape = true;
float scroll = -53.0f;
std::string display_message = "Pirate. Monkey. Robot. Ninja.";


void FooComponent::set_message(std::string message) {
  display_message = message;
}

void FooComponent::setup() {
  //stdio_init_all();
  ESP_LOGCONFIG(TAG, "Setup");

  galactic_unicorn.init();
  galactic_unicorn.set_brightness(0.5);
}

void FooComponent::loop() {
    int width = graphics.measure_text(display_message, 1);
    scroll += 0.25f;

    if(scroll > width) {
      scroll = -53.0f;
    }

    graphics.set_pen(0, 0, 0);
    graphics.clear();

    //ok_color::HSL hsl{scroll / 100.0f, 1.0f, 0.5f};
    //ok_color::RGB rgb = ok_color::okhsl_to_srgb(hsl);
    //graphics.set_pen(rgb.r * 255, rgb.g * 255, rgb.b * 255);
    graphics.set_pen(230, 150, 0);
    graphics.text(display_message, Point(0 - scroll, 2), -1, 0.55);
    galactic_unicorn.update(&graphics);

    sleep_ms(10);

}

void FooComponent::dump_config(){
    ESP_LOGCONFIG(TAG, "Foo component");
}


}  // namespace empty_component
}  // namespace esphome
