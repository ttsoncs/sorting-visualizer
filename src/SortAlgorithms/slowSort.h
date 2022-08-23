#ifndef SLOW_SORT_H
#define SLOW_SORT_H

#include "../sortStrategy.h"

class SlowSort : public SortStrategy {
private:
  void slowSort(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                int left, int right) {
    if (left < right) {
      auto mid{(left + right) / 2};
      slowSort(v, left, mid);
      slowSort(v, mid + 1, right);
      Visualize::visualizeTraverse(v, mid, right, "Slow Sort");
      if (v[mid].first > v[right].first) {
        std::swap(v[mid], v[right]);
      }
      slowSort(v, left, right - 1);
    }
  }

public:
  explicit SlowSort(int size) : SortStrategy(size) {
    Visualize::visualizeSortTitle("Slow Sort");
  }

  ~SlowSort() noexcept override = default;

  SlowSort(const SlowSort &other) = delete;

  SlowSort &operator=(const SlowSort &other) = delete;

  SlowSort(SlowSort &&other) noexcept = default;

  SlowSort &operator=(SlowSort &&other) noexcept = default;

  void sort() override {
    auto v{vector_.getVector()};
    slowSort(v, 0, v.size() - 1);
    Visualize::visualizeEnding(v, "Slow Sort");
  }
};

#endif