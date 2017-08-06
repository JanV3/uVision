#ifndef UVISION_CAMERA_H
#define UVISION_CAMERA_H

#include "Device.h"

namespace uVision {
/// @brief Base class of every type of camera
class Camera : public Device {
public:
    Camera() = default;
    virtual ~Camera() = default;
};
}

#endif /* UVISION_CAMERA_H */
