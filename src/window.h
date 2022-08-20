#ifndef WINDOW_H
#define WINDOW_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include <string>

class Window {
  public:
    Window(int width, int height, int fps, std::string const &title) {
        InitWindow(width, height, title.c_str());
        SetTargetFPS(fps);
        SetExitKey(KEY_ESCAPE);
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        SetConfigFlags(FLAG_VSYNC_HINT);
        SetConfigFlags(FLAG_WINDOW_HIGHDPI);
        SetConfigFlags(FLAG_FULLSCREEN_MODE);
        SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);
    }

    ~Window() noexcept { CloseWindow(); }

    Window operator=(const Window &other) = delete;

    Window(const Window &other) = delete;

    [[nodiscard]] static bool windowShouldClose() {
        return WindowShouldClose();
    }

    [[nodiscard]] static bool isKeyDown(int key) { return IsKeyDown(key); }
};

#endif