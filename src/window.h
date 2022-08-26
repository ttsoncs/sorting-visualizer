#ifndef WINDOW_H
#define WINDOW_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include <string>

class Window {
  public:
    Window() {
        InitWindow(1280, 720, "Sort Visualizer");
        SetExitKey(KEY_ESCAPE);
        SetTargetFPS(Window::fps);
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    }

    ~Window() noexcept { CloseWindow(); }

    Window(const Window &other) = delete;

    Window &operator=(const Window &other) = delete;

    Window(Window &&other) noexcept = default;

    Window &operator=(Window &&other) noexcept = default;

    static auto incrementFps(bool isSorting = false) {
        if (Window::fps < 240) {
            Window::fps += 2;
            SetTargetFPS(Window::fps);
        }
    }

    static auto decrementFps() {
        if (Window::fps > 2) {
            Window::fps -= 2;
            SetTargetFPS(Window::fps);
        }
    }

    static auto beginDrawing() { BeginDrawing(); }

    static auto endDrawing() { EndDrawing(); }

    static auto pause() { while(Window::isKeyPressed(KEY_SPACE)); }

    [[nodiscard]] static auto getFps() { return Window::fps; }

    [[nodiscard]] static auto windowShouldClose() { return WindowShouldClose(); }

    [[nodiscard]] static auto isKeyDown(int key) -> bool { return IsKeyDown(key); }

    [[nodiscard]] static auto isKeyPressed(int key) -> bool { return IsKeyPressed(key); }

  private:
    inline static auto fps{60};
};

#endif