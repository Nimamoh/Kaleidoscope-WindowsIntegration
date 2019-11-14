# Kaleidoscope-WindowsIntegration

Keyboard plugin which add capabilities to communicate with [Kaleidoscope Companion tool](https://github.com/Nimamoh/Kaleidoscope-WindowsIntegration-Client)

## How to install
This is a third party plugin, follow these [instructions](https://github.com/keyboardio/Kaleidoscope/wiki/Installing-Plugins#installing-third-party-plugins) from the official kaleidoscope documentation.

Then, modify your sketch to include the plugin and add it to `KALEIDOSCOPE_INIT_PLUGINS`

```cpp
#include "Kaleidoscope-WindowsIntegration.h"

...
KALEIDOSCOPE_INIT_PLUGINS(
  ...
  WindowsIntegration
  ...
);
...
```
Don't forget to compile and flash your firmware.

### How do I check the plugin is correctly setup
Open a serial monitor tool to connect to your model 01 (arduino IDE has one under `Tools > Serial Monitor`). 

Then type the `wi.version` request, you should get the plugin version as an answer:

> ```
> wi.version
> 0.0.1
> .
> ```


## Focus commands
This plugin uses [Focus](https://github.com/keyboardio/Kaleidoscope/blob/master/doc/plugin/FocusSerial.md) extensively. It adds these commands:

### `wi.version`

> Shows the version of WindowsIntegration API installed on the keyboard

### `wi.layer <layer_number: n> <active_flag: 0|1>` 

> Without argument, prints the top active layer number. e.g:
>
> ```
> < wi.layer
> > 0
> ```
>
> When providing a layer number, return `true` if layer active, `false` otherwise. e.g:
>
> ```
> < wi.layer 3
> > false
> ```
>
> When providing both layer number and active flag, enable/disable layer (`0` disables the layer, `1` enable the layer). e.g:
> 
> ```
> < wi.layer 3 1 #Enables the third layer
> ``` 
> ```
> < wi.layer 2 0 #Disables the second layer
> ``` 

### `wi.layers`

> Prints the total layers count


