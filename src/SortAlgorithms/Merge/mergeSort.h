#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class MergeSort : public SortStrategy {
  public:
    MergeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Merge Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        mergeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Merge Sort");
    }

  private:
    auto mergeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end)-> void {
        if (start < end) {
            auto mid{(start + end) / 2};
            mergeSort(v, start, mid);
            mergeSort(v, mid + 1, end);
            merge(v, start, mid, end);
        }
    }

    auto merge(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int mid, int end)-> void {
        std::vector<std::pair<int, std::pair<float, Color>>> temp(end - start + 1);
        auto i{start};
        auto j{mid + 1};
        auto k{0};
        while (i <= mid && j <= end) {
            Visualize::visualizeTraverse(v, i, j, "Merge Sort");
            if (v[i].first < v[j].first) {
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        while (i <= mid) {
            Visualize::visualizeTraverse(v, i, j, "Merge Sort");
            temp[k++] = v[i++];
        }
        while (j <= end) {
            Visualize::visualizeTraverse(v, i, j, "Merge Sort");
            temp[k++] = v[j++];
        }
        auto size{temp.size()};
        for (auto i{0}; i != size; ++i) {
            v[start + i] = temp[i];
        }
    }
};

#endif