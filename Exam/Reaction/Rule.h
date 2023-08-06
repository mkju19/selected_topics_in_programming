//
// Created by marco on 06-08-2023.
//

#ifndef EXAM_RULE_H
#define EXAM_RULE_H

#include <utility>
#include <vector>
#include <memory>

class Agent;
class ReactionComponent;

using Agents = std::vector<std::shared_ptr<Agent>>;

class Rule {
    Agents inputAgents;
    Agents outputAgents;
public:
    Rule(Agents lhs, Agents rhs): inputAgents(std::move(lhs)), outputAgents(std::move(rhs)){};
    Agents getInputAgents(){return inputAgents;};
    Agents getOutputAgents(){return outputAgents;};
};

// REQUIREMENT 1 - overload operators to support reaction rule typesetting in code
Rule operator>>= (Agent &input, Agent &output);
Rule operator>>= (Agent &input, ReactionComponent &&output);
Rule operator>>= (ReactionComponent &&input, Agent &output);
Rule operator>>= (ReactionComponent &&input, ReactionComponent &&output);

#endif //EXAM_RULE_H
