#ifndef TIM_SORT_H
#define TIM_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class TimSort : public SortStrategy {
  public:
    TimSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Tim Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        timSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Tim Sort");
    }

  private:
    auto timSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto size{end - start + 1};
        if (size <= 16) {
            insertionSort(v, start, end);
            return;
        }
        auto mid{(start + end) / 2};
        timSort(v, start, mid);
        timSort(v, mid + 1, end);
        if (v[mid].first > v[mid + 1].first) {
            merge(v, start, mid, end);
        }
    }

    auto insertionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{start + 1}; i != end + 1; ++i) {
            auto [barHeight, color] = v[i];
            auto j{i};
            while (j > start && v[j - 1].first > barHeight) {
                Visualize::visualizeTraverse(v, j, j - 1, "Tim Sort");
                v[j] = v[j - 1];
                --j;
            }
            Visualize::visualizeTraverse(v, j, i, "Tim Sort");
            v[j] = std::make_pair(barHeight, color);
        }
    }

    auto merge(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int mid, int end) -> void {
        std::vector<std::pair<int, std::pair<float, Color>>> temp(end - start + 1);
        auto i{start};
        auto j{mid + 1};
        auto k{0};
        while (i <= mid && j <= end) {
            Visualize::visualizeTraverse(v, i, j, "Tim Sort");
            if (v[i].first < v[j].first) {
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        while (i <= mid) {
            Visualize::visualizeTraverse(v, i, j, "Tim Sort");
            temp[k++] = v[i++];
        }
        while (j <= end) {
            Visualize::visualizeTraverse(v, i, j, "Tim Sort");
            temp[k++] = v[j++];
        }
        for (auto i{0}; i != temp.size(); ++i) {
            v[start + i] = temp[i];
        }
    }
};

#endif