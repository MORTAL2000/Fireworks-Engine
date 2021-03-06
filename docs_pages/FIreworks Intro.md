@mainpage
<h1 align="center"> Fireworks Engine </h1>

<p align="center">
<h3 align="center">A Lightweight Sandbox Game Engine using OpenGL for additional Customisation and Quick Prototyping.</h3>
</p>


### About
Basically a HelloWorld but this time it's for an entire game engine.

### Ludum Dare 47
- Checkout branch [LD47](https://github.com/Pikachuxxxx/Fireworks-Engine/tree/LD47/Fireworks%20Engine/LD47) for my [ludum dare submissoin](https://ldjam.com/events/ludum-dare/47/one-for-an-era) using fireworks engine, a lot of experimental features were added during the jam that will soon be integrated into the engine.

### Updates

Currently Event system and adding more diversity to the existing API.

Find the latest features list and updates about the engine at : [Fireworks Engine update thread](https://twitter.com/GameGraphicsGuy/status/1300449455733239808)


### Features

- 2D rendering pipeline
- Can render upto 60, 000 Sprites, textures using batch rendering
- Sprite Sheet Animations (can change frame or frame rate manually, supports 2 types of in-built animation modes [LOOP, PING_PONG])
- Simple and customisable math library
- Basic font rendering (supports only a single font for now)
- Easy to manage and customisable native scripting 
- Simple API for faster development and customisation
- Simple Window and Input management System 
- Huge custom Maths Library and a lot of utility functions
- Render textures and Frame Buffer objects
- 2D orthographic camera 


### Building
**MacOS/Windows/Linux :**
  change to the build folder and use the CMakeFile to generate the MakeFile and build the library using the Make command
```bash
  mkdir build
  cd build 
  cmake ..
  make 
```

### Usage
**Find more Examples in the [Sandbox project here](https://github.com/Pikachuxxxx/Fireworks-Engine/tree/master/Fireworks%20Engine/Sandbox/examples)**

Here's an example to render a simple coloured square. [simplebox.h](https://github.com/Pikachuxxxx/Fireworks-Engine/blob/master/Examples/SimpleBox.h)
```cpp

#include <fireworks/fireworks.h>

using namespace fireworks;

class SimpleBox : public Fireworks
{
private:
    Window* window;
    Layer* layer;
public:
    SimpleBox() { }

    ~SimpleBox()
    {
        delete layer;
    }

    // Runs once per initialisation
    void init() override
    {
        window = createWindow("Test Game Example : Fireworks Engine", 800, 600);
        layer = new Layer(new BatchRenderer2D(),
                          new Shader("../Fireworks-core/src/shaders/basic.vert",
                                     "../Fireworks-core/src/shaders/basic.frag"),
                          mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f , 1.0f));

        Sprite* box = new Sprite(4.0f, 4.0f, 4.0f, 4.0f, vec4(1.0f, 1.0f, 0.0f, 1.0f));
        layer->add(box);
   }

   // Runs once per second
    void tick() override { }

    // Runs 60 times per second
    void update() override { }

    // Runs as fast as possible
    void render() override
    {
        layer->render();
    }
};

int main()
{
    SimpleBox game;
    game.start();
    return 0;
}
```
### TODO
- [x] Camera 2D
- [x] Render textures and Frame Buffer objects
- [x] Sprite Sheet Animations
- Physics2D component (box2d physics engine integration)
- Better and customisable font rendering 
- Audio system
- Materials and Lights (2D and 3D)
- Event system
- 3D rendering + BatchRenderer3D
- Camera 3D
- 2D + 3D primitive drawing utility function 
- 3D Physics 
- ECS - entity component system 
- Occlusion Culling
- Editor UI using ImGui


### Dependencies
- [SOIL](https://github.com/Pikachuxxxx/SOIL), Freetype and [glText](https://github.com/vallentin/glText), GLEW, GLFW, PNG, Zlib2 

