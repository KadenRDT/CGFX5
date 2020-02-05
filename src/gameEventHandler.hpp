#pragma once

#include "core/iapplicationEventHandler.hpp"
#include "dataStructures/map.hpp"
#include "dataStructures/array.hpp"
#include "inputControl.hpp"

class GameEventHandler : public IApplicationEventHandler {
public:
    GameEventHandler() = default;

    ~GameEventHandler() override = default;

    void onKeyDown(uint32 keyCode, bool isRepeat) override;

    void onKeyUp(uint32 keyCode, bool isRepeat) override;

    void onMouseDown(uint32 mouseButton, uint8 numClicks) override;

    void onMouseUp(uint32 mouseButton, uint8 numClicks) override;

    void onMouseMove(int32 mousePosX, int32 mousePosY,
                     int32 deltaX, int32 deltaY) override;

    void addKeyControl(uint32 keyCode, InputControl &inputControl, float weight = 1.0f);

    void addMouseControl(uint32 mouseButton, InputControl &inputControl, float weight = 1.0f);

private:
    Map<uint32, Array<std::pair<float, InputControl &>>> inputs;

    void updateInput(uint32 inputCode, float direction, bool isRepeat);
};