#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "../sortStrategy.h"

class CountingSort : public SortStrategy {
  private:
    void countingSort(std::vector<std::pair<int, std::pair<float, Color>>> &v,
                      int start, int end) {
        std::vector<int> count(end - start + 1, 0);
        for (auto &i : v) {
            ++count[i.first - start];
        }
        auto countSize{count.size()};
        for (auto i{1}; i != countSize; ++i) {
            Visualize::visualizeTraverse(v, i, i - 1, "Counting Sort");
            count[i] += count[i - 1];
        }
        auto size{v.size()};
        std::vector<std::pair<int, std::pair<float, Color>>> sorted(size);
        for (auto i{size - 1}; i != -1; --i) {
            auto j{count[v[i].first - start]};
            Visualize::visualizeTraverse(v, j - 1, i, "Counting Sort");
            sorted[j - 1] = v[i];
            --j;
        }
        v = std::move(sorted);
    }

  public:
    explicit CountingSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Counting Sort");
    }
    ~CountingSort() noexcept override = default;
    CountingSort(const CountingSort &other) = default;
    CountingSort &operator=(const CountingSort &other) = default;
    CountingSort(CountingSort &&other) noexcept = default;
    void sort() override {
        auto v{vector_.getVector()};
        countingSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Counting Sort");
    }
};

#endif