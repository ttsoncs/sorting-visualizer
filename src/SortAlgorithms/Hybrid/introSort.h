#ifndef INTRO_SORT_H
#define INTRO_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class IntroSort : public SortStrategy {
  public:
    IntroSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Intro Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        auto depthLimit{2 * log2(v.size() - 1)};
        introSort(v, 0, v.size() - 1, depthLimit);
        Visualize::visualizeEnding(v, "Intro Sort");
    }

  private:
    auto introSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end, int depth) -> void {
        auto size{end - start + 1};
        if (size <= 16) {
            insertionSort(v, start, end);
            return;
        }
        if (depth == 0) {
            heapSort(v, start, end);
            return;
        }
        auto i{start};
        auto j{end};
        auto pivot{v[(start + end) / 2]};
        while (i <= j) {
            while (v[i].first < pivot.first) {
                ++i;
            }
            while (v[j].first > pivot.first) {
                --j;
            }
            Visualize::visualizeTraverse(v, i, j, "Intro Sort");
            if (i <= j) {
                std::swap(v[i], v[j]);
                ++i;
                --j;
            }
        }
        if (start < j) {
            introSort(v, start, j, depth - 1);
        }
        if (i < end) {
            introSort(v, i, end, depth - 1);
        }
    }

    auto
    partition(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> int {
        auto pivot{v[end].first};
        auto i{start - 1};
        for (auto j{start}; j < end; j++) {
            if (v[j].first <= pivot) {
                Visualize::visualizeTraverse(v, i + 1, j, "Intro Sort");
                i++;
                std::swap(v[i], v[j]);
            }
        }
        Visualize::visualizeTraverse(v, i + 1, end, "Intro Sort");
        std::swap(v[i + 1], v[end]);
        return i + 1;
    }

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

    auto insertionSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{start + 1}; i != end + 1; ++i) {
            auto temp = v[i];
            auto j{i};
            while (j > 0 && v[j - 1].first > temp.first) {
                Visualize::visualizeTraverse(v, j - 1, j, "Intro Sort");
                v[j] = v[j - 1];
                --j;
            }
            Visualize::visualizeTraverse(v, j, i, "Intro Sort");
            v[j] = temp;
        }
    }
};

#endif