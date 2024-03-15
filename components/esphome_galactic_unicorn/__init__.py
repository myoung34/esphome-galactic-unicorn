import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

foo_component_ns = cg.esphome_ns.namespace('esphome_galactic_unicorn')
FooComponent = foo_component_ns.class_('FooComponent', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FooComponent),
    cv.Required("message"): cv.string_strict,
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    cg.add(var.set_message(config["message"]))

