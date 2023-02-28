//
// Created by marco on 21-02-2023.
//

#ifndef EXERCISE5_1_BASE_H
#define EXERCISE5_1_BASE_H


class base {
public:
    int i = 0;
    virtual void increment() = 0;
    void decrement() {i--;};
};


#endif //EXERCISE5_1_BASE_H
