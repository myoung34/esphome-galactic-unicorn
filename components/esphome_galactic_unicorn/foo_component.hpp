#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace esphome_galactic_unicorn {

class FooComponent : public Component {
 public:
  void set_message(std::string message);
  void setup() override;
  void loop() override;
  void dump_config() override;
};


}  // namespace foo_component
}  // namespace esphome
