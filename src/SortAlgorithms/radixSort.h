#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "../sortStrategy.h"

class RadixSort : public SortStrategy {
private:
  void radixSort(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                 int start, int end) {
    if (start < end) {
      auto max{v[start].first};
      auto j{start};
      for (auto i{start + 1}; i != end; ++i) {
        if (v[i].first > max) {
          Visualize::visualizeTraverse(v, i, j, "Radix Sort");
          max = v[i].first;
          j = i;
        }
      }
      auto exp{1};
      while (max / exp > 0) {
        countSort(v, start, end, exp);
        exp *= 10;
      }
    }
  }
  void countSort(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                 int start, int end, int exp) {
    std::vector<std::pair<int, std::pair<float, Color>>> temp(end - start +
                                                                1);
    std::vector<int> count(10);
    for (auto i{start}; i != end + 1; ++i) {
      ++count[(v[i].first / exp) % 10];
    }
    for (auto i{1}; i != 10; ++i) {
      Visualize::visualizeTraverse(v, i, i - 1, "Radix Sort");
      count[i] += count[i - 1];
    }
    for (auto i{end}; i != start - 1; --i) {
      auto j{(v[i].first / exp) % 10};
      Visualize::visualizeTraverse(v, i, count[j] - 1, "Radix Sort");
      temp[count[j] - 1] = v[i];
      --count[j];
    }
    for (auto i{start}; i != end + 1; ++i) {
      Visualize::visualizeTraverse(v, i, i - start, "Radix Sort");
      v[i] = temp[i - start];
    }
  }

public:
  explicit RadixSort(int size) : SortStrategy(size) {
    Visualize::visualizeSortTitle("Radix Sort");
  }

  ~RadixSort() noexcept override = default;

  RadixSort(const RadixSort &other) = delete;

  RadixSort &operator=(const RadixSort &other) = delete;

  RadixSort(RadixSort &&other) noexcept = default;

  RadixSort &operator=(RadixSort &&other) noexcept = default;

  void sort() override {
    auto v{vector_.getVector()};
    radixSort(v, 0, v.size() - 1);
    Visualize::visualizeEnding(v, "Radix Sort");
  }
};
#endif