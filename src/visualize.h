#ifndef VISUALIZE_H
#define VISUALIZE_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include <string>
#include <vector>
#include <iostream>

class Visualize {
  public:
    Visualize() = default;

    static void visualize(std::vector<std::pair<float, Color>> const &v = {},
                          std::string const &title = {}) {
        BeginDrawing();
        ClearBackground(BLANK);
        float barWidth =
            static_cast<float>(GetScreenWidth()) / static_cast<float>(v.size());
        for (uint32_t i{0}; i < v.size(); ++i) {
            auto [barHeight, color] = v[i];
            DrawRectangleV(
                Vector2{static_cast<float>(i) * barWidth,
                        static_cast<float>(GetScreenHeight()) - barHeight},
                Vector2{barWidth, barHeight}, color);
        }
        drawSortTitle(title);
        if (IsKeyDown(KEY_ESCAPE)) { return; }
        EndDrawing();
    }

    static void drawSortTitle(std::string const &title = {}) {
        DrawText(title.c_str(), 10, 10, 30, RAYWHITE);
    }

    static void visualizeBar(std::vector<std::pair<float, Color>> const &v = {},
                             uint32_t index = 0,
                             std::string const &title = {}) {
        BeginDrawing();
        float barWidth =
            static_cast<float>(GetScreenWidth()) / static_cast<float>(v.size());
        auto [barHeight, color] = v[index];
        DrawRectangleV(
            Vector2{static_cast<float>(index) * barWidth,
                    static_cast<float>(GetScreenHeight()) - barHeight},
            Vector2{barWidth, barHeight}, RAYWHITE);
        drawSortTitle(title);
        if (IsKeyDown(KEY_ESCAPE)) { return; }
        EndDrawing();
    }

    static void
    visualizeEnding(std::vector<std::pair<float, Color>> const &v = {},
                    std::string const &title = {}) {
        for (uint32_t i{0}; i < v.size(); ++i) {
            visualizeBar(v, i, title);
        }
        visualize(v, title);
    }
};

#endif