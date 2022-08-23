#ifndef CYCLE_SORT_H
#define CYCLE_SORT_H

#include "../sortStrategy.h"

class CycleSort : public SortStrategy {
public:
  explicit CycleSort(int size) : SortStrategy(size) {
    Visualize::visualizeSortTitle("Cycle Sort");
  }

  ~CycleSort() noexcept override = default;

  CycleSort(const CycleSort &other) = delete;

  CycleSort &operator=(const CycleSort &other) = delete;

  CycleSort(CycleSort &&other) noexcept = default;

  CycleSort &operator=(CycleSort &&other) noexcept = default;

  void sort() override {
    auto v{vector_.getVector()};
    auto size{v.size()};
    auto rank{0};
    for (auto cycleStart{0}; cycleStart != size; ++cycleStart) {
      do {
        Visualize::visualizeTraverse(v, rank, cycleStart, "Cycle Sort");
        rank = cycleStart;
        for (auto i{cycleStart + 1}; i < size; ++i) {
          if (v[i].first < v[cycleStart].first) {
            ++rank;
          }
        }
        if (rank == cycleStart) {
          break;
        }
        Visualize::visualizeTraverse(v, rank, cycleStart, "Cycle Sort");
        std::swap(v[rank], v[cycleStart]);
      } while (rank != cycleStart);
    }
    Visualize::visualizeEnding(v, "Cycle Sort");
  }
};

#endif