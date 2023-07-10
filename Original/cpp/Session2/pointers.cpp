#include <iostream>

double max1(double *a, double *b);
double max2(double &a, double &b);
double max3(const double &a, const double &b);
double max5(double* &a, double* &b);
double max6(double* const&a, double* const&b);
void pointersAndRefs(){
    double f1 = 1.0f, f2 = 2.0f;

    double res1 = max1(&f1, &f2);
    std::cout<< "C-style call by reference parameters: " << res1 << "\n";

    res1 = max2(f1, f2);
    std::cout<< "Call by C++ references: " << res1 << "\n";

    res1 = max3( f1, f2);
    std::cout<< "Call by C++ const references: " << res1 << "\n";

    //this seems to be working fine
//    double &ref = f1;
//    double *ptr = &ref;
//    double *ptr2 = &f1;
//    std::cout << "Pointers to references do not exist: " << ptr << "\n";
//    std::cout << "Pointers to references do not exist: " << ptr2 << "\n";

    double *pf1 = &f1, *pf2 = &f2;
    res1 = max5(pf1, pf2);
    std::cout<< "References to pointers: " << res1 << "\n";

    res1 = max6(pf1, pf2);
    std::cout<< "Const references to pointers: " << res1 << "\n";

}

double max0(double a, double b)
{ return a < b ? b : a; }

double max1(double *a, double *b){

    return *a < *b ? *b :*a;
}

double max2(double &a, double &b){
    std::cout << a;
    return a < b ? b :a;
}

double max3(const double &a, const double &b){
    return a < b ? b :a;
}

//double maxError(const double & *a, const double & *b){
//    return *a;//a < b ? b :a;
//}

double max5(double* &a, double* &b){
    return *a < *b ? *b :*a;
}

double max6(double* const&a, double* const&b){
    return *a < *b ? *b :*a;
}