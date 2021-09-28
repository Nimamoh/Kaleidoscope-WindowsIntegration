// -*- mode: c++ -*-
// Kaleidoscope-WindowsIntegration -- Third party plugin for the windows integration tool
// Copyright (C) 2019 Nimamoh
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <Kaleidoscope-WindowsIntegration.h>

namespace kaleidoscope
{
namespace plugin
{

/** bernstein hash function */
constexpr uint8_t hash(const char *str, uint8_t offset = 0)
{
  return !str[offset] ? 5381 : (hash(str, offset + 1) * 33) ^ str[offset];
}

void echo(const char *command)
{
  ::Focus.send(command);
  ::Focus.send("\n");
}

bool WindowsIntegration::disabled_ = false;

void WindowsIntegration::enable() { disabled_ = false; }
void WindowsIntegration::disable() { disabled_ = true; }
bool WindowsIntegration::active() { return !disabled_; }

EventHandlerResult WindowsIntegration::onFocusEvent(const char *command)
{

  if (::Focus.handleHelp(command, PSTR(WI_CMD_VER))
    && ::Focus.handleHelp(command, PSTR(WI_CMD_LAYER))
    && ::Focus.handleHelp(command, PSTR(WI_CMD_LAYERS))) {
    return EventHandlerResult::OK;
  }

  switch (hash(command))
  {
  case hash(WI_CMD_VER):

    ::Focus.send(WI_API_VER);
    break;

  case hash(WI_CMD_LAYER):

    if (::Focus.isEOL()) {
      // ::Focus.send("Top active layer: ");
      ::Focus.send(Layer.mostRecent());
      break;
    }

    uint8_t layer_n;
    ::Focus.read(layer_n);

    if (::Focus.isEOL()) {
      // ::Focus.send("Layer is active: ");
      ::Focus.send(Layer.isActive(layer_n));
      break;
    }

    uint8_t state;
    ::Focus.read(state);
    if (state) {
      // ::Focus.send("Activate layer "); 
      Layer.activate(layer_n);
    } else {
      // ::Focus.send("Deactivate layer "); 
      Layer.deactivate(layer_n);
    }
    break;

  case hash(WI_CMD_LAYERS):
    ::Focus.send(layer_count);
    break;
  default:

    return EventHandlerResult::OK;
    break;
  }

  return EventHandlerResult::EVENT_CONSUMED;
}

EventHandlerResult WindowsIntegration::onSetup()
{
  return EventHandlerResult::OK;
}

} // namespace plugin
} // namespace kaleidoscope

kaleidoscope::plugin::WindowsIntegration WindowsIntegration;
