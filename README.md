# cub3D — 3D Raycasting Engine in C

> A fully functional 3D game engine built from scratch in C, inspired by Wolfenstein 3D — no external graphics library, pure raycasting mathematics.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![42](https://img.shields.io/badge/École_42-000000?style=flat&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green?style=flat)

---

## 📐 What is cub3D?

cub3D is a École 42 project that challenges students to build a 3D perspective engine using the **raycasting** technique — the same algorithm that powered the original Wolfenstein 3D (1992).

The entire rendering engine is written from scratch in C using only the **MiniLibX** graphics library for window and pixel management.

---

## ✨ Features

- 🎮 Real-time 3D rendering via raycasting
- 🗺️ Custom map parser (`.cub` format)
- 🧱 Textured walls with directional faces (N/S/E/W)
- 🎨 Configurable floor and ceiling colors
- 🧭 Smooth player movement and rotation (keyboard)
- 💥 Collision detection
- 🪟 Resizable window with proper event handling

---

## 🛠️ Technical highlights

- **Raycasting algorithm** — DDA (Digital Differential Analysis) for precise wall hit detection
- **Texture mapping** — correct perspective projection for wall slices
- **Memory management** — full manual memory handling, no leaks
- **Map validation** — checks for closed maps, invalid characters, missing elements

---

## 🚀 Installation & Usage

```bash
git clone https://github.com/elmikitozer/cub3d.git
cd cub3d
make
./cub3D maps/map.cub
```

**Controls**
| Key | Action |
|-----|--------|
| `W A S D` | Move |
| `← →` | Rotate camera |
| `ESC` | Quit |

---

## 📁 Map format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

---

## 📚 What I learned

- Low-level graphics programming in C
- Mathematical foundations of 3D rendering (trigonometry, vectors)
- Memory management and leak prevention
- Parsing and validation of custom file formats

---

*École 42 Paris — 2024*
