#ifndef EVEN_ODD_SORT_H
#define EVEN_ODD_SORT_H

#include "../sort.h"

class EvenOddSort : public SortStrategy {
  public:
    explicit EvenOddSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Even Odd Sort");
    }

    ~EvenOddSort() noexcept override = default;

    EvenOddSort(const EvenOddSort &other) = delete;

    EvenOddSort &operator=(const EvenOddSort &other) = delete;

    EvenOddSort(EvenOddSort &&other) noexcept = default;

    EvenOddSort &operator=(EvenOddSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v = vector_.getVector();
        bool isSorted{false};
        do {
            isSorted = true;
            for (uint32_t i{0}; i < v.size() - 1; ++i) {
                if (v[i].first > v[i + 1].first) {
                    std::swap(v[i], v[i + 1]);
                    Visualize::visualizeBar(v, i, "Even Odd Sort");
                    Visualize::visualizeBar(v, i + 1, "Even Odd Sort");
                    Visualize::visualize(v, "Even Odd Sort");
                    isSorted = false;
                }
            }
            for (uint32_t i{static_cast<uint32_t>(v.size() - 1)}; i > 0; --i) {
                if (v[i].first < v[i - 1].first) {
                    std::swap(v[i], v[i - 1]);
                    Visualize::visualizeBar(v, i, "Even Odd Sort");
                    Visualize::visualizeBar(v, i - 1, "Even Odd Sort");
                    Visualize::visualize(v, "Even Odd Sort");
                    isSorted = false;
                }
            }
        } while (!isSorted);
        Visualize::visualizeEnding(v, "Even Odd Sort");
    }
};

#endif