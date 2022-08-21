#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "../sort.h"

class HeapSort : public SortStrategy {
  public:
    explicit HeapSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Heap Sort");
    }

    ~HeapSort() noexcept override = default;

    HeapSort(const HeapSort &other) = delete;

    HeapSort &operator=(const HeapSort &other) = delete;

    HeapSort(HeapSort &&other) noexcept = default;

    HeapSort &operator=(HeapSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        for (uint32_t i{static_cast<uint32_t>(v_.size()) / 2}; i > 0; --i) {
            heapify(v_, i, v_.size() - 1);
            Visualize::visualize(v_, "Heap Sort");
        }

        for (uint32_t i{static_cast<uint32_t>(v_.size() - 1)}; i > 0; --i) {
            std::swap(v_[0], v_[i]);
            heapify(v_, 0, i - 1);
            Visualize::visualize(v_, "Heap Sort");
        }
        Visualize::visualizeEnding(v_, "Heap Sort");
    }

  private:
    void heapify(std::vector<std::pair<float, Color>> &v, uint32_t index, uint32_t size) {
        uint32_t child{index * 2};
        while (child <= size) {
            if (child < size && v[child].first < v[child + 1].first) {
                ++child;
            }
            if (v[index].first >= v[child].first) {
                break;
            }
            std::swap(v[index], v[child]);
            index = child;
            child = index * 2;
        }
    }

};

#endif