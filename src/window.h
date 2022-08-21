#ifndef WINDOW_H
#define WINDOW_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include <string>

class Window {
  public:
    Window(uint32_t width, uint32_t height, std::string const &windowTitle = {}) {
        InitWindow(width, height, windowTitle.c_str());
        SetExitKey(KEY_ESCAPE);
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT |
                       FLAG_WINDOW_HIGHDPI);
    }

    ~Window() noexcept { CloseWindow(); }

    Window(const Window &other) = delete;

    Window operator=(const Window &other) = delete;

    Window(Window &&other) noexcept = default;

    Window &operator=(Window &&other) noexcept = default;

    void setTargetFps(uint32_t fps) { SetTargetFPS(fps); }

    [[nodiscard]] static bool windowShouldClose() {
        return WindowShouldClose();
    }

    [[nodiscard]] static bool isKeyDown(int key) { return IsKeyDown(key); }
};

#endif