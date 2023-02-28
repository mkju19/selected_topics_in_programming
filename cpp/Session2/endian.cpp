#include <iostream>
#include <bitset>

union Value {
    unsigned int i;
    float f;
    char c[4];
};

void endian(){
    Value a = {.i = 0x31323334};
    for (char i : a.c)
        std::cout<< i;
    std::cout<< "\n";
    if (a.c[0] == '1' && a.c[1] == '2' && a.c[2] == '3' && a.c[3] == '4')
        std::cout<< "Big end \n\n";
    else if (a.c[0] == '4' && a.c[1] == '3' && a.c[2] == '2' && a.c[3] == '1')
        std::cout<< "Little end\n\n";
    else
        std::cout<< "could not determine endianness\n\n";
}

void reinterpretFloat(){
    Value v[4] = {{.f = 1.0f}, {.f = 2.0f}, {.f = 4.0f}, {.f = 8.0f}};

    for (auto item : v){
        auto bits = std::bitset<32>{item.i};
        std::cout   << "Value as float:" << item.f << "\n"
                    << "Value as int: " << item.i << "\n"
                    << "value as bits: " << bits << "\n\n";
    }
}