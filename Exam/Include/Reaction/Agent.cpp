#include "Agent.h"

//REQUIREMENT 2a - Pretty printer in human readable format
std::string Agent::toString() const {
    std::string str = id + ":" + std::to_string(value);
    return str;
}
std::ostream &operator<<(std::ostream &out , const Agent &agent) {
    return out << agent.toString();
}

