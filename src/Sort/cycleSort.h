#ifndef CYCLE_SORT_H
#define CYCLE_SORT_H

#include "../sort.h"

class CycleSort : public SortStrategy {
  public:
    explicit CycleSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Cycle Sort");
    }

    ~CycleSort() noexcept override = default;

    CycleSort(const CycleSort &other) = delete;

    CycleSort &operator=(const CycleSort &other) = delete;

    CycleSort(CycleSort &&other) noexcept = default;

    CycleSort &operator=(CycleSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v = vector_.getVector();
        uint32_t rank{0};
        for (uint32_t cycleStart{0}; cycleStart < v.size(); ++cycleStart) {
            do {
                rank = cycleStart;
                for (uint32_t i{cycleStart + 1}; i < v.size(); ++i) {
                    if (v[i].first < v[cycleStart].first) { ++rank; }
                }
                if (rank == cycleStart) { break; }
                std::swap(v[rank], v[cycleStart]);
                Visualize::visualizeBar(v, rank, "Cycle Sort");
                Visualize::visualizeBar(v, cycleStart, "Cycle Sort");
                Visualize::visualize(v, "Cycle Sort");
                if (IsKeyPressed(KEY_Q)) { return; }
            } while (rank != cycleStart);
        }
        Visualize::visualizeEnding(v, "Cycle Sort");
    }
};

#endif