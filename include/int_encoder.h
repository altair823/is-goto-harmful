#pragma once

#include <encoder.h>

constexpr size_t MAX_RETURN_VALUE = 255;

class IntEncoder : public Encoder {
    public:
        IntEncoder(int value);
        unsigned int encode() override;
};