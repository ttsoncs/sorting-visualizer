#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

#include "../sort.h"

class CocktailSort : public SortStrategy {
  public:
    explicit CocktailSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Cocktail Sort");
    }

    ~CocktailSort() noexcept override = default;

    CocktailSort(const CocktailSort &other) = delete;

    CocktailSort &operator=(const CocktailSort &other) = delete;

    CocktailSort(CocktailSort &&other) noexcept = default;

    CocktailSort &operator=(CocktailSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        bool swapped{true};
        while (swapped) {
            swapped = false;
            for (uint32_t i{0}; i < v_.size() - 1; ++i) {
                Visualize::visualizeBar(v_, i, "Cocktail Sort");
                if (v_[i].first > v_[i + 1].first) {
                    std::swap(v_[i], v_[i + 1]);
                    swapped = true;
                }
                if (IsKeyPressed(KEY_Q)) { return; }
                Visualize::visualize(v_, "Cocktail Sort");
            }
            if (!swapped) { break; }
            swapped = false;
            for (uint64_t i{v_.size() - 1}; i > 0; --i) {
                Visualize::visualizeBar(v_, i, "Cocktail Sort");
                if (v_[i].first < v_[i - 1].first) {
                    std::swap(v_[i], v_[i - 1]);
                    swapped = true;
                }
                if (IsKeyPressed(KEY_Q)) { return; }
                Visualize::visualize(v_, "Cocktail Sort");
            }
        }
        Visualize::visualizeEnding(v_, "Cocktail Sort");
    }
};

#endif