#include "Rule.h"
#include "Agent.h"
#include "ReactionComponent.h"

// REQUIREMENT 1 - overload operators to support reaction rule typesetting in code
Rule operator>>=(Agent &input, Agent &output) {
    auto p_input = std::make_shared<Agent>(input);
    auto p_output = std::make_shared<Agent>(output);

    auto v_input = std::vector{std::move(p_input)};
    auto v_output = std::vector{std::move(p_output)};
    return {std::move(v_input), std::move(v_output)};
}
Rule operator>>=(Agent &input, ReactionComponent &&output) {
    auto p_input = std::make_shared<Agent>(input);

    return Rule(std::vector{std::move(p_input)}, std::move(output.getAgents()));
}
Rule operator>>=(ReactionComponent &&input, Agent &output) {
    auto p_output = std::make_shared<Agent>(output);

    return Rule(std::move(input.getAgents()), std::vector{std::move(p_output)});
}
Rule operator>>=(ReactionComponent &&input, ReactionComponent &&output) {
    return {std::move(input.getAgents()), std::move(output.getAgents())};
}
