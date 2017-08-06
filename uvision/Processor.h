#ifndef UVISION_PROCESSOR_H
#define UVISION_PROCESSOR_H

namespace uVision {
/// @brief Base class of processor(image processor, etc.)
class Processor {
public:
    Processor() = default;
    virtual ~Processor() = default;
};
}

#endif /* UVISION_PROCESSOR_H */
