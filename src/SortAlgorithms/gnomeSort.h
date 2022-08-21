#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "../sortStrategy.h"
class GnomeSort : public SortStrategy {
  public:
    explicit GnomeSort(uint32_t size) : SortStrategy(size) {
        Visualize::visualizeSortTitle("Gnome Sort");
    }

    ~GnomeSort() noexcept override = default;

    GnomeSort(const GnomeSort &other) = delete;

    GnomeSort &operator=(const GnomeSort &other) = delete;

    GnomeSort(GnomeSort &&other) noexcept = default;

    GnomeSort &operator=(GnomeSort &&other) noexcept = default;

    void sort() override {
        auto v = vector_.getVector();
        auto size = v.size();
        auto index{0};
        while (index < size) {
            if (index == 0 || v[index].first >= v[index - 1].first) {
                ++index;
            } else {
                Visualize::visualizeBar(v, index, "Gnome Sort");
                Visualize::visualizeBar(v, index - 1, "Gnome Sort");
                std::swap(v[index], v[index - 1]);
                --index;
                Visualize::visualizeVector(v, "Gnome Sort");
            }
        }
        Visualize::visualizeEnding(v, "Gnome Sort");
    }
};

#endif