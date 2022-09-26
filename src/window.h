#ifndef WINDOW_H
#define WINDOW_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include <string>

class Window {
  public:
    Window() {
        InitWindow(1280, 720, "Sort Visualizer");
        InitAudioDevice();
        SetExitKey(KEY_ESCAPE);
        SetTargetFPS(Window::fps_);
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
        Sound sound{LoadSound("Sound/sound.mp3")};
        PlaySound(sound);
    }

    ~Window() noexcept {
        CloseAudioDevice();
        CloseWindow();
    }

    Window(const Window &other) = delete;

    auto operator=(const Window &other) -> Window & = delete;

    Window(Window &&other) noexcept = default;

    auto operator=(Window &&other) noexcept -> Window & = default;

    static auto incrementFps() {
        if (Window::fps_ < 240) {
            Window::fps_ += 2;
            SetTargetFPS(Window::fps_);
        }
    }

    static auto decrementFps() {
        if (Window::fps_ > 2) {
            Window::fps_ -= 2;
            SetTargetFPS(Window::fps_);
        }
    }

    static auto beginDrawing() { BeginDrawing(); }

    static auto endDrawing() { EndDrawing(); }

    static auto pause() {
        while (true) {
            if (Window::isKeyDown(KEY_M)) {
                break;
            }
            if (Window::isKeyPressed(KEY_ESCAPE)) {
                break;
            }
            Window::beginDrawing();
            Window::endDrawing();
        }
    }

    [[nodiscard]] static auto getFps() { return Window::fps_; }

    [[nodiscard]] static auto windowShouldClose() { return WindowShouldClose(); }

    [[nodiscard]] static auto isKeyDown(int key) -> bool { return IsKeyDown(key); }

    [[nodiscard]] static auto isKeyPressed(int key) -> bool { return IsKeyPressed(key); }

  private:
    inline static auto fps_{60};
};

#endif