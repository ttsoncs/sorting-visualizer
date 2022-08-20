#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "../sort.h"

class CombSort : public SortStrategy {
  public:
    explicit CombSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Comb Sort");
    }

    ~CombSort() noexcept override = default;

    CombSort(const CombSort &other) = delete;

    CombSort &operator=(const CombSort &other) = delete;

    CombSort(CombSort &&other) noexcept = default;

    CombSort &operator=(CombSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        uint32_t gap{static_cast<uint32_t>(v_.size())};
        bool swapped{true};
        while (gap > 1 || swapped) {
            if (gap > 1) {
                gap = static_cast<uint32_t>(static_cast<double>(gap) / 1.3);
            }
            swapped = false;
            for (uint32_t i{0}; i < v_.size() - gap; ++i) {
                Visualize::visualizeBar(v_, i, "Comb Sort");
                Visualize::visualizeBar(v_, i + gap, "Comb Sort");                
                if (v_[i].first > v_[i + gap].first) {
                    std::swap(v_[i], v_[i + gap]);
                    swapped = true;
                }
                if (IsKeyPressed(KEY_Q)) { return; }
                Visualize::visualize(v_, "Comb Sort");
            }
        }
        Visualize::visualizeEnding(v_, "Comb Sort");
    }
};

#endif