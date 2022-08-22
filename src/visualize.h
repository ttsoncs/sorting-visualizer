#ifndef VISUALIZE_H
#define VISUALIZE_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include <string>
#include <vector>

class Visualize {
  public:
    static void
    visualizeVector(std::vector<std::pair<float, Color>> const &v = {},
                    std::string const &sortTitle = {}) {
        auto barWidth{static_cast<float>(GetScreenWidth()) /
                      static_cast<float>(v.size())};
        auto size{v.size()};
        ClearBackground(BLANK);
        for (auto i{0}; i < size; ++i) {
            auto [barHeight, color] = v[i];
            DrawRectangleV(
                Vector2{static_cast<float>(i) * barWidth,
                        static_cast<float>(GetScreenHeight()) - barHeight},
                Vector2{barWidth, barHeight}, color);
        }
        visualizeSortTitle(sortTitle);
        if (IsKeyDown(KEY_ESCAPE)) { return; }
    }

    static void visualizeSortTitle(std::string const &sortTitle = {}) {
        DrawText(sortTitle.c_str(), 10, 10, 30, RAYWHITE);
    }

    static void visualizeBar(std::vector<std::pair<float, Color>> const &v = {},
                             int index = 0, std::string const &sortTitle = {}) {
        auto barWidth{static_cast<float>(GetScreenWidth()) /
                      static_cast<float>(v.size())};
        auto [barHeight, color] = v[index];
        DrawRectangleV(
            Vector2{static_cast<float>(index) * barWidth,
                    static_cast<float>(GetScreenHeight()) - barHeight},
            Vector2{barWidth, barHeight}, RAYWHITE);
        if (IsKeyDown(KEY_ESCAPE)) { return; }
    }

    static void
    visualizeEnding(std::vector<std::pair<float, Color>> const &v = {},
                    std::string const &sortTitle = {}) {
        auto size{v.size()};
        BeginDrawing();
        visualizeVector(v, sortTitle);
        EndDrawing();
        for (auto i{0}; i < size; ++i) {
            BeginDrawing();
            visualizeBar(v, i, sortTitle);
            EndDrawing();
        }
        BeginDrawing();
        visualizeVector(v, sortTitle);
        EndDrawing();
    }
};

#endif