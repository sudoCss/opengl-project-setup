# OpenGL Project setup for Arch linux & VSCode

Project setup for modern OpenGL (v3.0+) projects in C++ (Arch linux & Visual Studio Code project) for University.

This should work on any Arch derivatives (Manjaro, EndeavourOS, Archbang, etc...)

It Uses OpenGl, glew, and glfw

## Instructions

Designed to be edited and run with Visual Studio Code.

Install [Visual Studio Code](https://code.visualstudio.com), then follow the per-platform instructions below.

(Recommended) Install these plugins for VSCode:

- C/C++ Intellisense/debugging by Microsoft 

Afterwards, clone this repository and follow the per-platform instructions below.

Then, open this repository's root folder in Visual Studio Code and press Ctrl+Shift+B to build & run.

Or alternatively in VSCode click Terminal -> Task -> Run Task -> 'build & run opengl-app'

Then(if already built), to run, in VSCode click Terminal -> Task -> Run Task -> 'run opengl-app'

OR

```bash
./build/opengl-app
```

### Requirements  

The Arch software repos have up-to-date versions of all dependencies.

```
sudo pacman -Syyu
sudo pacman -S gcc gdb glew glfw-x11
```

Building should now work 😄



## A shout out & A big thank you to [mmowbray](https://github.com/mmowbray)
I used [this repo](https://github.com/mmowbray/opengl-starting-point) as a reference.