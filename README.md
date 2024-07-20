# Phoenix Engine

An evolving, lightweight 2d game engine.

---

### Libraries
- entt (entity component system)
- SFML (graphics amd input handling)
- Box2D (2d physics)
- spdlog (logging)

### Build

#### Requirements

- g++ compiler
- cmake 3.16 or higher
- GNU make

#### Install dependencies for linux
```bash
sudo apt-get update
sudo apt-get install libxrandr-dev libxcursor-dev libudev-dev libfreetype-dev libopenal-dev libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev build-essential cmake libxi-dev libx11-dev
```

<br>

1. Clone the repository:
```
git clone https://github.com/The-Phoenics/Phoenix.git
```

2. Open a terminal into cloned repository.

3. Generate build using *cmake*
```bash
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_POSITION_INDEPENDENT_CODE=ON
```

4. Build
```bash
cmake --build build
```

5. Run the executable generated at root of the repository (*app.exe* or *app*)

---

https://github.com/user-attachments/assets/c70dbdbd-269c-44cf-94fa-e5ab766f01e0


