#include <glad.h>
#include <memory>
#include <array>


class GPUBuffer;
enum BufferAttachmentPoint : std::size_t {      // 支持多个 VBO 1个 EBO
    VertexBuffer0,
    VertexBuffer1,
    VertexBuffer2,
    VertexBuffer3,
    VertexBuffer4,
    VertexBuffer5,
    VertexBuffer6,
    IndexBuffer,
    NumAttachmentPoint,
};

class ArrayBuffer : public IBind {
    ArrayBuffer() = default;
    ArrayBuffer(const ArrayBuffer &) = delete;
    ArrayBuffer &operator=(const ArrayBuffer &) = delete;
    void attachmentBuffer(BufferAttachmentPoint point, std::shared_ptr<GPUBuffer> pBuffer);
    std::shared_ptr<GPUBuffer> getBuffer(BufferAttachmentPoint point) const;
    virtual void bind() override;           // glBindArrayBuffer(VAO)
    virtual void unbind() override;         // glBindArrayBuffer(0)
private:
    void refreshVertexAttribute();          // 如果 EBO 有变化, 则调用 glVertexAttribPoint
private:
    constexpr static std::size_t kMaxBufferSize = BufferAttachmentPoint::NumAttachmentPoint;
    std::array<std::shared_ptr<GPUBuffer>, kMaxBufferSize> _buffers;
    bool _dirty = true;
};