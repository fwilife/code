#pragma once
#include "GPUBuffer.h"


enum class IndexType {
    UINT32,
    INT32,
    UINT16,
    INT16,
};

class IndexBuffer : public GPUBuffer {
public:
    IndexBuffer(std::size_t sizeInByte, IndexBuffer type, const void *pData = nullptr);        // glGenBuffer
    virtual std::size_t getBufferSize() const override; 
    virtual void *getBufferPtr() const override;
    virtual void updateBuffer(const void *pData, std::size_t sizeInByte, std::size_t offset = 0) override;
private:
    GLuint       _EBO;
    void        *_pMapping;
    std::size_t  _size;
    IndexType    _indexType;
};