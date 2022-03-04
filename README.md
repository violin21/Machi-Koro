# Machi Koro

 Machi Koro is a board game made by Pandasaurus© Games. I have decided to code it as a challenge. All rights go to their respective owners, I do not wish to infringe any copyright. If there are any legal issues, please contact me.

## How to Play

Find instructions [here](https://www.dropbox.com/s/ehpxe4aa6n0ee98/P_MK_Rulebook_7418%20%281%29.pdf?dl=0)

## Installation

You will find releases for Ubuntu and Windows on the GitHub page. If your operating system is not included, you can build using CMake.

### CMake installation

Install the source code Zip file from the release of your choice (it doesn't matter whether it is for Ubuntu or Windows) then extract it into a directory. Open a terminal in that directory and run
```
mkdir build && cd build
```
To create and enter the build directory. Once you're there, run
```
cmake .. && make
```
To compile the source code into a new directory called bin in that build directory. Note: the make command works for UNIX operating systems (including Linux). For Windows, use
```
cmake .. && mingw32-make
```

Make sure you have a C compiler installed. If you're on Windows, make sure you have MinGW installed.

## Development

This game is not yet completed and still in version 0.1. It is not yet intended to be played.

### Changelog

Nothing yet!

### Roadmap

No clear plans yet, finish the game core first, the gameplay stuff, then possibly add a GUI. Wait for first release for more info.