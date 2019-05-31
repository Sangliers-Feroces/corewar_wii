
Yup.
This a little graphical bonus for our corewar, running on both GameCube and Wii.



# Build instructions:

It comes precompiled (.elf on the root).

In case you want to build it yourself (or just modify it), you'll need
the PowerPC devkitPro, aka devkitPPC (free toolchain).



# How to run:

## On a Wii:
You'll need a Wii with the Homebrew Channel to run it on actual hardware.
There are plenty of exploits on Internet to install it on your system.

### SD card structure
* Create a folder `corewar` in the common Homebrew `apps` folder
* Copy the .elf binary (corewar_wii.elf in this repo) in this folder
  as `boot.elf`
* Copy your compiled champions (.cor) in the folder `apps/corewar/champions`


## On an emulator (Dolphin)
Just launch the .elf binary with Dolphin.

The tricky part is when it comes to copy your champions on the SD card.
Under Linux, you can mount the virtual SD card, create the folder
`apps/corewar/champions` and then copy your champions
(the SD image location can be found in Settings -> Paths -> SD Card Path).


## On a GameCube
Like for the Wii, your system needs to have homebrew capabilities.
https://www.reddit.com/r/Gamecube/comments/40u3d6/sd_media_launchersd_gecko_and_homebrew_set_up/
Once you're done, copy the .dol of this repo in your NGC SD card.


# How to play:

You'll need a GameCube controller on the Wii, as for the GameCube (obviously).
If you wish yo play it on a Wii and you don't have one, well it's time to
buy one and discover the awesome NGC library ^^
It can be configured virtually under Dolphin out of any existing controller.

## On the core section:
* Main stick: Move the camera
* C stick: Look around
* X: Enter the champions menu
* Start: Quit the game

## Champions menu
* D-pad: Select a champion
* A: Instanciate it
* B: Clean the core
* X: Go back to the core
