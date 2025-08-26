#pragma once

#include "ml.h"

namespace nexa {

class IAsr {
   public:
    virtual ~IAsr() = default;

    virtual int32_t create(const ml_AsrCreateInput*) = 0;

    virtual int32_t transcribe(const ml_AsrTranscribeInput*, ml_AsrTranscribeOutput*) = 0;

    virtual int32_t list_supported_languages(
        const ml_AsrListSupportedLanguagesInput*, ml_AsrListSupportedLanguagesOutput*) = 0;
};

}  // namespace nexa
