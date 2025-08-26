#pragma once

#include "ml.h"

namespace nexa {

class ICv {
   public:
    virtual ~ICv() = default;

    virtual int32_t create(const ml_CVCreateInput* input) = 0;

    virtual int32_t destroy() = 0;

    virtual int32_t infer(const ml_CVInferInput* input, ml_CVInferOutput* output) = 0;
};

}  // namespace nexa