# Kaleidoscope-WindowsIntegration

Keyboard plugin which add capabilities to communicate with WindowsIntegration tool #TODO: add link

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


