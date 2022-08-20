#ifndef VECTOR_H
#define VECTOR_H

#include "../lib/raylib-4.2.0/src/raylib.h"
#include <algorithm>
#include <cstdint>
#include <random>
#include <vector>

class Vector {
  private:
    std::vector<std::pair<float, Color>> v_;

    static Color getRandomColor() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        return {static_cast<unsigned char>(dis(gen)),
                static_cast<unsigned char>(dis(gen)),
                static_cast<unsigned char>(dis(gen)), 255};
    }

  public:
    explicit Vector(uint32_t size) : v_(size) {
        generate();
        shuffle();
    }

    void generate() {
        auto [r1, g1, b1, a1] = getRandomColor();
        auto [r2, g2, b2, a2] = getRandomColor();
        int deltaRed = r2 - r1;
        int deltaGreen = g2 - g1;
        int deltaBlue = b2 - b1;
        float redShift =
            static_cast<float>(deltaRed) / static_cast<float>(v_.size());
        float greenShift =
            static_cast<float>(deltaGreen) / static_cast<float>(v_.size());
        float blueShift =
            static_cast<float>(deltaBlue) / static_cast<float>(v_.size());
        float blockHeight = static_cast<float>(GetScreenHeight()) /
                            static_cast<float>(v_.size());
        for (uint32_t i{0}; i < v_.size(); ++i) {
            float barHeight = static_cast<float>(i + 1) * blockHeight;
            unsigned char red = r1 + i * redShift;
            unsigned char green = g1 + i * greenShift;
            unsigned char blue = b1 + i * blueShift;
            v_[i] = std::make_pair(barHeight, Color{red, green, blue, 255});
        }
    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(v_.begin(), v_.end(), g);
    }

    auto getVector() { return v_; }
};

#endif