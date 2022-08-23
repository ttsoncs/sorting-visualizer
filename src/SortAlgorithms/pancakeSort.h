#ifndef PANCAKE_SORT_H
#define PANCAKE_SORT_H

#include "../sortStrategy.h"

class PancakeSort : public SortStrategy {
  private:
    int maxIndex(std::vector<std::pair<int, std::pair<float, Color>>> const &v,
                 int size) {
        auto maxIndex{0};
        for (auto i{0}; i != size; ++i) {
            Visualize::visualizeTraverse(v, maxIndex, i, "Pancake Sort");
            if (v[i].first > v[maxIndex].first) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    void reverseElement(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                        int index) {
        auto start{0};
        while (start < index) {
            Visualize::visualizeTraverse(v, start, index, "Pancake Sort");
            std::swap(v[start], v[index]);
            ++start;
            --index;
        }
    }

  public:
    explicit PancakeSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Pancake Sort");
    }

    ~PancakeSort() noexcept override = default;

    PancakeSort(const PancakeSort &other) = default;

    PancakeSort &operator=(const PancakeSort &other) = default;

    PancakeSort(PancakeSort &&other) noexcept = default;

    PancakeSort &operator=(PancakeSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        for (auto i{size}; i != 1; --i) {
            auto location{maxIndex(v, i)};
            if (location != i - 1) {
                reverseElement(v, location);
                reverseElement(v, i - 1);
            }
        }
        Visualize::visualizeEnding(v, "Pancake Sort");
    }
};

#endif