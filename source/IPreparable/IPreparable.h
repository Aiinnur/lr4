#pragma once
#include "../IDrawable/IDrawable.h"

class IPreparable :public IDrawable {
public:
    virtual void prepare_for_drawing() = 0; //       .
    virtual ~IPreparable() {} //       .
};
