#pragma once
#include <cstdint>
#include "IBind.h"

class GPUBuffer : public IBind {
public:
    virtual std::size_t getBufferSize() const = 0;
    virtual void *getBufferPtr() const = 0;
    virtual void updateBuffer(const void *pData, std::size_t sizeInByte, std::size_t offset = 0) = 0;
};