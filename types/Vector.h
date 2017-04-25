
#define Vector(T) Vector_ ## T

#define Vector_method(T, name) Vector_ ## T ## _ ## name

#define implement_Vector(T)                                             \
                                                                        \
    typedef struct Vector {                                             \
        size_t size;                                                    \
        size_t length;                                                  \
        T* data;                                                        \
    } Vector(T);                                                        \
                                                                        \
    Vector(T) new_Vector_ ## T (size) {                                 \
        Vector(T) this;                                                 \
        this.size = size;                                               \
        this.length = 0;                                                \
        this.data = malloc(size * sizeof(T));                           \
        return this;                                                    \
    }                                                                   \
                                                                        \
    void Vector_method(T, resize)(Vector(T)* this, size_t size) {       \
        fprintf(stderr,                                                 \
                "expanding: oldsize: %zu, newsize: %zu\n",              \
                this->size, size);                                      \
        this->data = realloc(this->data, size * sizeof(T));             \
        this->size = size;                                              \
    }                                                                   \
                                                                        \
    void Vector_method(T, expand)(Vector(T)* this) {                    \
        Vector_method(T, resize)(this, this->size * 2);                 \
    }                                                                   \
                                                                        \
    void Vector_method(T, push)(Vector(T)* this, T item) {              \
        if (this->length >= this->size)                                 \
            Vector_method(T, expand)(this);                             \
        ((T*)this->data)[this->length++] = item;                        \
    }                                                                   \
                                                                        \
    T Vector_method(T, pop)(Vector(T)* this) {                          \
        return ((T*)this->data)[--this->length];                        \
    }

