#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "../sortStrategy.h"

class HeapSort : public SortStrategy {
  private:
    void buildMaxHeap(std::vector<std::pair<float, Color>> &v) {
        auto size{v.size()};
        for (auto i = 1; i < size; ++i) {
            if (v[i].first > v[(i - 1) / 2].first) {
                auto j{i};
                while (v[j].first > v[(j - 1) / 2].first) {
                    Visualize::visualizeBar(v, j, "Heap Sort");
                    Visualize::visualizeBar(v, (j - 1) / 2, "Heap Sort");
                    std::swap(v[j], v[(j - 1) / 2]);
                    j = (j - 1) / 2;
                    Visualize::visualizeVector(v, "Heap Sort");
                }
            }
        }
    }

  public:
    explicit HeapSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Heap Sort");
    }

    ~HeapSort() noexcept override = default;

    HeapSort(const HeapSort &other) = delete;

    HeapSort &operator=(const HeapSort &other) = delete;

    HeapSort(HeapSort &&other) noexcept = default;

    HeapSort &operator=(HeapSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        buildMaxHeap(v);
        for (auto i{size - 1}; i > 0; --i) {
            Visualize::visualizeBar(v, 0, "Heap Sort");
            Visualize::visualizeBar(v, i, "Heap Sort");
            std::swap(v[0], v[i]);
            Visualize::visualizeVector(v, "Heap Sort");
            auto j{0};
            while (j * 2 + 1 < i) {
                auto index{j * 2 + 1};
                if (index + 1 < i && v[index].first < v[index + 1].first) {
                    ++index;
                }
                if (v[j].first >= v[index].first) { break; }
                Visualize::visualizeBar(v, j, "Heap Sort");
                Visualize::visualizeBar(v, index, "Heap Sort");
                std::swap(v[j], v[index]);
                j = index;
                Visualize::visualizeVector(v, "Heap Sort");
            }
        }
        Visualize::visualizeEnding(v, "Heap Sort");
    }
};

#endif