#pragma once

#include "ml.h"

namespace nexa {

class IEmbedding {
   public:
    virtual ~IEmbedding() = default;

    virtual int32_t create(const ml_EmbedderCreateInput*) = 0;

    virtual int32_t embed(const ml_EmbedderEmbedInput*, ml_EmbedderEmbedOutput*) = 0;

    virtual int32_t embedding_dim(ml_EmbedderDimOutput*) = 0;
};

}  // namespace nexa
