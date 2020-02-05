#pragma once

#include <utility>

#include "ecsComponent.hpp"

class BaseECSSystem {
public:
    BaseECSSystem(Array<uint32> componentTypesIn) : componentTypes(std::move(componentTypesIn)) {}

    virtual void updateComponents(float delta, BaseECSComponent **components) {}

    const Array<uint32> &getComponentTypes() {
        return componentTypes;
    }

private:
    Array<uint32> componentTypes;
};