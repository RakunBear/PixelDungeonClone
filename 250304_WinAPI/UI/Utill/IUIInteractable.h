#pragma once

class IUIInteractable {
public:
    virtual bool HandleClick(int x, int y) = 0;
    virtual ~IUIInteractable() = default;
};