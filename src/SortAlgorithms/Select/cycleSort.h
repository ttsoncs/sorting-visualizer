#ifndef CYCLE_SORT_H
#define CYCLE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class CycleSort : public SortStrategy {
  public:
    CycleSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Cycle Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        cycleSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Cycle Sort");
    }

  private:
    auto cycleSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto rank{0};
        for (auto cycleStart{start}; cycleStart != end + 1; ++cycleStart) {
            do {
                Visualize::visualizeTraverse(v, rank, cycleStart, "Cycle Sort");
                rank = cycleStart;
                for (auto i{cycleStart + 1}; i < end + 1; ++i) {
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
    }
};

#endif