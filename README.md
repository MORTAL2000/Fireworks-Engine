<p align="center">
  <img width=400" src="https://github.com/Pikachuxxxx/Fireworks-Engine/blob/master/fireworks%20logo.png">
</p>
<h1 align="center"> Fireworks Engine </h1>

<p align="center">
<h3 align="center">A Lightweight Sandbox Game Engine using OpenGL for additional Customisation and Quick Prototyping.</h3>
</p>

<p align="center">
  <a href="Building">Building</a> |
  <a href="Features">Features</a> |
  <a href="Dependencies">Dependencies</a>
<br/>
<br/>
<a href="https://actions-badge.atrox.dev/jmorton06/Lumos/goto"><img alt="Build" src="https://img.shields.io/endpoint.svg?url=https%3A%2F%2Factions-badge.atrox.dev%2Fjmorton06%2FLumos%2Fbadge&style=flat-square&label=build&branch=master&event=push"/></a>
<a href=""><img alt="platforms" src="https://img.shields.io/badge/Platforms-Windows%20%7C%20Linux%20%7C%20macOS%20%7C%20iOS-blue?style=flat-square"/></a>
<a href="https://github.com/jmorton06/Lumos/blob/master/LICENSE"><img alt="license" src="https://img.shields.io/github/license/jmorton06/Lumos?style=flat-square"/></a>
<br/>
<a href="https://github.com/jmorton06/Lumos/issues"><img alt="Issues" src="https://img.shields.io/github/issues-raw/jmorton06/Lumos.svg?style=flat-square"/></a>
<a href=""><img alt="size" src="https://img.shields.io/github/repo-size/jmorton06/Lumos?style=flat-square"/></a>
<a href=""><img alt="stars" src="https://img.shields.io/github/stars/jmorton06/Lumos?style=social"/></a>
<br/>
</p>

### About
Basically a HelloWorld but this time it's for an entire game engine.

**Updates :**

Currently working on Camera2D and adding Render and Frame buffers (FBO, RBO for textures mapping) to the Renderer2D.

Find the latest features list and updates about the engine at : [Fireworks Engine update thread](https://twitter.com/GameGraphicsGuy/status/1300449455733239808)

#
### Features

- 2D rendering pipeline
- Can render upto 60, 000 Sprites, textures using batch rendering
- Simple and customisable math library
- Basic font rendering (supports only a sinle font for now)
- Easy to manage and customisable native scripting 
- Simple API for faster development and customisation
- Simple Window and Input management System and a lot more... on the way...

#
### Building
**MacOS :**
  change to the build folder and use the CMakeFile to generate the MakeFile and build the library using the Make command
```bash
  cd build 
  cmake ..
  make 
```
**Windows/Linux :**
CMakeFile to  be updated....

### Usage
Here's a simple example to render a window.
```cpp

#include <fireworks/fireworks.h>

using namespace fireworks;

class ExampleTemplate : public Fireworks
{
private:
    Window* window;
public:
    ExampleTemplate()
    {

    }

    ~ExampleTemplate()
    {

    }

    // Runs once per initialisation
    void init() override
    {
        window = createWindow("Example Template", 800, 600);
    }

    // Runs once per second
    void tick() override
    {

    }

    // Runs 60 times per second
    void update() override
    {

    }

    // Runs as fast as possible
    void render() override
    {

    }
};

int main()
{
    ExampleTemplate game;
    game.start();
    return 0;
}
```
### TODO
- Camera 2D
- Render textures and frame buffer textures
- Physics2D component (box3d)
- Better and customisable font rendering 
- Audio system
- Event system
- 3D rendering + BatchRenderer3D
- Camera 3D
- 2D + 3D primitive drawing utility function 
- 3D Physics 
- ECS - entity component system 

#
### Dependencies
- SOIL, Freetype and [glText](https://github.com/vallentin/glText), GLEW, GLFW, PNG 

