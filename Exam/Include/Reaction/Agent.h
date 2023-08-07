

#ifndef EXAM_AGENT_H
#define EXAM_AGENT_H

#include <string>
#include <memory>
#include <utility>
#include <vector>

class Agent{
    int value;
    std::string id;
public:
    void setValue(int v){value = v;}
    int getValue(){return value;};
    std::string getId(){return id;};
    Agent(std::string id, const int& val): value(val), id(std::move(id)){};

    //REQUIREMENT 2a - Pretty printer in human readable format
    friend std::ostream& operator<< (std::ostream &, Agent const&);
};

#endif //EXAM_AGENT_H
