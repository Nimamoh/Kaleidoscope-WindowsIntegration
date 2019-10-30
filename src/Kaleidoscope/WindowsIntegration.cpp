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

namespace kaleidoscope {
namespace plugin {

// WindowsIntegration

// Member variables.
bool WindowsIntegration::disabled_ = false;

// Basic plugin status functions.

// Enable the plugin.
void WindowsIntegration::enable() {
  disabled_ = false;
}

// Disable the plugin.
void WindowsIntegration::disable() {
  disabled_ = true;
}

// Returns true if the plugin is enabled.
bool WindowsIntegration::active() {
  return !disabled_;
}

// Event handlers.

// Runs once, when the plugin is initialized during Kaleidoscope.setup().
EventHandlerResult WindowsIntegration::onSetup() {
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run as the first thing at the start of each cycle.
EventHandlerResult WindowsIntegration::beforeEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run for every non-idle key, in each cycle the key isn't idle in. If a key
// gets pressed, released, or is held, it is not considered idle, and this
// event handler will run for it too.
EventHandlerResult WindowsIntegration::onKeyswitchEvent(Key &mapped_key, byte row,
                                              byte col, uint8_t key_state) {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs each cycle right before sending the various reports (keys pressed, mouse
// events, etc) to the host.
EventHandlerResult WindowsIntegration::beforeReportingState() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs at the very end of each cycle.
EventHandlerResult WindowsIntegration::afterEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

}  // namespace plugin
}  // namespace kaleidoscope

kaleidoscope::plugin::WindowsIntegration WindowsIntegration;
