//
// Created by marco on 05-08-2023.
//

#ifndef EXAM_REACTIONCOMPONENT_H
#define EXAM_REACTIONCOMPONENT_H

#include <vector>
#include <memory>
class Agent;

using Agents = std::vector<std::shared_ptr<Agent>>;

class ReactionComponent {

    Agents agents;

public:
    void addAgent(Agent &a);
    Agents& getAgents();

    explicit ReactionComponent(Agents agents): agents(std::move(agents)){};
};

// REQUIREMENT 1 - overload operators to support reaction rule typesetting in code
ReactionComponent operator+ (Agent &lhs, Agent &rhs);
ReactionComponent operator+ (ReactionComponent& lhs, Agent& rhs);

#endif //EXAM_REACTIONCOMPONENT_H
