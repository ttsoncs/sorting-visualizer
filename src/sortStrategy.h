#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H

#include "vector.h"
#include "visualize.h"

class SortStrategy {
  protected:
    Vector vector_;

  public:
    explicit SortStrategy(int size) : vector_(size) {
        Visualize::visualizeVector(vector_.getVector());
    }

    virtual ~SortStrategy() noexcept = default;

    SortStrategy(const SortStrategy &other) = delete;

    SortStrategy &operator=(const SortStrategy &other) = delete;

    SortStrategy(SortStrategy &&other) noexcept = default;

    SortStrategy &operator=(SortStrategy &&other) noexcept = default;

    virtual void sort() = 0;
};

#endif