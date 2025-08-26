#pragma once

#include "ml.h"

namespace nexa {

class ITts {
   public:
    virtual ~ITts() = default;

    virtual int32_t create(const ml_TtsCreateInput*) = 0;

    virtual int32_t synthesize(const ml_TtsSynthesizeInput*, ml_TtsSynthesizeOutput*) = 0;

    virtual int32_t list_available_voices(const ml_TtsListAvailableVoicesInput*, ml_TtsListAvailableVoicesOutput*) = 0;
};

}  // namespace nexa
