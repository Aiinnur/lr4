#pragma once

#include "CommonBuilder.h"

class ComplexBuilder : public CommonBuilder {
public:
    using CommonBuilder::CommonBuilder;
    void create_rooms() override;
};
