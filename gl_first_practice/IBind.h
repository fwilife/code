#pragma once

class IBind {
    virtual ~IBind() = default;
    virtual void bind() = 0;
    virtual void unbind() = 0;
};

template<typename T>
struct BindGuard {  
    T &_object;
    bool isBind = false;
public:
    BindGuard(T &object) : _object(object) {
        _object.bind();
        isBind = true;
    }

    ~BindGuard() {
        if (isBind) {
            _object.unbind();
            isBind = false;
        }
    }
};