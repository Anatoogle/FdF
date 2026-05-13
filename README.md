# FdF

FdF is a graphics project from the 42 curriculum focused on creating a simple 3D wireframe renderer in C using the MiniLibX graphics library.

The program reads a map file containing height values and displays the landscape in an isometric projection. The project introduces the basics of computer graphics, coordinate transformations, rendering, and event handling.

This project is not a 3D engine. It is a low-level graphics program focused on understanding how images are drawn from mathematical data.

Instead of relying on modern rendering systems, everything is built from scratch: calculating coordinates, projecting 3D points onto a 2D screen, and drawing lines pixel by pixel.

This project was developed in compliance with the requirements and constraints of the 42 network, respecting the imposed coding standards, allowed functions, and project guidelines.

---

<img width="750" height="422" alt="FdF_gif" src="https://github.com/user-attachments/assets/a357f0c9-dac9-4078-b168-6e51bfc1980d" />

---

## Features

- Parse `.fdf` map files
- Render 3D wireframe maps
- Isometric projection
- Parallel projection
- Zoom and movement controls
- Rotation support
- Event handling with MiniLibX

## Custom Features

In addition to the standard FdF heightmap rendering, I extended the project to support fully 3D wireframe objects.

### 3D Object Support (.plus files)

I implemented a custom format (`.plus`) that allows the program to render full 3D meshes instead of only heightmaps.

To generate these files, I created a Blender script that extracts vertex and edge data directly from a selected mesh. The script can be run inside Blender and automatically exports the object into a `.plus` file, which can then be loaded and rendered by the program as a wireframe model.

This extends FdF from terrain visualization to general 3D wireframe rendering.

### Blender Export Script

Usage:
- Select a mesh in Blender
- Run the provided Python script
- A `.plus` file is generated containing vertices and edges

---

## Compilation

- Clone FdF repository.
- Clone the MiniLibX repository into the same parent directory as the FdF project and name it mlx.
- https://github.com/42paris/minilibx-linux

```text
.
├── FdF/
├── mlx/
```

Then compile the project with:

```bash
make
```
```bash
make bonus
```
```bash
make plus
```
---

## Usage

```bash
./fdf test_maps/42.fdf
```
```bash
./fdf_bonus test_maps/42.fdf
```
```bash
./fdf_plus test_maps/Monkey.plus
```

---

## Controls

The controls are inspired by Autodesk Maya navigation style for a more intuitive 3D viewport experience.

| Key | Action |
|-----|--------|
| ALT + MMB + Mouse Move | Move |
| ALT + LMB + Mouse Move | Rotate |
| ALT + RMB + Mouse Move | Zoom |
| MMB + Mouse Move | Height Scale |
| P | Change Camera |
| ESC | Exit |

---

## What I Learned

- Basics of computer graphics
- Coordinate transformations
- Parsing and data structures
- Event-driven programming
- Memory management in C

