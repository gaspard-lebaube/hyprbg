# HyprBG

#### The most "*Beau Gosse*" wallpaper ever!

## Features

- Runs on Hyprland via `hyprwinwrap` (Wayland) or `xwinwrap` (X11)
- Configurable FPS
- Lightweight and efficient

## Requirements

- **C compiler** (GCC/Clang)
- **SDL2** library
```bash
  sudo pacman -S sdl2    # Arch Linux
````

* **Wayland/Hyprland** or **X11**
* Optional: `xwinwrap` (for X11) or `hyprwinwrap` (for Hyprland)

## Installation

### 1. Clone the repository

```bash
git clone https://github.com/gaspard-lebaube/hyprbg.git
cd hyprbg
```

### 2. Compile the program

```bash
gcc wallpaper.c -o wallpaper $(pkg-config --cflags --libs sdl2)
```

## Usage

### X11 with xwinwrap

```bash
xwinwrap -ov -g 1920x1080+0+0 -- ./wallpaper
```

### Hyprland with hyprwinwrap

1. Make sure your SDL2 window sets a **title** or **class**:

```c
SDL_SetWindowTitle(window, "hyprbg");
```

2. Install [hyprland-plugins](https://github.com/hyprwm/hyprland-plugins):

```bash
hyprpm update

hyprpm add https://github.com/hyprwm/hyprland-plugins

hyprpm enable hyprwinwrap
```

3. Add to `~/.config/hypr/hyprland.conf`:

```conf
plugin {
    hyprwinwrap {
        class = hyprbg
        title = hyprbg
        pos_x = 0
        pos_y = 0
        size_x = 100
        size_y = 100
        ignore_input = true
    }
}
```

> [!NOTE]
> If you use blur on your windows, please consider that you should probably set decoration:blur:new_optimizations to false.
>
> [Issue #197](https://github.com/hyprwm/hyprland-plugins/issues/197) 

4. Reload Hyprland config:

```bash
hyprctl reload
```

Don't forget to add the `hyprbg` executable to your `~/.config/hypr/hyprland.conf`:

```conf
exec-once = ~/hyprbg/hyprbg 
```

## Customization

TODO: add a simple config

## Contributing

Feel free to open issues, suggest features, or submit pull requests.
This project is meant to be lightweight and easily extensible.

