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
        BeginDrawing();
        ClearBackground(BLANK);
        auto barWidth =
            static_cast<float>(GetScreenWidth()) / static_cast<float>(v.size());
        auto size = v.size();
        for (auto i{0}; i < size; ++i) {
            auto [barHeight, color] = v[i];
            DrawRectangleV(
                Vector2{static_cast<float>(i) * barWidth,
                        static_cast<float>(GetScreenHeight()) - barHeight},
                Vector2{barWidth, barHeight}, color);
        }
        visualizeSortTitle(sortTitle);
        if (IsKeyDown(KEY_ESCAPE)) { return; }
        EndDrawing();
    }

    //mesure text nay nua ha
    static void visualizeSortTitle(std::string const &sortTitle = {}) {
        DrawText(sortTitle.c_str(), 10, 10, 30, RAYWHITE);
    }

    static void visualizeBar(std::vector<std::pair<float, Color>> const &v = {},
                             uint32_t index = 0,
                             std::string const &sortTitle = {}) {
        BeginDrawing();
        auto barWidth =
            static_cast<float>(GetScreenWidth()) / static_cast<float>(v.size());
        auto [barHeight, color] = v[index];
        DrawRectangleV(
            Vector2{static_cast<float>(index) * barWidth,
                    static_cast<float>(GetScreenHeight()) - barHeight},
            Vector2{barWidth, barHeight}, RAYWHITE);
        if (IsKeyDown(KEY_ESCAPE)) { return; }
        EndDrawing();
    }

    static void
    visualizeEnding(std::vector<std::pair<float, Color>> const &v = {},
                    std::string const &sortTitle = {}) {
        auto size = v.size();
        for (auto i{0}; i < size; ++i) {
            visualizeBar(v, i, sortTitle);
        }
        visualizeVector(v, sortTitle);
    }
};

#endif