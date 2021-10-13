# Buttermilk Terminal Emulator
This is a basic personal terminal emulator using the VTE library.

<!-- START doctoc.sh generated TOC please keep comment here to allow auto update -->
<!-- DO NOT EDIT THIS SECTION, INSTEAD RE-RUN doctoc.sh TO UPDATE -->
**Table of Contents**

- [Key bindings:](#key-bindings)
- [Installation](#installation)
- [Configuration](#configuration)
- [Terminal cloning](#terminal-cloning)
- [Credits](#credits)

<!-- END doctoc.sh generated TOC please keep comment here to allow auto update -->

## Key bindings:
Buttermilk features only a few simple keybindings, which are optimized for the default English keyboard layout:
* `Ctrl+Shift+plus` - make the font bigger
* `Ctrl+minus` - make the font smaller
* `Ctrl+equals` - reset the font size
* `Ctrl+return` - launch new instance (also take a look at [Terminal cloning](#terminal-cloning))


## Installation
Just run the following command inside project folder:
```sh
sudo make install clean
```


## Configuration
To print out your current configuration use `buttermilk -c`.
The global config file should be in `/etc/buttermilk.conf`, the user config file in `~/.config/buttermilk/buttermilk.conf`.

You can initially create a config file for your user, by first creating the according directory and
then writing the default configuration into the config file:
```sh
mkdir ~/.config/buttermilk
buttermilk -c > ~/.config/buttermilk/buttermilk.conf
```

## Terminal cloning
You can clone the terminal with `Ctrl+Enter`, but in order to keep the current working directory you have to source `vte.sh`.
On Arch Linux it is located at `/etc/profile.d/vte.sh` and you can source it in your `~/.profile` for example.


## Credits
This program is based on a tutorial by Vincent Bernat: "[Writing your own terminal emulator](https://vincent.bernat.ch/en/blog/2017-write-own-terminal)"
I also took borrowed some code from his own implementation of a VTE terminal emulator, called [vbeterm](https://github.com/vincentbernat/vbeterm).

[VTE documentation](https://developer-old.gnome.org/vte/unstable/VteTerminal.html)
