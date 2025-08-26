#pragma once

#include "ml.h"

namespace nexa {

class IImageGen {
   public:
    virtual ~IImageGen() = default;

    virtual int32_t create(const ml_ImageGenCreateInput*) = 0;

    virtual int32_t txt2img(const ml_ImageGenTxt2ImgInput*, ml_ImageGenOutput*) = 0;

    virtual int32_t img2img(const ml_ImageGenImg2ImgInput*, ml_ImageGenOutput*) = 0;
};

}  // namespace nexa
