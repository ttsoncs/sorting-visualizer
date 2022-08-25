#ifndef SORT_CONTROLLER_H
#define SORT_CONTROLLER_H

#include "SortAlgorithms/Exchange/bubbleSort.h"
#include <memory>

class SortController {
  private:
    std::unique_ptr<SortStrategy> sortStrategy_;

  public:
    SortController() {
        sortStrategy_ = std::make_unique<BubbleSort>();
    }

    explicit SortController(std::unique_ptr<SortStrategy> sortStrategy)
        : sortStrategy_{std::move(sortStrategy)} {}

    void setSortStrategy(std::unique_ptr<SortStrategy> sortStrategy) {
        sortStrategy_ = std::move(sortStrategy);
    }

    void sort() { sortStrategy_->sort(); }
};

#endif