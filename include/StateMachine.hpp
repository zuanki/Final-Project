#pragma once

#include <memory>
#include <stack>
#include <State.hpp>

using StateRef = std::unique_ptr<State>;

class StateMachine
{
public:
    StateMachine() = default;
    ~StateMachine() = default;
    void addState(StateRef newState, bool isReplacing = true);
    void removeState();
    void processStateChanges();
    StateRef &getActiveState();

private:
    std::stack<StateRef> states;
    StateRef newState;
    bool isAdding;
    bool isReplacing;
    bool isRemoving;
};