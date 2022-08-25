#ifndef SLOW_SORT_H
#define SLOW_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class SlowSort : public SortStrategy {
  public:
    SlowSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Slow Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        slowSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Slow Sort");
    }

  private:
    auto slowSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        if (start < end) {
            auto mid{(start + end) / 2};
            slowSort(v, start, mid);
            slowSort(v, mid + 1, end);
            Visualize::visualizeTraverse(v, mid, end, "Slow Sort");
            if (v[mid].first > v[end].first) {
                std::swap(v[mid], v[end]);
            }
            slowSort(v, start, end - 1);
        }
    }
};

#endif