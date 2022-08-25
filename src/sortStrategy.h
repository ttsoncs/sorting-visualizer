#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H

class SortStrategy {
  public:
    explicit SortStrategy() {}

    virtual ~SortStrategy() noexcept = default;

    SortStrategy(const SortStrategy &other) = delete;

    SortStrategy &operator=(const SortStrategy &other) = delete;

    SortStrategy(SortStrategy &&other) noexcept = default;

    SortStrategy &operator=(SortStrategy &&other) noexcept = default;

    virtual void sort() = 0;
};

#endif