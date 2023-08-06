#include "Agent.h"

std::ostream &operator<<(std::ostream &out , const Agent &agent) {
    return out << "(" << agent.id << ":" << agent.value << ")";
}

