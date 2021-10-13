# Buttermilk Terminal Emulator
This is a basic personal terminal emulator using the VTE library.


## Terminal cloneing
You can clone the terminal with `Ctrl+Enter`, but in order to keep the current working directory you have to source `vte.sh`.
On Arch Linux it is located at `/etc/profile.d/vte.sh` and you can source it in your `~/.profile` for example.

## Credits
This program is based on a tutorial by Vincent Bernat: "[Writing your own terminal emulator](https://vincent.bernat.ch/en/blog/2017-write-own-terminal)"
I also took borrowed some code from his own implementation of a VTE terminal emulator, called [vbeterm](https://github.com/vincentbernat/vbeterm).
