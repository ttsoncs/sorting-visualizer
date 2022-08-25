#ifndef VISUALIZE_H
#define VISUALIZE_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include "window.h"
#include <vector>

class Visualize {
  private:
    inline static bool style_ = false;

  public:
    static auto visualizeVector(std::vector<std::pair<int, std::pair<float, Color>>> const &v = {}) {
        auto size{v.size()};
        auto barWidth{static_cast<float>(GetScreenWidth()) / static_cast<float>(size)};
        auto screenHeight{static_cast<float>(GetScreenHeight())};
        ClearBackground(BLANK);
        if (Visualize::style_) {
            for (auto i{0}; i != size; ++i) {
                auto [barHeight, color] = v[i].second;
                DrawRectangleV(Vector2{static_cast<float>(i) * barWidth, screenHeight - barHeight},
                               Vector2{barWidth, barWidth}, color);
            }
        } else {
            for (auto i{0}; i != size; ++i) {
                auto [barHeight, color] = v[i].second;
                DrawRectangleV(Vector2{static_cast<float>(i) * barWidth, screenHeight - barHeight},
                               Vector2{barWidth, barHeight}, color);
            }
        }
    }

    static auto visualizeBar(std::vector<std::pair<int, std::pair<float, Color>>> const &v = {}, int index = 0) {
        auto barWidth{static_cast<float>(GetScreenWidth()) / static_cast<float>(v.size())};
        auto [barHeight, color] = v[index].second;
        auto screenHeight{static_cast<float>(GetScreenHeight())};
        if (Visualize::style_) {
            DrawRectangleV(Vector2{static_cast<float>(index) * barWidth, screenHeight - barHeight},
                           Vector2{barWidth, barWidth}, RAYWHITE);
        } else {
            DrawRectangleV(Vector2{static_cast<float>(index) * barWidth, screenHeight - barHeight},
                           Vector2{barWidth, barHeight}, RAYWHITE);
        }
    }

    static auto visualizeTitle(std::string const &title = {}) {
        DrawText(title.c_str(), 10, 10, GetScreenWidth() / 40, RAYWHITE);
    }

    static void visualizeTraverse(std::vector<std::pair<int, std::pair<float, Color>>> const &v = {}, int firstBar = 0, int secondBar = 0,
                                  std::string const &title = {}) {
        Window::beginDrawing();
        Visualize::visualizeVector(v);
        Visualize::visualizeBar(v, firstBar);
        Visualize::visualizeBar(v, secondBar);
        Visualize::visualizeTitle(title);
        if (Window::isKeyDown(KEY_LEFT)) {
            Window::decrementFps();
        }
        if (Window::isKeyDown(KEY_RIGHT)) {
            Window::incrementFps();
        }
        if (Window::isKeyDown(KEY_ESCAPE)) {
            return;
        }
        Window::endDrawing();
    }

    static auto visualizeEnding(std::vector<std::pair<int, std::pair<float, Color>>> const &v = {}, std::string const &title = {}) {
        auto size{v.size()};
        Window::beginDrawing();
        Visualize::visualizeVector(v);
        Visualize::visualizeTitle(title);
        if (Window::isKeyDown(KEY_ESCAPE)) {
            return;
        }
        Window::endDrawing();
        for (auto i{0}; i != size; ++i) {
            Window::beginDrawing();
            Visualize::visualizeBar(v, i);
            Visualize::visualizeTitle(title);
            if (Window::isKeyDown(KEY_LEFT)) {
                Window::decrementFps();
            }
            if (Window::isKeyDown(KEY_RIGHT)) {
                Window::incrementFps();
            }
            if (Window::isKeyDown(KEY_ESCAPE)) {
                return;
            }
            Window::endDrawing();
        }
        Window::beginDrawing();
        Visualize::visualizeVector(v);
        Visualize::visualizeTitle(title);
        if (Window::isKeyDown(KEY_ESCAPE)) {
            return;
        }
        Window::endDrawing();
    }

    static auto visualizeStyle(std::vector<std::pair<int, std::pair<float, Color>>> const &v = {}) {
        Visualize::style_ = !Visualize::style_;
        Visualize::visualizeVector(v);
        if (Visualize::style_) {
            Visualize::visualizeTitle("Scatter Plot Style");
        } else {
            Visualize::visualizeTitle("Bar Chart Style");
        }
    }
};

#endif