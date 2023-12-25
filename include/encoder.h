#pragma once

#include <string>

/**
 * @brief Interface for encoding a value
 * 
 */
class Encoder {
    protected: 
        /**
        * @brief The encoded value to return
        * 
        */
        unsigned int result;
    public:
        /**
        * @brief Encode a value
        * The value to encode is passed in the constructor.
        */
        virtual unsigned int encode() = 0;
};