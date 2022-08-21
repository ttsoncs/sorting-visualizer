#ifndef PANCAKE_SORT_H
#define PANCAKE_SORT_H

#include "../sortStrategy.h"
class PancakeSort : public SortStrategy {
  public:
    explicit PancakeSort(uint32_t size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Pancake Sort");
    }

    ~PancakeSort() noexcept override = default;

    PancakeSort(const PancakeSort &other) = delete;

    PancakeSort &operator=(const PancakeSort &other) = delete;

    PancakeSort(PancakeSort &&other) noexcept = default;

    PancakeSort &operator=(PancakeSort &&other) noexcept = default;

    void sort() override {
        auto v = vector_.getVector();
        auto size{v.size()};
        for (auto i{size}; i > 1; --i) {
            auto location{maxIndex(v, i)};
            if (location != i - 1) {
                Visualize::visualizeBar(v, location, "Pancake Sort");
                Visualize::visualizeBar(v, i - 1, "Pancake Sort");
                reverseElement(v, location);
                reverseElement(v, i - 1);
                Visualize::visualizeVector(v, "Pancake Sort");
            }
        }
        Visualize::visualizeEnding(v, "Pancake Sort");
    }

    uint32_t maxIndex(std::vector<std::pair<float, Color>> const &v,
                      uint32_t size) {
        auto maxIndex{0};
        for (auto i{0}; i < size; ++i) {
            if (v[i].first > v[maxIndex].first) { maxIndex = i; }
        }
        return maxIndex;
    }

    void reverseElement(std::vector<std::pair<float, Color>> &v,
                        uint32_t index) {
        auto start{0};
        while (start < index) {
            std::swap(v[start], v[index]);
            ++start;
            --index;
        }
    }
};

#endif