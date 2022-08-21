#ifndef PANCAKE_SORT_H
#define PANCAKE_SORT_H

#include "../sort.h"

class PancakeSort : public SortStrategy {
  public:
    explicit PancakeSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Pancake Sort");
    }

    ~PancakeSort() noexcept override = default;

    PancakeSort(const PancakeSort &other) = delete;

    PancakeSort &operator=(const PancakeSort &other) = delete;

    PancakeSort(PancakeSort &&other) noexcept = default;

    PancakeSort &operator=(PancakeSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        for (uint32_t i{static_cast<uint32_t>(v_.size())}; i > 1; --i) {
            uint32_t location = maxIndex(v_, i);
            if (location != i - 1) {
                Visualize::visualizeBar(v_, location, "Pancake Sort");
                Visualize::visualizeBar(v_, i - 1, "Pancake Sort");
                reverseElement(v_, location);
                reverseElement(v_, i - 1);
                Visualize::visualize(v_, "Pancake Sort");
            }
        }
        Visualize::visualizeEnding(v_, "Pancake Sort");
    }

    uint32_t maxIndex(std::vector<std::pair<float, Color>> &v, uint32_t size) {
        uint32_t maxIndex{0};
        for (uint32_t i{0}; i < size; ++i) {
            if (v[i].first > v[maxIndex].first) { maxIndex = i; }
        }
        return maxIndex;
    }

    void reverseElement(std::vector<std::pair<float, Color>> &v,
                        uint32_t index) {
        for (uint32_t i{0}; i < index / 2; ++i) {
            std::swap(v[i], v[index - i - 1]);
        }
    }
};

#endif