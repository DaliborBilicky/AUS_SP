#pragma once
#include <libds/heap_monitor.h>
#include <libds/amt/implicit_sequence.h>

template<typename T>
class Sorter {
  public:
    void sort(ds::amt::ImplicitSequence<T> &is, std::function<int(const T&, const T&)> compare);

  private:
    void quickSort(ds::amt::ImplicitSequence<T> &is, std::function<int(const T&, const T&)> compare, size_t min, size_t max);
};

template<typename T>
void Sorter<T>::sort(ds::amt::ImplicitSequence<T> &is, std::function<int(const T&, const T&)> compare) {
	if (!is.isEmpty())
	{
		this->quickSort(is, compare, 0, is.size() - 1);
	}
}

template<typename T>
void Sorter<T>::quickSort(ds::amt::ImplicitSequence<T> &is, std::function<int(const T&, const T&)> compare, size_t min, size_t max) {
	T pivot = is.access((min + max) / 2)->data_;
	size_t left = min;
	size_t right = max;

	while (left <= right) {
		while (compare(is.access(left)->data_, pivot) < 0) {
			++left;
		}

		while (compare(is.access(right)->data_, pivot) > 0) {
			--right;
		}

		if (left <= right) {
			std::swap(is.access(left)->data_, is.access(right)->data_);
			++left;
			if (right > 0) {
				--right;
			}
		}
	}

	if (min < right) {
		this->quickSort(is, compare, min, right);
	}

	if (left < max) {
		this->quickSort(is, compare, left, max);
	}
}
