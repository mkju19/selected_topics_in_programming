#include "Agent.h"

//REQUIREMENT 2a - Pretty printer in human readable format
std::ostream &operator<<(std::ostream &out , const Agent &agent) {
    return out << "(" << agent.id << ":" << agent.value << ")";
}
