#pragma once

#include "ml.h"

namespace nexa {

class IVlm {
   public:
    virtual ~IVlm() = default;

    virtual int32_t create(const ml_VlmCreateInput* input) = 0;

    virtual int32_t reset() = 0;

    virtual int32_t apply_chat_template(
        const ml_VlmApplyChatTemplateInput* input, ml_VlmApplyChatTemplateOutput* output) = 0;

    virtual int32_t generate(const ml_VlmGenerateInput* input, ml_VlmGenerateOutput* output) = 0;
};

}  // namespace nexa
