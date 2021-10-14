# Buttermilk Terminal Emulator
This is a basic personal terminal emulator using the VTE library.

<!-- START doctoc.sh generated TOC please keep comment here to allow auto update -->
<!-- DO NOT EDIT THIS SECTION, INSTEAD RE-RUN doctoc.sh TO UPDATE -->
**Table of Contents**

- [Key bindings](#key-bindings)
- [Installation](#installation)
  - [Arch, Manjaro, etc.](#arch-manjaro-etc)
  - [From source](#from-source)
- [Configuration](#configuration)
- [Terminal cloning](#terminal-cloning)
- [Credits](#credits)

<!-- END doctoc.sh generated TOC please keep comment here to allow auto update -->

## Key bindings
Buttermilk features only a few simple keybindings, which are optimized for the default English keyboard layout:
* `Ctrl+Shift+plus` - make the font bigger
* `Ctrl+minus` - make the font smaller
* `Ctrl+equals` - reset the font size
* `Ctrl+return` - launch new instance (also take a look at [Terminal cloning](#terminal-cloning))


## Installation

### Arch, Manjaro, etc.
If you are on Arch, Manjaro or another distro that supports the AUR you can install this
software directly from there.
It is available as `buttermilk`.
If you are using yay:
```sh
yay -S buttermilk
```
otherwise:
```sh
git clone https://aur.archlinux.org/buttermilk.git
cd buttermilk
makepkg -si
```


### From source
Installation should be fairly simple on other distros as well.
First make sure you have the dependencies (namely `vte` and `libinih`) installed.
Then clone the repository and run the following make command inside project folder:
```sh
git clone https://github.com/jzbor/buttermilk
cd buttermilk
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
You can clone the terminal with `Ctrl+Enter`, but in order to keep the current working directory `vte.sh` has to be loaded.
On Arch Linux it is located at `/etc/profile.d/vte.sh`.
If it is not loaded automatically you can try adding this line to your `.bashrc`/`.zshrc`:
```sh
[ -f "/etc/profile.d/vte.sh" ] && . /etc/profile.d/vte.sh
```


## Credits
This program is based on a tutorial by Vincent Bernat: "[Writing your own terminal emulator](https://vincent.bernat.ch/en/blog/2017-write-own-terminal)".
I also took borrowed some code from his own implementation of a VTE terminal emulator, called [vbeterm](https://github.com/vincentbernat/vbeterm).

[VTE documentation](https://developer-old.gnome.org/vte/unstable/VteTerminal.html)
