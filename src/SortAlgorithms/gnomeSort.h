#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "../sortStrategy.h"

class GnomeSort : public SortStrategy {
  public:
    explicit GnomeSort(int size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Gnome Sort");
    }

    ~GnomeSort() noexcept override = default;

    GnomeSort(const GnomeSort &other) = default;

    GnomeSort &operator=(const GnomeSort &other) = default;

    GnomeSort(GnomeSort &&other) noexcept = default;

    GnomeSort &operator=(GnomeSort &&other) noexcept = default;

    void sort() override {
        auto v{vector_.getVector()};
        auto size{v.size()};
        auto index{0};
        while (index != size) {
            Visualize::visualizeTraverse(v, index, index - 1, "Gnome Sort");
            if (index == 0 || v[index].first >= v[index - 1].first) {
                ++index;
            } else {
                std::swap(v[index], v[index - 1]);
                --index;
            }
        }
        Visualize::visualizeEnding(v, "Gnome Sort");
    }
};

#endif