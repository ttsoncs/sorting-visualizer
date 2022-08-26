#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class HeapSort : public SortStrategy {
  public:
    HeapSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Heap Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        heapSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Heap Sort");
    }

  private:
    auto heapSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        buildMaxHeap(v);
        for (auto i{end}; i != start; --i) {
            Visualize::visualizeTraverse(v, 0, i, "Heap Sort");
            std::swap(v[0], v[i]);
            auto j{0};
            while (j * 2 + 1 < i) {
                auto index{j * 2 + 1};
                if (index + 1 < i && v[index].first < v[index + 1].first) {
                    ++index;
                }
                if (v[j].first >= v[index].first) {
                    break;
                }
                Visualize::visualizeTraverse(v, j, index, "Heap Sort");
                std::swap(v[j], v[index]);
                j = index;
            }
        }
    }

    auto buildMaxHeap(std::vector<std::pair<int, std::pair<float, Color>>> &v) -> void {
        auto size{v.size()};
        for (auto i{1}; i != size; ++i) {
            if (v[i].first > v[(i - 1) / 2].first) {
                auto j{i};
                while (v[j].first > v[(j - 1) / 2].first) {
                    Visualize::visualizeTraverse(v, j, (j - 1) / 2, "Heap Sort");
                    std::swap(v[j], v[(j - 1) / 2]);
                    j = (j - 1) / 2;
                }
            }
        }
    }
};

#endif