#pragma once
#include "GPUBuffer.h"
#include <vector>

struct VertexAttribute {
    GLenum type;
    GLenum count;
    GLBool nomrlaize;
};

class VertexBuffer : public GPUBuffer {
public:
    VertexBuffer(std::size_t sizeInByte, const void *pData = nullptr);
    VertexBuffer(const VertexBuffer &) = delete;
    VertexBuffer &operator=(const VertexBuffer &) = delete;
    void setVertexAttribute(const VertexAttribute &attr)        // 保存 glVertexAttribPoint 的数据
    virtual std::size_t getBufferSize() const override;
    virtual void *getBufferPtr() const override;
    virtual void updateBuffer(const void *pData, std::size_t sizeInByte, std::size_t offset = 0) override;
public:
    GLuint  _VBO;
    void   *_pMapping;
    std::vector<VertexAttribute> _attribute;
};