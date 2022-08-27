#ifndef INTERPOLATION_SORT_H
#define INTERPOLATION_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class InterpolationSort : public SortStrategy {
  public:
    InterpolationSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Interpolation Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        interpolationSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Interpolation Sort");
    }

  private:
    auto interpolationSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
          
    }
};

#endif