#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "../sort.h"

class GnomeSort : public SortStrategy {
  public:
    explicit GnomeSort(uint32_t size) : SortStrategy(size) {
        Visualize::drawSortTitle("Gnome Sort");
    }

    ~GnomeSort() noexcept override = default;

    GnomeSort(const GnomeSort &other) = delete;

    GnomeSort &operator=(const GnomeSort &other) = delete;

    GnomeSort(GnomeSort &&other) noexcept = default;

    GnomeSort &operator=(GnomeSort &&other) noexcept = default;

    void sort() override {
        std::vector<std::pair<float, Color>> v_ = vector_.getVector();
        uint32_t i{0};
        while (i < v_.size()) {
            Visualize::visualizeBar(v_, i, "Gnome Sort");
            if (i == 0 || v_[i].first >= v_[i - 1].first) {
                ++i;
            } else {
                std::swap(v_[i], v_[i - 1]);
                --i;
            }
            Visualize::visualize(v_, "Gnome Sort");
            if (IsKeyPressed(KEY_Q)) { return; }
        }
        Visualize::visualizeEnding(v_, "Gnome Sort");
    }
};

#endif