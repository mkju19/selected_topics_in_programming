/**
 * Definitions of number_series and number_series_wrap classes.
 */

#ifndef INCLUDE_NUMBER_SERIES_H
#define INCLUDE_NUMBER_SERIES_H

#include <vector>
#include <limits>
#include <memory>
#include <iostream>

namespace data_series
{
    class number_series
    {
    private:
        std::vector<int> numbers {};
        int minimum = INT_MIN;
        int maximum = INT_MAX;

        std::vector<int> add_numbers(const number_series &other) const;
        void updateMinMax();
    public:
        number_series()=default;
        explicit number_series(std::vector<int> nums);
        static number_series make_random(const int & size);
        number_series operator+(const number_series &other) const;
        number_series operator+=(const number_series &other);
        bool operator<(const number_series &other) const;

        friend std::ostream& operator<<(std::ostream& os, const number_series& n);
    };


    class number_series_wrap
    {
    private:
        std::unique_ptr<number_series> ns;
    public:
        number_series_wrap()=default;
        explicit number_series_wrap(std::vector<int> nums);
        explicit number_series_wrap(number_series n);

        static number_series_wrap make_random(const int & size);
        number_series_wrap operator+(const number_series_wrap &other) const;
        number_series_wrap &operator+=(const number_series_wrap &other);
        bool operator<(const number_series_wrap &other) const;

        friend std::ostream& operator<<(std::ostream& os, const number_series_wrap& n);
    };

}  // namespace data_series

#endif  // INCLUDE_NUMBER_SERIES_H
