#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class GnomeSort : public SortStrategy {
  public:
    GnomeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Gnome Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        gnomeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Gnome Sort");
    }

  private:
    auto gnomeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        auto index{start};
        while (index != end + 1) {
            Visualize::visualizeTraverse(v, index, index - 1, "Gnome Sort");
            if (index == 0 || v[index].first >= v[index - 1].first) {
                ++index;
            } else {
                std::swap(v[index], v[index - 1]);
                --index;
            }
        }
    }
};

#endif