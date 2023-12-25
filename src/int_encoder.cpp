#include <int_encoder.h>

IntEncoder::IntEncoder(int value) {
    result = value % MAX_RETURN_VALUE;
}