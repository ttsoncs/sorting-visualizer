#ifndef VECTOR_H
#define VECTOR_H

#include "visualize.h"
#include <algorithm>

class Vector {
  public:
    Vector() {
        Vector::generate();
        Vector::randomShuffle(false);
    }

    static auto changeColor() {
        auto [r1, g1, b1, a1] = Visualize::getRandomColor();
        auto [r2, g2, b2, a2] = Visualize::getRandomColor();
        auto deltaRed{static_cast<float>(r2 - r1) / static_cast<float>(Vector::v_size_)};
        auto deltaGreen{static_cast<float>(g2 - g1) / static_cast<float>(Vector::v_size_)};
        auto deltaBlue{static_cast<float>(b2 - b1) / static_cast<float>(Vector::v_size_)};
        for (auto i{0}; i != Vector::v_size_; ++i) {
            auto it             = std::find_if(Vector::v_.begin(), Vector::v_.end(),
                                               [i](auto const &p) { return p.first == i; });
            it->second.second.r = r1 + static_cast<int>(deltaRed * i);
            it->second.second.g = g1 + static_cast<int>(deltaGreen * i);
            it->second.second.b = b1 + static_cast<int>(deltaBlue * i);
        }
        Visualize::visualizeVector(Vector::v_);
        Visualize::visualizeTitle("Color Changed");
    }

    static auto generate() -> void {
        Vector::v_.clear();
        Vector::v_.reserve(Vector::v_size_);
        auto [r1, g1, b1, a1] = Visualize::getRandomColor();
        auto [r2, g2, b2, a2] = Visualize::getRandomColor();
        auto deltaRed{static_cast<float>(r2 - r1) / Vector::v_size_};
        auto deltaGreen{static_cast<float>(g2 - g1) / Vector::v_size_};
        auto deltaBlue{static_cast<float>(b2 - b1) / Vector::v_size_};
        auto deltaHeight{static_cast<float>(GetScreenHeight()) / Vector::v_size_};
        auto barHeight{0.0f};
        for (auto i{0}; i != Vector::v_size_; ++i) {
            barHeight += deltaHeight;
            v_.emplace_back(std::make_pair(i, std::make_pair(barHeight, Color{
                                                                            static_cast<unsigned char>(r1 + i * deltaRed),
                                                                            static_cast<unsigned char>(g1 + i * deltaGreen),
                                                                            static_cast<unsigned char>(b1 + i * deltaBlue),
                                                                            255})));
        }
    }

    static auto randomShuffle(bool isConstructed = true) -> void {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(Vector::v_.begin(), Vector::v_.end(), g);
        if (isConstructed) {
            Window::beginDrawing();
            Visualize::visualizeVector(Vector::v_);
            Visualize::visualizeTitle("Random Shuffle");
            Window::endDrawing();
        }
    }

    static auto reverseSortedShuffle(bool isConstructed = true) -> void {
        std::sort(Vector::v_.begin(), Vector::v_.end(), [](auto const &a, auto const &b) {
            return a.first > b.first;
        });
        if (isConstructed) {
            Window::beginDrawing();
            Visualize::visualizeVector(Vector::v_);
            Visualize::visualizeTitle("Reverse Sorted Shuffle");
            Window::endDrawing();
        }
    }

    static auto almostSortedShuffle(bool isConstructed = true) -> void {
        std::sort(Vector::v_.begin(), Vector::v_.end(), [](auto const &a, auto const &b) {
            return a.first < b.first;
        });
        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<int> dSize((Vector::v_size_ / 4), (Vector::v_size_ / 2));
        std::uniform_int_distribution<int> dIndex(0, Vector::v_size_ - 1);
        auto size{dSize(g)};
        for (auto i{0}; i != size; ++i) {
            auto firstIndex{dIndex(g)};
            auto secondIndex{dIndex(g)};
            std::swap(v_[firstIndex], v_[secondIndex]);
        }
        if (isConstructed) {
            Window::beginDrawing();
            Visualize::visualizeVector(Vector::v_);
            Visualize::visualizeTitle("Almost Sorted Shuffle");
            Window::endDrawing();
        }
    }

    static auto getVector() { return Vector::v_; }

    static auto incrementVectorSize() {
        if (Vector::v_size_ < 480) {
            Vector::v_size_ += 20;
            Vector::generate();
            Vector::randomShuffle(false);
            Visualize::visualizeVector(Vector::getVector());
            auto title{"Vector Size: " + std::to_string(Vector::v_size_)};
            Visualize::visualizeTitle(title);
        } else {
            Visualize::visualizeVector(Vector::getVector());
            auto title{"Max Size: " + std::to_string(Vector::v_size_)};
            Visualize::visualizeTitle(title);
        }
    }

    static auto decrementVectorSize() {
        if (Vector::v_size_ > 20) {
            Vector::v_size_ -= 20;
            Vector::generate();
            Vector::randomShuffle(false);
            Visualize::visualizeVector(Vector::getVector());
            auto title{"Vector Size: " + std::to_string(Vector::v_size_)};
            Visualize::visualizeTitle(title);
        } else {
            Visualize::visualizeVector(Vector::getVector());
            auto title{"Min Size: " + std::to_string(Vector::v_size_)};
            Visualize::visualizeTitle(title);
        }
    }

  private:
    inline static std::vector<std::pair<int, std::pair<float, Color>>> v_;
    inline static auto v_size_{120};
};

#endif