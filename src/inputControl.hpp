#pragma once

#include <math/math.hpp>

class InputControl {
public:
    InputControl();

    void addAmount(float amountToAdd);

    float getAmount();

private:
    float amount;
};

inline InputControl::InputControl() : amount(0.0f) {}

inline void InputControl::addAmount(float amountToAdd) {
    amount += amountToAdd;
}

inline float InputControl::getAmount() {
    return Math::clamp(amount, -1.0f, 1.0f);
}