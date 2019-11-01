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

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-Macros.h>

#define WI_API_VER "0.0.1" // version of the windows integration api
#define WI_CMD(X) "wi." X

#define WI_CMD_VER WI_CMD("version")
#define WI_CMD_LAYER WI_CMD("layer")
#define WI_CMD_LAYERS WI_CMD("layers") // Layers getter

namespace kaleidoscope {
namespace plugin {

class WindowsIntegration : public kaleidoscope::Plugin {
  public:
    static void enable();
    static void disable();
    static bool active();

    EventHandlerResult onFocusEvent(const char *command);

    EventHandlerResult onSetup();
  private:
    static bool disabled_;
};


}  // namespace plugin
}  // namespace kaleidoscope

extern kaleidoscope::plugin::WindowsIntegration WindowsIntegration;
