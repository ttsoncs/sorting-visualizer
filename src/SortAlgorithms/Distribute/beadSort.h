#ifndef BEAD_SORT_H
#define BEAD_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class BeadSort : public SortStrategy {
  public:
    BeadSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Bead Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        beadSort(v);
        Visualize::visualizeEnding(v, "Bead Sort");
    }

  private:
    auto beadSort(std::vector<std::pair<int, std::pair<float, Color>>> &v) -> void {
        
    }
};

#endif