#pragma once

#include "ml.h"

namespace nexa {

class ILlm {
   public:
    virtual ~ILlm() = default;

    virtual int32_t create(const ml_LlmCreateInput*) = 0;

    virtual int32_t reset() = 0;

    virtual int32_t save_kv_cache(const ml_KvCacheSaveInput*, ml_KvCacheSaveOutput*) = 0;
    virtual int32_t load_kv_cache(const ml_KvCacheLoadInput*, ml_KvCacheLoadOutput*) = 0;

    virtual int32_t apply_chat_template(const ml_LlmApplyChatTemplateInput*, ml_LlmApplyChatTemplateOutput*) = 0;

    virtual int32_t generate(const ml_LlmGenerateInput*, ml_LlmGenerateOutput*) = 0;
};

}  // namespace nexa
