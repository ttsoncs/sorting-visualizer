#ifndef GRAVITY_SORT_H
#define GRAVITY_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class GravitySort : public SortStrategy {
  public:
    GravitySort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Gravity Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        gravitySort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Gravity Sort");
    }

  private:
    auto gravitySort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
    }
};
#endif