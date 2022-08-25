#ifndef BINARY_GNOME_SORT
#define BINARY_GNOME_SORT

#include "../../sortStrategy.h"
#include "../../vector.h"
#include "../../visualize.h"

class BinaryGnomeSort : public SortStrategy {
public:
    BinaryGnomeSort() {
        Visualize::visualizeVector(Vector::getVector());
        Visualize::visualizeTitle("Binary Gnome Sort");
    }

    auto sort() -> void override {
        auto v{Vector::getVector()};
        binaryGnomeSort(v, 0, v.size() - 1);
        Visualize::visualizeEnding(v, "Binary Gnome Sort");
    }

  private:
    auto binaryGnomeSort(std::vector<std::pair<int, std::pair<float, Color>>> &v, int start, int end) -> void {
        for (auto i{start + 1}; i != end + 1; ++i) {
            auto key{v[i]};
            auto low{0};
            auto high{i};
            while (low < high) {
                auto mid{(low + high) / 2};
                if (v[mid].first < key.first) {
                    Visualize::visualizeTraverse(v, low, mid + 1, "Binary Gnome Sort");
                    low = mid + 1;
                } else {
                    Visualize::visualizeTraverse(v, mid, high, "Binary Gnome Sort");
                    high = mid;
                }
            }
            for (auto j{i}; j != low; --j) {
                Visualize::visualizeTraverse(v, j, j - 1, "Binary Gnome Sort");
                std::swap(v[j], v[j - 1]);
            }
        }
    }
};

#endif