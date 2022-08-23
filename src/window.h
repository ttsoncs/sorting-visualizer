#ifndef WINDOW_H
#define WINDOW_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include "globalVariable.h"

class Window {
  public:
    Window(int width, int height, std::string const &windowTitle = {}) {
        InitWindow(width, height, windowTitle.c_str());
        SetExitKey(KEY_ESCAPE);
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT |
                       FLAG_WINDOW_HIGHDPI);
    }

    ~Window() noexcept { CloseWindow(); }

    Window(const Window &other) = default;

    Window &operator=(const Window &other) = default;

    Window(Window &&other) noexcept = default;

    Window &operator=(Window &&other) noexcept = default;

    void setTargetFps(int fps) { SetTargetFPS(fps); }

    static void changeFps() {
        if (IsKeyDown(KEY_LEFT) && SCREEN_FPS > 2) {
            SCREEN_FPS -= 2;
            SetTargetFPS(SCREEN_FPS);
        }
        if (IsKeyDown(KEY_RIGHT) && SCREEN_FPS < 240) {
            SCREEN_FPS += 2;
            SetTargetFPS(SCREEN_FPS);
        }
    }

    [[nodiscard]] static bool windowShouldClose() { return WindowShouldClose(); }

    [[nodiscard]] static bool isKeyDown(int key) { return IsKeyDown(key); }
};

#endif