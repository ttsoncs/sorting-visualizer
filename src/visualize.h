#ifndef VISUALIZE_H
#define VISUALIZE_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include "window.h"
#include <vector>

class Visualize {
  public:
    static void visualizeVector(
        std::vector<std::pair<int, std::pair<float, Color>>> const &v = {},
        std::string const &sortTitle = {}) {
        auto barWidth{static_cast<float>(GetScreenWidth()) /
                      static_cast<float>(v.size())};
        auto size{v.size()};
        auto screenHeight{static_cast<float>(GetScreenHeight())};
        ClearBackground(BLANK);
        for (auto i{0}; i != size; ++i) {
            auto [barHeight, color] = v[i].second;
            DrawRectangleV(
                Vector2{static_cast<float>(i) * barWidth, screenHeight - barHeight},
                Vector2{barWidth, barHeight}, color);
        }
        visualizeSortTitle(sortTitle);
    }

    static void visualizeBar(
        std::vector<std::pair<int, std::pair<float, Color>>> const &v = {},
        int index = 0, std::string const &sortTitle = {}) {
        auto barWidth{static_cast<float>(GetScreenWidth()) /
                      static_cast<float>(v.size())};
        auto [barHeight, color] = v[index].second;
        auto screenHeight{static_cast<float>(GetScreenHeight())};
        DrawRectangleV(
            Vector2{static_cast<float>(index) * barWidth, screenHeight - barHeight},
            Vector2{barWidth, barHeight}, RAYWHITE);
    }

    static void visualizeSortTitle(std::string const &sortTitle = {}) {
        DrawText(sortTitle.c_str(), 10, 10, GetScreenWidth() / 40, RAYWHITE);
    }

    static void visualizeTraverse(
        std::vector<std::pair<int, std::pair<float, Color>>> const &v = {},
        int firstBar = 0, int secondBar = 0, std::string const &sortTitle = {}) {
        BeginDrawing();
        Visualize::visualizeVector(v, sortTitle);
        Visualize::visualizeBar(v, firstBar, sortTitle);
        Visualize::visualizeBar(v, secondBar, sortTitle);
        if (Window::isKeyDown(KEY_ESCAPE)) {
            return;
        }
        Window::changeFps();
        EndDrawing();
    }

    static void visualizeEnding(
        std::vector<std::pair<int, std::pair<float, Color>>> const &v = {},
        std::string const &sortTitle = {}) {
        auto size{v.size()};
        BeginDrawing();
        visualizeVector(v, sortTitle);
        if (Window::isKeyDown(KEY_ESCAPE)) {
            return;
        }
        EndDrawing();
        for (auto i{0}; i != size; ++i) {
            BeginDrawing();
            visualizeBar(v, i, sortTitle);
            if (Window::isKeyDown(KEY_ESCAPE)) {
                return;
            }
            Window::changeFps();
            EndDrawing();
        }
        BeginDrawing();
        visualizeVector(v, sortTitle);
        if (Window::isKeyDown(KEY_ESCAPE)) {
            return;
        }
        EndDrawing();
    }
};

#endif