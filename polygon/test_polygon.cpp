#include "polygon.hpp"
#include <iostream>
#include <vector>

/**
 * Code to test the understanding of special member functions and references.
 * @author Marius Mikucionis <marius@cs.aau.dk>
 */

polygon polygon_factory(size_t count){ return polygon(count); }

void draw_value(polygon) { std::cout << "passed-by-value\n"; }
void draw(const polygon&) { std::cout << "passed-by-const-reference\n"; }
void draw(polygon&) { std::cout << "passed-by-lvalue-reference\n"; }
void draw(polygon&&) { std::cout << "passed-by-rvalue-reference\n"; }

int main()
{
    polygon pq{};
    polygon pp = pq;

    std::string ruler(40, '-');
    // TODO: Replace "???" with your predictions: what gets printed after each line?
    //       Note that some statements may print more than one line.
    // TODO: After all "???" are gone, step through the program in debugger and check your answers against output.
    // TODO: Answer the additional questions below.
    {   // for example:
        std::cout << ruler << std::endl;
        polygon poly{};
        // default-constructor
        // destructor
    }
    {
        std::cout << ruler << std::endl;
        polygon poly{1};
        // TODO:
//        std::cout   << "Prediction: \n"
//                    <<"Custom constructor (1) \n"
//                    << "Destructor \n";
    }
    {
        std::cout << ruler << std::endl;
        polygon poly{1};
        // TODO:
//        std::cout   << "Prediction: \n"
//                    <<"Custom constructor (1) \n"
//                    << "Destructor \n";
    }
    {
        std::cout << ruler << std::endl;
        const polygon poly0{};
        // TODO:
//        std::cout   << "Prediction: \n"
//                    <<"default constructor\n";

        std::cout << ruler << std::endl;
        polygon poly1{poly0};
        // TODO:
//        std::cout   << "Prediction: \n "
//                    << "Copy-constructor \n";

        std::cout << ruler << std::endl;
        polygon poly2 = polygon{2};
        // TODO:
//        std::cout   << "Prediction: \n"
//                    << "Custom constructor (2)\n";
        std::cout << ruler << std::endl;
        polygon poly3{{1,2},{3,4},{5,6},{7,8}};
        // TODO:
//        std::cout   << "Prediction: \n"
//                    << "custom-constructor {point(1,2), point(3,4), point(5,6), point(7,8)}\n";

        std::cout << ruler << std::endl;
        poly2 = poly1;
        // TODO:
//        std::cout   << "Prediction: \n"
//                    << "Copy-assignment\n";

        std::cout << ruler << std::endl;
        poly2 = polygon_factory(3);
        // TODO:
        //  custom-constructor(3)
        //  move-assignment
        //  destructor -- because the rvalue is removed when out of scope

        std::cout << ruler << std::endl;
        draw_value(poly0);
        // TODO:
        //  copy-constructor
        //  Passed by value
        //  destructor

        std::cout << ruler << std::endl;
        draw(poly0);
        // TODO:
        //  Passed by const reference

        std::cout << ruler << std::endl;
        draw(poly1);
        // TODO: passed by r-value reference

        std::cout << ruler << std::endl;
        draw(polygon_factory(4));
        // TODO:
        //  custom constructor(4)

        std::cout << ruler << std::endl;
        std::vector<polygon> polies(4, poly3);
        // TODO:
        //  Copy-constructor
        //  Copy-constructor
        //  Copy-constructor
        //  Copy-constructor

        std::cout << ruler << std::endl;
        std::cout << "HERE!\n\n";
        for (auto &p : polies)
            std::cout << p << "\n";
        polies.push_back(poly3);
        // TODO:
        //   Copy-constructor -- first value
        //   move-constructor
        //   destructor
        //   move-constructor
        //   destructor
        //   move-constructor
        //   destructor
        //   move-constructor
        //   destructor
        for (auto &p : polies)
            std::cout<< p << "\n";

        // TODO: Why are so many operations here?
        // push_back creates a new array that is of double size
        // It then copies the first element into the new larger array
        // It then moves the old old elements and destroys the old references into the new array.

        std::cout << ruler << std::endl;
        polies.push_back(poly3);

        // TODO:
        //  Copy-constructor
        // TODO: Why is the number of operations fewer here than for the above one?
        //  The array did not have to expand this time, and therefore did not need to move old values.

        std::cout << ruler << std::endl;
        for (polygon &p : polies)
            std::cout << p << " at " << &p << '\n';
        // TODO:
        //  arst
        // TODO: Can we make the loop above more efficient?
        //  Only use a reference to p instead of copying the value from polies
        // TODO: This is an incredibly common mistake, make sure to fix it, or ask.
    }
    {
        std::cout << ruler << std::endl;

        draw(1);
        // TODO:
        //  Custom-constructor(1)
        //  passed by rvalue reference
        //  destructor
        // TODO: What is going on here? Why "1" is treated as polygon? This is unlikely to be intentional.
        // TODO: Can we forbid the last statement without breaking the previous code?
        //      No it will break other parts of the code since implicit conversion is used elsewhere.
        // TODO: Fix it in polygon.hpp so that this line does not compile.
        //      We can add 'explicit' keyword to the custom constructor,
        //      to make it impossible to do implicit conversions in a function.
    }
    {
        std::cout << ruler << std::endl;
        polygon poly{2};
        std::cout << poly << " at " << &poly << std::endl;
        draw_value(std::move(poly));
        // TODO:
        //  Custom-constructor(2)
        //  Pass-by-value
        //  polly is no longer initialized;
        std::cout << poly << " at " << &poly << std::endl;
        // TODO: What was inside poly before draw_value call?
        //      The polygon
        // TODO: What is inside poly after draw_value call? Why?
        //      Random value that is interpreted as a polygon
    }
    {
        std::cout << ruler << std::endl;
        polygon poly{2};
        std::cout << poly << " at " << &poly << std::endl;
        draw(std::move(poly));
        // TODO:
        //  Custom-constructor
        //  Point point
        //  Move-constructor
        std::cout << poly << " at " << &poly << std::endl;
        // TODO: What was inside poly before draw call?
        //      A polygon with two points
        // TODO: What is inside poly after draw call? Why?
        //      an empty polygon, because the move constructor swaps the count and pointer with 0 and nullptr.
    }
    std::cout << ruler << ruler << std::endl;
}
