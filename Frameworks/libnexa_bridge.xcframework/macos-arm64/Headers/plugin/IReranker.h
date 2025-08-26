#pragma once

#include "../ml.h"

namespace nexa {

class IReranker {
   public:
    virtual ~IReranker() = default;

    virtual int32_t create(const ml_RerankerCreateInput*) = 0;

    virtual int32_t rerank(const ml_RerankerRerankInput*, ml_RerankerRerankOutput*) = 0;
};

}  // namespace nexa
