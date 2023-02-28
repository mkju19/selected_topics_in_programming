#include "number_series.h"

#include <algorithm>
#include <iterator>
#include <random>
#include <functional>

namespace data_series
{
    number_series::number_series(std::vector<int> nums) : numbers{std::move(nums)}{
        updateMinMax();
    }

    number_series number_series::make_random(const int &size) {
        std::vector<int> vec{};
        int min = -100;
        int max = 100;

        auto seed = std::random_device{};
        auto gen = std::mt19937{seed()};
        auto dist = std::uniform_int_distribution{min, max};

        for (int i = 0; i <= size; i++) {
            vec.push_back((dist(gen)));
        }
        return number_series(vec);
    }

    number_series number_series::operator+(const data_series::number_series& other) const{
        auto result = add_numbers(other);

        return number_series{result};
    }

    number_series number_series::operator+=(const data_series::number_series& other){
        this->numbers = add_numbers(other);
        this->updateMinMax();
        return *this;
    }

    bool number_series::operator<(const number_series &other) const{
        auto amplitude1 = this->maximum - this->minimum;
        auto amplitude2 = other.maximum - other.minimum;
        return amplitude1 < amplitude2;
    }

    std::vector<int> number_series::add_numbers(const number_series &other) const{
        auto result = this->numbers;

        if(result.size() < other.numbers.size()) {
            result.resize(other.numbers.size(), 0);
        }

        std::transform(other.numbers.begin(), other.numbers.end(), result.begin(), result.begin(), [](int i, int j){
            return i + j;
        });

        return result;
    }

    void number_series::updateMinMax(){
        minimum = INT_MAX;
        maximum = INT_MIN;
        for (auto i : numbers) {
            minimum = std::min(i, minimum);
            maximum = std::max(i, maximum);
        }
    }

//    number_series_wrap::number_series_wrap() {}


    number_series_wrap::number_series_wrap(std::vector<int> nums) : ns(std::make_unique<number_series>(number_series(std::move(nums)))) {}

    number_series_wrap::number_series_wrap(data_series::number_series n) : ns(std::make_unique<number_series>(std::move(n))){}

    number_series_wrap number_series_wrap::make_random(const int& size){
        return number_series_wrap(number_series::make_random(size));
    }

    number_series_wrap number_series_wrap::operator+(const data_series::number_series_wrap& other) const{
        return number_series_wrap(*ns + *other.ns);
    }

    number_series_wrap &number_series_wrap::operator+=(const data_series::number_series_wrap& other){
        *ns += *other.ns;
//        return number_series_wrap(*ns += *other.ns);
// why does this not work???
        return *this;
    }

    bool number_series_wrap::operator<(const data_series::number_series_wrap& other) const{
        return *ns < *other.ns;
    }

    std::ostream& operator<<(std::ostream& os, const number_series_wrap& n){
        os << *n.ns;
    }

    std::ostream& operator<<(std::ostream& os, const number_series& n){
        os << "Numbers: [";
        for (auto i = 0; i < n.numbers.size(); i++) {
            if (i != n.numbers.size()-1)
                os << n.numbers[i] << ", ";
            else
                os << n.numbers[i];
        }
        os << "]\n";
        os << "Minimum: " << n.minimum << "\n";
        os << "Maximum: " << n.maximum << "\n";
        os << "Amplitude: " << n.maximum - n.minimum << "\n";
        return os;
    }
}  // namespace data_series
